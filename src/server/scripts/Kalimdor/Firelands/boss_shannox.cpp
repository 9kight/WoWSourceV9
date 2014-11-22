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

enum Shannox_Yells
{
    SAY_AGGRO = 0,
    EMOTE_SOFT_ENRAGE = 1,
    SAY_ON_DOGS_FALL = 2,
    SAY_ON_DEAD = 3,
    SAY_DOG_FOOD = 4,
    SAY_FETCH_SUPPER = 5,
    SAY_GO_FOR_THROAT = 6,
    SAY_BURN_ONE = 7,
    SAY_ON_KILL_ONE = 8,
    SAY_RIPLIMB = 9,
    SAY_ON_KILL_TWO = 10,
    SAY_BURN_TWO = 11,
    SAY_INTRO_SPECH_PART_ONE = 12,
    SAY_INTRO_SPECH_PART_TWO = 13
};

enum ePhases
{
    PHASE_NON = 0,

    PHASE_SHANNOX_HAS_SPEER = 1,
    PHASE_SPEAR_ON_THE_GROUND = 2,
    PHASE_RIPLIMB_GOS_TO_SPEER = 3,
    PHASE_RIPLIMB_BRINGS_SPEER = 4
};

enum Actions
{
    ACTION_SAY_RIPLIMB, //Shannox yell when Riplimb bites someone.
    ACTION_START_EVENT_TO_RESPAWN_RIPLIMB, // Used by Riplimb when he dies to start Shannox respawn event.
};

enum AreaIds
{
    AREA_1 = 5764,
    AREA_2 = 5821,
    AREA_3 = 5766,
    AREA_4 = 5791,
    AREA_5 = 5765
};

enum Misc
{
    DATA_TRAPPED_PLAYER = 4,
    DATA_TRAPPED_DOG = 5,
};

enum Spells
{
    //Shannox
    SPELL_ARCTIC_SLASH_10N = 99931,
    SPELL_ARCTIC_SLASH_25N = 101201,
    SPELL_ARCTIC_SLASH_10H = 101202,
    SPELL_ARCTIC_SLASH_25H = 101203,

    SPELL_BERSERK = 47008,

    SPELL_CALL_SPEAR = 100663,
    SPELL_HURL_SPEAR = 100002, // Dummy Effect & Damage.
    SPELL_HURL_SPEAR_SUMMON = 99978,  //Summons Spear of Shannox.
    SPELL_MAGMA_RUPTURE_SHANNOX = 99840,

    SPELL_FRENZY_SHANNOX = 100522,

    // Riplimb
    SPELL_LIMB_RIP = 99832,
    SPELL_DOGGED_DETERMINATION = 101111,

    // Rageface
    SPELL_FACE_RAGE = 99947,
    SPELL_RAGE = 100415,

    SPELL_FACE_RAGE_10N = 100129, // Buff to remove damage aura.
    SPELL_FACE_RAGE_25N = 101212,
    SPELL_FACE_RAGE_10H = 101213,
    SPELL_FACE_RAGE_25H = 101214,

    // Both Dogs
    SPELL_FRENZIED_DEVOLUTION = 100064,
    SPELL_FEEDING_FRENZY_H = 100655,

    SPELL_WARY_10N = 100167, // Buff when the Dog goes into a Trap.
    SPELL_WARY_25N = 101215,
    SPELL_WARY_10H = 101216,
    SPELL_WARY_25H = 101217,

    // Misc
    SPELL_SEPERATION_ANXIETY = 99835,

    //Spear Abilities
    SPELL_MAGMA_FLARE = 100495, // Inflicts Fire damage to enemies within 50 yards.
    SPELL_MAGMA_RUPTURE = 100003, // Calls forth magma eruptions to damage nearby foes. (Dummy Effect)
    SPELL_MAGMA_RUPTURE_VISUAL = 99841,
    RED_TARGET_AUR = 99988,
    SPEAR_VISIBLE_ON_GROUND = 100005,
    SPEAR_VISIBLE_FETCH = 100026,

    //Trap Abilities
    SPELL_SUMMON_CRYSTAL_PRISON = 99836,
    CRYSTAL_PRISON_EFFECT = 99837,
    SPELL_SUMMON_IMOLATION_TRAP = 99839,

    SPELL_IMMOLATION_TRAP_10N = 99838,
    SPELL_IMMOLATION_TRAP_25N = 101208,
    SPELL_IMMOLATION_TRAP_10H = 101209,
    SPELL_IMMOLATION_TRAP_25H = 101210
};

enum Events
{
    //Shannox
    EVENT_SUMMON_IMMOLATION_TRAP = 1, // Every 10s
    EVENT_BERSERK = 2, // After 10m
    EVENT_ARCING_SLASH = 3, // Every 12s
    EVENT_HURL_SPEAR_OR_MAGMA_RUPTURE = 4, // Every 42s
    EVENT_HURL_SPEAR = 5,
    EVENT_HURL_SPEAR_2 = 6,
    EVENT_SUMMON_CRYSTAL_PRISON = 7, // Every 25s
    EVENT_SUMMON_SPEAR = 8,
    EVENT_DESPAWN_SPEAR = 9,

    //Riplimb
    EVENT_LIMB_RIP = 10,
    EVENT_RIPLIMB_RESPAWN_H = 11,
    EVENT_TAKING_SPEAR_DELAY = 12,

    //Rageface
    EVENT_FACE_RAGE = 13, // Every 31s
    EVENT_CHANGE_TARGET = 14,

    // Trigger for the Crystal Trap
    EVENT_CRYSTAL_TRAP_TRIGGER = 15,

    // Trigger for the Immolation Trap
    EVENT_IMMOLATION_TRAP_TRIGGER = 16,

    // Trigger for self Dispawn (Crystal Prison)
    EVENT_CRYSTAL_PRISON_DESPAWN = 17,

    // Event trigger to reset Yells infight
    EVENT_RIPLIMB_RESET_SHANNOX_YELL = 18,
    EVENT_SHANNOX_RESET_INTRO_YELL = 19,
    EVENT_SHANNOX_SEC_INTRO_YELL = 20,

    EVENT_PRISON_DOG_ATTACK_RAGEFACE = 21,
    EVENT_PRISON_DOG_ATTACK_RIPLIMB = 22,

    // Misc
    EVENT_UPDATE_MOTION = 23
};

Position const bucketListPositions[5] =
{
{ 0.0f, 0.0f, 0.0f, 0.0f },
{ 0.0f, 0.0f, 0.0f, 0.0f },
{ 0.0f, 0.0f, 0.0f, 0.0f },
{ 0.0f, 0.0f, 0.0f, 0.0f },
{ 0.0f, 0.0f, 0.0f, 0.0f } };

