/*
* Copyright (C) 2010-2011 Project Trinity <http://www.projecttrinity.org/>
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

#include "bastion_of_twilight.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Cell.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

enum ChogallSpells
{
    SPELL_FURY_OF_CHOGALL                       = 82524,
    SPELL_CONVERSION                            = 91303,
    SPELL_FESTER_BLOOD                          = 82299,
    SPELL_CORRUPTION_OF_THE_OLD_GOD             = 82361,
    SPELL_CORRUPTED_BLOOD_BAR                   = 93104, // Possibly casted on Cho'gall himself?
    SPELL_DARKENED_CREATIONS                    = 82414,
    SPELL_SUMMON_CORRUPTING_ADHERENT            = 81628,
    
    SPELL_CORRUPTING_CRASH                      = 81685,
    SPELL_DEPRAVITY                             = 81713,
    SPELL_SPILLED_BLOOD_OF_THE_OLD_GOD_VISUAL   = 81771,
    SPELL_SPILLED_BLOOD_OF_THE_OLD_GOD          = 81757,
    SPELL_AURA_SHOW_PROGRESS_BAR                = 93103,
    CORRUPTED_BLOOD_BAR                         = 93103,
};

enum ChogallEvents
{
    EVENT_FURY_OF_CHOGALL                       = 1,
    EVENT_CONVERSION                            = 2,
    EVENT_FESTER_BLOOD                          = 3,
    EVENT_SUMMON_CORRUPTING_ADHERENT            = 4,

    EVENT_CORRUPTING_CRASH                      = 5,
    EVENT_DEPRAVITY                             = 6,
};

enum Misc
{
    NPC_BLOOD_OF_THE_OLD_GOD                    = 43707,
};

uint32 const summonSpells[2][2] =
{
    { 205950, 81611 },
    { 205951, 81618 },
};

class boss_chogall : public CreatureScript
{
    public:
        boss_chogall() : CreatureScript("boss_chogall")
        {
        }

        struct script_impl: public BossAI
        {
            script_impl(Creature* creature) : BossAI(creature, BOSS_CHOGALL)
            {
            }

            void Reset()
            {
                _Reset();
                phase = 0;
                instance->DoRemoveAurasDueToSpellOnPlayers(CORRUPTED_BLOOD_BAR);
                events.ScheduleEvent(EVENT_FURY_OF_CHOGALL, 15000);
                events.ScheduleEvent(EVENT_CONVERSION, urand(15000, 25000));
                events.ScheduleEvent(EVENT_FESTER_BLOOD, urand(20000, 30000));
                events.ScheduleEvent(EVENT_SUMMON_CORRUPTING_ADHERENT, urand(30000, 35000));
            }

            void EnterCombat(Unit*)
            {
                _EnterCombat();
                phase = 1;

                me->CastSpell(me, SPELL_CORRUPTED_BLOOD_BAR, true);
            }

            void JustDied(Unit*)
            {
                _EnterCombat();
                instance->DoRemoveAurasDueToSpellOnPlayers(CORRUPTED_BLOOD_BAR);
                summons.DespawnAll();
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HealthBelowPct(26) && phase == 1)
                    SetPhaseTwo();

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FURY_OF_CHOGALL:
                            me->CastSpell(me->getVictim(), SPELL_FURY_OF_CHOGALL, false);
                            events.RescheduleEvent(EVENT_FURY_OF_CHOGALL, urand(15000, 25000));
                            break;
                        case EVENT_CONVERSION:
                            me->CastSpell(me, SPELL_CONVERSION, true);
                            events.RescheduleEvent(EVENT_CONVERSION, urand(25000, 35000));
                            break;
                        case EVENT_FESTER_BLOOD:
                            me->CastSpell(me, SPELL_FESTER_BLOOD, false);
                            events.RescheduleEvent(EVENT_FESTER_BLOOD, urand(20000, 25000));
                            break;
                        case EVENT_SUMMON_CORRUPTING_ADHERENT:
                            me->CastSpell(me, SPELL_SUMMON_CORRUPTING_ADHERENT, true);
                            events.RescheduleEvent(EVENT_SUMMON_CORRUPTING_ADHERENT, urand(30000, 35000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void SetPhaseTwo()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_FURY_OF_CHOGALL, 15000);
                phase = 2;

                me->CastSpell(me, SPELL_CORRUPTION_OF_THE_OLD_GOD, true);
                me->CastSpell(me, SPELL_DARKENED_CREATIONS, true); // Possibly wrong
            }

        private:
            uint8 phase;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetBastionOfTwilightAI<script_impl>(creature);
        }
};

class npc_corrupting_adherent : public CreatureScript
{
    public:
        npc_corrupting_adherent() : CreatureScript("npc_corrupting_adherent")
        {
        }

        struct script_impl: public ScriptedAI
        {
            script_impl(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_CORRUPTING_CRASH, urand(5000, 15000));
                events.ScheduleEvent(EVENT_DEPRAVITY, urand(10000, 20000));
            }

            void DamageTaken(Unit*, uint32& damage)
            {
                if (damage < me->GetHealth())
                    return;

                me->StopMoving();
                me->CastStop();
                me->CombatStop(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
                me->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);

                me->CastSpell(me, SPELL_SPILLED_BLOOD_OF_THE_OLD_GOD, true);
                me->CastSpell(me, SPELL_SPILLED_BLOOD_OF_THE_OLD_GOD_VISUAL, true);
                damage = 0;
            }

            void JustSummoned(Creature* summoned)
            {
                if (summoned->GetEntry() == NPC_BLOOD_OF_THE_OLD_GOD)
                {
                    if (Player* const target = summoned->FindNearestPlayer(100.0f))
                    {
                        summoned->SetInCombatWith(target);
                        summoned->SetUInt64Value(UNIT_FIELD_TARGET, target->GetGUID());
                        summoned->GetMotionMaster()->MoveChase(target);
                        //summoned->AddThreat(target, 10000.0f);
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CORRUPTING_CRASH:
                            if (Unit* const target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                me->CastSpell(target, SPELL_CORRUPTING_CRASH, true);
                            events.RescheduleEvent(EVENT_CORRUPTING_CRASH, urand(10000, 20000));
                            break;
                        case EVENT_DEPRAVITY:
                            me->CastSpell(me, SPELL_DEPRAVITY, false);
                            events.RescheduleEvent(EVENT_DEPRAVITY, urand(10000, 20000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetBastionOfTwilightAI<script_impl>(creature);
        }
};

class spell_chogall_conversion : public SpellScriptLoader
{
    class script_impl : public SpellScript
    {
        PrepareSpellScript(script_impl);

        enum { SPELL_WORSHIPPING = 91317 };

        bool is10men;

        bool Load()
        {
            Unit const* const caster = GetCaster();
            Map const* const map = caster->GetMap();
            if (!map)
                return false;

            Difficulty difficulty = map->GetDifficulty();
            is10men = (difficulty == RAID_DIFFICULTY_10MAN_NORMAL || difficulty == RAID_DIFFICULTY_10MAN_HEROIC);
            return true;
        }

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            std::list<WorldObject*> tempList;

            uint8 const size = (is10men ? 2 : 5);
            if (unitList.size() <= size)
                return;

            for (uint8 n = 0; n < size; ++n)
            {
                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(unitList);
                unitList.remove(target);
                tempList.push_back(target);
            }

            unitList = tempList;
        }

        void HandleScriptEffect(SpellEffIndex)
        {
            if (Unit* const target = GetHitUnit())
                target->CastSpell(target, SPELL_WORSHIPPING, true);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(script_impl::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(script_impl::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

public:
    spell_chogall_conversion()
        : SpellScriptLoader("spell_chogall_conversion")
    {
    }

    SpellScript* GetSpellScript() const
    {
        return new script_impl();
    }
};

class spell_chogall_corruption : public SpellScriptLoader
{
    class script_impl : public SpellScript
    {
        PrepareSpellScript(script_impl);

        enum { SPELL_CORRUPTED_BLOOD = 81701 };

        void HandleScriptEffect(SpellEffIndex)
        {
            if (Unit* const target = GetHitUnit())
                target->CastSpell(target, SPELL_CORRUPTED_BLOOD, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(script_impl::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

public:
    spell_chogall_corruption()
        : SpellScriptLoader("spell_chogall_corruption")
    {
    }

    SpellScript* GetSpellScript() const
    {
        return new script_impl();
    }
};

class spell_chogall_corrupted_blood : public SpellScriptLoader
{
    class script_impl : public SpellScript
    {
        PrepareSpellScript(script_impl);

        enum
        {
            SPELL_CORRUPTED_BLOOD               = 81701,
            SPELL_CORRUPTION_ACCELERATED        = 81836,
            SPELL_CORRUPTION_SICKNESS           = 81829,
            //SPELL_CORRUPTION_MALFORMATION       = 
            SPELL_CORRUPTION_ABSOLUTE           = 82170,
            SPELL_CORRUPTION_ABSOLUTE_TRANSFORM = 82193,
        };

        void HandleScriptEffect(SpellEffIndex)
        {
            Unit* const target = GetHitUnit();
            if (!target)
                return;

            Aura* const aura = target->GetAura(SPELL_CORRUPTED_BLOOD);
            if (!aura)
                return;

            uint8 const amount = aura->GetStackAmount();
            switch (amount)
            {
                case 25:
                    target->CastSpell(target, SPELL_CORRUPTION_ACCELERATED, true);
                    break;
                case 50:
                    target->CastSpell(target, SPELL_CORRUPTION_SICKNESS, true);
                    break;
                case 75:
                    // #TODO: Implement it
                    break;
                case 100:
                    target->CastSpell(target, SPELL_CORRUPTION_ABSOLUTE, true);
                    target->CastSpell(target, SPELL_CORRUPTION_ABSOLUTE_TRANSFORM, true);
                    break;
                default:
                    break;
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(script_impl::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

public:
    spell_chogall_corrupted_blood()
        : SpellScriptLoader("spell_chogall_corrupted_blood") { }

    SpellScript* GetSpellScript() const
    {
        return new script_impl();
    }
};

class spell_chogall_corruption_bar : public SpellScriptLoader
{
    class script_impl : public AuraScript
    {
        PrepareAuraScript(script_impl);

        enum { SPELL_CORRUPTED_BLOOD = 81701 };

        // #NOTE: Will not work until SPELL_AURA_SHOW_PROGRESS_BAR is implemented :(

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes)
        {
            if (Aura* const aura = GetTarget()->GetAura(SPELL_CORRUPTED_BLOOD))
            {
                int32 const amount = int32(aura->GetStackAmount());
                const_cast<AuraEffect*>(aurEff)->SetAmount(amount);
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(script_impl::OnApply, EFFECT_0, SPELL_AURA_ENABLE_ALT_POWER, AURA_EFFECT_HANDLE_REAL);
        }
    };

public:
    spell_chogall_corruption_bar()
        : SpellScriptLoader("spell_chogall_corruption_bar")
    {
    }

    AuraScript* GetAuraScript() const
    {
        return new script_impl();
    }
};

class spell_chogall_summon_corrupting_adherent : public SpellScriptLoader
{
    class script_impl : public SpellScript
    {
        PrepareSpellScript(script_impl);

        void HandleScriptEffect(SpellEffIndex)
        {
            Unit* const caster = GetCaster();
            Map* const map = caster->GetMap();
            if (!map)
                return;

            if (map->GetDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC)
            {
                for (uint8 n = 0; n < 2; ++n)
                    if (GameObject* const gameObject = caster->FindNearestGameObject(summonSpells[0][n], 200.0f))
                        caster->CastSpell(gameObject, summonSpells[1][n], true);
                return;
            }

            uint8 const n = urand(0, 1);
            if (GameObject* const gameObject = caster->FindNearestGameObject(summonSpells[0][n], 200.0f))
                caster->CastSpell(gameObject, summonSpells[1][n], true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(script_impl::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

public:
    spell_chogall_summon_corrupting_adherent()
        : SpellScriptLoader("spell_chogall_summon_corrupting_adherent")
    {
    }

    SpellScript* GetSpellScript() const
    {
        return new script_impl();
    }
};

void AddSC_boss_chogall()
{
    new boss_chogall();
    new npc_corrupting_adherent();
    new spell_chogall_conversion();
    new spell_chogall_corruption();
    new spell_chogall_corrupted_blood();
    new spell_chogall_corruption_bar();
    new spell_chogall_summon_corrupting_adherent();
}