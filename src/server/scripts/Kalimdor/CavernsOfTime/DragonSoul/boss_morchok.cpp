#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "dragon_soul.h"

#define SPELL_STOMP RAID_MODE(109033, 109034, 103414, 108571)

enum Yells
{
    SAY_AGGRO                   = 0,
    SAY_DEATH                   = 1,
    SAY_PLAYER_KILL             = 2,
    SAY_SUMMON_CRYSTAL          = 3
};

enum Spells
{
    SPELL_CRUSH_ARMOR               = 103687,
    SPELL_RESONATING_CRYSTAL        = 103640,
    SPELL_FURIOUS                   = 103846,
    SPELL_EARTHS_VENGEANCE_CHANNEL  = 103176,
    SPELL_EARTHS_VENGEANCE          = 103178,
    SPELL_BLACK_BLOOD_OF_THE_EARTH  = 103851,
    SPELL_BLACK_BLOOD_SUM           = 103180,
    SPELL_RESONATING_CRYSTAL_EX     = 108572,
    SPELL_RESONATING_CRYSTAL_AURA   = 103494,
    SPELL_DANGER                    = 103534,
    SPELL_WARNING                   = 103536,
    SPELL_SAFE                      = 103541,
    SPELL_ENRAGE                    = 47008
};

enum Events
{
    EVENT_STOMP                     = 1,
    EVENT_CRUSH_ARMOR               = 2,
    EVENT_RESONATING_CRYSTAL        = 3,
    EVENT_FURIOUS                   = 4,
    EVENT_EARTHS_VENGEANCE          = 5,
    EVENT_BLACK_BLOOD_OF_THE_EARTH  = 6,
    EVENT_EXPLODE                   = 7,
    EVENT_DESPAWN                   = 8,
    EVENT_RESONATING                = 9,
    EVENT_ANTI_EXPLODE              = 10,
    EVENT_CLEANING                  = 11,
    EVENT_PHASE_NORMAL              = 12,
    EVENT_PHASE_BLACK_BLOOD         = 13,
    EVENT_EARTHS_VENGEANCE_DROP     = 14,
    EVENT_ENRAGE                    = 15
};

enum Phases
{
    PHASE_NORMAL                    = 1,
    PHASE_BLACK_BLOOD               = 2
};

class boss_morchok : public CreatureScript
{
public:
    boss_morchok() : CreatureScript("boss_morchok") { }

    struct boss_morchokAI : public BossAI
    {
        boss_morchokAI(Creature* creature) : BossAI(creature, DATA_MORCHOK) { }

        uint32 MorchokHealth;
        uint32 Raid10N;
        uint32 Raid10H;
        uint32 Raid25N;
        uint32 Raid25H;
        void Reset()
        {
            _Reset();
            Raid10N = 23400130;
            Raid10H = 13957449;
            Raid25N = 66299996;
            Raid25H = 58631360;
            MorchokHealth = RAID_MODE(Raid10N, Raid25N, Raid10H, Raid25H);
            me->SetMaxHealth(MorchokHealth);
            me->SetFullHealth();
            me->SetObjectScale(1);
            events.SetPhase(PHASE_NORMAL);
            events.ScheduleEvent(EVENT_STOMP, urand(9000, 14000));
            events.ScheduleEvent(EVENT_CRUSH_ARMOR, urand(10000, 15000));
            events.ScheduleEvent(EVENT_RESONATING_CRYSTAL, urand(25000, 35000));
            events.ScheduleEvent(EVENT_PHASE_BLACK_BLOOD, urand(45000, 55000));
            events.ScheduleEvent(EVENT_ENRAGE, 447000);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            _EnterCombat();
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
        }

        void EnterEvadeMode()
        {
            events.Reset();
            summons.DespawnAll();
            me->GetMotionMaster()->MoveTargetedHome();
            me->SetObjectScale(1);
            _Reset();
            _EnterEvadeMode();
        }

