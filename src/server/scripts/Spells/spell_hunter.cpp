/*
* Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/*
* Scripts for spells with SPELLFAMILY_HUNTER, SPELLFAMILY_PET and SPELLFAMILY_GENERIC spells used by hunter players.
* Ordered alphabetically using scriptname.
* Scriptnames of files in this file should be prefixed with "spell_hun_".
*/

#include "Pet.h"
#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum HunterSpells
{
	SPELL_HUNTER_BESTIAL_WRATH = 19574,
	SPELL_HUNTER_INVIGORATION_TRIGGERED = 53398,
	SPELL_HUNTER_MASTERS_CALL_TRIGGERED = 62305,
	SPELL_HUNTER_MISDIRECTION_PROC = 35079,
	SPELL_HUNTER_PET_LAST_STAND_TRIGGERED = 53479,
	SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX = 55709,
	SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED = 54114,
	SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF = 55711,
	SPELL_HUNTER_PET_CARRION_FEEDER_TRIGGERED = 54045,
	SPELL_HUNTER_READINESS = 23989,
	SPELL_HUNTER_SNIPER_TRAINING_R1 = 53302,
	SPELL_HUNTER_SNIPER_TRAINING_BUFF_R1 = 64418,
	SPELL_DRAENEI_GIFT_OF_THE_NAARU = 59543,
	SPELL_HUNTER_KILL_COMMAND_CRIT_10 = 60110,
	SPELL_HUNTER_KILL_COMMAND_CRIT_20 = 60113,
	SPELL_HUNTER_FOCUSED_FIRE_1 = 35029,
	SPELL_HUNTER_FOCUSED_FIRE_2 = 35030,
	SPELL_HUNTER_FOCUS_ENERGIZE = 82716,
	SPELL_HUNTER_GLYPH_OF_SILENCING_SHOT = 56836,
	SPELL_HUNTER_GLYPH_KILL_SHOT = 63067,
	SPELL_HUNTER_GLYPH_KILL_SHOT_CD = 90967,
	SPELL_HUNTER_KILL_SHOT = 53351
};

enum HunterPetCalculate
{
	SPELL_TAMED_PET_PASSIVE_06 = 19591,
	SPELL_TAMED_PET_PASSIVE_07 = 20784,
	SPELL_TAMED_PET_PASSIVE_08 = 34666,
	SPELL_TAMED_PET_PASSIVE_09 = 34667,
	SPELL_TAMED_PET_PASSIVE_10 = 34675,
	SPELL_HUNTER_PET_SCALING_01 = 34902,
	SPELL_HUNTER_PET_SCALING_02 = 34903,
	SPELL_HUNTER_PET_SCALING_03 = 34904,
	SPELL_HUNTER_PET_SCALING_04 = 61017,
	SPELL_HUNTER_PET_SCALING_05 = 89446
};

enum HunterPetTreeSpecializationMarker
{
	SPELL_HUNTER_PET_FEROCITY_MARKER = 87887,
	SPELL_HUNTER_PET_TENACITY_MARKER = 87891,
	SPELL_HUNTER_PET_CUNNING_MARKER = 87884
};

// 53209 - Chimera Shot
class spell_hun_chimera_shot : public SpellScriptLoader
{
public:
	spell_hun_chimera_shot() : SpellScriptLoader("spell_hun_chimera_shot") { }

	class spell_hun_chimera_shot_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_chimera_shot_SpellScript);

		void HandleScriptEffect(SpellEffIndex /*effIndex*/)
		{
			Unit* caster = GetCaster();
			if (Unit* unitTarget = GetHitUnit())
			{
				// Chimera shot heal
				caster->CastSpell(caster, 53353, true);
				// Refresh serpent sting
				if (Aura* aura = unitTarget->GetAura(1978, caster->GetGUID()))
					aura->RefreshDuration();
			}
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(spell_hun_chimera_shot_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_chimera_shot_SpellScript();
	}
};

// 1978 - serpent sting
class spell_hun_serpent_sting : public SpellScriptLoader
{
public:
	spell_hun_serpent_sting() : SpellScriptLoader("spell_hun_serpent_sting") { }

	class spell_hun_serpent_sting_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_serpent_sting_SpellScript);

		void HandleAfterHit()
		{
			Unit* caster = GetCaster();
			if (Unit* unitTarget = GetHitUnit())
			{
				if (AuraEffect* impSerpent = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, 536, EFFECT_0))
				{
					if (AuraEffect* aurEff = unitTarget->GetAuraEffect(1978, EFFECT_0, caster->GetGUID()))
					{
						Aura* aura = aurEff->GetBase();
						int32 TickCount = aurEff->GetTotalTicks();
						int32 bp0 = aurEff->GetAmount();
						ApplyPct(bp0, TickCount * impSerpent->GetAmount());
						bp0 = unitTarget->SpellDamageBonusTaken(aura->GetSpellInfo(), bp0, DOT, aura->GetStackAmount(), caster->GetGUID());
						caster->CastCustomSpell(unitTarget, 83077, &bp0, NULL, NULL, true);
					}
				}
			}
		}

		void Register()
		{
			AfterHit += SpellHitFn(spell_hun_serpent_sting_SpellScript::HandleAfterHit);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_serpent_sting_SpellScript();
	}
};


// 781 - Disengage
class spell_hun_disengage : public SpellScriptLoader
{
public:
	spell_hun_disengage() : SpellScriptLoader("spell_hun_disengage") { }

	class spell_hun_disengage_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_disengage_SpellScript);

		SpellCastResult CheckCast()
		{
			Unit* caster = GetCaster();
			if (caster->GetTypeId() == TYPEID_PLAYER && !caster->isInCombat())
				return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

			return SPELL_CAST_OK;
		}

		void HandlePostHaste(SpellEffIndex /*effIndex*/)
		{
			Unit* target = GetHitUnit();
			if (AuraEffect* postHaste = target->GetDummyAuraEffect(SPELLFAMILY_HUNTER, 5094, EFFECT_1))
			{
				int32 bp0 = postHaste->GetAmount();
				target->CastCustomSpell(target, 83559, &bp0, NULL, NULL, true);
			}
		}

		void Register()
		{
			OnCheckCast += SpellCheckCastFn(spell_hun_disengage_SpellScript::CheckCast);
			OnEffectHitTarget += SpellEffectFn(spell_hun_disengage_SpellScript::HandlePostHaste, EFFECT_0, SPELL_EFFECT_LEAP_BACK);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_disengage_SpellScript();
	}
};

// 53412 - Invigoration
class spell_hun_invigoration : public SpellScriptLoader
{
public:
	spell_hun_invigoration() : SpellScriptLoader("spell_hun_invigoration") { }

