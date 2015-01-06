/*
 * Copyright (C) 2014 WoW Source  <http://wowsource.info/>
 *
 * Dont Share The SourceCode
 * and read our WoWSource Terms
 *
 */

// ToDo: - Move drones to bethtilac and siphon at 0% fire energy | Achievements
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
#include "ScriptedCreature.h"
#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

#include "firelands.h"

#define ACHIEVMENT_DFA_CRITERIA      1

enum Spells
{
    // Beth'tilac
    SPELL_NO_REGEN = 78725,     ///98623(98153) + 97196 for top
    // Phase 1
    SPELL_EMBER_FLARE = 98934, // phase 2 also
    SPELL_METEOR_FALL = 99073,
    SPELL_METEOR_BURN = 99071,
    SPELL_METEOR_BURN_TRIGGERED = 99076,
    SPELL_TELEPORT_UNITS = 99566,
    SPELL_CONSUME = 100634,
    SPELL_SMOLDERING_DEVASTATION = 99052,

    SPELL_VENOM_RAIN = 99333,
    SPELL_DRONE_DRAIN = 99411,
    SPELL_WEB_SILK = 100048,

    // Phase 2
    SPELL_FRENZY = 99497,
    SPELL_THE_WIDOWS_KISS = 99476,

    // Ciderweb Spinner
    SPELL_BURNING_ACID = 98471,
    SPELL_FIERY_WEB_SPIN_H = 99615, // aura e 99822 link with 97202 needed maybe, triggers it.

    // Cinderweb Drone consume and burning acid
    SPELL_BOILING_SPLATTER = 99463,
    SPELL_FIXATE = 49026,  // 99559 99526

    //Cinderweb Spiderling
    SPELL_SEEPING_VENOM = 97079,

    // Engorged Broodling  53745 heroic only.
    SPELL_VOLATILE_BURST_H = 99990,

    // Web Rip
    SPELL_METEOR_BURN_DUMMY = 99146,
};

enum Points // how the hell do you find these?
{
    POINT_UP = 1,
    POINT_DOWN = 2,
    POINT_SPINNER_MEDIATE = 3,
};

static const Position upPos =
{ 67.888f, 387.82f, 111.767f, 3.682f };
static const Position downPos =
{ 67.888f, 387.82f, 74.042f, 3.682f };
bool AchievementChecker;

enum Events
{
    // Beth'tilac
    EVENT_SUMMON_CINDERWEB_SPINNER = 1,
    EVENT_SUMMON_CINDERWEB_DRONE = 2,
    EVENT_SUMMON_CINDERWEB_SPIDERLING = 3,
    EVENT_SUMMON_ENGORGED_BROODLING = 4,
    EVENT_ENERGY_DRAIN = 5,
    EVENT_SMOLDERING_DEVASTATION = 6,
    EVENT_PHASE_LOWER = 7,
    EVENT_PHASE_UPPER = 8,
    EVENT_EMBER_FLARE = 9,
    EVENT_METEOR_FALL = 10,
    EVENT_CONSUME_SPIDERLING = 11,

    EVENT_FRENZY = 12,
    EVENT_WIDOWS_KISS = 13,

    // Spinner
    EVENT_FIERY_WEB_SPIN = 14,
    EVENT_SPINNER_BURNING_ACID = 15,

    // Drone
    EVENT_DRONE_BURNING_ACID = 16,
    EVENT_CONSUME = 17,
    EVENT_BOILING_SPLATTER = 18,
    EVENT_FIXATE = 19,
    EVENT_DRAIN_ENERGY = 20,

    // Spiderling
    EVENT_CHECK_PLAYER_SEEPING_VENOM = 21,

    // Engorged Broodling
    EVENT_CHECK_PLAYER_RANGE = 22,

    // Web Rip 53450 id
    EVENT_METEOR_DUMMY = 23,

    // Misc
    EVENT_ATTACK_START = 24,
    EVENT_SPINNER_MOVE_DOWN = 25,
    EVENT_CHECK_UPPER = 26,
    EVENT_LITTLE_CHECK_TARGET = 27,

    EVENT_MOVING_LIFT = 28,

    // event group
    EVENT_GROUP_UP_PHASE = 1,
};

enum Achievement
{
    ACHIEVEMENT_DEATH_FROM_ABOVE = 5821
};

