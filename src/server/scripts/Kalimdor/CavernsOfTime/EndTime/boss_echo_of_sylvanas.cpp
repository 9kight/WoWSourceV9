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
    INTRO_SYLVANAS							= 0,
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
    EVENT_INTRO_NOZDORMU_1				= 1,
    EVENT_INTRO_NOZDORMU_2				= 2,
    EVENT_INTRO_NOZDORMU_3				= 3,
    EVENT_INTRO_SYLVANAS_1				= 4,

    EVENT_CALLING_OF_THE_HIGHBORNE		= 5,
    EVENT_SHRIEK_OF_THE_HIGHBORNE		= 6,
    EVENT_BLACK_ARROW					= 7,
    EVENT_UNHOLY_SHOT					= 8,
    EVENT_BLIGHTED_ARROWS				= 9,
    EVENT_SACRIFICE						= 10,
    EVENT_CALLING_OF_THE_HIGHBORNE2		= 11,
    EVENT_CALLING_OF_THE_HIGHBORNE3		= 12,
    EVENT_DESPAWN						= 13,
};

enum Spells
{
    SPELL_CALLING_OF_THE_HIGHBORNE		= 100686,
    SPELL_CALLING_OF_THE_HIGHBORNE2		= 105766,
    SPELL_WRACKING_PAIN					= 101258,
    SPELL_SHRIEK_OF_THE_HIGHBORNE		= 101412,
    SPELL_SACRIFICE		   		   		= 101348,
    SPELL_BLACK_ARROW	           		= 101404,
    SPELL_UNHOLY_SHOT	           		= 101411,
    SPELL_BLIGHTED_ARROWS         		= 101401,
};

enum MovePoints
{
    POINT_END,
};

Position const SummonPositions[9] =
{
    {3860.87f, 933.488f, 55.8451f, 4.07536f},
    {3861.88f, 892.72f, 55.974f, 2.37295f},
    {3870.55f, 914.55f, 55.8985f, 3.28849f},
    {3815.28f, 913.11f, 55.490036f, 6.20176f},
    {3821.19f, 891.696f, 55.8674f, 0.787663f},
    {3840.6f, 883.566f, 55.9362f, 1.41476f},
    {3816.63f, 934.567f, 55.9203f, 5.79538f},
    {3838.74f, 941.945f, 55.7624f, 4.92806f},
};

Position const EndPosition = {3845.510010f, 909.317993f, 56.062218f, 0.0f};

class boss_echo_of_sylvanas : public CreatureScript
{
public:
    boss_echo_of_sylvanas() : CreatureScript("boss_echo_of_sylvanas") { }

    struct boss_echo_of_sylvanasAI : public BossAI
    {
        boss_echo_of_sylvanasAI(Creature* pCreature) : BossAI(pCreature, DATA_ECHO_OF_SYLVANAS)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        }


        void Reset()
        {
            _Reset();

        }

        void KilledUnit(Unit* /*who*/)
        {
            Talk (RAND(SAY_KILL, SAY_KILL_2, SAY_KILL_3));
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            _EnterCombat();
            instance->SendEncounterUnit(DATA_ECHO_OF_SYLVANAS, me, 1);
            events.ScheduleEvent(EVENT_SHRIEK_OF_THE_HIGHBORNE, 30000, 0, ON_COMBAT);
            events.ScheduleEvent(EVENT_CALLING_OF_THE_HIGHBORNE, 3000, 0, ON_COMBAT);
            events.ScheduleEvent(EVENT_CALLING_OF_THE_HIGHBORNE2, 3000, 0, ON_COMBAT);
            events.ScheduleEvent(EVENT_CALLING_OF_THE_HIGHBORNE3, 3000, 0, ON_COMBAT);
            events.ScheduleEvent(EVENT_BLACK_ARROW, 3000, 0, ON_COMBAT);
            events.ScheduleEvent(EVENT_UNHOLY_SHOT, 3000, 0, ON_COMBAT);
            //events.ScheduleEvent(EVENT_BLIGHTED_ARROWS, 3000, 0, ON_COMBAT);
        }

