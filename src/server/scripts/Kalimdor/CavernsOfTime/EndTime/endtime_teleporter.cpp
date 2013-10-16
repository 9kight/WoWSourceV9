/*
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

#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "endtime.h"
#include "InstanceScript.h"
#include "Player.h"

enum endtimeTeleporter
{
    ECHO_OF_BAINE                                = 200,
    ECHO_OF_JAINA                                = 201,
    ECHO_OF_SYLVANAS                             = 202,
    ECHO_OF_TYRANDE                              = 203,
    MUROZOND	                                 = 204,
    ENTRANCE									 = 205,
};

const Position nozdormu_baine  = {4347.017578f, 1306.678589f, 148.205292f, 4.925019f};


class endtime_teleporter : public GameObjectScript
{
public:
    endtime_teleporter() : GameObjectScript("endtime_teleporter") { }

    bool OnGossipSelect(Player* player, GameObject* /*gameObject*/, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return false;
        if (!player->getAttackers().empty())
            return false;
        GameObject* teleporter;
        switch (action)
        {
        case ECHO_OF_BAINE:
            player->TeleportTo(938, 4345.706055f, 1295.630249f, 147.504166f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            player->SummonCreature(NPC_NOZDORMU_BAINE, nozdormu_baine, TEMPSUMMON_DEAD_DESPAWN);
            break;
        case ECHO_OF_JAINA:
            player->TeleportTo(938, 3026.755371f, 520.566345f, 22.127562f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            break;
        case ECHO_OF_SYLVANAS:
            player->TeleportTo(938, 3827.220947f, 1104.166626f, 84.145508f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            break;
        case ECHO_OF_TYRANDE:
            player->TeleportTo(938, 2945.854492f, 70.078247f, 8.549151f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            break;
        case MUROZOND:
            player->TeleportTo(938, 4037.264404f, -356.555908f, 122.007019f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            break;
        case ENTRANCE:
            player->TeleportTo(938, 3707.933350f, -369.515900f, 113.820717f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, GameObject* gameObject)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Obsidian Dragonshrine", GOSSIP_SENDER_MAIN, ECHO_OF_BAINE);
        if (InstanceScript* instance = gameObject->GetInstanceScript())
        {
            if (instance->GetBossState(DATA_ECHO_OF_BAINE) == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Azure Dragonshrine", GOSSIP_SENDER_MAIN, ECHO_OF_JAINA);
            if (instance->GetBossState(DATA_ECHO_OF_JAINA) == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ruby Dragonshrine", GOSSIP_SENDER_MAIN, ECHO_OF_SYLVANAS);
            if (instance->GetBossState(DATA_ECHO_OF_SYLVANAS) == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Emerald Dragonshrine", GOSSIP_SENDER_MAIN, ECHO_OF_TYRANDE);
            if (instance->GetBossState(DATA_ECHO_OF_TYRANDE) == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Bronze Dragonshrine", GOSSIP_SENDER_MAIN, MUROZOND);
            if (instance->GetBossState(DATA_MUROZOND) == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Entryway of Time", GOSSIP_SENDER_MAIN, ENTRANCE);
        }

        player->SEND_GOSSIP_MENU(gameObject->GetGOInfo()->GetGossipMenuId(), gameObject->GetGUID());
        return true;
    }
};

class endtime_teleporter_1 : public GameObjectScript
{
public:
    endtime_teleporter_1() : GameObjectScript("endtime_teleporter_1") { }

    bool OnGossipSelect(Player* player, GameObject* /*gameObject*/, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return false;
        if (!player->getAttackers().empty())
            return false;
        GameObject* teleporter;
        switch (action)
        {
        case ECHO_OF_JAINA:
            player->TeleportTo(938, 3026.755371f, 520.566345f, 22.127562f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, GameObject* gameObject)
    {
        if (InstanceScript* instance = gameObject->GetInstanceScript())
        {
            if (instance->GetBossState(DATA_ECHO_OF_BAINE) == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Azure Dragonshrine", GOSSIP_SENDER_MAIN, ECHO_OF_JAINA);
        }

        player->SEND_GOSSIP_MENU(gameObject->GetGOInfo()->GetGossipMenuId(), gameObject->GetGUID());
        return true;
    }
};

class endtime_teleporter_2 : public GameObjectScript
{
public:
    endtime_teleporter_2() : GameObjectScript("endtime_teleporter_2") { }

    bool OnGossipSelect(Player* player, GameObject* /*gameObject*/, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return false;
        if (!player->getAttackers().empty())
            return false;
        GameObject* teleporter;
        switch (action)
        {
        case ECHO_OF_SYLVANAS:
            player->TeleportTo(938, 3827.220947f, 1104.166626f, 84.145508f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            break;

        }

        return true;
    }

    bool OnGossipHello(Player* player, GameObject* gameObject)
    {
        if (InstanceScript* instance = gameObject->GetInstanceScript())
        {
            if (instance->GetBossState(DATA_ECHO_OF_JAINA) == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ruby Dragonshrine", GOSSIP_SENDER_MAIN, ECHO_OF_SYLVANAS);
        }

        player->SEND_GOSSIP_MENU(gameObject->GetGOInfo()->GetGossipMenuId(), gameObject->GetGUID());
        return true;
    }
};

class endtime_teleporter_3 : public GameObjectScript
{
public:
    endtime_teleporter_3() : GameObjectScript("endtime_teleporter_3") { }

    bool OnGossipSelect(Player* player, GameObject* /*gameObject*/, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return false;
        if (!player->getAttackers().empty())
            return false;
        GameObject* teleporter;
        switch (action)
        {
        case ECHO_OF_TYRANDE:
            player->TeleportTo(938, 2945.854492f, 70.078247f, 8.549151f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, GameObject* gameObject)
    {
        if (InstanceScript* instance = gameObject->GetInstanceScript())
        {
            if (instance->GetBossState(DATA_ECHO_OF_SYLVANAS) == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Emerald Dragonshrine", GOSSIP_SENDER_MAIN, ECHO_OF_TYRANDE);
        }

        player->SEND_GOSSIP_MENU(gameObject->GetGOInfo()->GetGossipMenuId(), gameObject->GetGUID());
        return true;
    }
};

class endtime_teleporter_4 : public GameObjectScript
{
public:
    endtime_teleporter_4() : GameObjectScript("endtime_teleporter_4") { }

    bool OnGossipSelect(Player* player, GameObject* /*gameObject*/, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return false;
        if (!player->getAttackers().empty())
            return false;
        GameObject* teleporter;
        switch (action)
        {
        case MUROZOND:
            player->TeleportTo(938, 4037.264404f, -356.555908f, 122.007019f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, GameObject* gameObject)
    {
        if (InstanceScript* instance = gameObject->GetInstanceScript())
        {
            if (instance->GetBossState(DATA_ECHO_OF_TYRANDE) == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Bronze Dragonshrine", GOSSIP_SENDER_MAIN, MUROZOND);
        }

        player->SEND_GOSSIP_MENU(gameObject->GetGOInfo()->GetGossipMenuId(), gameObject->GetGUID());
        return true;
    }
};

class endtime_teleporter_5 : public GameObjectScript
{
public:
    endtime_teleporter_5() : GameObjectScript("endtime_teleporter_5") { }

    bool OnGossipSelect(Player* player, GameObject* /*gameObject*/, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return false;
        if (!player->getAttackers().empty())
            return false;
        GameObject* teleporter;
        switch (action)
        {
        case ENTRANCE:
            player->TeleportTo(938, 3707.933350f, -369.515900f, 113.820717f, 0.0f);
            player->CLOSE_GOSSIP_MENU();
            break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, GameObject* gameObject)
    {
        if (InstanceScript* instance = gameObject->GetInstanceScript())
        {
            if (instance->GetBossState(DATA_MUROZOND) == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Entryway of Time", GOSSIP_SENDER_MAIN, ENTRANCE);
        }

        player->SEND_GOSSIP_MENU(gameObject->GetGOInfo()->GetGossipMenuId(), gameObject->GetGUID());
        return true;
    }
};

void AddSC_endtime_teleporter()
{
    new endtime_teleporter();
    new endtime_teleporter_1();
    new endtime_teleporter_2();
    new endtime_teleporter_3();
    new endtime_teleporter_4();
    new endtime_teleporter_5();
}