Position const CinderwebSummonPos[7] =
{
{ 59.858f, 407.506f, 111.0f, 0 },
{ 40.635f, 394.649f, 111.0f, 0 },
{ 70.855f, 368.306f, 111.0f, 0 },
{ 84.209f, 378.696f, 111.0f, 0 },
{ 80.958f, 389.088f, 111.0f, 0 },
{ 44.758f, 371.840f, 111.0f, 0 },
{ 51.221f, 363.103f, 112.0f, 0 } };

Position const DronePositionSummon[2] =
{
{ 16.313f, 478.900f, 78.366f, 5.21f },
{ 25.308f, 299.858f, 81.036f, 1.23f } };

Position const DronePosition[4] =
{
{ 51.93f, 396.768f, 110.591f, 5.53f },
{ 71.617f, 397.226f, 109.829f, 4.01f },
{ 79.445f, 382.773f, 110.330f, 2.86f },
{ 67.604f, 371.714f, 110.168f, 1.69f } };

Position const SpinderlingsPos[5] =
{
{ 28.156f, 303.488f, 80.014f, 0 },
{ 86.379f, 431.416f, 76.500f, 0 },
{ 78.570f, 355.845f, 74.200f, 0 } };

#define POSITION_Z 75

/**** Beth'tilac ****/

class boss_bethtilac: public CreatureScript
{
    public:
        boss_bethtilac() : CreatureScript("boss_bethtilac") { }

