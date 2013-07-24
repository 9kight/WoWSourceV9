/*
 * Copyright (C) 2010-2011 Trinity <http://www.projecttrinity.org/>
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
#include "halls_of_origination.h"

enum ScriptTexts
{
    SAY_AGGRO                       = 0,
    SAY_DEATH                       = 1,
    SAY_SLAY                        = 2,
};

enum Spells
{
    SPELL_FLAME_BOLT                = 77370,
    SPELL_RAGING_SMASH              = 83650,
    SPELL_SUMMON_JEWELED_SCARAB     = 75462,
    SPELL_SUMMON_DUSTBONE_HORROR    = 75521,
    SPELL_FEIGN_DEATH               = 75511,
    SPELL_PTAH_EXPLOSION            = 75519,
    SPELL_QUICKSAND                 = 75546,
    SPELL_QUICKSAND_2               = 75548,
    SPELL_GROUND_RUPTURE            = 75379,
    SPELL_EARTH_SPIKE               = 94974,
};

enum Events
{
    EVENT_FLAME_BOLT                = 1,
    EVENT_RAGING_SMASH              = 2,
    EVENT_QUICKSAND                 = 3,
    EVENT_EARTH_SPIKE               = 4,
    EVENT_DIST_CHECK                = 5,
};

enum Entities
{
    NPC_QUICKSAND                   = 40503,
    NPC_JEWELED_SCARAB              = 40458,
    NPC_DUSTBONE_HORROR             = 40450,
    NPC_SAND_VORTEX                 = 44291,
};

class boss_ptah : public CreatureScript
{
    class SummonEvent : public BasicEvent
    {
    public:
        SummonEvent(Creature &owner, Creature &quicksand, uint32 entry) : BasicEvent(), _entry(entry), _owner(owner), _quicksand(quicksand) { }
        bool Execute(uint64 /*eventTime*/, uint32 /*diff*/)
        {
            //_quicksand.CastSpell(&_quicksand, _spellId, true, NULL, NULL, _quicksand.ToTempSummon()->GetSummonerGUID());
            _owner.SummonCreature(_entry, _quicksand.GetPositionX(), _quicksand.GetPositionY(), _quicksand.GetPositionZ(), 0.0f, TEMPSUMMON_DEAD_DESPAWN, 2000);
            return true;
        }

    private:
        uint32 _entry;
        Creature &_owner;
        Creature &_quicksand;
    };

    struct boss_ptahAI : public BossAI
    {
        boss_ptahAI(Creature * creature) : BossAI(creature, DATA_EARTHRAGER_PTAH) {}

        void Reset()
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            phase = false;
            feignDeath = false;
            count = 0;
            _Reset();
        }

        void DamageTaken(Unit * /*done_by*/, uint32 &damage)
        {
            if(feignDeath)
                damage = 0;

            if(!phase && me->GetHealthPct() <= 50.0f)
            {
                phase = true;
                feignDeath = true;
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetHealth(0);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();
                DoCast(SPELL_PTAH_EXPLOSION);
                DoCast(SPELL_FEIGN_DEATH);
                SummonAdds();
            }
        }

        void JustDied(Unit * /*killer*/)
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void JustSummoned(Creature * summon)
        {
            if(summon->GetEntry() == NPC_JEWELED_SCARAB || summon->GetEntry() == NPC_DUSTBONE_HORROR)
                if(Unit * victim = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    summon->AI()->AttackStart(victim);

            BossAI::JustSummoned(summon);
        }

        void SummonAdds()
        {
            uint8 cnt = IsHeroic() ? 12 : 8; // needs to be adjusted
            count = cnt;
            Position pos;
            uint32 entry = 0;
            //uint32 spellId = 0;
            for(int i=0; i < cnt; ++i)
            {
                //spellId = (cnt % 3) ? SPELL_SUMMON_JEWELED_SCARAB : SPELL_SUMMON_DUSTBONE_HORROR;
                entry = (i % 3) ? NPC_JEWELED_SCARAB : NPC_DUSTBONE_HORROR;
                me->GetNearPosition(pos, float(urand(25, 40)), (float)rand_norm()*static_cast<float>(2*M_PI));
                if(Creature * quicksand = me->SummonCreature(NPC_QUICKSAND, pos, TEMPSUMMON_TIMED_DESPAWN, 5000))
                {
                    quicksand->CastSpell(quicksand, SPELL_GROUND_RUPTURE, true);
                    quicksand->m_Events.AddEvent(new SummonEvent(*me, *quicksand, entry), me->m_Events.CalculateTime(3000));
                }
            }

            if(IsHeroic())
            {
                if(Creature * vortex = me->SummonCreature(NPC_SAND_VORTEX, 0, 0, 0, 0))
                {
                    vortex->GetMotionMaster()->Clear();
                    vortex->GetMotionMaster()->MoveRandom(50.0f);
                }
            }
        }

        void EnterCombat(Unit * /*who*/)
        {
            Talk(SAY_AGGRO);

            events.ScheduleEvent(EVENT_FLAME_BOLT, urand(7000, 8000));
            events.ScheduleEvent(EVENT_RAGING_SMASH, urand(5000, 10000));
            events.ScheduleEvent(EVENT_QUICKSAND, urand(8000, 10000));
            events.ScheduleEvent(EVENT_EARTH_SPIKE, urand(15000, 20000));
            events.ScheduleEvent(EVENT_DIST_CHECK, 5000);
            _EnterCombat();
        }

        void KilledUnit(Unit * /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void SummonedCreatureDies(Creature * summon, Unit * killer)
        {
            BossAI::SummonedCreatureDies(summon, killer);

            if(feignDeath && (summon->GetEntry() == NPC_JEWELED_SCARAB || summon->GetEntry() == NPC_DUSTBONE_HORROR))
            {
                --count;

                if(count <= 0)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    me->SetHealth(me->CountPctFromMaxHealth(50));
                    feignDeath = false;
                    me->RemoveAurasDueToSpell(SPELL_PTAH_EXPLOSION);
                    me->RemoveAurasDueToSpell(SPELL_FEIGN_DEATH);

                    Unit * target = me->getVictim();
                    if(!target)
                        target = SelectTarget(SELECT_TARGET_RANDOM);
                    if(target)
                        DoStartMovement(target);
                }
            }
        }

        Unit * SelectTargetNoTank()
        {
            Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true);
            if(!target)
                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true);

            return target;
        }

        void UpdateAI(uint32 diff)
        {
            if(!UpdateVictim() || feignDeath)
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_FLAME_BOLT:
                    DoCast(SPELL_FLAME_BOLT);
                    events.ScheduleEvent(EVENT_FLAME_BOLT, urand(15000, 20000));
                    break;
                case EVENT_RAGING_SMASH:
                    DoCast(SPELL_RAGING_SMASH);
                    events.ScheduleEvent(EVENT_RAGING_SMASH, urand(5000, 8000));
                    break;
                case EVENT_QUICKSAND:
                    if(Unit * target = SelectTargetNoTank())
                    {
                        if(Creature * quicksand = me->SummonCreature(NPC_QUICKSAND, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 45000))
                        {
                            quicksand->CastSpell(quicksand, SPELL_QUICKSAND, true, NULL, NULL, me->GetGUID());
                            quicksand->CastSpell(quicksand, SPELL_QUICKSAND_2, true);
                        }
                    }
                    events.ScheduleEvent(EVENT_QUICKSAND, urand(30000, 35000));
                    break;
                case EVENT_EARTH_SPIKE:
                    if(Unit * target = SelectTargetNoTank())
                        DoCast(target, SPELL_EARTH_SPIKE);
                    events.ScheduleEvent(EVENT_EARTH_SPIKE, urand(10000, 15000));
                    break;
                case EVENT_DIST_CHECK:
                    if(me->GetDistance(me->GetHomePosition()) >= 80.0f)
                    {
                        EnterEvadeMode();
                        return;
                    }
                    events.ScheduleEvent(EVENT_DIST_CHECK, 5000);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        bool phase;
        bool feignDeath;
        int8 count;
    };

public:
    boss_ptah() : CreatureScript("boss_ptah") {}
    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_ptahAI(creature);
    }
};

void AddSC_boss_earthrager_ptah()
{
    new boss_ptah();
}
