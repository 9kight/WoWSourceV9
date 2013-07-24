/*
 * Copyright (C) 2005 - 2011 MaNGOS <http://www.getmangos.org/>
 *
 * Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
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

#include "throne_of_the_four_winds.h"

class instance_throne_of_the_four_winds : public InstanceMapScript
{
    public:
	    instance_throne_of_the_four_winds() : InstanceMapScript("instance_throne_of_the_four_winds", 754)
        {
        }

	    struct instance_throne_of_the_four_winds_InstanceMapScript: public InstanceScript
	    {
		    instance_throne_of_the_four_winds_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
            }

		    uint64 Anshal;
		    uint64 Nezir;
		    uint64 Rohash;
		    uint64 Alakir;

		    void Initialize()
		    {
			    Anshal = 0;
			    Nezir = 0;
			    Rohash = 0;
			    Alakir = 0;
		    }

            void OnGameObjectCreate(GameObject* go)
            {
                sLog->outInfo(LOG_FILTER_UNITS, "OnGameObjectCreate() - %s & %u", go->GetName().c_str(), go->GetEntry());
                go->setActive(true);
            }

		    void OnCreatureCreate(Creature* creature)
		    {
			    switch (creature->GetEntry())
			    {
			    case BOSS_ANSHAL:
				    Anshal = creature->GetGUID();
				    break;
			    case BOSS_NEZIR:
				    Nezir = creature->GetGUID();
				    break;
			    case BOSS_ROHASH:
				    Rohash = creature->GetGUID();
				    break;
			    case BOSS_ALAKIR:
				    Alakir = creature->GetGUID();
				    break;
			    }
		    }

		    void SetData(uint32 type, uint32 data)
		    {
			    if (data == DONE)
				    SaveToDB();
		    }

		    uint64 GetData64(uint32 type) const
		    {
			    switch (type)
			    {
			        case BOSS_ANSHAL:
				        return Anshal;
			        case BOSS_NEZIR:
				        return Nezir;
			        case BOSS_ROHASH:
				        return Rohash;
			        case BOSS_ALAKIR:
				        return Alakir;
			    }

			    return 0;
		    }

		    std::string GetSaveData()
		    {
			    OUT_SAVE_INST_DATA;

			    std::ostringstream saveStream;
			    saveStream << "T W" << GetBossSaveData();

			    OUT_SAVE_INST_DATA_COMPLETE;
			    return saveStream.str();
		    }

		    void Load(const char* strIn)
		    {
			    if (!strIn)
			    {
				    OUT_LOAD_INST_DATA_FAIL;
				    return;
			    }

			    OUT_LOAD_INST_DATA(strIn);

			    char dataHead1, dataHead2;

			    std::istringstream loadStream(strIn);
			    loadStream >> dataHead1 >> dataHead2;

			    if (dataHead1 == 'T' && dataHead2 == 'W')
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

                OUT_LOAD_INST_DATA_COMPLETE;
		    }
	    };

	    InstanceScript* GetInstanceScript(InstanceMap* map) const
	    {
		    return new instance_throne_of_the_four_winds_InstanceMapScript(map);
	    }
};

void AddSC_instance_throne_of_the_four_winds()
{
	new instance_throne_of_the_four_winds();
}