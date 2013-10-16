/* ScriptData
SDName: boss_echo_of_baine.cpp
SD%Complete: 90%
SDCategory: endtime
EndScriptData */

// HELP me, correct the timers to cast for boss.
#include "ScriptPCH.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "endtime.h"

enum Text
{
    INTRO_NOZDORMU                      = 0, // The undying flames are all that remain of this sacred place. I sense much anger here...a seething rage, barely held in check. Be on your guard
    INTRO_NOZDORMU_2                    = 1, // You must give peace to these lands if you are to face Murozond.
    INTRO_BAINE							= 0,
    SAY_AGGRO                           = 1, // What dark horrors have you brought in this place? By my ancestors honor - I shall take you to task!
    SAY_PULVERIZE                       = 2, // There will be no escape!
    SAY_PULVERIZE_2                     = 3, // ENOUGH! I WILL NO LONGER BE CONTAINED!
    SAY_KILL                            = 4, // This is the price you pay.
    SAY_KILL_2                          = 5, // A just punishment!
    SAY_KILL_3							= 6, // Suffer for your arrogance!
    SAY_DEATH                           = 7, // Where... is this place? What... have I done? Forgive me, my father... 

};

enum Phases
{
    ON_COMBAT,
};

enum EVENTS
{
    EVENT_INTRO_NOZDORMU_1		= 1,
    EVENT_INTRO_NOZDORMU_2		= 2,
    EVENT_INTRO_NOZDORMU_3		= 3,
    EVENT_INTRO_BAINE_1			= 4,

    EVENT_PULVERIZE 			= 5,
    EVENT_PULVERIZE2 			= 6,

    EVENT_TOTEM					= 7,
    EVENT_MOLTENBLAST			= 8,

};

enum Spells
{
    SPELL_TOTEM    				   = 101614,
    SPELL_MOLTENBLAST   		   = 101840,
    SPELL_PULVERIZE		           = 101625,
    SPELL_PULVERIZE_1	           = 101626,
    SPELL_PULVERIZE_2	           = 101627,

};

class Platformreset
{
public:
    Platformreset() { }

    bool operator()(GameObject* go)
    {
        switch (go->GetEntry())
        {
        case BAINE_PLATFORM_1:
        case BAINE_PLATFORM_2:
        case BAINE_PLATFORM_3:
        case BAINE_PLATFORM_4:
            go->GetGUID();
            go->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING);
            break;
        default:
            break;
        }

        return false;
    }
};

class boss_echo_of_baine : public CreatureScript
{
public:
    boss_echo_of_baine() : CreatureScript("boss_echo_of_baine") { }

    struct boss_echo_of_baineAI : public BossAI
    {
        boss_echo_of_baineAI(Creature* pCreature) : BossAI(pCreature, DATA_ECHO_OF_BAINE)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }



        uint32 platform;
        uint8 _phase;
        uint32 phase;
        void Reset()
        {
            _Reset();
            Platformreset reset;
            Trinity::GameObjectWorker<Platformreset> worker(me, reset);
        }

        void KilledUnit(Unit* /*who*/)
        {
            Talk (RAND(SAY_KILL, SAY_KILL_2, SAY_KILL_3));
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            _EnterCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
            events.ScheduleEvent(EVENT_PULVERIZE, 4500, 0, ON_COMBAT);
            events.ScheduleEvent(EVENT_TOTEM, 3000, 0, ON_COMBAT);
            events.ScheduleEvent(EVENT_MOLTENBLAST, 3000, 0, ON_COMBAT);
        }

        void JustDied(Unit* killer)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->SetBossState(DATA_ECHO_OF_BAINE, DONE);
            Talk(SAY_DEATH);
            _JustDied();
        }

        void JustReachedHome()
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _JustReachedHome();
            instance->SetBossState(DATA_ECHO_OF_BAINE, FAIL);

            Platformreset reset;
            Trinity::GameObjectWorker<Platformreset> worker(me, reset);
            me->VisitNearbyGridObject(333.0f, worker);
        }


        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;
            events.Update(diff);
            if (!instance)
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PULVERIZE:
                    Talk(RAND(SAY_PULVERIZE, SAY_PULVERIZE_2));
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoCast(pTarget, SPELL_PULVERIZE);
                        DoCast(pTarget, SPELL_PULVERIZE_1);
                    }
                    events.ScheduleEvent(EVENT_PULVERIZE2, 3500, 0, ON_COMBAT);
                    events.ScheduleEvent(EVENT_PULVERIZE, 40000, 0, ON_COMBAT);
                    break;
                case EVENT_PULVERIZE2:
                    DoCast(SPELL_PULVERIZE_2);
                    break;
                case EVENT_TOTEM:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoCast(pTarget, SPELL_TOTEM);
                    }
                    events.ScheduleEvent(EVENT_TOTEM, 25000, 0, ON_COMBAT);
                    break;
                case EVENT_MOLTENBLAST:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoCast(101840);
                    }
                    events.ScheduleEvent(EVENT_MOLTENBLAST, 10000, 0, ON_COMBAT);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_echo_of_baineAI(pCreature);
    }

};

class npc_nozdormu_baine : public CreatureScript
{
public:
    npc_nozdormu_baine() : CreatureScript("npc_nozdormu_baine") { }

    struct npc_nozdormu_baineAI : public ScriptedAI
    {
        npc_nozdormu_baineAI(Creature* creature) : ScriptedAI(creature), pInstance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/)
        {
            _events.ScheduleEvent(EVENT_INTRO_NOZDORMU_1, 2500);
        }

        void UpdateAI(uint32 diff)
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INTRO_NOZDORMU_1:
                    Talk(INTRO_NOZDORMU);
                    _events.ScheduleEvent(EVENT_INTRO_NOZDORMU_2, 10000);
                    break;
                case EVENT_INTRO_NOZDORMU_2:
                    Talk(INTRO_NOZDORMU_2);
                    _events.ScheduleEvent(EVENT_INTRO_BAINE_1, 6000);
                    break;
                case EVENT_INTRO_BAINE_1:
                    if (Creature* pBaine = me->GetCreature(*me, uiBaine))
                        pBaine->AI()->Talk(INTRO_BAINE);
                    _events.ScheduleEvent(EVENT_INTRO_NOZDORMU_3, 6000);
                    break;
                case EVENT_INTRO_NOZDORMU_3:
                    me->DespawnOrUnsummon();
                    break;

                }
            }
        }

    protected:
        EventMap _events;
        InstanceScript* pInstance;
        uint64 uiBaine;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_nozdormu_baineAI(creature);
    }
};

void AddSC_boss_echo_of_baine()
{
    new boss_echo_of_baine();
    new npc_nozdormu_baine();
}