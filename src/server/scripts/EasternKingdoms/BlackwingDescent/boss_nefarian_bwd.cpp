#include "ScriptMgr.h"
#include "blackwing_descent.h"

enum Spells {
    SPELL_ELECTROCUTE             = 94089, // Nefarian
    SPELL_SHADOWFLAME_BREATH      = 77826,
    SPELL_TAIL_LASH               = 23364,
    SPELL_SHADOW_OF_COWARDICE     = 79353, 
    SPELL_EXPLOSIVE_CINDERS       = 79339, // hc
    SPELL_CHILDREN_OF_DEATHWING   = 78619,
    SPELL_HAIL_OF_BONES           = 78684,
    SPELL_DOMINION                = 79318,
    SPELL_SHADOWFLAME_BARRAGE     = 78621,
    SPELL_SHADOWBLAZE_SPARK       = 81031,
    
    SPELL_SHADOW_BREATH           = 77826, // Onyxia
    SPELL_LIGHTNING_DISCHARGE     = 94107,
    SPELL_OVERLOAD                = 78999,
    
    SPELL_EMPOWER                 = 79330, // Bone Warrior
    SPELL_HURL_BONE               = 81586,
    
    SPELL_BLAST_NOVA              = 80734, // Prototype
};

enum Events {
    // Nefarian Events
    EVENT_SHADOWFLAME_BREATH = 1, 
    EVENT_TAIL_LASH,
    EVENT_SHADOW_OF_COWARDICE,
    EVENT_SHADOWBLAZE_SPARK,
    EVENT_EXPLOSIVE_CINDERS, // hc

    // Onyxia Events
    EVENT_LIGHTNING_DISCHARGE,
    EVENT_SHADOW_BREATH,

    // Bone Warrior Events
    EVENT_EMPOWER, 
    EVENT_HURL_BONE
};

enum Phases {
    PHASE_INTRO,
    PHASE_ONE,
    PHASE_TWO,
    PHASE_THREE
};

enum Actions {
    //Nefarian Actions
    ACTION_ONYXIA_RESET,
    ACTION_ONYXIA_DIED
};

//Prototype Locations
const Position PrototypeLoc[] = 
{
    {-138.410339f, -250.865982f, 25.165585f, 0.00f},
    {-71.121140f , -235.487427f, 35.362190f, 0.00f},
    {-118.801903f, -183.530136f, 31.782761f, 0.00f},
};

//Bone Warrior Locations
const Position BoneWarriorLoc[] = 
{
    {-135.034927f, -195.426865f, 20.359344f, 0.00f},
    {-133.972275f, -246.354782f, 20.359377f, 0.00f},
    {-111.243645f, -182.850723f, 20.358669f, 0.00f},
    {-113.298744f, -261.105133f, 20.359344f, 0.00f},
};

const Position MiddleRoomLocation = {-103.057961f, -222.698685f, 18.374910f, 0.0f};
const Position Phase2Location = {-103.057961f, -222.698685f, 36.959911f, 0.0f};
const Position OnyxiaLocation = {-102.864f, -222.71f, 18.3749f, 3.1601f};

Creature* pNefarian;
Creature* pOnyxia;

class boss_nefarian_bwd : public CreatureScript {
public:
    boss_nefarian_bwd() : CreatureScript("boss_nefarian_bwd") { }

    struct boss_nefarian_bwdAI : public BossAI {
        boss_nefarian_bwdAI(Creature* creature) : BossAI(creature, DATA_NEFARIAN) {
            pNefarian = me;
            instance = creature->GetInstanceScript();
        }

        void Reset() {
            events.Reset();
            InitPhase(PHASE_INTRO);
        }

        void PhaseIntro() { // fly to the ground to assist onyxia
            while (uint32 eventId = events.ExecuteEvent()) {
                switch (eventId) {
                    default: return;
                }
            }
        }

        void PhaseOne() {
            while (uint32 eventId = events.ExecuteEvent()) {
                switch (eventId) {
                    case EVENT_SHADOWFLAME_BREATH: {
                        DoCastVictim(SPELL_SHADOWFLAME_BREATH);
                        events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, urand(21000, 33000));
                        break;
                    }
                
                    case EVENT_TAIL_LASH: {
                        DoCastAOE(SPELL_TAIL_LASH);
                        events.ScheduleEvent(EVENT_TAIL_LASH, urand(15000, 22000));
                        break;
                    }

                    case EVENT_SHADOW_OF_COWARDICE: {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                            DoCast(pTarget, SPELL_SHADOW_OF_COWARDICE);
                        events.ScheduleEvent(EVENT_SHADOW_OF_COWARDICE, urand(19000, 27000));
                        break;
                    }
                    default: return;
                }
            }

            if (uint8(me->GetHealth()*100/me->GetMaxHealth()) < 70)
                InitPhase(PHASE_TWO);
        }