	class spell_hun_invigoration_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_invigoration_SpellScript);

		bool Validate(SpellInfo const* /*spellInfo*/)
		{
			if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_INVIGORATION_TRIGGERED))
				return false;
			return true;
		}

		void HandleScriptEffect(SpellEffIndex /*effIndex*/)
		{
			if (Unit* unitTarget = GetHitUnit())
				if (AuraEffect* aurEff = unitTarget->GetDummyAuraEffect(SPELLFAMILY_HUNTER, 3487, 0))
					if (roll_chance_i(aurEff->GetAmount()))
						unitTarget->CastSpell(unitTarget, SPELL_HUNTER_INVIGORATION_TRIGGERED, true);
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(spell_hun_invigoration_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_invigoration_SpellScript();
	}
};

// 53478 - Last Stand Pet
class spell_hun_last_stand_pet : public SpellScriptLoader
{
public:
	spell_hun_last_stand_pet() : SpellScriptLoader("spell_hun_last_stand_pet") { }

	class spell_hun_last_stand_pet_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_last_stand_pet_SpellScript);

		bool Validate(SpellInfo const* /*spellInfo*/)
		{
			if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_PET_LAST_STAND_TRIGGERED))
				return false;
			return true;
		}

		void HandleDummy(SpellEffIndex /*effIndex*/)
		{
			Unit* caster = GetCaster();
			int32 healthModSpellBasePoints0 = int32(caster->CountPctFromMaxHealth(30));
			caster->CastCustomSpell(caster, SPELL_HUNTER_PET_LAST_STAND_TRIGGERED, &healthModSpellBasePoints0, NULL, NULL, true, NULL);
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(spell_hun_last_stand_pet_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_last_stand_pet_SpellScript();
	}
};

// 53271 - Masters Call
class spell_hun_masters_call : public SpellScriptLoader
{
public:
	spell_hun_masters_call() : SpellScriptLoader("spell_hun_masters_call") { }

	class spell_hun_masters_call_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_masters_call_SpellScript);

		SpellCastResult CheckCast()
		{
			Player* caster = GetCaster()->ToPlayer();
			if (caster && caster->GetPet() && caster->GetPet()->HasUnitState(UNIT_STATE_CONTROLLED))
				return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

			return SPELL_CAST_OK;
		}

		void HandleDummy(SpellEffIndex /*effIndex*/)
		{
			if (Unit* ally = GetHitUnit())
				if (Player* caster = GetCaster()->ToPlayer())
					if (Pet* target = caster->GetPet())
					{
						TriggerCastFlags castMask = TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_CASTER_AURASTATE);
						target->CastSpell(ally, GetEffectValue(), castMask);
					}
		}

		void HandleScriptEffect(SpellEffIndex /*effIndex*/)
		{
			if (Unit* target = GetHitUnit())
			{
				// Cannot be processed while pet is dead
				TriggerCastFlags castMask = TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_CASTER_AURASTATE);
				target->CastSpell(target, SPELL_HUNTER_MASTERS_CALL_TRIGGERED, castMask);
			}
		}

		void Register()
		{
			OnCheckCast += SpellCheckCastFn(spell_hun_masters_call_SpellScript::CheckCast);
			OnEffectHitTarget += SpellEffectFn(spell_hun_masters_call_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
			OnEffectLaunchTarget += SpellEffectFn(spell_hun_masters_call_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_masters_call_SpellScript();
	}
};

// 34477 - Misdirection
class spell_hun_misdirection : public SpellScriptLoader
{
public:
	spell_hun_misdirection() : SpellScriptLoader("spell_hun_misdirection") { }

	class spell_hun_misdirection_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_misdirection_AuraScript);

		bool Validate(SpellInfo const* /*spellInfo*/)
		{
			if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_MISDIRECTION_PROC))
				return false;
			return true;
		}

		void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
		{
			if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEFAULT)
				GetTarget()->ResetRedirectThreat();
		}

		bool CheckProc(ProcEventInfo& /*eventInfo*/)
		{
			return GetTarget()->GetRedirectThreatTarget();
		}

		void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
		{
			PreventDefaultAction();
			GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_MISDIRECTION_PROC, true, NULL, aurEff);
		}

		void Register()
		{
			AfterEffectRemove += AuraEffectRemoveFn(spell_hun_misdirection_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
			DoCheckProc += AuraCheckProcFn(spell_hun_misdirection_AuraScript::CheckProc);
			OnEffectProc += AuraEffectProcFn(spell_hun_misdirection_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_misdirection_AuraScript();
	}
};

// 35079 - Misdirection (Proc)
class spell_hun_misdirection_proc : public SpellScriptLoader
{
public:
	spell_hun_misdirection_proc() : SpellScriptLoader("spell_hun_misdirection_proc") { }

	class spell_hun_misdirection_proc_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_misdirection_proc_AuraScript);

		void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
		{
			GetTarget()->ResetRedirectThreat();
		}

		void Register()
		{
			AfterEffectRemove += AuraEffectRemoveFn(spell_hun_misdirection_proc_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_misdirection_proc_AuraScript();
	}
};

// 54044 - Pet Carrion Feeder
class spell_hun_pet_carrion_feeder : public SpellScriptLoader
{
public:
	spell_hun_pet_carrion_feeder() : SpellScriptLoader("spell_hun_pet_carrion_feeder") { }

	class spell_hun_pet_carrion_feeder_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_pet_carrion_feeder_SpellScript);

		bool Load()
		{
			if (!GetCaster()->isPet())
				return false;
			return true;
		}

		bool Validate(SpellInfo const* /*spellInfo*/)
		{
			if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_PET_CARRION_FEEDER_TRIGGERED))
				return false;
			return true;
		}

		SpellCastResult CheckIfCorpseNear()
		{
			Unit* caster = GetCaster();
			float max_range = GetSpellInfo()->GetMaxRange(false);
			WorldObject* result = NULL;
			// search for nearby enemy corpse in range
			Trinity::AnyDeadUnitSpellTargetInRangeCheck check(caster, max_range, GetSpellInfo(), TARGET_CHECK_ENEMY);
			Trinity::WorldObjectSearcher<Trinity::AnyDeadUnitSpellTargetInRangeCheck> searcher(caster, result, check);
			caster->GetMap()->VisitFirstFound(caster->m_positionX, caster->m_positionY, max_range, searcher);
			if (!result)
				return SPELL_FAILED_NO_EDIBLE_CORPSES;
			return SPELL_CAST_OK;
		}

		void HandleDummy(SpellEffIndex /*effIndex*/)
		{
			Unit* caster = GetCaster();
			caster->CastSpell(caster, SPELL_HUNTER_PET_CARRION_FEEDER_TRIGGERED, false);
		}

		void Register()
		{
			OnEffectHit += SpellEffectFn(spell_hun_pet_carrion_feeder_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
			OnCheckCast += SpellCheckCastFn(spell_hun_pet_carrion_feeder_SpellScript::CheckIfCorpseNear);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_pet_carrion_feeder_SpellScript();
	}
};

