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

#include "ScriptPCH.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "Map.h"
#include "MapManager.h"
#include "ZoneScript.h"
#include "PoolMgr.h"
#include "AccountMgr.h"
#include "bastion_of_twilight.h"

#define ENCOUNTERS     5


static DoorData const doorData[] =
{
    { GO_HALFUS_ENTRANCE,    BOSS_HALFUS,            DOOR_TYPE_ROOM,     BOUNDARY_W },
    { GO_HALFUS_EXIT,        BOSS_HALFUS,            DOOR_TYPE_PASSAGE,  BOUNDARY_S },
    { GO_VALIONA_ENTRANCE,   BOSS_VALIONA,           DOOR_TYPE_ROOM,     BOUNDARY_N },
    { GO_VALIONA_EXIT,       BOSS_VALIONA,           DOOR_TYPE_PASSAGE,  BOUNDARY_S },
    { GO_COUNCIL_ENTRANCE,   BOSS_ASCENDANT_COUNCIL, DOOR_TYPE_ROOM,     BOUNDARY_N },
    { GO_COUNCIL_EXIT,       BOSS_ASCENDANT_COUNCIL, DOOR_TYPE_PASSAGE,  BOUNDARY_S },
    { GO_CHOGALL_ENTRANCE,   BOSS_CHOGALL,           DOOR_TYPE_ROOM,     BOUNDARY_W },
};

class instance_bastion_of_twilight : public InstanceMapScript
{
    public:
        instance_bastion_of_twilight() : InstanceMapScript("instance_bastion_of_twilight", 671)
        {
        }

        struct instance_bastion_of_twilight_InstanceMapScript : public InstanceScript
        {
            instance_bastion_of_twilight_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetBossNumber(maxEncounter);
                LoadDoorData(doorData);
                valionaGUID         = 0;
                theralionGUID       = 0;
                sinestraGUID        = 0;
                twilightFiendsSlain = 0;
            }

            void OnGameObjectCreate(GameObject* gameObject)
            {
                switch (gameObject->GetEntry())
                {
                    case GO_HALFUS_ENTRANCE:
                    case GO_HALFUS_EXIT:
                    case GO_VALIONA_ENTRANCE:
                    case GO_VALIONA_EXIT:
                    case GO_COUNCIL_ENTRANCE:
                    case GO_COUNCIL_EXIT:
                    case GO_CHOGALL_ENTRANCE:
                        AddDoor(gameObject, true);
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_VALIONA:
                        valionaGUID = creature->GetGUID();
                        break;
                    case NPC_THERALION:
                        theralionGUID = creature->GetGUID();
                        break;
                    case NPC_SINESTRA:
                        sinestraGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 type) const
            {
                switch (type)
                {
                    case NPC_VALIONA:
                        return valionaGUID;
                    case NPC_THERALION:
                        return theralionGUID;
                    case BOSS_SINESTRA:
                        return sinestraGUID;
                }

                return 0;
            }

            void OnCreatureDeath(Creature* creature)
            {
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_DOUBLE_DRAGON)
                {
                    if (data == DATA_RESET)
                        twilightFiendsSlain = 0;
                    else if (data == DATA_ACCUMULATE)
                        ++twilightFiendsSlain;
                }
            }
            
            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/)
            {
                if (criteria_id == ACH_DOUBLE_DRAGON || criteria_id == ACH_DOUBLE_DRAGON_2)
                    return twilightFiendsSlain >= 6;

                return false;
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                 return true;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "B O T " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str)
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2, dataHead3;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2 >> dataHead3;

                if (dataHead1 == 'B' && dataHead2 == 'O' && dataHead3 == 'T')
                {
                    for (uint8 i = 0; i < maxEncounter; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        private:
            uint64 valionaGUID;
            uint64 theralionGUID;
            uint64 sinestraGUID;
            uint32 twilightFiendsSlain;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_bastion_of_twilight_InstanceMapScript(map);
        }
};

void AddSC_instance_bastion_of_twilight()
{
    new instance_bastion_of_twilight();
}