        void PhaseTwo() {
            while (uint32 eventId = events.ExecuteEvent()) {
                switch (eventId) {
                    case EVENT_SHADOW_OF_COWARDICE: {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                            DoCast(pTarget, SPELL_SHADOW_OF_COWARDICE);
                        events.ScheduleEvent(EVENT_SHADOW_OF_COWARDICE, urand(19000, 27000));
                        break;
                    }

                    case EVENT_EXPLOSIVE_CINDERS: {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                            DoCast(target, SPELL_EXPLOSIVE_CINDERS);
                        events.ScheduleEvent(EVENT_EXPLOSIVE_CINDERS, urand(18000, 23000));
                        break;
                    }
                    default: return;
                }
            }

            if (uint8(me->GetHealth()*100/me->GetMaxHealth()) < 60)
                InitPhase(PHASE_THREE);
        }

        void PhaseThree() {
            while (uint32 eventId = events.ExecuteEvent()) {
                switch (eventId) {
                    case EVENT_SHADOW_OF_COWARDICE: {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                            DoCast(pTarget, SPELL_SHADOW_OF_COWARDICE);
                        events.ScheduleEvent(EVENT_SHADOW_OF_COWARDICE, urand(19000, 27000));
                        break;
                    }

                    case EVENT_SHADOWFLAME_BREATH: {
                        DoCastVictim(SPELL_SHADOWFLAME_BREATH);
                        events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, urand(21000, 33000));
                        break;
                    }
                
                    case EVENT_TAIL_LASH: {
                        DoCastAOE(SPELL_TAIL_LASH);
                        events.ScheduleEvent(EVENT_TAIL_LASH, urand(15000, 22000));
                        break;
                    }

                    case EVENT_SHADOWBLAZE_SPARK: {
                        DoCastAOE(SPELL_SHADOWBLAZE_SPARK);
                        events.ScheduleEvent(EVENT_SHADOWBLAZE_SPARK, urand(10000, 20000));
                        break;
                    }
                    default: return;
                }
            }
        }

        void UpdateAI(const uint32 diff) {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!phase) 
                PhaseIntro();
            else if (phase == 1)
                PhaseOne();
            else if (phase == 2)
                PhaseTwo();
            else if (phase == 3)
                PhaseThree();

            if (uint8(me->GetHealth()*100/me->GetMaxHealth()) < nextEC) { // alle 10%
                DoCast(SPELL_ELECTROCUTE);
                nextEC -= 10;
            }
        }

        void DoAction(int32 const action) {
            switch (action) {
                case ACTION_ONYXIA_DIED: {
                    break;
                }

                case ACTION_ONYXIA_RESET: {
                    break;
                }
            }
        }

        void InitPhase(uint8 _phase) { // init phase id + event timer
            switch (_phase) {
                case PHASE_INTRO: {
                    phase = 0;
                    break;
                }

                case PHASE_ONE: {
                    phase = 1;
                    events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, urand(21000, 33000));
                    events.ScheduleEvent(EVENT_TAIL_LASH, urand(15000, 22000));
                    events.ScheduleEvent(EVENT_SHADOW_OF_COWARDICE, urand(19000, 27000));
                    break;
                }

                case PHASE_TWO: {
                    phase = 2;

                    if (IsHeroic()) {
                        events.ScheduleEvent(EVENT_EXPLOSIVE_CINDERS, 1000);
                    }

                    for (uint8 i = 0; i < 3; i++)
                        me->SummonCreature(NPC_PROTOTYPE, PrototypeLoc[i].GetPositionX(), PrototypeLoc[i].GetPositionY(), PrototypeLoc[i].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                    me->SetSpeed(MOVE_FLIGHT, 4.0f);
                    me->GetMotionMaster()->MovePoint(1, Phase2Location);
                    break;
                }

                case PHASE_THREE: {
                    phase = 3;
                    me->SetCanFly(false);
                    me->SetDisableGravity(false);
                    me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetSpeed(MOVE_WALK, 1.3f);
                    me->GetMotionMaster()->MovePoint(1, MiddleRoomLocation);
                    break;
                }
            }
        }

    private:
        uint8 phase;
        uint8 nextEC;
        InstanceScript *instance;
    };

    CreatureAI* GetAI(Creature *creature) const {
        return new boss_nefarian_bwdAI (creature);
    }
};

class npc_onyxia_bwd : public CreatureScript {
public:
    npc_onyxia_bwd() : CreatureScript("npc_onyxia_bwd") { }

    struct npc_onyxia_bwdAI : public ScriptedAI {
        npc_onyxia_bwdAI(Creature *c) : ScriptedAI(c) {
            instance = c->GetInstanceScript();
            pOnyxia = me;
            
            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
            me->setPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 0);
        }

        void Reset() {
            me->SetPower(POWER_MANA,0);
            events.Reset();

            DespawnMinions();
            
            if (pNefarian) {
                pNefarian->SetPhaseMask(2, true);

                if (pNefarian->AI())
                    pNefarian->AI()->DoAction(ACTION_ONYXIA_RESET);
            }
        }
        
