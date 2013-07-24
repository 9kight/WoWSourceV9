#include "ScriptPCH.h"
#include "blackwing_descent.h"
#include "SpellAuraEffects.h"
#include "Spell.h"

enum Spells
{
    SPELL_BERSERK                   = 26662,
    SPELL_ARCANE_STORM              = 77896,
    SPELL_RELEASE_ABERRATIONS       = 77569,
    // Red Vial
    SPELL_CONSUMING_FLAMES          = 77786,
    SPELL_SCORCHING_BLAST           = 77679,
    // Blue Vial
    SPELL_BITING_CHILL              = 77760,
    SPELL_FLASH_FREEZE              = 77699,
    // Green Vial
    SPELL_REMEDY                    = 77912,
    SPELL_DEBILITATING_SLIME_VIS    = 77602,
    SPELL_DEBILITATING_SLIME_DMG    = 77615,
    SPELL_DEBILITATING_SLIME_DMG_2  = 92910,
    SPELL_DEBILITATING_SLIME_KNK    = 77948,
    // 25%
    SPELL_RELEASE_ALL,
    SPELL_MAGMA_JETS                = 78194,
    SPELL_MAGMA_JETS_EFF            = 78095,
    SPELL_MAGMA_JETS_PERIODIC       = 93018,
    SPELL_ABSOLUTE_ZERO             = 78223,
    SPELL_ACID_NOVA                 = 78225,

    SPELL_THROW_RED                 = 77925,
    SPELL_THROW_BLUE                = 77932,
    SPELL_THROW_GREEN               = 77937,
    SPELL_SHATTER                   = 77715,
    SPELL_FLASH_FREEZE_VIS          = 77712,

    SPELL_ABSOLUTE_ZERO_CAST        = 78201,
    SPELL_ABSOLUTE_ZERO_PERIODIC    = 78206,
    SPELL_ABSOLUTE_ZERO_DMG         = 78208,
    SPELL_FIXATE                    = 78618
};

enum Entities
{
    NPC_ABERRATION                  = 41440,
    NPC_FLASH_FREEZE                = 41576,
    NPC_CAULDRON_STALKER            = 41505,
    NPC_MAGMA_JETS_CONTROLLER       = 50030,
    NPC_PRIME_SUBJECT               = 41841,
    GO_CAULDRON                     = 401904,
    NPC_MAGMA_JET                   = 41901
};

enum Events
{
    EVENT_ARCANE_STORM              = 1,
    EVENT_RELEASE_ABERRATIONS,
    EVENT_CONSUMING_FLAMES,
    EVENT_SCORCHING_BLAST,
    EVENT_BITING_CHILL,
    EVENT_FLASH_FREEZE,
    EVENT_REMEDY,
    EVENT_DEBILITATING_SLIME,
    EVENT_MAGMA_JETS,
    EVENT_ABSOLUTE_ZERO,
    EVENT_ACID_NOVA,
    EVENT_NEXT_VIAL,
    EVENT_RESUME_COMBAT
};

enum EventGroups
{
    EVENT_GROUP_RED             = 1,
    EVENT_GROUP_BLUE,
    EVENT_GROUP_GREEN
};

enum Misc
{
    MAX_ABERRATIONS             = 18,
    GOBJ_ANIM_RED               = 0,
    GOBJ_ANIM_BLUE,
    GOBJ_ANIM_GREEN,
    GOBJ_ANIM_BLACK,
    POINT_CAULDRON              = 1
};

enum Phases
{
    PHASE_NORMAL,
    PHASE_RED,
    PHASE_BLUE,
    PHASE_GREEN,
    PHASE_25
};

enum Texts
{
    EMOTE_RED_BOTTLE,
    EMOTE_GREEN_BOTTLE,
    EMOTE_BLUE_BOTTLE,
    SAY_AGGRO,
    SAY_SLAY,
    SAY_RED_PHASE,
    SAY_BLUE_PHASE,
    SAY_GREEN_PHASE,
    SAY_25,
    SAY_DEATH
};

static const Position cauldronPos = {-106.330498f, -470.160492f, 73.454094f, 0.0f};
static const Position spawn1 = {-67.947990f, -497.436676f, 74.215050f, 0.0f};
static const Position spawn2 = {-146.541443f, -461.949677f, 73.268913f, 0.0f};

class boss_maloriak : public CreatureScript
{
    public:
        boss_maloriak() : CreatureScript("boss_maloriak") {}

