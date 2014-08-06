/*
<<<<<<< HEAD
 * Copyright (C) 2014 WoWSource 4.3.4
 *
 * Do Not Share The SourceCode
 * and read our WoWSource Terms
 *
 */

/* ScriptData
SDName: LFG
SD%Complete: 100%
SDComment: Fully Working
SDCategory: LFG
EndScriptData
*/

#include "LFGPlayerData.h"

namespace lfg
{

LfgPlayerData::LfgPlayerData(): m_State(LFG_STATE_NONE), m_OldState(LFG_STATE_NONE),
    m_Team(0), m_Group(0), m_Roles(0), m_Comment("")
=======
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "LFGPlayerData.h"

LfgPlayerData::LfgPlayerData():
m_State(LFG_STATE_NONE), m_OldState(LFG_STATE_NONE), m_Roles(0), m_Comment("")
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
{}

LfgPlayerData::~LfgPlayerData()
{
}

void LfgPlayerData::SetState(LfgState state)
{
    switch (state)
    {
        case LFG_STATE_NONE:
<<<<<<< HEAD
        case LFG_STATE_FINISHED_DUNGEON:
            m_Roles = 0;
            m_SelectedDungeons.clear();
            m_Comment = "";
            // No break on purpose
        case LFG_STATE_DUNGEON:
            m_OldState = state;
            // No break on purpose
=======
        case LFG_STATE_DUNGEON:
        case LFG_STATE_FINISHED_DUNGEON:
            m_OldState = state;
                    // No break on purpose
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
        default:
            m_State = state;
    }
}

<<<<<<< HEAD
void LfgPlayerData::RestoreState()
{
    if (m_OldState == LFG_STATE_NONE)
    {
        m_SelectedDungeons.clear();
        m_Roles = 0;
    }
    m_State = m_OldState;
}

void LfgPlayerData::SetLockedDungeons(LfgLockMap const& lockStatus)
=======
void LfgPlayerData::ClearState()
{
    m_SelectedDungeons.clear();
    m_Roles = 0;
    m_State = m_OldState;
}

void LfgPlayerData::SetLockedDungeons(const LfgLockMap& lockStatus)
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
{
    m_LockedDungeons = lockStatus;
}

<<<<<<< HEAD
void LfgPlayerData::SetTeam(uint8 team)
{
    m_Team = team;
}

void LfgPlayerData::SetGroup(uint64 group)
{
    m_Group = group;
}

=======
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
void LfgPlayerData::SetRoles(uint8 roles)
{
    m_Roles = roles;
}

<<<<<<< HEAD
void LfgPlayerData::SetComment(std::string const& comment)
=======
void LfgPlayerData::SetComment(const std::string& comment)
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
{
    m_Comment = comment;
}

<<<<<<< HEAD
void LfgPlayerData::SetSelectedDungeons(LfgDungeonSet const& dungeons)
=======
void LfgPlayerData::SetSelectedDungeons(const LfgDungeonSet& dungeons)
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
{
    m_SelectedDungeons = dungeons;
}

<<<<<<< HEAD
LfgState LfgPlayerData::GetState() const
{
    return m_State;
}

LfgState LfgPlayerData::GetOldState() const
{
    return m_OldState;
}

const LfgLockMap& LfgPlayerData::GetLockedDungeons() const
=======
void LfgPlayerData::ClearSelectedDungeons()
{
    m_SelectedDungeons.clear();
}

LfgState LfgPlayerData::GetState() const
{
    return m_State;
}

const LfgLockMap & LfgPlayerData::GetLockedDungeons() const
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
{
    return m_LockedDungeons;
}

<<<<<<< HEAD
uint8 LfgPlayerData::GetTeam() const
{
    return m_Team;
}

uint64 LfgPlayerData::GetGroup() const
{
    return m_Group;
}

=======
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
uint8 LfgPlayerData::GetRoles() const
{
    return m_Roles;
}

<<<<<<< HEAD
std::string const& LfgPlayerData::GetComment() const
=======
const std::string& LfgPlayerData::GetComment() const
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
{
    return m_Comment;
}

<<<<<<< HEAD
LfgDungeonSet const& LfgPlayerData::GetSelectedDungeons() const
{
    return m_SelectedDungeons;
}

} // namespace lfg
=======
const LfgDungeonSet& LfgPlayerData::GetSelectedDungeons() const
{
    return m_SelectedDungeons;
}
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
