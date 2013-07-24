#include "blackwing_descent.h"
#include "ScriptPCH.h"

/*
TODO:
- Add Encounter Frames
*/

enum Spells
{
    SPELL_POWERED_DOWN              = 82265, // transform
    SPELL_SHUTTING_DOWN             = 78746, // triggers inactive
    SPELL_INACTIVE                  = 78726,
    SPELL_ACTIVATED                 = 78740,
    SPELL_ENERGY_DRAIN              = 78725, // -100% regen
    SPELL_RECHARGE_ARCANOTRON       = 78699, // Beams
    SPELL_RECHARGE_ELECTRON         = 78697,
    SPELL_RECHARGE_MAGMATRON        = 78698,
    SPELL_RECHARGE_TOXITRON         = 78700,
    SPELL_POWER_CONVERSION          = 79729, // Arcanotron Shield
    SPELL_UNSTABLE_SHIELD           = 79900, // Electron Shield
    SPELL_BARRIER                   = 79582, // Magmatron Shield
    SPELL_POISON_SHELL              = 79835, // Toxitron Shield

    // Arcantron
    SPELL_POWER_GENERATOR           = 79626,
    SPELL_ARCANE_ANNIHILATOR        = 79710,
    SPELL_OVERCHARGED_GENERATOR     = 91857,

    // Electron
    SPELL_LIGHTNING_CONDUCTOR       = 79888,
    SPELL_ELECTRICAL_DISCHARGE      = 79879,
    SPELL_SHADOW_INFUSION           = 92048,

    // Magmatron
    SPELL_INCINERATION              = 79023,
    SPELL_ACQUIRING_TARGET          = 79501,
    SPELL_ENCASING_SHADOWS          = 92023,
    SPELL_BACKDRAFT                 = 79617,

    // Toxitron
    SPELL_CHEMICAL_BOMB             = 80157,
    SPELL_POISON_PROTOCOL           = 80053,
    SPELL_FIXATE                    = 80094,
    SPELL_CHEMICAL_CLOUD            = 80162,

    // Nefarius
    SPELL_GRIP_OF_DEATH             = 91849,

    // Power generator
    SPELL_GROW_STACKER              = 91861,
    SPELL_ARCANE_BLOWBACK           = 91879,
    SPELL_GROW                      = 91860
};

enum Texts
{
    EMOTE_SHIELD                = 0,
    SAY_ARCANOTRON_ACTIVATE     = 0,
    SAY_ELECTRON_ACTIVATE,
    SAY_MAGMATRON_ACTIVATE,
    SAY_TOXITRON_ACTIVATE,
    SAY_ARCANOTRON_SHIELD,
    SAY_ELECTRON_SHIELD,
    SAY_MAGMATRON_SHIELD,
    SAY_TOXITRON_SHIELD,
    SAY_MAGMATRON_FLAMETHROWER,
    SAY_AGGRO,
    SAY_DEATH,
    SAY_NEF_ARCANOTRON          = 0,
    SAY_NEF_ELECTRON,
    SAY_NEF_MAGMATRON,
    SAY_NEF_TOXITRON,
    SAY_NEF_AGGRO,
    SAY_NEF_DEATH
};

enum Actions
{
    ACTION_COMBAT,
    ACTION_DEATH,
    ACTION_GRIP,
    ACTION_RESET_EVENTS
};

enum Events
{
    // Omnotron
    EVENT_BEAM_NEXT         = 1,
    EVENT_PLAYER_CHECK,
    EVENT_RESET,

    // Arcanotron
    EVENT_GENERATOR,
    EVENT_ANNIHILATOR,

    // Electron
    EVENT_CONDUCTOR,
    EVENT_DISCHARGE,

    // Magmatron
    EVENT_INCINERATION,
    EVENT_ACQUIRING_TARGET,
    EVENT_TAUNT_UNAPPLY,

    // Toxitron
    EVENT_CHEMICAL_BOMB,
    EVENT_POISON_PROTOCOL,

    // Nefarius
    EVENT_DEATH,
    EVENT_INTRO,
    EVENT_GRIP,
};

enum Misc
{
    EMOTE_CONDUCTOR         = 1,
    EMOTE_FLAMETHROWER      = 1
};

// 67236 on bots, invis detection

struct Tron
{
    uint8 data;
    uint32 beamId;
    uint32 shieldId;
    uint8 activation;
    uint8 textId;
};

