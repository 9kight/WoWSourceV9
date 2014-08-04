/* Copyright (C) WoW Source 4.3.4 */

/* Name: boss_grand_vizier_ertan
* Progress: 100%
* Author: Demigodess
* Comments:
*/

#include "SpellScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Cell.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "the_vortex_pinnacle.h"

enum AltairusSpells
{
    SPELL_CHILLING_BREATH        = 88308, // SPELL_AURA_DUMMY | SPELL_EFFECT_SCHOOL_DAMAGE

    SPELL_SAFE_ZONE              = 88350, // SPELL_EFFECT_APPLY_AREA_AURA_ENEMY

    SPELL_LIGHTNING_BLAST        = 88332, //(+)SPELL_EFFECT_DUMMY
    SPELL_LIGHTNING_BLAST_DAMAGE = 88357, // +-> SPELL_EFFECT_SCHOOL_DAMAGE

    SPELL_CALL_THE_WIND          = 88276, //(+)SPELL_EFFECT_DUMMY
    SPELL_CALL_WINDS_VISUAL      = 88772, // +-> SPELL_AURA_DUMMY
    SPELL_CALL_THE_WIND_PERIODIC = 88244, // +-> + SPELL_AURA_PERIODIC_TRIGGER_SPELL
    SPELL_UPWIND_OF_ALTAIRUS     = 88282, //     +->(+)SPELL_AURA_MELEE_SLOW | SPELL_AURA_MOD_INCREASE_SPEED
    SPELL_DOWNWIND_OF_ALTAIRUS   = 88286, //         +-> SPELL_AURA_MELEE_SLOW | SPELL_AURA_MOD_DECREASE_SPEED

    SPELL_TWISTER_AURA           = 88313, // + SPELL_AURA_PERIODIC_TRIGGER_SPELL
    SPELL_TWISTER_TICK           = 88314, // +-> SPELL_EFFECT_SCHOOL_DAMAGE | SPELL_EFFECT_KNOCK_BACK | SPELL_EFFECT_APPLY_AURA
};

enum AltairusEvents
{
    EVENT_CHECK_COWARDICE = 1,
    EVENT_CHILLING_BREATH,
    EVENT_CALL_THE_WIND,
    EVENT_TWISTING_WINDS
};

enum AltaiursTimer
{
    TIMER_CHECK_COWARDICE      = 1 * IN_MILLISECONDS,

    TIMER_CHILLING_BREATH_INIT = 2 * IN_MILLISECONDS,
    TIMER_CHILLING_BREATH_MIN  = 10 * IN_MILLISECONDS,
    TIMER_CHILLING_BREATH_MAX  = 15 * IN_MILLISECONDS,

    TIMER_CALL_THE_WIND_INIT   = 6 * IN_MILLISECONDS,
    TIMER_CALL_THE_WIND        = 20 * IN_MILLISECONDS,
    TIMER_DELAY_VISUAL         = 2 * IN_MILLISECONDS,

    TIMER_TWISTING_WINDS_INIT  = 5 * IN_MILLISECONDS,
    TIMER_TWISTING_WINDS       = 15 * IN_MILLISECONDS
};

enum AltairusCreatureTexts
{
    SAY_WIND_CHANGE = 0,
    SAY_COWARDICE   = 1
};

float const SUMMON_RADIUS = 25.0f;
uint32 const NUM_TWISTERS_PER_SUMMON = 4;
Position const Center = { -1216.225f, 64.027f, 734.175f, 0.0f };

class boss_altairus : public CreatureScript
{
public:
    boss_altairus() : CreatureScript("boss_altairus") {}

    struct boss_altairusAI : public BossAI
    {
        boss_altairusAI(Creature* creature) : BossAI(creature, DATA_ALTAIRUS) { }

        void Reset()
        {
            BossAI::Reset();

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->DespawnCreaturesInArea(NPC_SAFE_ZONE);
            me->DespawnCreaturesInArea(NPC_TWISTER);

            std::list<Creature*> targets;
            GetCreatureListWithEntryInGrid(targets, me, NPC_AIR_CURRENT, 150.0f);
            for (std::list<Creature*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                (*itr)->RemoveAura(SPELL_CALL_THE_WIND_PERIODIC);
        }

        void EnterCombat(Unit* who)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            Creature *safe_zone = DoSummon(NPC_SAFE_ZONE, Center);
            safe_zone->CastSpell(safe_zone, SPELL_SAFE_ZONE);
            safe_zone->SetReactState(REACT_PASSIVE);

            events.ScheduleEvent(EVENT_CHECK_COWARDICE, TIMER_CHECK_COWARDICE);
            events.ScheduleEvent(EVENT_CHILLING_BREATH, TIMER_CHILLING_BREATH_INIT);
            events.ScheduleEvent(EVENT_CALL_THE_WIND, TIMER_CALL_THE_WIND_INIT);

            if (IsHeroic())
                events.ScheduleEvent(EVENT_TWISTING_WINDS, TIMER_TWISTING_WINDS_INIT);

            BossAI::EnterCombat(who);
        }

        void JustDied(Unit* /*who*/)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->DespawnCreaturesInArea(NPC_SAFE_ZONE);
            me->DespawnCreaturesInArea(NPC_TWISTER);