// 55709 - Pet Heart of the Phoenix
class spell_hun_pet_heart_of_the_phoenix : public SpellScriptLoader
{
public:
	spell_hun_pet_heart_of_the_phoenix() : SpellScriptLoader("spell_hun_pet_heart_of_the_phoenix") { }

	class spell_hun_pet_heart_of_the_phoenix_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_pet_heart_of_the_phoenix_SpellScript);

		bool Load()
		{
			if (!GetCaster()->isPet())
				return false;
			return true;
		}

		bool Validate(SpellInfo const* /*spellInfo*/)
		{
			if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED) || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
				return false;
			return true;
		}

		void HandleScript(SpellEffIndex /*effIndex*/)
		{
			Unit* caster = GetCaster();
			if (Unit* owner = caster->GetOwner())
				if (!caster->HasAura(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
				{
					owner->CastCustomSpell(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED, SPELLVALUE_BASE_POINT0, 100, caster, true);
					caster->CastSpell(caster, SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF, true);
				}
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(spell_hun_pet_heart_of_the_phoenix_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_pet_heart_of_the_phoenix_SpellScript();
	}
};

// 23989 - Readiness
class spell_hun_readiness : public SpellScriptLoader
{
public:
	spell_hun_readiness() : SpellScriptLoader("spell_hun_readiness") { }

	class spell_hun_readiness_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_readiness_SpellScript);

		bool Load()
		{
			return GetCaster()->GetTypeId() == TYPEID_PLAYER;
		}

		void HandleDummy(SpellEffIndex /*effIndex*/)
		{
			Player* caster = GetCaster()->ToPlayer();
			// immediately finishes the cooldown on your other Hunter abilities except Bestial Wrath
			const SpellCooldowns& cm = caster->ToPlayer()->GetSpellCooldownMap();
			for (SpellCooldowns::const_iterator itr = cm.begin(); itr != cm.end();)
			{
				SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first);

				///! If spellId in cooldown map isn't valid, the above will return a null pointer.
				if (spellInfo &&
					spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER &&
					spellInfo->Id != SPELL_HUNTER_READINESS &&
					spellInfo->Id != SPELL_HUNTER_BESTIAL_WRATH &&
					spellInfo->Id != SPELL_DRAENEI_GIFT_OF_THE_NAARU &&
					spellInfo->GetRecoveryTime() > 0)
					caster->RemoveSpellCooldown((itr++)->first, true);
				else
					++itr;
			}
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(spell_hun_readiness_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_readiness_SpellScript();
	}
};

// 37506 - Scatter Shot
class spell_hun_scatter_shot : public SpellScriptLoader
{
public:
	spell_hun_scatter_shot() : SpellScriptLoader("spell_hun_scatter_shot") { }

	class spell_hun_scatter_shot_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_scatter_shot_SpellScript);

		bool Load()
		{
			return GetCaster()->GetTypeId() == TYPEID_PLAYER;
		}

		void HandleDummy(SpellEffIndex /*effIndex*/)
		{
			Player* caster = GetCaster()->ToPlayer();
			// break Auto Shot and autohit
			caster->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
			caster->AttackStop();
			caster->SendAttackSwingCancelAttack();
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(spell_hun_scatter_shot_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_scatter_shot_SpellScript();
	}
};

// -53302 - Sniper Training
class spell_hun_sniper_training : public SpellScriptLoader
{
public:
	spell_hun_sniper_training() : SpellScriptLoader("spell_hun_sniper_training") { }

	class spell_hun_sniper_training_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_sniper_training_AuraScript);

		bool Validate(SpellInfo const* /*spellInfo*/)
		{
			if (!sSpellMgr->GetSpellInfo(SPELL_HUNTER_SNIPER_TRAINING_R1) || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_SNIPER_TRAINING_BUFF_R1))
				return false;
			return true;
		}

		void HandlePeriodic(AuraEffect const* aurEff)
		{
			PreventDefaultAction();
			if (aurEff->GetAmount() <= 0)
			{
				Unit* caster = GetCaster();
				uint32 spellId = SPELL_HUNTER_SNIPER_TRAINING_BUFF_R1 + GetId() - SPELL_HUNTER_SNIPER_TRAINING_R1;
				if (Unit* target = GetTarget())
					if (!target->HasAura(spellId))
					{
						SpellInfo const* triggeredSpellInfo = sSpellMgr->GetSpellInfo(spellId);
						Unit* triggerCaster = triggeredSpellInfo->NeedsToBeTriggeredByCaster() ? caster : target;
						triggerCaster->CastSpell(target, triggeredSpellInfo, true, 0, aurEff);
					}
			}
		}

		void HandleUpdatePeriodic(AuraEffect* aurEff)
		{
			if (Player* playerTarget = GetUnitOwner()->ToPlayer())
			{
				int32 baseAmount = aurEff->GetBaseAmount();
				int32 amount = playerTarget->isMoving() ?
					playerTarget->CalculateSpellDamage(playerTarget, GetSpellInfo(), aurEff->GetEffIndex(), &baseAmount) :
					aurEff->GetAmount() - 1;
				aurEff->SetAmount(amount);
			}
		}

		void Register()
		{
			OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_sniper_training_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
			OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_hun_sniper_training_AuraScript::HandleUpdatePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_sniper_training_AuraScript();
	}
};

// 1515 - Tame Beast
class spell_hun_tame_beast : public SpellScriptLoader
{
public:
	spell_hun_tame_beast() : SpellScriptLoader("spell_hun_tame_beast") { }

	class spell_hun_tame_beast_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_tame_beast_SpellScript);

		SpellCastResult CheckCast()
		{
			Unit* caster = GetCaster();
			if (caster->GetTypeId() != TYPEID_PLAYER)
				return SPELL_FAILED_DONT_REPORT;

			if (!GetExplTargetUnit())
				return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

			if (Creature* target = GetExplTargetUnit()->ToCreature())
			{
				if (target->getLevel() > caster->getLevel())
					return SPELL_FAILED_HIGHLEVEL;

				// use SMSG_PET_TAME_FAILURE?
				if (!target->GetCreatureTemplate()->isTameable(caster->ToPlayer()->CanTameExoticPets()))
					return SPELL_FAILED_BAD_TARGETS;

				if (caster->GetPetGUID())
					return SPELL_FAILED_ALREADY_HAVE_SUMMON;

				if (caster->GetCharmGUID())
					return SPELL_FAILED_ALREADY_HAVE_CHARM;
			}
			else
				return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

			return SPELL_CAST_OK;
		}

		void Register()
		{
			OnCheckCast += SpellCheckCastFn(spell_hun_tame_beast_SpellScript::CheckCast);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_tame_beast_SpellScript();
	}
};

