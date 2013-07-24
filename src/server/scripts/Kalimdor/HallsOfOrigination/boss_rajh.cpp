#include "halls_of_origination.h"
#include "Spell.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "Map.h"
#include "Vehicle.h"
#include "MoveSplineInit.h"
#include "SpellAuras.h"
#include "ObjectMgr.h"
#include "Unit.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_SOLAR_WINDS_SUMMON        = 74104,
    SPELL_SOLAR_WINDS_SUMMON_2      = 74106,
    SPELL_SUMMON_SUN_ORB            = 80352,
    SPELL_BLESSING_OF_THE_SUN       = 76352,
    SPELL_SUN_STRIKE                = 73872,
    SPELL_INFERNO_LEAP              = 87650,
    SPELL_INFERNO_LEAP_VEH          = 87653,
    SPELL_INFERNO_LEAP_DMG          = 87647,
    SPELL_NO_REGEN                  = 72242,
};

enum Entities
{
    NPC_SOLAR_WINDS_DUMMY           = 39634,
    NPC_SOLAR_WINDS                 = 39635,
    NPC_ORB_OF_THE_SUN              = 40835,
    NPC_BLAZING_INFERNO             = 40927,
    NPC_SOLAR_FIRE                  = 47922,
};


enum Events
{
    EVENT_SUMMON_SUN_ORB            = 1,
    EVENT_SOLAR_WINDS,
    EVENT_SUN_STRIKE,
    EVENT_INFERNO_LEAP,
    EVENT_COMBAT_RESET,
    EVENT_SUN_ORB_JUMP
};

enum Misc
{
    POINT_CENTER                    = 1,
    PHASE_NORMAL                    = 1,
    PHASE_BLESSING                  = 2,
};

enum Quotes
{
    SAY_AGGRO,
    SAY_BLESSING,
    SAY_SLAY,
    SAY_DEATH
};

static const Position centerPos = {-319.76f, 193.39f, 343.95f, M_PI};

class boss_rajh : public CreatureScript
{
    struct boss_rajhAI : public BossAI
    {
        boss_rajhAI(Creature * creature) : BossAI(creature, DATA_RAJH)  {}

        void Reset()
        {
            _Reset();
            me->SetHealth(me->GetMaxHealth());
            me->SetReactState(REACT_AGGRESSIVE);
            events.SetPhase(PHASE_NORMAL);
            me->SetPower(POWER_ENERGY, 100);
            DoCast(SPELL_NO_REGEN);
            DespawnFires();
        }

        void DespawnFires()
        {
            std::list<Creature *> cList;
            me->GetCreatureListWithEntryInGrid(cList, NPC_SOLAR_FIRE, 200.0f);
            if(!cList.empty())
                for(std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        void SpellHit(Unit * /*caster*/, const SpellInfo *spell)
        {
            Spell * curSpell = me->GetCurrentSpell(CURRENT_GENERIC_SPELL);
            if(me->HasAura(SPELL_SUMMON_SUN_ORB) || (curSpell && (curSpell->m_spellInfo->Id == SPELL_SUMMON_SUN_ORB || curSpell->m_spellInfo->Id == SPELL_INFERNO_LEAP_VEH)))
            {
                for (uint8 i = 0; i < 3; ++i)
                {
                    if(spell->Effects[i].Effect == SPELL_EFFECT_INTERRUPT_CAST)
                    {
                        me->InterruptSpell(CURRENT_GENERIC_SPELL, false);
                        me->RemoveAurasDueToSpell(SPELL_SUMMON_SUN_ORB);
                    }
                }
            }
        }

        void JustSummoned(Creature * summon)
        {
            switch(summon->GetEntry())
            {
            case NPC_SOLAR_WINDS:
                summon->GetMotionMaster()->MoveRandom(25.0f);
                break;
            case NPC_SOLAR_WINDS_DUMMY:
                DoCast(summon, SPELL_SOLAR_WINDS_SUMMON_2, true);
                break;
            case NPC_ORB_OF_THE_SUN:
                if(Unit * target = SelectTarget(SELECT_TARGET_RANDOM))
                    me->SummonCreature(NPC_BLAZING_INFERNO, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 10000);
                //summon->GetMotionMaster()->Clear();
                //summon->GetMap()->CreatureRelocation(summon, summon->GetPositionX(), summon->GetPositionY(), summon->GetPositionZ() + 20, 0.0f);
                //summon->SetPosition(summon->GetPositionX(), summon->GetPositionY(), summon->GetPositionZ() + 20, 0.0f, true);
                events.ScheduleEvent(EVENT_SUN_ORB_JUMP, 4000);
                break;
            default:
                break;
            }
            BossAI::JustSummoned(summon);
        }

        void JustDied(Unit * )
        {
            Talk(SAY_DEATH);
            _JustDied();
            DespawnFires();
        }

        void KillerUnit(Unit * )
        {
            Talk(SAY_SLAY);
        }

        void EnterCombat(Unit * /*who*/)
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_SUN_STRIKE, urand(5000, 8000), 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_SOLAR_WINDS, urand(8000, 10000), 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_SUMMON_SUN_ORB, urand(15000, 20000), 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_INFERNO_LEAP, urand(25000, 30000), 0, PHASE_NORMAL);
            _EnterCombat();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if(type == POINT_MOTION_TYPE && id == POINT_CENTER)
            {
                Talk(SAY_BLESSING);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();
                me->SetOrientation(M_PI);
//                me->SendMovementFlagUpdate();
                DoCast(SPELL_BLESSING_OF_THE_SUN);
                events.ScheduleEvent(EVENT_COMBAT_RESET, 20000, 0, PHASE_BLESSING);
            }
        }

