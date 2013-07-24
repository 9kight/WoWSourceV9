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
 * Cookie Walk
 * Food despawn after looting
 * Mount on Cauldron or is it a gobject?
 */

#include "ScriptMgr.h"
#include "deadmines.h"

enum Spells
{
   SPELL_CAULDRON_FIRE      = 89252,

   // Normal Mode

   // Good Food
   SPELL_THROW_FOOD1       = 90557,
   SPELL_THROW_FOOD2       = 90560,
   SPELL_THROW_FOOD3       = 90556,
   SPELL_THROW_FOOD4       = 90559,
   SPELL_THROW_FOOD5       = 89263,
   SPELL_THROW_FOOD6       = 90555,

   // Bad Food
   SPELL_THROW_FOOD7       = 90606,
   SPELL_THROW_FOOD8       = 90603,
   SPELL_THROW_FOOD9       = 89739,
   SPELL_THROW_FOOD10      = 90605,
   SPELL_THROW_FOOD11      = 90602,
   SPELL_THROW_FOOD12      = 90604,

   // Heroic Mode

   // Good Food
   SPELL_THROW_FOOD1_H     = 92057,
   SPELL_THROW_FOOD2_H     = 92059,
   SPELL_THROW_FOOD3_H     = 92062,
   SPELL_THROW_FOOD4_H     = 92058,
   SPELL_THROW_FOOD5_H     = 92060,
   SPELL_THROW_FOOD6_H     = 92063,

   // Bad Food
   SPELL_THROW_FOOD7_H     = 92839,
   SPELL_THROW_FOOD8_H     = 92841,
   SPELL_THROW_FOOD9_H     = 92843,
   SPELL_THROW_FOOD10_H    = 92838,
   SPELL_THROW_FOOD11_H    = 92840,
   SPELL_THROW_FOOD12_H    = 92844,

   // MISC (MURLOC
   SPELL_THROW_FOODX_H     = 92842,
   SPELL_THROW_FOODX       = 90680,
   SPELL_THROW_FOODZ       = 90680,

   // FOOD NPC
   SPELL_ROTTEN_AURA       = 89734,

};

enum Texts
{
   EMOTE_START             = 0,
};

enum Events
{
   EVENT_THROW_FOOD        = 1,
   EVENT_FIRE,
};

class boss_captain_cookie : public CreatureScript
{
    struct boss_captain_cookieAI : public BossAI
    {
        boss_captain_cookieAI(Creature * creature) : BossAI(creature, BOSS_CAPTAIN_COOKIE) 
         {
         me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
         me->ApplySpellImmune(0, IMMUNITY_ID, 89734, true);
         me->ApplySpellImmune(0, IMMUNITY_ID, 89252, true);
         }

        void Reset()
        {
            _Reset();
        }

        void EnterCombat(Unit * /*who*/)
        {
            Talk(EMOTE_START);
            events.ScheduleEvent(EVENT_THROW_FOOD, 5000);
            events.ScheduleEvent(EVENT_FIRE, 10000);
            _EnterCombat();
        }

        void JustDied(Unit * /*killer*/)
        {
            _JustDied();
        }

        void KilledUnit(Unit * victim)
        {
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
                switch(urand(0,11))
                {
               case 0:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD1,SPELL_THROW_FOOD1_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 5000);
                    break;
               case 1:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD2,SPELL_THROW_FOOD2_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 6000);
                    break;
               case 2:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD3,SPELL_THROW_FOOD3_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 7000);
                    break;
               case 3:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD4,SPELL_THROW_FOOD4_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 8000);
                    break;
               case 4:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD5,SPELL_THROW_FOOD5_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 9000);
                    break;
               case 5:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD6,SPELL_THROW_FOOD6_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 10000);
                    break;
               case 6:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD7,SPELL_THROW_FOOD7_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 11000);
                    break;
               case 7:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD8,SPELL_THROW_FOOD8_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 12000);
                    break;
               case 8:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD9,SPELL_THROW_FOOD9_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 13000);
                    break;
               case 9:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD10,SPELL_THROW_FOOD10_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 14000);
                    break;
               case 10:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD11,SPELL_THROW_FOOD11_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 15000);
                    break;
               case 11:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_THROW_FOOD12,SPELL_THROW_FOOD12_H), true);
                    events.ScheduleEvent(EVENT_THROW_FOOD, 16000);
                    break;
                }
                switch(eventId)
                {
               case EVENT_FIRE:
                    DoCast(SPELL_CAULDRON_FIRE);
                    break;
                }
            }
        }
    };
public:
    boss_captain_cookie() : CreatureScript("boss_captain_cookie") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_captain_cookieAI(creature);
    }
};

class npc_food : public CreatureScript
{
public:
    npc_food() : CreatureScript("npc_food") {}

    struct npc_foodAI : public ScriptedAI
    {
        npc_foodAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
            me->ApplySpellImmune(0, IMMUNITY_ID, 89252, true);
            me->AddAura(SPELL_ROTTEN_AURA, me);
        }

        InstanceScript *pInstance;

        void Reset()
        {
        }
};

    CreatureAI* GetAI(Creature *pCreature) const
    {
        return new npc_foodAI (pCreature);
}
};

void AddSC_boss_captain_cookie()
{
    new boss_captain_cookie();
    new npc_food();
}