        struct boss_maloriakAI : public BossAI
        {
            boss_maloriakAI(Creature* creature) : BossAI(creature, DATA_MALORIAK) { }

            void Reset()
            {
                _Reset();
                bluePhase = urand(0, 1);
                aberrationsCnt = 0;
                phase = PHASE_NORMAL;
                moving = false;
                enrageTimer = 420000;
                me->SetReactState(REACT_AGGRESSIVE);
            }

            void DamageTaken(Unit* /*done_by*/, uint32 &damage)
            {
                if (me->HealthBelowPctDamaged(25, damage) && phase != PHASE_25)
                {
                    phase = PHASE_25;
                    Talk(SAY_25);
                    events.Reset();
                    events.ScheduleEvent(EVENT_ARCANE_STORM, 5000);
                    events.ScheduleEvent(EVENT_ACID_NOVA, 8000);
                    events.ScheduleEvent(EVENT_ABSOLUTE_ZERO, 10000);
                    events.ScheduleEvent(EVENT_MAGMA_JETS, 15000);
                    uint8 toSummon = MAX_ABERRATIONS - aberrationsCnt;
                    for (uint8 i = 0; i < toSummon; ++i)
                        me->SummonCreature(NPC_ABERRATION, i%2 ? spawn1 : spawn2);
                    me->SummonCreature(NPC_PRIME_SUBJECT, -144.514420f, -438.325470f, 73.322784f);
                    me->SummonCreature(NPC_PRIME_SUBJECT, -71.038322f, -432.436676f, 74.161919f);
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == NPC_ABERRATION)
                    ++aberrationsCnt;
                else if (summon->GetEntry() == NPC_FLASH_FREEZE)
                    summon->CastSpell(summon, SPELL_FLASH_FREEZE_VIS, true);
                else if (summon->GetEntry() == NPC_MAGMA_JETS_CONTROLLER)
                {
                    summon->SetOrientation(me->GetAngle(me->getVictim()));
                    summon->SetReactState(REACT_PASSIVE);
                    summon->CastSpell(summon, SPELL_MAGMA_JETS_PERIODIC, true);
                    summon->DespawnOrUnsummon(5000);
                }
                BossAI::JustSummoned(summon);
            }

            void SummonedCreatureDies(Creature* summon, Unit * /*killer*/)
            {
                if (summon->GetEntry() == NPC_FLASH_FREEZE)
                    summon->CastSpell(summon, SPELL_SHATTER, true);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_ARCANE_STORM, 10000);
                events.ScheduleEvent(EVENT_RELEASE_ABERRATIONS, 15000);
                events.ScheduleEvent(EVENT_NEXT_VIAL, 20000);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE && id == POINT_CAULDRON)
                {
                    switch(phase)
                    {
                    case PHASE_BLUE:
                        if (Creature* stalker = me->FindNearestCreature(NPC_CAULDRON_STALKER, 30.0f))
                            DoCast(stalker, SPELL_THROW_BLUE);
                        break;
                    case PHASE_RED:
                        DoCast(SPELL_THROW_RED);
                        break;
                    case PHASE_GREEN:
                        DoCast(SPELL_THROW_GREEN);
                        if (Creature* stalker = me->FindNearestCreature(NPC_CAULDRON_STALKER, 30.0f))
                        {
                            stalker->CastSpell(stalker, SPELL_DEBILITATING_SLIME_VIS, false);
                            stalker->CastSpell(stalker, SPELL_DEBILITATING_SLIME_DMG, true);
                            stalker->CastSpell(stalker, SPELL_DEBILITATING_SLIME_DMG_2, true);
                            stalker->CastSpell(stalker, SPELL_DEBILITATING_SLIME_KNK, true);
                        }
                        break;
                    }
                    moving = false;
                    events.DelayEvents(4000);
                    events.ScheduleEvent(EVENT_RESUME_COMBAT, 3000);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || moving)
                    return;

