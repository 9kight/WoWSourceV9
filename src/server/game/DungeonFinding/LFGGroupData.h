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

>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
#ifndef _LFGGROUPDATA_H
#define _LFGGROUPDATA_H

#include "LFG.h"

<<<<<<< HEAD
namespace lfg
{

enum LfgGroupEnum
{
    LFG_GROUP_MAX_KICKS                           = 3,
=======
enum LfgGroupEnum
{
    LFG_GROUP_MAX_KICKS                           = 3,
    LFG_GROUP_KICK_VOTES_NEEDED                   = 3
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
};

/**
    Stores all lfg data needed about a group.
*/
class LfgGroupData
{
    public:
        LfgGroupData();
        ~LfgGroupData();

<<<<<<< HEAD
        bool IsLfgGroup();

        // General
        void SetState(LfgState state);
        void RestoreState();
        void AddPlayer(uint64 guid);
        uint8 RemovePlayer(uint64 guid);
        void RemoveAllPlayers();
        void SetLeader(uint64 guid);

        // Dungeon
        void SetDungeon(uint32 dungeon);

        // VoteKick
=======
        // General
        void SetState(LfgState state);
        void RestoreState();
        // Dungeon
        void SetDungeon(uint32 dungeon);
        // VoteKick
        void SetVotesNeeded(uint8 votes);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
        void DecreaseKicksLeft();

        // General
        LfgState GetState() const;
<<<<<<< HEAD
        LfgState GetOldState() const;
        LfgGuidSet const& GetPlayers() const;
        uint8 GetPlayerCount() const;
        uint64 GetLeader() const;

        // Dungeon
        uint32 GetDungeon(bool asId = true) const;

        // VoteKick
=======
        // Dungeon
        uint32 GetDungeon(bool asId = true) const;
        // VoteKick
        uint8 GetVotesNeeded() const;
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
        uint8 GetKicksLeft() const;

    private:
        // General
        LfgState m_State;                                  ///< State if group in LFG
        LfgState m_OldState;                               ///< Old State
<<<<<<< HEAD
        uint64 m_Leader;                                   ///< Leader GUID
        LfgGuidSet m_Players;                              ///< Players in group
        // Dungeon
        uint32 m_Dungeon;                                  ///< Dungeon entry
        // Vote Kick
        uint8 m_KicksLeft;                                 ///< Number of kicks left
};

} // namespace lfg

=======
        // Dungeon
        uint32 m_Dungeon;                                  ///< Dungeon entry
        // Vote Kick
        uint8 m_VotesNeeded;                               ///< Votes need to kick success
        uint8 m_KicksLeft;                                 ///< Number of kicks left
};

>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
#endif