static const Tron bots[4] =
{
    {DATA_ARCANOTRON_GUID, SPELL_RECHARGE_ARCANOTRON, SPELL_POWER_CONVERSION, SAY_ARCANOTRON_ACTIVATE, SAY_ARCANOTRON_SHIELD},
    {DATA_ELECTRON_GUID, SPELL_RECHARGE_ELECTRON, SPELL_UNSTABLE_SHIELD, SAY_ELECTRON_ACTIVATE, SAY_ELECTRON_SHIELD},
    {DATA_MAGMATRON_GUID, SPELL_RECHARGE_MAGMATRON, SPELL_BARRIER, SAY_MAGMATRON_ACTIVATE, SAY_MAGMATRON_SHIELD},
    {DATA_TOXITRON_GUID, SPELL_RECHARGE_TOXITRON, SPELL_POISON_SHELL, SAY_TOXITRON_ACTIVATE, SAY_TOXITRON_SHIELD},
};

// Generic AI for bots

struct generic_botAI : public BossAI
{
    generic_botAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId) 
    {
        me->setPowerType(POWER_ENERGY);    
    }

    void OmnotronTalk(uint8 ID)
    {
        if (Creature* omnotron = me->GetCreature(*me, instance->GetData64(DATA_OMNOTRON_GUID)))
            omnotron->AI()->Talk(ID);
    }

    void Reset()
    {
        _Reset();
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_31); // from sniffs
        me->SetHealth(me->GetMaxHealth()); // health regen is disabled
        me->SetReactState(REACT_PASSIVE);
        me->CastSpell(me, SPELL_INACTIVE, true);
        me->CastSpell(me, SPELL_POWERED_DOWN, true);
        me->CastSpell(me, SPELL_ENERGY_DRAIN, true);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void JustReachedHome()
    {
        _JustReachedHome();
    }

    void JustDied(Unit* /*killer*/)
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_31);
    }

    void EnterEvadeMode()
    {
        _EnterEvadeMode();
        me->RemoveAllAuras();
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void DamageTaken(Unit* attacker, uint32 &damage)
    {
        if (attacker == me)
            return;

        if (damage >= me->GetHealth())
            if (Creature* omnotron = me->GetCreature(*me, instance->GetData64(DATA_OMNOTRON_GUID)))
                omnotron->AI()->DoAction(ACTION_DEATH);
    }

    void JustSummoned(Creature* summon)
    {
        BossAI::JustSummoned(summon);

        if (summon->GetEntry() == NPC_POWER_GENERATOR)
            summon->DespawnOrUnsummon(30000);
    }

    void EnterCombat(Unit* who)
    {
        if (Creature* omnotron = me->GetCreature(*me, instance->GetData64(DATA_OMNOTRON_GUID)))
            omnotron->AI()->DoAction(ACTION_COMBAT);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        DoCast(SPELL_ACTIVATED);
        DoCast(SPELL_ENERGY_DRAIN);
    }
};

// Controller
class boss_omnotron : public CreatureScript
{
    public:
        boss_omnotron() : CreatureScript("boss_omnotron") { }

        struct boss_omnotronAI : public BossAI
        {
            boss_omnotronAI(Creature* creature) : BossAI(creature, DATA_OMNOTRON_DEFENSE_SYSTEM) { }

            void Reset()
            {
                _Reset();
                oldBot = 0;
                currentBot = 0;
                nextBot = 0;
                cur = 0;
                for (uint8 i = 0; i < 4; ++i)
                    botSequenz[i] = 0;
                target = NULL;
                first = true;
                me->CombatStop(true);

                InitBots();
            }

            void EnterEvadeMode()
            {
                _EnterEvadeMode();
            }

            void InitBots()
            {
                for (uint8 i = 0; i < 4; ++i)
                {
                    botSequenz[i] = i;
                    if (Creature* tron = Creature::GetCreature(*me, instance->GetData64(bots[i].data)))
                        tron->AI()->Reset();
                }

                srand(time(NULL));
                std::random_shuffle(botSequenz, botSequenz + 3);

                currentBot = botSequenz[cur];

                if (Creature* tron = Creature::GetCreature(*me, instance->GetData64(bots[currentBot].data)))
                {
                    // Enable and make us follow waypoints
                    tron->RemoveAllAuras();
                    tron->SetReactState(REACT_AGGRESSIVE);
                    tron->GetMotionMaster()->MovePath(NPC_OMNOTRON * 100, true);
                    tron->SetPower(POWER_ENERGY, 100);
                    tron->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_31); // from sniffs
                }
            }

