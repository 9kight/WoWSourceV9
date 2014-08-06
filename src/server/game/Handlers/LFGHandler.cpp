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

#include "LFGMgr.h"
#include "ObjectMgr.h"
#include "Group.h"
#include "Player.h"
#include "Opcodes.h"
#include "WorldPacket.h"
#include "WorldSession.h"

#define LFG_MULTYPLIER 100

void BuildPlayerLockDungeonBlock(WorldPacket& data, lfg::LfgLockMap const& lock)
{
    data << uint32(lock.size());                           // Size of lock dungeons
    for (lfg::LfgLockMap::const_iterator it = lock.begin(); it != lock.end(); ++it)
    {
        data << uint32(it->first);                         // Dungeon entry (id + type)
        data << uint32(it->second.locktyp);                // Lock status
        data << uint32(it->second.neededItemlevel);        // Required itemLevel
        data << uint32(it->second.averageItemlevel);       // Current itemLevel
    }
}

void BuildPartyLockDungeonBlock(WorldPacket& data, lfg::LfgLockPartyMap const& lockMap)
{
    data << uint8(lockMap.size());
    for (lfg::LfgLockPartyMap::const_iterator it = lockMap.begin(); it != lockMap.end(); ++it)
    {
        data << uint64(it->first);                         // Player guid
        BuildPlayerLockDungeonBlock(data, it->second);
    }
}

void BuildQuestReward(WorldPacket& data, Quest const* quest, Player* player)
{
    uint8 rewCount = quest->GetRewItemsCount() + quest->GetRewCurrencyCount();
    
    data << uint32(quest->GetRewOrReqMoney());
    data << uint32(quest->XPValue(player));
    data << uint8(rewCount);
    if (rewCount)
    {
        ItemTemplate const* iProto = NULL;
        for (uint8 i = 0; i < quest->GetRewItemsCount(); ++i)
        {
            if (!quest->RewardItemId[i])
                continue;
            
            iProto = sObjectMgr->GetItemTemplate(quest->RewardItemId[i]);
            
            data << uint32(quest->RewardItemId[i]);
            if(quest->RewardItemId[i])
            {
                data << uint32(iProto ? iProto->DisplayInfoID : 0);
                data << uint32(quest->RewardItemIdCount[i]);
            }
            data << uint8(false);
        }
        
        CurrencyTypesEntry const* iCurr = NULL;
        for (uint8 i = 0; i < quest->GetRewCurrencyCount(); ++i)
        {
            if (!quest->RewardCurrencyId[i])
                continue;
            
            iCurr = sCurrencyTypesStore.LookupEntry(quest->RewardCurrencyId[i]);
            
            data << uint32(quest->RewardCurrencyId[i]);
            if(quest->RewardCurrencyId[i])
            {
                data << uint32(0);
                data << uint32(quest->RewardCurrencyCount[i] * LFG_MULTYPLIER);  // currency amount
            }
            data << uint8(true);
        }
    }
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

#include "WorldSession.h"
#include "WorldPacket.h"
#include "DBCStores.h"
#include "Player.h"
#include "Group.h"
#include "LFGMgr.h"
#include "ObjectMgr.h"
#include "GroupMgr.h"
#include "InstanceScript.h"

void BuildPlayerLockDungeonBlock(WorldPacket& data, const LfgLockMap& lock)
{
    data << uint32(lock.size());                           // Size of lock dungeons
    for (LfgLockMap::const_iterator it = lock.begin(); it != lock.end(); ++it)
    {
        data << uint32(it->first);                         // Dungeon entry (id + type)
        data << uint32(it->second);                        // Lock status
        data << uint32(0);                                 // needed ILvL
        data << uint32(0);                                 // player ILvL
    }
}

void BuildLfgRewardDungeonBlock(WorldPacket& data, Player* player,LfgReward const* reward,LFGDungeonEntry const* dungeon)
{
    Quest const* qRew[2]; //= NULL;
    Quest const* actualQuest = NULL;
    uint8 done = 0;

    if (reward)
    {
        qRew[0] = sObjectMgr->GetQuestTemplate(reward->reward[0].questId); //1st time reward quest
        qRew[1] = sObjectMgr->GetQuestTemplate(reward->reward[1].questId); //Nth time reward quest
        if (qRew[0])
        {
            actualQuest = qRew[0];
            done = player->CanRewardQuest(qRew[0], false);
            if (!done && qRew[1])
                actualQuest = qRew[1];              
        }
    }

    data << done;

    /*if(data.GetOpcode() == SMSG_LFG_PLAYER_REWARD)
    {
        data << uint32(0);              //strangers, no fucking idea
    }*/

    //if (actualQuest)
    if(dungeon->type == LFG_TYPE_RANDOM)
    {
        if(dungeon->difficulty == 1)
        {
            data << uint32(actualQuest->RewardCurrencyCount[0] * LFG_MULTYPLIER);
            data << uint32(1000 * LFG_MULTYPLIER);
            data << uint32(actualQuest->RewardCurrencyId[0]);

            data << uint32(0);                          //nuller      
            data << uint32(1000 * LFG_MULTYPLIER);      //CapFirst

            data << uint32(0);                          //nuller
            data << uint32(1000 * LFG_MULTYPLIER);      //CapNth

            data << uint32(0);                          //nuller  
            data << uint32(1000 * LFG_MULTYPLIER);      //MaxCap

            data << uint32(qRew[1]->RewardCurrencyCount[0] * LFG_MULTYPLIER);      //unk6
            data << uint32(0);      //unk7

            data << uint32(qRew[0]->RewardCurrencyCount[0] * LFG_MULTYPLIER);      //unk8
            data << uint32(0);      //unk8.1
        }
        else
        {
            data << uint32(1);
            data << uint32(7);
            data << uint32(0);

            data << uint32(0);      //nuller      
            data << uint32(7);      //CapFirst

            data << uint32(0);      //nuller
            data << uint32(0);      //CapNth

            data << uint32(0);      //nuller  
            data << uint32(0);      //MaxCap

            data << uint32(0);      //unk6
            data << uint32(0);      //unk7

            data << uint32(1);      //unk8
            data << uint32(0);      //unk8.1
        }
        
        data << uint8(1);       //unk9

        for(uint8 i = 0; i < 3; ++i)
        {
            uint8 controller = 0;
            data << uint32(controller);                     // some controller, if != 0 then the code bellow is executed
            if(controller != 0)
            {
                data << uint32(0);
                data << uint32(0);
                uint8 counter1 = 0;
                data << counter1;
                for(uint8 j = 0; j < counter1; ++j)
                {
                    data << uint32(0);
                    data << uint32(0);
                    data << uint32(0);
                    data << uint8(0);
                }
            }
        }

        data << uint32(actualQuest->GetRewOrReqMoney());
        data << uint32(reward->reward[done].variableMoney);           // money

        uint8 rewItemCount = actualQuest->GetRewItemsCount() + actualQuest->GetRewCurrencyCount();

        data << uint8(rewItemCount);
        if (rewItemCount)
        {
            ItemTemplate const* iProto = NULL;
            for (uint8 i = 0; i < actualQuest->GetRewItemsCount(); ++i)
            {
                if (!actualQuest->RewardItemId[i])
                    continue;

                iProto = sObjectMgr->GetItemTemplate(actualQuest->RewardItemId[i]);

                data << uint32(actualQuest->RewardItemId[i]);
                if(actualQuest->RewardItemId[i])
                {
                    data << uint32(iProto ? iProto->DisplayInfoID : 0);
                    data << uint32(actualQuest->RewardItemIdCount[i]);
                }
                data << uint8(false);
            }

            CurrencyTypesEntry const* iCurr = NULL;
            for (uint8 i = 0; i < actualQuest->GetRewCurrencyCount(); ++i)
            {
                if (!actualQuest->RewardCurrencyId[i])
                    continue;
            
                iCurr = sCurrencyTypesStore.LookupEntry(actualQuest->RewardCurrencyId[i]);

                data << uint32(actualQuest->RewardCurrencyId[i]);
                if(actualQuest->RewardCurrencyId[i])
                {
                   data << uint32(0);
                   data << uint32(actualQuest->RewardCurrencyCount[i] * LFG_MULTYPLIER);  // currency amount
                }
                data << uint8(true);
            }
        }
    }
    else
    {
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);
        data << uint32(0);

        data << uint8(0);

        data << uint32(0);
        data << uint32(0);
        data << uint32(0);

        data << uint32(0);
        data << uint32(0);

        data << uint8(0);
    }
}

void BuildPartyLockDungeonBlock(WorldPacket& data, const LfgLockPartyMap& lockMap)
{
    data << uint8(lockMap.size());
    for (LfgLockPartyMap::const_iterator it = lockMap.begin(); it != lockMap.end(); ++it)
    {
        data << uint64(it->first);                         // Player guid
        BuildPlayerLockDungeonBlock(data, it->second);
    }
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
}