            std::list<Creature*> targets;
            GetCreatureListWithEntryInGrid(targets, me, NPC_AIR_CURRENT, 150.0f);
            for (std::list<Creature*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                (*itr)->RemoveAura(SPELL_CALL_THE_WIND_PERIODIC);

            Creature * Slipstream = me->SummonCreature(45455, -765.79f, -44.01f, 641.91f, 4.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            Slipstream->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHECK_COWARDICE:
                    {
                        bool cast = false;
                        Map::PlayerList const &players = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player *player = itr->getSource())
                        if (!itr->getSource()->HasAura(SPELL_SAFE_ZONE))
                        {
                            Talk(SAY_COWARDICE, player->GetGUID());
                            cast = true;
                        }

                        if (cast)
                            DoCastAOE(SPELL_LIGHTNING_BLAST);

                        events.ScheduleEvent(EVENT_CHECK_COWARDICE, TIMER_CHECK_COWARDICE);
                        break;
                    }
                    case EVENT_CHILLING_BREATH:
                    {
                        if (IsHeroic())
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_CHILLING_BREATH);
                        else
                            DoCastVictim(SPELL_CHILLING_BREATH);

                        events.ScheduleEvent(EVENT_CHILLING_BREATH, urand(TIMER_CHILLING_BREATH_MIN, TIMER_CHILLING_BREATH_MAX));
                        break;
                    }
                    case EVENT_CALL_THE_WIND:
                    {
                        DoCastAOE(SPELL_CALL_THE_WIND);
                        events.ScheduleEvent(EVENT_CALL_THE_WIND, TIMER_CALL_THE_WIND);
                        break;
                    }
                    case EVENT_TWISTING_WINDS:
                    {
                        for (uint32 i = 0; i < NUM_TWISTERS_PER_SUMMON; ++i)
                        {
                            Position pos;
                            pos.RelocatePolar(frand(0, M_PI * 2), frand(0.0f, SUMMON_RADIUS));
                            pos.Add(Center);

                            DoSummon(NPC_TWISTER, pos)->GetMotionMaster()->MoveRandom(20.0f);
                        }

                        events.ScheduleEvent(EVENT_TWISTING_WINDS, TIMER_TWISTING_WINDS);
                    }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* Creature) const
    {
        return new boss_altairusAI(Creature);
    }
};

struct inSafeZone
{
    bool operator()(WorldObject *obj)
    {
        return obj->ToUnit() && obj->ToUnit()->HasAura(SPELL_SAFE_ZONE);
    }
};

class spell_altairus_lightning_blast : public SpellScriptLoader
{
public:
    spell_altairus_lightning_blast() : SpellScriptLoader("spell_altairus_lightning_blast") { }

    class spell_altairus_lightning_blastSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_altairus_lightning_blastSpellScript);

        void FilterTargets(std::list<WorldObject*> &targets)
        {
            targets.remove_if(inSafeZone());
        }

        void HandleDummy(SpellEffIndex)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_LIGHTNING_BLAST_DAMAGE, true);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_altairus_lightning_blastSpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_altairus_lightning_blastSpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_altairus_lightning_blastSpellScript();
    }
};

class spell_call_the_wind : public SpellScriptLoader
{
public:
    spell_call_the_wind() : SpellScriptLoader("spell_call_the_wind") { }

    class spell_call_the_windSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_call_the_windSpellScript);

        void FilterTargets(std::list<WorldObject*> &targets)
        {
            Trinity::Containers::RandomResizeList(targets, 1);
        }

        void HandleDummy(SpellEffIndex)
        {
            std::list<Creature*> targets;
            GetCreatureListWithEntryInGrid(targets, GetCaster(), NPC_AIR_CURRENT, 150.0f);
            for (std::list<Creature*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                (*itr)->RemoveAura(SPELL_CALL_THE_WIND_PERIODIC);

            GetHitUnit()->CastSpell(GetHitUnit(), SPELL_CALL_THE_WIND_PERIODIC);
            uint64 guid = GetCaster()->GetInstanceScript()->GetData64(NPC_SAFE_ZONE);
            Creature *safe_zone = ObjectAccessor::GetCreature(*GetCaster(), guid);
            safe_zone->CastWithDelay(TIMER_DELAY_VISUAL, GetHitUnit(), SPELL_CALL_WINDS_VISUAL, false);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_call_the_windSpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_call_the_windSpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_call_the_windSpellScript();
    }
};

class spell_upwind_of_altairus : public SpellScriptLoader
{
public:
    spell_upwind_of_altairus() : SpellScriptLoader("spell_upwind_of_altairus") { }

    class spell_upwind_of_altairusSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_upwind_of_altairusSpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            float altairus_dist = GetCaster()->GetExactDist2d(ObjectAccessor::GetUnit(*GetCaster(), GetCaster()->GetInstanceScript()->GetData64(BOSS_ALTAIRUS)));

            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
            {
                if (GetCaster()->GetExactDist2d(*itr) > altairus_dist)
                {
                    if (Unit *neg_target = (*itr)->ToUnit())
                    {
                        neg_target->RemoveAura(SPELL_UPWIND_OF_ALTAIRUS);
                        neg_target->CastSpell(neg_target, SPELL_DOWNWIND_OF_ALTAIRUS, true);
                    }

                    targets.erase(itr++);
                }
                else
                {
                    if (Unit *unit = (*itr)->ToUnit())
                        unit->RemoveAura(SPELL_DOWNWIND_OF_ALTAIRUS);

                    _targets.push_back(*itr);
                    ++itr;
                }
            }
        }

        void FillTargets(std::list<WorldObject*>& targets)
        {
            targets.clear();
            targets.merge(_targets);
        }

        std::list<WorldObject*> _targets;

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_upwind_of_altairusSpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_upwind_of_altairusSpellScript::FillTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_upwind_of_altairusSpellScript();
    }
};

void AddSC_boss_altairus()
{
    new boss_altairus;
    new spell_altairus_lightning_blast;
    new spell_call_the_wind;
    new spell_upwind_of_altairus;
}