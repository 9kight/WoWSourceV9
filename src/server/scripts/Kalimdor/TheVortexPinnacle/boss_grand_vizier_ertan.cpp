/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Cell.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "the_vortex_pinnacle.h"

/*
 * #TODO
 * - add code for cyclones
 * - fix target selection for Storm's Edge
 * - add DB sniffs
 */

enum GrandVizierErtan
{
    // Spells
    SPELL_CYCLONE_SHIELD            = 86292,
    SPELL_STORMS_EDGE               = 86295,
    SPELL_STORMS_EDGE_KNOCKBACK     = 86310,
    SPELL_STORMS_EDGE_DAMAGE        = 86309,
    SPELL_LIGHTNING_BOLT            = 86331,
    SPELL_SUMMON_TEMPEST            = 86340,
    SPELL_VORTEX_VISUAL             = 86267,

    // NPCs
    NPC_CYCLONE                     = 46007,

    // Events
    EVENT_LIGHTNING_BOLT            = 1,
    EVENT_SUMMON_TEMPEST            = 2,
    EVENT_CYCLONE_SHIELD            = 3,

    // Texts
    SAY_AGGRO                       = 1,
    SAY_DEATH                       = 2,
    SAY_KILL                        = 3,

    // Misc
    ACTION_CYCLONE_SHIELD           = 1,
};

class boss_grand_vizier_ertan : public CreatureScript
{
    public:
        boss_grand_vizier_ertan() : CreatureScript("boss_grand_vizier_ertan")
        {
        }

        struct boss_grand_vizier_ertanAI : public BossAI
        {
            boss_grand_vizier_ertanAI(Creature* creature) : BossAI(creature, BOSS_GRAND_VIZIER_ERTAN)
            {
            }

            std::list<Creature*> vortexList;
            bool cycloneShield;

            void Reset()
            {
                _Reset();
                events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 2000);
                events.ScheduleEvent(EVENT_CYCLONE_SHIELD, 12000);
                //if (IsHeroic())
                //    events.ScheduleEvent(EVENT_SUMMON_TEMPEST, 10000);
                cycloneShield = false;
                me->RemoveAurasDueToSpell(SPELL_STORMS_EDGE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                if (!vortexList.empty())
                    for (std::list<Creature*>::const_iterator itr = vortexList.begin(); itr != vortexList.end(); ++itr)
                    {
                        if (Creature* vortex = *itr)
                        {
                            vortex->RemoveAllAuras();
                            RelocateVortex(vortex);
                            vortex->GetMotionMaster()->ResetMovement(false);
                        }
                        if (instance)
                         {
                        instance->SetData(DATA_GRAND_VIZIER_ERTAN, NOT_STARTED);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_RESET_COMBAT_RES_LIMIT, me);
                          }
                      }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                me->CastSpell(me, SPELL_STORMS_EDGE, true);
                Talk(SAY_AGGRO);
                instance->SetData(DATA_GRAND_VIZIER_ERTAN, IN_PROGRESS);
                GetCreatureListWithEntryInGrid(vortexList, me, NPC_CYCLONE, 200.0f);
                for (std::list<Creature*>::const_iterator itr = vortexList.begin(); itr != vortexList.end(); ++itr)
                {
                    if (Creature* vortex = *itr)
                    {
                        RelocateVortex(vortex);
                        vortex->CastSpell(vortex, SPELL_VORTEX_VISUAL, true);
                        vortex->GetMotionMaster()->Initialize();
                        vortex->GetMotionMaster()->MovePath(vortex->GetDBTableGUIDLow() * 10, true);
                    }
                    if (instance)
                     {
                        instance->SetData(DATA_GRAND_VIZIER_ERTAN, IN_PROGRESS);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_SET_COMBAT_RES_LIMIT, me);
                         }
                      }
            }

            void RelocateVortex(Creature* vortex)
            {
                Position homePos = vortex->GetHomePosition();
                vortex->Relocate(homePos);
//                vortex->SendMonsterMove(homePos.GetPositionX(), homePos.GetPositionY(), homePos.GetPositionZ(), 0);
                vortex->NearTeleportTo(homePos);
            }

            void KilledUnit(Unit* who)
            {
                if (who && who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void JustDied(Unit* /*who*/)
            {
                Talk(SAY_DEATH);
                _JustDied();
                instance->SetData(DATA_GRAND_VIZIER_ERTAN, DONE);

                if (!vortexList.empty())
                    for (std::list<Creature*>::const_iterator itr = vortexList.begin(); itr != vortexList.end(); ++itr)
                    {
                        if (Creature* vortex = *itr)
                        {
                            vortex->RemoveAllAuras();
                            RelocateVortex(vortex);
                            vortex->GetMotionMaster()->ResetMovement(false);
                        }
                 if (instance)
                  {
                instance->SetData(DATA_GRAND_VIZIER_ERTAN, IN_PROGRESS);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_SET_COMBAT_RES_LIMIT, me);
                    }
                }
            Creature * Slipstream = me->SummonCreature(NPC_SLIPSTREAM, -765.79f, -44.01f, 641.91f, 4.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            Slipstream->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_CYCLONE_SHIELD:
                        cycloneShield = false;
                        break;
                    default:
                        break;
                }
            }

            void CycloneShield()
            {
                me->InterruptNonMeleeSpells(false);
                me->CastSpell(me, SPELL_STORMS_EDGE_KNOCKBACK, true);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (cycloneShield)
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_LIGHTNING_BOLT:
                            DoCastVictim(SPELL_LIGHTNING_BOLT);
                            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 2000);
                            break;
                        case EVENT_SUMMON_TEMPEST:
                            me->CastSpell(me, SPELL_SUMMON_TEMPEST, true);
                            events.ScheduleEvent(EVENT_SUMMON_TEMPEST, urand(30000, 40000));
                            break;
                        case EVENT_CYCLONE_SHIELD:
                            cycloneShield = true;
                            CycloneShield();
                            events.ScheduleEvent(EVENT_CYCLONE_SHIELD, 30000);
                            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 2000);
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetVortexPinnacleAI<boss_grand_vizier_ertanAI>(creature);
        }
};

