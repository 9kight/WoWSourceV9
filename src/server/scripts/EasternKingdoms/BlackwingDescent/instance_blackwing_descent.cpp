#include "blackwing_descent.h"
#include "Object.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"

static const Position NefarianPos = {143.501663f, -241.307678f, 74.920464f, 2.260429f};
static const Position AtramedesPos = {386.093842f, -314.483643f, 137.624100f, 0.0f};

class instance_blackwing_descent : public InstanceMapScript
{
    public:
        instance_blackwing_descent() : InstanceMapScript("instance_blackwing_descent", 669) { }

        struct instance_blackwing_descent_InstanceMapScript : public InstanceScript
        {
            instance_blackwing_descent_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetBossNumber(ENCOUNTER_COUNT);
                drakonidCnt             = 0;
                dwarvesCnt              = 0;
                magmawGUID              = 0;
                nefarianGUID            = 0;
                omnotronGUID            = 0;
                arcanotronGUID          = 0;
                electronGUID            = 0;
                magmatronGUID           = 0;
                toxitronGUID            = 0;
                bellGUID                = 0;
                atramedesGUID           = 0;
                omnotronNefarianGUID    = 0;
                chimaeronGUID           = 0;
            }

            void OnGameObjectCreate(GameObject * go)
            {
                if(go->GetEntry() == GO_ANCIENT_BELL)
                {
                    bellGUID = go->GetGUID();
                    if(dwarvesCnt < 7)
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                }
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch(creature->GetEntry())
                {
                case NPC_DRAKONID_DRUDGE:
                    if(Creature * magmaw = this->instance->GetCreature(magmawGUID))
                    {
                        if(drakonidCnt < 2)
                        {
                            magmaw->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                            magmaw->SetReactState(REACT_PASSIVE);
                            if(creature->isDead())
                                SetData(DATA_DRAKONID, 1);
                        }
                    }
                    break;
                case NPC_MAGMAW:
                    magmawGUID = creature->GetGUID();
                    break;
                case NPC_ATRAMEDES:
                    atramedesGUID = creature->GetGUID();
                    break;
                case NPC_OMNOTRON:
                    omnotronGUID = creature->GetGUID();
                    break;
                case NPC_ELECTRON:
                    electronGUID = creature->GetGUID();
                    break;
                case NPC_TOXITRON:
                    toxitronGUID = creature->GetGUID();
                    break;
                case NPC_MAGMATRON:
                    magmatronGUID = creature->GetGUID();
                    break;
                case NPC_ARCANOTRON:
                    arcanotronGUID = creature->GetGUID();
                    break;
                case NPC_NEFARIUS_OMNOTRON:
                    omnotronNefarianGUID = creature->GetGUID();
                    break;
                case NPC_CHIMAERON:
                    chimaeronGUID = creature->GetGUID();
                    break;
                default:
                    break;
                }
            }

            void OnCreatureDeath(Creature * creature)
            {
                if(creature->GetEntry() == NPC_SPIRIT_OF_THAURISSIAN)
                {
                    ++dwarvesCnt;
                    if(dwarvesCnt == 7)
                    {
                        instance->SummonCreature(NPC_INTRO_NEFARIAN, NefarianPos);
                        SaveToDB();
                    }
                }
            }

            void SetData(uint32 type, uint32 /*data*/)
            {
                switch(type)
                {
                case DATA_DRAKONID:
                    ++drakonidCnt;
                    if(drakonidCnt >= 2)
                    {
                        if(Creature * magmaw = this->instance->GetCreature(magmawGUID))
                        {
                            magmaw->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                            magmaw->SetReactState(REACT_AGGRESSIVE);
                        }
                    }
                    break;
                case DATA_ATRAMEDES_INTRO:
                    if(GameObject * go = instance->GetGameObject(bellGUID))
                        go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                    break;
                case DATA_ATRAMEDES_SUMMON:
                    if(!atramedesGUID && GetBossState(DATA_ATRAMEDES) != DONE)
                        instance->SummonCreature(NPC_ATRAMEDES, AtramedesPos);
                    break;
                default:
                    break;
                }
            }

            uint64 GetData64(uint32 type) const
            {
                switch (type)
                {
                case DATA_OMNOTRON_GUID:
                    return omnotronGUID;
                    break;
                case DATA_NEFARIUS_OMNOTRON_GUID:
                    return omnotronNefarianGUID;
                    break;
                case DATA_ARCANOTRON_GUID:
                    return arcanotronGUID;
                    break;
                case DATA_ELECTRON_GUID:
                    return electronGUID;
                    break;
                case DATA_MAGMATRON_GUID:
                    return magmatronGUID;
                    break;
                case DATA_TOXITRON_GUID:
                    return toxitronGUID;
                    break;
                case DATA_MAGMAW_GUID:
                    return magmawGUID;
                case DATA_CHIMAERON_GUID:
                    return chimaeronGUID;
                    break;
                default:
                    return 0;
                }
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
                saveStream << "B D " << GetBossSaveData() << drakonidCnt << " " << dwarvesCnt;

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

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'B' && dataHead2 == 'D')
                {
                    for (uint8 i = 0; i < ENCOUNTER_COUNT; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                    loadStream >> drakonidCnt >> dwarvesCnt;
                } else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        private:
            uint32 drakonidCnt;
            uint32 dwarvesCnt;
            uint64 magmawGUID;
            uint64 bellGUID;
            uint64 atramedesGUID;
            uint64 nefarianGUID;
            uint64 omnotronGUID;
            uint64 arcanotronGUID;
            uint64 electronGUID;
            uint64 magmatronGUID;
            uint64 toxitronGUID;
            uint64 omnotronNefarianGUID;
            uint64 chimaeronGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_blackwing_descent_InstanceMapScript(map);
        }
};

void AddSC_instance_blackwing_descent()
{
    new instance_blackwing_descent();
}
