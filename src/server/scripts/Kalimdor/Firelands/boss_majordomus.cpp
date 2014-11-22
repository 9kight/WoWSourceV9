/*
 * Copyright (C) 2013 WoW Source  <http://wowsource.info/>
 *
 * Copyright (C) 2013 WoWSource [WS] <http://wowsource.info/>
 *
 * Dont Share The SourceCode
 * and read our WoWSource Terms
 *
 */

#include "ScriptPCH.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"

#include "firelands.h"

enum Yells
{
    SAY_INTRO_1  = 0,
    SAY_INTRO_2  = 1,
    SAY_INTRO_3  = 2,
    SAY_AGGRO    = 3,
    SAY_ON_DEAD  = 4,
    SAY_ON_KILL  = 5,
    SAY_SCORPION = 6,
    SAY_CAT      = 7,
    SAY_DRUID    = 8,
    SAY_SEEDS    = 9,
    SAY_ORBS     = 10,
    SAY_SCYTE    = 11,
    SAY_LEAP     = 12
};

enum Spells
{
    SPELL_ZERO_POWER = 72242,

    SPELL_CAT_FORM = 98374,
    SPELL_SCORPION_FORM = 98379,

    SPELL_ADRENALINE = 97238,
    SPELL_BERSERK = 47008,
    SPELL_BURNING_ORBS = 98451,
    SPELL_BURNING_ORBS_SUMMON = 98565,
    SPELL_BURNING_ORBS_VISUAL = 98583,
    SPELL_FIERY_CYCLONE = 98443,
    SPELL_FURY = 97235,

    SPELL_BURNING_ORBS_DMG_10N = 98584,
    SPELL_BURNING_ORBS_DMG_25N = 100209,
    SPELL_BURNING_ORBS_DMG_10H = 100210,
    SPELL_BURNING_ORBS_DMG_25H = 100211,

    SPELL_FLAME_SCYTE_10N = 98474,
    SPELL_FLAME_SCYTE_25N = 100212,
    SPELL_FLAME_SCYTE_10H = 100213,
    SPELL_FLAME_SCYTE_25H = 100214,

    SPELL_LEAPING_FLAMES = 98476,
    SPELL_LEAPING_FLAMES_SUMMON = 101222,

    SPELL_LEAP_FLAMES_DMG_10N = 98535,
    SPELL_LEAP_FLAMES_DMG_25N = 100206,
    SPELL_LEAP_FLAMES_DMG_10H = 100207,
    SPELL_LEAP_FLAMES_DMG_25H = 100208,

    SPELL_SEARING_SEEDS = 98450,

    SPELL_SEARING_SEEDS_DMG_10N = 98620,
    SPELL_SEARING_SEEDS_DMG_25N = 100215,
    SPELL_SEARING_SEEDS_DMG_10H = 100216,
    SPELL_SEARING_SEEDS_DMG_25H = 100217
};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_INTRO_1 = 2,
    EVENT_INTRO_2 = 3,
    EVENT_INTRO_3 = 4,
    EVENT_SUMMON_ORBS = 5,
    EVENT_CHECK_FORM = 6,
    EVENT_ENERGY_REGEN = 7,

    // Spirit of the Flame
    EVENT_JUMP_TARGET = 8,

    // Burning Orb
    EVENT_ORB_DAMAGE = 9,

    EVENT_SAY = 10
};

enum MajordomoPhase
{
    PHASE_NONE = 0, PHASE_DRUID = 1, PHASE_CAT = 2, PHASE_SCORPION = 3
};

/**** Majordomo Staghelm ****/

