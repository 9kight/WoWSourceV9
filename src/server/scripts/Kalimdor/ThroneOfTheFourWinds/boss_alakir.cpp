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

/*
 * Notice: There are missing Abilities on Wowhead an Buffed
 * Squall Line: 93283
 * Eye of the Storm: 89107
 * Relentless Storm: 88866
 */

#include "throne_of_the_four_winds.h"
#include "ScriptPCH.h"

enum Spells
{
    SPELL_WIND_BURST                = 87770,
    SPELL_ICE_STORM_SUMMON_HEAD     = 88239,
    SPELL_ICE_STORM_SUMMON_PERIODIC = 87053,

    SPELL_BERSERK                   = 95211,
    SPELL_ELECTROCUTE               = 88427,
    SPELL_LIGHTNING_ROD             = 89668,
    SPELL_STATIC_SHOCK              = 87873,

    // 10 Normal
    SPELL_ACID_RAIN_10N             = 88301,
    SPELL_WIND_BURST_10N            = 87770,

    // 10 Heroic
    SPELL_ACID_RAIN_10H             = 93280,
    SPELL_WIND_BURST_10H            = 93262,

    // 25 Normal
    SPELL_ACID_RAIN_25N              = 93279,
    SPELL_WIND_BURST_25N             = 93261,

    // 25 Heroic
    SPELL_ACID_RAIN_25H              = 93281,
    SPELL_WIND_BURST_25H             = 93263,
};

enum AlakirEvents
{
    EVENT_WIND_BURST                = 1,
    EVENT_ICE_STORM                 = 2,
};

enum AlakirPhases
{
    PHASE_STAGE_ONE                 = 1,
};

class boss_alakir : public CreatureScript
{
    public:
        boss_alakir() : CreatureScript("boss_alakir")
        {
        }

        struct script_impl : public BossAI
        {
            script_impl(Creature* creature) : BossAI(creature, BOSS_ALAKIR)
            {
            }

            void Reset()
            {
                _Reset();
                events.Reset();
                events.SetPhase(PHASE_STAGE_ONE);
                events.ScheduleEvent(EVENT_WIND_BURST, 10000, 0, PHASE_STAGE_ONE);
                events.ScheduleEvent(EVENT_ICE_STORM, urand(10000, 15000), 0, PHASE_STAGE_ONE);
            }

            void JustSummoned(Creature* summoned)
            {
                if (summoned->GetEntry() == NPC_ICE_STORM_HEAD)
                {
                    summoned->DespawnOrUnsummon(30000);
                    summoned->GetMotionMaster()->MoveRandom(30.0f);
                    summoned->CastSpell(summoned, SPELL_ICE_STORM_SUMMON_PERIODIC, true);
                }
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
                        case EVENT_WIND_BURST:
                            me->CastSpell(me, SPELL_WIND_BURST, true);
                            events.ScheduleEvent(EVENT_WIND_BURST, 20000, 0, PHASE_STAGE_ONE);
                            break;
                        case EVENT_ICE_STORM:
                            if (Unit* const target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                me->CastSpell(target, SPELL_ICE_STORM_SUMMON_HEAD, true);
                            events.ScheduleEvent(EVENT_ICE_STORM, urand(20000, 30000), 0, PHASE_STAGE_ONE);
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

void AddSC_boss_alakir()
{
    new boss_alakir();
}