        void KilledUnit(Unit* victim)
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_PLAYER_KILL);
        }

        void DespawnGameobjects(uint32 entry, float distance)
        {
            std::list<GameObject*> gameobjects;
            GetGameObjectListWithEntryInGrid(gameobjects, me, entry, distance);

            if (gameobjects.empty())
                return;

            for (std::list<GameObject*>::iterator iter = gameobjects.begin(); iter != gameobjects.end(); ++iter)
                (*iter)->RemoveFromWorld();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (me->HealthBelowPct(80) && me->HealthAbovePct(71))
                me->SetObjectScale(0.7f);
            else if(me->HealthBelowPct(70) && me->HealthAbovePct(61))
                me->SetObjectScale(0.6f);
            else if(me->HealthBelowPct(60) && me->HealthAbovePct(51))
                me->SetObjectScale(0.5f);
            else if(me->HealthBelowPct(50) && me->HealthAbovePct(41))
                me->SetObjectScale(0.4f);
            else if(me->HealthBelowPct(40) && me->HealthAbovePct(31))
                me->SetObjectScale(0.3f);
            else if(me->HealthBelowPct(20))
                DoCast(me, SPELL_FURIOUS);
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (Unit* victim = me->GetVictim())
                if (!me->IsWithinLOSInMap(victim) && events.IsInPhase(PHASE_NORMAL))
                    me->DealDamage(victim, victim->GetHealth());

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_STOMP:
                    if (events.IsInPhase(PHASE_NORMAL))
                        DoCastVictim(SPELL_STOMP);
                    events.ScheduleEvent(EVENT_STOMP, urand(12000, 18000));
                    break;
                case EVENT_CRUSH_ARMOR:
                    if (events.IsInPhase(PHASE_NORMAL))
                        DoCastVictim(SPELL_CRUSH_ARMOR);
                    events.ScheduleEvent(EVENT_CRUSH_ARMOR, urand(12000, 18000));
                    break;
                case EVENT_RESONATING_CRYSTAL:
                    if (events.IsInPhase(PHASE_NORMAL))
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {
                            DoCast(target, SPELL_RESONATING_CRYSTAL);
                            Talk(SAY_SUMMON_CRYSTAL);
                        }
                        events.ScheduleEvent(EVENT_RESONATING_CRYSTAL, urand(20000, 25000));
                        break;
                case EVENT_PHASE_BLACK_BLOOD:
                    events.SetPhase(PHASE_BLACK_BLOOD);
                    events.ScheduleEvent(EVENT_EARTHS_VENGEANCE, 100);
                    break;
                case EVENT_EARTHS_VENGEANCE:
                    DoCast(me, SPELL_EARTHS_VENGEANCE_CHANNEL);
                    float x, y, z, x1, y1, x2, y2, x3, y3, x4, y4;
                    x = me->GetPositionX();
                    y = me->GetPositionY();
                    z = me->GetPositionZ() - 3;
                    x1 = x + urand(18, 25);
                    y1 = y + urand(18, 25);
                    x2 = x + urand(18, 25);
                    y2 = y - urand(18, 25);
                    x3 = x - urand(18, 25);
                    y3 = y + urand(18, 25);
                    x4 = x - urand(18, 25);
                    y4 = y - urand(18, 25);
                    //me->SummonCreature(NPC_MINNOR_RESONATING_CRYSTAL, x1, y1, z, 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
                    //me->SummonCreature(NPC_MINNOR_RESONATING_CRYSTAL, x2, y2, z, 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
                    //me->SummonCreature(NPC_MINNOR_RESONATING_CRYSTAL, x3, y3, z, 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
                    //me->SummonCreature(NPC_MINNOR_RESONATING_CRYSTAL, x4, y4, z, 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
                    events.ScheduleEvent(EVENT_BLACK_BLOOD_OF_THE_EARTH, 5000, 0, PHASE_BLACK_BLOOD);
                    break;
                case EVENT_BLACK_BLOOD_OF_THE_EARTH:
                    DoCast(me, SPELL_BLACK_BLOOD_OF_THE_EARTH);
                    events.ScheduleEvent(EVENT_CLEANING, 17000, 0, PHASE_BLACK_BLOOD);
                    break;
                case EVENT_CLEANING:
                    //DespawnGameobjects(GO_INNER_WALL, 100.0f);
                    events.ScheduleEvent(EVENT_PHASE_NORMAL, 100, 0, PHASE_BLACK_BLOOD);
                    break;
                case EVENT_PHASE_NORMAL:
                    events.SetPhase(PHASE_NORMAL);
                    events.ScheduleEvent(EVENT_PHASE_BLACK_BLOOD, urand(30000, 50000));
                    break;
                case EVENT_ENRAGE:
                    me->InterruptNonMeleeSpells(true);
                    DoCast(me, SPELL_ENRAGE);
                    events.ScheduleEvent(EVENT_ENRAGE, 447000);
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
        return new boss_morchokAI(creature);
    }
};