        struct boss_bethtilacAI: public ScriptedAI
        {
                boss_bethtilacAI(Creature* creature) :
                        ScriptedAI(creature), _moveup(false)
                {
                    ASSERT(creature->GetVehicleKit()); // we dont actually use it, just check if exists
                    instance = creature->GetInstanceScript();
                    me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_METEOR_BURN_TRIGGERED, true);
                    me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_TELEPORT_UNITS, true);
                }

                InstanceScript* instance;
                EventMap events;
                int8 Devastion;
                bool _moveup;
				bool AggroResetTime;

                void InitializeAI()
                {
                    if (!me->isDead())
                        Reset();
                }

                void DespawnCreatures(uint32 entry)
                {
                    std::list<Creature*> creatures;
                    GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                    if (creatures.empty())
                        return;

                    for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                        (*iter)->DespawnOrUnsummon();
                }

                void Reset()
                {
                    if (_moveup)
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveJump(upPos, 37.0f, 0.0f);
                        _moveup = false;
                        return;
                    }
					
					AggroResetTime = false;

                    AchievementChecker = true;
                    if (instance)
                    {
                        instance->SetData(DATA_BETHTILAC, NOT_STARTED);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                    }

                    events.Reset();

                    me->SetHealth(me->GetMaxHealth());
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->RemoveAurasDueToSpell(SPELL_NO_REGEN);
                    me->SetUInt32Value(UNIT_FIELD_BYTES_1, 50331648);
                    me->AddUnitState(MOVEMENTFLAG_SWIMMING);
                    me->GetMotionMaster()->MoveTargetedHome();
                    me->SetPower(POWER_ENERGY, 100);
                    me->SetMaxPower(POWER_ENERGY, 100);
                    DespawnCreatures(NPC_LIFT_CONTROLLER);
                    DespawnCreatures(NPC_SPIDERWEB_FILAMENT);
                    DespawnCreatures(NPC_CINDERWEB_SPINNER);
                    DespawnCreatures(NPC_CINDERWEB_DRONE);
                    DespawnCreatures(NPC_CINDERWEB_SPIDERLING);
                    DespawnCreatures(NPC_ENGORGED_BROODLING);
                    DespawnCreatures(NPC_WEB_RIP);

                    events.ScheduleEvent(EVENT_EMBER_FLARE, 10000);
                    events.ScheduleEvent(EVENT_METEOR_FALL, 30000);
                    //phase upper
                    events.ScheduleEvent(EVENT_PHASE_UPPER, 100);

                    Devastion = 0;
                }

                void EnterEvadeMode()
                {
                    Reset();

                    if (instance)
                        instance->SetData(DATA_BETHTILAC, FAIL);

                    _EnterEvadeMode();
                }

                uint32 GetData(uint32 type) const
                {
                    if (type == ACHIEVMENT_DFA_CRITERIA)
                        return AchievementChecker ? 1 : 0;

                    return 0;
                }

                void EnterCombat(Unit* who)
                {
                    if (instance)
                    {
                        instance->SetData(DATA_BETHTILAC, IN_PROGRESS);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
                    }
                    me->AddAura(SPELL_WEB_SILK, me);
                    me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                    me->ClearUnitState(MOVEMENTFLAG_SWIMMING);
                    me->SetDisableGravity(false);
                    me->setActive(true);
                }

                void JustDied(Unit* killer)
                {
                    if (instance)
                    {
                        instance->SetData(DATA_BETHTILAC, DONE);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                    }
                    DespawnCreatures(NPC_CINDERWEB_SPIDERLING);
                    DespawnCreatures(NPC_CINDERWEB_SPINNER);
                    DespawnCreatures(NPC_WEB_RIP);

                    if (me->GetPositionZ() > POSITION_Z)
                        me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), POSITION_Z, 0);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim())
                        return;
					
					if (AggroResetTime)
                    {
                    //Attack random Gamers
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                        {
                        me->AddThreat(target, 1.0f);
                        me->TauntApply(target);
                        AttackStart(target);
                        }
                    AggroResetTime = false;
					}
					
                    events.Update(diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_ENERGY_DRAIN:
                                if (me->GetPower(POWER_ENERGY) == 0)
                                {
                                    DoCast(me, SPELL_SMOLDERING_DEVASTATION);
                                    me->SetPower(POWER_ENERGY, 100);
                                    Devastion++;
                                    if (Devastion == 3)
                                    {
                                        events.CancelEvent(EVENT_ENERGY_DRAIN);
                                        events.ScheduleEvent(EVENT_PHASE_LOWER, 10000);
                                        break;
                                    }
                                }
                                else
                                    me->SetPower(POWER_ENERGY, (me->GetPower(POWER_ENERGY) - 1));

                                events.ScheduleEvent(EVENT_ENERGY_DRAIN, 1000, EVENT_GROUP_UP_PHASE);
                                break;
                            case EVENT_EMBER_FLARE:
                                DoCast(me, SPELL_EMBER_FLARE);
                                events.ScheduleEvent(EVENT_EMBER_FLARE, urand(10000, 15000));
                                break;
                            case EVENT_METEOR_FALL:
                                if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true))
                                {
                                    DoCast(target, SPELL_METEOR_FALL);
                                    events.ScheduleEvent(EVENT_METEOR_FALL, urand(20000, 30000));
                                }
                                else
                                    events.ScheduleEvent(EVENT_METEOR_FALL, 5000);
                                break;
                            case EVENT_PHASE_UPPER:
                                me->SetCanFly(true);
                                me->SetDisableGravity(true);
								AggroResetTime = true;
                                me->AddAura(SPELL_WEB_SILK, me);
                                me->GetMotionMaster()->MovePoint(POINT_UP, upPos);
                                _moveup = true;
                                me->SetReactState(REACT_PASSIVE);
                                me->SetPower(POWER_ENERGY, 100);
                                DoCast(me, SPELL_NO_REGEN);
                                events.ScheduleEvent(EVENT_ENERGY_DRAIN, 3000, EVENT_GROUP_UP_PHASE);
                                events.ScheduleEvent(EVENT_SUMMON_CINDERWEB_SPINNER, 10000, EVENT_GROUP_UP_PHASE);
                                events.ScheduleEvent(EVENT_SUMMON_CINDERWEB_DRONE, 44500, EVENT_GROUP_UP_PHASE);
                                events.ScheduleEvent(EVENT_SUMMON_CINDERWEB_SPIDERLING, 12000, EVENT_GROUP_UP_PHASE);
                                events.ScheduleEvent(EVENT_SMOLDERING_DEVASTATION, 120000, EVENT_GROUP_UP_PHASE);
                                events.ScheduleEvent(EVENT_PHASE_LOWER, 312000);
                                events.ScheduleEvent(EVENT_CHECK_UPPER, 1900);
                                if (me->GetMap()->IsHeroic())
                                    events.ScheduleEvent(EVENT_SUMMON_ENGORGED_BROODLING, 45000, EVENT_GROUP_UP_PHASE);
                                break;
                            case EVENT_PHASE_LOWER:
                                events.CancelEvent(EVENT_SUMMON_CINDERWEB_SPINNER);
                                events.CancelEvent(EVENT_SUMMON_CINDERWEB_DRONE);
                                events.CancelEvent(EVENT_SUMMON_CINDERWEB_SPIDERLING);
                                events.CancelEvent(EVENT_SUMMON_ENGORGED_BROODLING);
                                events.CancelEvent(EVENT_SMOLDERING_DEVASTATION);
                                events.CancelEvent(EVENT_CHECK_UPPER);
                                events.CancelEvent(EVENT_METEOR_FALL);
                                me->GetMotionMaster()->MovePoint(POINT_DOWN, 67.888f, 387.82f, 74.042f);
                                me->SetPower(POWER_ENERGY, 0);
                                events.ScheduleEvent(EVENT_ATTACK_START, 12000);
                                events.ScheduleEvent(EVENT_FRENZY, 13000);
                                events.ScheduleEvent(EVENT_WIDOWS_KISS, 15000);
                                break;
                            case EVENT_SUMMON_CINDERWEB_SPINNER:
                                for (int i = 0; i < 5; i++)
                                    me->SummonCreature(NPC_LIFT_CONTROLLER, CinderwebSummonPos[i].GetPositionX(),
                                            CinderwebSummonPos[i].GetPositionY(), CinderwebSummonPos[i].GetPositionZ(),
                                            0, TEMPSUMMON_TIMED_DESPAWN, 120000);
                                events.ScheduleEvent(EVENT_SUMMON_CINDERWEB_SPINNER, 55000, EVENT_GROUP_UP_PHASE);
                                break;
                            case EVENT_SUMMON_CINDERWEB_DRONE:
                                me->SummonCreature(NPC_CINDERWEB_DRONE, DronePositionSummon[urand(0, 1)],
                                        TEMPSUMMON_CORPSE_DESPAWN);
                                events.ScheduleEvent(EVENT_SUMMON_CINDERWEB_DRONE, 60000, EVENT_GROUP_UP_PHASE);
                                break;
                            case EVENT_SUMMON_CINDERWEB_SPIDERLING:
                            {
                                int8 position = urand(0, 4);
                                for (int i = 1; i < 8; i++)
                                    me->SummonCreature(NPC_CINDERWEB_SPIDERLING,
                                            SpinderlingsPos[position].GetPositionX() + urand(1, 4),
                                            SpinderlingsPos[position].GetPositionY() + urand(1, 4),
                                            SpinderlingsPos[position].GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
                                events.ScheduleEvent(EVENT_SUMMON_CINDERWEB_SPIDERLING, urand(25000, 35000),
                                        EVENT_GROUP_UP_PHASE);
                            }
                                break;
                            case EVENT_SUMMON_ENGORGED_BROODLING:
                                for (int i = 4; i < 8; i++)
                                    me->SummonCreature(NPC_ENGORGED_BROODLING, CinderwebSummonPos[i].GetPositionX(),
                                            CinderwebSummonPos[i].GetPositionY(), 74.042f, TEMPSUMMON_CORPSE_DESPAWN);
                                events.ScheduleEvent(EVENT_SUMMON_ENGORGED_BROODLING, urand(30000, 40000),
                                        EVENT_GROUP_UP_PHASE);
                                break;
                            case EVENT_ATTACK_START:
                                me->GetMotionMaster()->MoveChase(me->GetVictim());
                                break;
                            case EVENT_FRENZY:
                                DoCast(me, SPELL_FRENZY);
                                events.ScheduleEvent(EVENT_FRENZY, 15000);
                                break;
                            case EVENT_WIDOWS_KISS:
                                if (Unit* target = me->GetVictim())
                                    me->AddAura(SPELL_THE_WIDOWS_KISS, target);
                                events.ScheduleEvent(EVENT_WIDOWS_KISS, 20000);
                                break;
                            case EVENT_CHECK_UPPER:
                                Map* map = me->GetMap();
                                if (map && map->IsDungeon() && Devastion != 3)
                                {
                                    //Players part
                                    std::list<Player*> TargetList;
                                    Map::PlayerList const& Players = map->GetPlayers();
                                    for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end();
                                            ++itr)
                                    {
                                        if (Player* player = itr->getSource())
                                        {
                                            if (player->GetPositionZ() > 108.0f)
                                                TargetList.push_back(player);
                                            else
                                                continue;
                                        }
                                    }
                                    if (TargetList.empty())
                                    {
                                        me->SetReactState(REACT_PASSIVE);
                                        me->AddAura(SPELL_WEB_SILK, me);
                                        //me->GetMotionMaster()->MoveJumpTo(67.888f, 387.82f, 111.767f);
                                        me->GetMotionMaster()->MovePoint(POINT_UP, upPos);
                                        DoCast(me, SPELL_VENOM_RAIN);
                                    }
                                    else
                                    {
                                        for (std::list<Player*>::const_iterator itr = TargetList.begin();
                                                itr != TargetList.end(); ++itr)
                                        {
                                            if (!me->HasReactState(REACT_AGGRESSIVE))
                                            {
                                                me->SetReactState(REACT_AGGRESSIVE);
                                                me->Attack((*itr), true);
                                                me->GetMotionMaster()->MoveChase((*itr));
                                            }
                                            me->AddAura(SPELL_WEB_SILK, *itr);
                                        }
                                    }

                                    //Creatures part
                                    std::list<Creature*> DroneList;
                                    GetCreatureListWithEntryInGrid(DroneList, me, NPC_CINDERWEB_DRONE, 1000.0f);
                                    for (std::list<Creature*>::const_iterator itr = DroneList.begin();
                                            itr != DroneList.end(); ++itr)
                                        if ((*itr)->GetPositionZ() > 108.0f)
                                            me->AddAura(SPELL_WEB_SILK, *itr);
                                }
                                events.ScheduleEvent(EVENT_CHECK_UPPER, 2500);
                                break;
                        }

                    }
                    DoMeleeAttackIfReady();
                }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_bethtilacAI(creature);
        }
};