                if (enrageTimer <= diff)
                {
                    DoCast(me, SPELL_BERSERK, true);
                    enrageTimer = 420000;
                }else enrageTimer -= diff;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_ARCANE_STORM:
                        DoCast(SPELL_ARCANE_STORM);
                        events.ScheduleEvent(EVENT_ARCANE_STORM, 15000);
                        break;
                    case EVENT_RELEASE_ABERRATIONS:
                        if (aberrationsCnt < MAX_ABERRATIONS)
                        {
                            DoCast(SPELL_RELEASE_ABERRATIONS);
                            events.ScheduleEvent(EVENT_RELEASE_ABERRATIONS, 15000);
                        }
                        break;
                    case EVENT_CONSUMING_FLAMES:
                        DoCastRandom(SPELL_CONSUMING_FLAMES, 0.0f, true);
                        events.ScheduleEvent(EVENT_CONSUMING_FLAMES, 15000, EVENT_GROUP_RED);
                        break;
                    case EVENT_SCORCHING_BLAST:
                        DoCastVictim(SPELL_SCORCHING_BLAST);
                        events.ScheduleEvent(EVENT_SCORCHING_BLAST, 10000, EVENT_GROUP_RED);
                        break;
                    case EVENT_BITING_CHILL:
                        DoCastRandom(SPELL_BITING_CHILL, 0.0f, true);
                        events.ScheduleEvent(EVENT_BITING_CHILL, 15000, EVENT_GROUP_BLUE);
                        break;
                    case EVENT_FLASH_FREEZE:
                        DoCastRandom(SPELL_FLASH_FREEZE, 0.0f, true);
                        events.ScheduleEvent(EVENT_FLASH_FREEZE, 15000, EVENT_GROUP_BLUE);
                        break;
                    case EVENT_REMEDY:
                        DoCast(me, SPELL_REMEDY, true);
                        events.ScheduleEvent(EVENT_REMEDY, 15000, EVENT_GROUP_GREEN);
                        break;
                    case EVENT_NEXT_VIAL:
                        // todo: improve this part
                        if (phase == PHASE_GREEN)
                        {
                            phase = PHASE_NORMAL;
                            bluePhase = urand(0,1);
                        }

                        switch(phase)
                        {
                        case PHASE_NORMAL:
                            phase = bluePhase ? PHASE_BLUE : PHASE_RED;
                            break;
                        case PHASE_RED:
                            events.CancelEventGroup(EVENT_GROUP_RED);
                            phase = !bluePhase ? PHASE_BLUE : PHASE_GREEN;
                            break;
                        case PHASE_BLUE:
                            events.CancelEventGroup(EVENT_GROUP_BLUE);
                            phase = bluePhase ? PHASE_RED : PHASE_GREEN;
                            break;
                        case PHASE_GREEN:
                            events.CancelEventGroup(EVENT_GROUP_GREEN);
                            bluePhase = urand(0,1);
                            phase = bluePhase ? PHASE_BLUE : PHASE_RED;
                            break;
                        }

                        // schedule events
                        switch(phase)
                        {
                        case PHASE_RED:
                            Talk(EMOTE_RED_BOTTLE);
                            Talk(SAY_RED_PHASE);
                            events.ScheduleEvent(EVENT_CONSUMING_FLAMES, 10000, EVENT_GROUP_RED);
                            events.ScheduleEvent(EVENT_SCORCHING_BLAST, 20000, EVENT_GROUP_RED);
                            break;
                        case PHASE_BLUE:
                            Talk(EMOTE_BLUE_BOTTLE);
                            Talk(SAY_BLUE_PHASE);
                            events.ScheduleEvent(EVENT_BITING_CHILL, 20000, EVENT_GROUP_BLUE);
                            events.ScheduleEvent(EVENT_FLASH_FREEZE, 15000, EVENT_GROUP_BLUE);
                            break;
                        case PHASE_GREEN:
                            Talk(EMOTE_GREEN_BOTTLE);
                            Talk(SAY_GREEN_PHASE);
                            events.ScheduleEvent(EVENT_REMEDY, 20000, EVENT_GROUP_GREEN);
                            events.ScheduleEvent(EVENT_DEBILITATING_SLIME, 10000, EVENT_GROUP_GREEN);
                            break;
                        }
                        moving = true;
                        me->SetReactState(REACT_PASSIVE);
                        me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                        me->GetMotionMaster()->MovePoint(POINT_CAULDRON, cauldronPos);

