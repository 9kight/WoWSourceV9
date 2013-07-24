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

#include "ScriptMgr.h"
#include "deadmines.h"

enum Spells
{
   // Normal Mode
   SPELL_GO_FOR_THE_THROAT_N       = 88836,
   SPELL_THIRST_FOR_BLOOD_N        = 88737,
   SPELL_THIRST_FOR_BLOOD          = 88736,
   SPELL_SWIPE_N                   = 88839,

   // Heroic Mode
   SPELL_GO_FOR_THE_THROAT_H       = 91863,
   SPELL_SWIPE_H                   = 91859,
   SPELL_THIRST_FOR_BLOOD_H        = 91862,
   SPELL_THE_FOG                   = 88783,
   SPELL_SUMMON_VAPOR              = 88831,

   // Vapors Spells ( Only Heroic)
   SPELL_CONDENSATION              = 92013,
   SPELL_SWIRLING_VAPOR            = 92007,
   SPELL_CONDENSING_VAPOR          = 92008,
   SPELL_FREEZING_VAPOR            = 92011,
   SPELL_COALESCE                  = 92042,
};

class boss_admiral_ripsnarl : public CreatureScript
{
public:
    boss_admiral_ripsnarl() : CreatureScript("boss_admiral_ripsnarl") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_admiral_ripsnarlAI (creature);
    }

    struct boss_admiral_ripsnarlAI : public ScriptedAI
    {
        boss_admiral_ripsnarlAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

    };
};

void AddSC_boss_admiral_ripsnarl()
{
    new boss_admiral_ripsnarl();
}