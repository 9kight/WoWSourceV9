// PWS PortPet Script Cataclysm

#include "ScriptPCH.h"
#include <cstring>

class npc_tele_gangnam : public CreatureScript
{
    public:

        npc_tele_gangnam()
            : CreatureScript("npc_tele_gangnam")
        {
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM(2, "Hauptst\303\244dte", GOSSIP_SENDER_MAIN, 1);
            player->ADD_GOSSIP_ITEM(2, "Kalimdor Instanzen", GOSSIP_SENDER_MAIN, 2);
            player->ADD_GOSSIP_ITEM(2, "Östliche K\303\266nigreiche Instanzen", GOSSIP_SENDER_MAIN, 3);
            player->ADD_GOSSIP_ITEM(2, "Azeroth Schlachtz\303\274ge", GOSSIP_SENDER_MAIN, 4);
            player->ADD_GOSSIP_ITEM(2, "Scherbenwelt Instanzen", GOSSIP_SENDER_MAIN, 5);
            player->ADD_GOSSIP_ITEM(2, "Scherbenwelt Schlachtz\303\274ge", GOSSIP_SENDER_MAIN, 6);
            player->ADD_GOSSIP_ITEM(2, "Nordend Instanzen", GOSSIP_SENDER_MAIN, 7);
            player->ADD_GOSSIP_ITEM(2, "Nordend Raids", GOSSIP_SENDER_MAIN, 8);
            player->ADD_GOSSIP_ITEM(2, "Cataclysm Instanzen", GOSSIP_SENDER_MAIN, 122);
            player->ADD_GOSSIP_ITEM(2, "Cataclysm Schlachtz\303\274ge", GOSSIP_SENDER_MAIN, 123);
            player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
        {
          if (sender == GOSSIP_SENDER_MAIN)
          {
               player->PlayerTalkClass->ClearMenus();
          if (action == 1)
          {
          if (player->GetTeam() == ALLIANCE)
          {
               player->ADD_GOSSIP_ITEM(2, "Sturmwind", GOSSIP_SENDER_MAIN, 10);
               player->ADD_GOSSIP_ITEM(2, "Darnassus", GOSSIP_SENDER_MAIN, 11);
               player->ADD_GOSSIP_ITEM(2, "Eisenschmiede", GOSSIP_SENDER_MAIN, 12);
               player->ADD_GOSSIP_ITEM(2, "Exodar", GOSSIP_SENDER_MAIN, 13);
               player->ADD_GOSSIP_ITEM(2, "Shattrath", GOSSIP_SENDER_MAIN, 14);
               player->ADD_GOSSIP_ITEM(2, "Dalaran", GOSSIP_SENDER_MAIN, 15);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
          }
          else
          {
               player->ADD_GOSSIP_ITEM(2, "Orgrimmar", GOSSIP_SENDER_MAIN, 16);
               player->ADD_GOSSIP_ITEM(2, "Donnerfels", GOSSIP_SENDER_MAIN, 17);
               player->ADD_GOSSIP_ITEM(2, "Unterstadt", GOSSIP_SENDER_MAIN, 18);
               player->ADD_GOSSIP_ITEM(2, "Silbermond", GOSSIP_SENDER_MAIN, 19);
               player->ADD_GOSSIP_ITEM(2, "Shattrath", GOSSIP_SENDER_MAIN, 14);
               player->ADD_GOSSIP_ITEM(2, "Dalaran", GOSSIP_SENDER_MAIN, 15);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
             }
          };

          if (action == 2)
          {
               player->ADD_GOSSIP_ITEM(2, "Der Flammenschlund", GOSSIP_SENDER_MAIN, 23);
               player->ADD_GOSSIP_ITEM(2, "Die H\303\266hlen des Wehklagens", GOSSIP_SENDER_MAIN, 24);
               player->ADD_GOSSIP_ITEM(2, "D\303\274sterbruch Nord", GOSSIP_SENDER_MAIN, 25);
               player->ADD_GOSSIP_ITEM(2, "D\303\274sterbruch Ost", GOSSIP_SENDER_MAIN, 26);
               player->ADD_GOSSIP_ITEM(2, "D\303\274sterbruch West", GOSSIP_SENDER_MAIN, 27);
               player->ADD_GOSSIP_ITEM(2, "H\303\274gel der Klingenhauer", GOSSIP_SENDER_MAIN, 89);
               player->ADD_GOSSIP_ITEM(2, "Kral der Klingenhauer", GOSSIP_SENDER_MAIN, 90);
               player->ADD_GOSSIP_ITEM(2, "Maraudon", GOSSIP_SENDER_MAIN, 28);
               player->ADD_GOSSIP_ITEM(2, "Tiefschwarze Grotte", GOSSIP_SENDER_MAIN, 29);
               player->ADD_GOSSIP_ITEM(2, "Zul Farak", GOSSIP_SENDER_MAIN, 30);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
           };

           if (action == 3)
           {
               player->ADD_GOSSIP_ITEM(2, "Burg Schattenfang", GOSSIP_SENDER_MAIN, 31);
               player->ADD_GOSSIP_ITEM(2, "Das Verlies", GOSSIP_SENDER_MAIN, 32);
               player->ADD_GOSSIP_ITEM(2, "Das scharlachrote Kloster", GOSSIP_SENDER_MAIN, 33);
               player->ADD_GOSSIP_ITEM(2, "Der Tempel von Atal Hakkar", GOSSIP_SENDER_MAIN, 34);
               player->ADD_GOSSIP_ITEM(2, "Die Todesminen", GOSSIP_SENDER_MAIN, 35);
               player->ADD_GOSSIP_ITEM(2, "Gnomeregan", GOSSIP_SENDER_MAIN, 36);
               player->ADD_GOSSIP_ITEM(2, "Scholomance", GOSSIP_SENDER_MAIN, 37);
               player->ADD_GOSSIP_ITEM(2, "Stratholme", GOSSIP_SENDER_MAIN, 38);
               player->ADD_GOSSIP_ITEM(2, "Schwarzfelstiefen", GOSSIP_SENDER_MAIN, 39);
               player->ADD_GOSSIP_ITEM(2, "Uldaman", GOSSIP_SENDER_MAIN, 40);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
           };

           if (action == 4)
           {
               player->ADD_GOSSIP_ITEM(2, "Geschmolzener Kern", GOSSIP_SENDER_MAIN, 41);
               player->ADD_GOSSIP_ITEM(2, "Pechschwingenhort", GOSSIP_SENDER_MAIN, 42);
               player->ADD_GOSSIP_ITEM(2, "Ruinen von Ahn Qiraj", GOSSIP_SENDER_MAIN, 43);
               player->ADD_GOSSIP_ITEM(2, "Tempel von Ahn Qiraj", GOSSIP_SENDER_MAIN, 44);
               player->ADD_GOSSIP_ITEM(2, "Schwarzfelsspitze", GOSSIP_SENDER_MAIN, 45);
               player->ADD_GOSSIP_ITEM(2, "Zul Gurub", GOSSIP_SENDER_MAIN, 46);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
           };

           if (action == 5)
           {
               player->ADD_GOSSIP_ITEM(2, "Auchenaikrypta", GOSSIP_SENDER_MAIN, 47);
               player->ADD_GOSSIP_ITEM(2, "Der Blutkessel", GOSSIP_SENDER_MAIN, 48);
               player->ADD_GOSSIP_ITEM(2, "Der Tiefensumpf", GOSSIP_SENDER_MAIN, 49);
               player->ADD_GOSSIP_ITEM(2, "Der schwarze Morast", GOSSIP_SENDER_MAIN, 50);
               player->ADD_GOSSIP_ITEM(2, "Die Arkatraz", GOSSIP_SENDER_MAIN, 51);
               player->ADD_GOSSIP_ITEM(2, "Die Botanika", GOSSIP_SENDER_MAIN, 52);
               player->ADD_GOSSIP_ITEM(2, "Die Dampfkammer", GOSSIP_SENDER_MAIN, 53);
               player->ADD_GOSSIP_ITEM(2, "Die Mechanar", GOSSIP_SENDER_MAIN, 54);
               player->ADD_GOSSIP_ITEM(2, "Die Sklavenunterkunfte", GOSSIP_SENDER_MAIN, 55);
               player->ADD_GOSSIP_ITEM(2, "Die zerschmetterten Hallen", GOSSIP_SENDER_MAIN, 56);
               player->ADD_GOSSIP_ITEM(2, "H\303\266llenfeuerbollwerk", GOSSIP_SENDER_MAIN, 57);
               player->ADD_GOSSIP_ITEM(2, "Managruft", GOSSIP_SENDER_MAIN, 58);
               player->ADD_GOSSIP_ITEM(2, "Schattenlabyrinth", GOSSIP_SENDER_MAIN, 59);
               player->ADD_GOSSIP_ITEM(2, "Sethekkhallen", GOSSIP_SENDER_MAIN, 60);
               player->ADD_GOSSIP_ITEM(2, "Terasse der Magister", GOSSIP_SENDER_MAIN, 61);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
           };

           if (action == 6)
           {
               player->ADD_GOSSIP_ITEM(2, "Das Auge", GOSSIP_SENDER_MAIN, 62);
               player->ADD_GOSSIP_ITEM(2, "Der schwarze Tempel", GOSSIP_SENDER_MAIN, 63);
               player->ADD_GOSSIP_ITEM(2, "Gruuls Unterschlupf", GOSSIP_SENDER_MAIN, 64);
               player->ADD_GOSSIP_ITEM(2, "H\303\266hle des Schlangenschreins", GOSSIP_SENDER_MAIN, 65);
               player->ADD_GOSSIP_ITEM(2, "Hyjalgipfel", GOSSIP_SENDER_MAIN, 66);
               player->ADD_GOSSIP_ITEM(2, "Karazhan", GOSSIP_SENDER_MAIN, 67);
               player->ADD_GOSSIP_ITEM(2, "Magtheridons Kammer", GOSSIP_SENDER_MAIN, 68);
               player->ADD_GOSSIP_ITEM(2, "Sonnenbrunnenplateau", GOSSIP_SENDER_MAIN, 69);
               player->ADD_GOSSIP_ITEM(2, "Zul Aman", GOSSIP_SENDER_MAIN, 70);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
           };

           if (action == 7)
           {
               player->ADD_GOSSIP_ITEM(2, "Azjol Nerub", GOSSIP_SENDER_MAIN, 73);
               player->ADD_GOSSIP_ITEM(2, "Burg Utgarde", GOSSIP_SENDER_MAIN, 91);
               player->ADD_GOSSIP_ITEM(2, "Das alte K\303\266nigreich", GOSSIP_SENDER_MAIN, 74);
               player->ADD_GOSSIP_ITEM(2, "Das Ausmerzen von Stratholme", GOSSIP_SENDER_MAIN, 75);
               player->ADD_GOSSIP_ITEM(2, "Das Oculus", GOSSIP_SENDER_MAIN, 77);
               player->ADD_GOSSIP_ITEM(2, "Der Nexus", GOSSIP_SENDER_MAIN, 78);
               player->ADD_GOSSIP_ITEM(2, "Die Hallen der Blitze", GOSSIP_SENDER_MAIN, 79);
               player->ADD_GOSSIP_ITEM(2, "Die Hallen des Steins", GOSSIP_SENDER_MAIN, 80);
               player->ADD_GOSSIP_ITEM(2, "Die violette Festung", GOSSIP_SENDER_MAIN, 81);
               player->ADD_GOSSIP_ITEM(2, "Feste Drak Tharon", GOSSIP_SENDER_MAIN, 82);
               player->ADD_GOSSIP_ITEM(2, "Zul'Drak", GOSSIP_SENDER_MAIN, 83);
               player->ADD_GOSSIP_ITEM(2, "Gundrak", GOSSIP_SENDER_MAIN, 83);
               player->ADD_GOSSIP_ITEM(2, "Pr\303\274fung des Champions", GOSSIP_SENDER_MAIN, 86);
               player->ADD_GOSSIP_ITEM(2, "Turm Utgarde", GOSSIP_SENDER_MAIN, 88);
               player->ADD_GOSSIP_ITEM(2, "Die gefrorenen Hallen", GOSSIP_SENDER_MAIN, 114);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
           };

           if (action == 8)
           {
               player->ADD_GOSSIP_ITEM(2, "Auge der Ewigkeit", GOSSIP_SENDER_MAIN, 91);
               player->ADD_GOSSIP_ITEM(2, "Das Obsidiansanktum", GOSSIP_SENDER_MAIN, 92);
               player->ADD_GOSSIP_ITEM(2, "Naxxramas", GOSSIP_SENDER_MAIN, 93);
               player->ADD_GOSSIP_ITEM(2, "Onyxias Hort", GOSSIP_SENDER_MAIN, 94);
               player->ADD_GOSSIP_ITEM(2, "Pr\303\274fung des Kreuzfahrers", GOSSIP_SENDER_MAIN, 95);
               player->ADD_GOSSIP_ITEM(2, "Ulduar", GOSSIP_SENDER_MAIN, 96);
               player->ADD_GOSSIP_ITEM(2, "Eiskronenzitadelle", GOSSIP_SENDER_MAIN, 112);
               player->ADD_GOSSIP_ITEM(2, "Rubinsanktum", GOSSIP_SENDER_MAIN, 113);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
           };

           if (action == 9)
           {
               player->ADD_GOSSIP_ITEM(2, "Hauptst\303\244dte", GOSSIP_SENDER_MAIN, 1);
               player->ADD_GOSSIP_ITEM(2, "Kalimdor Instanzen", GOSSIP_SENDER_MAIN, 2);
               player->ADD_GOSSIP_ITEM(2, "Östliche K\303\266nigreiche Instanzen", GOSSIP_SENDER_MAIN, 3);
               player->ADD_GOSSIP_ITEM(2, "Azeroth Schlachtz\303\274ge", GOSSIP_SENDER_MAIN, 4);
               player->ADD_GOSSIP_ITEM(2, "Scherbenwelt Instanzen", GOSSIP_SENDER_MAIN, 5);
               player->ADD_GOSSIP_ITEM(2, "Scherbenwelt Schlachtz\303\274ge", GOSSIP_SENDER_MAIN, 6);
               player->ADD_GOSSIP_ITEM(2, "Nordend Instanzen", GOSSIP_SENDER_MAIN, 7);
               player->ADD_GOSSIP_ITEM(2, "Nordend Raids", GOSSIP_SENDER_MAIN, 8);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
           };

           if (action == 122)
           {
               player->ADD_GOSSIP_ITEM(2, "Der steinerne Kern", GOSSIP_SENDER_MAIN, 115);
               player->ADD_GOSSIP_ITEM(2, "Der Vortexgipfel", GOSSIP_SENDER_MAIN, 116);
               player->ADD_GOSSIP_ITEM(2, "Die verlorene Stadt der TolVir", GOSSIP_SENDER_MAIN, 117);
               player->ADD_GOSSIP_ITEM(2, "Grim Batol", GOSSIP_SENDER_MAIN, 118);
               player->ADD_GOSSIP_ITEM(2, "Hallen des Ursprungs", GOSSIP_SENDER_MAIN, 119);
               player->ADD_GOSSIP_ITEM(2, "SchwarzfelshK\303\266hlen", GOSSIP_SENDER_MAIN, 120);
               player->ADD_GOSSIP_ITEM(2, "Thron der Gezeiten", GOSSIP_SENDER_MAIN, 121);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
           };

           if (action == 123)
           {
               player->ADD_GOSSIP_ITEM(2, "Thron der vier Winde", GOSSIP_SENDER_MAIN, 124);
               player->ADD_GOSSIP_ITEM(2, "Bastion des Zwielichts", GOSSIP_SENDER_MAIN, 125);
               player->ADD_GOSSIP_ITEM(2, "Pechschwingenabstieg", GOSSIP_SENDER_MAIN, 126);
               player->ADD_GOSSIP_ITEM(0, "Mainmenü", GOSSIP_SENDER_MAIN, 9);
               player->PlayerTalkClass->SendGossipMenu(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
           };
        }
           if (action == 10)
           {
                player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -8881.000000f, 575.000000f, 93.000000f, 0.000000f);
           }
           if (action == 11)
           {
                player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, 9951.890000f, 2280.550000f, 1341.390000f, 0.000000f);
           }
           if (action == 12)
           {
                player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -4981.000000f, -881.000000f, 501.660000f, 0.000000f);
           }
           if (action == 13)
           {
                player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -4014.000000f, -11895.790000f, -2.000000f, 0.000000f);
           }
           if (action == 14)
           {
                player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -1887.510010f, 5359.379883f, -12.427300f, 0.000000f);
           }
           if (action == 15)
           {
                player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 5804.149902f, 624.770996f, 647.767029f, 0.000000f);
           }
           if (action == 16)
           {
                player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, 1570.642578f, -4400.348145f, 16.005386f, 0.000000f);
           }
           if (action == 17)
           {
                player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -1196.858398f, 30.147331f, 176.949188f, 0.000000f);
           }
           if (action == 18)
           {
                player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, 1844.765625f, 237.655991f, 62.275150f, 0.000000f);
           }
           if (action == 19)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 9400.486328f, -7278.376953f, 14.206780f, 0.000000f);
           }
           if (action == 23)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, 1811.780029f, -4410.500000f, -18.470400f, 0.000000f);
           }
           if (action == 24)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -738.755310f, -2217.383545f, 16.586060f, 2.692518f);
           }
           if (action == 25)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -3520.649902f, 1077.719971f, 161.13800f, 0.000000f);
           }
           if (action == 26)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -3831.790039f, 1250.229980f, 160.223007f, 0.000000f);
           }
           if (action == 27)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -3981.660645f, 779.088074f, 161.004211f, 0.000000f);
           }
           if (action == 28)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -1422.326538f, 2917.872559f, 136.098511f, 1.573660f);
           }
           if (action == 29)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, 4248.875977f, 742.226318f, -25.163849f, 1.314702f);
           }
           if (action == 30)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -6808.619141f, -2889.259766f, 8.898358f, 0.000000f);
           }
           if (action == 31)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -234.495087f, 1561.946411f, 76.892143f, 0.000000f);
           }
           if (action == 32)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -8764.829102f, 846.075623f, 87.484047f, 0.000000f);
           }
           if (action == 33)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, 2870.442627f, -819.985229f, 160.331085f, 0.000000f);
           }
           if (action == 34)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -10175.099609f, -3995.149902f, -112.900002f, 0.000000f);
           }
           if (action == 35)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -11208.700195f, 1673.520020f, 24.636101f, 0.000000f);
           }
           if (action == 36)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -5137.708496f, 887.978333f, 287.392731f, 2.243454f);
           }
           if (action == 37)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, 1267.468628f, -2556.651367f, 94.127983f, 0.000000f);
           }
           if (action == 38)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, 3359.111572f, -3380.844238f, 144.781860f, 0.000000f);
           }
           if (action == 39)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -7179.629883f, -923.666992f, 166.416000f, 4.988057f);
           }
           if (action == 40)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -6071.370117f, -2955.159912f, 209.781998f, 0.000000f);
           }
           if (action == 41)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(409, 1089.600000f, -470.190000f, -106.410000f, 0.000000f);
           }
           if (action == 42)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -7527.129883f, -1224.997437f, 285.733002f, 0.000000f);
           }
           if (action == 43)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -8394.730469f, 1485.658447f, 21.038563f, 0.000000f);
           }
           if (action == 44)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -8247.316406f, 1970.156860f, 129.071472f, 0.000000f);
           }
           if (action == 45)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -7524.718262f, -1229.250366f, 285.732239f, 5.253190f);
           }
           if (action == 46)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -11916.700195f, -1215.719971f, 92.288849f, 0.000000f);
           }
           if (action == 47)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -3361.959961f, 5225.770020f, -101.047997f, 0.000000f);
           }
           if (action == 48)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -303.506012f, 3164.820068f, 31.742500f, 0.000000f);
           }
           if (action == 49)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 777.088989f, 6763.450195f, -72.062561f, 0.000000f);
           }
           if (action == 50)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -8761.467773f, -4182.452637f, -209.484467f, 0.000000f);
           }
           if (action == 51)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 3309.066660f, 1340.211426f, 505.559052f, 0.000000f);
           }
           if (action == 52)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 3413.649902f, 1483.319946f, 182.837997f, 0.000000f);
           }
           if (action == 53)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 816.590027f, 6934.669922f, -80.544601f, 0.000000f);
           }
           if (action == 54)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 2862.409912f, 1546.089966f, 252.158691f, 0.000000f);
           }
           if (action == 55)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 719.507996f, 6999.339844f, -73.074303f, 0.000000f);
           }
           if (action == 56)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -309.003052f, 3075.307861f, -3.648393f, 0.000000f);
           }
           if (action == 57)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -360.670990f, 3071.899902f, -15.097700f, 0.000000f);
           }
           if (action == 58)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -3079.810059f, 4943.040039f, -101.046997f, 0.000000f);
           }
           if (action == 59)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -3547.746826f, 4943.016113f, -101.395813f, 0.000000f);
           }
           if (action == 60)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -3362.219971f, 4660.410156f, -101.049004f, 0.000000f);
           }
           if (action == 61)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 12886.715820f, -7332.387207f, 65.488792f, 4.670000f);
           }
           if (action == 62)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 3087.310059f, 1373.790039f, 184.643005f, 0.000000f);
           }
           if (action == 63)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -3609.739990f, 328.252014f, 37.307701f, 0.000000f);
           }
           if (action == 64)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 3549.424072f, 5179.854004f, -4.430779f, 0.000000f);
           }
           if (action == 65)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 830.542908f, 6865.445801f, -63.785503f, 0.000000f);
           }
           if (action == 66)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -8175.338867f, -4173.908691f, -165.994934f, 0.000000f);
           }
           if (action == 67)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -11115.046875f, -2007.983643f, 48.629845f, 0.000000f);
           }
           if (action == 68)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, -313.678986f, 3088.350098f, -116.501999f, 0.000000f);
           }
           if (action == 69)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 12571.569336f, -6774.471191f, 15.091288f, 0.000000f);
           }
           if (action == 70)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(530, 6853.331055f, -7956.031738f, 170.074585f, 4.670000f);
           }
           if (action == 73)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 3677.579102f, 2167.551514f, 35.849609f, 0.000000f);
           }
           if (action == 74)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 3641.306152f, 2031.166870f, 2.527870f, 0.000000f);
           }
           if (action == 75)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -8755.722656f, -4453.486816f, -200.054230f, 0.000000f);
           }
           if (action == 77)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 3880.489990f, 6984.014160f, 106.320763f, 0.000000f);
           }
           if (action == 78)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 3897.419922f, 6985.330078f, 69.487000f, 0.000000f);
           }
           if (action == 79)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 9182.910156f, -1384.729980f, 1110.209961f, 0.000000f);
           }
           if (action == 80)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 8921.929688f, -970.398987f, 1039.199951f, 0.000000f);
           }
           if (action == 81)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 5691.767578f, 500.888733f, 652.667908f, 0.000000f);
           }
           if (action == 82)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 4891.184082f, -2047.110107f, 248.309097f, 0.000000f);
           }
           if (action == 83)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 4894.620117f, -2047.743652f, 248.309784f, 0.000000f);
           }
           if (action == 84)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(533, 3006.060000f, -3436.720000f, 293.891000f, 0.000000f);
           }
           if (action == 85)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -4744.647000f, -3752.661133f, 50.427000f, 3.000000f);
           }
           if (action == 86)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 8579.184570f, 792.057678f, 558.234741f, 0.000000f);
           }
           if (action == 87)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 8515.795898f, 722.216858f, 558.247864f, 0.000000f);
           }
           if (action == 88)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 1237.199951f, -4859.270020f, 218.283005f, 0.000000f);
           }
           if (action == 89)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -4656.981934f, -2522.471924f, 81.216866f, 0.000000f);
           }
           if (action == 90)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -4468.556152f, -1672.829468f, 81.832565f, 0.000000f);
           }
           if (action == 91)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 1219.695190f, -4864.639160f, 41.248211f, 0.000000f);
           }
           if (action == 92)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 3448.000000f, 261.545013f, -110.163002f, 0.000000f);
           }
           if (action == 93)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 3672.559814f, -1271.414551f, 243.506485f, 0.000000f);
           }
           if (action == 94)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -4744.647000f, -3752.661133f, 50.427000f, 3.000000f);
           }
           if (action == 95)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 8515.795898f, 722.216858f, 558.247864f, 0.000000f);
           }
           if (action == 96)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 9330.671875f, -1115.889282f, 1245.146118f, 0.000000f);
           }
           if (action == 100)
           {
               player->CLOSE_GOSSIP_MENU();
           }
           if (action == 112)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 5797.020996f, 2074.763428f, 636.064209f, 3.508371f);
           }
           if (action == 113)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 3599.075195f, 198.837952f, -113.960136f, 5.313031f);
           }
           if (action == 114)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(571, 5636.815430f, 2062.120117f, 798.056091f, 4.599276f);
           }
           if (action == 115)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(646, 1026.767578f, 633.862793f, 156.673004f, 4.917323f);
           }
           if (action == 116)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -11512.099609f, -2309.048340f, 608.393311f, 3.794239f);
           }
           if (action == 117)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -10669.228516f, -1303.898193f, 15.353142f, 3.389767f);
           }
           if (action == 118)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -4058.158936f, -3449.236328f, 281.169342f, 0.292089f);
           }
           if (action == 119)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -10201.176758f, -1838.095947f, 20.128529f, 3.139240f);
           }
           if (action == 120)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -7571.361328f, -1323.190674f, 245.535965f, 4.825781f);
           }
           if (action == 121)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -5597.939941f, 5411.246094f, -1798.614868f, 5.620756f);
           }
           if (action == 124)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(1, -11354.787109f, 57.626900f, 723.884399f, 1.985465f);
           }
           if (action == 125)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -4888.666504f, -4244.182617f, 827.763428f, 2.156230f);
           }
           if (action == 126)
           {
               player->CLOSE_GOSSIP_MENU(); player->TeleportTo(0, -7537.036133f, -1200.331543f, 477.722443f, 1.935534f);
           }
           return true;
        }
};

void AddSC_npc_tele_gangnam()
{
    new npc_tele_gangnam();
}