            void BeamNext()
            {
                if (cur < 4)
                    ++cur;
                else
                    cur = 0;

                nextBot = botSequenz[cur];
                if (Creature* bot = Creature::GetCreature(*me, instance->GetData64(bots[nextBot].data)))
                    DoCast(bot, bots[nextBot].beamId, true);
            }

            void ShieldOld()
            {
                oldBot = currentBot;

                if (Creature* bot = Creature::GetCreature(*me, instance->GetData64(bots[oldBot].data)))
                {
                    bot->CastSpell(bot, bots[oldBot].shieldId, false);
                    Talk(bots[oldBot].textId);
                    bot->AI()->Talk(EMOTE_SHIELD);
                    target = bot->getVictim();
                }
            }

            void ActivateNext()
            {
                currentBot = nextBot;

                if (Creature* bot = Creature::GetCreature(*me, instance->GetData64(bots[currentBot].data)))
                {
                    bot->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_31);
                    bot->SetReactState(REACT_AGGRESSIVE);
                    bot->RemoveAurasDueToSpell(SPELL_INACTIVE);
                    bot->RemoveAurasDueToSpell(SPELL_POWERED_DOWN);
                    bot->CastSpell(bot, SPELL_ENERGY_DRAIN, true);
                    bot->CastSpell(bot, SPELL_ACTIVATED, true);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, bot);

                    if (target)
                        bot->GetMotionMaster()->MoveChase(target);
                }
            }

            void DeactivateOld()
            {
                if (!first)
                    if (Creature* bot = Creature::GetCreature(*me, instance->GetData64(bots[oldBot].data)))
                    {
                        bot->SetReactState(REACT_PASSIVE);
                        bot->RemoveAurasDueToSpell(SPELL_ACTIVATED);
                        bot->CastSpell(bot, SPELL_SHUTTING_DOWN, false);
                        bot->CastSpell(bot, SPELL_POWERED_DOWN, true);
                        bot->CastSpell(bot, SPELL_ENERGY_DRAIN, true);
                        bot->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_31);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, bot);
                        bot->AttackStop();
                        bot->AI()->DoAction(ACTION_RESET_EVENTS);
                    }
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_COMBAT:
                    {
                        if (!me->isInCombat())
                            me->SetInCombatWithZone();

                        BeamNext();
                        break;
                    }
                    case ACTION_DEATH:
                    {
                        Talk(SAY_DEATH);
                        _JustDied();
                        me->DespawnOrUnsummon(5000);
                        if (Creature* nefarian = me->GetCreature(*me, instance->GetData64(DATA_NEFARIUS_OMNOTRON_GUID)))
                            nefarian->AI()->DoAction(ACTION_DEATH);
                        break;
                    }
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_BEAM_NEXT, IsHeroic() ? 30000 : 45000);
                events.ScheduleEvent(EVENT_PLAYER_CHECK, 5000);
                Talk(SAY_AGGRO);
                if (IsHeroic())
                    me->SummonCreature(NPC_NEFARIUS_OMNOTRON, -302.155975f, -349.211700f, 220.481094f, 4.7f);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!me->isInCombat())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_BEAM_NEXT: // activates next npc
                        {
                            DeactivateOld();
                            ShieldOld();
                            ActivateNext();
                            BeamNext();
                            if (first)
                                first = false;
                            events.ScheduleEvent(EVENT_BEAM_NEXT, IsHeroic() ? 30000 : 45000);
                            break;
                        }
                    case EVENT_PLAYER_CHECK:
                        if (!SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {
                            for (int i = 0; i < 4; ++i)
                                if (Creature* bot = Creature::GetCreature(*me, instance->GetData64(bots[i].data)))
                                    bot->AI()->EnterEvadeMode();
                            events.ScheduleEvent(EVENT_RESET, 5000);
                        }
                        events.ScheduleEvent(EVENT_PLAYER_CHECK, 5000);
                        break;
                    case EVENT_RESET:
                        Reset();
                        break;
                    default:
                        break;
                    }
                }
            }

        private:
            uint8 oldBot;
            uint8 currentBot;
            uint8 nextBot;
            uint8 botSequenz[4];
            uint8 cur;
            Unit* target;
            bool first;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_omnotronAI(creature);
        }
};

// Individual AI for each bot

class npc_arcanotron : public CreatureScript
{
    public:
        npc_arcanotron() : CreatureScript("npc_arcanotron") { }