class npc_resonating_crystal : public CreatureScript
{
public:
    npc_resonating_crystal() : CreatureScript("npc_resonating_crystal") { }

    struct npc_resonating_crystalAI : public ScriptedAI
    {
        npc_resonating_crystalAI(Creature* creature) : ScriptedAI(creature),
            _instance(creature->GetInstanceScript())
        {
            me->AttackStop();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        }

        int32 count;
        void Reset()
        {
            _events.Reset();
            _events.ScheduleEvent(EVENT_RESONATING, 100);
            _events.ScheduleEvent(EVENT_ANTI_EXPLODE, 500);
            _events.ScheduleEvent(EVENT_EXPLODE, 11900);
            _events.ScheduleEvent(EVENT_DESPAWN, 12000);
            count = 0;
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_RESONATING:
                    DoCast(me, SPELL_RESONATING_CRYSTAL_AURA);
                    break;
                case EVENT_EXPLODE:
                    {
                        Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                        if (!PlayerList.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                if (i->getSource()->isAlive())
                                {
                                    i->getSource()->RemoveAurasDueToSpell(SPELL_SAFE);
                                    i->getSource()->RemoveAurasDueToSpell(SPELL_WARNING);
                                    i->getSource()->RemoveAurasDueToSpell(SPELL_DANGER);
                                }
                            }
                        }
                        DoCast(me, SPELL_RESONATING_CRYSTAL_EX);
                        break;
                    }
                case EVENT_ANTI_EXPLODE:
                    {
                        count = 0;
                        Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                        if (!PlayerList.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                if (i->getSource()->isAlive())
                                {
                                    if (me->GetExactDist(i->getSource()) < 3.0f)
                                    {
                                        count++;
                                    }
                                }
                            }
                        }

                        if (!PlayerList.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                if (i->getSource()->isAlive())
                                {
                                    if (count == 0)
                                    {
                                        DoCast(i->getSource(), SPELL_DANGER);
                                        i->getSource()->RemoveAurasDueToSpell(SPELL_WARNING);
                                        i->getSource()->RemoveAurasDueToSpell(SPELL_SAFE);
                                    }
                                    else if (count == 1)
                                    {
                                        DoCast(i->getSource(), SPELL_DANGER);
                                        i->getSource()->RemoveAurasDueToSpell(SPELL_WARNING);
                                        i->getSource()->RemoveAurasDueToSpell(SPELL_SAFE);
                                    }
                                    else if (count == 2)
                                    {
                                        DoCast(i->getSource(), SPELL_WARNING);
                                        i->getSource()->RemoveAurasDueToSpell(SPELL_DANGER);
                                        i->getSource()->RemoveAurasDueToSpell(SPELL_SAFE);
                                    }
                                    else
                                    {
                                        DoCast(i->getSource(), SPELL_SAFE);
                                        i->getSource()->RemoveAurasDueToSpell(SPELL_WARNING);
                                        i->getSource()->RemoveAurasDueToSpell(SPELL_DANGER);
                                        _events.ScheduleEvent(EVENT_DESPAWN, 2000);
                                    }
                                }
                            }
                        }
                        _events.ScheduleEvent(EVENT_ANTI_EXPLODE, 500);
                        break;
                    }
                case EVENT_DESPAWN:
                    {
                        Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                        if (!PlayerList.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                if (i->getSource()->isAlive())
                                {
                                    i->getSource()->RemoveAurasDueToSpell(SPELL_SAFE);
                                    i->getSource()->RemoveAurasDueToSpell(SPELL_WARNING);
                                    i->getSource()->RemoveAurasDueToSpell(SPELL_DANGER);
                                }
                            }
                        }
                        me->DespawnOrUnsummon();
                        break;
                    }
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetDragonSoulAI<npc_resonating_crystalAI>(creature);
    }
};