void WorldSession::HandleLfgJoinOpcode(WorldPacket& recvData)
{
<<<<<<< HEAD
    if (!sLFGMgr->isOptionEnabled(lfg::LFG_OPTION_ENABLE_DUNGEON_FINDER | lfg::LFG_OPTION_ENABLE_RAID_BROWSER) ||
=======
    if (!sWorld->getIntConfig(CONFIG_DUNGEON_FINDER_ENABLE) ||
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
        (GetPlayer()->GetGroup() && GetPlayer()->GetGroup()->GetLeaderGUID() != GetPlayer()->GetGUID() &&
        (GetPlayer()->GetGroup()->GetMembersCount() == MAXGROUPSIZE || !GetPlayer()->GetGroup()->isLFGGroup())))
    {
        recvData.rfinish();
        return;
    }

<<<<<<< HEAD
    uint32 roles;

    recvData >> roles;
    for (int32 i = 0; i < 3; ++i)
        recvData.read_skip<uint32>();

    uint32 commentLen = recvData.ReadBits(9);
    uint32 numDungeons = recvData.ReadBits(24);

    if (!numDungeons)
    {
        sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_JOIN %s no dungeons selected", GetPlayerInfo().c_str());
        recvData.rfinish();
        return;
    }
    std::string comment = recvData.ReadString(commentLen);

    lfg::LfgDungeonSet newDungeons;
    for (uint32 i = 0; i < numDungeons; ++i)
    {
        uint32 dungeon;
        recvData >> dungeon;
        newDungeons.insert((dungeon & 0x00FFFFFF));        // remove the type from the dungeon entry
    }

    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_JOIN %s roles: %u, Dungeons: %u, Comment: %s",
        GetPlayerInfo().c_str(), roles, uint8(newDungeons.size()), comment.c_str());

    sLFGMgr->JoinLfg(GetPlayer(), uint8(roles), newDungeons, comment);
}

void WorldSession::HandleLfgLeaveOpcode(WorldPacket& recvData)
{
    ObjectGuid leaveGuid;
    Group* group = GetPlayer()->GetGroup();
    uint64 guid = GetPlayer()->GetGUID();
    uint64 gguid = group ? group->GetGUID() : guid;

    recvData.read_skip<uint32>();                          // Always 8
    recvData.read_skip<uint32>();                          // Join date
    recvData.read_skip<uint32>();                          // Always 3
    recvData.read_skip<uint32>();                          // Queue Id

    leaveGuid[4] = recvData.ReadBit();
    leaveGuid[5] = recvData.ReadBit();
    leaveGuid[0] = recvData.ReadBit();
    leaveGuid[6] = recvData.ReadBit();
    leaveGuid[2] = recvData.ReadBit();
    leaveGuid[7] = recvData.ReadBit();
    leaveGuid[1] = recvData.ReadBit();
    leaveGuid[3] = recvData.ReadBit();

    recvData.ReadByteSeq(leaveGuid[7]);
    recvData.ReadByteSeq(leaveGuid[4]);
    recvData.ReadByteSeq(leaveGuid[3]);
    recvData.ReadByteSeq(leaveGuid[2]);
    recvData.ReadByteSeq(leaveGuid[6]);
    recvData.ReadByteSeq(leaveGuid[0]);
    recvData.ReadByteSeq(leaveGuid[1]);
    recvData.ReadByteSeq(leaveGuid[5]);

    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_LEAVE %s in group: %u sent guid " UI64FMTD ".",
        GetPlayerInfo().c_str(), group ? 1 : 0, uint64(leaveGuid));

    // Check cheating - only leader can leave the queue
    if (!group || group->GetLeaderGUID() == guid)
        sLFGMgr->LeaveLfg(gguid);
=======
    uint32 dungeon;
    uint32 roles;
    uint32 unk[3];
    std::string comment;

    recvData >> roles;

    for (int8 i = 0; i < 3; ++i)
    {
        recvData >> unk[i]; // Unknown.
    }

    uint32 length = recvData.ReadBits(9);
    uint32 count  = recvData.ReadBits(24);

    comment = recvData.ReadString(length);

    if (!count) // numDungeons.
    {
        sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFG_JOIN [" UI64FMTD "] no dungeons selected", GetPlayer()->GetGUID());
        recvData.rfinish();
        return;
    }

    LfgDungeonSet newDungeons; // numfields
    for (uint32 i = 0; i < count; ++i)
    {
        recvData >> dungeon; // dungeonentry
        newDungeons.insert((dungeon & 0x00FFFFFF));       // remove the type from the dungeon entry
    }

    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFG_JOIN [" UI64FMTD "] roles: %u, Dungeons: %u, Comment: %s", GetPlayer()->GetGUID(), roles, uint8(newDungeons.size()), comment.c_str());
    sLFGMgr->Join(GetPlayer(), uint8(roles), newDungeons, comment);
}

void WorldSession::HandleLfgLeaveOpcode(WorldPacket&  recvData)
{
    Group* grp = GetPlayer()->GetGroup();

    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFG_LEAVE [" UI64FMTD "] in group: %u", GetPlayer()->GetGUID(), grp ? 1 : 0);

    uint32 roles, time, reason, instanceid;
    ObjectGuid guid;

    recvData >> roles;
    recvData >> time;
    recvData >> reason;
    recvData >> instanceid;

    guid[4] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[5]);

    // Check cheating - only leader can leave the queue
    if (!grp || grp->GetLeaderGUID() == guid && guid == GetPlayer()->GetGUID())
        sLFGMgr->Leave(GetPlayer(), grp);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
}

void WorldSession::HandleLfgProposalResultOpcode(WorldPacket& recvData)
{
<<<<<<< HEAD
    uint32 lfgGroupID;                                     // Internal lfgGroupID
    bool accept;                                           // Accept to join?

    uint32 roles;
    uint32 ProposalID;
    recvData >> ProposalID;
    recvData.read_skip<uint32>();
    recvData.read_skip<uint32>();
    recvData.read_skip<uint32>();
    
    ObjectGuid guid1;       //Instance Guid
    ObjectGuid guid2;       //Player guid
    
=======
    ObjectGuid guid;          // Instance guid.
    ObjectGuid guid2;         // Player guid

    bool accept;              // Accept to join? is actually a bool.
    uint32 lfgGroupID;        // Internal lfgGroupID
    uint32 time;
    uint32 roles;
    uint32 unk;               // Unknown

    recvData >> lfgGroupID;
    recvData >> time;
    recvData >> roles;
    recvData >> unk;

    // Player guid
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    guid2[4] = recvData.ReadBit();
    guid2[5] = recvData.ReadBit();
    guid2[0] = recvData.ReadBit();
    guid2[6] = recvData.ReadBit();
    guid2[2] = recvData.ReadBit();
    guid2[7] = recvData.ReadBit();
    guid2[1] = recvData.ReadBit();
    guid2[3] = recvData.ReadBit();
<<<<<<< HEAD
    
=======

>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    recvData.ReadByteSeq(guid2[7]);
    recvData.ReadByteSeq(guid2[4]);
    recvData.ReadByteSeq(guid2[3]);
    recvData.ReadByteSeq(guid2[2]);
    recvData.ReadByteSeq(guid2[6]);
    recvData.ReadByteSeq(guid2[0]);
    recvData.ReadByteSeq(guid2[1]);
    recvData.ReadByteSeq(guid2[5]);

<<<<<<< HEAD
    guid1[7] = recvData.ReadBit();
    accept   = recvData.ReadBit();
    guid1[1] = recvData.ReadBit();
    guid1[3] = recvData.ReadBit();
    guid1[0] = recvData.ReadBit();
    guid1[5] = recvData.ReadBit();
    guid1[4] = recvData.ReadBit();
    guid1[6] = recvData.ReadBit();
    guid1[2] = recvData.ReadBit();

    recvData.ReadByteSeq(guid1[7]);
    recvData.ReadByteSeq(guid1[1]);
    recvData.ReadByteSeq(guid1[5]);
    recvData.ReadByteSeq(guid1[6]);
    recvData.ReadByteSeq(guid1[3]);
    recvData.ReadByteSeq(guid1[4]);
    recvData.ReadByteSeq(guid1[0]);
    recvData.ReadByteSeq(guid1[2]);
    
    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_PROPOSAL_RESULT %s proposal: %u accept: %u",
                   GetPlayerInfo().c_str(), ProposalID, accept ? 1 : 0);
    sLFGMgr->UpdateProposal(ProposalID, GetPlayer()->GetGUID(), accept);
=======
    // Instance guid - var guid = new byte[8]; ? vector?
    guid[7] = recvData.ReadBit();
    accept =  recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[2]);

    uint64 proposalId = guid;

    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFG_PROPOSAL_RESULT [" UI64FMTD "] proposal: %u accept: %u", GetPlayer()->GetGUID(), lfgGroupID, accept ? 1 : 0);
    sLFGMgr->UpdateProposal((uint32)proposalId, guid2, accept);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
}

void WorldSession::HandleLfgSetRolesOpcode(WorldPacket& recvData)
{
<<<<<<< HEAD
    uint8 roles;
    recvData >> roles;                                     // Player Group Roles
    uint64 guid = GetPlayer()->GetGUID();
    Group* group = GetPlayer()->GetGroup();
    if (!group)
    {
        sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_SET_ROLES %s Not in group",
            GetPlayerInfo().c_str());
        return;
    }
    uint64 gguid = group->GetGUID();
    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_SET_ROLES: Group %u, Player %s, Roles: %u",
        GUID_LOPART(gguid), GetPlayerInfo().c_str(), roles);
    sLFGMgr->UpdateRoleCheck(gguid, guid, roles);
=======
    uint32 roles;
    recvData >> roles;                                    // Player Group Roles

    /*ObjectGuid guid;
    guid[2] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[7]);*/

    Group* grp = GetPlayer()->GetGroup();
    if (!grp)
    {
        sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFG_SET_ROLES [" UI64FMTD "] Not in group", uint64(GetPlayer()->GetGUID()));
        return;
    }
    uint64 gguid = grp->GetGUID();
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFG_SET_ROLES: Group [" UI64FMTD "], Player [" UI64FMTD "], Roles: %u", gguid, uint64(GetPlayer()->GetGUID()), roles);
    sLFGMgr->UpdateRoleCheck(gguid, GetPlayer()->GetGUID(), roles);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
}

void WorldSession::HandleLfgSetCommentOpcode(WorldPacket&  recvData)
{
    std::string comment;
<<<<<<< HEAD
    recvData >> comment;

    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_SET_COMMENT %s comment: %s",
        GetPlayerInfo().c_str(), comment.c_str());

    sLFGMgr->SetComment(GetPlayer()->GetGUID(), comment);