// -24604 - Furious Howl
//  53434 - Call of the Wild
class spell_hun_target_only_pet_and_owner : public SpellScriptLoader
{
public:
	spell_hun_target_only_pet_and_owner() : SpellScriptLoader("spell_hun_target_only_pet_and_owner") { }

	class spell_hun_target_only_pet_and_owner_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_target_only_pet_and_owner_SpellScript);

		void FilterTargets(std::list<WorldObject*>& targets)
		{
			targets.clear();
			targets.push_back(GetCaster());
			if (Unit* owner = GetCaster()->GetOwner())
				targets.push_back(owner);
		}

		void Register()
		{
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hun_target_only_pet_and_owner_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hun_target_only_pet_and_owner_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_PARTY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_target_only_pet_and_owner_SpellScript();
	}
};

// Intervene
class spell_hun_intervene : public SpellScriptLoader
{
public:
	spell_hun_intervene() : SpellScriptLoader("spell_hun_intervene") { }

	class spell_hun_intervene_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_intervene_AuraScript);

		void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Unit* caster = GetCaster())
				amount = caster->CountPctFromMaxHealth(amount);
		}

		void Register()
		{
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_intervene_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_intervene_AuraScript();
	}
};

// -82692 - Foucus Fire
// -82692 - Focus Fire
class spell_hun_focus_fire : public SpellScriptLoader
{
public:
	spell_hun_focus_fire() : SpellScriptLoader("spell_hun_focus_fire") { }

	// SpellScript
	class spell_hun_focus_fire_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_focus_fire_SpellScript)

			bool Validate(SpellInfo const* /*spellEntry*/)
		{
			if (!sSpellMgr->GetSpellInfo(82692))
				return false;
			return true;
		}

		SpellCastResult CheckPetFrenzy()
		{
			Unit * pet = GetCaster()->GetGuardianPet();
			if (!pet)
				return SPELL_FAILED_NO_PET;

			if (pet->HasAura(19615))
				return SPELL_CAST_OK;
			else
				return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
		}

		void Register()
		{
			OnCheckCast += SpellCheckCastFn(spell_hun_focus_fire_SpellScript::CheckPetFrenzy);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_focus_fire_SpellScript();
	}

	// AuraScript

	class spell_hun_focus_fire_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_focus_fire_AuraScript);

		bool Load()
		{
			return GetCaster()->GetTypeId() == TYPEID_PLAYER;
		}

		void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Pet* pet = GetCaster()->ToPlayer()->GetPet())
				if (Aura* aur = pet->GetAura(19615, pet->GetGUID()))
					amount *= aur->GetStackAmount();
		}

		void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
		{
			int32 basepoints0 = aurEff->GetAmount();
			if (Pet* pet = GetCaster()->ToPlayer()->GetPet())
				if (Aura* aur = pet->GetAura(19615, pet->GetGUID()))
				{
					basepoints0 *= aur->GetStackAmount();
					GetCaster()->CastCustomSpell(pet, 83468, &basepoints0, NULL, NULL, true);
					aur->Remove();
				}
		}

		void Register()
		{
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_focus_fire_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_RANGED_HASTE);
			AfterEffectApply += AuraEffectApplyFn(spell_hun_focus_fire_AuraScript::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_focus_fire_AuraScript();
	}
};

// 56641 - Steady Shot
// 77767 - Cobra Shot
class spell_hun_energize : public SpellScriptLoader
{
public:
	spell_hun_energize() : SpellScriptLoader("spell_hun_energize") { }

	class spell_hun_energize_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_energize_SpellScript);

		void HandleOnHit()
		{
			uint32 triggeredSpell = 91954;
			SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggeredSpell);
			if (!spellInfo)
				return;

			int32 bp0 = spellInfo->Effects[EFFECT_0].BasePoints;
			Unit* caster = GetCaster();
			if (Unit* unitTarget = GetHitUnit())
			{
				// Refresh serpent sting
				if (GetSpellInfo()->Id == 77767)
					if (Aura* aura = unitTarget->GetAura(1978, GetCaster()->GetGUID()))
						aura->SetDuration(std::min(aura->GetDuration() + GetSpellInfo()->Effects[EFFECT_1].BasePoints * 1000, aura->GetMaxDuration()), false, true);

				// Termination
				if (AuraEffect* termination = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, 2008, EFFECT_0))
					if (unitTarget->GetHealthPct() <= 25.0f)
						bp0 += termination->GetAmount();

				caster->CastCustomSpell(caster, triggeredSpell, &bp0, NULL, NULL, true);
			}

		}

		void Register()
		{
			OnHit += SpellHitFn(spell_hun_energize_SpellScript::HandleOnHit);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_energize_SpellScript();
	}
};

// -83676 - Resistance is futile periodic trigger
class spell_hun_resistance_is_futile : public SpellScriptLoader
{
public:
	spell_hun_resistance_is_futile() : SpellScriptLoader("spell_hun_resistance_is_futile") { }

	class spell_hun_resistance_is_futile_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_resistance_is_futile_AuraScript);

		void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
		{
			GetUnitOwner()->GetPosition(&oldPos);
		}

		void HandleUpdatePeriodic(AuraEffect* aurEff)
		{
			if (Unit* caster = GetCaster())
			{
				Position newPos;
				GetUnitOwner()->GetPosition(&newPos);
				// Proc chance every 2 yards moved
				if (newPos.GetExactDist(&oldPos) > 2.0f)
				{
					oldPos.GetPosition(&newPos);
					if (AuraEffect* aur = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, 5119, EFFECT_0))
						if (roll_chance_i(aur->GetAmount()))
							caster->CastSpell(caster, 82897, true);
				}
			}
		}

		void Register()
		{
			OnEffectApply += AuraEffectApplyFn(spell_hun_resistance_is_futile_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
			OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_hun_resistance_is_futile_AuraScript::HandleUpdatePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
		}

		Position oldPos;
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_resistance_is_futile_AuraScript();
	}
};

