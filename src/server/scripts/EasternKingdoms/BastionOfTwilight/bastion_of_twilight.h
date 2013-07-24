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

#ifndef DEF_BASTION_TWILIGHT_H
#define DEF_BASTION_TWILIGHT_H

static const int maxEncounter = 5;

#define BastionOfTwilightScriptName "instance_bastion_of_twilight"

enum sharedSpells
{
    SPELL_BERSERK           = 26662
};

enum eData
{
    BOSS_HALFUS             = 0,
    BOSS_VALIONA            = 1,
    BOSS_THERALION          = 2,
    BOSS_ASCENDANT_COUNCIL  = 3,
    BOSS_FELUDIUS           = 4,
    BOSS_IGNACIOUS          = 5,
    BOSS_ARION              = 6,
    BOSS_TERRASTRA          = 7,
    BOSS_CHOGALL            = 8,
    BOSS_SINESTRA           = 9,
};

enum Data64
{
    DATA_THERALION,
    DATA_FELUDIUS,
    DATA_IGNACIOUS,
    DATA_ARION,
    DATA_TERRASTRA,
    DATA_MONSTROSITY,
    DATA_RESET,
    DATA_ACCUMULATE,
    DATA_COUNCIL_EVENT,
    DATA_CHOGALL,

    DATA_DOUBLE_DRAGON      = 0,
};

enum eCreatures
{
    NPC_VALIONA                 = 45992,
    NPC_THERALION               = 45993,
    NPC_SINESTRA                = 45213,
    NPC_CHOGAL                  = 51494,
    NPC_FIRE_ELEMENTAL          = 43406,
    NPC_SHADOW_LORD             = 43592,

    // Council Bosses
    BOSS_MONSTROSITY            = 43735,

    //Misc
    NPC_COUNCIL_PLUME_STALKER   = 45420,
};

enum eGameObjects
{
    GO_HALFUS_ENTRANCE      = 205222,
    GO_HALFUS_EXIT          = 205223,
    GO_COUNCIL_ENTRANCE     = 205226,
    GO_COUNCIL_EXIT         = 205227,
    GO_VALIONA_ENTRANCE     = 205224,
    GO_VALIONA_EXIT         = 205225,
    GO_CHOGALL_ENTRANCE     = 205228
};

enum eAchievementCriterias
{
    ACH_DOUBLE_DRAGON       = 16015,
    ACH_DOUBLE_DRAGON_2     = 15672
};

enum MovePoints
{
    POINT_FINAL             = 1,
    POINT_SHADOW_CHOGAL     = 2,
};

enum Waypoints
{
    WALK_FELUDIUS           = 14,
};

enum Talks
{
    SAY_PHASE3_FELUDIUS     = 4,
};

template<class AI>
CreatureAI* GetBastionOfTwilightAI(Creature* creature)
{
    if (InstanceMap* const instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(BastionOfTwilightScriptName))
                return new AI(creature);

    return NULL;
}

#endif