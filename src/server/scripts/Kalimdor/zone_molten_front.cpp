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

/* ScriptData
SDName: Molten Front
SD%Complete: 0
SDComment: Placeholder
SDCategory: Molten Front
EndScriptData */

/* ContentData
EndContentData */

#include "ScriptPCH.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Spells
{

};

enum eEvents
{
    // npc_pyrelord
    EVENT_INCINERATE,
    EVENT_BACKDRAFT,
    
    //npc_ancient_charhound
    EVENT_FLAME_LASH,
    EVENT_LEAPING_BITE,
    EVENT_SLEEPING_SLEEP,

    //npc_ancient_charhound	
	EVENT_INCATFORM,
	EVENT_PYROBLAST,
	EVENT_SCORCH,
	
	//npc_subterranean_magma_worm
    EVENT_LAVA_SHOWER,
	EVENT_BURNING_HUNGER,	
};

/*######
# npc_pyrelord - 52683
######*/

class npc_pyrelord : public CreatureScript
{
public:
    npc_pyrelord() : CreatureScript("npc_pyrelord") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_pyrelordAI(pCreature);
    }

    struct npc_pyrelordAI : public ScriptedAI
    {
        npc_pyrelordAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_INCINERATE, 3000);
            events.ScheduleEvent(EVENT_BACKDRAFT, 6000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_INCINERATE:
					    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, 79938);
                        events.RescheduleEvent(EVENT_INCINERATE, 3000);
                        return;
                    case EVENT_BACKDRAFT:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, 98839);
                        events.RescheduleEvent(EVENT_BACKDRAFT, 6000);
                        return;
                }
            }
        }
    };
};

/*######
# npc_ancient_charhound - 54339
######*/

class npc_ancient_charhound : public CreatureScript
{
public:
    npc_ancient_charhound() : CreatureScript("npc_ancient_charhound") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_ancient_charhoundAI(pCreature);
    }

    struct npc_ancient_charhoundAI : public ScriptedAI
    {
        npc_ancient_charhoundAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_FLAME_LASH, 3000);
            events.ScheduleEvent(EVENT_LEAPING_BITE, 6000);
			events.ScheduleEvent(EVENT_SLEEPING_SLEEP, 14000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_FLAME_LASH:
					if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, 3356);
                        events.RescheduleEvent(EVENT_FLAME_LASH, 3000);
                        return;
                    case EVENT_LEAPING_BITE:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, 98701);
                        events.RescheduleEvent(EVENT_LEAPING_BITE, 6000);
                        return;
                    case EVENT_SLEEPING_SLEEP:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, 42648);
                        events.RescheduleEvent(EVENT_SLEEPING_SLEEP, 14000);
                        return;						
                }
            }
          DoMeleeAttackIfReady();			
        }
    };
};

/*######
# npc_druid_of_the_flame - 54343
######*/

class npc_druid_of_the_flame : public CreatureScript
{
public:
    npc_druid_of_the_flame() : CreatureScript("npc_druid_of_the_flame") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_druid_of_the_flameAI(pCreature);
    }

    struct npc_druid_of_the_flameAI : public ScriptedAI
    {
        npc_druid_of_the_flameAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_INCATFORM, 2000);
            events.ScheduleEvent(EVENT_PYROBLAST, 3000);
			events.ScheduleEvent(EVENT_SCORCH, 6000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_INCATFORM:
                        DoCast(me, 97678);
					    events.ScheduleEvent(EVENT_PYROBLAST, 3000);
			            events.ScheduleEvent(EVENT_SCORCH, 6000);
                        return;
                    case EVENT_PYROBLAST:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, 17273);
                        return;
                    case EVENT_SCORCH:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, 13878);
                        return;							
                }
            }
          DoMeleeAttackIfReady();			
        }
    };
};

/*######
# npc_subterranean_magma_worm - 53112
######*/

class npc_subterranean_magma_worm : public CreatureScript
{
public:
    npc_subterranean_magma_worm() : CreatureScript("npc_subterranean_magma_worm") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_subterranean_magma_wormAI(pCreature);
    }

        struct npc_subterranean_magma_wormAI: public Scripted_NoMovementAI
        {
                npc_subterranean_magma_wormAI(Creature* pCreature) :
                        Scripted_NoMovementAI(pCreature)
                {
                }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_LAVA_SHOWER, 15000);
			events.ScheduleEvent(EVENT_BURNING_HUNGER, urand(9000, 17000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_LAVA_SHOWER:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, 97549);
                        events.ScheduleEvent(EVENT_LAVA_SHOWER, 55000);
                        return;
                    case EVENT_BURNING_HUNGER:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, 98268);
                        events.RescheduleEvent(EVENT_BURNING_HUNGER, urand(12000, 17000));
                        return;						
                }
            }
           DoSpellAttackIfReady(97306);			
        }
    };
};

void AddSC_molten_front()
{
  new npc_pyrelord();
  new npc_ancient_charhound();
  new npc_druid_of_the_flame();
  new npc_subterranean_magma_worm();
}