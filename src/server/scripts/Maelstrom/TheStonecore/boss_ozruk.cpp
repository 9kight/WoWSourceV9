/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"
#include "stonecore.h"

// TO-DO:
// Find heroic sniffs and script "Rupture" (95669) spell and "Rupture Controller" (49597) npc. Triggered by Ground Slam (92410) on heroic mode.

enum Spells
{
    SPELL_ELEMENTIUM_BULWARK      = 78939,
    SPELL_GROUND_SLAM             = 78903,
    SPELL_ELEMENTIUM_SPIKE_SHIELD = 78835,
    SPELL_SHATTER                 = 78807,
    SPELL_ENRAGE                  = 80467,
};

enum NPCs
{
    NPC_BOUNCER_SPIKE             = 42189,
};

enum Texts
{
    SAY_AGGRO                   = 0,
    SAY_ELEMENTIUM_BULWARK      = 1,
    SAY_ELEMENTIUM_SPIKE_SHIELD = 2,
    SAY_ENRAGE                  = 3,
    SAY_DEATH                   = 4,
};

enum Events
{
    EVENT_NONE,

    EVENT_ELEMENTIUM_BULWARK,
    EVENT_GROUND_SLAM,
    EVENT_ELEMENTIUM_SPIKE_SHIELD,
    EVENT_SHATTER,
    EVENT_ENRAGE,
};


class boss_ozruk : public CreatureScript
{
    struct boss_ozrukAI : public BossAI
        {
            boss_ozrukAI(Creature* creature) : BossAI(creature, DATA_OZRUK) { }

            void Reset() override
            {
                _Reset();

                events.ScheduleEvent(EVENT_ELEMENTIUM_BULWARK, 5000);
                events.ScheduleEvent(EVENT_GROUND_SLAM, 10000);
                events.ScheduleEvent(EVENT_ELEMENTIUM_SPIKE_SHIELD, 13000);
            }

            void EnterCombat(Unit* /*victim*/) override
            {
                _EnterCombat();

                Talk(SAY_AGGRO);
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
            {
                if (!me->HealthBelowPctDamaged(25, damage) || me->HasAura(SPELL_ENRAGE))
                    return;

                DoCast(me, SPELL_ENRAGE);
                Talk(SAY_ENRAGE);
            }

            void JustDied(Unit* killer) override
            {
                Talk(SAY_DEATH/*, killer*/); // receiver is the killer, sniff source!

                // Despawn Bouncer Spikes
                if (Vehicle* vehicle = me->GetVehicleKit())
                    for (uint8 i = 0; i < vehicle->GetAvailableSeatCount(); i++)
                        if (Unit* passenger = vehicle->GetPassenger(i))
                            if (Creature* creature = passenger->ToCreature())
                                creature->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_ELEMENTIUM_SPIKE_SHIELD))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ELEMENTIUM_BULWARK:
                            DoCast(me, SPELL_ELEMENTIUM_BULWARK);
                            Talk(SAY_ELEMENTIUM_BULWARK);
                            break;
                        case EVENT_GROUND_SLAM:
                            DoCast(me, SPELL_GROUND_SLAM);
                            break;
                        case EVENT_ELEMENTIUM_SPIKE_SHIELD:
                            DoCast(me, SPELL_ELEMENTIUM_SPIKE_SHIELD);
                            Talk(SAY_ELEMENTIUM_SPIKE_SHIELD);
                            events.ScheduleEvent(EVENT_SHATTER, 10000);
                            break;
                        case EVENT_SHATTER:
                            DoCast(me, SPELL_SHATTER);
                            // Spells are cast in same order everytime after Shatter, so we schedule them here 
                            events.ScheduleEvent(EVENT_ELEMENTIUM_BULWARK, urand(3000,4000));
                            events.ScheduleEvent(EVENT_GROUND_SLAM, urand(7000,9000));
                            events.ScheduleEvent(EVENT_ELEMENTIUM_SPIKE_SHIELD, urand(10000,12000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

public:
	boss_ozruk() : CreatureScript("boss_ozruk") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_ozrukAI(creature);
        }
};

// 78835 - Elementium Spike Shield
class spell_elementium_spike_shield : public SpellScriptLoader
{
public:
    spell_elementium_spike_shield() : SpellScriptLoader("spell_elementium_spike_shield") { }

    class spell_elementium_spike_shield_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_elementium_spike_shield_SpellScript);

        void HandleBouncerSpikes()
        {
            Unit* caster = GetCaster();
            if (caster->GetEntry() != NPC_OZRUK)
                return;

            Vehicle* vehicle = caster->GetVehicleKit();
            if (!vehicle)
                return;

            for (uint8 i = 0; i < vehicle->GetAvailableSeatCount(); i++)
                if (Creature* summon = caster->SummonCreature(NPC_BOUNCER_SPIKE, caster->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 10000))
                    summon->EnterVehicle(caster, i);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_elementium_spike_shield_SpellScript::HandleBouncerSpikes);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_elementium_spike_shield_SpellScript();
    }
};

void AddSC_boss_ozruk()
{
    new boss_ozruk();
    new spell_elementium_spike_shield();
}