=======

    uint32 length = recvData.ReadBits(9);
    comment = recvData.ReadString(length);

    uint64 guid = GetPlayer()->GetGUID();
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFG_SET_COMMENT [" UI64FMTD "] comment: %s", guid, comment.c_str());

    sLFGMgr->SetComment(guid, comment);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
}

void WorldSession::HandleLfgSetBootVoteOpcode(WorldPacket& recvData)
{
    bool agree;                                            // Agree to kick player
    recvData >> agree;

<<<<<<< HEAD
    uint64 guid = GetPlayer()->GetGUID();
    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_SET_BOOT_VOTE %s agree: %u",
        GetPlayerInfo().c_str(), agree ? 1 : 0);
    sLFGMgr->UpdateBoot(guid, agree);
=======
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFG_SET_BOOT_VOTE [" UI64FMTD "] agree: %u", GetPlayer()->GetGUID(), agree ? 1 : 0);
    sLFGMgr->UpdateBoot(GetPlayer(), agree);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
}

void WorldSession::HandleLfgTeleportOpcode(WorldPacket& recvData)
{
    bool out;
    recvData >> out;

<<<<<<< HEAD
    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_TELEPORT %s out: %u",
        GetPlayerInfo().c_str(), out ? 1 : 0);
    sLFGMgr->TeleportPlayer(GetPlayer(), out, true);
}

void WorldSession::HandleLfgGetLockInfoOpcode(WorldPacket& recvData)
{
    bool forPlayer = recvData.ReadBit();
    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_LOCK_INFO_REQUEST %s for %s", GetPlayerInfo().c_str(), (forPlayer ? "player" : "party"));

    if (forPlayer)
        SendLfgPlayerLockInfo();
    else
        SendLfgPartyLockInfo();
}

void WorldSession::SendLfgPlayerLockInfo()
{
    uint64 guid = GetPlayer()->GetGUID();

    // Get Random dungeons that can be done at a certain level and expansion
    uint8 level = GetPlayer()->getLevel();
    lfg::LfgDungeonSet const& randomDungeons =
        sLFGMgr->GetRandomAndSeasonalDungeons(level, GetPlayer()->GetSession()->Expansion());

    // Get player locked Dungeons
    lfg::LfgLockMap const& lock = sLFGMgr->GetLockedDungeons(guid);
    uint32 rsize = uint32(randomDungeons.size());
    uint32 lsize = uint32(lock.size());

    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_PLAYER_INFO %s", GetPlayerInfo().c_str());
    WorldPacket data(SMSG_LFG_PLAYER_INFO, 1 + rsize * (4 + 1 + 4 + 4 + 4 + 4 + 1 + 4 + 4 + 4) + 4 + lsize * (1 + 4 + 4 + 4 + 4 + 1 + 4 + 4 + 4));

    data << uint8(randomDungeons.size());                  // Random Dungeon count
    for (lfg::LfgDungeonSet::const_iterator it = randomDungeons.begin(); it != randomDungeons.end(); ++it)
    {
        data << uint32(*it);                               // Dungeon Entry (id + type)
        lfg::LfgReward const* reward = sLFGMgr->GetRandomDungeonReward(*it, level);
        Quest const* quest[2];
        Quest const* actualQuest = NULL;
        bool done = false;
        if (reward)
        {
            quest[0] = sObjectMgr->GetQuestTemplate(reward->firstQuest);
            quest[1] = sObjectMgr->GetQuestTemplate(reward->otherQuest);
            if (quest[0])
            {
                done = !GetPlayer()->CanRewardQuest(quest[0], false);
                if (done)
                    actualQuest = quest[1];
                else
                    actualQuest = quest[0];
            }
        }
        data << uint8(done);
        if (actualQuest)
        {
            data << uint32(actualQuest->RewardCurrencyCount[0] * LFG_MULTYPLIER); // currencyQuantity
            data << uint32(1000 * LFG_MULTYPLIER);                                // some sort of overall cap/weekly cap
            data << uint32(actualQuest->RewardCurrencyId[0]);                     // currencyID
            
            data << uint32(0);                                              // tier1Quantity
            data << uint32(1000 * LFG_MULTYPLIER);                          // tier1Limit
            data << uint32(0);                                              // overallQuantity
            data << uint32(1000 * LFG_MULTYPLIER);                          // overallLimit
            data << uint32(0);                                              // periodPurseQuantity
            data << uint32(1000 * LFG_MULTYPLIER);                          // periodPurseLimit
            if(quest[1])
            {
                data << uint32(quest[1]->RewardCurrencyCount[0] * LFG_MULTYPLIER);  // purseQuantity
                data << uint32(0);                                                  // purseLimit
            }
            else
            {
                data << uint32(0);                                          // purseQuantity
                data << uint32(0);                                          // purseLimit
            }
            data << uint32(quest[0]->RewardCurrencyCount[0] * LFG_MULTYPLIER);  // some sort of reward for completion
            data << uint32(0);                                              // completedEncounters
        }
        else
        {
            data << uint32(0);                                              // currencyQuantity
            data << uint32(0);                                              // some sort of overall cap/weekly cap
            data << uint32(0);                                              // currencyID
            data << uint32(0);                                              // tier1Quantity
            data << uint32(0);                                              // tier1Limit
            data << uint32(0);                                              // overallQuantity
            data << uint32(0);                                              // overallLimit
            data << uint32(0);                                              // periodPurseQuantity
            data << uint32(0);                                              // periodPurseLimit
            data << uint32(0);                                              // purseQuantity
            data << uint32(0);                                              // purseLimit
            data << uint32(0);                                              // some sort of reward for completion
            data << uint32(0);                                              // completedEncounters
        }
        data << uint8(0);                                               // Call to Arms eligible

        for (uint32 i = 0; i < 3; ++i)
        {
            data << uint32(0);                                          // Call to Arms Role
            //if (role)
            //    BuildQuestReward(data, ctaRoleQuest, GetPlayer());
        }
        if (actualQuest)
            BuildQuestReward(data, actualQuest, GetPlayer());

        else
        {
            data << uint32(0);                                          // Money
            data << uint32(0);                                          // XP
            data << uint8(0);                                           // Reward count
        }
    }

=======
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFG_TELEPORT [" UI64FMTD "] out: %u", GetPlayer()->GetGUID(), out ? 1 : 0);
    sLFGMgr->TeleportPlayer(GetPlayer(), out, true);
}

void WorldSession::HandleLfgPlayerLockInfoRequestOpcode(WorldPacket& recvData)
{
    uint64 guid = GetPlayer()->GetGUID();
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFD_PLAYER_LOCK_INFO_REQUEST [" UI64FMTD "]", guid);

    // Get Random dungeons that can be done at a certain level and expansion
    // FIXME - Should return seasonals (when not disabled)
    LfgDungeonsMap randomDungeons;
    uint8 level = GetPlayer()->getLevel();
    uint8 expansion = GetPlayer()->GetSession()->Expansion();
    for (uint32 i = 0; i < sLFGDungeonStore.GetNumRows(); ++i)
    {
        LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(i);
        if (dungeon && dungeon->type == LFG_TYPE_RANDOM && dungeon->expansion <= expansion &&
            dungeon->minlevel <= level && level <= dungeon->maxlevel)
                randomDungeons[dungeon->Entry()] = dungeon;
    }

    // Get player locked Dungeons
    LfgLockMap lock = sLFGMgr->GetLockedDungeons(guid);
    uint32 rsize = uint32(randomDungeons.size());
    uint32 lsize = uint32(lock.size());

    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_PLAYER_INFO [" UI64FMTD "]", guid);
    WorldPacket data(SMSG_LFG_PLAYER_INFO, 1 + rsize * (4 + 1 + 4 + 4 + 4 + 4 + 1 + 4 + 4 + 4) + 4 + lsize * (1 + 4 + 4 + 4 + 4 + 1 + 4 + 4 + 4));

    data << uint8(randomDungeons.size());                  // Random Dungeon count
    for (LfgDungeonsMap::const_iterator it = randomDungeons.begin(); it != randomDungeons.end(); ++it)
    {
        data << uint32(it->first);                               // Dungeon Entry (id + type)
        BuildLfgRewardDungeonBlock(data, GetPlayer(), sLFGMgr->GetRandomDungeonReward(it->first, level),it->second);
    }
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    BuildPlayerLockDungeonBlock(data, lock);
    SendPacket(&data);
}

