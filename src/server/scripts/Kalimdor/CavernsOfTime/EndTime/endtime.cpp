#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "endtime.h"
#include "InstanceScript.h"
#include "Player.h"

class go_time_transit_device : public GameObjectScript
{
    public:
        go_time_transit_device() : GameObjectScript("go_time_transit_device") { }

        bool OnGossipSelect(Player* player, GameObject* /*gameObject*/, uint32 sender, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            if (sender != GOSSIP_SENDER_MAIN)
                return false;
            if (!player->getAttackers().empty())
                return false;

            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF+1:
                    player->TeleportTo(938, 2932.906f, 68.194f, 6.074f, 3.27f);
                    player->CLOSE_GOSSIP_MENU();
                break;
                case GOSSIP_ACTION_INFO_DEF+2:
                    player->TeleportTo(938, 3021.525f, 519.07f, 22.585f, 6.22f);
                    player->CLOSE_GOSSIP_MENU();
                break;
                case GOSSIP_ACTION_INFO_DEF+3:
                    player->TeleportTo(938, 4352.32f, 1289.19f, 147.503f, 1.344f);
                    player->CLOSE_GOSSIP_MENU();
                break;
                case GOSSIP_ACTION_INFO_DEF+4:
                    player->TeleportTo(938, 3827.44f, 1099.803f, 83.821f, 4.6f);
                    player->CLOSE_GOSSIP_MENU();
                break;
            }

                return true;
        }

    bool OnGossipHello(Player* player, GameObject* gameObject)
    {
        InstanceScript* instance = gameObject->GetInstanceScript();

            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Emerald Dragonshire", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
//        if (instance && instance->GetData(DATA_EMERALD_EVENT)==DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Azure Dragonshire", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
//        if (instance && instance->GetData(DATA_AZURE_EVENT)==DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Obsidian Dragonshire", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
//        if (instance && instance->GetData(DATA_OBSIDIAN_EVENT)==DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Ruby Dragonshire", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);

            player->SEND_GOSSIP_MENU(gameObject->GetGOInfo()->GetGossipMenuId(), gameObject->GetGUID());
            return true;
    }
};

void AddSC_endtime()
{
    new go_time_transit_device();
}
