#include "ScriptPCH.h"

#define RACE_WORGEN 22
#define RACE_GOBLIN 9
#define CLASS_DEATHKNIGHT 6

#define WORGEN_STARTAREA 1
#define GOBLIN_STARTAREA 2
#define DEATHKNIGHT_STARTAREA 3
#define DEFAULT 0

#define HORDE_RACEMASK           690
#define ALLIANCE_RACEMASK        1101

class npc_skip_startarea : public CreatureScript {
public:
    npc_skip_startarea() : CreatureScript("npc_skip_startarea") {}

    bool OnGossipHello(Player* player, Creature* creature) {
        if (player->getClass() == CLASS_DEATHKNIGHT)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Startgebiet ueberspringen", GOSSIP_SENDER_MAIN, DEATHKNIGHT_STARTAREA);
        else if (player->getRace() == RACE_GOBLIN)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Startgebiet ueberspringen", GOSSIP_SENDER_MAIN, GOBLIN_STARTAREA);
        else if (player->getRace() == RACE_WORGEN)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Startgebiet ueberspringen", GOSSIP_SENDER_MAIN, WORGEN_STARTAREA);
        else
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Bye", GOSSIP_SENDER_MAIN, DEFAULT);
        player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) {
        player->PlayerTalkClass->ClearMenus();
        player->CLOSE_GOSSIP_MENU();

        switch (action) {
            case WORGEN_STARTAREA: {
                player->learnSpell(68992, false); //Finstere Pfade
                //player->learnSpell(87840, false); //Wilde Hatz
                player->learnSpell(68996, false); //Zwei Gestalten
                player->TeleportTo(0, -8914.57f, -133.909f, 80.5378f, 0.000000f); //Mensch Startgebiet
                break;
            }

            case GOBLIN_STARTAREA: {
                player->learnSpell(69046, false);
                player->TeleportTo(1, -618.518f, -4251.67f, 38.718f, 0.000000f); //Ork Startgebiet
                break;
            }

            case DEATHKNIGHT_STARTAREA: {
                if (player->getLevel() != 55) {
                    creature->MonsterWhisper("Du hast leider schon mit dem Leveln begonnen :(", player->GetGUID(), true);
                    break;
                }

                player->AddItem(38674, 1); //Quest Items
                player->AddItem(38667, 1);
                player->AddItem(38663, 1);
                player->AddItem(38662, 1);
                player->AddItem(40483, 1);
                player->AddItem(39322, 1);
                player->AddItem(39208, 1);
                player->AddItem(38671, 1);
                player->AddItem(38666, 1);
                player->AddItem(38669, 1);
                player->AddItem(38675, 1);
                player->AddItem(38670, 1);
                player->AddItem(38672, 1);
                player->AddItem(38632, 1);
                player->AddItem(38665, 1);
                player->AddItem(38661, 1);

                player->SetFreeTalentPoints(16); //Quest Talents
                player->SendTalentsInfoData(true);

                player->learnSpell(50977, false); //Quest Spells
                player->learnSpell(53428, false);   
                player->learnSpell(48778, false);  

                if (player->getRaceMask() & ALLIANCE_RACEMASK)
                    player->TeleportTo(0, -8830.7f, 624.16f, 95.1f, 0.0f, 0); //Stormwind
                else
                    player->TeleportTo(1, 1572.7f, -4398.16f, 16.1f, 0.0f, 0); //Orgrimmar

                break;
            }
        }

        return true;
    }
};

void AddSC_npc_skip_startarea(){
    new npc_skip_startarea();
}

/*
SET @ENTRY = XXXXXXX;
SET @MODEL = 10045;

DELETE FROM creature_template WHERE entry = @ENTRY;
INSERT INTO creature_template (entry, modelid1, name, npcflags, faction_a, faction_h, ScriptName) VALUES (@ENTRY, @MODEL, 'Startgebiet überspringen', 1, 35, 35, 'npc_skip_startarea');
*/