// Dogs Walking Distance to Shannox
const float walkRagefaceDistance = 8;
const float walkRagefaceAngle = 7;

const float walkRiplimbDistance = 9;
const float walkRiplimbAngle = 6;

// If the Distance between Shannox & Dogs > This Value, all 3 get the Seperation Buff
const float maxDistanceBetweenShannoxAndDogs = 110;

/**** Shannox ****/
class boss_shannox: public CreatureScript
{
    public:
        boss_shannox() :
                CreatureScript("boss_shannox")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_shannoxAI(creature);
        }

        struct boss_shannoxAI: public BossAI
        {
                boss_shannoxAI(Creature* c) : BossAI(c, DATA_SHANNOX)
                {
                    instance = me->GetInstanceScript();
                    introSpeechDone = false;

                    Reset();
                }

                InstanceScript* instance;
                EventMap events;
                bool bucketListCheckPoints[5], hurlSpeer, introSpeechDone;

                void DespawnCreatures(uint32 entry, float distance)
                {
                    std::list<Creature*> creatures;
                    GetCreatureListWithEntryInGrid(creatures, me, entry, distance);

                    if (creatures.empty())
                        return;

                    for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                        (*iter)->DespawnOrUnsummon();
                }

		void DespawnObjects(uint32 entry, float distance)
		{
                    std::list<GameObject*> firedoor;
                    me->GetGameObjectListWithEntryInGrid(firedoor, 209066, 5000.0f);
			
		    if (!firedoor.empty())
                    	for (std::list<GameObject*>::const_iterator itr = firedoor.begin(); itr != firedoor.end(); ++itr)                       
				(*itr)->Delete();
		}
			

                void SetData(uint32 type, uint32 data)
                {
                    switch (type)
                    {
                        case DATA_PHASE:
                            uiPhase = data;
                            break;
                    }
                }

                bool AllowAchieve()
                {
                    for (uint8 i = 0; i < 5; ++i)
                        if (!areas[i])
                            return false;
                    return true;
                }

                uint32 GetData(uint32 id) const
                {
                    switch (id)
                    {
                        case DATA_PHASE:
                            return uiPhase;
                    }
                    return 0;
                }

                void Reset()
                {
                    uiPhase = PHASE_NON;
                    introSpeechDone = false;
                    memset(areas, false, sizeof(areas));

                    if (instance)
                    {
                        instance->SetData(DATA_SHANNOX, NOT_STARTED);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                    }

                    me->RemoveAllAuras();
                    instance->DoRemoveAurasDueToSpellOnPlayers(CRYSTAL_PRISON_EFFECT);
                    hurlSpeer = false;
                    events.Reset();

                    DespawnCreatures(NPC_CRYSTAL_PRISON, 5000.0f);
                    DespawnCreatures(NPC_SHANNOX_SPEAR, 5000.0f);
                    DespawnCreatures(NPC_FAKE_SHANNOX_SPEAR, 5000.0f);
                    DespawnCreatures(NPC_CRYSTAL_TRAP, 5000.0f);

                    if (GetRiplimb())  // Prevents Crashes
                    {
                        GetRiplimb()->Respawn(true);
                        GetRiplimb()->AI()->Reset();
                    }
                    else
                        me->SummonCreature(NPC_RIPLIMB, me->GetPositionX() - 5, me->GetPositionY() - 5, me->GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN);

                    if (GetRageface())  // Prevents Crashes
                    {
                        GetRageface()->Respawn(true);
                        GetRageface()->AI()->Reset();
                    }
                    else
                        me->SummonCreature(NPC_RAGEFACE, me->GetPositionX() + 5, me->GetPositionY() + 5, me->GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN);

                    me->LoadEquipment(1, true);

                    _Reset();
                }

                void EnterEvadeMode()
                {
                    Reset();

                    me->GetMotionMaster()->MoveTargetedHome();

                    if (instance)
                        instance->SetData(DATA_SHANNOX, FAIL);

                    _EnterEvadeMode();
                }

                void JustSummoned(Creature* summon)
                {
                    summons.Summon(summon);
                    summon->setActive(true);

                    if (me->isInCombat())
                        summon->AI()->DoZoneInCombat();
                }

                void KilledUnit(Unit * /*victim*/)
                {
                    Talk(RAND(SAY_ON_KILL_ONE, SAY_ON_KILL_TWO));
                }

                void DoAction(const int32 action)
                {
                    switch (action)
                    {
                        case ACTION_SAY_RIPLIMB:
                            Talk(SAY_RIPLIMB);
                            break;
                        case ACTION_START_EVENT_TO_RESPAWN_RIPLIMB:
                            events.ScheduleEvent(EVENT_RIPLIMB_RESPAWN_H, 30000);
                            break;
                    }
                }

                void JustDied(Unit * /*victim*/)
                {
                    Talk(SAY_ON_DEAD);

                    summons.DespawnAll();
                    instance->DoRemoveAurasDueToSpellOnPlayers(CRYSTAL_PRISON_EFFECT);

		    DespawnObjects(209066, 50000.0f);

                    if (GetRageface())
                        GetRageface()->DisappearAndDie();

                    if (GetRiplimb())
                        GetRiplimb()->DisappearAndDie();

                    if (instance)
                    {
                        instance->SetBossState(DATA_SHANNOX, DONE);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                    }

                    uiPhase = PHASE_NON;

                    _JustDied();
                }

                void EnterCombat(Unit* who)
                {
                    Talk(SAY_AGGRO);
                    memset(areas, false, sizeof(areas));

                    // Not tauntable.
                    me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);

                    if (instance)
                    {
                        instance->SetBossState(DATA_SHANNOX, IN_PROGRESS);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
                    }

                    events.ScheduleEvent(EVENT_SUMMON_IMMOLATION_TRAP, 10000);
                    events.ScheduleEvent(EVENT_ARCING_SLASH, 12000);
                    events.ScheduleEvent(EVENT_HURL_SPEAR_OR_MAGMA_RUPTURE, 20000);
                    events.ScheduleEvent(EVENT_SUMMON_CRYSTAL_PRISON, 25000);
                    events.ScheduleEvent(EVENT_BERSERK, 10 * MINUTE * IN_MILLISECONDS);

                    // Sets the current Position as Home Position prevents that Shannox is running through the Instance
                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(),
                            me->GetOrientation());

                    uiPhase = PHASE_SHANNOX_HAS_SPEER;

                    _EnterCombat();
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!me->GetVictim()) { }

                    if ((!introSpeechDone) && (!me->isInCombat()))
                    {
                        introSpeechDone = true;
                        Talk(SAY_INTRO_SPECH_PART_ONE);
                        events.ScheduleEvent(EVENT_SHANNOX_SEC_INTRO_YELL, 6500);
                        events.ScheduleEvent(EVENT_SHANNOX_RESET_INTRO_YELL, 180000); // 1:15 Min
                    }

                    if (Creature* crystalprison = me->FindNearestCreature(NPC_CRYSTAL_PRISON, 150.0f))
                        crystalprison->SetTarget(0);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    switch (me->GetAreaId())
                    {
                        case AREA_1:
                            if (!areas[0])
                                areas[0] = true;
                            break;
                        case AREA_2:
                            if (!areas[1])
                                areas[1] = true;
                            break;
                        case AREA_3:
                            if (!areas[2])
                                areas[2] = true;
                            break;
                        case AREA_4:
                            if (!areas[3])
                                areas[3] = true;
                            break;
                        case AREA_5:
                            if (!areas[4])
                                areas[4] = true;
                            break;
                    }

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_SUMMON_IMMOLATION_TRAP:
                                if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true))
                                    DoCast(tempTarget, SPELL_SUMMON_IMOLATION_TRAP);
                                events.ScheduleEvent(EVENT_SUMMON_IMMOLATION_TRAP, 10000);
                                break;

                            case EVENT_BERSERK:
                                DoCast(me, SPELL_BERSERK);
                                break;

                            case EVENT_SHANNOX_RESET_INTRO_YELL:
                                introSpeechDone = false;
                                break;

                            case EVENT_SHANNOX_SEC_INTRO_YELL:
                                Talk(SAY_INTRO_SPECH_PART_TWO);
                                break;

                            case EVENT_ARCING_SLASH:
                                if (uiPhase == PHASE_SHANNOX_HAS_SPEER)
                                {
                                    DoCastVictim(
                                            RAID_MODE(SPELL_ARCTIC_SLASH_10N, SPELL_ARCTIC_SLASH_25N,
                                                    SPELL_ARCTIC_SLASH_10H, SPELL_ARCTIC_SLASH_25H));
                                    events.ScheduleEvent(EVENT_ARCING_SLASH, 12000);
                                }
                                else
                                    events.ScheduleEvent(EVENT_ARCING_SLASH, 500);
                                break;

                            case EVENT_HURL_SPEAR:
                                if (Creature *fakeSpear = me->FindNearestCreature(NPC_FAKE_SHANNOX_SPEAR, 5000.0f,
                                        true))
                                {
                                    DoCast(fakeSpear, SPELL_HURL_SPEAR);
                                    events.ScheduleEvent(EVENT_HURL_SPEAR_2, 1000);
                                }
                                break;

                            case EVENT_HURL_SPEAR_2:
                                if (Creature *fakeSpear = me->FindNearestCreature(NPC_FAKE_SHANNOX_SPEAR, 5000.0f,
                                        true))
                                {
                                    // Shifts the Event back if Shannox has not the Spear yet
                                    me->LoadEquipment(0, true);

                                    me->SummonCreature(NPC_SHANNOX_SPEAR, fakeSpear->GetPositionX(),
                                            fakeSpear->GetPositionY(), fakeSpear->GetPositionZ());

                                    DespawnCreatures(NPC_FAKE_SHANNOX_SPEAR, 5000.0f);
                                }
                                break;

                            case EVENT_DESPAWN_SPEAR:
                                me->LoadEquipment(1, true);
                                DespawnCreatures(NPC_SHANNOX_SPEAR, 5000.0f);
                                break;

                            case EVENT_SUMMON_SPEAR:
                                if (GetSpear())
                                    DoCast(GetSpear(), SPELL_CALL_SPEAR);

                                events.ScheduleEvent(EVENT_DESPAWN_SPEAR, 700);
                                break;

                            case EVENT_HURL_SPEAR_OR_MAGMA_RUPTURE:
                                if (GetRiplimb() && GetRiplimb()->isDead())
                                {
                                    // Cast Magma Rupture when Ripclimb is Death
                                    DoCastVictim(SPELL_MAGMA_RUPTURE_SHANNOX);
                                    me->LoadEquipment(0, true);
                                    me->SummonCreature(NPC_SHANNOX_SPEAR,
                                            me->GetPositionX() - (cos(float(me->GetOrientation())) + 6),
                                            me->GetPositionY() - (sin(float(me->GetOrientation())) + 6),
                                            me->GetPositionZ());
                                    events.ScheduleEvent(EVENT_SUMMON_SPEAR, 4000);
                                    events.ScheduleEvent(EVENT_HURL_SPEAR_OR_MAGMA_RUPTURE, 42000);
                                }
                                else
                                {
                                    // Throw Spear if Riplimb is Alive and Shannox has the Spear
                                    if (uiPhase == PHASE_SHANNOX_HAS_SPEER && GetRiplimb())
                                    {
                                        events.ScheduleEvent(EVENT_HURL_SPEAR_OR_MAGMA_RUPTURE, 42000);

                                        me->SummonCreature(NPC_FAKE_SHANNOX_SPEAR,
                                                GetRiplimb()->GetPositionX() + irand(-30, 30),
                                                GetRiplimb()->GetPositionY() + irand(-30, 30),
                                                GetRiplimb()->GetPositionZ());

                                        if (Creature *fakeSpear = me->FindNearestCreature(NPC_FAKE_SHANNOX_SPEAR,
                                                5000.0f, true))
                                            events.ScheduleEvent(EVENT_HURL_SPEAR, 2000);

                                        uiPhase = PHASE_SPEAR_ON_THE_GROUND;
                                        //DoCast(SPELL_HURL_SPEAR_DUMMY_SCRIPT);

                                        Talk(RAND(SAY_BURN_ONE, SAY_BURN_TWO));

                                    }
                                    else
                                        events.ScheduleEvent(EVENT_HURL_SPEAR_OR_MAGMA_RUPTURE, 10000);
                                }
                                break;

                            case EVENT_SUMMON_CRYSTAL_PRISON:
                                if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true))
                                    DoCast(tempTarget, SPELL_SUMMON_CRYSTAL_PRISON);
                                events.ScheduleEvent(EVENT_SUMMON_CRYSTAL_PRISON, 25000);
                                break;

                            case EVENT_RIPLIMB_RESPAWN_H:
                                if (GetRiplimb())
                                {
                                    Talk(SAY_FETCH_SUPPER);
                                    GetRiplimb()->Respawn();
                                    DoZoneInCombat(GetRiplimb());
                                }
                                break;

                            default:
                                break;
                        }
                    }

                    if (!UpdateVictim())
                        return;

                    if (((GetRiplimb() && GetRiplimb()->GetDistance2d(me) >= maxDistanceBetweenShannoxAndDogs
                            && GetRiplimb()->isAlive())
                            || (GetRageface() && GetRageface()->GetDistance2d(me) >= maxDistanceBetweenShannoxAndDogs)
                                    && GetRageface()->isAlive()) && (!me->HasAura(SPELL_SEPERATION_ANXIETY)))
                        DoCast(me, SPELL_SEPERATION_ANXIETY);

                    if (uiPhase == PHASE_RIPLIMB_BRINGS_SPEER && GetRiplimb() && GetRiplimb()->GetDistance(me) <= 1)
                    {
                        uiPhase = PHASE_SHANNOX_HAS_SPEER;
                        me->LoadEquipment(1, true);

                        DespawnCreatures(NPC_SHANNOX_SPEAR, 5000.0f);

                        if (GetRiplimb()->HasAura(SPELL_DOGGED_DETERMINATION))
                            GetRiplimb()->RemoveAura(SPELL_DOGGED_DETERMINATION);

                        if (GetRiplimb()->HasAura(SPEAR_VISIBLE_FETCH))
                            GetRiplimb()->RemoveAura(SPEAR_VISIBLE_FETCH);

                        GetRiplimb()->setActive(true);
                        GetRiplimb()->GetMotionMaster()->MoveChase(GetRiplimb()->GetVictim());
                        GetRiplimb()->AI()->AttackStart(GetRiplimb()->GetVictim());
                    }
                    else if (uiPhase == PHASE_RIPLIMB_GOS_TO_SPEER && GetRiplimb() && GetRiplimb()->isAlive())
                    {
                        if (GetSpear() && !GetRiplimb()->HasAura(CRYSTAL_PRISON_EFFECT))
                        {
                            GetRiplimb()->GetMotionMaster()->MoveIdle();
                            GetRiplimb()->GetMotionMaster()->MovePoint(0, GetSpear()->GetPositionX(),
                                    GetSpear()->GetPositionY(), GetSpear()->GetPositionZ());
                        }
                    }
                    else if (uiPhase == PHASE_RIPLIMB_BRINGS_SPEER && GetRiplimb() && GetRiplimb()->isAlive())
                    {
                        GetRiplimb()->GetMotionMaster()->MoveIdle();
                        GetRiplimb()->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(),
                                me->GetPositionZ());
                    }

                    DoMeleeAttackIfReady();
                }

                Creature* GetSpear()
                {
                    return me->FindNearestCreature(NPC_SHANNOX_SPEAR, 5000.0f, true);
                }

                Creature* GetRageface()
                {
                    return (me->FindNearestCreature(NPC_RAGEFACE, 5000.0f, true) == NULL) ?
                            me->FindNearestCreature(NPC_RAGEFACE, 5000.0f, false) :
                            me->FindNearestCreature(NPC_RAGEFACE, 5000.0f, true);
                }

                Creature* GetRiplimb()
                {
                    return (me->FindNearestCreature(NPC_RIPLIMB, 5000.0f, true) == NULL) ?
                            me->FindNearestCreature(NPC_RIPLIMB, 5000.0f, false) :
                            me->FindNearestCreature(NPC_RIPLIMB, 5000.0f, true);
                }

            private:
                uint32 uiPhase;
                bool areas[5];
        };
};

