#include "bastion_of_twilight.h"
#include "ScriptMgr.h"
#include "MoveSplineInit.h"
#include "Spell.h"
#include "SpellScript.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"
#include "Player.h"
#include "MoveSplineInit.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Cell.h"
#include "CellImpl.h"
#include "ObjectMgr.h"

enum Spells
{
    SPELL_TWILIGHT_SHIFT                = 85556,
    SPELL_TWILIGHT_SHIFT_PLAYER         = 86202,
    SPELL_SHARE_HEALTH_VALIONA          = 90345,
    SPELL_SHARE_HEALTH_THERALION        = 90346,
    SPELL_SPEED_BURST                   = 86077,
    // Valiona
    SPELL_BLACKOUT                      = 86788,
    SPELL_DEEP_BREATH                   = 86059, // Script Eff
    SPELL_CONVECTIVE_FLAMES_SUMMON      = 86832, // Moving npc
    SPELL_DEVOURING_FLAMES              = 86840,
    SPELL_TWILIGHT_METEORITE            = 86013,
    SPELL_TWILIGHT_METEORITE_MARKER     = 88518,
    SPELL_TWILIGHT_FLAMES               = 86194,
    // Theralion
    SPELL_DAZZLING_DESTRUCTION_SUMMON   = 86380,
    SPELL_DAZZLING_DESTRUCTION_DUMMY    = 86408, // Targets Stalker - not triggered
    SPELL_DAZZLING_DESTRUCTION_MISSILE  = 86386,
    SPELL_ENGULFING_MAGIC               = 86607,
    SPELL_FABULOUS_FLAMES               = 86497, // Check Twilight Shift
    SPELL_TWILIGHT_BLAST                = 86369,
};

enum Entities
{
    NPC_VALIONA_TRIGGER         = 46147,
    NPC_DAZZLING_DESTRUCTION    = 46374,
    NPC_COLLAPSING_PORTAL       = 46301
};

enum Misc
{
    POINT_BREATH,
    POINT_BREATH_TARGET,
    POINT_AIR_PHASE,

    EVENT_GROUP_GROUND          = 1,
    EVENT_GROUP_AIR,

    ACTION_THERALION_TAKEOFF    = 1,
    ACTION_THERALION_LAND
};

enum BreathPos
{
    BREATH_POS_LEFT,
    BREATH_POS_MID,
    BREATH_POS_RIGHT,
    BREATH_POS_MAX
};

struct BreathBoundary
{
    float xMin;
    float xMax;
};

static const BreathBoundary BREATH_BOUNDARIES[BREATH_POS_MAX] = 
{
    {-795.725464f, -754.973999f},
    {-745.089172f, -736.978577f},
    {-728.798035f, -685.444824f}
};

static const Position VALIONA_W[BREATH_POS_MAX] = 
{
    {-759.226990f, -603.424011f, 851.034973f, 4.747290f}, // left
    {-740.937988f, -601.679016f, 851.031982f, 4.747290f},
    {-725.369995f, -600.206970f, 850.841980f, 4.747290f}
};

static const Position VALIONA_E[BREATH_POS_MAX] = 
{
    {-757.414978f, -767.221008f, 849.921997f, 4.729840f}, // right
    {-740.481018f, -770.554016f, 851.146973f, 4.729840f},
    {-724.299988f, -769.867981f, 850.046997f, 4.729840f}
};

static const Position FLIGHT_POS = {-740.804016f, -683.642029f, 858.656006f, 0.0f};

class boss_valiona : public CreatureScript
{
    enum
    {
        EVENT_BLACKOUT              = 1,
        EVENT_DEVOURING_FLAMES,
        // Flying
        EVENT_TWILIGHT_METEORITE,
        EVENT_DEEP_BREATH,
        EVENT_BREATH_PREPARE,
        EVENT_TWILIGHT_FLAMES,
        EVENT_AIR_PHASE,
        EVENT_AIR_PHASE_END,

        SAY_INTRO_1                 = 0,
        SAY_INTRO_2,
        SAY_SLAY,
        SAY_DEATH,
        SAY_BREATH,
        EMOTE_BREATH,
        SAY_BLACKOUT,
        EMOTE_BLACKOUT
    };

