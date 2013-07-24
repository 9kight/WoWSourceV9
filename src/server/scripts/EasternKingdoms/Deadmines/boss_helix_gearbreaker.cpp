#include "ScriptMgr.h"
#include "deadmines.h"
#include "Vehicle.h"

enum Spells {
    SPELL_CHEST_BOMB        = 88352,
    SPELL_STICKY_BOMB       = 132998,
    SPELL_OAF_SMASH         = 88300,
};

enum Events {
    EVENT_CHEST_BOMB,
    EVENT_STICKY_BOMB,
    EVENT_OAF_SMASH,
    EVENT_THROW_HELIX,
};

enum NPCs {
    NPC_HELIX_CREW          = 49136,
};

class boss_helix_gearbreaker : public CreatureScript {
public:
    boss_helix_gearbreaker() : CreatureScript("boss_helix_gearbreaker") { }

    CreatureAI* GetAI(Creature* creature) const {
        return new boss_helix_gearbreakerAI (creature);
    }

    struct boss_helix_gearbreakerAI : public ScriptedAI {
        boss_helix_gearbreakerAI(Creature* creature) : ScriptedAI(creature) {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Creature* oaf;

        void Reset() {
            me->SetReactState(REACT_PASSIVE);
            if (oaf = (me->SummonCreature(NPC_LUMBERING_OAF, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN)))
            {
              if (!me->GetVehicle() && oaf->IsVehicle() && oaf->GetVehicleKit()->HasEmptySeat(0))
              {
                me->EnterVehicle(oaf);
                oaf->SetReactState(REACT_AGGRESSIVE); 
                oaf->SetHealth(oaf->CountPctFromMaxHealth(100));
                oaf->GetMotionMaster()->MoveTargetedHome();
              }
            }
        }

        void EnterCombat(Unit* who) {
            InitEvents();
            if (oaf) {
                oaf->GetMotionMaster()->Clear();
                oaf->AddThreat(who, 10.0f); 
                oaf->Attack(who, false);
            }
        }

        void InitEvents() {
            events.ScheduleEvent(EVENT_CHEST_BOMB, 30000);
        }

        void UpdateAI(uint32 const diff) {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent()) {
                switch (eventId) {
                    case EVENT_CHEST_BOMB:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_CHEST_BOMB);

                        events.ScheduleEvent(EVENT_CHEST_BOMB, 20000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_lumbering_oaf : public CreatureScript {
public:
    npc_lumbering_oaf() : CreatureScript("npc_lumbering_oaf") { }

    CreatureAI* GetAI(Creature* creature) const {
        return new npc_lumbering_oafAI (creature);
    }

    struct npc_lumbering_oafAI : public ScriptedAI {
        npc_lumbering_oafAI(Creature* creature) : ScriptedAI(creature) {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        
        void UpdateAI(uint32 const diff) {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_helix_gearbreaker() {
    new boss_helix_gearbreaker();
    new npc_lumbering_oaf();
}