class spell_ertan_storms_edge : public SpellScriptLoader
{
public:
    spell_ertan_storms_edge() : SpellScriptLoader("spell_ertan_storms_edge")
    {
    }

    class StormsEdgeCheck
    {
        Unit const* _caster;

    public:
        StormsEdgeCheck(Unit* caster) : _caster(caster)
        {
        }

        bool operator() (WorldObject* target)
        {
            if (target->IsInRange(_caster, 0.0f, 23.0f, true))
                return true;

            return false;
        }
    };

    class spell_ertan_storms_edge_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ertan_storms_edge_SpellScript);

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            if (Unit* caster = GetCaster())
                unitList.remove_if(StormsEdgeCheck(caster));
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Unit *target = GetHitUnit())
            {
                if (target->GetTypeId() == TYPEID_PLAYER || target->isPet() || target->isTotem())
                    if (Creature *c =  GetHitUnit()->FindNearestCreature(NPC_CYCLONE, 100, true))
                        c->CastSpell(GetHitUnit(), SPELL_STORMS_EDGE_DAMAGE, true);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ertan_storms_edge_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_ertan_storms_edge_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_ertan_storms_edge_SpellScript();
    }
};

class spell_ertan_storms_edge_triggered : public SpellScriptLoader
{
    public:
        spell_ertan_storms_edge_triggered() : SpellScriptLoader("spell_ertan_storms_edge_triggered")
        {
        }

        class spell_ertan_storms_edge_triggered_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ertan_storms_edge_triggered_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_ertan_storms_edge_triggered_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ertan_storms_edge_triggered_SpellScript();
        }
};

class spell_ertan_storms_edge_knockback : public SpellScriptLoader
{
    public:
        spell_ertan_storms_edge_knockback() : SpellScriptLoader("spell_ertan_storms_edge_knockback")
        {
        }

        class spell_ertan_storms_edge_knockback_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ertan_storms_edge_knockback_AuraScript);

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* Ertan = GetCaster()->ToCreature())
                    Ertan->AI()->DoAction(ACTION_CYCLONE_SHIELD);
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_ertan_storms_edge_knockback_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_ertan_storms_edge_knockback_AuraScript();
        }
};

void AddSC_boss_grand_vizier_ertan()
{
    new boss_grand_vizier_ertan();
    new spell_ertan_storms_edge();
    new spell_ertan_storms_edge_triggered();
    new spell_ertan_storms_edge_knockback();
};
