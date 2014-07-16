/*
*
* Copyright (C) 2012-2014 Cerber Project <https://bitbucket.org/mojitoice/>
*
*/

#include "ScriptPCH.h"
#include "deadmines.h"

enum eSpels
{
    SPELL_CANNONBALL        = 89697, // 91066 (HC) supported by Spell Difficulty
    SPELL_THROW             = 91038,
    SPELL_THROW_H           = 91039,
    SPELL_EXPLODE           = 89769,
    SPELL_EYE_GOUGE         = 90913,
    SPELL_EYE_GOUGE_H       = 90918,
    SPELL_EYE_PECK          = 90920,
    SPELL_EYE_PECK_H        = 90921,
};

Position const SourcePosition[8] =
{
    {-30.2622f, -793.069f, 19.237f},
    {-72.1059f, -786.894f, 39.5538f},
    {-58.6424f, -787.132f, 39.3505f},
    {-82.3142f, -775.5f,   26.8933f},
    {-46.901f,  -783.155f, 18.4898f},
    {-89.2569f, -782.528f, 17.2564f},
    {-122.925f, -388.813f, 59.0769f},
    {-40.0035f, -793.302f, 39.4754f},
};

Position const TargetPosition[8] =
{
    {0.512153f, -768.229f, 9.80134f},
    {-72.559f,  -731.221f, 8.5869f},
    {-49.3264f, -730.056f, 9.32048f},
    {-100.849f, -703.773f, 9.29407f},
    {-30.6337f, -727.731f, 8.52102f},
    {-88.4253f, -724.722f, 8.67503f},
    {-91.9409f, -375.307f, 57.9774f},
    {-12.0556f, -740.252f, 9.10946f},
};

/**
 * TODO: this npc is also used in Ship and require 48522
 */
class npc_defias_cannon : public CreatureScript
{
public:
    npc_defias_cannon() : CreatureScript("npc_defias_cannon") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_defias_cannonAI(creature);
    }

    struct npc_defias_cannonAI : public ScriptedAI
    {
        npc_defias_cannonAI(Creature* creature) : ScriptedAI(creature), TargetGUID(0)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 Phase;
        uint32 CannonBlast_Timer;
        uint64 TargetGUID;

        void Reset()
        {
            Phase = 0;
            CannonBlast_Timer = DATA_CANNON_BLAST_TIMER;
            if (!me)
                return;

            if (!ObjectAccessor::GetCreature(*me, TargetGUID))
                GetCreature();
        }

        bool GetSupporter()
        {
            Creature* supporter = me->FindNearestCreature(NPC_OGRE_HENCHMAN, 7.0f, true);
            if (supporter)
                return true;

            supporter = me->FindNearestCreature(NPC_DEFIAS_PIRATE, 5.0f, true);
            if (supporter)
                return true;

            return false;
        }

        void EnterCombat(Unit* /*who*/) { }

        void GetCreature()
        {
            if (!me)
                return;

            for (uint8 i = 0; i <= 7; i++)
            {
                if (me->IsInDist(&SourcePosition[i], 1.0f))
                {
                    TargetGUID = me->SummonCreature(NPC_SCORCH_MARK_BUNNY_JMF, TargetPosition[i])->GetGUID();
                    break;
                }
            }
        }

        void UpdateAI(uint32 const uiDiff)
        {
            if (!me)
                return;

            if (Phase == 0)
            {
                if (CannonBlast_Timer <= uiDiff)
                {
                    if (!GetSupporter())
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        Phase++;
                    } else if (Creature* target = ObjectAccessor::GetCreature(*me, TargetGUID))
                    {
                        me->CastSpell(target, SPELL_CANNONBALL);
                    }
                    CannonBlast_Timer = urand(3000, 5000);
                } else
                    CannonBlast_Timer -= uiDiff;
            }
        }
    };
};

