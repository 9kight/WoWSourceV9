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
   SPELL_BACKSLASH                 = 92619,
   SPELL_DEADLY_BLADES             = 92622,
   SPELL_DEFLECTION                = 92614,
   SPELL_POWDER_EXPLOSION          = 96283,
   SPELL_VENGEANCE_OF_VANCLEEF     = 95542,
};


class boss_vanessa_vancleef : public CreatureScript
{
public:
    boss_vanessa_vancleef() : CreatureScript("boss_vanessa_vancleef") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_vanessa_vancleefAI (creature);
    }

    struct boss_vanessa_vancleefAI : public ScriptedAI
    {
        boss_vanessa_vancleefAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

    };
};

void AddSC_boss_vanessa_vancleef()
{
    new boss_vanessa_vancleef();
}