        void JustDied(Unit* killer)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->SetBossState(DATA_ECHO_OF_SYLVANAS, DONE);
            Talk(SAY_DEATH);
            _JustDied();
        }

        void JustReachedHome()
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _JustReachedHome();
            instance->SetBossState(DATA_ECHO_OF_SYLVANAS, FAIL);
        }

        void SummonGhouls()
        {
            for (uint32 i = 0; i < 8; i++)
                me->SummonCreature(NPC_RISEN_GHOUL, SummonPositions[i]);
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
                case EVENT_CALLING_OF_THE_HIGHBORNE:
                    Talk(RAND(SAY_PULVERIZE, SAY_PULVERIZE_2));
                    DoCast(me, SPELL_CALLING_OF_THE_HIGHBORNE);
                    events.ScheduleEvent(EVENT_CALLING_OF_THE_HIGHBORNE, 40000, 0, ON_COMBAT);
                    break;
                case EVENT_CALLING_OF_THE_HIGHBORNE2:
                    SummonGhouls();
                    events.ScheduleEvent(EVENT_CALLING_OF_THE_HIGHBORNE2, 40000, 0, ON_COMBAT);
                    break;
                case EVENT_CALLING_OF_THE_HIGHBORNE3:
                    me->RemoveAura(SPELL_CALLING_OF_THE_HIGHBORNE);
                    events.ScheduleEvent(EVENT_CALLING_OF_THE_HIGHBORNE3, 59000, 0, ON_COMBAT);
                    break;
                case EVENT_SHRIEK_OF_THE_HIGHBORNE:
                    DoCast(SPELL_SHRIEK_OF_THE_HIGHBORNE);
                    events.ScheduleEvent(EVENT_SHRIEK_OF_THE_HIGHBORNE, 1000, 0, ON_COMBAT);
                    break;
                case EVENT_BLACK_ARROW:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoCast(pTarget, SPELL_BLACK_ARROW);
                    }
                    events.ScheduleEvent(EVENT_BLACK_ARROW, 25000, 0, ON_COMBAT);
                    break;
                case EVENT_UNHOLY_SHOT:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoCast(SPELL_UNHOLY_SHOT);
                    }
                    events.ScheduleEvent(EVENT_UNHOLY_SHOT, 10000, 0, ON_COMBAT);
                    break;
                    //case EVENT_BLIGHTED_ARROWS:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoCast(SPELL_BLIGHTED_ARROWS);
                    }
                    events.ScheduleEvent(EVENT_UNHOLY_SHOT, 10000, 0, ON_COMBAT);
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
        return new boss_echo_of_sylvanasAI(pCreature);
    }

};

class npc_risenghoul : public CreatureScript
{
public:
    npc_risenghoul() : CreatureScript("npc_risenghoul") { }

    struct npc_risenghoulAI : public ScriptedAI
    {
        npc_risenghoulAI(Creature* creature) : ScriptedAI(creature), pTarget(NULL), pInstance(creature->GetInstanceScript())
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }
        void IsSummonedBy(Unit* /*summoner*/)
        {
            DoCast(me, SPELL_CALLING_OF_THE_HIGHBORNE2);
            me->GetMotionMaster()->MovePoint(POINT_END, EndPosition);
            me->SetSpeed(MOVE_WALK, 0.8f);
            me->SetWalk(true);
            _events.ScheduleEvent(EVENT_SACRIFICE, 17000, 0, ON_COMBAT);
            _events.ScheduleEvent(EVENT_DESPAWN, 18000, 0, ON_COMBAT);
        }

        void UpdateAI(uint32 diff)
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SACRIFICE:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoCastAOE(SPELL_SACRIFICE);
                    }
                    break;
                case EVENT_DESPAWN:
                    me->DespawnOrUnsummon(1000);
                    break;
                default:
                    break;							
                }
            }
        }

    protected:
        EventMap _events;
        InstanceScript* pInstance;
        Creature* pTarget;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_risenghoulAI(creature);
    }
};

class npc_nozdormu_sylvanas : public CreatureScript
{
public:
    npc_nozdormu_sylvanas() : CreatureScript("npc_nozdormu_sylvanas") { }

    struct npc_nozdormu_sylvanasAI : public ScriptedAI
    {
        npc_nozdormu_sylvanasAI(Creature* creature) : ScriptedAI(creature), pInstance(creature->GetInstanceScript()) { }

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
                    _events.ScheduleEvent(EVENT_INTRO_SYLVANAS_1, 6000);
                    break;
                case EVENT_INTRO_SYLVANAS_1:
                    if (Creature* pSylvanas = me->GetCreature(*me, uiSylvanas))
                        pSylvanas->AI()->Talk(INTRO_SYLVANAS);
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
        uint64 uiSylvanas;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_nozdormu_sylvanasAI(creature);
    }
};

void AddSC_boss_echo_of_sylvanas()
{
    new boss_echo_of_sylvanas();
    new npc_risenghoul();
    new npc_nozdormu_sylvanas();
}