    struct boss_valionaAI : public BossAI
    {
        boss_valionaAI(Creature * creature) : BossAI(creature, BOSS_VALIONA) {}

        void Reset()
        {
            breathCnt = 0;
            nextBreath = BREATH_POS_LEFT;
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->SetCanFly(false);
            instance->SetData(DATA_DOUBLE_DRAGON, DATA_RESET);
            me->SetSpeed(MOVE_FLIGHT, 2.25f, true);
            _Reset();
        }

        void EnterCombat(Unit * /*who*/)
        {
            events.ScheduleEvent(EVENT_AIR_PHASE, 90000);
            events.ScheduleEvent(EVENT_DEVOURING_FLAMES, 25000, EVENT_GROUP_GROUND);
            events.ScheduleEvent(EVENT_BLACKOUT, 10000, EVENT_GROUP_GROUND);
            berserkTimer = 600000;
            DoCast(SPELL_SHARE_HEALTH_VALIONA);
            _EnterCombat();
        }

        void JustDied(Unit * /*killer*/)
        {
            Talk(SAY_DEATH);
            me->GetMotionMaster()->MoveFall(me->GetMap()->GetHeight(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), true, 30.0f));
            _JustDied();
        }

        void KilledUnit(Unit * victim)
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void SpellHit(Unit * caster, const SpellInfo * spell)
        {
            if (spell->Id == SPELL_SHARE_HEALTH_THERALION && !me->isInCombat())
                if (Unit * victim = caster->getVictim())
                    AttackStart(victim);
        }