// 2643 - Multi-shot
class spell_hun_serpent_spread : public SpellScriptLoader
{
public:
	spell_hun_serpent_spread() : SpellScriptLoader("spell_hun_serpent_spread") { }

	class spell_hun_serpent_spread_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_serpent_spread_SpellScript);

		void HandleOnHit()
		{
			Unit* caster = GetCaster();
			if (Unit* unitTarget = GetHitUnit())
			{
				uint32 triggeredSpell = 0;
				if (caster->HasSpell(87934))
					triggeredSpell = 88453;
				else if (caster->HasSpell(87935))
					triggeredSpell = 88466;

				if (triggeredSpell)
					caster->CastSpell(unitTarget, triggeredSpell, true);
			}
		}

		void Register()
		{
			OnHit += SpellHitFn(spell_hun_serpent_spread_SpellScript::HandleOnHit);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_serpent_spread_SpellScript();
	}
};

// 51753 - Camouflage
class spell_hun_camouflage : public SpellScriptLoader
{
public:
	spell_hun_camouflage() : SpellScriptLoader("spell_hun_camouflage") { }

	class spell_hun_camouflage_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_camouflage_SpellScript);

		void HandleDummy(SpellEffIndex /*effIndex*/)
		{
			Unit* caster = GetCaster();
			caster->CastSpell(caster, 51755, true);
			if (caster->ToPlayer())
				if (Pet* pet = caster->ToPlayer()->GetPet())
					pet->CastSpell(pet, 51755, true);
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(spell_hun_camouflage_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_camouflage_SpellScript();
	}
};

// 80326 - Camouflage periodic
class spell_hun_camouflage_periodic : public SpellScriptLoader
{
public:
	spell_hun_camouflage_periodic() : SpellScriptLoader("spell_hun_camouflage_periodic") { }

	class spell_hun_camouflage_periodic_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_camouflage_periodic_AuraScript);

		void HandlePeriodic(AuraEffect const* aurEff)
		{
			if (GetUnitOwner()->isMoving())
				PreventDefaultAction();
		}

		void Register()
		{
			OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_camouflage_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_camouflage_periodic_AuraScript();
	}
};

// Mend pet
class spell_hun_mend_pet : public SpellScriptLoader
{
public:
	spell_hun_mend_pet() : SpellScriptLoader("spell_hun_mend_pet") { }

	class spell_hun_mend_pet_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_mend_pet_AuraScript);

		void HandlePeriodic(AuraEffect const* aurEff)
		{
			if (Unit* caster = GetCaster())
				if (AuraEffect* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, 267, EFFECT_0))
					if (roll_chance_i(aurEff->GetAmount()))
						caster->CastSpell(GetTarget(), 24406, true);
		}

		void Register()
		{
			OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_mend_pet_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_mend_pet_AuraScript();
	}
};

class spell_hun_pet_damage_spells : public SpellScriptLoader
{
public:
	spell_hun_pet_damage_spells() : SpellScriptLoader("spell_hun_pet_damage_spells") { }

	class spell_hun_pet_damage_spells_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_pet_damage_spells_SpellScript);

		void HandleHit(SpellEffIndex /*effIndex*/)
		{
			Unit* caster = GetCaster();
			if (Unit* owner = caster->GetOwner())
			{
				float coeff = 1.0f;
				switch (GetSpellInfo()->Id)
				{
				case 16827: // Claw
				case 49966: // Smack
				case 17253: // Bite
					coeff = 0.2f * 0.4f;
					if (caster->GetPower(POWER_FOCUS) >= 50)
					{
						// Wild Hunt
						if (caster->HasSpell(62758))
						{
							SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(62758);
							AddPct(coeff, spellInfo->Effects[EFFECT_0].BasePoints);
						}
						else if (caster->HasSpell(62762))
						{
							SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(62762);
							AddPct(coeff, spellInfo->Effects[EFFECT_0].BasePoints);
						}
					}
					break;
				case 83381: // Kill command
					coeff = 0.516f;
					break;
				}
				int32 baseDamage = GetEffectValue() + (coeff * owner->GetTotalAttackPowerValue(RANGED_ATTACK));
				SetEffectDamage(baseDamage);
			}
		}

		void Register()
		{
			OnEffectLaunchTarget += SpellEffectFn(spell_hun_pet_damage_spells_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_pet_damage_spells_SpellScript();
	}
};

class spell_hun_pet_spirit_mend : public SpellScriptLoader
{
public:
	spell_hun_pet_spirit_mend() : SpellScriptLoader("spell_hun_pet_spirit_mend") { }

	class spell_hun_pet_spirit_mend_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_pet_spirit_mend_SpellScript);

		void HandleHeal(SpellEffIndex /*effIndex*/)
		{
			if (!GetCaster())
				return;

			if (Unit* owner = GetCaster()->GetOwner())
			{
				float coeff = 0.35f * 0.5f;
				SetEffectDamage(GetEffectValue() + (coeff * owner->GetTotalAttackPowerValue(RANGED_ATTACK)));
			}
		}

		void Register()
		{
			OnEffectLaunchTarget += SpellEffectFn(spell_hun_pet_spirit_mend_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_pet_spirit_mend_SpellScript();
	}

	class spell_hun_pet_spirit_mend_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_pet_spirit_mend_AuraScript);

		void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (!GetCaster())
				return;

			if (Unit* owner = GetCaster()->GetOwner())
			{
				float coeff = 0.35f * 0.335f;
				amount += (coeff * owner->GetTotalAttackPowerValue(RANGED_ATTACK));
			}
		}

		void Register()
		{
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_spirit_mend_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_PERIODIC_HEAL);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_pet_spirit_mend_AuraScript();
	}
};

/*PET SCALING*/
class spell_hun_pet_scaling_01 : public SpellScriptLoader
{
public:
	spell_hun_pet_scaling_01() : SpellScriptLoader("spell_hun_pet_scaling_01") { }

