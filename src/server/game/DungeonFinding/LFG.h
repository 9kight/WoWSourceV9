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
#ifndef _LFG_H
#define _LFG_H

#include "Common.h"

<<<<<<< HEAD
namespace lfg
{

enum LFGEnum
{
    LFG_TANKS_NEEDED                             = 1,
    LFG_HEALERS_NEEDED                           = 1,
    LFG_DPS_NEEDED                               = 3
};

enum LfgRoles
{
    PLAYER_ROLE_NONE                             = 0x00,
    PLAYER_ROLE_LEADER                           = 0x01,
    PLAYER_ROLE_TANK                             = 0x02,
    PLAYER_ROLE_HEALER                           = 0x04,
    PLAYER_ROLE_DAMAGE                           = 0x08
=======
#define LFG_MULTYPLIER 100

enum LfgRoles
{
    ROLE_NONE                                    = 0x00,
    ROLE_LEADER                                  = 0x01,
    ROLE_TANK                                    = 0x02,
    ROLE_HEALER                                  = 0x04,
    ROLE_DAMAGE                                  = 0x08
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
};

enum LfgUpdateType
{
    LFG_UPDATETYPE_DEFAULT                       = 0,      // Internal Use
<<<<<<< HEAD
    LFG_UPDATETYPE_LEADER_UNK1                   = 1,      // FIXME: At group leave
    LFG_UPDATETYPE_ROLECHECK_ABORTED             = 4,
    LFG_UPDATETYPE_JOIN_QUEUE                    = 6,
    LFG_UPDATETYPE_ROLECHECK_FAILED              = 7,
    LFG_UPDATETYPE_REMOVED_FROM_QUEUE            = 8,
    LFG_UPDATETYPE_PROPOSAL_FAILED               = 9,
    LFG_UPDATETYPE_PROPOSAL_DECLINED             = 10,
    LFG_UPDATETYPE_GROUP_FOUND                   = 11,
    LFG_UPDATETYPE_ADDED_TO_QUEUE                = 13,
    LFG_UPDATETYPE_PROPOSAL_BEGIN                = 14,
    LFG_UPDATETYPE_UPDATE_STATUS                 = 15,
    LFG_UPDATETYPE_GROUP_MEMBER_OFFLINE          = 16,
    LFG_UPDATETYPE_GROUP_DISBAND_UNK16           = 17,     // FIXME: Sometimes at group disband
    LFG_UPDATETYPE_JOIN_QUEUE_INITIAL            = 24,
    LFG_UPDATETYPE_DUNGEON_FINISHED              = 25,
    LFG_UPDATETYPE_PARTY_ROLE_NOT_AVAILABLE      = 43,
    LFG_UPDATETYPE_JOIN_LFG_OBJECT_FAILED        = 45,
=======
    LFG_UPDATETYPE_LEADER                        = 1,
    LFG_UPDATETYPE_ROLECHECK_ABORTED             = 4,
    LFG_UPDATETYPE_JOIN_PROPOSAL                 = 5,
    LFG_UPDATETYPE_ROLECHECK_FAILED              = 6,
    LFG_UPDATETYPE_REMOVED_FROM_QUEUE            = 7,
    LFG_UPDATETYPE_PROPOSAL_FAILED               = 8,
    LFG_UPDATETYPE_PROPOSAL_DECLINED             = 9,
    LFG_UPDATETYPE_GROUP_FOUND                   = 10,
    LFG_UPDATETYPE_ADDED_TO_QUEUE                = 12,
    LFG_UPDATETYPE_PROPOSAL_BEGIN                = 13,
    LFG_UPDATETYPE_CLEAR_LOCK_LIST               = 14,
    LFG_UPDATETYPE_GROUP_MEMBER_OFFLINE          = 15,
    LFG_UPDATETYPE_GROUP_DISBAND                 = 16
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
};

enum LfgState
{
    LFG_STATE_NONE,                                        // Not using LFG / LFR
    LFG_STATE_ROLECHECK,                                   // Rolecheck active
    LFG_STATE_QUEUED,                                      // Queued
    LFG_STATE_PROPOSAL,                                    // Proposal active
    LFG_STATE_BOOT,                                        // Vote kick active
    LFG_STATE_DUNGEON,                                     // In LFG Group, in a Dungeon
    LFG_STATE_FINISHED_DUNGEON,                            // In LFG Group, in a finished Dungeon
    LFG_STATE_RAIDBROWSER                                  // Using Raid finder
};

/// Instance lock types
enum LfgLockStatusType
{
<<<<<<< HEAD
    LFG_LOCKSTATUS_NONE                          = 0,
=======
    LFG_LOCKSTATUS_OK                            = 0,      // Internal use only
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    LFG_LOCKSTATUS_INSUFFICIENT_EXPANSION        = 1,
    LFG_LOCKSTATUS_TOO_LOW_LEVEL                 = 2,
    LFG_LOCKSTATUS_TOO_HIGH_LEVEL                = 3,
    LFG_LOCKSTATUS_TOO_LOW_GEAR_SCORE            = 4,
    LFG_LOCKSTATUS_TOO_HIGH_GEAR_SCORE           = 5,
    LFG_LOCKSTATUS_RAID_LOCKED                   = 6,
    LFG_LOCKSTATUS_ATTUNEMENT_TOO_LOW_LEVEL      = 1001,
    LFG_LOCKSTATUS_ATTUNEMENT_TOO_HIGH_LEVEL     = 1002,
    LFG_LOCKSTATUS_QUEST_NOT_COMPLETED           = 1022,
    LFG_LOCKSTATUS_MISSING_ITEM                  = 1025,
<<<<<<< HEAD
    LFG_LOCKSTATUS_NOT_IN_SEASON                 = 1031,
    LFG_LOCKSTATUS_MISSING_ACHIEVEMENT           = 1034
};

/// Answer state (Also used to check compatibilites)
enum LfgAnswer
{
    LFG_ANSWER_PENDING                           = -1,
    LFG_ANSWER_DENY                              = 0,
    LFG_ANSWER_AGREE                             = 1
};

struct LockData
{
    LfgLockStatusType locktyp;
    uint32 neededItemlevel;
    uint32 averageItemlevel;
    