/**** Rageface ****/

class npc_rageface: public CreatureScript
{
    public:
        npc_rageface() :
                CreatureScript("npc_rageface")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_ragefaceAI(creature);
        }

        struct npc_ragefaceAI: public ScriptedAI
        {
                npc_ragefaceAI(Creature *c) :
                        ScriptedAI(c)
                {
                    instance = me->GetInstanceScript();
                    me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                    me->ApplySpellImmune(0, IMMUNITY_ID, 56222, true); // Dark Command

                    Reset();
                }

                InstanceScript* instance;
                EventMap events;
                bool frenzy, prisonStartAttack;

                void Reset()
                {
                    if (instance)
                    {
                        instance->SetData(DATA_SHANNOX, NOT_STARTED);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove Frame
                    }

                    me->RemoveAllAuras();
                    events.Reset();
                    frenzy = false;
                    prisonStartAttack = false;
                }

                void KilledUnit(Unit * /*victim*/)
                {
                }

                void JustDied(Unit * /*victim*/)
                {
                    if (GetShannox())
                    {
                        GetShannox()->HasAura(SPELL_FRENZY_SHANNOX) ?
                                GetShannox()->GetAura(SPELL_FRENZY_SHANNOX)->SetStackAmount(2) :
                                DoCast(GetShannox(), SPELL_FRENZY_SHANNOX);
                        GetShannox()->MonsterTextEmote(SAY_ON_DOGS_FALL, 0, true);
                        GetShannox()->MonsterTextEmote(EMOTE_SOFT_ENRAGE, 0, true);
                    }
                    if (instance)
                    {
                        instance->SetData(DATA_SHANNOX, DONE);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove Frame
                    }
                }

                void EnterCombat(Unit * /*who*/)
                {
                    if (instance)
                    {
                        instance->SetData(DATA_SHANNOX, IN_PROGRESS);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Remove Frame
                    }

                    if (Creature* shannox = me->FindNearestCreature(NPC_SHANNOX, 250.0f, true))
                    {
                        if (Unit* player = me->FindNearestPlayer(250.0f, true))
                            shannox->AI()->AttackStart(player);
                    }

                    me->GetMotionMaster()->MoveIdle();
                    me->GetMotionMaster()->MoveChase(me->GetVictim());

                    events.ScheduleEvent(EVENT_CHANGE_TARGET, urand(9000, 15000));

                    events.ScheduleEvent(EVENT_FACE_RAGE, urand(24000, 30000));
                }

                void SelectNewTarget()
                {
                    if (!me->HasAura(CRYSTAL_PRISON_EFFECT))
                        if (Unit *shallTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true))
                        {
                            me->getThreatManager().resetAllAggro();
                            me->AddThreat(shallTarget, 500.0f);

                            if (me->GetDistance(shallTarget) >= 13.0f)
                                me->JumpTo(shallTarget, 15);

                            me->GetMotionMaster()->MoveChase(shallTarget);
                            me->AI()->AttackStart(shallTarget);
                        }
                }

                void DamageTaken(Unit* who, uint32& damage)
                {
                    if (damage >= 40000
                            && me->HasAura(
                                    RAID_MODE(SPELL_FACE_RAGE_10N, SPELL_FACE_RAGE_25N, SPELL_FACE_RAGE_10H,
                                            SPELL_FACE_RAGE_25H)))
                    {
                        me->GetVictim()->RemoveAurasDueToSpell(SPELL_FACE_RAGE);
                        me->RemoveAurasDueToSpell(
                                RAID_MODE(SPELL_FACE_RAGE_10N, SPELL_FACE_RAGE_25N, SPELL_FACE_RAGE_10H,
                                        SPELL_FACE_RAGE_25H));
                    }
                }

                void UpdateAI(const uint32 diff)
                {
                    if (me->GetVictim())
                        if (!me->HasAura(
                                RAID_MODE(SPELL_FACE_RAGE_10N, SPELL_FACE_RAGE_25N, SPELL_FACE_RAGE_10H,
                                        SPELL_FACE_RAGE_25H)) && me->GetVictim()->HasAura(SPELL_FACE_RAGE)
                                && !me->HasAura(CRYSTAL_PRISON_EFFECT))
                        {
                            if (Unit *RageTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true, SPELL_RAGE))
                            {
                                me->getThreatManager().resetAllAggro();
                                me->AddThreat(RageTarget, 500.0f);

                                if (me->GetDistance(RageTarget) >= 13.0f)
                                    me->JumpTo(RageTarget, 15);

                                me->GetMotionMaster()->MoveChase(RageTarget);
                                me->AI()->AttackStart(RageTarget);
                            }
                            me->GetVictim()->RemoveAurasDueToSpell(SPELL_FACE_RAGE);
                        }

                    if (GetShannox() && !me->isInCombat())
                    {
                        if (me->GetDistance(GetShannox()) > 20.0f)
                            me->SetPosition(GetShannox()->GetPositionX() + 5, GetShannox()->GetPositionY() - 5,
                                    GetShannox()->GetPositionZ(), 0);
                        else
                            me->GetMotionMaster()->MoveFollow(GetShannox(), walkRagefaceDistance, walkRagefaceAngle);
                    }

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CHANGE_TARGET:
                                if(me->GetVictim())
                                    if (!me->GetVictim()->HasAura(SPELL_RAGE) && !me->HasAura(RAID_MODE(SPELL_FACE_RAGE_10N, SPELL_FACE_RAGE_25N, SPELL_FACE_RAGE_10H, SPELL_FACE_RAGE_25H)))
                                        SelectNewTarget();
                                events.ScheduleEvent(EVENT_CHANGE_TARGET, urand(9000, 15000));
                                break;
                            case EVENT_FACE_RAGE:
                                if (Unit *FaceRageTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500, true))
                                {
                                    me->getThreatManager().resetAllAggro();
                                    me->AddThreat(FaceRageTarget, 500.0f);

                                    if (me->GetDistance(FaceRageTarget) >= 13.0f)
                                        me->JumpTo(FaceRageTarget, 15);

                                    me->GetMotionMaster()->MoveChase(FaceRageTarget);
                                    me->AI()->AttackStart(FaceRageTarget);
                                    DoCast(FaceRageTarget, SPELL_FACE_RAGE);
                                }
                                events.ScheduleEvent(EVENT_FACE_RAGE, 61000);
                                break;
                            case EVENT_PRISON_DOG_ATTACK_RAGEFACE:
                                if (Creature *prison = me->FindNearestCreature(NPC_CRYSTAL_PRISON, 50.0f, true))
                                {
                                    int32 dmg = prison->GetMaxHealth() * 0.20;
                                    me->DealDamage(prison, dmg);
                                    if (prison->isAlive())
                                        events.ScheduleEvent(EVENT_PRISON_DOG_ATTACK_RAGEFACE, 1000);
                                }
                                break;
                            default:
                                break;
                        }
                    }

                    if (me->HasAura(CRYSTAL_PRISON_EFFECT) && !prisonStartAttack)
                        if (Creature *prison = me->FindNearestCreature(NPC_CRYSTAL_PRISON, 50.0f, true))
                        {
                            events.ScheduleEvent(EVENT_PRISON_DOG_ATTACK_RAGEFACE, 1000);
                            prisonStartAttack = true;
                        }

                    if (GetShannox())
                    {
                        if (GetShannox()->GetHealthPct() <= 30 && frenzy == false && !me->GetMap()->IsHeroic())
                        {
                            frenzy = true;
                            DoCast(me, SPELL_FRENZIED_DEVOLUTION);
                        }

                        if (GetShannox()->GetDistance(me) >= maxDistanceBetweenShannoxAndDogs
                                && !me->HasAura(SPELL_SEPERATION_ANXIETY)) //
                        {
                            DoCast(me, SPELL_SEPERATION_ANXIETY);
                        }

                    }

                    if (!UpdateVictim())
                        return;

                    if (Unit* victim = me->GetVictim()) // DoMeleeAttackIfReady implementation of Feeding Frenzy.
                        if (me->isAttackReady() && me->IsWithinMeleeRange(victim))
                        {
                            me->AttackerStateUpdate(victim);
                            me->resetAttackTimer();

                            if (me->GetMap()->IsHeroic())
                                me->AddAura(SPELL_FEEDING_FRENZY_H, me);
                        }
                }

                Creature* GetShannox()
                {
                    return me->FindNearestCreature(NPC_SHANNOX, 5000.0f, true);
                }

        };
};