        struct npc_arcanotronAI : public generic_botAI
        {
            npc_arcanotronAI(Creature* creature) : generic_botAI(creature, DATA_OMNOTRON_DEFENSE_SYSTEM) { }

            void Reset()
            {
                generic_botAI::Reset();
            }

            void JustReachedHome()
            {
                generic_botAI::JustReachedHome();
            }
            
            void EnterCombat(Unit* who)
            {
                generic_botAI::EnterCombat(who);
                events.ScheduleEvent(EVENT_GENERATOR, urand(5000, 8000));
                events.ScheduleEvent(EVENT_ANNIHILATOR, urand(8000, 10000));
            }

            void EnterEvadeMode()
            {
                generic_botAI::EnterEvadeMode();
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_RESET_EVENTS)
                    events.Reset();
            }

            void UpdateAI(uint32  const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_GENERATOR:
                        {
                            Unit* target = NULL;
                            for (uint8 i = 0; i <= 2; ++i)
                            {
                                if (Creature* creature = me->GetCreature(*me,instance->GetData64(DATA_ELECTRON_GUID + i)))
                                {
                                    if (creature->HasAura(SPELL_INACTIVE))
                                        continue;
                                    target = creature;
                                    break;
                                }
                            }
                            if (!target)
                                target = me;
                            if (IsHeroic())
                                if (Creature* nefarian = me->GetCreature(*me, instance->GetData64(DATA_NEFARIUS_OMNOTRON_GUID)))
                                    nefarian->AI()->Talk(SAY_NEF_ARCANOTRON);
                            target->CastSpell(target, SPELL_POWER_GENERATOR, true);
                            events.ScheduleEvent(EVENT_GENERATOR, urand(30000, 35000));
                            break;
                        }
                    case EVENT_ANNIHILATOR:
                        DoCastRandom(SPELL_ARCANE_ANNIHILATOR, 200.0f); 
                        events.ScheduleEvent(EVENT_ANNIHILATOR, urand(5000, 7000));
                        break;
                    default:
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_arcanotronAI(creature);
        }
};

class npc_electron : public CreatureScript
{
    public:
        npc_electron() : CreatureScript("npc_electron") { }

        struct npc_electronAI : public generic_botAI
        {
            npc_electronAI(Creature * creature) : generic_botAI(creature, DATA_OMNOTRON_DEFENSE_SYSTEM) { }

            void Reset()
            {
                generic_botAI::Reset();
            }

            void JustReachedHome()
            {
                generic_botAI::JustReachedHome();
            }
            
            void EnterCombat(Unit* who)
            {
                generic_botAI::EnterCombat(who);
                events.ScheduleEvent(EVENT_CONDUCTOR, urand(5000, 8000));
                events.ScheduleEvent(EVENT_DISCHARGE, urand(8000, 10000));
            }

            void EnterEvadeMode()
            {
                generic_botAI::EnterEvadeMode();
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_RESET_EVENTS)
                    events.Reset();
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_CONDUCTOR:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                        {
                            DoCast(target, SPELL_LIGHTNING_CONDUCTOR);

                            if (IsHeroic())
                            {
                                if (Creature* nefarian = me->GetCreature(*me, instance->GetData64(DATA_NEFARIUS_OMNOTRON_GUID)))
                                {
                                    nefarian->AI()->Talk(SAY_NEF_ELECTRON);
                                    nefarian->CastSpell(nefarian, SPELL_SHADOW_INFUSION, false);
                                }
                            }
                            Talk(EMOTE_CONDUCTOR, target->GetGUID());
                        }
                        events.ScheduleEvent(EVENT_CONDUCTOR, urand(12000, 15000));
                        break;
                    case EVENT_DISCHARGE:
                        DoCastRandom(SPELL_ELECTRICAL_DISCHARGE, 200.0f); 
                        events.ScheduleEvent(EVENT_DISCHARGE, urand(5000, 7000));
                        break;
                    default:
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_electronAI(creature);
        }
};

class npc_magmatron : public CreatureScript
{
    public:
        npc_magmatron() : CreatureScript("npc_magmatron") { }

        struct npc_magmatronAI : public generic_botAI
        {
            npc_magmatronAI(Creature* creature) : generic_botAI(creature, DATA_OMNOTRON_DEFENSE_SYSTEM) { }

            void Reset()
            {
                BossAI::Reset();
                generic_botAI::Reset();
                targetGUID = 0;
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
            }

            void JustReachedHome()
            {
                generic_botAI::JustReachedHome();
            }