class npc_minnor_resonating_crystal : public CreatureScript
{
public:
    npc_minnor_resonating_crystal() : CreatureScript("npc_minnor_resonating_crystal") { }

    struct npc_minnor_resonating_crystalAI : public ScriptedAI
    {
        npc_minnor_resonating_crystalAI(Creature* creature) : ScriptedAI(creature),
            _instance(creature->GetInstanceScript())
        {
        }

        void Reset()
        {
            _events.Reset();
            _events.ScheduleEvent(EVENT_EARTHS_VENGEANCE_DROP, urand(2000, 4000));
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_EARTHS_VENGEANCE_DROP:
                    DoCast(me, SPELL_EARTHS_VENGEANCE);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetDragonSoulAI<npc_minnor_resonating_crystalAI>(creature);
    }
};

class spell_morchok_stomp : public SpellScriptLoader
{
public:
    spell_morchok_stomp() : SpellScriptLoader("spell_morchok_stomp") { }

    class spell_morchok_stomp_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_morchok_stomp_SpellScript);

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            int32 damage;
            int32 count = 1;
            damage = 675000;

            if (caster->GetMap()->IsHeroic())
            {
                if (caster->GetMap()->Is25ManRaid())
                    damage = 2700000;
                else
                    damage = 1350000;
            }
            else
            {
                if (caster->GetMap()->Is25ManRaid())
                    damage = 2000000;
                else
                    damage = 675000;
            }

            Map::PlayerList const &PlayerList = caster->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    if (i->getSource()->isAlive())
                    {
                        if (caster->GetExactDist(i->getSource()) < 26.0f)
                        {
                            count++;
                        }
                    }
            damage = damage / count;
            SetHitDamage(damage);
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_morchok_stomp_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_morchok_stomp_SpellScript();
    }

};

class spell_morchok_black_blood : public SpellScriptLoader
{
public:
    spell_morchok_black_blood() :  SpellScriptLoader("spell_morchok_black_blood") { }

    class spell_morchok_black_blood_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_morchok_black_blood_SpellScript);

        void HandleOnCast()
        {
            Unit* caster = GetCaster();
            Map::PlayerList const &PlayerList = caster->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    if (i->getSource()->isAlive())
                    {
                        if (!caster->IsWithinLOSInMap(i->getSource()))
                        {
                            i->getSource()->RemoveAurasDueToSpell(103785); //TODO this just remove aura stacks but i->getSource() should not receive damage at all
                        }
                    }
        }

        void Register()
        {
            OnCast += SpellCastFn(spell_morchok_black_blood_SpellScript::HandleOnCast);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new spell_morchok_black_blood_SpellScript();
    }
};

void AddSC_boss_morchok()
{
    new boss_morchok();
    new npc_resonating_crystal();
    new npc_minnor_resonating_crystal();
    new spell_morchok_stomp();
    new spell_morchok_black_blood();
}