/**** Riplimb ****/

class npc_riplimb: public CreatureScript
{
    public:
        npc_riplimb() :
                CreatureScript("npc_riplimb")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_riplimbAI(creature);
        }

        struct npc_riplimbAI: public ScriptedAI
        {
                npc_riplimbAI(Creature *c) :
                        ScriptedAI(c), vehicle(c->GetVehicleKit())
                {
                    instance = me->GetInstanceScript();

                    Reset();
                }

                InstanceScript* instance;
                EventMap events;
                bool frenzy, inTakingSpearPhase, firstLimbRip, prisonStartAttack;
                Vehicle* vehicle;

                void Reset()
                {
                    if (instance)
                    {
                        instance->SetData(DATA_SHANNOX, NOT_STARTED);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove Frame
                    }

                    me->RemoveAllAuras();
                    events.Reset();
                    prisonStartAttack = false;
                    frenzy = false; // Is needed, that Frenzy is not casted twice on Riplimb
                    inTakingSpearPhase = false; // Is needed for correct execution of the Phases
                    firstLimbRip = false;
                }

                void KilledUnit(Unit * /*victim*/)
                {
                }

                void JustDied(Unit * /*victim*/)
                {
                    if (GetShannox())
                    {
                        // Heroic: Respawn Riplimb 30s after he is Death (Trigger)
                        if (GetShannox()->GetMap()->IsHeroic())
                        {
                            GetShannox()->AI()->DoAction(ACTION_START_EVENT_TO_RESPAWN_RIPLIMB);
                            GetShannox()->GetAI()->DoAction(ACTION_SAY_RIPLIMB);
                        }
                        GetShannox()->HasAura(SPELL_FRENZY_SHANNOX) ?
                                GetShannox()->GetAura(SPELL_FRENZY_SHANNOX)->SetStackAmount(2) :
                                DoCast(GetShannox(), SPELL_FRENZY_SHANNOX);
                        GetShannox()->MonsterTextEmote(SAY_ON_DOGS_FALL, 0, true);
                        GetShannox()->MonsterTextEmote(EMOTE_SOFT_ENRAGE, 0, true);
                    }
                    if (instance)
                    {
                        instance->SetData(DATA_SHANNOX, DONE);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove Frame
                    }
                }

                void EnterCombat(Unit * who)
                {
                    if (instance)
                    {
                        instance->SetData(DATA_SHANNOX, IN_PROGRESS);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add Frame
                    }

                    if (Creature* shannox = me->FindNearestCreature(NPC_SHANNOX, 250.0f, true))
                    {
                        if (Unit* player = me->FindNearestPlayer(250.0f, true))
                            shannox->AI()->AttackStart(player);
                    }

                    prisonStartAttack = false;
                    inTakingSpearPhase = false;

                    me->GetMotionMaster()->MoveIdle();
                    me->GetMotionMaster()->MoveChase(me->GetVictim());

                    events.ScheduleEvent(EVENT_LIMB_RIP, 12000); //TODO Find out the correct Time
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!me->GetVictim())
                    {
                    }

                    if (GetShannox() && !me->isInCombat())
                    {
                        if (me->GetDistance(GetShannox()) > 20.0f)
                            me->SetPosition(GetShannox()->GetPositionX() + 5, GetShannox()->GetPositionY() - 5,
                                    GetShannox()->GetPositionZ(), 0);
                        else
                            me->GetMotionMaster()->MoveFollow(GetShannox(), walkRiplimbDistance, walkRiplimbAngle);
                    }

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_LIMB_RIP:
                                DoCastVictim(SPELL_LIMB_RIP);

                                if (GetShannox() && !firstLimbRip)
                                {
                                    firstLimbRip = true;
                                    Talk(SAY_GO_FOR_THROAT);
                                    events.ScheduleEvent(EVENT_RIPLIMB_RESET_SHANNOX_YELL, 45000); // Resets Yell after 45s
                                }

                                events.ScheduleEvent(EVENT_LIMB_RIP, 12000); //TODO Find out the correct Time
                                break;

                            case EVENT_TAKING_SPEAR_DELAY:
                                inTakingSpearPhase = false;
                                if (GetShannox())
                                    GetShannox()->AI()->SetData(DATA_PHASE, PHASE_RIPLIMB_GOS_TO_SPEER);
                                break;

                            case EVENT_RIPLIMB_RESET_SHANNOX_YELL:
                                firstLimbRip = false;
                                break;

                            case EVENT_PRISON_DOG_ATTACK_RIPLIMB:
                                if (Creature *prison = me->FindNearestCreature(NPC_CRYSTAL_PRISON, 50.0f, true))
                                {
                                    int32 dmg = prison->GetMaxHealth() * 0.10;
                                    me->DealDamage(prison, dmg);
                                    if (prison->isAlive())
                                        events.ScheduleEvent(EVENT_PRISON_DOG_ATTACK_RIPLIMB, 1000);
                                }
                                break;

                            default:
                                break;
                        }
                    }

                    if (me->HasAura(CRYSTAL_PRISON_EFFECT) && !prisonStartAttack)
                        if (Creature *prison = me->FindNearestCreature(NPC_CRYSTAL_PRISON, 50.0f, true))
                        {
                            events.ScheduleEvent(EVENT_PRISON_DOG_ATTACK_RIPLIMB, 1000);
                            prisonStartAttack = true;
                        }

                    if (GetShannox())
                    {
                        if (GetShannox()->GetHealthPct() <= 30 && frenzy == false && !me->GetMap()->IsHeroic())
                        {
                            frenzy = true;
                            DoCast(me, SPELL_FRENZIED_DEVOLUTION);
                        }

                        if (GetShannox()->GetDistance(me) >= maxDistanceBetweenShannoxAndDogs
                                && !me->HasAura(SPELL_SEPERATION_ANXIETY)) //TODO Sniff right Distance
                            DoCast(me, SPELL_SEPERATION_ANXIETY);

                        if (GetShannox()->AI()->GetData(DATA_PHASE) == PHASE_SPEAR_ON_THE_GROUND && !inTakingSpearPhase)
                        {
                            inTakingSpearPhase = true;
                            events.ScheduleEvent(EVENT_TAKING_SPEAR_DELAY, 7500);
                        }

                        if (GetSpear())
                        {
                            if (GetShannox()->AI()->GetData(DATA_PHASE) == PHASE_RIPLIMB_GOS_TO_SPEER
                                    && GetSpear()->GetDistance(me) <= 1)
                            {
                                GetShannox()->AI()->SetData(DATA_PHASE, PHASE_RIPLIMB_BRINGS_SPEER);
                                GetSpear()->DespawnOrUnsummon();
                                me->AddAura(SPEAR_VISIBLE_FETCH, me);

                                DoCast(me, SPELL_DOGGED_DETERMINATION);
                            }
                        }
                    }

                    if (!UpdateVictim())
                        return;

                    if (Unit* victim = me->GetVictim()) // DoMeleeAttackIfReady implementation of Feeding Frenzy.
                        if (me->isAttackReady() && me->IsWithinMeleeRange(victim))
                        {
                            me->AttackerStateUpdate(victim);
                            me->resetAttackTimer();

                            if (me->GetMap()->IsHeroic())
                                me->AddAura(SPELL_FEEDING_FRENZY_H, me);
                        }
                }

                inline Creature* GetShannox()
                {
                    return me->FindNearestCreature(NPC_SHANNOX, 5000.0f, true);
                }

                inline Creature* GetSpear()
                {
                    return GetShannox()->FindNearestCreature(NPC_SHANNOX_SPEAR, 5000.0f, true);
                }
        };
};

