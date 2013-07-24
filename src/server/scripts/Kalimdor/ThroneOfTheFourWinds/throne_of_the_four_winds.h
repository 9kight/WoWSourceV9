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

#ifndef DEF_THRONE_OF_THE_FOUR_WINDS_H
#define DEF_THRONE_OF_THE_FOUR_WINDS_H

#include "ObjectMgr.h"

static const int maxEncounter = 2;
#define ThroneOfTheFourWindsScriptName "instance_throne_of_the_four_winds"

enum Bosses
{
	BOSS_ANSHAL,
    BOSS_NEZIR,
    BOSS_ROHASH,
    BOSS_ALAKIR,
};

enum CreatureIds
{
    NPC_ANSHAL                      = 45870,
    NPC_NEZIR                       = 45871,
    NPC_ROHASH                      = 45872,
    NPC_ALAKIR                      = 46753,

    // Conclave of Wind
    NPC_SOOTHING_BREEZE_TRIGGER     = 46246,
    NPC_RAVENOUS_CREEPER_TRIGGER    = 45813,
    NPC_RAVENOUS_CREEPER            = 45812,
    NPC_ICE_PATCH                   = 46186,
    NPC_TORNADO                     = 46207,
    NPC_ICE_STORM_HEAD              = 46734,
    NPC_ICE_STORM                   = 46973,
};

template<class AI>
CreatureAI* GetThroneOfTheFourWindsAI(Creature* creature)
{
    if (InstanceMap* const instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(ThroneOfTheFourWindsScriptName))
                return new AI(creature);

    return NULL;
}

#endif