class boss_majordomus: public CreatureScript
{
    public:
        boss_majordomus() :
                CreatureScript("boss_majordomus")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_majordomusAI(creature);
        }

        struct boss_majordomusAI: public BossAI
        {
                boss_majordomusAI(Creature* c) :
                        BossAI(c, DATA_MAJORDOMUS)
                {
                    instance = me->GetInstanceScript();
                    introDone = false;
                    me->SetSpeed(MOVE_RUN, 1.5f, true);
                }

                InstanceScript* instance;

                MajordomoPhase phase;
                bool introDone;
                uint32 transformcount;

                void Reset()
                {
                    if (instance)
                    {
                        instance->SetBossState(DATA_MAJORDOMUS, NOT_STARTED);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                    }

                    events.Reset();

                    summons.DespawnAll();
                    me->RemoveAllAuras();
                    TransformToNormal();
                    transformcount = 0;
                }

                void MoveInLineOfSight(Unit* who)
                {
                    if (introDone || !me->IsWithinDistInMap(who, 35.0f, false))
                        return;

                    introDone = true;
                    // events.SetPhase(1);

                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    me->SetReactState(REACT_PASSIVE);

                    events.ScheduleEvent(EVENT_INTRO_1, 5000);
                    events.ScheduleEvent(EVENT_INTRO_2, 17000);
                    events.ScheduleEvent(EVENT_INTRO_3, 22500);
                }

                void EnterEvadeMode()
                {
                    Reset();

                    me->GetMotionMaster()->MoveTargetedHome();

                    if (instance)
                        instance->SetBossState(DATA_MAJORDOMUS, FAIL);

                    _EnterEvadeMode();
                }

                void KilledUnit(Unit * /*victim*/)
                {
                    Talk(SAY_ON_KILL);
                }

                void JustSummoned(Creature* summon)
                {
                    summons.Summon(summon);
                    summon->setActive(true);

                    if (me->isInCombat())
                        summon->AI()->DoZoneInCombat();
                }

		void DespawnObjects(uint32 entry, float distance)
		{
                    std::list<GameObject*> firedoor;
                    me->GetGameObjectListWithEntryInGrid(firedoor, 208873, 5000.0f);
			
		    if (!firedoor.empty())
                    	for (std::list<GameObject*>::const_iterator itr = firedoor.begin(); itr != firedoor.end(); ++itr)                       
				(*itr)->Delete();
		}

                void JustDied(Unit * /*victim*/)
                {
                    if (instance)
                    {
                        instance->SetBossState(DATA_MAJORDOMUS, DONE);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                    }

                    if (GameObject* firewall = me->FindNearestGameObject(208906, 5000.0f))
                        firewall->DestroyForNearbyPlayers();

		    DespawnObjects(208873, 50000.0f);

                    Talk(SAY_ON_DEAD);
                    summons.DespawnAll();
                    _JustDied();
                }

                void EnterCombat(Unit* who)
                {
                    if (instance)
                    {
                        instance->SetBossState(DATA_MAJORDOMUS, IN_PROGRESS);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
                    }

                    Talk(SAY_AGGRO);
                    events.ScheduleEvent(EVENT_CHECK_FORM, 10000);
                    events.ScheduleEvent(EVENT_ENERGY_REGEN, 12000);
                    events.ScheduleEvent(EVENT_BERSERK, 10 * MINUTE * IN_MILLISECONDS);

                    _EnterCombat();
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim() && phase != PHASE_NONE || me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    if (phase == PHASE_SCORPION && me->GetPower(POWER_ENERGY) == 100)
                    {
                        DoCast(me,
                                RAID_MODE(SPELL_FLAME_SCYTE_10N, SPELL_FLAME_SCYTE_25N, SPELL_FLAME_SCYTE_10H,
                                        SPELL_FLAME_SCYTE_25H));

                        Talk(SAY_SCYTE);
                    }

                    if (phase == PHASE_CAT && me->GetPower(POWER_ENERGY) == 100)
                    {
                        DoCast(me, SPELL_LEAPING_FLAMES_SUMMON);
                        if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
                        {
                            DoCast(tempTarget, SPELL_LEAPING_FLAMES);
                            DoCast(tempTarget,
                                    RAID_MODE(SPELL_LEAP_FLAMES_DMG_10N, SPELL_LEAP_FLAMES_DMG_25N,
                                            SPELL_LEAP_FLAMES_DMG_10H, SPELL_LEAP_FLAMES_DMG_25H));
                        }

                        Talk(SAY_LEAP);
                    }

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CHECK_FORM:
                            {
                                uint8 numb = 0;
                                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                    if (Player* player = itr->getSource())
                                        if (me->GetDistance(player) <= 7.0f)
                                            ++numb;

                                if ((numb >= (Is25ManRaid() ? 18 : 7)) && phase != PHASE_SCORPION
                                        && phase != PHASE_DRUID)
                                {
                                    if (transformcount == 3)
                                    {
                                        transformcount = 0;
                                        TransformToDruid();
                                    }
                                    else
                                    {
                                        transformcount += 1;
                                        TransformToScorpion();
                                    }
                                }
                                else if ((numb < (Is25ManRaid() ? 18 : 7)) && phase != PHASE_CAT
                                        && phase != PHASE_DRUID)
                                {
                                    if (transformcount == 3)
                                    {
                                        transformcount = 0;
                                        TransformToDruid();
                                    }
                                    else
                                    {
                                        transformcount += 1;
                                        TransformToCat();
                                    }
                                }

                                events.ScheduleEvent(EVENT_CHECK_FORM, 1000);
                                break;
                            }
                            case EVENT_ENERGY_REGEN:
                            {
                                if (phase == PHASE_CAT || phase == PHASE_SCORPION)
                                {
                                    int32 power = 5;
                                    if (me->HasAura(SPELL_ADRENALINE))
                                        power += power * (me->GetAura(SPELL_ADRENALINE)->GetStackAmount() * 20) / 100;
                                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + power);
                                }
                                events.ScheduleEvent(EVENT_ENERGY_REGEN, 1000);
                                break;
                            }

                            case EVENT_INTRO_1:
                                Talk(SAY_INTRO_1);
                                break;

                            case EVENT_INTRO_2:
                                Talk(SAY_INTRO_2);
                                break;

                            case EVENT_INTRO_3:
                                Talk(SAY_INTRO_3);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                                me->SetReactState(REACT_DEFENSIVE);
                                break;

                            case EVENT_BERSERK:
                                DoCast(me, SPELL_BERSERK);
                                break;

                            case EVENT_SUMMON_ORBS:
                            {
                                std::list<Unit*> targets;
                                SelectTargetList(targets, RAID_MODE(2, 3, 2, 3), SELECT_TARGET_RANDOM, 200.0f, true);
                                if (!targets.empty())
                                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                        DoCast(*itr, SPELL_BURNING_ORBS_SUMMON);
                                break;
                            }
                        }
                    }

                    DoMeleeAttackIfReady();
                }

            private:
                void TransformToCat()
                {
                    me->RemoveAura(SPELL_ADRENALINE);
                    me->RemoveAura(SPELL_SCORPION_FORM);

                    DoCast(me, SPELL_CAT_FORM);

                    me->SetByteValue(UNIT_FIELD_BYTES_0, 1, 4);
                    me->SetByteValue(UNIT_FIELD_BYTES_0, 3, POWER_ENERGY);
                    me->SetMaxPower(POWER_ENERGY, 100);
                    me->SetPower(POWER_ENERGY, 0);
                    DoCast(me, SPELL_ZERO_POWER);

                    DoCast(me, SPELL_FURY);

                    phase = PHASE_CAT;

                    Talk(SAY_CAT);
                }

                void TransformToScorpion()
                {
                    me->RemoveAura(SPELL_ADRENALINE);
                    me->RemoveAura(SPELL_CAT_FORM);

                    DoCast(me, SPELL_SCORPION_FORM);

                    me->SetByteValue(UNIT_FIELD_BYTES_0, 1, 4);
                    me->SetByteValue(UNIT_FIELD_BYTES_0, 3, POWER_ENERGY);
                    me->SetMaxPower(POWER_ENERGY, 100);
                    me->SetPower(POWER_ENERGY, 0);
                    DoCast(me, SPELL_ZERO_POWER);

                    DoCast(me, SPELL_FURY);

                    phase = PHASE_SCORPION;

                    Talk(SAY_SCORPION);
                }

                void TransformToDruid()
                {
                    me->RemoveAura(SPELL_ADRENALINE);

                    DoCast(me, SPELL_FIERY_CYCLONE);

                    //When switching from Cat form to Scorpion form, Fandral unleashes Searing Seeds.When switching from Scorpion form to Cat form, Fandral unleashes Burning Orbs.
                    if (me->HasAura(SPELL_CAT_FORM)) // Here is the check for previous form for seering seeds.
                    {
                        me->RemoveAura(SPELL_CAT_FORM);
                        Talk(SAY_SEEDS);
                        DoCast(me, SPELL_SEARING_SEEDS);
                    }

                    if (me->HasAura(SPELL_SCORPION_FORM)) // Here is the check for previous form for burning orbs.
                    {
                        me->RemoveAura(SPELL_SCORPION_FORM);
                        Talk(SAY_ORBS);
                        DoCast(me, SPELL_BURNING_ORBS);
                        events.ScheduleEvent(EVENT_SUMMON_ORBS, 500);
                    }

                    me->SetByteValue(UNIT_FIELD_BYTES_0, 1, 2);
                    me->SetByteValue(UNIT_FIELD_BYTES_0, 3, POWER_MANA);
                    me->SetMaxPower(POWER_MANA, 179200);
                    me->SetPower(POWER_MANA, 179200);
                    phase = PHASE_DRUID;
                    Talk(SAY_DRUID);
                }

                void TransformToNormal()
                {
                    me->SetByteValue(UNIT_FIELD_BYTES_0, 1, 2);
                    me->SetByteValue(UNIT_FIELD_BYTES_0, 3, POWER_MANA);
                    me->SetMaxPower(POWER_MANA, 179200);
                    me->SetPower(POWER_MANA, 179200);
                    phase = PHASE_NONE;
                }
        };
};