/**** Shannox Fake Spear ****/

class npc_shannox_fake_spear: public CreatureScript
{
    public:
        npc_shannox_fake_spear() :
                CreatureScript("npc_shannox_fake_spear")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_shannox_fake_spearAI(creature);
        }

        struct npc_shannox_fake_spearAI: public ScriptedAI
        {
                npc_shannox_fake_spearAI(Creature *c) :
                        ScriptedAI(c)
                {
                    me->SetReactState(REACT_PASSIVE);
                    me->AddAura(RED_TARGET_AUR, me);
                    me->SetDisplayId(11686);

                    instance = me->GetInstanceScript();

                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }

                InstanceScript* instance;
        };
};

/**** Shannox Spear ****/

class npc_shannox_spear: public CreatureScript
{
    public:
        npc_shannox_spear() :
                CreatureScript("npc_shannox_spear")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_shannox_spearAI(creature);
        }

        struct npc_shannox_spearAI: public ScriptedAI
        {
                npc_shannox_spearAI(Creature *c) :
                        ScriptedAI(c)
                {
                    instance = me->GetInstanceScript();
                    me->AddAura(SPEAR_VISIBLE_ON_GROUND, me);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                }

                InstanceScript* instance;

                void Reset()
                {
                }

                void JustDied(Unit * /*victim*/)
                {
                }

                void EnterCombat(Unit * /*who*/)
                {
                    DoCast(SPELL_MAGMA_FLARE);

                    // Calcs 3 Circles
                    for (float r = 0; r <= 30; r = r + 10)
                        for (float x = 0; x <= r * 2; x = x + 2)
                        {
                            GetShannox()->CastSpell(me->GetPositionX() + cos(x) * r, me->GetPositionY() + sin(x) * r,
                                    me->GetPositionZ(), SPELL_MAGMA_RUPTURE_VISUAL, true);

                            GetShannox()->CastSpell(me->GetPositionX() - cos(x) * r, me->GetPositionY() - sin(x) * r,
                                    me->GetPositionZ(), SPELL_MAGMA_RUPTURE_VISUAL, true);
                        }
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim())
                        return;
                }

                Creature* GetShannox()
                {
                    return me->FindNearestCreature(NPC_SHANNOX, 5000.0f, true);
                }
        };
};