            void EnterCombat(Unit* who)
            {
                generic_botAI::EnterCombat(who);
                events.ScheduleEvent(EVENT_INCINERATION, urand(5000, 8000));
                events.ScheduleEvent(EVENT_ACQUIRING_TARGET, urand(8000, 10000));
            }

            void EnterEvadeMode()
            {
                generic_botAI::EnterEvadeMode();
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_RESET_EVENTS)
                    events.Reset();
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_INCINERATION:
                        DoCast(SPELL_INCINERATION);
                        events.ScheduleEvent(EVENT_INCINERATION, urand(18000, 20000));
                        break;
                    case EVENT_ACQUIRING_TARGET:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        {
                            targetGUID = target->GetGUID();
                            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                            me->AddThreat(target, 50000000.0f);
                            DoCast(target, SPELL_ACQUIRING_TARGET);
                            if (IsHeroic())
                            {
                                if (Creature* nefarian = me->GetCreature(*me, instance->GetData64(DATA_NEFARIUS_OMNOTRON_GUID)))
                                {
                                    nefarian->AI()->Talk(SAY_NEF_MAGMATRON);
                                    target->AddAura(SPELL_ENCASING_SHADOWS, target);
                                    //nefarian->CastSpell(nefarian, SPELL_ENCASING_SHADOWS, false);
                                }
                            }
                            Talk(EMOTE_FLAMETHROWER, targetGUID);
                            OmnotronTalk(SAY_MAGMATRON_FLAMETHROWER);
                        }
                        events.ScheduleEvent(EVENT_ACQUIRING_TARGET, urand(15000, 18000));
                        events.ScheduleEvent(EVENT_TAUNT_UNAPPLY, 8000);
                        break;
                    case EVENT_TAUNT_UNAPPLY:
                        if (Player* target = me->GetPlayer(*me, targetGUID))
                            me->AddThreat(target, -50000000.0f);
                        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                        break;
                    default:
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            uint64 targetGUID;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_magmatronAI(creature);
        }
};

class npc_toxitron : public CreatureScript
{
    public:
        npc_toxitron() : CreatureScript("npc_toxitron") { }

        struct npc_toxitronAI : public generic_botAI
        {
            npc_toxitronAI(Creature* creature) : generic_botAI(creature, DATA_OMNOTRON_DEFENSE_SYSTEM) { }

            void Reset()
            {
                generic_botAI::Reset();
            }

            void JustReachedHome()
            {
                generic_botAI::JustReachedHome();
            }
            
            void EnterCombat(Unit* who)
            {
                generic_botAI::EnterCombat(who);
                events.ScheduleEvent(EVENT_CHEMICAL_BOMB, urand(5000, 8000));
                events.ScheduleEvent(EVENT_POISON_PROTOCOL, urand(10000, 15000));
            }

            void EnterEvadeMode()
            {
                generic_botAI::EnterEvadeMode();
            }

            void JustSummoned(Creature* summon)
            {
                generic_botAI::JustSummoned(summon);
                if (summon->GetEntry() == NPC_POISON_BOMB)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_FIXATE))
                    {
                        summon->CastSpell(target, SPELL_FIXATE, true);
                        summon->ClearUnitState(UNIT_STATE_CASTING);
                        summon->AddThreat(target, 5000000.0f);
                        summon->AI()->AttackStart(target);
                    }
                }
                else if (summon->GetEntry() == NPC_CHEMICAL_BOMB)
                    summon->CastSpell(summon, SPELL_CHEMICAL_CLOUD, true);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_RESET_EVENTS)
                    events.Reset();
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_CHEMICAL_BOMB:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -INTERACTION_DISTANCE, true))
                        {
                            DoCastRandom(SPELL_CHEMICAL_BOMB, 0.0f);
                            if (IsHeroic())
                            {
                                if (Creature* nefarian = me->FindNearestCreature(NPC_NEFARIUS_OMNOTRON, 500.0f))
                                {
                                    nefarian->AI()->Talk(SAY_NEF_TOXITRON);
                                    nefarian->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f);
                                    nefarian->AI()->DoAction(ACTION_GRIP);
                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_CHEMICAL_BOMB, urand(20000, 23000));
                        break;
                    case EVENT_POISON_PROTOCOL:
                        DoCast(SPELL_POISON_PROTOCOL);
                        events.ScheduleEvent(EVENT_POISON_PROTOCOL, urand(18000, 20000));
                        break;
                    default:
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_toxitronAI(creature);
        }
};