        void EnterEvadeMode()
        {
            if (Creature * theralion = me->GetCreature(*me, instance->GetData64(BOSS_THERALION)))
                if (Unit * victim = theralion->getVictim())
                    AttackStart(victim);
            BossAI::EnterEvadeMode();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;
            if (id == POINT_BREATH)
            {
                events.ScheduleEvent(EVENT_DEEP_BREATH, 3000, EVENT_GROUP_AIR);
                Movement::MoveSplineInit init(me);
                init.SetFacing(breathCnt%2 ? 1.646989f : 4.723450f);
                Talk(EMOTE_BREATH);
            }
            else if (id == POINT_BREATH_TARGET/* && breathCnt < BREATH_POS_MAX*/)
            {
                me->RemoveAurasDueToSpell(SPELL_SPEED_BURST);
                me->SetSpeed(MOVE_FLIGHT, 2.25f, true);
                events.CancelEvent(EVENT_TWILIGHT_FLAMES);
                events.ScheduleEvent(EVENT_BREATH_PREPARE, 3000, EVENT_GROUP_AIR);
                ++breathCnt;
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (berserkTimer)
            {
                if (berserkTimer <= diff)
                {
                    if (Creature * theralion = me->GetCreature(*me, instance->GetData64(BOSS_THERALION)))
                        theralion->CastSpell(theralion, SPELL_BERSERK, true);
                    DoCast(me, SPELL_BERSERK, true);
                    berserkTimer = 0;
                }else berserkTimer -= diff;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_BLACKOUT:
                        Talk(SAY_BLACKOUT);
                        Talk(EMOTE_BLACKOUT);
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_BLACKOUT, true);
                        events.ScheduleEvent(EVENT_BLACKOUT, urand(40000, 45000), EVENT_GROUP_GROUND);
                        break;
                    case EVENT_DEVOURING_FLAMES:
                        DoCast(me, SPELL_CONVECTIVE_FLAMES_SUMMON, true);
                        DoCast(me, SPELL_DEVOURING_FLAMES);
                        events.ScheduleEvent(EVENT_DEVOURING_FLAMES, 40000, EVENT_GROUP_GROUND);
                        break;
                    case EVENT_TWILIGHT_METEORITE:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        {
                            me->SetUInt64Value(UNIT_FIELD_TARGET, target->GetGUID());
                            DoCast(target, SPELL_TWILIGHT_METEORITE_MARKER, true);
                            DoCast(target, SPELL_TWILIGHT_METEORITE);
                        }
                        events.ScheduleEvent(EVENT_TWILIGHT_METEORITE, urand(10000, 12000), EVENT_GROUP_AIR);
                        break;
                    case EVENT_AIR_PHASE:
                        breathCnt = 0;
                        me->SetUnitMovementFlags(MOVEMENTFLAG_DISABLE_GRAVITY);
                        me->SetCanFly(true);
                        me->SetReactState(REACT_PASSIVE);
                        me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                        me->GetMotionMaster()->MovePoint(POINT_AIR_PHASE, FLIGHT_POS);

                        events.CancelEventGroup(EVENT_GROUP_GROUND);
                        events.ScheduleEvent(EVENT_AIR_PHASE_END, 90000);
                        events.ScheduleEvent(EVENT_BREATH_PREPARE, 42000, EVENT_GROUP_AIR);
                        events.ScheduleEvent(EVENT_TWILIGHT_METEORITE, urand(5000, 10000), EVENT_GROUP_AIR);
                        break;
                    case EVENT_AIR_PHASE_END:
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
                        me->SetCanFly(false); // TODO: landing animation
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (Unit * victim = me->getVictim())
                        {
                            DoStartMovement(victim);
                            me->SetUInt64Value(UNIT_FIELD_TARGET, victim->GetGUID());
                        }

                        events.CancelEventGroup(EVENT_GROUP_AIR);
                        events.ScheduleEvent(EVENT_AIR_PHASE, 90000);
                        events.ScheduleEvent(EVENT_DEVOURING_FLAMES, 25000, EVENT_GROUP_GROUND);
                        events.ScheduleEvent(EVENT_BLACKOUT, 10000, EVENT_GROUP_GROUND);
                        break;
                    case EVENT_BREATH_PREPARE:
                        if (!breathCnt)
                        {
                            Talk(SAY_BREATH);
                            me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                            events.CancelEvent(EVENT_TWILIGHT_METEORITE);
                            Position pos = {-740.804016f, -683.642029f, 832.0f, 0.0f};
                            me->MovePosition(pos, 30.0f * (float)rand_norm(), (float)rand_norm() * static_cast<float>(2 * M_PI));
                            me->SummonCreature(NPC_COLLAPSING_PORTAL, pos, TEMPSUMMON_TIMED_DESPAWN, 60000);
                        }
                        if (breathCnt < BREATH_POS_MAX)
                        {
                            nextBreath = (BreathPos)urand(BREATH_POS_LEFT, BREATH_POS_RIGHT);
                            me->GetMotionMaster()->MovePoint(POINT_BREATH, breathCnt%2 ? VALIONA_E[nextBreath] : VALIONA_W[nextBreath]);
                        }
                        break;
                    case EVENT_DEEP_BREATH:
                        DoCast(me, SPELL_SPEED_BURST, true);
                        me->SetSpeed(MOVE_FLIGHT, 4.5f, true);
                        me->GetMotionMaster()->MovePoint(POINT_BREATH_TARGET, breathCnt%2 ? VALIONA_W[nextBreath] : VALIONA_E[nextBreath]);
                        events.ScheduleEvent(EVENT_TWILIGHT_FLAMES, 0, EVENT_GROUP_AIR);
                        break;
                    case EVENT_TWILIGHT_FLAMES:
                        {
                            std::list<Creature*> cList;
                            me->GetCreatureListWithEntryInGrid(cList, NPC_VALIONA_TRIGGER, 30.0f);
                            for(std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                                if ((*itr)->GetPositionX() > BREATH_BOUNDARIES[nextBreath].xMin && (*itr)->GetPositionX() < BREATH_BOUNDARIES[nextBreath].xMax && !(*itr)->HasAura(SPELL_TWILIGHT_FLAMES))
                                    (*itr)->CastSpell(*itr, SPELL_TWILIGHT_FLAMES, true);
                            events.ScheduleEvent(EVENT_TWILIGHT_FLAMES, 500, EVENT_GROUP_AIR);
                        }
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        uint8 breathCnt; // West(0), East(1), West(2)...
        BreathPos nextBreath;
        uint32 berserkTimer;
    };

public:
    boss_valiona() : CreatureScript("boss_valiona") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_valionaAI(creature);
    }
};

class boss_theralion : public CreatureScript
{
    enum
    {
        EVENT_ENGULFING_MAGIC       = 1,
        EVENT_FABULOUS_FLAMES,
        // Flying
        EVENT_DAZZLING_DESTRUCTION,
        EVENT_TWILIGHT_BLAST,
        EVENT_AIR_PHASE,
        EVENT_AIR_PHASE_END,