<<<<<<< HEAD
void WorldSession::SendLfgPartyLockInfo()
{
    uint64 guid = GetPlayer()->GetGUID();

    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    // Get the locked dungeons of the other party members
    lfg::LfgLockPartyMap lockMap;
    for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
=======
void WorldSession::HandleLfgPartyLockInfoRequestOpcode(WorldPacket&  recvData)
{
    uint64 guid = GetPlayer()->GetGUID();
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_LFD_PARTY_LOCK_INFO_REQUEST [" UI64FMTD "]", guid);

    Group* grp = GetPlayer()->GetGroup();
    if (!grp)
        return;

    // Get the locked dungeons of the other party members
    LfgLockPartyMap lockMap;
    for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    {
        Player* plrg = itr->getSource();
        if (!plrg)
            continue;

        uint64 pguid = plrg->GetGUID();
        if (pguid == guid)
            continue;

        lockMap[pguid] = sLFGMgr->GetLockedDungeons(pguid);
    }

    uint32 size = 0;
<<<<<<< HEAD
    for (lfg::LfgLockPartyMap::const_iterator it = lockMap.begin(); it != lockMap.end(); ++it)
        size += 8 + 4 + uint32(it->second.size()) * (4 + 4 + 4 + 4);

    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_PARTY_INFO %s", GetPlayerInfo().c_str());
=======
    for (LfgLockPartyMap::const_iterator it = lockMap.begin(); it != lockMap.end(); ++it)
        size += 8 + 4 + uint32(it->second.size()) * (4 + 4 + 4 + 4);

    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_PARTY_INFO [" UI64FMTD "]", guid);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    WorldPacket data(SMSG_LFG_PARTY_INFO, 1 + size);
    BuildPartyLockDungeonBlock(data, lockMap);
    SendPacket(&data);
}

<<<<<<< HEAD
void WorldSession::HandleLfrJoinOpcode(WorldPacket& recvData)
{
    uint32 entry;                                          // Raid id to search
    recvData >> entry;
    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_LFR_JOIN %s dungeon entry: %u",
        GetPlayerInfo().c_str(), entry);
=======
void WorldSession::HandleLfrSearchOpcode(WorldPacket& recvData)
{
    uint32 entry;                                          // Raid id to search
    recvData >> entry;
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_SEARCH_LFG_JOIN [" UI64FMTD "] dungeon entry: %u", GetPlayer()->GetGUID(), entry);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    //SendLfrUpdateListOpcode(entry);
}

void WorldSession::HandleLfrLeaveOpcode(WorldPacket& recvData)
{
    uint32 dungeonId;                                      // Raid id queue to leave
    recvData >> dungeonId;
<<<<<<< HEAD
    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_LFR_LEAVE %s dungeonId: %u",
        GetPlayerInfo().c_str(), dungeonId);
    //sLFGMgr->LeaveLfr(GetPlayer(), dungeonId);
}

void WorldSession::HandleLfgGetStatus(WorldPacket& /*recvData*/)
{
    sLog->outDebug(LOG_FILTER_LFG, "CMSG_LFG_GET_STATUS %s", GetPlayerInfo().c_str());
    if (!GetPlayer()->isUsingLfg())
        return;

    uint64 guid = GetPlayer()->GetGUID();
    lfg::LfgUpdateData updateData = sLFGMgr->GetLfgStatus(guid);

    if (GetPlayer()->GetGroup())
    {
        SendLfgUpdateStatus(updateData, true);
        updateData.dungeons.clear();
        SendLfgUpdateStatus(updateData, false);
    }
    else
    {
        SendLfgUpdateStatus(updateData, false);
        updateData.dungeons.clear();
        SendLfgUpdateStatus(updateData, true);
    }
}

void WorldSession::SendLfgUpdateStatus(lfg::LfgUpdateData const& updateData, bool party)
{
    bool join = false;
    bool queued = false;
    uint8 size = uint8(updateData.dungeons.size());
    ObjectGuid guid = _player->GetGUID();
    time_t joinTime = sLFGMgr->GetQueueJoinTime(_player->GetGUID());
    uint32 queueId = sLFGMgr->GetQueueId(_player->GetGUID());

    switch (updateData.updateType)
    {
    case lfg::LFG_UPDATETYPE_JOIN_QUEUE_INITIAL: // Joined queue outside the dungeon
        join = true;
        break;
    case lfg::LFG_UPDATETYPE_JOIN_QUEUE:
    case lfg::LFG_UPDATETYPE_ADDED_TO_QUEUE: // Rolecheck Success
        join = true;
        queued = true;
        break;
    case lfg::LFG_UPDATETYPE_PROPOSAL_BEGIN:
        join = true;
        break;
    case lfg::LFG_UPDATETYPE_UPDATE_STATUS:
        join = updateData.state != lfg::LFG_STATE_ROLECHECK && updateData.state != lfg::LFG_STATE_NONE;
        queued = updateData.state == lfg::LFG_STATE_QUEUED;
        break;
    default:
        break;
    }

    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_UPDATE_STATUS %s updatetype: %u, party %s",
        GetPlayerInfo().c_str(), updateData.updateType, party ? "true" : "false");

    WorldPacket data(SMSG_LFG_UPDATE_STATUS, 1 + 8 + 3 + 2 + 1 + updateData.comment.length() + 4 + 4 + 1 + 1 + 1 + 4 + size);
    data.WriteBit(guid[1]);
    data.WriteBit(party);
    data.WriteBits(size, 24);
    data.WriteBit(guid[6]);
    data.WriteBit(size > 0); // Extra info
    data.WriteBits(updateData.comment.length(), 9);
    data.WriteBit(guid[4]);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[2]);
    data.WriteBit(join); // LFG Join
    data.WriteBit(guid[0]);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[5]);
    data.WriteBit(queued); // Join the queue

    data << uint8(updateData.updateType); // Lfg Update type
    data.WriteString(updateData.comment);
    data << uint32(queueId); // Queue Id
    data << uint32(joinTime); // Join date
    data.WriteByteSeq(guid[6]);
    for (uint8 i = 0; i < 3; ++i)
        data << uint8(0); // unk - Always 0

    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(guid[2]);
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(guid[5]);
    data.WriteByteSeq(guid[0]);
    data << uint32(3);
    data.WriteByteSeq(guid[7]);
    for (lfg::LfgDungeonSet::const_iterator it = updateData.dungeons.begin(); it != updateData.dungeons.end(); ++it)
        data << uint32(*it);

=======
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_SEARCH_LFG_LEAVE [" UI64FMTD "] dungeonId: %u", GetPlayer()->GetGUID(), dungeonId);
    //sLFGMgr->LeaveLfr(GetPlayer(), dungeonId);
}

void WorldSession::SendLfgUpdateStatus(const LfgUpdateData& updateData, bool isParty)
{
    bool queued = false;
    bool joined = false;
    bool LFGJoined = false;
    bool UnkBit = false;
    uint8 UnkByte64 = 0;

    ObjectGuid playerGuid = GetPlayer()->GetGUID();

    WorldPacket data(SMSG_LFG_UPDATE_STATUS);

    switch (updateData.updateType)
    {
        case LFG_UPDATETYPE_JOIN_PROPOSAL:
            joined = true;
			if(!isParty)
				queued = true;
            break;
        case LFG_UPDATETYPE_CLEAR_LOCK_LIST:
            // join = true;  // TODO: Sometimes queued and extrainfo - Check ocurrences...
            queued = true;
            break;
        case LFG_UPDATETYPE_PROPOSAL_BEGIN: 
			joined = true;
			if(isParty)
				LFGJoined = true;
			break;
        case LFG_UPDATETYPE_ADDED_TO_QUEUE:
            joined = true;
            queued = true;
			if(isParty)
				LFGJoined = true;
            break;
        case LFG_UPDATETYPE_GROUP_FOUND:
            UnkBit = true;
            break;
        default:
            break;
    }

    data.WriteBit(playerGuid[1]);
    data.WriteBit(UnkBit);                               //Unk Bit 65
    data.WriteBits(updateData.dungeons.size(),24);
    data.WriteBit(playerGuid[6]);
    data.WriteBit(joined);
    data.WriteBits(updateData.comment.size(),9);
    data.WriteBit(playerGuid[4]);
    data.WriteBit(playerGuid[7]);
    data.WriteBit(playerGuid[2]);
    data.WriteBit(LFGJoined);
    data.WriteBit(playerGuid[0]);
    data.WriteBit(playerGuid[3]);
    data.WriteBit(playerGuid[5]);
    data.WriteBit(queued);

    data.FlushBits();

    data << uint8(UnkByte64);                       // unk byte 64
    data.WriteString(updateData.comment);
    data << uint32(GetPlayer()->GetTeam());         // QueueID, not known how to pass it for now
    data << uint32(time(NULL));                     // joined date

    data.WriteByteSeq(playerGuid[6]);

    for(uint8 i = 0; i < 3; i++)
    {
        data << uint8(0);                           // always 0
    }

    data.WriteByteSeq(playerGuid[1]);
    data.WriteByteSeq(playerGuid[2]);
    data.WriteByteSeq(playerGuid[3]);
    data.WriteByteSeq(playerGuid[4]);
    data.WriteByteSeq(playerGuid[5]);
    data.WriteByteSeq(playerGuid[0]);

    data << int32(3);                               // Same value as "Unk_UInt32_1" in SMSG_LFG_JOIN_RESULT - Only seen 3

    data.WriteByteSeq(playerGuid[7]);

    for(LfgDungeonSet::const_iterator itr = updateData.dungeons.begin(); itr != updateData.dungeons.end(); itr++)
    {
        data << uint32(*itr);
    }

    SendPacket(&data);
}

void WorldSession::SendLfgUpdatePlayer(const LfgUpdateData& updateData)
{
    bool queued = false;
    bool extrainfo = false;

    switch (updateData.updateType)
    {
        case LFG_UPDATETYPE_JOIN_PROPOSAL:
        case LFG_UPDATETYPE_ADDED_TO_QUEUE:
            queued = true;
            extrainfo = true;
            break;
        //case LFG_UPDATETYPE_CLEAR_LOCK_LIST: // TODO: Sometimes has extrainfo - Check ocurrences...
        case LFG_UPDATETYPE_PROPOSAL_BEGIN:
            extrainfo = true;
            break;
        default:
            break;
    }

    uint64 guid = GetPlayer()->GetGUID();
    uint8 size = uint8(updateData.dungeons.size());

    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_UPDATE_PLAYER [" UI64FMTD "] updatetype: %u", guid, updateData.updateType);
    WorldPacket data(SMSG_LFG_UPDATE_PLAYER, 1 + 1 + (extrainfo ? 1 : 0) * (1 + 1 + 1 + 1 + size * 4 + updateData.comment.length()));
    data << uint8(updateData.updateType);                 // Lfg Update type
    data << uint8(extrainfo);                             // Extra info
    if (extrainfo)
    {
        data << uint8(queued);                            // Join the queue
        data << uint8(0);                                 // unk - Always 0
        data << uint8(0);                                 // unk - Always 0

        data << uint8(size);
        if (size)
            for (LfgDungeonSet::const_iterator it = updateData.dungeons.begin(); it != updateData.dungeons.end(); ++it)
                data << uint32(*it);
        data << updateData.comment;
    }
    SendPacket(&data);
}