typedef boss_bethtilac::boss_bethtilacAI BethtilacAI;

/**** Cinderweb Spinner ****/

class npc_cinderweb_spinner: public CreatureScript  //  
{
    public:
        npc_cinderweb_spinner() :
                CreatureScript("npc_cinderweb_spinner")
        {
        }

        struct npc_cinderweb_spinnerAI: public ScriptedAI
        {
                npc_cinderweb_spinnerAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                }

                bool Downed;

                void InitializeAI()
                {
                    if (!me->isDead())
                        Reset();
                }

                void Reset()
                {
                    Downed = false;
                    events.Reset();
                    me->SetReactState(REACT_PASSIVE);
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->AddUnitState(MOVEMENTFLAG_SWIMMING);
                    me->SetUInt32Value(UNIT_FIELD_BYTES_1, 50331648);
                    if (Unit* target = me->SelectNearestPlayer(200.0f))
                    {
                        me->Attack(target, false);
                        events.ScheduleEvent(EVENT_SPINNER_BURNING_ACID, 5000);
                        events.ScheduleEvent(EVENT_SPINNER_MOVE_DOWN, 60000);
                    }
                    if (me->GetMap()->IsHeroic())
                        events.ScheduleEvent(EVENT_FIERY_WEB_SPIN, urand(15000, 20000));
                }