class npc_mining_monkey : public CreatureScript
{
public:
    npc_mining_monkey() : CreatureScript("npc_mining_monkey") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_mining_monkeyAI(creature);
    }

    struct npc_mining_monkeyAI : public ScriptedAI
    {
        npc_mining_monkeyAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 Phase;
        uint32 uiTimer;

        void Reset()
        {
            Phase = 1;
            uiTimer = 2000;
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (!me)
                return;

            if (Phase == 1)
            {
                if (me->GetHealth()-damage <= me->GetMaxHealth()*0.15)
                {
                    Phase++;
                }
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (!me)
                return;
        }

        void UpdateAI(uint32 const uiDiff)
        {
            if (!me || !me->AI() || !UpdateVictim())
                return;

            switch (Phase)
            {
                case 1:
                    if (Unit* victim = me->GetVictim())
                    {
                        if (me->IsInRange(victim, 0, 35.0f, true))
                        {
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                            if (uiTimer <= uiDiff)
                            {
                                me->CastSpell(victim, IsHeroic() ? SPELL_THROW_H : SPELL_THROW);
                                uiTimer = 2000;
                            } else
                                uiTimer -= uiDiff;
                        } else
                        {
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                        }
                    }
                    break;
                case 2:
                    Talk(0);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    Phase++;
                    break;
                default:
                    me->DoFleeToGetAssistance();
                    break;
            }
        }
    };
};

/**
 * explode door and say mobs after Door to attack tank...
 */
class go_defias_cannon : public GameObjectScript
{
public:
    go_defias_cannon() : GameObjectScript("go_defias_cannon") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (!go || !player)
            return false;

        InstanceScript* instance = go->GetInstanceScript();
        if (GameObject* ironCladDoor = go->FindNearestGameObject(GO_IRONCLAD_DOOR, 30.0f))
        {
            go->SetGoState(GO_STATE_ACTIVE);
            go->PlayDistanceSound(SOUND_CANNONFIRE, player);
            ironCladDoor->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
            ironCladDoor->PlayDistanceSound(SOUND_DESTROYDOOR, player);

            MoveCreatureInside(go, NPC_DEFIAS_SHADOWGUARD);
            MoveCreatureInside(go, NPC_DEFIAS_ENFORCER);
            MoveCreatureInside(go, NPC_DEFIAS_BLOODWIZARD);
            if (Creature* bunny = go->SummonCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ()))
            {
                bunny->AI()->Talk(0);
            }
        }
        return true;
    }

    void MoveCreatureInside(GameObject* go, uint32 entry)
    {
        if (!go || entry <= 0)
            return;

        if (Creature* defias = go->FindNearestCreature(entry, 20.0f))
        {
            defias->SetWalk(false);
            defias->GetMotionMaster()->MovePoint(0, -102.7f, -655.9f, defias->GetPositionZ());
        }
    }
};