void WorldSession::SendLfgUpdateParty(const LfgUpdateData& updateData)
{
    bool join = false;
    bool extrainfo = false;
    bool queued = false;

    switch (updateData.updateType)
    {
        case LFG_UPDATETYPE_JOIN_PROPOSAL:
            extrainfo = true;
            break;
        case LFG_UPDATETYPE_ADDED_TO_QUEUE:
            extrainfo = true;
            join = true;
            queued = true;
            break;
        case LFG_UPDATETYPE_CLEAR_LOCK_LIST:
            // join = true;  // TODO: Sometimes queued and extrainfo - Check ocurrences...
            queued = true;
            break;
        case LFG_UPDATETYPE_PROPOSAL_BEGIN:
            extrainfo = true;
            join = true;
            break;
        default:
            break;
    }

    uint64 guid = GetPlayer()->GetGUID();
    uint8 size = uint8(updateData.dungeons.size());

    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_UPDATE_PARTY [" UI64FMTD "] updatetype: %u", guid, updateData.updateType);
    WorldPacket data(SMSG_LFG_UPDATE_PARTY, 1 + 1 + (extrainfo ? 1 : 0) * (1 + 1 + 1 + 1 + 1 + size * 4 + updateData.comment.length()));
    data << uint8(updateData.updateType);                 // Lfg Update type
    data << uint8(extrainfo);                             // Extra info
    if (extrainfo)
    {
        data << uint8(join);                              // LFG Join
        data << uint8(queued);                            // Join the queue
        data << uint8(0);                                 // unk - Always 0
        data << uint8(0);                                 // unk - Always 0
        for (uint8 i = 0; i < 3; ++i)
            data << uint8(0);                             // unk - Always 0

        data << uint8(size);
        if (size)
            for (LfgDungeonSet::const_iterator it = updateData.dungeons.begin(); it != updateData.dungeons.end(); ++it)
                data << uint32(*it);
        data << updateData.comment;
    }
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    SendPacket(&data);
}

void WorldSession::SendLfgRoleChosen(uint64 guid, uint8 roles)
{
<<<<<<< HEAD
    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_ROLE_CHOSEN %s guid: %u roles: %u",
        GetPlayerInfo().c_str(), GUID_LOPART(guid), roles);
=======
    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_ROLE_CHOSEN [" UI64FMTD "] guid: [" UI64FMTD "] roles: %u", GetPlayer()->GetGUID(), guid, roles);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f

    WorldPacket data(SMSG_LFG_ROLE_CHOSEN, 8 + 1 + 4);
    data << uint64(guid);                                  // Guid
    data << uint8(roles > 0);                              // Ready
<<<<<<< HEAD
    data << uint32(roles);                                 // Roles
    SendPacket(&data);
}

void WorldSession::SendLfgRoleCheckUpdate(lfg::LfgRoleCheck const& roleCheck)
{
    lfg::LfgDungeonSet dungeons;
    if (roleCheck.rDungeonId)
        dungeons.insert(roleCheck.rDungeonId);
    else
        dungeons = roleCheck.dungeons;

    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_ROLE_CHECK_UPDATE %s", GetPlayerInfo().c_str());
    WorldPacket data(SMSG_LFG_ROLE_CHECK_UPDATE, 4 + 1 + 1 + dungeons.size() * 4 + 1 + roleCheck.roles.size() * (8 + 1 + 4 + 1));

    data << uint32(roleCheck.state);                       // Check result
    data << uint8(roleCheck.state == lfg::LFG_ROLECHECK_INITIALITING);
    data << uint8(dungeons.size());                        // Number of dungeons
    if (!dungeons.empty())
        for (lfg::LfgDungeonSet::iterator it = dungeons.begin(); it != dungeons.end(); ++it)
            data << uint32(sLFGMgr->GetLFGDungeonEntry(*it)); // Dungeon

    data << uint8(roleCheck.roles.size());                 // Players in group
    if (!roleCheck.roles.empty())
    {
        // Leader info MUST be sent 1st :S
        uint64 guid = roleCheck.leader;
        uint8 roles = roleCheck.roles.find(guid)->second;
        Player* player = ObjectAccessor::FindPlayer(guid);
        data << uint64(guid);                              // Guid
        data << uint8(roles > 0);                          // Ready
        data << uint32(roles);                             // Roles
        data << uint8(player ? player->getLevel() : 0);    // Level

        for (lfg::LfgRolesMap::const_iterator it = roleCheck.roles.begin(); it != roleCheck.roles.end(); ++it)
        {
            if (it->first == roleCheck.leader)
=======
    data << int32(roles);                                  // Roles
    SendPacket(&data);
}

void WorldSession::SendLfgRoleCheckUpdate(const LfgRoleCheck* pRoleCheck)
{
    ASSERT(pRoleCheck);
    LfgDungeonSet dungeons;
    if (pRoleCheck->rDungeonId)
        dungeons.insert(pRoleCheck->rDungeonId);
    else
        dungeons = pRoleCheck->dungeons;

    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_ROLE_CHECK_UPDATE [" UI64FMTD "]", GetPlayer()->GetGUID());
    WorldPacket data(SMSG_LFG_ROLE_CHECK_UPDATE, 4 + 1 + 1 + dungeons.size() * 4 + 1 + pRoleCheck->roles.size() * (8 + 1 + 4 + 1));

    data << uint32(pRoleCheck->state);                     // Check result
    data << uint8(pRoleCheck->state == LFG_ROLECHECK_INITIALITING);
    data << uint8(dungeons.size());                        // Number of dungeons
    if (!dungeons.empty())
    {
        for (LfgDungeonSet::iterator it = dungeons.begin(); it != dungeons.end(); ++it)
        {
            LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(*it);
            data << uint32(dungeon ? dungeon->Entry() : 0); // Dungeon
        }
    }

    data << uint8(pRoleCheck->roles.size());               // Players in group
    if (!pRoleCheck->roles.empty())
    {
        // Leader info MUST be sent 1st :S
        uint64 guid = pRoleCheck->leader;
        uint8 roles = pRoleCheck->roles.find(guid)->second;
        data << uint64(guid);                              // Guid
        data << uint8(roles > 0);                          // Ready
        data << uint32(roles);                             // Roles
        Player* player = ObjectAccessor::FindPlayer(guid);
        data << uint8(player ? player->getLevel() : 0);          // Level

        for (LfgRolesMap::const_iterator it = pRoleCheck->roles.begin(); it != pRoleCheck->roles.end(); ++it)
        {
            if (it->first == pRoleCheck->leader)
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
                continue;

            guid = it->first;
            roles = it->second;
<<<<<<< HEAD
            player = ObjectAccessor::FindPlayer(guid);
            data << uint64(guid);                          // Guid
            data << uint8(roles > 0);                      // Ready
            data << uint32(roles);                         // Roles
            data << uint8(player ? player->getLevel() : 0);// Level
=======
            data << uint64(guid);                          // Guid
            data << uint8(roles > 0);                      // Ready
            data << uint32(roles);                         // Roles
            player = ObjectAccessor::FindPlayer(guid);
            data << uint8(player ? player->getLevel() : 0);      // Level
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
        }
    }
    SendPacket(&data);
}

<<<<<<< HEAD
void WorldSession::SendLfgJoinResult(lfg::LfgJoinResultData const& joinData)
{
    uint32 size = 0;
    ObjectGuid guid = GetPlayer()->GetGUID();
    uint32 queueId = sLFGMgr->GetQueueId(_player->GetGUID());
    for (lfg::LfgLockPartyMap::const_iterator it = joinData.lockmap.begin(); it != joinData.lockmap.end(); ++it)
        size += 8 + 4 + uint32(it->second.size()) * (4 + 4 + 4 + 4);

    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_JOIN_RESULT %s checkResult: %u checkValue: %u",
        GetPlayerInfo().c_str(), joinData.result, joinData.state);

    WorldPacket data(SMSG_LFG_JOIN_RESULT, 4 + 4 + size);
    data << uint32(3);
    data << uint8(joinData.result); // Check Result
    data << uint32(queueId); // Queue Id
    data << uint8(joinData.state); // Check Value
    data << uint32(time(NULL)); // Join date
    data.WriteBit(guid[2]);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[0]);
    data.WriteBits(joinData.lockmap.size(), 24);
    for (lfg::LfgLockPartyMap::const_iterator it = joinData.lockmap.begin(); it != joinData.lockmap.end(); ++it)
    {
        ObjectGuid playerGuid = it->first;
        data.WriteBit(playerGuid[7]);
        data.WriteBit(playerGuid[5]);
        data.WriteBit(playerGuid[3]);
        data.WriteBit(playerGuid[6]);
        data.WriteBit(playerGuid[0]);
        data.WriteBit(playerGuid[2]);
        data.WriteBit(playerGuid[4]);
        data.WriteBit(playerGuid[1]);
        data.WriteBits(it->second.size(), 22);
    }

    data.WriteBit(guid[4]);
    data.WriteBit(guid[5]);
    data.WriteBit(guid[1]);
    data.WriteBit(guid[6]);
    for (lfg::LfgLockPartyMap::const_iterator it = joinData.lockmap.begin(); it != joinData.lockmap.end(); ++it)
    {
        ObjectGuid playerGuid = it->first;
        for (lfg::LfgLockMap::const_iterator itr = it->second.begin(); itr != it->second.end(); ++itr)
        {
            data << uint32(itr->second.locktyp); // Lock status
            data << uint32(itr->second.averageItemlevel); // Current itemLevel
            data << uint32(itr->second.neededItemlevel); // Required itemLevel
            data << uint32(itr->first); // Dungeon entry (id + type)
        }

        data.WriteByteSeq(playerGuid[2]);
        data.WriteByteSeq(playerGuid[5]);
        data.WriteByteSeq(playerGuid[1]);
        data.WriteByteSeq(playerGuid[0]);
        data.WriteByteSeq(playerGuid[4]);
        data.WriteByteSeq(playerGuid[3]);
        data.WriteByteSeq(playerGuid[6]);
        data.WriteByteSeq(playerGuid[7]);
    }

    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(guid[5]);
    data.WriteByteSeq(guid[0]);
    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(guid[2]);
    data.WriteByteSeq(guid[6]);
=======
void WorldSession::SendLfgJoinResult(const LfgJoinResultData& joinData)
{
    uint32 queueId = GetPlayer()->GetTeam();
    uint32 size = 0;
    ObjectGuid playerGuid = GetPlayer()->GetGUID();
    for (LfgLockPartyMap::const_iterator it = joinData.lockmap.begin(); it != joinData.lockmap.end(); ++it)
        size += 8 + 4 + uint32(it->second.size()) * (4 + 4 + 4 + 4);

    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_JOIN_RESULT [" UI64FMTD "] checkResult: %u checkValue: %u", GetPlayer()->GetGUID(), joinData.result, joinData.state);
    WorldPacket data(SMSG_LFG_JOIN_RESULT);

    data << uint32(3);                                      //Unk_UInt32_1
    data << uint8(joinData.result);                         //Check Result
    data << uint32(queueId);
    data << uint8(joinData.state);                          // state
    data << uint32(sLFGMgr->GetJoinedTime(GetPlayer()->GetGUID()));

    data.WriteBit(playerGuid[2]);
    data.WriteBit(playerGuid[7]);
    data.WriteBit(playerGuid[3]);
    data.WriteBit(playerGuid[0]);

    data.WriteBits(joinData.lockmap.size(),24);

    for(LfgLockPartyMap::const_iterator itr = joinData.lockmap.begin(); itr != joinData.lockmap.end(); ++itr)
    {
        ObjectGuid playerGuid1 = itr->first;
        data.WriteBit(playerGuid1[7]);
        data.WriteBit(playerGuid1[5]);
        data.WriteBit(playerGuid1[3]);
        data.WriteBit(playerGuid1[6]);
        data.WriteBit(playerGuid1[0]);
        data.WriteBit(playerGuid1[2]);
        data.WriteBit(playerGuid1[4]);
        data.WriteBit(playerGuid1[1]);
        data.WriteBits(itr->second.size(),22);
    }

    data.WriteBit(playerGuid[4]);
    data.WriteBit(playerGuid[5]);
    data.WriteBit(playerGuid[1]);
    data.WriteBit(playerGuid[6]);

    data.FlushBits();

    for(LfgLockPartyMap::const_iterator itr = joinData.lockmap.begin(); itr != joinData.lockmap.end(); ++itr)
    {
        for (LfgLockMap::const_iterator itr1 = itr->second.begin(); itr1 != itr->second.end(); ++itr1)
        {
            data << uint32(itr1->first);                         // Dungeon entry (id + type)
            data << uint32(itr1->second);                        // Lock status
            data << uint32(0);                                   // needed ILvL
            data << uint32(0);                                   // player ILvL
        }

        ObjectGuid playerGuid1 = itr->first;

        data.WriteByteSeq(playerGuid1[2]);
        data.WriteByteSeq(playerGuid1[5]);
        data.WriteByteSeq(playerGuid1[1]);
        data.WriteByteSeq(playerGuid1[0]);
        data.WriteByteSeq(playerGuid1[4]);
        data.WriteByteSeq(playerGuid1[3]);
        data.WriteByteSeq(playerGuid1[6]);
        data.WriteByteSeq(playerGuid1[7]);
    }

    data.WriteByteSeq(playerGuid[1]);
    data.WriteByteSeq(playerGuid[7]);
    data.WriteByteSeq(playerGuid[3]);
    data.WriteByteSeq(playerGuid[5]);
    data.WriteByteSeq(playerGuid[0]);
    data.WriteByteSeq(playerGuid[7]);
    data.WriteByteSeq(playerGuid[2]);
    data.WriteByteSeq(playerGuid[6]);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f

    SendPacket(&data);
}

<<<<<<< HEAD
void WorldSession::SendLfgQueueStatus(lfg::LfgQueueStatusData const& queueData)
{
    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_QUEUE_STATUS %s dungeon: %u, waitTime: %d, "
        "avgWaitTime: %d, waitTimeTanks: %d, waitTimeHealer: %d, waitTimeDps: %d, "
        "queuedTime: %u, tanks: %u, healers: %u, dps: %u",
        GetPlayerInfo().c_str(), queueData.dungeonId, queueData.waitTime, queueData.waitTimeAvg,
        queueData.waitTimeTank, queueData.waitTimeHealer, queueData.waitTimeDps,
        queueData.queuedTime, queueData.tanks, queueData.healers, queueData.dps);

    ObjectGuid guid = _player->GetGUID();
    WorldPacket data(SMSG_LFG_QUEUE_STATUS, 4 + 4 + 4 + 4 + 4 + 4 + 1 + 1 + 1 + 4 + 4 + 4 + 4 + 8);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[0]);
    data.WriteBit(guid[2]);
    data.WriteBit(guid[6]);
    data.WriteBit(guid[5]);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[1]);
    data.WriteBit(guid[4]);

    data.WriteByteSeq(guid[0]);
    data << uint8(queueData.tanks);                        // Tanks needed
    data << int32(queueData.waitTimeTank);                 // Wait Tanks
    data << uint8(queueData.healers);                      // Healers needed
    data << int32(queueData.waitTimeHealer);               // Wait Healers
    data << uint8(queueData.dps);                          // Dps needed
    data << int32(queueData.waitTimeDps);                  // Wait Dps
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[6]);
    data << int32(queueData.waitTime);                     // Wait Time
    data << uint32(queueData.joinTime);                    // Join time
    data << uint32(queueData.dungeonId);                   // Dungeon
    data << uint32(queueData.queuedTime);                  // Player wait time in queue
    data.WriteByteSeq(guid[5]);
    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(guid[3]);
    data << uint32(queueData.queueId);                     // Queue Id
    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(guid[2]);
    data << int32(queueData.waitTimeAvg);                  // Average Wait time
    data << uint32(3);