                        break;
                    case EVENT_RESUME_COMBAT:
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (GameObject* go = me->FindNearestGameObject(GO_CAULDRON, 20.0f))
                        {
                            switch (phase)
                            {
                            case PHASE_BLUE: go->SendCustomAnim(GOBJ_ANIM_BLUE); break;
                            case PHASE_RED: go->SendCustomAnim(GOBJ_ANIM_RED); break;
                            case PHASE_GREEN: go->SendCustomAnim(GOBJ_ANIM_GREEN); break;
                            }
                        }
                        events.ScheduleEvent(EVENT_NEXT_VIAL, 50000);
                        if (Unit* victim = me->getVictim())
                        {
                            me->SetUInt64Value(UNIT_FIELD_TARGET, victim->GetGUID());
                            DoStartMovement(victim);
                        }
                        break;
                    case EVENT_MAGMA_JETS:
                        DoCastVictim(SPELL_MAGMA_JETS);
                        events.ScheduleEvent(EVENT_MAGMA_JETS, urand(10000, 15000));
                        break;
                    case EVENT_ABSOLUTE_ZERO:
                        DoCastRandom(SPELL_ABSOLUTE_ZERO, 0.0f, true);
                        events.ScheduleEvent(EVENT_ABSOLUTE_ZERO, urand(7000, 10000));
                        break;
                    case EVENT_ACID_NOVA:
                        DoCast(SPELL_ACID_NOVA);
                        events.ScheduleEvent(EVENT_ACID_NOVA, 20000);
                        break;
                    default:
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            uint32 aberrationsCnt;
            uint32 combatTimer;
            uint32 enrageTimer;
            uint8 phase;
            bool bluePhase;
            bool moving;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_maloriakAI(creature);
        }
};

class spell_remedy : public SpellScriptLoader
{
    public:
        spell_remedy() : SpellScriptLoader("spell_remedy") { }

        class spell_remedy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_remedy_AuraScript)

                void HandleEffectPeriodicUpdate(AuraEffect* aurEff)
            {
                uint32 baseAmt = aurEff->GetBaseAmount();
                aurEff->SetAmount(aurEff->GetAmount() + baseAmt);
            }

            void Register()
            {
                OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_remedy_AuraScript::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_remedy_AuraScript();
        }
};

class spell_magma_jets_periodic : public SpellScriptLoader
{
    public:
        spell_magma_jets_periodic() : SpellScriptLoader("spell_magma_jets_periodic") { }

        class spell_magma_jets_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_magma_jets_periodic_AuraScript)

                void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                float dist = aurEff->GetTickNumber() * 5.0f;
                Position pos;

                if (Unit* caster = GetCaster())
                {
                    caster->GetNearPosition(pos, dist, caster->GetOrientation());
                    if (Creature* summon = caster->SummonCreature(NPC_MAGMA_JET, pos, TEMPSUMMON_TIMED_DESPAWN, 20000))
                        summon->CastSpell(summon, SPELL_MAGMA_JETS_EFF, true);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_magma_jets_periodic_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_magma_jets_periodic_AuraScript();
        }
};

class npc_absolute_zero : public CreatureScript
{
    public:
        npc_absolute_zero() : CreatureScript("npc_absolute_zero") {}

        struct npc_absolute_zeroAI : public ScriptedAI
        {
            npc_absolute_zeroAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                me->SetInCombatWithZone();
                DoCast(SPELL_ABSOLUTE_ZERO_CAST);
            }

            void SpellHitTarget(Unit* /*victim*/, const SpellInfo* spell)
            {
                if (spell->Id == SPELL_ABSOLUTE_ZERO_PERIODIC)
                {
                    me->RemoveAllAuras();
                    DoCast(SPELL_ABSOLUTE_ZERO_DMG);
                    me->DespawnOrUnsummon(2000);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_absolute_zeroAI(creature);
        }
};

class npc_prime_subject : public CreatureScript
{
    public:
        npc_prime_subject() : CreatureScript("npc_prime_subject") {}

        struct npc_prime_subjectAI : public ScriptedAI
        {
            npc_prime_subjectAI(Creature * creature) : ScriptedAI(creature)  {}

            void Reset()
            {
                tauntTimer = 5000;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (tauntTimer <= diff)
                {
                    if (!me->HasAura(SPELL_FIXATE))
                        me->getVictim()->CastSpell(me, SPELL_FIXATE, true);
                    tauntTimer = 5000;
                }else tauntTimer -= diff;

                DoMeleeAttackIfReady();
            }
        private:
            uint32 tauntTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_prime_subjectAI(creature);
        }
};

void AddSC_boss_maloriak()
{
    new boss_maloriak();
    new npc_absolute_zero();
    new npc_prime_subject();
    new spell_remedy();
    new spell_magma_jets_periodic();
};