	class spell_hun_pet_scaling_01_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_pet_scaling_01_AuraScript);

		bool Load()
		{
			if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
				return false;
			_tempHealth = 0;
			return true;
		}

		void CalculateMaxHealthAmount(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Unit* pet = GetUnitOwner())
				if (pet->isPet())
					if (Unit* owner = pet->ToPet()->GetOwner())
					{
						float mod = 0.0f;
						if (pet->HasAura(SPELL_HUNTER_PET_FEROCITY_MARKER))
							mod = 0.67f;
						else if (pet->HasAura(SPELL_HUNTER_PET_TENACITY_MARKER))
							mod = 0.78f;
						else if (pet->HasAura(SPELL_HUNTER_PET_CUNNING_MARKER))
							mod = 0.725f;

						float ownerBonus = owner->GetStat(STAT_STAMINA) * mod * 10.0f; // convert stamina in p
						amount += ownerBonus;
					}
		}

		void ApplyEffect(AuraEffect const* /* aurEff */, AuraEffectHandleModes /*mode*/)
		{
			if (Unit* pet = GetUnitOwner())
			{
				if (_tempHealth)
					pet->SetHealth(_tempHealth);
				else
					pet->SetHealth(pet->GetMaxHealth());
			}
		}

		void RemoveEffect(AuraEffect const* /* aurEff */, AuraEffectHandleModes /*mode*/)
		{
			if (Unit* pet = GetUnitOwner())
				_tempHealth = pet->GetHealth();
		}

		void CalculateAttackPowerAmount(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Unit* pet = GetUnitOwner())
			{
				if (!pet->isPet())
					return;

				Unit* owner = pet->ToPet()->GetOwner();
				if (!owner)
					return;

				float mod = 0.425f;                                                 //Hunter contribution modifier
				float bonusAP = owner->GetTotalAttackPowerValue(RANGED_ATTACK) * mod;
				amount += bonusAP;
			}
		}

		void CalculateSpellDamageDoneAmount(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Unit* pet = GetUnitOwner())
			{
				if (!pet->isPet())
					return;

				Unit* owner = pet->ToPet()->GetOwner();
				if (!owner)
					return;

				float mod = 1.0f;                                                 //Hunter contribution modifier
				float bonusDamage = owner->GetTotalAttackPowerValue(RANGED_ATTACK) * 0.1287f * mod;
				amount += bonusDamage;
			}
		}

		void Register()
		{
			OnEffectRemove += AuraEffectRemoveFn(spell_hun_pet_scaling_01_AuraScript::RemoveEffect, EFFECT_0, SPELL_AURA_MOD_STAT, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
			AfterEffectApply += AuraEffectApplyFn(spell_hun_pet_scaling_01_AuraScript::ApplyEffect, EFFECT_0, SPELL_AURA_MOD_STAT, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_01_AuraScript::CalculateMaxHealthAmount, EFFECT_0, SPELL_AURA_MOD_MAX_HEALTH);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_01_AuraScript::CalculateAttackPowerAmount, EFFECT_1, SPELL_AURA_MOD_ATTACK_POWER);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_01_AuraScript::CalculateSpellDamageDoneAmount, EFFECT_2, SPELL_AURA_MOD_DAMAGE_DONE);
		}

	private:
		uint32 _tempHealth;
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_pet_scaling_01_AuraScript();
	}
};

class spell_hun_pet_scaling_02 : public SpellScriptLoader
{
public:
	spell_hun_pet_scaling_02() : SpellScriptLoader("spell_hun_pet_scaling_02") { }

	class spell_hun_pet_scaling_02_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_pet_scaling_02_AuraScript);

		bool Load()
		{
			if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
				return false;
			return true;
		}

		void CalculateFrostResistanceAmount(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Unit* pet = GetUnitOwner())
			{
				if (!pet->isPet())
					return;

				Unit* owner = pet->ToPet()->GetOwner();
				if (!owner)
					return;

				float ownerBonus = 0.0f;

				ownerBonus = CalculatePct(owner->GetResistance(SPELL_SCHOOL_FROST), 40);

				amount += ownerBonus;
			}
		}

		void CalculateFireResistanceAmount(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Unit* pet = GetUnitOwner())
			{
				if (!pet->isPet())
					return;

				Unit* owner = pet->ToPet()->GetOwner();
				if (!owner)
					return;

				float ownerBonus = 0.0f;

				ownerBonus = CalculatePct(owner->GetResistance(SPELL_SCHOOL_FIRE), 40);

				amount += ownerBonus;
			}
		}

		void CalculateNatureResistanceAmount(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Unit* pet = GetUnitOwner())
			{
				if (!pet->isPet())
					return;

				Unit* owner = pet->ToPet()->GetOwner();
				if (!owner)
					return;

				float ownerBonus = 0.0f;

				ownerBonus = CalculatePct(owner->GetResistance(SPELL_SCHOOL_NATURE), 40);

				amount += ownerBonus;
			}
		}

		void Register()
		{
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_02_AuraScript::CalculateFireResistanceAmount, EFFECT_0, SPELL_AURA_MOD_RESISTANCE);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_02_AuraScript::CalculateFrostResistanceAmount, EFFECT_1, SPELL_AURA_MOD_RESISTANCE);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_02_AuraScript::CalculateNatureResistanceAmount, EFFECT_2, SPELL_AURA_MOD_RESISTANCE);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_pet_scaling_02_AuraScript();
	}
};

class spell_hun_pet_scaling_03 : public SpellScriptLoader
{
public:
	spell_hun_pet_scaling_03() : SpellScriptLoader("spell_hun_pet_scaling_03") { }

	class spell_hun_pet_scaling_03_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_pet_scaling_03_AuraScript);

		bool Load()
		{
			if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
				return false;
			return true;
		}

		void CalculateShadowResistanceAmount(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Unit* pet = GetUnitOwner())
			{
				if (!pet->isPet())
					return;

				Unit* owner = pet->ToPet()->GetOwner();
				if (!owner)
					return;

				float ownerBonus = 0.0f;

				ownerBonus = CalculatePct(owner->GetResistance(SPELL_SCHOOL_SHADOW), 40);

				amount += ownerBonus;
			}
		}

		void CalculateArcaneResistanceAmount(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Unit* pet = GetUnitOwner())
			{
				if (!pet->isPet())
					return;

				Unit* owner = pet->ToPet()->GetOwner();
				if (!owner)
					return;

				float ownerBonus = 0.0f;

				ownerBonus = CalculatePct(owner->GetResistance(SPELL_SCHOOL_ARCANE), 40);

				amount += ownerBonus;
			}
		}

		void CalculateArmorAmount(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (Unit* pet = GetUnitOwner())
			{
				if (!pet->isPet())
					return;

				Unit* owner = pet->ToPet()->GetOwner();
				if (!owner)
					return;

				float ownerBonus = 0.0f;
				float pctMod = 0.0f;

				if (pet->HasAura(SPELL_HUNTER_PET_FEROCITY_MARKER))
					pctMod = 50.0f;
				else if (pet->HasAura(SPELL_HUNTER_PET_TENACITY_MARKER))
					pctMod = 60.0f;
				else if (pet->HasAura(SPELL_HUNTER_PET_CUNNING_MARKER))
					pctMod = 70.0f;

				ownerBonus = CalculatePct(owner->GetArmor(), pctMod);

				amount += ownerBonus;
			}
		}

		void Register()
		{
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_03_AuraScript::CalculateShadowResistanceAmount, EFFECT_0, SPELL_AURA_MOD_RESISTANCE);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_03_AuraScript::CalculateArcaneResistanceAmount, EFFECT_1, SPELL_AURA_MOD_RESISTANCE);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_03_AuraScript::CalculateArmorAmount, EFFECT_2, SPELL_AURA_MOD_RESISTANCE);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_pet_scaling_03_AuraScript();
	}
};

