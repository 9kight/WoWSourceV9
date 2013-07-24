/*
 * Copyright (C) 2011-2012 Project SkyFire <http://www.projectskyfire.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#include "ScriptPCH.h"
#include "blackrock_caverns.h"

enum eKarshYells
{
    SAY_AGGRO                   = 0,
    SAY_QUICKSILVER_ARMOR       = 1,
    SAY_KILL                    = 2,
    SAY_DEATH                   = 3,
};

enum eKarshSpells
{
    SPELL_CLEAVE                = 15284,
    SPELL_QUICKSILVER_ARMOR     = 75842,
    SPELL_QUICKSILVER_PERIODIC  = 75854,

    SPELL_HEAT_WAVE             = 75851,
    SPELL_BURNING_METAL         = 76002,
    SPELL_TRANSFORM             = 93750, // Used in spell_linked_spell
    SPELL_SUPERHEATED_ARMOR     = 75846,
    SPELL_SUPERHEATED_ARMOR_H   = 93567,

    SPELL_BOUND_FLAMES          = 93499,
    //18852 - aggro sound (?)
};

// 75854 Quicksilver Armor
class spell_karsh_quicksilver_armor : public SpellScriptLoader
{
public:
    spell_karsh_quicksilver_armor() : SpellScriptLoader("spell_karsh_quicksilver_armor") { }

    class spell_karsh_quicksilver_armor_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_karsh_quicksilver_armor_AuraScript)

        void HandleEffectPeriodicUpdate(AuraEffect* /*aurEff*/)
        {
            if (Unit * caster = GetCaster())
            {
                // If close to the lava stream, handle armor heaten / removal
                if (caster->GetDistance(237.528107f, 784.951538f, 95.670837f) < 5.5f)
                {
                    caster->RemoveAurasDueToSpell(SPELL_QUICKSILVER_ARMOR);
                    caster->CastSpell(caster, SPELL_HEAT_WAVE, true);
                    caster->CastSpell(caster, SPELL_SUPERHEATED_ARMOR, true);
                }
            }
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_QUICKSILVER_ARMOR, true);

                if (GetTarget()->GetMap()->IsHeroic())
                    for(int i = 0; i < 3; ++i)
                        GetTarget()->CastSpell(GetTarget(), SPELL_BOUND_FLAMES, true);
            }
        }

        void Register()
        {
            OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_karsh_quicksilver_armor_AuraScript::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectRemove         += AuraEffectRemoveFn(spell_karsh_quicksilver_armor_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_karsh_quicksilver_armor_AuraScript();
    }
};

class boss_karsh_steelbender: public CreatureScript
{
public:
    boss_karsh_steelbender() : CreatureScript("boss_karsh_steelbender") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_karsh_steelbenderAI (creature);
    }

    struct boss_karsh_steelbenderAI : public ScriptedAI
    {
        boss_karsh_steelbenderAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 CleaveTimer;
        uint32 DarkCommandTimer;

        void Reset()
        {
            CleaveTimer = urand(15000, 25000);
            me->CastSpell(me, SPELL_QUICKSILVER_PERIODIC, true);
            me->CastSpell(me, SPELL_QUICKSILVER_ARMOR, true);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_KILL);
        }

        void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType type)
        {
            uint32 count = me->GetAuraCount(IsHeroic() ? SPELL_SUPERHEATED_ARMOR_H : SPELL_SUPERHEATED_ARMOR);

            if (type == SPELL_DIRECT_DAMAGE && count)
            {
                damage = damage * count;
            }
            else if (type == DIRECT_DAMAGE && count)
            {
                DoCastVictim(SPELL_BURNING_METAL);
            }
        }

        void JustDied(Unit* /*Kill*/)
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(BOSS_KARSH_STEELBENDER, DONE);
        }

        void EnterCombat(Unit* /*Ent*/)
        {
            Talk(SAY_AGGRO);

            if (instance)
                instance->SetData(BOSS_KARSH_STEELBENDER, IN_PROGRESS);
        }

        void UpdateAI(uint32 Diff)
        {
            if (!UpdateVictim())
                return;

            if (CleaveTimer <= Diff)
            {
                if (me->IsNonMeleeSpellCasted(false))
                    return;

                DoCastVictim(SPELL_CLEAVE);

                CleaveTimer = urand(20000, 25000);
            }
            else
                CleaveTimer -= Diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_karsh_steelbender()
{
    new boss_karsh_steelbender();
    new spell_karsh_quicksilver_armor();
}
