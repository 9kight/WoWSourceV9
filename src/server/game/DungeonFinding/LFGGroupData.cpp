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

#include "LFG.h"
#include "LFGGroupData.h"

namespace lfg
{

LfgGroupData::LfgGroupData(): m_State(LFG_STATE_NONE), m_OldState(LFG_STATE_NONE),
    m_Leader(0), m_Dungeon(0), m_KicksLeft(LFG_GROUP_MAX_KICKS)
{ }

LfgGroupData::~LfgGroupData()
{ }

bool LfgGroupData::IsLfgGroup()
{
    return m_OldState != LFG_STATE_NONE;
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

#include "LFG.h"
#include "LFGGroupData.h"

LfgGroupData::LfgGroupData():
m_State(LFG_STATE_NONE), m_OldState(LFG_STATE_NONE), m_Dungeon(0),
m_VotesNeeded(LFG_GROUP_KICK_VOTES_NEEDED), m_KicksLeft(LFG_GROUP_MAX_KICKS)
{
}

LfgGroupData::~LfgGroupData()
{
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
}

void LfgGroupData::SetState(LfgState state)
{
    switch (state)
    {
        case LFG_STATE_NONE:
<<<<<<< HEAD
            m_Dungeon = 0;
            m_KicksLeft = LFG_GROUP_MAX_KICKS;
        case LFG_STATE_FINISHED_DUNGEON:
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

void LfgGroupData::RestoreState()
{
    m_State = m_OldState;
}

<<<<<<< HEAD
void LfgGroupData::AddPlayer(uint64 guid)
{
    m_Players.insert(guid);
}

uint8 LfgGroupData::RemovePlayer(uint64 guid)
{
    LfgGuidSet::iterator it = m_Players.find(guid);
    if (it != m_Players.end())
        m_Players.erase(it);
    return uint8(m_Players.size());
}

void LfgGroupData::RemoveAllPlayers()
{
    m_Players.clear();
}

void LfgGroupData::SetLeader(uint64 guid)
{
    m_Leader = guid;
}

=======
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
void LfgGroupData::SetDungeon(uint32 dungeon)
{
    m_Dungeon = dungeon;
}

void LfgGroupData::DecreaseKicksLeft()
{
    if (m_KicksLeft)
      --m_KicksLeft;
}

LfgState LfgGroupData::GetState() const
{
    return m_State;
}

<<<<<<< HEAD
LfgState LfgGroupData::GetOldState() const
{
    return m_OldState;
}

LfgGuidSet const& LfgGroupData::GetPlayers() const
{
    return m_Players;
}

uint8 LfgGroupData::GetPlayerCount() const
{
    return m_Players.size();
}

uint64 LfgGroupData::GetLeader() const
{
    return m_Leader;
}

=======
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
uint32 LfgGroupData::GetDungeon(bool asId /* = true */) const
{
    if (asId)
        return (m_Dungeon & 0x00FFFFFF);
    else
        return m_Dungeon;
}

<<<<<<< HEAD
=======
uint8 LfgGroupData::GetVotesNeeded() const
{
    return m_VotesNeeded;
}

>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
uint8 LfgGroupData::GetKicksLeft() const
{
    return m_KicksLeft;
}
<<<<<<< HEAD

} // namespace lfg
=======
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