class spell_hun_pet_scaling_04 : public SpellScriptLoader
{
public:
	spell_hun_pet_scaling_04() : SpellScriptLoader("spell_hun_pet_scaling_04") { }

	class spell_hun_pet_scaling_04_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_pet_scaling_04_AuraScript);

		bool Load()
		{
			if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
				return false;
			return true;
		}

		void CalculateAmountMeleeHit(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (!GetCaster() || !GetCaster()->GetOwner())
				return;
			if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
			{
				// For others recalculate it from:
				float HitMelee = 0.0f;
				// Increase hit from SPELL_AURA_MOD_HIT_CHANCE
				HitMelee += owner->GetTotalAuraModifier(SPELL_AURA_MOD_HIT_CHANCE);
				// Increase hit melee from meele hit ratings
				HitMelee += owner->GetRatingBonusValue(CR_HIT_MELEE);

				amount += int32(HitMelee);
			}
		}

		void CalculateAmountSpellHit(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (!GetCaster() || !GetCaster()->GetOwner())
				return;
			if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
			{
				// For others recalculate it from:
				float HitSpell = 0.0f;
				// Increase hit from SPELL_AURA_MOD_SPELL_HIT_CHANCE
				HitSpell += owner->GetTotalAuraModifier(SPELL_AURA_MOD_SPELL_HIT_CHANCE);
				// Increase hit spell from spell hit ratings
				HitSpell += owner->GetRatingBonusValue(CR_HIT_SPELL);

				amount += int32(HitSpell);
			}
		}

		void CalculateAmountExpertise(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (!GetCaster() || !GetCaster()->GetOwner())
				return;
			if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
			{
				// For others recalculate it from:
				float Expertise = 0.0f;
				// Increase hit from SPELL_AURA_MOD_EXPERTISE
				Expertise += owner->GetTotalAuraModifier(SPELL_AURA_MOD_EXPERTISE);
				// Increase Expertise from Expertise ratings
				Expertise += owner->GetRatingBonusValue(CR_EXPERTISE);

				amount += int32(Expertise);
			}
		}

		void Register()
		{
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_04_AuraScript::CalculateAmountMeleeHit, EFFECT_0, SPELL_AURA_MOD_HIT_CHANCE);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_04_AuraScript::CalculateAmountSpellHit, EFFECT_1, SPELL_AURA_MOD_SPELL_HIT_CHANCE);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_04_AuraScript::CalculateAmountExpertise, EFFECT_2, SPELL_AURA_MOD_EXPERTISE);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_pet_scaling_04_AuraScript();
	}
};

class spell_hun_pet_scaling_05 : public SpellScriptLoader
{
public:
	spell_hun_pet_scaling_05() : SpellScriptLoader("spell_hun_pet_scaling_05") { }

	class spell_hun_pet_scaling_05_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_pet_scaling_05_AuraScript);

		bool Load()
		{
			if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
				return false;
			return true;
		}

		void CalculateAmountCritPct(AuraEffect const* /* aurEff */, int32& /*amount*/, bool& /*canBeRecalculated*/)
		{
		}

		void CalculateAmountHaste(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (!GetCaster() || !GetCaster()->GetOwner())
				return;
			if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
			{
				float meleeHaste = (1.0f - owner->m_modAttackSpeedPct[BASE_ATTACK]) * 100.0f;
				amount += int32(meleeHaste);
			}
		}

		void CalculateAmountResistance(AuraEffect const* /* aurEff */, int32& /*amount*/, bool& /*canBeRecalculated*/)
		{
		}

		void Register()
		{
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_05_AuraScript::CalculateAmountCritPct, EFFECT_0, SPELL_AURA_MOD_CRIT_PCT);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_05_AuraScript::CalculateAmountHaste, EFFECT_1, SPELL_AURA_MELEE_SLOW);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_scaling_05_AuraScript::CalculateAmountResistance, EFFECT_2, SPELL_AURA_MOD_TARGET_RESISTANCE);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_pet_scaling_05_AuraScript();
	}
};

class spell_hun_pet_passive_crit : public SpellScriptLoader
{
public:
	spell_hun_pet_passive_crit() : SpellScriptLoader("spell_hun_pet_passive_crit") { }

	class spell_hun_pet_passive_crit_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_pet_passive_crit_AuraScript);

		bool Load()
		{
			if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
				return false;
			return true;
		}

		void CalculateAmountCritSpell(AuraEffect const* /* aurEff */, int32& /*amount*/, bool& /*canBeRecalculated*/)
		{
		}

		void CalculateAmountCritMelee(AuraEffect const* /* aurEff */, int32& /*amount*/, bool& /*canBeRecalculated*/)
		{
		}

		void Register()
		{
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_passive_crit_AuraScript::CalculateAmountCritMelee, EFFECT_0, SPELL_AURA_MOD_WEAPON_CRIT_PERCENT);
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_passive_crit_AuraScript::CalculateAmountCritSpell, EFFECT_1, SPELL_AURA_MOD_SPELL_CRIT_CHANCE);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_pet_passive_crit_AuraScript();
	}
};

class spell_hun_pet_passive_damage_done : public SpellScriptLoader
{
public:
	spell_hun_pet_passive_damage_done() : SpellScriptLoader("spell_hun_pet_passive_damage_done") { }

	class spell_hun_pet_passive_damage_done_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_pet_passive_damage_done_AuraScript);

		bool Load()
		{
			if (!GetCaster() || !GetCaster()->GetOwner() || GetCaster()->GetOwner()->GetTypeId() != TYPEID_PLAYER)
				return false;
			return true;
		}

		void CalculateAmountDamageDone(AuraEffect const* /* aurEff */, int32& amount, bool& /*canBeRecalculated*/)
		{
			if (!GetCaster() || !GetCaster()->GetOwner())
				return;
		}

		void Register()
		{
			DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_pet_passive_damage_done_AuraScript::CalculateAmountDamageDone, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_pet_passive_damage_done_AuraScript();
	}
};

class spell_hun_pet_passive_tree_marker : public SpellScriptLoader
{
public:
	spell_hun_pet_passive_tree_marker() : SpellScriptLoader("spell_hun_pet_passive_tree_marker") { }