/**** Immolation Trap****/

class npc_immolation_trap: public CreatureScript
{
    public:
        npc_immolation_trap() :
                CreatureScript("npc_immolation_trap")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_immolation_trapAI(creature);
        }

        struct npc_immolation_trapAI: public Scripted_NoMovementAI
        {
                npc_immolation_trapAI(Creature *c) :
                        Scripted_NoMovementAI(c)
                {
                    instance = me->GetInstanceScript();
                    tempTarget = NULL;
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS,
                            UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
                    events.Reset();
                }

                InstanceScript* instance;
                EventMap events;
                Unit* tempTarget;

                void JustDied(Unit * /*victim*/)
                {
                }

                void Reset()
                {
                    events.Reset();
                }

                void EnterCombat(Unit * /*who*/)
                {
                    events.ScheduleEvent(EVENT_IMMOLATION_TRAP_TRIGGER, 2000);
                }

                void UpdateAI(const uint32 diff)
                {
                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_IMMOLATION_TRAP_TRIGGER:
                                //Riplimb and Rageface has a higher Priority than Players...

                                if (GetRiplimb() && GetRiplimb()->GetDistance(me) <= 3.0f
                                        && !GetRiplimb()->HasAura(
                                                RAID_MODE(SPELL_WARY_10N, SPELL_WARY_25N, SPELL_WARY_10H,
                                                        SPELL_WARY_25H)) && GetRiplimb()->isAlive()
                                        && GetShannox()->AI()->GetData(DATA_PHASE) == PHASE_SHANNOX_HAS_SPEER)
                                    tempTarget = GetRiplimb();
                                else if (GetRageface() && GetRageface()->GetDistance(me) <= 3.0f
                                        && !GetRageface()->HasAura(
                                                RAID_MODE(SPELL_WARY_10N, SPELL_WARY_25N, SPELL_WARY_10H,
                                                        SPELL_WARY_25H)) && GetRageface()->isAlive())
                                    tempTarget = GetRageface();
                                else
                                    tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 1.0f, true);

                                if (!tempTarget || tempTarget->HasAura(CRYSTAL_PRISON_EFFECT)) // If no Target exists try to get a new Target in 0,5s
                                    events.ScheduleEvent(EVENT_IMMOLATION_TRAP_TRIGGER, 500);
                                else
                                {
                                    DoCast(tempTarget,
                                            RAID_MODE(SPELL_IMMOLATION_TRAP_10N, SPELL_IMMOLATION_TRAP_25N,
                                                    SPELL_IMMOLATION_TRAP_10H, SPELL_IMMOLATION_TRAP_25H));

                                    // Cast Spell Wary on Dogs
                                    if (tempTarget->GetEntry() == NPC_RIPLIMB || tempTarget->GetEntry() == NPC_RAGEFACE)
                                        tempTarget->AddAura(
                                                RAID_MODE(SPELL_WARY_10N, SPELL_WARY_25N, SPELL_WARY_10H,
                                                        SPELL_WARY_25H), tempTarget);

                                    me->DisappearAndDie();
                                }

                                break;
                            default:
                                break;
                        }
                    }
                }

                Creature* GetShannox()
                {
                    return me->FindNearestCreature(NPC_SHANNOX, 5000.0f, true);
                }

                Creature* GetRiplimb()
                {
                    return me->FindNearestCreature(NPC_RIPLIMB, 5000.0f, true);
                }

                Creature* GetRageface()
                {
                    return me->FindNearestCreature(NPC_RAGEFACE, 5000.0f, true);
                }
        };
};

