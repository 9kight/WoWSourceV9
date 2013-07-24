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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "PassiveAI.h"
#include "SpellScript.h"
#include "firelands.h"

enum MiscSpell
{
    SPELL_FIEROBLAST               = 100094,
    SPELL_FIEROCLAST_BARRAGE       = 100095,
    SPELL_FIRE_CHANNELING          = 100109,

    // Misc
    SPELL_BR_NORD_BOSS_COS         = 100255,

    // Tormented Protector
    SPELL_BLAZING_STOMP            = 100156,
    SPELL_BLESSED_DEFENDER         = 100274,
    SPELL_SMOULDERING_ROOTS        = 100146
};

enum MiscEvents
{
    EVENT_FIEROBLAST               = 0,
    EVENT_FIEROCLAST_BARRAGE       = 1,
    EVENT_BLAZING_STOMP            = 2,
    EVENT_BLESSED_DEFENDER         = 3,
    EVENT_SMOULDERING_ROOTS        = 5,
    EVENT_SUMMON_TREANTS           = 6,
    EVENT_ACTION_PHASE2_0          = 7,
    EVENT_ACTION_PHASE2_1          = 8,
    EVENT_ACTION_PHASE2_2          = 9,
    EVENT_ACTION_PHASE2_3          = 10,
    EVENT_ACTION_PHASE2_4          = 11,
    EVENT_ACTION_PHASE2_5          = 12,
    EVENT_ACTION_PHASE2_6          = 13
};

enum Talk
{
    SAY_STOP                      = 0, // Phase 1 End
    SAY_HISTORY_1                 = 1,
    SAY_HISTORY_2                 = 2,
    SAY_HISTORY_3                 = 3,
    SAY_BIN_DA_WER_NOCH           = 4
};

const Position SpawnPosition[] =
{
    {455.199f, 515.552f, 244.823837f, 5.64499f}, // Volc(anus) Spawn Pos
};

class npc_harbinger_legendary : public CreatureScript
{
    struct npc_harbinger_legendaryAI : public ScriptedAI
    {
        npc_harbinger_legendaryAI(Creature* creature) : ScriptedAI(creature)
        {
           SetCombatMovement(false);
        }

        void Reset()
        {
            if (Creature* staffnordrassil = me->FindNearestCreature(NPC_BRANCH_OF_NORDRASSIL, 50.0f))
            {
                DoCast(staffnordrassil, SPELL_FIRE_CHANNELING);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            _events.ScheduleEvent(EVENT_FIEROBLAST, 1000);
            _events.ScheduleEvent(EVENT_FIEROCLAST_BARRAGE, 5000);
        }

        void UpdateAI(uint32 diff)
        {
            if(!UpdateVictim())
                return;

            _events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = _events.ExecuteEvent())
            {
                switch(eventId)
                {
               case EVENT_FIEROBLAST:
                    DoCast(SPELL_FIEROBLAST);
                    _events.ScheduleEvent(EVENT_FIEROBLAST, urand(2000, 5000));
                    break;
               case EVENT_FIEROCLAST_BARRAGE:
                    DoCast(SPELL_FIEROCLAST_BARRAGE);
                    _events.ScheduleEvent(EVENT_FIEROCLAST_BARRAGE, urand(9000, 12000));
                    break;
                }
            }
        }
        private:
            EventMap _events;
    };
public:
    npc_harbinger_legendary() : CreatureScript("npc_harbinger_legendary") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_harbinger_legendaryAI(creature);
    }
};

class npc_tormented_protector : public CreatureScript
{
    struct npc_tormented_protectorAI : public ScriptedAI
    {
        npc_tormented_protectorAI(Creature* creature) : ScriptedAI(creature)
        {
           defaultsize = creature->GetFloatValue(OBJECT_FIELD_SCALE_X);
        }

        float defaultsize;

        void Reset()
        {
        }

        void EnterCombat(Unit* /*who*/)
        {
            _events.ScheduleEvent(EVENT_BLAZING_STOMP, 15000);
            _events.ScheduleEvent(EVENT_SMOULDERING_ROOTS, 10000);
            _events.ScheduleEvent(EVENT_SUMMON_TREANTS, 40000);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who && who->GetTypeId() == TYPEID_PLAYER && me->IsValidAttackTarget(who))

