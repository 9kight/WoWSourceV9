/*
 * Copyright (C) 2005 - 2011 MaNGOS <http://www.getmangos.org/>
 *
 * Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
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

#include "throne_of_the_four_winds.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Cell.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

enum Spells
{
// All Three Conclaves

    SPELL_GATHER_STRENGTH_10N                   = 86307,
    SPELL_GATHER_STRENGTH_10H                   = 101445, // The right Spell but doesnt exist
    SPELL_GATHER_STRENGTH_25N                   = 101444, // The right Spell but doesnt exist
    SPELL_GATHER_STRENGTH_25H                   = 101446, // The right Spell but doesnt exist

// BOSS ANSHAL

    SPELL_ANSHAL_NURTURE                        = 85422,
    SPELL_ANSHAL_NURTURE_SUMMON                 = 85429,
    SPELL_ANSHAL_SMOOTHING_BREEZE               = 86205,
    SPELL_ANSHAL_SMOOTHING_BREEZE_HEAL          = 86206,
    SPELL_ANSHAL_SMOOTHING_BREEZE_PACIFY        = 86207,
    SPELL_ANSHAL_SMOOTHING_BREEZE_VISUAL        = 86208, // Possibly visual?
    SPELL_ANSHAL_ZEPHYR                         = 84638,
    SPELL_ANSHAL_ZEPHYR_VISUAL                  = 89813, // Possibly visual?

// BOSS NEZIR

    SPELL_NEZIR_WIND_CHILL                      = 84645,
    SPELL_NEZIR_PERMAFROST                      = 86082,
    SPELL_NEZIR_SLEET_STORM                     = 84644,
    SPELL_NEZIR_ICE_PATCH_SUMMON                = 86122,
    SPELL_NEZIR_ICE_PATCH                       = 86107,

// BOSS ROHASH
    SPELL_ROHASH_SLICING_GALE                   = 86182,
    SPELL_ROHASH_TORNADO_SUMMON                 = 86192,
    SPELL_ROHASH_TORNADO                        = 86134,
   SPELL_HURRICANE                               = 84643,
   SPELL_WIND_BLAST                              = 86193,

   // 10 Normal
   SPELL_DEAFENING_WINDS_10N                     = 85573,

   // 10 Heroic
   SPELL_DEAFENING_WINDS_10H                     = 93191,
   SPELL_STORM_SHIELD_10H                        = 93059,

   // 25 Normal
   SPELL_DEAFENING_WINDS_25N                     = 93190,

   // 25 Heroic
   SPELL_DEAFENING_WINDS_25H                     = 93192,
   SPELL_STORM_SHIELD_25H                        = 95865,

};

enum ConclaveEvents
{
    EVENT_ANSHAL_NURTURE            = 1,
    EVENT_ANSHAL_SOOTHING_BREEZE    = 2,
    EVENT_ANSHAL_ZEPHYR             = 3,

    EVENT_NEZIR_WIND_CHILL          = 4,
    EVENT_NEZIR_PERMAFROST          = 5,
    EVENT_NEZIR_SLEET_STORM         = 6,
    EVENT_NEZIR_ICE_PATCH           = 7,

    EVENT_ROHASH_SLICING_GALE       = 8,
    EVENT_ROHASH_TORNADOS           = 9,
};

class boss_anshal : public CreatureScript
{
    public:
        boss_anshal() : CreatureScript("boss_anshal")
        {
        }

        struct script_impl : public BossAI
        {
            script_impl(Creature* creature) : BossAI(creature, BOSS_ANSHAL)
            {
            }

            void Reset()
            {
                _Reset();
                events.Reset();
                events.ScheduleEvent(EVENT_ANSHAL_NURTURE, 30000);
                events.ScheduleEvent(EVENT_ANSHAL_ZEPHYR, 90000);
            }

            void EnterCombat(Unit*)
            {
                _EnterCombat();
            }

            void JustSummoned(Creature* summoned)
            {
                switch (summoned->GetEntry())
                {
                    case NPC_RAVENOUS_CREEPER_TRIGGER:
                        summoned->CastSpell(me, SPELL_ANSHAL_NURTURE_SUMMON, true);
                        break;
                    case NPC_SOOTHING_BREEZE_TRIGGER:
                        summoned->CastSpell(summoned, SPELL_ANSHAL_SMOOTHING_BREEZE_HEAL, true);
                        summoned->CastSpell(summoned, SPELL_ANSHAL_SMOOTHING_BREEZE_VISUAL, true);
                        summoned->CastSpell(summoned, SPELL_ANSHAL_SMOOTHING_BREEZE_PACIFY, true);
                        break;
                }
            }

            uint64 GetRandomCreeper() const
            {
                std::list<Creature*> creeperList;
                me->GetCreatureListWithEntryInGrid(creeperList, NPC_RAVENOUS_CREEPER, 100.0f);
                creeperList.push_back(me);
                if (!creeperList.empty())
                    return Trinity::Containers::SelectRandomContainerElement(creeperList)->GetGUID();

                return NULL;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ANSHAL_NURTURE:
                            me->CastSpell(me, SPELL_ANSHAL_NURTURE, true);
                            events.CancelEvent(EVENT_ANSHAL_NURTURE);
                            events.ScheduleEvent(EVENT_ANSHAL_SOOTHING_BREEZE, 20000);
                            break;
                        case EVENT_ANSHAL_SOOTHING_BREEZE:
                            if (Creature* const creeper = ObjectAccessor::GetCreature(*me, GetRandomCreeper()))
                                me->CastSpell(creeper, SPELL_ANSHAL_SMOOTHING_BREEZE, true);
                            events.ScheduleEvent(EVENT_ANSHAL_SOOTHING_BREEZE, 20000);
                            break;
                        case EVENT_ANSHAL_ZEPHYR:
                            me->CastSpell(me, SPELL_ANSHAL_ZEPHYR, true);
                            me->CastSpell(me, SPELL_ANSHAL_ZEPHYR_VISUAL, true);
                            events.CancelEvent(EVENT_ANSHAL_ZEPHYR);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetThroneOfTheFourWindsAI<script_impl>(creature);
        }
};

class boss_nezir : public CreatureScript
{
    public:
        boss_nezir() : CreatureScript("boss_nezir")
        {
        }

        struct script_impl : public BossAI
        {
            script_impl(Creature* creature) : BossAI(creature, BOSS_NEZIR)
            {
            }

            void Reset()
            {
                _Reset();
                events.Reset();
                events.ScheduleEvent(EVENT_NEZIR_SLEET_STORM, 90000);
                events.ScheduleEvent(EVENT_NEZIR_WIND_CHILL, 10000);
                events.ScheduleEvent(EVENT_NEZIR_ICE_PATCH, urand(10000, 15000));
                events.ScheduleEvent(EVENT_NEZIR_PERMAFROST, 30000);
            }

            void EnterCombat(Unit*)
            {
                _EnterCombat();
            }

            void JustSummoned(Creature* summoned)
            {
                if (summoned->GetEntry() == NPC_ICE_PATCH)
                    summoned->CastSpell(summoned, SPELL_NEZIR_ICE_PATCH, true);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_NEZIR_WIND_CHILL:
                            me->CastSpell(me, SPELL_NEZIR_WIND_CHILL, true);
                            events.ScheduleEvent(EVENT_NEZIR_WIND_CHILL, 10000);
                            break;
                        case EVENT_NEZIR_PERMAFROST:
                            me->CastSpell(me->getVictim(), SPELL_NEZIR_PERMAFROST, true);
                            events.ScheduleEvent(EVENT_NEZIR_PERMAFROST, 30000);
                            break;
                        case EVENT_NEZIR_SLEET_STORM:
                            me->CastSpell(me, SPELL_NEZIR_SLEET_STORM, true);
                            events.CancelEvent(EVENT_NEZIR_SLEET_STORM);
                            break;
                        case EVENT_NEZIR_ICE_PATCH:
                            if (Unit* const target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                me->CastSpell(target, SPELL_NEZIR_ICE_PATCH_SUMMON, true);
                            events.ScheduleEvent(EVENT_NEZIR_ICE_PATCH, urand(10000, 15000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetThroneOfTheFourWindsAI<script_impl>(creature);
        }
};

class boss_rohash : public CreatureScript
{
    public:
        boss_rohash() : CreatureScript("boss_rohash")
        {
        }

        struct script_impl : public BossAI
        {
            script_impl(Creature* creature) : BossAI(creature, BOSS_ROHASH)
            {
            }

            void Reset()
            {
                _Reset();
                events.Reset();
                events.ScheduleEvent(EVENT_ROHASH_SLICING_GALE, 10000);
                events.ScheduleEvent(EVENT_ROHASH_TORNADOS, 30000);
            }

            void EnterCombat(Unit*)
            {
                _EnterCombat();
            }

            void JustSummoned(Creature* summoned)
            {
                if (summoned->GetEntry() == NPC_TORNADO)
                    summoned->CastSpell(summoned, SPELL_ROHASH_TORNADO, true);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ROHASH_SLICING_GALE:
                            if (Unit* const target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                me->CastSpell(target, SPELL_ROHASH_SLICING_GALE, true);
                            events.ScheduleEvent(EVENT_ROHASH_SLICING_GALE, 10000);
                            break;
                        case EVENT_ROHASH_TORNADOS:
                            me->CastSpell(me, SPELL_ROHASH_TORNADO_SUMMON, true);
                            events.CancelEvent(EVENT_ROHASH_TORNADOS);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetThroneOfTheFourWindsAI<script_impl>(creature);
        }
};

void AddSC_boss_conclave_of_wind()
{
    new boss_anshal();
    new boss_nezir();
    new boss_rohash();
}