/*
*
* Copyright (C) 2012-2014 Cerber Project <https://bitbucket.org/mojitoice/>
*
*/

#include "ScriptPCH.h"
#include "deadmines.h"
#include "Vehicle.h"

enum eSpels
{
    // Helix
    SPELL_OAFQUARD                  = 90546,
    SPELL_HELIX_RIDE                = 88337,
    SPELL_THROW_BOMB                = 88264,

    // Oaf spell
    SPELL_OAF_GRAB_TARGETING        = 88289,
    SPELL_RIDE_OAF                  = 88278, // 88277,
    SPELL_RIDE_VEHICLE_HARDCODED    = 46598,
    OAF_CHARGE                      = 88288,
    SPELL_OAF_SMASH                 = 88300,
    SPELL_OAF_SMASH_H               = 91568,

    // BOMB
    SPELL_STICKY_BOMB_EXPLODE       = 95500, //88329, // 95500 -> 88321, 88974
    SPELL_STICKY_BOMB_EXPLODE_H     = 91566,
    SPELL_ARMING_VISUAL_YELLOW      = 88315,
    SPELL_ARMING_VISUAL_ORANGE      = 88316,
    SPELL_ARMING_VISUAL_RED         = 88317,
    SPELL_BOMB_ARMED_STATE          = 88319,
    SPELL_CHEST_BOMB                = 88352, // Unused
};


const Position OafPos[2] =
{
    {-289.809f, -527.215f, 49.8021f, 0},
    {-289.587f, -489.575f, 49.9126f, 0},
};

const Position CrewSpawn[] =
{
    {-281.68f, -504.10f, 60.51f, 4.75f},
    {-284.71f, -504.13f, 60.42f, 4.72f},
    {-288.65f, -503.74f, 60.38f, 4.64f},
    {-293.88f, -503.90f, 60.07f, 4.77f},
};

enum HelOaf_Events
{
    // Helix Events
    EVENT_CHEST_BOMB         = 1,
    EVENT_THROW_BOMB         = 2,
    EVENT_NO_OAF             = 3,
    EVENT_ACHIEVEVEMENT_BUFF = 4,

    // Oaf Events
    EVENT_OAFQUARD           = 5,
    EVENT_MOVE_TO_POINT      = 6,
    EVENT_MOUNT_PLAYER       = 7,
    EVEMT_CHARGE             = 8,
    EVENT_FINISH             = 9,
};

#define CHEST_BOMB "Helix attaches a bomb to $N's chest."

class boss_helix_gearbreaker : public CreatureScript
{
public:
    boss_helix_gearbreaker() : CreatureScript("boss_helix_gearbreaker") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_helix_gearbreakerAI(creature);
    }

    struct boss_helix_gearbreakerAI : public BossAI
    {
        boss_helix_gearbreakerAI(Creature* pCreature) : BossAI(pCreature, DATA_HELIX), summons(me)
        {
            instance = pCreature->GetInstanceScript();
        }

        InstanceScript* instance;
        SummonList summons;


        uint32 Phase;
        uint32 uiTimer;
        uint32 numberKillMineRat;
        Creature* oaf;

        void Reset()
        {
            _Reset();
            Phase = 1;
            uiTimer = 2000;
            numberKillMineRat = 0;

            if (!me)
                return;

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            summons.DespawnAll();
            OafSupport();
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            if (!me)
                return;

            _EnterCombat();
            Talk(5);
            me->SetInCombatWithZone();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(EVENT_THROW_BOMB, 3000);

            if (IsHeroic())
            {
                SummonCrew();
                events.ScheduleEvent(EVENT_ACHIEVEVEMENT_BUFF, 0);
            }
        }

        void OafSupport()
        {
            oaf = me->GetVehicleCreatureBase();
            if (!oaf)
            {
                oaf = me->FindNearestCreature(NPC_OAF, 30.0f);
                if (oaf && oaf->isAlive())
                {
                    me->CastSpell(oaf, SPELL_RIDE_VEHICLE_HARDCODED);
                } else
                {
                    oaf = me->SummonCreature(NPC_OAF, me->GetHomePosition());

                    if (oaf && oaf->isAlive())
                    {
                        me->CastSpell(oaf, SPELL_RIDE_VEHICLE_HARDCODED);
                    }
                }
            }
        }

        void JustSummoned(Creature* summoned)
        {
            summons.Summon(summoned);
        }

        void SummonCrew()
        {
            for (uint8 i = 0; i < 4; ++i)
            {
                me->SummonCreature(NPC_HELIX_CREW, CrewSpawn[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (!me)
                return;

            _JustDied();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            Talk(0);
            summons.DespawnAll();
        }

        void JustReachedHome()
        {
            if (!me)
                return;

            _JustReachedHome();
            Talk(1);
            instance->SetBossState(DATA_HELIX, FAIL);
        }

        void OafDead()
        {
            events.ScheduleEvent(EVENT_NO_OAF, 100);
            events.ScheduleEvent(EVENT_THROW_BOMB, 3000);
            if (IsHeroic())
                events.ScheduleEvent(EVENT_CHEST_BOMB, 5000);
        }

        void UpdateAI(uint32 const uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (!me)
                return;

            DoMeleeAttackIfReady();

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_THROW_BOMB:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150, true))
                            me->CastSpell(target, SPELL_THROW_BOMB, TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE);
                        events.ScheduleEvent(EVENT_THROW_BOMB, 3000);
                        break;
                    case EVENT_CHEST_BOMB:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150, true))
                        {
                            me->MonsterTextEmote(CHEST_BOMB, target->GetGUID(), true);
                            me->AddAura(SPELL_CHEST_BOMB, target);
                        }
                        events.ScheduleEvent(EVENT_CHEST_BOMB, 11000);
                        break;
                    case EVENT_NO_OAF:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveAura(SPELL_OAFQUARD);
                        Talk(2);
                        events.RescheduleEvent(EVENT_THROW_BOMB, 3000);
                        break;
                    case EVENT_ACHIEVEVEMENT_BUFF:
                        std::list<Player*> players;
                        Trinity::AnyPlayerInObjectRangeCheck checker(me, 150.0f);
                        Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, players, checker);
                        me->VisitNearbyWorldObject(150.0f, searcher);

                        for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            me->CastSpell(( *itr ), SPELL_HELIX_RIDE, true);

                        events.ScheduleEvent(EVENT_ACHIEVEVEMENT_BUFF, 60000);
                        break;
                }
            }
        }
    };
};