=======
/*void WorldSession::HandleGetLfgStatus(WorldPacket& recvData) // Placeholder, empty cmsg requesting queue status ?
{
  GetPlayer()->GetSession()->SendLfgQueueStatus();
}*/

void WorldSession::SendLfgQueueStatus(uint32 dungeon, int32 waitTime, int32 avgWaitTime, int32 waitTimeTanks, int32 waitTimeHealer, int32 waitTimeDps, uint32 queuedTime, uint8 tanks, uint8 healers, uint8 dps)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_QUEUE_STATUS [" UI64FMTD "] dungeon: %u - waitTime: %d - avgWaitTime: %d - waitTimeTanks: %d - waitTimeHealer: %d - waitTimeDps: %d - queuedTime: %u - tanks: %u - healers: %u - dps: %u", GetPlayer()->GetGUID(), dungeon, waitTime, avgWaitTime, waitTimeTanks, waitTimeHealer, waitTimeDps, queuedTime, tanks, healers, dps);
    uint32 queueId = GetPlayer()->GetTeam();
    int32 joinTime = sLFGMgr->GetJoinedTime(GetPlayer()->GetGUID());
    ObjectGuid playerGuid = GetPlayer()->GetGUID();

    WorldPacket data(SMSG_LFG_QUEUE_STATUS);
    
    data.WriteBit(playerGuid[3]);
    data.WriteBit(playerGuid[2]);
    data.WriteBit(playerGuid[0]);
    data.WriteBit(playerGuid[6]);
    data.WriteBit(playerGuid[5]);
    data.WriteBit(playerGuid[7]);
    data.WriteBit(playerGuid[1]);
    data.WriteBit(playerGuid[4]);

    data.FlushBits();

    data.WriteByteSeq(playerGuid[0]);

    data << uint8(tanks);                      //Tank Unk
    data << int32(waitTimeTanks); 
    data << uint8(healers);                    //Healer Unk
    data << int32(waitTimeHealer);
    data << uint8(dps);                        //DPS Unk
    data << int32(waitTimeDps);

    data.WriteByteSeq(playerGuid[4]);
    data.WriteByteSeq(playerGuid[6]);

    data << int32(avgWaitTime);               // Average Wait time
    data << int32(joinTime);                  // Join Time
    data << uint32(dungeon);                  // Dungeon
    data << int32(queuedTime);                // Player wait time in queue

    data.WriteByteSeq(playerGuid[5]);
    data.WriteByteSeq(playerGuid[7]);
    data.WriteByteSeq(playerGuid[3]);

    data << uint32(queueId);                 // queueId

    data.WriteByteSeq(playerGuid[1]);
    data.WriteByteSeq(playerGuid[2]);

    data << int32(waitTime);                 // Wait Time, if == -1, it wont show average wait time and time in queue
    data << int32(3);                        // Unk_UInt32_1
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f

    SendPacket(&data);
}