        SAY_INTRO_1                 = 0,
        SAY_INTRO_2,
        SAY_ENGULFING_MAGIC,
        EMOTE_ENGULFING_MAGIC,
        SAY_DEATH,
        SAY_DAZZLING_DESTRUCTION,
        EMOTE_DAZZLING_DESTRUCTION,
        SAY_SLAY
    };

    struct boss_theralionAI : public ScriptedAI
    {
        boss_theralionAI(Creature * creature) : ScriptedAI(creature), summons(me) {}

        void Reset()
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->SetCanFly(false);
            me->SetSpeed(MOVE_FLIGHT, 2.25f, true);
            destructionCnt = 0;
            events.Reset();
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoZoneInCombat();
            DoCast(SPELL_SHARE_HEALTH_THERALION);
            events.ScheduleEvent(EVENT_AIR_PHASE, 0);
        }

        void JustDied(Unit * /*killer*/)
        {
            Talk(SAY_DEATH);
        }

        void KilledUnit(Unit * /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void SpellHitTarget(Unit * victim, const SpellInfo * spell)
        {
            if (spell->Id == SPELL_DAZZLING_DESTRUCTION_DUMMY)
                DoCast(victim, SPELL_DAZZLING_DESTRUCTION_MISSILE, true);
        }

        void SpellHit(Unit * caster, const SpellInfo * spell)
        {
            if (spell->Id == SPELL_SHARE_HEALTH_VALIONA && !me->isInCombat())
                if (Unit * victim = caster->getVictim())
                    AttackStart(victim);
        }

        void EnterEvadeMode()
        {
            if (InstanceScript * instance = me->GetInstanceScript())
                if (Creature * valiona = me->GetCreature(*me, instance->GetData64(BOSS_VALIONA)))
                    if (Unit * victim = valiona->getVictim())
                        AttackStart(victim);
            ScriptedAI::EnterEvadeMode();
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_AIR_PHASE:
                        destructionCnt = 0;
                        me->SetUnitMovementFlags(MOVEMENTFLAG_DISABLE_GRAVITY);
                        me->SetCanFly(true);
                        me->SetReactState(REACT_PASSIVE);
                        me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                        me->GetMotionMaster()->MovePoint(POINT_AIR_PHASE, FLIGHT_POS);
                        events.CancelEventGroup(EVENT_GROUP_GROUND);
                        events.ScheduleEvent(EVENT_AIR_PHASE_END, 90000);
                        events.ScheduleEvent(EVENT_DAZZLING_DESTRUCTION, urand(50000, 60000));
                        events.ScheduleEvent(EVENT_TWILIGHT_BLAST, urand(8000, 10000));
                        break;
                    case EVENT_AIR_PHASE_END:
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
                        me->SetCanFly(false); // TODO: landing animation
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (Unit * victim = me->getVictim())
                        {
                            DoStartMovement(victim);
                            me->SetUInt64Value(UNIT_FIELD_TARGET, victim->GetGUID());
                        }
                        events.CancelEventGroup(EVENT_GROUP_AIR);
                        events.ScheduleEvent(EVENT_AIR_PHASE, 90000);
                        events.ScheduleEvent(EVENT_ENGULFING_MAGIC, urand(8000, 10000), EVENT_GROUP_GROUND);
                        events.ScheduleEvent(EVENT_FABULOUS_FLAMES, urand(10000, 12000), EVENT_GROUP_GROUND);
                        break;
                    case EVENT_ENGULFING_MAGIC:
                        Talk(SAY_ENGULFING_MAGIC);
                        Talk(EMOTE_ENGULFING_MAGIC);
                        DoCast(me, SPELL_ENGULFING_MAGIC, true);
                        events.ScheduleEvent(EVENT_ENGULFING_MAGIC, urand(15000, 18000), EVENT_GROUP_GROUND);
                        break;
                    case EVENT_FABULOUS_FLAMES:
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_TWILIGHT_SHIFT_PLAYER), SPELL_FABULOUS_FLAMES);
                        events.ScheduleEvent(EVENT_FABULOUS_FLAMES, urand(8000, 10000), EVENT_GROUP_GROUND);
                        break;
                    case EVENT_DAZZLING_DESTRUCTION:
                        summons.DespawnEntry(NPC_DAZZLING_DESTRUCTION);
                        if (!destructionCnt)
                        {
                            Talk(SAY_DAZZLING_DESTRUCTION);
                            Position pos = {-740.804016f, -683.642029f, 832.0f, 0.0f};
                            me->MovePosition(pos, 30.0f * (float)rand_norm(), (float)rand_norm() * static_cast<float>(2 * M_PI));
                            me->SummonCreature(NPC_COLLAPSING_PORTAL, pos, TEMPSUMMON_TIMED_DESPAWN, 60000);
                        }
                        if (destructionCnt < 3)
                        {
                            Talk(EMOTE_DAZZLING_DESTRUCTION);
                            DoCast(me, SPELL_DAZZLING_DESTRUCTION_SUMMON, true);
                            DoCast(me, SPELL_DAZZLING_DESTRUCTION_DUMMY);
                            events.ScheduleEvent(EVENT_DAZZLING_DESTRUCTION, 7000, EVENT_GROUP_AIR);
                            ++destructionCnt;
                        }
                        break;
                    case EVENT_TWILIGHT_BLAST:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            me->SetUInt64Value(UNIT_FIELD_TARGET, target->GetGUID());
                            DoCast(target, SPELL_TWILIGHT_BLAST);
                        }
                        events.ScheduleEvent(EVENT_TWILIGHT_BLAST, urand(2000, 4000), EVENT_GROUP_AIR);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
        uint8 destructionCnt;
        SummonList summons;
    };