                void DamageTaken(Unit* who, uint32& damage)
                {
                    if (damage > 0 && !Downed)
                    {
                        Downed = true;
                        me->RemoveAurasDueToSpell(98623);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_SWIMMING);
                        me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                        me->Attack(who, true);
                        me->GetMotionMaster()->MoveFall();
                    }
                }

                void EnterCombat(Unit* who)
                {
                }

                void JustDied(Unit* /*killer*/)
                {
                    if (me->isSummon())
                    {
                        if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                            summoner->SummonCreature(NPC_SPIDERWEB_FILAMENT, summoner->GetPositionX(),
                                    summoner->GetPositionY(), summoner->GetPositionZ() - 15.0f, 0,
                                    TEMPSUMMON_TIMED_DESPAWN, 60000);
                    }
                }

                void IsSummonedBy(Unit* summoner)
                {
                    summoner->CastSpell(me, 98623, true);
                    me->GetMotionMaster()->MovePoint(POINT_SPINNER_MEDIATE, me->GetPositionX(), me->GetPositionY(),
                            me->GetPositionZ() - 15, true);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim())
                        return;

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_SPINNER_BURNING_ACID:
                                if (!Downed)
                                {
                                    DoCastAOE(SPELL_BURNING_ACID);
                                    events.ScheduleEvent(EVENT_SPINNER_BURNING_ACID, 7000);
                                }
                                break;
                            case EVENT_SPINNER_MOVE_DOWN:
                                if (!Downed)
                                {
                                    Downed = true;
                                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                                }
                                break;
                            case EVENT_FIERY_WEB_SPIN:
                                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true), SPELL_FIERY_WEB_SPIN_H);
                                events.ScheduleEvent(EVENT_FIERY_WEB_SPIN, urand(35000, 45000));
                                break;
                        }
                    }
                    DoMeleeAttackIfReady();
                }
            private:
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cinderweb_spinnerAI(creature);
        }
};

/**** Cinderweb Drone ****/ 
class npc_cinderweb_drone: public CreatureScript   //  
{
    public:
        npc_cinderweb_drone() :
                CreatureScript("npc_cinderweb_drone")
        {
        }