<<<<<<< HEAD
void WorldSession::SendLfgPlayerReward(lfg::LfgPlayerRewardData const& rewardData)
{
    if (!rewardData.rdungeonEntry || !rewardData.sdungeonEntry || !rewardData.quest)
        return;

    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_PLAYER_REWARD %s rdungeonEntry: %u, sdungeonEntry: %u, done: %u",
        GetPlayerInfo().c_str(), rewardData.rdungeonEntry, rewardData.sdungeonEntry, rewardData.done);

    uint8 itemNum = rewardData.quest->GetRewItemsCount() + rewardData.quest->GetRewCurrencyCount();

    WorldPacket data(SMSG_LFG_PLAYER_REWARD, 4 + 4 + 1 + 4 + 4 + 4 + 4 + 4 + 1 + itemNum * (4 + 4 + 4));
    data << uint32(rewardData.rdungeonEntry);                               // Random Dungeon Finished
    data << uint32(rewardData.sdungeonEntry);                               // Dungeon Finished
    BuildQuestReward(data, rewardData.quest, GetPlayer());
    SendPacket(&data);
}

void WorldSession::SendLfgBootProposalUpdate(lfg::LfgPlayerBoot const& boot)
{
    uint64 guid = GetPlayer()->GetGUID();
    lfg::LfgAnswer playerVote = boot.votes.find(guid)->second;
    uint8 votesNum = 0;
    uint8 agreeNum = 0;
    uint32 secsleft = uint8((boot.cancelTime - time(NULL)) / 1000);
    for (lfg::LfgAnswerContainer::const_iterator it = boot.votes.begin(); it != boot.votes.end(); ++it)
    {
        if (it->second != lfg::LFG_ANSWER_PENDING)
        {
            ++votesNum;
            if (it->second == lfg::LFG_ANSWER_AGREE)
                ++agreeNum;
        }
    }
    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_BOOT_PROPOSAL_UPDATE %s inProgress: %u - "
        "didVote: %u - agree: %u - victim: %u votes: %u - agrees: %u - left: %u - "
        "needed: %u - reason %s",
        GetPlayerInfo().c_str(), uint8(boot.inProgress), uint8(playerVote != lfg::LFG_ANSWER_PENDING),
        uint8(playerVote == lfg::LFG_ANSWER_AGREE), GUID_LOPART(boot.victim), votesNum, agreeNum,
        secsleft, lfg::LFG_GROUP_KICK_VOTES_NEEDED, boot.reason.c_str());
    
    WorldPacket data(SMSG_LFG_BOOT_PROPOSAL_UPDATE, 1 + 1 + 1 + 1 + 8 + 4 + 4 + 4 + 4 + boot.reason.length());
    data << uint8(boot.inProgress);                                 // Vote in progress
    data << uint8(agreeNum >= lfg::LFG_GROUP_KICK_VOTES_NEEDED);    // Did succeed
    data << uint8(playerVote != lfg::LFG_ANSWER_PENDING);           // Did Vote
    data << uint8(playerVote == lfg::LFG_ANSWER_AGREE);             // Agree
    data << uint64(boot.victim);                                    // Victim GUID
    data << uint32(votesNum);                                       // Total Votes
    data << uint32(agreeNum);                                       // Agree Count
    data << uint32(secsleft);                                       // Time Left
    data << uint32(lfg::LFG_GROUP_KICK_VOTES_NEEDED);               // Needed Votes
    data << boot.reason.c_str();                                    // Kick reason
    SendPacket(&data);
}

void WorldSession::SendLfgUpdateProposal(lfg::LfgProposal const& proposal)
{
    uint64 guid = GetPlayer()->GetGUID();
    uint64 gguid = proposal.players.find(guid)->second.group;
    bool silent = !proposal.isNew && gguid == proposal.group;
    uint32 dungeonEntry = proposal.dungeonId;

    uint32 queueId = sLFGMgr->GetQueueId(_player->GetGUID()); 
    time_t joinTime = sLFGMgr->GetQueueJoinTime(_player->GetGUID());
    

    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_PROPOSAL_UPDATE %s state: %u",
        GetPlayerInfo().c_str(), proposal.state);

    // show random dungeon if player selected random dungeon and it's not lfg group
    if (!silent)
    {
        lfg::LfgDungeonSet const& playerDungeons = sLFGMgr->GetSelectedDungeons(guid);
        if (playerDungeons.find(proposal.dungeonId) == playerDungeons.end())
            dungeonEntry = (*playerDungeons.begin());
    }

    dungeonEntry = sLFGMgr->GetLFGDungeonEntry(dungeonEntry);

    uint8 count = proposal.players.size();
    
    WorldPacket data(SMSG_LFG_PROPOSAL_UPDATE, 4 + 1 + 4 + 4 + 1 + 1 + proposal.players.size() * (4 + 1 + 1 + 1 + 1 +1));
    data << uint32(joinTime);               // Dungeon
    data << uint32(proposal.encounters);                   // encounters done
    data << uint32(queueId);
    data << uint32(3);
    data << uint32(dungeonEntry);                          // Dungeon
    data << uint32(proposal.id);
    data << uint8(proposal.state);                         // Proposal sta6te
    
    ObjectGuid guid1 = guid;
    ObjectGuid guid2 = gguid;
    
    data.WriteBit(guid2[4]);
    data.WriteBit(guid1[3]);
    data.WriteBit(guid1[7]);
    data.WriteBit(guid1[0]);
    data.WriteBit(guid2[1]);
    
    data.WriteBit(silent);                                 // Show proposal window

    data.WriteBit(guid1[4]);
    data.WriteBit(guid1[5]);
    data.WriteBit(guid2[3]);
    
    data.WriteBits(count,23);           //count
    data.WriteBit(guid2[7]);
    
    for (lfg::LfgProposalPlayerContainer::const_iterator it = proposal.players.begin(); it != proposal.players.end(); ++it)
    {
        lfg::LfgProposalPlayer const& player = it->second;
        if (!player.group)                                 // Player not it a group
        {
            data.WriteBit(0);
            data.WriteBit(0);
        }
        else
        {
            data.WriteBit(player.group == proposal.group); // In dungeon (silent)
            data.WriteBit(player.group == gguid);          // Same Group than player
        }
        data.WriteBit(player.accept != lfg::LFG_ANSWER_PENDING);// Answered
        data.WriteBit(player.accept == lfg::LFG_ANSWER_AGREE);  // Accepted
        
        data.WriteBit(it->first == guid);
        
    }

    data.WriteBit(guid2[5]);
    data.WriteBit(guid1[6]);
    data.WriteBit(guid2[2]);
    data.WriteBit(guid2[6]);
    data.WriteBit(guid1[2]);
    data.WriteBit(guid1[1]);
    data.WriteBit(guid2[0]);
    
    data.WriteByteSeq(guid1[5]);
    data.WriteByteSeq(guid2[3]);
    data.WriteByteSeq(guid2[6]);
    data.WriteByteSeq(guid1[6]);
    data.WriteByteSeq(guid1[0]);
    data.WriteByteSeq(guid2[5]);
    data.WriteByteSeq(guid1[1]);


    for (lfg::LfgProposalPlayerContainer::const_iterator it = proposal.players.begin(); it != proposal.players.end(); ++it)
    {
        lfg::LfgProposalPlayer const& player = it->second;
        data << uint32(player.role);                       // Role
    }

    data.WriteByteSeq(guid2[7]);
    data.WriteByteSeq(guid1[4]);
    data.WriteByteSeq(guid2[0]);
    data.WriteByteSeq(guid2[1]);
    data.WriteByteSeq(guid1[2]);
    data.WriteByteSeq(guid1[7]);
    data.WriteByteSeq(guid2[2]);
    data.WriteByteSeq(guid1[3]);
    data.WriteByteSeq(guid2[4]);
    
    SendPacket(&data);
}

void WorldSession::SendLfgLfrList(bool update)
{
    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_LFR_LIST %s update: %u",
        GetPlayerInfo().c_str(), update ? 1 : 0);
