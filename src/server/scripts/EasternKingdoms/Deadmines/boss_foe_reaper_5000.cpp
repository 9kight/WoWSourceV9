/*
 * Copyright (C) 2005-2011 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008-2011 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 *
 * Copyright (C) 2010-2011 Project Trinity <http://www.projecttrinity.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ToDo
 * Make Overdrive Randomize (Like Marrowgar)
 * Spell Harvest needs Voids + Charge (need Retail Infos)
 * Correct Timers
 * Add the OFF_LINE Spell, but first the Creatures to Activate Foe Reaper 5000
 */

#include "ScriptMgr.h"
#include "deadmines.h"
#include "MapManager.h"

enum Spells
{
   // All Modes
   SPELL_OFF_LINE                  = 88348,
   SPELL_OVERDRIVE                 = 88481,
   SPELL_HARVEST                   = 88495,

   // Normal Mode
   SPELL_HARVEST_SWEEP             = 88521,
   SPELL_REAPER_STRIKE             = 88490,
   SPELL_SAFETY_RESTRICTIONS       = 88522,

   // Heroic Mode
   SPELL_HARVEST_SWEEP_H           = 91718,
   SPELL_REAPER_STRIKE_H           = 91717,
   SPELL_SAFETY_RESTRICTIONS_H     = 91720,
};

enum Events
{
   EVENT_OVERDRIVE                 = 1,
   EVENT_HARVEST_SWEEP,
   EVENT_REAPER_STRIKE,
};

enum Texts
{
   SAY_AGGRO                       = 0,
   EMOTE_OVERDRIVE                 = 1,
   SAY_OVERDRIVE                   = 2,
   SAY_HARVEST_1                   = 3,
   SAY_HARVEST_2                   = 4,
   SAY_SAFETY                      = 5,
   SAY_KILLER                      = 6,
   SAY_DEATH                       = 7,
};

class boss_foe_reaper_5000 : public CreatureScript
{
    struct boss_foe_reaper_5000AI : public BossAI
    {
        boss_foe_reaper_5000AI(Creature * creature) : BossAI(creature, BOSS_FOE_REAPER_5000_DATA) {}

        void Reset()
        {
            _Reset();
        }

        void EnterCombat(Unit * who)
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_OVERDRIVE, 20000);
            events.ScheduleEvent(EVENT_HARVEST_SWEEP, 35000);
            events.ScheduleEvent(EVENT_REAPER_STRIKE, 55000);
            _EnterCombat();
        }

        void JustDied(Unit * /*killer*/)
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void KilledUnit(Unit * victim)
        {
            Talk(SAY_KILLER);
        }

        void UpdateAI(uint32 const diff)
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
               case EVENT_OVERDRIVE:
                    Talk(EMOTE_OVERDRIVE);
                    Talk(SAY_OVERDRIVE);
                    me->AddAura(SPELL_OVERDRIVE, me);
                    events.ScheduleEvent(EVENT_OVERDRIVE, 20000);
                    break;
               case EVENT_HARVEST_SWEEP:
                    DoCast(DUNGEON_MODE(SPELL_HARVEST_SWEEP,SPELL_HARVEST_SWEEP_H));
                    events.ScheduleEvent(EVENT_HARVEST_SWEEP, 35000);
                    break;
               case EVENT_REAPER_STRIKE:
                    DoCast(DUNGEON_MODE(SPELL_REAPER_STRIKE,SPELL_REAPER_STRIKE_H));
                    events.ScheduleEvent(EVENT_REAPER_STRIKE, 55000);
                    break;
                }
            }

            if(HealthBelowPct(30))
            {
                Talk(SAY_SAFETY);
                DoCast(DUNGEON_MODE(SPELL_SAFETY_RESTRICTIONS,SPELL_SAFETY_RESTRICTIONS_H));
            }

            DoMeleeAttackIfReady();
        }
    };
public:
    boss_foe_reaper_5000() : CreatureScript("boss_foe_reaper_5000") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_foe_reaper_5000AI(creature);
    }
};

void AddSC_boss_foe_reaper_5000()
{
    new boss_foe_reaper_5000();
}