            if (me->IsWithinDistInMap(who, 120.0f))
            {
                AttackStart(who);
                ScriptedAI::MoveInLineOfSight(who);
            }
        }

        void UpdateAI(uint32 diff)
        {
            if(!UpdateVictim())
                return;

            _events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = _events.ExecuteEvent())
            {
                switch(eventId)
                {
               case EVENT_BLAZING_STOMP:
                    DoCast(SPELL_BLAZING_STOMP);
                    _events.ScheduleEvent(EVENT_BLAZING_STOMP, 20000);
                    break;
               case EVENT_SMOULDERING_ROOTS:
                    DoCast(SPELL_SMOULDERING_ROOTS);
                    _events.ScheduleEvent(EVENT_SMOULDERING_ROOTS, 30000);
                    break;
               case EVENT_SUMMON_TREANTS:
                    me->SummonCreature(NPC_BURNING_TREANTS, me->GetPositionX()+30, me->GetPositionY(), me->GetPositionZ()+1, float(rand()%5), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_BURNING_TREANTS, me->GetPositionX()-30, me->GetPositionY(), me->GetPositionZ()+1, float(rand()%5), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_BURNING_TREANTS, me->GetPositionX(), me->GetPositionY()+30, me->GetPositionZ()+1, float(rand()%5), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    me->SummonCreature(NPC_BURNING_TREANTS, me->GetPositionX(), me->GetPositionY()-30, me->GetPositionZ()+1, float(rand()%5), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    _events.ScheduleEvent(EVENT_SUMMON_TREANTS, 40000);
                    break;
                }
            }

            if(me->HealthBelowPct(20))
            {
                me->SetFloatValue(OBJECT_FIELD_SCALE_X, defaultsize*0.5f);
                _events.CancelEvent(EVENT_BLAZING_STOMP); // Cancel Events, seems he need the combat active for the Event
                _events.CancelEvent(EVENT_SMOULDERING_ROOTS);
                _events.CancelEvent(EVENT_SUMMON_TREANTS);

                me->setFaction(35);
                me->CombatStop(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT); // no regen health here
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveAllAuras();
            }

            DoMeleeAttackIfReady();
        }
        private:
            EventMap _events;
    };
public:
    npc_tormented_protector() : CreatureScript("npc_tormented_protector") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_tormented_protectorAI(creature);
    }
};

class npc_burning_treant : public CreatureScript
{
    struct npc_burning_treantAI : public ScriptedAI
    {
        npc_burning_treantAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset()
        {
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who && who->GetTypeId() == TYPEID_PLAYER && me->IsValidAttackTarget(who))

            if (me->IsWithinDistInMap(who, 130.0f))
            {
                me->SetSpeed(MOVE_RUN, 0.2f, true);
                me->GetMotionMaster()->MoveChase(who, 0.0f, 0.0f);
                ScriptedAI::MoveInLineOfSight(who);
            }
        }
    };
public:
    npc_burning_treant() : CreatureScript("npc_burning_treant") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_burning_treantAI(creature);
    }
};

class spell_branch_of_nordrassil_summon : public SpellScriptLoader
{
    public:
        spell_branch_of_nordrassil_summon() : SpellScriptLoader("spell_branch_of_nordrassil_summon") { }

        class spell_branch_of_nordrassil_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_branch_of_nordrassil_summon_SpellScript);

            bool Load()
            {
                target = NULL;
                return true;
            }

            void AfterCast(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                caster->SummonCreature(NPC_TORMENTED_PROTECTOR, caster->m_positionX, caster->m_positionY, caster->m_positionZ, 0);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_branch_of_nordrassil_summon_SpellScript::AfterCast, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

            WorldObject* target;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_branch_of_nordrassil_summon_SpellScript();
        }
};

void AddSC_firelands()
{
//    new npc_branch_of_nordrassil(); // Soon phase 2
    new npc_harbinger_legendary();
    new npc_burning_treant();
    new npc_tormented_protector();
    new spell_branch_of_nordrassil_summon();
}