        struct npc_cinderweb_droneAI: public ScriptedAI
        {
                npc_cinderweb_droneAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                }

                bool SummonLift;

                void InitializeAI()
                {
                    if (!me->isDead())
                        Reset();

                    SummonLift = true;
                }

                void JustDied(Unit* /*killer*/)
                {
                }

                void Reset()
                {
                    if (Unit* target = me->SelectNearestPlayer(200.0f))
                    {
                        me->Attack(target, true);
                        me->GetMotionMaster()->MoveChase(target);
                    }
                    events.Reset();
                    me->setPowerType(POWER_ENERGY);
                    me->SetMaxPower(POWER_ENERGY, 85);
                    me->SetPower(POWER_ENERGY, 85);
                    events.ScheduleEvent(EVENT_CONSUME, 3000);
                    events.ScheduleEvent(EVENT_BOILING_SPLATTER, urand(15000, 25000));
                    events.ScheduleEvent(EVENT_DRONE_BURNING_ACID, urand(5000, 10000));
                    if (me->GetMap()->IsHeroic())
                        events.ScheduleEvent(EVENT_FIXATE, 100);
                }

                void EnterCombat(Unit* who)
                {
                    DoCast(me, SPELL_NO_REGEN);
                    me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                }

                void DamageTaken(Unit* attacker, uint32& damage)
                {
                    if (damage > me->GetMaxHealth())
                    {
                        if (!me->HasAura(100048))
                            AchievementChecker = false;
                    }
                }

                void JustSummoned(Creature *summon)
                {
                    events.CancelEvent(EVENT_CONSUME);
                    events.CancelEvent(EVENT_BOILING_SPLATTER);
                    events.CancelEvent(EVENT_DRONE_BURNING_ACID);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim())
                        return;

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_DRAIN_ENERGY:
                                if (GetBethi())
                                {
                                    GetBethi()->SetPower(POWER_ENERGY,
                                            (GetBethi()->GetPower(POWER_ENERGY) - 85) > 0 ?
                                                    (GetBethi()->GetPower(POWER_ENERGY) - 85) : 0);
                                    me->SetPower(POWER_ENERGY, 85);
                                    me->SetReactState(REACT_AGGRESSIVE);
                                    if (Unit *player = me->SelectNearestPlayer(100.0f))
                                    {
                                        me->Attack(player, true);
                                        me->GetMotionMaster()->MoveChase(player);
                                    }
                                }
                                break;
                            case EVENT_DRONE_BURNING_ACID:
                                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true), SPELL_BURNING_ACID);
                                events.ScheduleEvent(EVENT_DRONE_BURNING_ACID, urand(15000, 35000));
                                break;
                            case EVENT_BOILING_SPLATTER:
                                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true), SPELL_BOILING_SPLATTER);
                                events.ScheduleEvent(EVENT_BOILING_SPLATTER, urand(25000, 35000));
                                break;
                            case EVENT_CONSUME:
                                if (Creature* spiderling = me->FindNearestCreature(NPC_CINDERWEB_SPIDERLING, 5.0f,
                                        true))
                                {
                                    me->AddAura(SPELL_CONSUME, me);
                                    spiderling->DespawnOrUnsummon();
                                }
                                events.ScheduleEvent(EVENT_CONSUME, 1000);
                                break;
                            case EVENT_FIXATE:
                                if (Unit* victim = SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true))
                                {
                                    DoCast(victim, SPELL_FIXATE);
                                    me->GetMotionMaster()->MoveChase(victim);
                                }
                                break;
                        }
                    }
                    DoMeleeAttackIfReady();
                }

                Creature* GetBethi()
                {
                    return (me->FindNearestCreature(52498, 5000.0f, true) == NULL) ?
                            me->FindNearestCreature(52498, 5000.0f, false) :
                            me->FindNearestCreature(52498, 5000.0f, true);
                }

            private:
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cinderweb_droneAI(creature);
        }
};

/**** Cinderweb Spiderling ****/

class npc_cinderweb_spiderling: public CreatureScript //
{
    public:
        npc_cinderweb_spiderling() :
                CreatureScript("npc_cinderweb_spiderling")
        {
        }

        struct npc_cinderweb_spiderlingAI: public ScriptedAI
        {
                npc_cinderweb_spiderlingAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                }

