#include "blackwing_descent.h"
#include "ScriptPCH.h"
#include "Util.h"
#include "Spell.h"

enum Spells
{
    SPELL_BERSERK               = 26662,
    SPELL_BREAK                 = 82881,
    SPELL_CAUSTIC_SLIME         = 82913,
    SPELL_MASSACRE              = 82848,
    SPELL_FEUD                  = 88872,
    SPELL_DOUBLE_ATTACK_EFF     = 82882,
    SPELL_DOUBLE_ATTACK_VIS     = 88826,
    SPELL_MORTALITY_AOE         = 82890,
    SPELL_MORTALITY_SELF        = 82934,
    SPELL_FAST_ASLEEP           = 82706,
    SPELL_MIXTURE_VIS           = 91106,
    SPELL_MIXTURE_EFF           = 82705,
    SPELL_SYSTEMS_FAILURE       = 88853,
    SPELL_REROUTE_POWER         = 88861,
};

enum Events
{
    EVENT_ENRAGE        = 1,
    EVENT_BREAK,
    EVENT_CAUSTIC_SLIME,
    EVENT_MASSACRE,
    EVENT_MASSACRE_FEUD,
    EVENT_DOUBLE_ATTACK,
    EVENT_MASSACRE_KNOCKOUT,
    EVENT_FEUD_INTERRUPT,

    EVENT_GROUP_NORMAL  = 1,
};

enum Misc
{
    DATA_BOT_GUID,
    PATH_BILE_O_TRON            = 4441800,
    ACTION_START_COMBAT         = 1,
    ACTION_DEATH,
    ACTION_FEUD,
    ACTION_PHASE_2
};

enum Phases
{
    PHASE_NORMAL        = 1,
    PHASE_FEUD,
    PHASE_MORTALITY,
};

enum Quotes
{
    EMOTE_AGGRO,
    EMOTE_BILE_O_TRON,
    EMOTE_MASSACRE,
    EMOTE_KNOCKOUT,
    SAY_SLAY            = 1,
    SAY_DEATH
};

class boss_chimaeron : public CreatureScript
{
    struct boss_chimaeronAI : public BossAI
    {
        boss_chimaeronAI(Creature* creature) : BossAI(creature, DATA_CHIMAERON)
        {
            DoCast(SPELL_FAST_ASLEEP);
        }

        void Reset()
        {
            _Reset();
            botGUID = 0;
            massacreCnt = 0;
            nefarianGUID = 0;
            events.SetPhase(PHASE_NORMAL);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
            if (Creature* nefarian = me->GetCreature(*me, nefarianGUID))
                nefarian->DespawnOrUnsummon();

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void KilledUnit(Unit* who)
        {
            BossAI::KilledUnit(who);
            if (who->GetTypeId() == TYPEID_PLAYER)
                if (Creature* finkle = me->FindNearestCreature(NPC_FINKLE_EINHORN, 200.0f))
                    finkle->AI()->Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            if (Creature* finkle = me->FindNearestCreature(NPC_FINKLE_EINHORN, 200.0f))
            {
                finkle->AI()->Talk(SAY_DEATH);
                finkle->DespawnOrUnsummon(1000);
            }
            if (Creature* nefarian = me->GetCreature(*me, nefarianGUID))
                nefarian->AI()->DoAction(ACTION_DEATH);

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MORTALITY_AOE);
        }

        void JustReachedHome()
        {
            _JustReachedHome();
            DoCast(SPELL_FAST_ASLEEP);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MORTALITY_AOE);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if (me->HealthBelowPctDamaged(20, damage) && (events.GetPhaseMask() & (1 << PHASE_MORTALITY)) == 0)
            {
                if (IsHeroic())
                    if (Creature* nefarian = me->GetCreature(*me, nefarianGUID))
                        nefarian->AI()->DoAction(ACTION_PHASE_2);
                events.CancelEventGroup(EVENT_GROUP_NORMAL);
                events.SetPhase(PHASE_MORTALITY);
                events.ScheduleEvent(EVENT_DOUBLE_ATTACK, 15000, EVENT_GROUP_NORMAL, PHASE_MORTALITY);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                DoCast(me, SPELL_MORTALITY_AOE, true);
                DoCast(me, SPELL_MORTALITY_SELF, true);
            }
        }