        void UpdateAI(uint32 diff)
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_SUMMON_SUN_ORB:
                    DoCast(SPELL_SUMMON_SUN_ORB);
                    events.ScheduleEvent(EVENT_SUMMON_SUN_ORB, urand(30000, 40000), 0, PHASE_NORMAL);
                    break;
                case EVENT_SOLAR_WINDS:
                    DoCast(SPELL_SOLAR_WINDS_SUMMON);
                    events.ScheduleEvent(EVENT_SOLAR_WINDS, urand(20000, 25000), 0, PHASE_NORMAL);
                    break;
                case EVENT_SUN_STRIKE:
                    DoCastVictim(SPELL_SUN_STRIKE);
                    events.ScheduleEvent(EVENT_SUN_STRIKE, urand(15000, 20000), 0, PHASE_NORMAL);
                    break;
                case EVENT_INFERNO_LEAP:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_INFERNO_LEAP);
                    DoCast(me, SPELL_INFERNO_LEAP_VEH, false);
                    events.ScheduleEvent(EVENT_INFERNO_LEAP, 15000, 0, PHASE_NORMAL);
                    break;
                case EVENT_COMBAT_RESET:
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.SetPhase(PHASE_NORMAL);
                    events.RescheduleEvent(EVENT_SUN_STRIKE, urand(5000, 8000), 0, PHASE_NORMAL);
                    events.RescheduleEvent(EVENT_SOLAR_WINDS, urand(8000, 10000), 0, PHASE_NORMAL);
                    events.RescheduleEvent(EVENT_SUMMON_SUN_ORB, urand(15000, 20000), 0, PHASE_NORMAL);
                    events.RescheduleEvent(EVENT_INFERNO_LEAP, urand(25000, 30000), 0, PHASE_NORMAL);
                    if(Unit * victim = me->getVictim())
                    {
                        me->SetUInt64Value(UNIT_FIELD_TARGET, victim->GetGUID());
                        DoStartMovement(victim);
                    }
                    break;
                case EVENT_SUN_ORB_JUMP:
                    if(Creature * orb = me->FindNearestCreature(NPC_ORB_OF_THE_SUN, 100.0f))
                    {
                        if(Creature * inferno = me->FindNearestCreature(NPC_BLAZING_INFERNO, 100.0f))
                        {
                            orb->GetMotionMaster()->Clear();
                            orb->GetMotionMaster()->MoveJump(inferno->GetPositionX(), inferno->GetPositionY(), inferno->GetPositionZ(), 30.0f, 30.0f);
                            orb->EnterVehicle(inferno, 0);
                        }
                    }
                    break;
                default:
                    break;
                }
            }

            if(me->GetPower(POWER_ENERGY) <= 10.0f && (events.GetPhaseMask() & (1 << PHASE_NORMAL)))
            {
                events.SetPhase(PHASE_BLESSING);
                me->SetReactState(REACT_PASSIVE);
                me->StopMoving();
                me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(POINT_CENTER, centerPos);
            }

            DoMeleeAttackIfReady();

            EnterEvadeIfOutOfCombatArea(diff);
        }
    };

public:
    boss_rajh() : CreatureScript("boss_rajh") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_rajhAI(creature);
    }
};

class npc_blazing_inferno : public CreatureScript
{
    enum
    {
        SPELL_BLAZING_INFERNO           = 76195,
        SPELL_INFERNO_LEAP              = 87647,
        NPC_RAJH                        = 39378
    };

    struct npc_blazing_infernoAI : public ScriptedAI
    {
        npc_blazing_infernoAI(Creature * creature) : ScriptedAI(creature) {}

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply)
        {
            if(apply)
            {
                if(who->GetEntry() == NPC_RAJH)
                    DoCast(SPELL_INFERNO_LEAP);
                else if (who->GetEntry() == NPC_ORB_OF_THE_SUN)
                {
                    DoCast(who, SPELL_BLAZING_INFERNO, true);
                    who->ToCreature()->DespawnOrUnsummon(500);
                }
            }
        }

    private:
    };

public:
    npc_blazing_inferno() : CreatureScript("npc_blazing_inferno") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_blazing_infernoAI(creature);
    }
};

void AddSC_boss_rajh()
{
    new boss_rajh();
    new npc_blazing_inferno();
};

/*class npc_solar_winds : public CreatureScript
{
    enum
    {
        POINT_THERE             = 1,
        POINT_HOME              = 2
    };

    struct npc_solar_windsAI : public ScriptedAI
    {
        npc_solar_windsAI(Creature * creature) : ScriptedAI(creature)
        {
        }

        void Reset()
        {
            me->GetPosition(&homePos);
            me->SetReactState(REACT_PASSIVE);
        }

        void IsSummonedBy(Unit * )
        {
            Position pos;
            me->GetRandomNearPosition(pos, urand(20000, 25000));
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if(type == POINT_MOTION_TYPE)
            {
                if (id == POINT_THERE)
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MovePoint(POINT_HOME, homePos);
                }
                else if (id == POINT_HOME)
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()
                }
            }
        }

        void JustSummoned(Creature * summon)
        {
        }

        void UpdateAI(const uint32 diff)
        {
        }

    private:
        bool there;
        Position homePos;
    };

public:
    npc_solar_winds() : CreatureScript("npc_solar_winds") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_solar_windsAI(creature);
    }
};*/