class npc_spirit_of_the_flame: public CreatureScript //52593 npc
{
    public:
        npc_spirit_of_the_flame() : CreatureScript("npc_spirit_of_the_flame") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spirit_of_the_flameAI(creature);
        }

        struct npc_spirit_of_the_flameAI: public ScriptedAI
        {
                npc_spirit_of_the_flameAI(Creature *c) : ScriptedAI(c) { }

                EventMap events;

                void IsSummonedBy(Unit* summoner)
                {
                    DoZoneInCombat();
                }

                void Reset()
                {
                    me->SetByteValue(UNIT_FIELD_BYTES_0, 1, 4);
                    me->SetByteValue(UNIT_FIELD_BYTES_0, 3, POWER_ENERGY);
                }

                void JustDied(Unit * /*victim*/)
                {
                    me->DespawnOrUnsummon(5000);
                }

                void EnterCombat(Unit* who)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 300.0f))
                        AttackStart(target);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim())
                        return;

                    DoMeleeAttackIfReady();
                }

        };
};

class npc_burning_orb: public CreatureScript //53216
{
    public:
        npc_burning_orb() : CreatureScript("npc_burning_orb") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_burning_orbAI(creature);
        }

        struct npc_burning_orbAI: public ScriptedAI
        {
                npc_burning_orbAI(Creature *c) : ScriptedAI(c)
                {
                    SetCombatMovement(false);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                }

                EventMap events;

                void Reset() { }

                void IsSummonedBy(Unit* summoner)
                {
                    DoZoneInCombat();
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->AddAura(SPELL_BURNING_ORBS_VISUAL, me);
                }

                void JustDied(Unit* /*victim*/) { }

                void EnterCombat(Unit* /*who*/)
                {
                    events.ScheduleEvent(EVENT_ORB_DAMAGE, 3500);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_ORB_DAMAGE:
                                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 200, true))
                                    DoCast(target, RAID_MODE(SPELL_BURNING_ORBS_DMG_10N, SPELL_BURNING_ORBS_DMG_25N, SPELL_BURNING_ORBS_DMG_10H, SPELL_BURNING_ORBS_DMG_25H));
                                events.ScheduleEvent(EVENT_ORB_DAMAGE, 3500);
                                break;
                        }
                    }
                }
        };
};