        void DoAction(int32 const action)
        {
            if (action == ACTION_START_COMBAT && !botGUID)
            {
                if (Creature* bot = me->SummonCreature(NPC_BILE_O_TRON_800, 0, 0, 0))
                {
                    Talk(EMOTE_BILE_O_TRON);
                    botGUID = bot->GetGUID();
                    bot->CastSpell(bot, SPELL_MIXTURE_VIS, true);
                    bot->CastSpell(bot, SPELL_MIXTURE_EFF, true);
                    bot->GetMotionMaster()->Clear();
                    bot->GetMotionMaster()->MovePath(PATH_BILE_O_TRON, true);
                    me->SetInCombatWithZone();
                }
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            Talk(EMOTE_AGGRO);
            events.ScheduleEvent(EVENT_ENRAGE, 450000);
            ScheduleEvents();
            if (Creature* nefarian = me->SummonCreature(NPC_NEFARIUS_CHIMAERON, -73.621025f, -26.955547f, 103.594498f, 2.373125f))
                nefarianGUID = nefarian->GetGUID();
        }

        void JustSummoned(Creature* creature)
        {
            if (creature->GetEntry() == NPC_NEFARIUS_CHIMAERON)
                return;

            BossAI::JustSummoned(creature);
        }

        void ScheduleEvents()
        {
            events.ScheduleEvent(EVENT_BREAK, 10000, EVENT_GROUP_NORMAL, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_DOUBLE_ATTACK, 15000, EVENT_GROUP_NORMAL, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_CAUSTIC_SLIME, 5000, EVENT_GROUP_NORMAL, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_MASSACRE, 45000, EVENT_GROUP_NORMAL, PHASE_NORMAL);
        }

        void MoveInLineOfSight(Unit* /*who*/)
        {
            // Do not engage on sight
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) && (events.GetPhaseMask() & (1 << PHASE_FEUD)) == 0)
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ENRAGE:
                    DoCast(SPELL_BERSERK);
                    break;
                case EVENT_BREAK:
                    DoCastVictim(SPELL_BREAK);
                    events.ScheduleEvent(EVENT_BREAK, urand(15000, 18000), EVENT_GROUP_NORMAL, IsHeroic() ? 0 : PHASE_NORMAL);
                    break;
                case EVENT_CAUSTIC_SLIME:
                    DoCastRandom(SPELL_CAUSTIC_SLIME, 0.0f, true, -SPELL_BREAK);
                    if(events.GetPhaseMask() & (1 << PHASE_NORMAL))
                        events.ScheduleEvent(EVENT_CAUSTIC_SLIME, urand(5000, 8000), EVENT_GROUP_NORMAL, PHASE_NORMAL);
                    break;
                case EVENT_MASSACRE:
                    Talk(EMOTE_MASSACRE);
                    DoCast(SPELL_MASSACRE);
                    events.DelayEvents(7000, EVENT_GROUP_NORMAL);
                    events.ScheduleEvent(EVENT_MASSACRE_KNOCKOUT, 4000, EVENT_GROUP_NORMAL);
                    break;
                case EVENT_MASSACRE_KNOCKOUT:
                    if(roll_chance_i(50 * massacreCnt))
                    {
                        massacreCnt = 0;
                        events.SetPhase(PHASE_FEUD);
                        events.CancelEventGroup(EVENT_GROUP_NORMAL);
                        DoCast(SPELL_FEUD);
                        // 3 Caustic Slime casts in a row
                        events.ScheduleEvent(EVENT_CAUSTIC_SLIME, 15000, EVENT_GROUP_NORMAL, PHASE_FEUD);
                        events.ScheduleEvent(EVENT_CAUSTIC_SLIME, 20000, EVENT_GROUP_NORMAL, PHASE_FEUD);
                        events.ScheduleEvent(EVENT_CAUSTIC_SLIME, 25000, EVENT_GROUP_NORMAL, PHASE_FEUD);
                        events.ScheduleEvent(EVENT_MASSACRE_FEUD, 26000, EVENT_GROUP_NORMAL, PHASE_FEUD);

                        if(IsHeroic())
                        {
                            if(Creature* nefarian = me->GetCreature(*me, nefarianGUID))
                                nefarian->AI()->DoAction(ACTION_FEUD);
                            events.ScheduleEvent(EVENT_FEUD_INTERRUPT, 6000);
                            events.ScheduleEvent(EVENT_DOUBLE_ATTACK, 6000, EVENT_GROUP_NORMAL, PHASE_FEUD);
                        }

                        if(Creature* bot = me->GetCreature(*me, botGUID))
                        {
                            Talk(EMOTE_KNOCKOUT);
                            bot->RemoveAllAuras();
                            bot->CastSpell(bot, SPELL_SYSTEMS_FAILURE, true);
                            bot->CastSpell(bot, SPELL_REROUTE_POWER, false);
                        }
                    }
                    else
                    {
                        ++massacreCnt;
                        events.ScheduleEvent(EVENT_MASSACRE, 26000, EVENT_GROUP_NORMAL);
                    }
                    break;
                case EVENT_FEUD_INTERRUPT:
                    if(Spell* spell = me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                        spell->SendChannelUpdate(0);
                        //spell->SendInterrupted(0);
                    me->RemoveAurasDueToSpell(SPELL_FEUD);
                    break;
                case EVENT_MASSACRE_FEUD:
                    Talk(EMOTE_MASSACRE);
                    DoCast(SPELL_MASSACRE);
                    // re-enable bot
                    if(Creature* bot = me->GetCreature(*me, botGUID))
                    {
                        bot->GetMotionMaster()->MovePath(PATH_BILE_O_TRON, true);
                        bot->RemoveAurasDueToSpell(SPELL_SYSTEMS_FAILURE);
                    }
                    // cancel everything except Enrage and re-schedule
                    events.SetPhase(PHASE_NORMAL);
                    events.CancelEventGroup(EVENT_GROUP_NORMAL);
                    ScheduleEvents();
                    me->resetAttackTimer();
                    break;
                case EVENT_DOUBLE_ATTACK:
                    DoCast(SPELL_DOUBLE_ATTACK_VIS);
                    DoCast(SPELL_DOUBLE_ATTACK_EFF);
                    events.ScheduleEvent(EVENT_DOUBLE_ATTACK, urand(10000, 15000), IsHeroic() ? 0 : EVENT_GROUP_NORMAL);
                    break;
                }
            }

            if(me->isAttackReady())
                me->RemoveAurasDueToSpell(SPELL_DOUBLE_ATTACK_VIS);
            DoMeleeAttackIfReady();
        }
    private:
        uint64 botGUID;
        uint64 nefarianGUID;
        uint8 massacreCnt;
    };