        void EnterCombat(Unit* who) {
            events.ScheduleEvent(EVENT_LIGHTNING_DISCHARGE, urand(24000,51000));
            events.ScheduleEvent(EVENT_SHADOW_BREATH, urand(24000,44000));
            events.ScheduleEvent(EVENT_TAIL_LASH, urand(15000,22000));

            if (pNefarian)
                pNefarian->SetPhaseMask(1, true);
        }
        
        void JustDied(Unit * /*killer*/) {
            if (pNefarian)
                if (pNefarian->AI())
                    pNefarian->AI()->DoAction(ACTION_ONYXIA_DIED);
        }

        void UpdateAI(const uint32 diff) {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent()) {
                switch (eventId) {
                    case EVENT_LIGHTNING_DISCHARGE: {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 10.0f, true))
                            DoCast(target, SPELL_LIGHTNING_DISCHARGE);
                        events.ScheduleEvent(EVENT_LIGHTNING_DISCHARGE, urand(24000, 51000));
                        break;
                    }
                    
                    case EVENT_SHADOW_BREATH: {
                        DoCastVictim(SPELL_SHADOW_BREATH);
                        events.ScheduleEvent(EVENT_SHADOW_BREATH, urand(24000, 44000));
                        break;
                    }
                    
                    case EVENT_TAIL_LASH: {
                        DoCast(me, SPELL_TAIL_LASH);
                        events.ScheduleEvent(EVENT_TAIL_LASH, urand(15000, 22000));
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        EventMap events;

        inline void DespawnMinions() {
            DespawnCreatures(NPC_BONE_WARRIOR);
            DespawnCreatures(NPC_PROTOTYPE);
        }

        void DespawnCreatures(uint32 entry) {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 200.0f);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }
    };

    CreatureAI* GetAI(Creature* creature) const {
        return new npc_onyxia_bwdAI (creature);
    }
};

class npc_bone_warrior : public CreatureScript {
public:
    npc_bone_warrior() : CreatureScript("npc_bone_warrior") { }

    struct npc_bone_warriorAI : public ScriptedAI {
        npc_bone_warriorAI(Creature *c) : ScriptedAI(c) { }

        void Reset() {
            HurlBoneTimer = 10000;
            EmpowerTimer = 20000;
            PowerDecrementTimer = 1000;
            power = 100;
            me->SetPower(POWER_ENERGY, power); //Power Energy???
        }

        void JustDied(Unit* /*killer*/) {
            me->DespawnOrUnsummon(5000);
        }

        void UpdateAI(const uint32 diff) {
            if (!UpdateVictim())
                return;

            if (EmpowerTimer <= diff) {
                DoCast(me, SPELL_EMPOWER);
                EmpowerTimer = 20000;
            } else {
                EmpowerTimer -= diff;
            }
            
            if (HurlBoneTimer <= diff) {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                    DoCast(target, SPELL_HURL_BONE);
                HurlBoneTimer = 10000;
            } else {
                HurlBoneTimer -= diff;
            }

            if (PowerDecrementTimer <= diff) {
                me->SetPower(POWER_ENERGY, --power);
                if (power < 1) {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE);
                    me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                }
            } else {
                PowerDecrementTimer -= diff;
            }
            
            DoMeleeAttackIfReady();
        }

        private:
            uint32 HurlBoneTimer;
            uint32 EmpowerTimer;
            uint32 PowerDecrementTimer;
            uint8  power;
    };

    CreatureAI* GetAI(Creature* creature) const {
        return new npc_bone_warriorAI(creature);
    }
};

class npc_chromatic_prototype : public CreatureScript {
public:
    npc_chromatic_prototype() : CreatureScript("npc_chromatic_prototype") { }

    

    struct npc_chromatic_prototypeAI : public ScriptedAI {
        npc_chromatic_prototypeAI(Creature *c) : ScriptedAI(c) {
//            pPrototype = me;
            instance = c->GetInstanceScript();
        }

        void Reset() {
            uiBlast_Nova = 12000;
        }
        
        void JustDied(Unit* /*killer*/) {
            me->DespawnOrUnsummon(5000);
        }

        void UpdateAI(const uint32 diff) {
            if (!UpdateVictim())
                return;
            
            if(uiBlast_Nova <= diff) {
                me->InterruptNonMeleeSpells(true);
                DoCastAOE(SPELL_BLAST_NOVA);
                uiBlast_Nova = 12000;
            } else {
                uiBlast_Nova -= diff;
            }

            DoMeleeAttackIfReady();
        }

    private:
        uint32 uiBlast_Nova;
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* pCreature) const {
        return new npc_chromatic_prototypeAI (pCreature);
    }
};

void AddSC_boss_nefarian_bwd() {
    new boss_nefarian_bwd();
    new npc_bone_warrior();
    new npc_onyxia_bwd();
    new npc_chromatic_prototype();
}