class spell_searing_seeds: public SpellScriptLoader
{
    public:
        spell_searing_seeds() :
                SpellScriptLoader("spell_searing_seeds")
        {
        }

        class spell_searing_seeds_AuraScript: public AuraScript
        {
                PrepareAuraScript(spell_searing_seeds_AuraScript)
                ;

                bool Validate(SpellInfo const* /*spell*/)
                {
                    if (!sSpellMgr->GetSpellInfo(SPELL_SEARING_SEEDS))
                    return false;
                    return true;
                }

                void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
                {
                    int32 duration = urand(15,60);
                    if (GetUnitOwner()->HasAura(SPELL_SEARING_SEEDS))
                    GetUnitOwner()->GetAura(SPELL_SEARING_SEEDS)->SetDuration(duration*IN_MILLISECONDS);
                }

                void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
                {
                    AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                    if (removeMode != AURA_REMOVE_BY_EXPIRE)
                    return;

                    int32 spell = 0;

                    if (InstanceScript* instance = GetTarget()->GetInstanceScript())
                    {
                        if (instance->instance->Is25ManRaid())
                        {
                            if (instance->instance->IsHeroic())
                            spell = SPELL_SEARING_SEEDS_DMG_25H;
                            else
                            spell = SPELL_SEARING_SEEDS_DMG_25N;
                        }
                        else
                        {
                            if (instance->instance->IsHeroic())
                            spell = SPELL_SEARING_SEEDS_DMG_10H;
                            else
                            spell = SPELL_SEARING_SEEDS_DMG_10N;
                        }
                    }

                    if (spell != 0)
                    GetUnitOwner()->CastSpell(GetUnitOwner(),spell,true);
                }

                void Register()
                {
                    OnEffectApply += AuraEffectApplyFn(spell_searing_seeds_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                    AfterEffectRemove += AuraEffectRemoveFn(spell_searing_seeds_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                }
            };

            AuraScript* GetAuraScript() const
            {
                return new spell_searing_seeds_AuraScript();
            }
        };

void AddSC_boss_majordomus()
{
    new boss_majordomus();
    new npc_spirit_of_the_flame();
    new npc_burning_orb();
    new spell_searing_seeds();
}