/**** Crystal Trap ****/

class npc_crystal_trap: public CreatureScript
{
    public:
        npc_crystal_trap() :
                CreatureScript("npc_crystal_trap")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_crystal_trapAI(creature);
        }

        struct npc_crystal_trapAI: public Scripted_NoMovementAI
        {
                npc_crystal_trapAI(Creature *c) :
                        Scripted_NoMovementAI(c)
                {
                    instance = me->GetInstanceScript();
                    tempTarget = NULL;
                    myPrison = NULL;
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS,
                            UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
                    events.Reset();
                }

                InstanceScript* instance;
                EventMap events;
                Unit* tempTarget;
                Creature* myPrison;

                void JustDied(Unit * /*victim*/)
                {
                }

                void Reset()
                {
                    events.Reset();
                }

                void EnterCombat(Unit * /*who*/)
                {
                    events.ScheduleEvent(EVENT_CRYSTAL_TRAP_TRIGGER, 2000); //  The trap arms after 2 seconds.
                }

                void UpdateAI(const uint32 diff)
                {

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CRYSTAL_TRAP_TRIGGER:

                                //Riplimb has a higher Priority than Players...

                                if (GetRiplimb() && GetRiplimb()->GetDistance(me) <= 2.0f
                                        && (!GetRiplimb()->HasAura(
                                                RAID_MODE(SPELL_WARY_10N, SPELL_WARY_25N, SPELL_WARY_10H,
                                                        SPELL_WARY_25H))) && GetRiplimb()->isAlive()
                                        && GetShannox()->AI()->GetData(DATA_PHASE) == PHASE_SHANNOX_HAS_SPEER)
                                    tempTarget = GetRiplimb();
                                else if (GetRageface() && GetRageface()->GetDistance(me) <= 3.0f
                                        && !GetRageface()->HasAura(
                                                RAID_MODE(SPELL_WARY_10N, SPELL_WARY_25N, SPELL_WARY_10H,
                                                        SPELL_WARY_25H)) && GetRageface()->isAlive())
                                    tempTarget = GetRageface();
                                else
                                    tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 2.0f, true);

                                if (!tempTarget || tempTarget->HasAura(CRYSTAL_PRISON_EFFECT)) // If no Target exists try to get a new Target in 0,5s
                                    events.ScheduleEvent(EVENT_CRYSTAL_TRAP_TRIGGER, 500);
                                else
                                {
                                    // Intialize Prison if tempTarget was set
                                    DoCast(tempTarget, CRYSTAL_PRISON_EFFECT);
                                    myPrison = me->SummonCreature(NPC_CRYSTAL_PRISON, tempTarget->GetPositionX(),
                                            tempTarget->GetPositionY(), tempTarget->GetPositionZ(), 0,
                                            TEMPSUMMON_MANUAL_DESPAWN);

                                    if (myPrison)
                                    {
                                        me->SetReactState(REACT_AGGRESSIVE);
                                        myPrison->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                                    }

                                    events.ScheduleEvent(EVENT_CRYSTAL_PRISON_DESPAWN, 20000);
                                }

                                break;

                            case EVENT_CRYSTAL_PRISON_DESPAWN:

                                if (tempTarget)
                                {
                                    myPrison->DisappearAndDie();
                                    tempTarget->RemoveAurasDueToSpell(CRYSTAL_PRISON_EFFECT);
                                    // Cast Spell Wary on Dogs
                                    if (tempTarget->GetEntry() == NPC_RIPLIMB || tempTarget->GetEntry() == NPC_RAGEFACE)
                                        tempTarget->AddAura(
                                                RAID_MODE(SPELL_WARY_10N, SPELL_WARY_25N, SPELL_WARY_10H,
                                                        SPELL_WARY_25H), tempTarget);

                                    me->DisappearAndDie();
                                }
                                break;
                            default:
                                break;
                        }
                    }

                    if (myPrison && myPrison->isDead())
                    {
                        myPrison->DisappearAndDie();
                        tempTarget->RemoveAurasDueToSpell(CRYSTAL_PRISON_EFFECT);
                        // Cast Spell Wary on Dogs
                        if (tempTarget->GetEntry() == NPC_RIPLIMB || tempTarget->GetEntry() == NPC_RAGEFACE)
                            tempTarget->AddAura(
                                    RAID_MODE(SPELL_WARY_10N, SPELL_WARY_25N, SPELL_WARY_10H, SPELL_WARY_25H),
                                    tempTarget);

                        me->DisappearAndDie();
                    }
                }

                Creature* GetShannox()
                {
                    return me->FindNearestCreature(NPC_SHANNOX, 5000.0f, true);
                }

                Creature* GetRiplimb()
                {
                    return me->FindNearestCreature(NPC_RIPLIMB, 5000.0f, true);
                }

                Creature* GetRageface()
                {
                    return me->FindNearestCreature(NPC_RAGEFACE, 5000.0f, true);
                }
        };
};