                void InitializeAI()
                {
                    if (!me->isDead())
                        Reset();
                }
                bool Founded;
                bool NeedKick;

                void JustDied(Unit* /*killer*/)
                {
                }

                void IsSummonedBy(Unit* summoner)
                {
                    NeedKick = true;
                    events.ScheduleEvent(EVENT_LITTLE_CHECK_TARGET, 1000);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                }

                void EnterCombat(Unit* who)
                {
                }

                void UpdateAI(const uint32 diff)
                {
                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CHECK_PLAYER_SEEPING_VENOM:
                                if (Unit* target = me->FindNearestPlayer(5.0f, true))
                                    DoCast(target, SPELL_SEEPING_VENOM);
                                events.ScheduleEvent(EVENT_CHECK_PLAYER_SEEPING_VENOM, 3000);
                                break;

                            case EVENT_LITTLE_CHECK_TARGET:
                            {
                                std::list<Creature*> creatures;
                                Founded = false;
                                GetCreatureListWithEntryInGrid(creatures, me, NPC_CINDERWEB_DRONE, 1000.0f);

                                if (creatures.empty())
                                {
                                    sLog;
                                    if(Unit* target = me->FindNearestPlayer(400.0f, true))
                                    {
                                        if(NeedKick)
                                        {
                                            me->GetMotionMaster()->MoveChase(target);
                                            NeedKick = false;
                                        }
                                        me->SetReactState(REACT_AGGRESSIVE);
                                        me->Attack(target, true);
                                        events.ScheduleEvent(EVENT_CHECK_PLAYER_SEEPING_VENOM, 3000);
                                        Founded = false;
                                    }
                                    //return;
                                }
                                else
                                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                                {
                                    if((*iter)->GetPositionZ() < 100.0f && (*iter)->isAlive())
                                    {
                                        me->GetMotionMaster()->MoveFollow(*iter, 1.0f, 0.0f);
                                        Founded = true;
                                        NeedKick = true;
                                        break;
                                    }
                                    else
                                    continue;
                                }

                                if (!Founded)
                                {
                                    if (Unit* target = me->FindNearestPlayer(400.0f, true))
                                    {
                                        sLog;
                                        me->SetReactState(REACT_AGGRESSIVE);
                                        if(NeedKick)
                                        {
                                            me->GetMotionMaster()->MoveChase(target);
                                            NeedKick = false;
                                        }
                                        me->Attack(target, true);
                                        events.ScheduleEvent(EVENT_CHECK_PLAYER_SEEPING_VENOM, 3000);
                                    }
                                }
                                events.ScheduleEvent(EVENT_LITTLE_CHECK_TARGET, 3000);
                            }
                                break;
                        }
                    }
                }
            private:
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cinderweb_spiderlingAI(creature);
        }
};

/**** Engorged Broodling ****/

class npc_engorged_broodling: public CreatureScript // .  
{
    public:
        npc_engorged_broodling() :
                CreatureScript("npc_engorged_broodling")
        {
        }

        struct npc_engorged_broodlingAI: public ScriptedAI
        {
                npc_engorged_broodlingAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                }

                void JustDied(Unit* /*killer*/)
                {
                }

                void Reset()
                {
                    events.Reset();
                    events.ScheduleEvent(EVENT_CHECK_PLAYER_RANGE, urand(2000, 9000));
                }

                void EnterCombat(Unit* /*who*/)
                {
                    me->SetReactState(REACT_PASSIVE);
                    if (Unit* player = SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true))
                        me->GetMotionMaster()->MoveChase(player);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim())
                        return;

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CHECK_PLAYER_RANGE:
                                if (Unit* target = me->FindNearestPlayer(5.0f, true))
                                {
                                    DoCast(me, SPELL_VOLATILE_BURST_H);
                                    me->DisappearAndDie();
                                }
                                events.ScheduleEvent(EVENT_CHECK_PLAYER_RANGE, 1000);
                                break;
                        }
                    }
                }
            private:
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_engorged_broodlingAI(creature);
        }
};

class npc_web_rip: public CreatureScript
{
    public:
        npc_web_rip() :
                CreatureScript("npc_web_rip")
        {
        }

        struct npc_web_ripAI: public Scripted_NoMovementAI
        {
                npc_web_ripAI(Creature* creature) :
                        Scripted_NoMovementAI(creature)
                {
                }

                void JustDied(Unit* /*killer*/)
                {
                }