class npc_deadmines_bird : public CreatureScript
{
public:
    npc_deadmines_bird() : CreatureScript("npc_deadmines_bird") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_deadmines_birdAI(creature);
    }

    struct npc_deadmines_birdAI : public ScriptedAI
    {
        npc_deadmines_birdAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 uiTimerEyePeck;
        uint32 uiTimerEyeGouge;

        void Reset()
        {
            uiTimerEyePeck  = urand(4000, 4900);
            uiTimerEyeGouge = urand(7000, 9000);
        }

        void UpdateAI(uint32 const uiDiff)
        {
            if (!me)
                return;

            if (!UpdateVictim())
                return;

            if (uiTimerEyeGouge <= uiDiff)
            {
                if (Unit* victim = me->GetVictim())
                {
                    me->CastSpell(victim, IsHeroic() ? SPELL_EYE_GOUGE_H : SPELL_EYE_GOUGE);
                }
                uiTimerEyeGouge = urand(9000, 12000);
                return;
            } else
                uiTimerEyeGouge -= uiDiff;

            if (uiTimerEyePeck <= uiDiff)
            {
                if (Unit* victim = me->GetVictim())
                {
                    me->CastSpell(victim, IsHeroic() ? SPELL_EYE_PECK_H : SPELL_EYE_PECK);
                }
                uiTimerEyePeck = urand(16000, 19000);
                return;
            } else
                uiTimerEyePeck -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_goblin_engineer : public CreatureScript
{
public:
    npc_goblin_engineer() : CreatureScript("npc_goblin_engineer") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_goblin_engineerAI(creature);
    }

    struct npc_goblin_engineerAI : public ScriptedAI
    {
        npc_goblin_engineerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        void Reset()
        {
            if (!me)
                return;

            if (me->FindNearestGameObject(GO_HEAVY_DOOR, 20.0f))
                me->AddAura(78087, me);
            else
                me->AddAura(57626, me);
        }

        void UpdateAI(uint32 const uiDiff) { }
    };
};

class go_heavy_door : public GameObjectScript
{
public:
    go_heavy_door() : GameObjectScript("go_heavy_door") { }

    void MoveNearCreature(GameObject* me, uint32 entry, uint32 ragne)
    {
        if (!me)
            return;

        std::list<Creature*> creature_list;
        me->GetCreatureListWithEntryInGrid(creature_list, entry, ragne);

        creature_list.sort(Trinity::ObjectDistanceOrderPred(me));
        for (std::list<Creature*>::iterator itr = creature_list.begin(); itr != creature_list.end(); ++itr)
        {
            if (( *itr ) && ( *itr )->isAlive() && ( *itr )->GetTypeId() == TYPEID_UNIT && ( *itr )->HasAura(78087))
            {
                ( *itr )->GetMotionMaster()->MoveCharge( me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 5.0f);
                ( *itr )->DespawnOrUnsummon(3000);
                ( *itr )->AI()->Talk(0);
            }
        }
    }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (!go || !player)
            return false;

        MoveNearCreature(go, 48439, 50.0f);
        MoveNearCreature(go, 48280, 50.0f);

        return true;
    }
};

#define GOSSIP_BOSS_1 "Press the button labeled 'Wood and Lumber.'"
#define GOSSIP_BOSS_2 "Press the button labeled 'Metal and Scraps.'"
#define GOSSIP_BOSS_3 "Press the button labeled 'Ship Parts.'"

class go_deadmines_tp : public GameObjectScript
{
public:
    go_deadmines_tp() : GameObjectScript("go_deadmines_tp") { }

    bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 sender, uint32 action)
    {
        if (player->HasAura(SPELL_NIGHTMARE_ELIXIR))
            return false;

        player->PlayerTalkClass->ClearMenus();
        player->CLOSE_GOSSIP_MENU();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->TeleportTo(player->GetMapId(), -305.32f, -491.29f, 49.23f, 3.14f);
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->TeleportTo(player->GetMapId(), -201.09f, -606.04f, 19.30f, 3.14f);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->TeleportTo(player->GetMapId(), -129.91f, -788.89f, 17.34f, 3.14f);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->HasAura(SPELL_NIGHTMARE_ELIXIR))
            return false;

        InstanceScript* instance = go->GetInstanceScript();
        if (!instance)
            return false;

        if (instance->GetBossState(DATA_HELIX) == DONE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BOSS_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        }
        if (instance->GetBossState(DATA_FOEREAPER) == DONE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BOSS_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        }
        if (instance->GetBossState(DATA_RIPSNARL) == DONE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BOSS_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        }
        player->SEND_GOSSIP_MENU(player->GetGossipTextId(go), go->GetGUID());
        return true;
    }
};


class npc_mining_powder : public CreatureScript
{
public:
    npc_mining_powder() : CreatureScript("npc_mining_powder") { }

    struct npc_mining_powderAI : public ScriptedAI
    {
        npc_mining_powderAI(Creature* creature) : ScriptedAI(creature), damaged(false) { }

        bool damaged;

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (damaged)
                return;
            damaged = true;
            me->CastSpell(me, SPELL_EXPLODE);
            me->DespawnOrUnsummon(100);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_mining_powderAI(creature);
    }
};

void AddSC_deadmines()
{
    new npc_mining_monkey();
    new npc_defias_cannon();
    new go_defias_cannon();
    new npc_deadmines_bird();
    new go_heavy_door();
    new npc_goblin_engineer();
    new go_deadmines_tp();
    new npc_mining_powder();
}