public:
    boss_theralion() : CreatureScript("boss_theralion") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_theralionAI(creature);
    }
};

class npc_twilight_fiend : public CreatureScript
{
    enum
    {
        SPELL_UNSTABLE_TWILIGHT_DUMMY       = 86301,
        SPELL_UNSTABLE_TWILIGHT_DMG         = 86305
    };

    struct npc_twilight_fiendAI : public ScriptedAI
    {
        npc_twilight_fiendAI(Creature * creature) : ScriptedAI(creature) {}

        void Reset()
        {
            me->GetMotionMaster()->MoveRandom(10.0f);
            me->SetReactState(REACT_PASSIVE);
        }

        void SpellHitTarget(Unit * /*victim*/, const SpellInfo * spell)
        {
            if (spell->Id == SPELL_UNSTABLE_TWILIGHT_DUMMY)
                DoCast(me, SPELL_UNSTABLE_TWILIGHT_DMG, true);
        }

        void JustDied(Unit * /*killer*/)
        {
            if (InstanceScript * instance = me->GetInstanceScript())
                instance->SetData(DATA_DOUBLE_DRAGON, DATA_ACCUMULATE);
        }

        void UpdateAI(uint32 /*diff*/)
        {
        }
    };

public:
    npc_twilight_fiend() : CreatureScript("npc_twilight_fiend") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_twilight_fiendAI(creature);
    }
};

class spell_devouring_flames : public SpellScriptLoader
{
    class spell_devouring_flames_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_devouring_flames_SpellScript)

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit * target = GetHitUnit();
            Unit * caster = GetCaster();
            if (!target || !caster)
                return;

            float dist = 1.0f - caster->GetDistance(target) / 100;
            SetHitDamage(GetHitDamage() * dist);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_devouring_flames_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };
public:
    spell_devouring_flames() : SpellScriptLoader("spell_devouring_flames") {}

    SpellScript* GetSpellScript() const
    {
        return new spell_devouring_flames_SpellScript();
    }
};

void AddSC_boss_valiona_theralion()
{
    new boss_valiona();
    new boss_theralion();
    new npc_twilight_fiend();
    new spell_devouring_flames();
};