public:
    boss_chimaeron() : CreatureScript("boss_chimaeron") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_chimaeronAI(creature);
    }
};

static const std::string GOSSIP_OPTIONS[5] =
{
    "I suppose you'll be needing a key for this cage? Wait, don't tell me. The horrific gibbering monster behind me ate it, right?",
    "You were trapped, as I recall. This situation seems oddly similar.",
    "Gnomes in Lava Suits, for example.",
    "No, I, uh, haven't seen it. You were saying?",
    "Restrictions? What restrictions?",
};

static const uint32 GOSSIP_TEXTS[6] = {16565,16593,16594,16595,16596,16597};

class npc_finkle_einhorn : public CreatureScript
{
    public:
        npc_finkle_einhorn() : CreatureScript("npc_finkle_einhorn") { }

        struct npc_finkle_einhornAI : public ScriptedAI
        {
            npc_finkle_einhornAI(Creature * creature) : ScriptedAI(creature) {}

            void Reset()
            {
                done = false;
                talkTimer = urand(10000, 15000);
            }

            void DoAction(int32 const /*action*/)
            {
                done = true;
            }

            void UpdateAI(uint32 const diff)
            {
                if (done)
                    return;

                if (talkTimer <= diff)
                {
                    Talk(0);
                    talkTimer = urand(10000, 15000);
                }else talkTimer -= diff;
            }