class npc_victor_nefarius_omnotron : public CreatureScript
{
    public:
        npc_victor_nefarius_omnotron() : CreatureScript("npc_victor_nefarius_omnotron") { }

        struct npc_victor_nefarius_omnotronAI : public ScriptedAI
        {
            npc_victor_nefarius_omnotronAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_INTRO, 2000);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_DEATH)
                    events.ScheduleEvent(EVENT_DEATH, 5000);
                else if (action == ACTION_GRIP)
                    events.ScheduleEvent(EVENT_GRIP, 1500);
            }

            void UpdateAI(uint32 const diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_INTRO:
                        Talk(SAY_NEF_AGGRO);
                        break;
                    case EVENT_DEATH:
                        Talk(SAY_NEF_DEATH);
                        me->DespawnOrUnsummon(5000);
                        break;
                    case EVENT_GRIP:
                        DoCast(SPELL_GRIP_OF_DEATH);
                        break;
                    }
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_victor_nefarius_omnotronAI(creature);
        }
};

class npc_power_generator : public CreatureScript
{
    public:
        npc_power_generator() : CreatureScript("npc_power_generator") { }

        struct npc_power_generatorAI : public ScriptedAI
        {
            npc_power_generatorAI(Creature* creature) : ScriptedAI(creature)
            {
                if (IsHeroic())
                {
                    me->RemoveAllAuras();
                    DoCast(me, SPELL_OVERCHARGED_GENERATOR, true);
                }
            }

            void Reset()
            {
                growing = false;
                actionTimer = 20000;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!IsHeroic())
                    return;

                if (actionTimer <= diff)
                {
                    if (!growing)
                    {
                        growing = true;
                        DoCast(SPELL_GROW_STACKER);
                        actionTimer = 4500;
                    }
                    else
                    {
                        DoCast(SPELL_ARCANE_BLOWBACK);
                        me->DespawnOrUnsummon(1000);
                        actionTimer = 2000;
                    }
                } else actionTimer -= diff;

            }

        private:
            bool growing;
            uint32 actionTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_power_generatorAI(creature);
        }
};

class spell_power_generator_periodic : public SpellScriptLoader
{
    public:
        spell_power_generator_periodic() : SpellScriptLoader("spell_power_generator_periodic") { }

        class spell_power_generator_periodic_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_power_generator_periodic_SpellScript);

            void FilterTargets(std::list<WorldObject*>& SummonList)
            {
                Unit* caster = GetCaster();
                if (!caster || SummonList.empty())
                    return;

                uint32 stackAmount = 0;
                if (Aura* aur = caster->GetAura(SPELL_GROW))
                    stackAmount = aur->GetStackAmount();

                for (std::list<WorldObject*>::iterator itr = SummonList.begin(); itr != SummonList.end();)
                {
                    if (!(*itr)->IsWithinDist(caster, INTERACTION_DISTANCE + 3.0f * stackAmount))
                        itr = SummonList.erase(itr);
                    else
                        ++itr;
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_power_generator_periodic_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_power_generator_periodic_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_power_generator_periodic_SpellScript();
        }
};

class spell_shadow_conductor : public SpellScriptLoader
{
    public:
        spell_shadow_conductor() : SpellScriptLoader("spell_shadow_conductor") { }

        enum
        {
            SPELL_ID_10M        = 92051
        };

        class spell_shadow_conductor_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shadow_conductor_SpellScript);

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();
                if (!caster || !target)
                    return;

                float damage = GetSpellInfo()->Id == SPELL_ID_10M ? 15000.0f : 20000.0f;
                float dist = caster->GetDistance(target);
                SetHitDamage(int32(damage * std::max(dist / 2.0f, 1.0f)));
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_shadow_conductor_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_shadow_conductor_SpellScript();
        }
};

class spell_magmatron_barrier : public SpellScriptLoader
{
public:
    spell_magmatron_barrier() : SpellScriptLoader("spell_magmatron_barrier") { }

    class spell_magmatron_barrier_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_magmatron_barrier_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
                caster->CastSpell(caster, SPELL_BACKDRAFT, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_magmatron_barrier_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_magmatron_barrier_AuraScript();
    }
};

void AddSC_boss_omnotron_defense_system()
{
    new boss_omnotron();
    new npc_arcanotron();
    new npc_electron();
    new npc_magmatron();
    new npc_toxitron();
    new npc_victor_nefarius_omnotron();
    new npc_power_generator();
    new spell_power_generator_periodic();
    new spell_shadow_conductor();
    new spell_magmatron_barrier();
}