=======
void WorldSession::SendLfgPlayerReward(uint32 rdungeonEntry, uint32 sdungeonEntry, uint8 done, const LfgReward* reward, const Quest* qRew)
{
    if (!rdungeonEntry || !sdungeonEntry || !qRew)
        return;

    uint8 itemNum = uint8(qRew ? qRew->GetRewItemsCount() + qRew->GetRewCurrencyCount() : 0);

    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_PLAYER_REWARD [" UI64FMTD "] rdungeonEntry: %u - sdungeonEntry: %u - done: %u", GetPlayer()->GetGUID(), rdungeonEntry, sdungeonEntry, done);
    WorldPacket data(SMSG_LFG_PLAYER_REWARD, 4 + 4 + 1 + 4 + 4 + 4 + 4 + 4 + 1 + itemNum * (4 + 4 + 4));
    data << uint32(rdungeonEntry);                         // Random Dungeon Finished
    data << uint32(sdungeonEntry);                         // Dungeon Finished
    data << uint32(qRew->GetRewOrReqMoney());
    data << uint32(qRew->XPValue(GetPlayer()));
    data << uint8(itemNum);
    if (itemNum)
    {
        ItemTemplate const* iProto = NULL;
        for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        {
            if (!qRew->RewardItemId[i])
            {
                data << uint32(0) << uint32(0) << uint32(0) << uint8(0);
                continue;
            }

            iProto = sObjectMgr->GetItemTemplate(qRew->RewardItemId[i]);

            data << uint32(qRew->RewardItemId[i]);
            data << uint32(iProto ? iProto->DisplayInfoID : 0);
            data << uint32(qRew->RewardItemIdCount[i]);
            data << uint8(false);       // isCurrency
        }

        CurrencyTypesEntry const* iCurr = NULL;
        for (uint8 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        {
            if (!qRew->RewardCurrencyId[i])
            {
                data << uint32(0) << uint32(0) << uint32(0) << uint8(0);
                continue;
            }

            iCurr = sCurrencyTypesStore.LookupEntry(qRew->RewardCurrencyId[i]);

            data << uint32(qRew->RewardCurrencyId[i]);
            data << uint32(0);
            data << uint32(qRew->RewardCurrencyCount[i]);  // currency amount
            data << uint8(true);       // isCurrency
        }
    }
    SendPacket(&data);
}

void WorldSession::SendLfgBootPlayer(const LfgPlayerBoot* pBoot)
{
    uint64 guid = GetPlayer()->GetGUID();
    LfgAnswer playerVote = pBoot->votes.find(guid)->second;
    uint8 votesNum = 0;
    uint8 agreeNum = 0;
    uint32 secsleft = uint8((pBoot->cancelTime - time(NULL)) / 1000);
    for (LfgAnswerMap::const_iterator it = pBoot->votes.begin(); it != pBoot->votes.end(); ++it)
    {
        if (it->second != LFG_ANSWER_PENDING)
        {
            ++votesNum;
            if (it->second == LFG_ANSWER_AGREE)
                ++agreeNum;
        }
    }
    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_BOOT_PROPOSAL_UPDATE [" UI64FMTD "] inProgress: %u - didVote: %u - agree: %u - victim: [" UI64FMTD "] votes: %u - agrees: %u - left: %u - needed: %u - reason %s",
        guid, uint8(pBoot->inProgress), uint8(playerVote != LFG_ANSWER_PENDING), uint8(playerVote == LFG_ANSWER_AGREE), pBoot->victim, votesNum, agreeNum, secsleft, pBoot->votedNeeded, pBoot->reason.c_str());
    WorldPacket data(SMSG_LFG_BOOT_PROPOSAL_UPDATE, 1 + 1 + 1 + 8 + 4 + 4 + 4 + 4 + pBoot->reason.length());
    data << uint8(pBoot->inProgress);                      // Vote in progress
    data << uint8(playerVote != LFG_ANSWER_PENDING);       // Did Vote
    data << uint8(playerVote == LFG_ANSWER_AGREE);         // Agree
    data << uint8(0);                                      // Unknown 4.2.2
    data << uint64(pBoot->victim);                         // Victim GUID
    data << uint32(votesNum);                              // Total Votes
    data << uint32(agreeNum);                              // Agree Count
    data << uint32(secsleft);                              // Time Left
    data << uint32(pBoot->votedNeeded);                    // Needed Votes
    data << pBoot->reason.c_str();                         // Kick reason
    SendPacket(&data);
}

void WorldSession::SendLfgUpdateProposal(uint32 proposalId, const LfgProposal* pProp)
{
    if (!pProp)
        return;

    ObjectGuid guid = GetPlayer()->GetGUID();
    ObjectGuid proposalGuid = (uint64)proposalId;

    LfgProposalPlayerMap::const_iterator itPlayer = pProp->players.find(guid);
    if (itPlayer == pProp->players.end())                  // Player MUST be in the proposal
        return;

    LfgProposalPlayer* ppPlayer = itPlayer->second;

    bool isSameDungeon = false;
    bool isContinue = false;
    uint32 completedEncounters = 0;
    uint32 pLowGroupGuid = ppPlayer->groupLowGuid;
    uint32 dLowGuid = pProp->groupLowGuid;
    uint32 dungeonId = pProp->dungeonId;
    uint32 queueId = GetPlayer()->GetTeam();
    uint32 UnkDWord3 = 0x7D484000;                          /// value taken from sniff, it must be != 0 to show to enter dungeon dialogue. Still unknown if it is static like 3 or dynamic

    Group* grp = dLowGuid ? sGroupMgr->GetGroupByGUID(dLowGuid) : NULL;
    
    if (grp)
    {
        uint64 gguid = grp->GetGUID();
        isContinue = grp->isLFGGroup() && sLFGMgr->GetState(gguid) != LFG_STATE_FINISHED_DUNGEON;
        isSameDungeon = GetPlayer()->GetGroup() == grp && isContinue;
    }

    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_PROPOSAL_UPDATE [" UI64FMTD "] state: %u", GetPlayer()->GetGUID(), pProp->state);
    WorldPacket data(SMSG_LFG_PROPOSAL_UPDATE);

    if (!isContinue)                                       // Only show proposal dungeon if it's continue
    {
        LfgDungeonSet playerDungeons = sLFGMgr->GetSelectedDungeons(guid);
        if (playerDungeons.size() == 1)
            dungeonId = (*playerDungeons.begin());
    }

    if (LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(dungeonId))
    {
        dungeonId = dungeon->Entry();

        // Select a player inside to be get completed encounters from
        if (grp)
        {
            for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* groupMember = itr->getSource();
                if (groupMember && groupMember->GetMapId() == uint32(dungeon->map))
                {
                    if (InstanceScript* instance = groupMember->GetInstanceScript())
                        completedEncounters = instance->GetCompletedEncounterMask();
                    break;
                }
            }
        }
    }

    data << uint32(time(NULL));
    data << int32(completedEncounters);
    data << int32(queueId);                             // queue ID
    data << uint32(3);                                  // the always 3 thing
    data << uint32(dungeonId);
    data << uint32(UnkDWord3);                          // Unk UInt32 3
    data << uint8(pProp->state);

    data.WriteBit(proposalGuid[4]);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[0]);
    data.WriteBit(proposalGuid[1]);
    data.WriteBit(isSameDungeon);
    data.WriteBit(guid[4]);
    data.WriteBit(guid[5]);
    data.WriteBit(proposalGuid[3]);
    data.WriteBits(pProp->players.size(),23);
    data.WriteBit(proposalGuid[7]);

    for(LfgProposalPlayerMap::const_iterator itr = pProp->players.begin(); itr != pProp->players.end(); ++itr)
    {
        data.WriteBit(itr->second->groupLowGuid == dLowGuid);
        data.WriteBit(itr->second->groupLowGuid == pLowGroupGuid);
        data.WriteBit(itr->second->accept == LFG_ANSWER_AGREE);
        data.WriteBit(itr->second->accept != LFG_ANSWER_PENDING);
        data.WriteBit(itr->first == guid);
    }

    data.WriteBit(proposalGuid[5]);
    data.WriteBit(guid[6]);
    data.WriteBit(proposalGuid[2]);
    data.WriteBit(proposalGuid[6]);
    data.WriteBit(guid[2]);
    data.WriteBit(guid[1]);
    data.WriteBit(proposalGuid[0]);

    data.FlushBits();

    data.WriteByteSeq(guid[5]);
    data.WriteByteSeq(proposalGuid[3]);
    data.WriteByteSeq(proposalGuid[6]);
    data.WriteByteSeq(guid[6]);
    data.WriteByteSeq(guid[0]);
    data.WriteByteSeq(proposalGuid[5]);
    data.WriteByteSeq(guid[1]);

    for(LfgProposalPlayerMap::const_iterator itr = pProp->players.begin(); itr != pProp->players.end(); ++itr)
    {
        data << int32(itr->second->role);
    }

    data.WriteByteSeq(proposalGuid[7]);
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(proposalGuid[0]);
    data.WriteByteSeq(proposalGuid[1]);
    data.WriteByteSeq(guid[2]);
    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(proposalGuid[2]);
    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(proposalGuid[4]);

    SendPacket(&data);
}

void WorldSession::SendLfgUpdateSearch(bool update)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_UPDATE_SEARCH [" UI64FMTD "] update: %u", GetPlayer()->GetGUID(), update ? 1 : 0);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    WorldPacket data(SMSG_LFG_UPDATE_SEARCH, 1);
    data << uint8(update);                                 // In Lfg Queue?
    SendPacket(&data);
}

void WorldSession::SendLfgDisabled()
{
<<<<<<< HEAD
    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_DISABLED %s", GetPlayerInfo().c_str());
=======
    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_DISABLED [" UI64FMTD "]", GetPlayer()->GetGUID());
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    WorldPacket data(SMSG_LFG_DISABLED, 0);
    SendPacket(&data);
}

void WorldSession::SendLfgOfferContinue(uint32 dungeonEntry)
{
<<<<<<< HEAD
    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_OFFER_CONTINUE %s dungeon entry: %u",
        GetPlayerInfo().c_str(), dungeonEntry);
=======
    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_OFFER_CONTINUE [" UI64FMTD "] dungeon entry: %u", GetPlayer()->GetGUID(), dungeonEntry);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    WorldPacket data(SMSG_LFG_OFFER_CONTINUE, 4);
    data << uint32(dungeonEntry);
    SendPacket(&data);
}

void WorldSession::SendLfgTeleportError(uint8 err)
{
<<<<<<< HEAD
    sLog->outDebug(LOG_FILTER_LFG, "SMSG_LFG_TELEPORT_DENIED %s reason: %u",
        GetPlayerInfo().c_str(), err);
=======
    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_LFG_TELEPORT_DENIED [" UI64FMTD "] reason: %u", GetPlayer()->GetGUID(), err);
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
    WorldPacket data(SMSG_LFG_TELEPORT_DENIED, 4);
    data << uint32(err);                                   // Error
    SendPacket(&data);
}

<<<<<<< HEAD
/*
void WorldSession::SendLfrUpdateListOpcode(uint32 dungeonEntry)
{
    sLog->outDebug(LOG_FILTER_PACKETIO, "SMSG_LFG_UPDATE_LIST %s dungeon entry: %u",
        GetPlayerInfo().c_str(), dungeonEntry);
    WorldPacket data(SMSG_LFG_UPDATE_LIST);
    SendPacket(&data);
}
*/
=======
void WorldSession::HandleDungeonFinderGetSystemInfo(WorldPacket& recvData)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO,"CMSG_DUNGEON_FINDER_GET_SYSTEM_INFO [" UI64FMTD "]", GetPlayer()->GetGUID());
    bool unk1 = recvData.ReadBit();

    recvData.hexlike();
}
>>>>>>> fc8fb590380a8581e688f47ce96cb1810f2f650f
