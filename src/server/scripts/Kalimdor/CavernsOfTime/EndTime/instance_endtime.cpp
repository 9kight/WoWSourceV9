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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "Map.h"
#include "PoolMgr.h"
#include "AccountMgr.h"
#include "endtime.h"
#include "Player.h"
#include "WorldPacket.h"
#include "WorldSession.h"

#define MAX_ENCOUNTER 5

class instance_endtime : public InstanceMapScript
{
public:
    instance_endtime() : InstanceMapScript("instance_endtime", 938) { }

    struct instance_endtime_InstanceMapScript: public InstanceScript
    {
        instance_endtime_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);
            uiBaine = 0;
            uiJaina = 0;
            uiSylvanas = 0;
            uiTyrande = 0;
            uiMurozond = 0;
            GoHourGlassofTimeGUID = 0;
            GoTimeTansitDeviceGUID = 0;
            GoMurozondCacheGUID = 0;
            GoBainePlatform1GUID = 0;
            GoBainePlatform2GUID = 0;
            GoBainePlatform3GUID = 0;
            GoBainePlatform4GUID = 0;
            GoFragmentsGUID = 0;

        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
            case HOURGLASS_OF_TIME:
                GoHourGlassofTimeGUID = go->GetGUID();
                break;
            case BAINE_PLATFORM_1:
                GoBainePlatform1GUID = go->GetGUID();
                break;
            case BAINE_PLATFORM_2:
                GoBainePlatform2GUID = go->GetGUID();
                break;
            case BAINE_PLATFORM_3:
                GoBainePlatform3GUID = go->GetGUID();
                break;
            case BAINE_PLATFORM_4:
                GoBainePlatform4GUID = go->GetGUID();
                break;
            case JAINAS_STAFF:
                GoFragmentsGUID = go->GetGUID();
                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                break;
            case MUROSZONDS_TEMPORAL_CACHE:
                GoMurozondCacheGUID = go->GetGUID();
                break;
            }
        }

        void OnCreatureCreate(Creature* creature, bool )
        {
            switch (creature->GetEntry())
            {
            case BOSS_BAINE:
                uiBaine = creature->GetGUID();
                break;
            case BOSS_JAINA:
                uiJaina = creature->GetGUID();
                break;
            case BOSS_SYLVANAS:
                uiSylvanas = creature->GetGUID();
                break;
            case BOSS_TYRANDE:
                uiTyrande = creature->GetGUID();
                break;
            case BOSS_MUROZOND:
                uiMurozond = creature->GetGUID();
                break;
            }
        }

        uint64 getData64(uint32 index) const
        {
            switch (index)
            {
            case DATA_ECHO_OF_BAINE:
                return uiBaine;
            case DATA_ECHO_OF_JAINA:
                return uiJaina;
            case DATA_JAINAS_STAFF:
                return jainasstaff;
            case DATA_ECHO_OF_SYLVANAS:
                return uiSylvanas;
            case DATA_ECHO_OF_TYRANDE:
                return uiTyrande;
            case DATA_MUROZOND:
                return uiMurozond;
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "H O " << GetBossSaveData();

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'H' && dataHead2 == 'O')
            {
                for (uint32 i = 0; i < EncounterCount; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }
                uint32 tmp;
                loadStream >> tmp;
            }
            else
                OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    protected:
        uint64 uiBaine;
        uint64 uiJaina;
        uint64 uiSylvanas;
        uint64 uiTyrande;
        uint64 uiMurozond;
        uint64 GoHourGlassofTimeGUID;
        uint64 GoTimeTansitDeviceGUID;
        uint64 GoMurozondCacheGUID;
        uint64 GoBainePlatform1GUID;
        uint64 GoBainePlatform2GUID;
        uint64 GoBainePlatform3GUID;
        uint64 GoBainePlatform4GUID;
        uint64 GoFragmentsGUID;
        uint64 jainasstaff;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_endtime_InstanceMapScript(map);
    }
};

void AddSC_instance_endtime()
{
    new instance_endtime();
}