class spell_shannox_riplimb_dogged_determination : public SpellScriptLoader
{
    public:
        spell_shannox_riplimb_dogged_determination() : SpellScriptLoader("spell_shannox_riplimb_dogged_determination") { }

        class spell_shannox_riplimb_dogged_determination_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_shannox_riplimb_dogged_determination_AuraScript);

            void PeriodicTick(AuraEffect const* aurEff)
            {
                if (!GetCaster())
                    return;

                if (Aura* aur = GetAura())
                {
                    if (AuraEffect* auraEff = aur->GetEffect(EFFECT_0))
                    {
                        int32 curr_amount = auraEff->GetAmount();
                        if (curr_amount < 100)
                            auraEff->SetAmount(curr_amount + 5);
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_shannox_riplimb_dogged_determination_AuraScript::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_shannox_riplimb_dogged_determination_AuraScript();
        }
};

class spell_shannox_crystal_prison_trap : public SpellScriptLoader
{
    public:
        spell_shannox_crystal_prison_trap() : SpellScriptLoader("spell_shannox_crystal_prison_trap") { }

        class spell_shannox_crystal_prison_trap_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_shannox_crystal_prison_trap_AuraScript);

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster() || !GetTarget())
                    return;

                Position pos;
                GetTarget()->GetPosition(&pos);
                if (Creature* pCrystalPrison = GetCaster()->SummonCreature(NPC_CRYSTAL_PRISON, pos))
                    pCrystalPrison->AI()->SetGUID(GetTarget()->GetGUID(), (GetTarget()->GetTypeId() == TYPEID_PLAYER)? DATA_TRAPPED_PLAYER: DATA_TRAPPED_DOG);
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                if (GetTarget()->GetEntry() == NPC_RIPLIMB || GetTarget()->GetEntry() == NPC_RAGEFACE)
                    GetTarget()->CastSpell(GetTarget(), SPELL_WARY_10N, true);
            }
            
            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_shannox_crystal_prison_trap_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_shannox_crystal_prison_trap_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_shannox_crystal_prison_trap_AuraScript();
        }
};

class spell_shannox_immolation_trap : public SpellScriptLoader
{
    public:
        spell_shannox_immolation_trap() : SpellScriptLoader("spell_shannox_immolation_trap") { }


        class spell_shannox_immolation_trap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shannox_immolation_trap_SpellScript);


            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit() && (GetHitUnit()->GetEntry() == NPC_RIPLIMB || GetHitUnit()->GetEntry() == NPC_RAGEFACE))
                    GetHitUnit()->CastSpell(GetHitUnit(), SPELL_WARY_10N, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_shannox_immolation_trap_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_shannox_immolation_trap_SpellScript();
        }
};

typedef boss_shannox::boss_shannoxAI ShannoxAI;

class achievement_bucket_list : public AchievementCriteriaScript
{
    public:
        achievement_bucket_list() : AchievementCriteriaScript("achievement_bucket_list") { }

        bool OnCheck(Player* source, Unit* target)
        {
            if (!target)
                return false;

            if (ShannoxAI* shannoxAI = CAST_AI(ShannoxAI, target->GetAI()))
                return shannoxAI->AllowAchieve();

            return false;
        }
};

void AddSC_boss_shannox()
{
    new boss_shannox();
    new npc_rageface();
    new npc_riplimb();
    new npc_shannox_spear();
    new npc_shannox_fake_spear();
    new npc_crystal_trap();
    new npc_immolation_trap();
    new spell_shannox_riplimb_dogged_determination();
    new spell_shannox_crystal_prison_trap();
    new spell_shannox_immolation_trap();
    new achievement_bucket_list();
}