                void IsSummonedBy(Unit* summoner)
                {
                    events.ScheduleEvent(EVENT_METEOR_DUMMY, 100);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_METEOR_DUMMY:
                                DoCast(SPELL_METEOR_BURN);

                                std::list<Player*> TargetList;
                                Map::PlayerList const& Players = me->GetMap()->GetPlayers();
                                for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                                {
                                    if (Player* player = itr->getSource())
                                    {
                                        if (player->GetDistance(me) <= 6.0f)
                                            TargetList.push_back(player);
                                        else
                                            continue;
                                    }
                                }
                                if (!TargetList.empty())
                                    for (std::list<Player*>::const_iterator itr = TargetList.begin();
                                            itr != TargetList.end(); ++itr)
                                        (*itr)->TeleportTo(me->GetMapId(), me->GetPositionX(), me->GetPositionY(),
                                                me->GetPositionZ() - 5.0f, (*itr)->GetOrientation());

                                events.ScheduleEvent(EVENT_METEOR_DUMMY, 2500);
                                break;
                        }
                    }
                }
            private:
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_web_ripAI(creature);
        }
};

class npc_web_filament: public CreatureScript
{
    public:
        npc_web_filament() : CreatureScript("npc_web_filament") { }

        struct npc_web_filamentAI: public ScriptedAI
        {
                npc_web_filamentAI(Creature* creature) : ScriptedAI(creature), vehicle(creature->GetVehicleKit())
                {
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                }

                Vehicle* vehicle;
                bool seated;

                void IsSummonedBy(Unit* summoner)
                {
                    seated = false;
                    me->AddAura(98149, me);
                    summoner->CastSpell(me, 98623, true);
                    me->DespawnOrUnsummon(10000);
                }

                void PassengerBoarded(Unit* who, int8 seatId, bool apply)
                {
//            if (!me->GetVehicle())
//                return;

                    if (who->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (!apply)
                            return;
                        else if (me->isSummon())
                            if (Unit* lifthandler = me->ToTempSummon()->GetSummoner())
                            {
                                seated = true;
                                me->GetMotionMaster()->MoveJump(lifthandler->GetPositionX(),
                                        lifthandler->GetPositionY(), lifthandler->GetPositionZ(), 60.0f, 50);
                                events.ScheduleEvent(EVENT_MOVING_LIFT, 7000);
                            }
                    }
                }

                void JustDied(Unit* /*killer*/)
                {
                }

                void EnterCombat(Unit* who)
                {
                }

                void UpdateAI(const uint32 diff)
                {
                    if (me->HasUnitState(UNIT_STATE_CASTING) || !seated)
                        return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_MOVING_LIFT:
                                if (Unit* lifthandler = me->ToTempSummon()->GetSummoner())
                                {
                                    if (lifthandler->GetVehicleKit())
                                        lifthandler->GetVehicleKit()->RemoveAllPassengers();
                                    lifthandler->ToCreature()->DespawnOrUnsummon();
                                    me->DespawnOrUnsummon();
                                }
                                break;
                        }
                    }
                }
            private:
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_web_filamentAI(creature);
        }
};

class npc_lift_controller: public CreatureScript
{
    public:
        npc_lift_controller() :
                CreatureScript("npc_lift_controller")
        {
        }

        struct npc_lift_controllerAI: public ScriptedAI
        {
                npc_lift_controllerAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                }

                void Reset()
                {
                }

                void IsSummonedBy(Unit* summoner)
                {
                    me->AddAura(97196, me);
                    if (summoner->GetEntry() == NPC_BETHTILAC)
                        me->SummonCreature(NPC_CINDERWEB_SPINNER, me->GetPositionX(), me->GetPositionY(),
                                me->GetPositionZ() - 5, 0, TEMPSUMMON_CORPSE_DESPAWN);
                }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_lift_controllerAI(creature);
        }
};

class achievement_death_from_above: public AchievementCriteriaScript //need to check
{
    public:
        achievement_death_from_above() :
                AchievementCriteriaScript("achievement_death_from_above")
        {
        }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Betti = target->ToCreature())
                if (Betti->AI()->GetData(ACHIEVMENT_DFA_CRITERIA))
                    return true;

            return false;
        }
};

void AddSC_boss_bethtilac()
{
    new boss_bethtilac();
    new npc_cinderweb_spinner();
    new npc_cinderweb_drone();
    new npc_cinderweb_spiderling();
    new npc_engorged_broodling();
    new npc_web_rip();
    new npc_web_filament();
    new npc_lift_controller();
    new achievement_death_from_above();
}