class npc_lumbering_oaf : public CreatureScript
{
public:
    npc_lumbering_oaf() : CreatureScript("npc_lumbering_oaf") { }


    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_lumbering_oafAI(creature);
    }

    struct npc_lumbering_oafAI : public ScriptedAI
    {
        npc_lumbering_oafAI(Creature* pCreature) : ScriptedAI(pCreature), summons(me)
        {
            _vehicle = me->GetVehicleKit();
            instance = pCreature->GetInstanceScript();
        }

        InstanceScript* instance;
        SummonList summons;
        EventMap events;
        Vehicle* _vehicle;
        Creature* bunny;

        void Reset()
        {
            if (!me || !_vehicle)
                return;

            events.Reset();
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            if (!me)
                return;

            events.ScheduleEvent(EVENT_OAFQUARD, 5000);
        }

        void JustDied(Unit* /*who*/)
        {
            if (Creature* Helix = me->FindNearestCreature(NPC_HELIX_GEARBREAKER, 200, true))
                if (boss_helix_gearbreaker::boss_helix_gearbreakerAI* pAI = CAST_AI(boss_helix_gearbreaker::boss_helix_gearbreakerAI, Helix->AI()))
                    pAI->OafDead();
        }

        void SummonBunny()
        {
            Talk(0);
            Talk(1);
            bunny = me->SummonCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, OafPos[1].GetPositionX(), OafPos[1].GetPositionY(), OafPos[1].GetPositionZ());
            me->SetInCombatWithZone();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                if (bunny)
                {
                    me->SetInCombatWithZone();
                    if (Unit* passenger = me->GetVehicleKit()->GetPassenger(1))
                    {
                        passenger->ExitVehicle();
                        me->Attack(passenger, true);
                    }

                    if (bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, 100.0f))
                    {
                        me->CastSpell(me, IsHeroic() ? SPELL_OAF_SMASH_H : SPELL_OAF_SMASH);

                        me->SummonCreature(NPC_MINE_RAT, -303.193481f, -486.287140f, 49.185917f, 2.152038f, TEMPSUMMON_TIMED_DESPAWN, 360000);
                        me->SummonCreature(NPC_MINE_RAT, -300.496674f, -490.433746f, 49.073387f, 5.243889f, TEMPSUMMON_TIMED_DESPAWN, 360000);
                        me->SummonCreature(NPC_MINE_RAT, -298.689301f, -486.994995f, 48.893055f, 0.950859f, TEMPSUMMON_TIMED_DESPAWN, 360000);
                        me->SummonCreature(NPC_MINE_RAT, -301.923676f, -486.674591f, 49.081684f, 2.677864f, TEMPSUMMON_TIMED_DESPAWN, 360000);
                        me->SummonCreature(NPC_MINE_RAT, -296.066345f, -488.150177f, 48.917435f, 2.657793f, TEMPSUMMON_TIMED_DESPAWN, 360000);

                        bunny->Kill(bunny, false);
                        me->SetSpeed(MOVE_RUN, 1.0f);
                    }
                }

                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    DoStartMovement(target);
            }
        }

        void UpdateAI(uint32 const uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (!me || !_vehicle)
                return;

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_OAFQUARD:
                        SummonBunny();
                        events.ScheduleEvent(EVENT_MOUNT_PLAYER, 500);
                        break;

                    case EVENT_MOUNT_PLAYER:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150, true))
                            target->CastSpell(me, SPELL_RIDE_VEHICLE_HARDCODED);
                        events.ScheduleEvent(EVENT_MOVE_TO_POINT, 500);
                        break;

                    case EVENT_MOVE_TO_POINT:
                        me->SetSpeed(MOVE_RUN, 5.0f);
                        me->GetMotionMaster()->MovePoint(0, -289.809f, -527.215f, 49.8021f);
                        events.ScheduleEvent(EVEMT_CHARGE, 2000);
                        break;

                    case EVEMT_CHARGE:
                        if (me->GetDistance(OafPos[0]) <= 2.0f)
                        {
                            me->GetMotionMaster()->Clear(true);
                            if (bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, 150.0f))
                            {
                                me->GetMotionMaster()->MovePoint(1, bunny->GetPositionX(), bunny->GetPositionY(), bunny->GetPositionZ());
                                bunny->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            }
                        }
                        events.ScheduleEvent(EVENT_FINISH, 1500);
                        break;

                    case EVENT_FINISH:
                        events.ScheduleEvent(EVENT_OAFQUARD, 17000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_sticky_bomb : public CreatureScript
{
public:
    npc_sticky_bomb() : CreatureScript("npc_sticky_bomb") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_sticky_bombAI(creature);
    }

    struct npc_sticky_bombAI : public ScriptedAI
    {
        npc_sticky_bombAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 Phase;
        uint32 uiTimer;

        void Reset()
        {
            Phase   = 1;
            uiTimer = 500;

            if (!me)
                return;

            DoCast(me, SPELL_CHEST_BOMB);
        }

        void UpdateAI(uint32 const uiDiff)
        {
            if (!me)
                return;

            if (uiTimer < uiDiff)
            {
                switch (Phase)
                {
                    case 1:
                        DoCast(me, SPELL_ARMING_VISUAL_YELLOW);
                        uiTimer = 700;
                        break;

                    case 2:
                        DoCast(me, SPELL_ARMING_VISUAL_ORANGE);
                        uiTimer = 600;
                        break;

                    case 3:
                        DoCast(me, SPELL_ARMING_VISUAL_RED);
                        uiTimer = 500;
                        break;

                    case 4:
                        DoCast(me, SPELL_BOMB_ARMED_STATE);
                        uiTimer = 400;
                        break;

                    case 5:
                        DoCast(me, IsHeroic() ? SPELL_STICKY_BOMB_EXPLODE_H : SPELL_STICKY_BOMB_EXPLODE);
                        uiTimer = 300;
                        break;

                    case 6:
                        me->DespawnOrUnsummon();
                        break;
                }
                Phase++;
            } else
                uiTimer -= uiDiff;
        }
    };
};

class npc_helix_crew : public CreatureScript
{
public:
    npc_helix_crew() : CreatureScript("npc_helix_crew") { }


    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_helix_crewAI(creature);
    }

    struct npc_helix_crewAI : public Scripted_NoMovementAI
    {
        npc_helix_crewAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature) { }

        uint32 ThrowBombTimer;

        void Reset()
        {
            ThrowBombTimer = 3000;
            DoCast(me, 18373);

            if (Player* victim = me->FindNearestPlayer(80.0f))
            {
                me->Attack(victim, false);
            }
        }

        void UpdateAI(uint32 const diff)
        {
            if (ThrowBombTimer <= diff)
            {
                if (Unit* player = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                {
                    DoCast(player, SPELL_THROW_BOMB);
                    ThrowBombTimer = 5000;
                }
            } else ThrowBombTimer-= diff;
        }
    };
};

void AddSC_boss_helix_gearbreaker()
{
    new npc_lumbering_oaf();
    new boss_helix_gearbreaker();
    new npc_sticky_bomb();
    new npc_helix_crew();
}