        private:
            bool done;
            uint32 talkTimer;
        };

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_OPTIONS[0], GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(GOSSIP_TEXTS[0], creature->GetGUID());

            creature->AI()->DoAction(0);
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            uint8 step = uint8(action - GOSSIP_ACTION_INFO_DEF);

            if (step <= 4)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_OPTIONS[step], GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + step + 1);

            if (step == 5)
                if (Creature* chimaeron = creature->FindNearestCreature(NPC_CHIMAERON, 100.0f))
                    chimaeron->AI()->DoAction(ACTION_START_COMBAT);

            player->SEND_GOSSIP_MENU(GOSSIP_TEXTS[step], creature->GetGUID());
            return true;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_finkle_einhornAI(creature);
        }
};

class npc_victor_nefarius_chimaeron : public CreatureScript
{
    public:
        npc_victor_nefarius_chimaeron() : CreatureScript("npc_victor_nefarius_chimaeron") {}

        enum
        {
            SAY_AGGRO,
            SAY_DEATH,
            SAY_MOCKING_SHADOWS,
            SAY_FEUD,
            SPELL_SHADOW_WHIP           = 91304,
            SPELL_MOCKING_SHADOWS       = 91307
        };

        struct npc_victor_nefarius_chimaeronAI : public ScriptedAI
        {
            npc_victor_nefarius_chimaeronAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void Reset()
            {
                deathTimer = 0;
                outro = false;
            }

            void IsSummonedBy(Unit* /* who*/)
            {
                Talk(SAY_AGGRO);
            }

            void DoAction(int32 const action)
            {
                switch(action)
                {
                case ACTION_DEATH:
                    outro = true;
                    deathTimer = 3000;
                    break;
                case ACTION_FEUD:
                    Talk(SAY_FEUD);
                    DoCast(SPELL_SHADOW_WHIP);
                    break;
                case ACTION_PHASE_2:
                    Talk(SAY_MOCKING_SHADOWS);
                    DoCast(SPELL_MOCKING_SHADOWS);
                    break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!outro)
                    return;

                if (deathTimer <= diff)
                {
                    outro = false;
                    Talk(SAY_DEATH);
                    me->DespawnOrUnsummon(5000);
                } else deathTimer -= diff;
            }

        private:
            bool outro;
            uint32 deathTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_victor_nefarius_chimaeronAI(creature);
        }
};

class spell_finkles_mixture : public SpellScriptLoader
{
public:
    spell_finkles_mixture() : SpellScriptLoader("spell_finkles_mixture") { }

    class spell_finkles_mixture_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_finkles_mixture_AuraScript);

        void CalculateAmount(AuraEffect const* /* aurEff*/, int32 &amount, bool & canBeRecalculated)
        {
            amount = -1;
        }

        void Absorb(AuraEffect* /* aurEff*/, DamageInfo &dmgInfo, uint32 &absorbAmount)
        {
            Unit* target = GetTarget();
            uint32 damage = dmgInfo.GetDamage();
            uint32 hp = target->GetHealth();
            if (damage >= hp && hp > 10000)
                absorbAmount = ++damage - hp;
            else
                absorbAmount = 0;
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_finkles_mixture_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_finkles_mixture_AuraScript::Absorb, EFFECT_1);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_finkles_mixture_AuraScript();
    }
};

void AddSC_boss_chimaeron()
{
    new boss_chimaeron();
    new npc_finkle_einhorn();
    new npc_victor_nefarius_chimaeron();
    new spell_finkles_mixture();
};
