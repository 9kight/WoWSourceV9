/* ScriptData
SDName: boss_echo_of_baine.cpp
SD%Complete: 90%
DCategory: endtime
EndScriptData */

// Need, correct the timers to cast for boss.
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
    INTRO_JAINA							= 0,
    SAY_AGGRO                           = 1, // What dark horrors have you brought in this place? By my ancestors honor - I shall take you to task!
    SAY_FROST_BLADE                     = 2, // There will be no escape!
    SAY_FROST_BLADE_2                   = 3, // There will be no escape!
    SAY_FROST_BLADE_3                   = 4, // ENOUGH! I WILL NO LONGER BE CONTAINED!
    SAY_KILL                            = 5, // This is the price you pay.
    SAY_KILL_2                          = 6, // A just punishment!
    SAY_KILL_3							= 7, // Suffer for your arrogance!
    SAY_DEATH                           = 8, // Where... is this place? What... have I done? Forgive me, my father... 

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
    EVENT_INTRO_JAINA_1			= 4,

    EVENT_FLARECORE 			= 5,
    EVENT_FROSTBOLD_VOLLEY		= 6,

    EVENT_PYROBLAST				= 7,

};

enum Spells
{
    SPELL_FROZEN_PRISON            = 47854,
    SPELL_BLINK   				   = 101812,
    SPELL_FLARECORE		   		   = 101927,
    SPELL_FROST_BLADE	           = 101339,
    SPELL_FROSTBOLD_VOLLEY         = 101810,
    SPELL_PYROBLAST		           = 101809,

};

enum Misc
{
    DATA_FRAGMENT = 12,
};

class Fragmentrest
{
public:
    Fragmentrest() { }

    bool operator()(GameObject* go)
    {
        switch (go->GetEntry())
        {
        case JAINAS_STAFF:
            go->GetGUID();
            go->ResetDoorOrButton();
            break;
        default:
            break;
        }

        return false;
    }
};

class boss_echo_of_jaina : public CreatureScript
{
public:
    boss_echo_of_jaina() : CreatureScript("boss_echo_of_jaina") { }

    struct boss_echo_of_jainaAI : public BossAI
    {
        boss_echo_of_jainaAI(Creature* pCreature) : BossAI(pCreature, DATA_ECHO_OF_JAINA)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }



        uint64 FragmentsGUIDs[DATA_FRAGMENT];
        uint8 _phase;
        uint32 phase;
        void Reset()
        {
            _Reset();
            Fragmentrest reset;
            Trinity::GameObjectWorker<Fragmentrest> worker(me, reset);
            StartEvent(CheckFragments());
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
            events.ScheduleEvent(EVENT_FLARECORE, 4500, 0, ON_COMBAT);
            events.ScheduleEvent(EVENT_FROSTBOLD_VOLLEY, 3000, 0, ON_COMBAT);
            events.ScheduleEvent(EVENT_PYROBLAST, 3000, 0, ON_COMBAT);
        }

        void JustDied(Unit* killer)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->SetBossState(DATA_ECHO_OF_JAINA, DONE);
            Talk(SAY_DEATH);
            _JustDied();
        }

        void JustReachedHome()
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _JustReachedHome();
            instance->SetBossState(DATA_ECHO_OF_JAINA, FAIL);

            Fragmentrest reset;
            Trinity::GameObjectWorker<Fragmentrest> worker(me, reset);
            me->VisitNearbyGridObject(333.0f, worker);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
        {
            DoCast(me, SPELL_BLINK);
        }

        bool CheckFragments(bool start_event = false)
        {
            if (!instance)
                return false;

            FragmentsGUIDs[12] = instance->GetData64(DATA_JAINAS_STAFF);

            GameObject* Fragments[DATA_FRAGMENT];

            for (uint8 i = 0; i < DATA_FRAGMENT; ++i)
            {
                Fragments[i] = instance->instance->GetGameObject(FragmentsGUIDs[i]);
                if (!Fragments[i])
                    return false;
                if (Fragments[i]->GetGoState() != GO_STATE_ACTIVE)
                    return false;
            }
            if (start_event)
                StartEvent(true);
            return true;
        }

        void StartEvent(bool start)
        {
            if (start)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetUInt32Value(UNIT_FIELD_DISPLAYID, 38802);
                me->setFaction(16);
                if (me->HasAura(SPELL_FROZEN_PRISON))
                    me->RemoveAurasDueToSpell(SPELL_FROZEN_PRISON);
            }
            else
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11686);
                me->setFaction(35);		
                DoCast(me, SPELL_FROZEN_PRISON, false);
            }
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
                case EVENT_FLARECORE:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoCast(pTarget, SPELL_FLARECORE);
                    }
                    events.ScheduleEvent(EVENT_FLARECORE, 40000, 0, ON_COMBAT);
                    break;
                    break;
                case EVENT_FROSTBOLD_VOLLEY:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoCast(pTarget, SPELL_FROSTBOLD_VOLLEY);
                    }
                    events.ScheduleEvent(EVENT_FROSTBOLD_VOLLEY, 25000, 0, ON_COMBAT);
                    break;
                case EVENT_PYROBLAST:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoCast(pTarget, SPELL_PYROBLAST);
                    }
                    events.ScheduleEvent(EVENT_PYROBLAST, 10000, 0, ON_COMBAT);
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
        return new boss_echo_of_jainaAI(pCreature);
    }

};

class jainasfragments : public GameObjectScript
{
public:
    jainasfragments() : GameObjectScript("jainasfragments") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        InstanceScript* instance = go->GetInstanceScript();

        Creature* uiJaina = Unit::GetCreature(*go, instance ? instance->GetData64(DATA_ECHO_OF_JAINA) : 0);
        if (uiJaina && uiJaina->isAlive())
        {
            // maybe these are hacks :(
            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            go->SetGoState(GO_STATE_ACTIVE);

            CAST_AI(boss_echo_of_jaina::boss_echo_of_jainaAI, uiJaina->AI())->CheckFragments(true);
        }
        return true;
    }

};

class npc_nozdormu_jaina : public CreatureScript
{
public:
    npc_nozdormu_jaina() : CreatureScript("npc_nozdormu_jaina") { }

    struct npc_nozdormu_jainaAI : public ScriptedAI
    {
        npc_nozdormu_jainaAI(Creature* creature) : ScriptedAI(creature), pInstance(creature->GetInstanceScript()) { }

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
                    _events.ScheduleEvent(EVENT_INTRO_JAINA_1, 6000);
                    break;
                case EVENT_INTRO_JAINA_1:
                    if (Creature* pJaina = me->GetCreature(*me, uiJaina))
                        pJaina->AI()->Talk(INTRO_JAINA);
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
        uint64 uiJaina;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_nozdormu_jainaAI(creature);
    }
};

void AddSC_boss_echo_of_jaina()
{
    new boss_echo_of_jaina();
    new jainasfragments();
    new npc_nozdormu_jaina();
}