    LockData(): locktyp(LFG_LOCKSTATUS_NONE), neededItemlevel(0), averageItemlevel(0) {};
    LockData(LfgLockStatusType typ, uint32 nilevel,uint32 avlevel): locktyp(typ), neededItemlevel(nilevel), averageItemlevel(avlevel) {};
};

typedef std::set<uint32> LfgDungeonSet;
typedef std::map<uint32, LockData> LfgLockMap;
typedef std::map<uint64, LfgLockMap> LfgLockPartyMap;
typedef std::set<uint64> LfgGuidSet;
typedef std::list<uint64> LfgGuidList;
typedef std::map<uint64, uint8> LfgRolesMap;
typedef std::map<uint64, uint64> LfgGroupsMap;

std::string ConcatenateDungeons(LfgDungeonSet const& dungeons);
std::string GetRolesString(uint8 roles);
std::string GetStateString(LfgState state);

} // namespace lfg
=======
    LFG_LOCKSTATUS_NOT_IN_SEASON                 = 1031
};

enum LfgRewardCurrency
{
    LFG_REWARD_JUSTICE = 395,
    LFG_REWARD_VALOR = 396
};

/// Dungeon and reason why player can't join
struct LfgLockStatus
{
    uint32 dungeon;                                        ///< Dungeon Id
    LfgLockStatusType lockstatus;                          ///< Lock type
};

typedef std::set<uint32> LfgDungeonSet;
typedef std::map<uint32, LfgLockStatusType> LfgLockMap;
typedef std::map<uint64, LfgLockMap> LfgLockPartyMap;
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f

#endif