	class spell_hun_pet_passive_tree_marker_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_pet_passive_tree_marker_AuraScript);

		void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
		{
			if (Unit* caster = GetCaster())
			{
				if (caster->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
				{
					((Guardian*)caster)->RecalculatePetScalingStats(STAT_STAMINA);
					((Guardian*)caster)->RecalculatePetScalingResistance(SPELL_SCHOOL_NORMAL);
				}
			}
		}

		void Register()
		{
			AfterEffectApply += AuraEffectApplyFn(spell_hun_pet_passive_tree_marker_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new spell_hun_pet_passive_tree_marker_AuraScript();
	}
};
/*END PET SCALING*/

class spell_hun_kill_shot : public SpellScriptLoader
{
public:
	spell_hun_kill_shot() : SpellScriptLoader("spell_hun_kill_shot") { }

	class spell_hun_kill_shot_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_kill_shot_SpellScript);

		void HandleDamage()
		{
			Unit* caster = GetCaster();
			if (caster->GetTypeId() != TYPEID_PLAYER)
				return;

			Unit* target = GetHitUnit();
			int32 damage = GetHitDamage();
			// Glyph cooldown reset when target was failed to kill
			if (AuraEffect* glyph = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, 3676, EFFECT_0))
				if (target && target->GetHealthPct() <= glyph->GetAmount() && !caster->HasAura(90967))
					if (int32(target->GetHealth()) > damage)
					{
						caster->ToPlayer()->RemoveSpellCooldown(53351, true);
						caster->CastSpell(caster, 90967, true);
					}
		}

		void Register()
		{
			OnHit += SpellHitFn(spell_hun_kill_shot_SpellScript::HandleDamage);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_kill_shot_SpellScript();
	}
};

// Concussive shot
class spell_hun_concussive : public SpellScriptLoader
{
public:
	spell_hun_concussive() : SpellScriptLoader("spell_hun_concussive") { }

	class spell_hun_concussive_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_concussive_SpellScript);

		void HandleOnHit()
		{
			AuraEffect* glyph = GetCaster()->GetAuraEffect(56851, EFFECT_0);
			if (Aura* debuff = GetHitAura())
			{
				// Modify normalization based on glyph
				if (AuraEffect* normalization = debuff->GetEffect(EFFECT_1))
				{
					if (!glyph)
					{
						normalization->SetAmount(0);
						normalization->HandleEffect(GetHitUnit(), AURA_REMOVE_BY_DEFAULT, false);
					}
				}
			}
		}

		void Register()
		{
			OnHit += SpellHitFn(spell_hun_concussive_SpellScript::HandleOnHit);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_concussive_SpellScript();
	}
};

// 34490 - Silencing Shot
class spell_hun_silencing_shot : public SpellScriptLoader
{
public:
	spell_hun_silencing_shot() : SpellScriptLoader("spell_hun_silencing_shot") { }

	class spell_hun_silencing_shot_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_hun_silencing_shot_AuraScript);

		void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
		{
			Unit* caster = GetCaster();
			Unit* target = GetTarget();
			if (caster && target)
			{
				// Glyph of Silencing Shot energize on spell interruption
				if (caster->HasAura(SPELL_HUNTER_GLYPH_OF_SILENCING_SHOT) && target->HasUnitState(UNIT_STATE_CASTING))
				{
					// Fixed value
					int32 bp0 = 10;
					caster->CastCustomSpell(caster, SPELL_HUNTER_FOCUS_ENERGIZE, &bp0, NULL, NULL, true);
				}
			}
		}

		void Register()
		{
			OnEffectApply += AuraEffectApplyFn(spell_hun_silencing_shot_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_SILENCE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
		}
	};


	AuraScript* GetAuraScript() const
	{
		return new spell_hun_silencing_shot_AuraScript();
	}
};

// Glyph Of Kill Shot
class spell_hun_glyph_kill_shot : public SpellScriptLoader
{
public:
	spell_hun_glyph_kill_shot() : SpellScriptLoader("spell_hun_glyph_kill_shot") { }

	class spell_hun_glyph_kill_shot_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_hun_glyph_kill_shot_SpellScript);

		void HandleGlyph()
		{
			if (GetCaster()->HasAura(SPELL_HUNTER_GLYPH_KILL_SHOT) && !GetCaster()->HasAura(SPELL_HUNTER_GLYPH_KILL_SHOT_CD))
			{
				if (GetHitUnit()->GetHealthPct() <= 20 && GetHitUnit()->GetHealth() > GetHitDamage())
				{
					GetCaster()->AddAura(SPELL_HUNTER_GLYPH_KILL_SHOT_CD, GetCaster());
					GetCaster()->ToPlayer()->RemoveSpellCooldown(SPELL_HUNTER_KILL_SHOT, true);
				}
			}
		}

		void Register()
		{
			OnHit += SpellHitFn(spell_hun_glyph_kill_shot_SpellScript::HandleGlyph);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new spell_hun_glyph_kill_shot_SpellScript();
	}
};

void AddSC_hunter_spell_scripts()
{
	new spell_hun_chimera_shot();
	new spell_hun_disengage();
	new spell_hun_invigoration();
	new spell_hun_last_stand_pet();
	new spell_hun_masters_call();
	new spell_hun_misdirection();
	new spell_hun_misdirection_proc();
	new spell_hun_pet_carrion_feeder();
	new spell_hun_pet_heart_of_the_phoenix();
	new spell_hun_readiness();
	new spell_hun_scatter_shot();
	new spell_hun_sniper_training();
	new spell_hun_tame_beast();
	new spell_hun_target_only_pet_and_owner();
	new spell_hun_focus_fire();
	new spell_hun_energize();
	new spell_hun_resistance_is_futile();
	new spell_hun_serpent_sting();
	new spell_hun_serpent_spread();
	new spell_hun_camouflage_periodic();
	new spell_hun_camouflage();
	new spell_hun_pet_scaling_01();
	new spell_hun_pet_scaling_02();
	new spell_hun_pet_scaling_03();
	new spell_hun_pet_scaling_04();
	new spell_hun_pet_scaling_05();
	new spell_hun_pet_passive_crit();
	new spell_hun_pet_passive_damage_done();
	new spell_hun_pet_passive_tree_marker();
	new spell_hun_kill_shot();
	new spell_hun_concussive();
	new spell_hun_intervene();
	new spell_hun_pet_damage_spells();
	new spell_hun_pet_spirit_mend();
	new spell_hun_mend_pet();
	new spell_hun_silencing_shot();
	new spell_hun_glyph_kill_shot();
}
