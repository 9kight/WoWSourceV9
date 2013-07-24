#include "bastion_of_twilight.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "Vehicle.h"
#include "CombatAI.h"
#include "GameObjectAI.h"
#include "CreatureTextMgr.h"
#include "MoveSplineInit.h"


enum Spells
{
    SPELL_BIND_WILL             = 83432,
    SPELL_FRENZIED_ASSAULT      = 83693,
    SPELL_FURIOUS_ROAR          = 83710,
    SPELL_MALEVOLENT_STRIKES    = 39171,
    SPELL_SHADOW_WRAPPED        = 83952,
    SPELL_SHADOW_NOVA           = 83703,
    SPELL_DRAGONS_VENGEANCE     = 87683,
    // Nether Scion
    SPELL_NETHER_BLINDNESS      = 83611,
    // Whelps
    SPELL_ATROPHIC_POISON       = 83609,
    // Slate Dragon
    SPELL_STONE_TOUCH           = 83603,
    SPELL_STONE_GRIP            = 84593,
    SPELL_PARALYSIS             = 84030,
    // Storm Rider
    SPELL_CYCLONE_WINDS         = 84092,
    // Time Warden
    SPELL_TIME_DILATION         = 83601,
    // Proto-Behemoth
    SPELL_FIREBALL              = 61909,
    SPELL_CHAIN                 = 83487,
    SPELL_UNRESPONSIVE          = 86003
};

enum Events
{
    EVENT_FURIOUS_ROAR          = 1,
    EVENT_SHADOW_NOVA,
    EVENT_ENRAGE
};

enum Entities
{
    NPC_TIME_WARDEN             = 44797,
    NPC_NETHER_SCION            = 44645,
    NPC_STORM_RIDER             = 44650,
    NPC_SLATE_DRAGON            = 44652,
    NPC_SPIKE                   = 44765,
    NPC_PROTO_BEHEMOTH          = 44687,
    NPC_ORPHANED_WHELP          = 44641,
    GO_WHELP_CAGE               = 205087,
};

enum Misc
{
    MAX_DRAKES                  = 5,
    MAX_ACTIVE_DRAKES           = 3,
    MAX_WHELPS                  = 8,

    FACTION_HOSTILE             = 14,
    ACTION_ENABLE_BLAST         = 1,
    ACTION_ENABLE_BARRAGE       = 2,
    ACTION_ENTER_COMBAT         = 3,
};

enum Text
{
    SAY_AGGRO,
    SAY_SLAY,
    SAY_BIND_WILL,
    SAY_ROAR
};

static const uint32 DRAKE_HELPER[MAX_DRAKES]  = {NPC_TIME_WARDEN, NPC_NETHER_SCION, NPC_STORM_RIDER, NPC_SLATE_DRAGON, GO_WHELP_CAGE};
static const Position drakePos[MAX_DRAKES] =
{
    {-353.179f, -700.667f, 888.1903f, 5.532694f},
    {-280.118f, -659.385f, 888.1883f, 1.675516f},
    {-318.705f, -722.688f, 888.1913f, 3.193953f},
    {-279.111f, -680.594f, 888.1913f, 3.106686f},
    {-346.672f, -723.26f, 888.106f, 5.532695f}
};

static const Position whelpPos[MAX_WHELPS] =
{
    {-347.578f, -717.302f, 891.7633f, 1.047198f},
    {-350.564f, -721.663f, 891.7633f, 1.012291f},
    {-350.571f, -725.417f, 891.7633f, 1.064651f},
    {-344.839f, -720.163f, 891.7643f, 1.082104f},
    {-346.434f, -724.049f, 891.7643f, 1.099557f},
    {-347.08f, -728.128f, 891.7643f, 1.117011f},
    {-340.75f, -722.476f, 891.7643f, 1.169371f},
    {-342.002f, -726.528f, 891.7643f, 1.169371f},
};
static const Position behemothPos = {-265.891f, -740.023f, 907.3633f, 2.338741f};

class boss_halfus_wyrmbreaker : public CreatureScript
{
    struct boss_halfus_wyrmbreakerAI : public BossAI
    {
        boss_halfus_wyrmbreakerAI(Creature * creature) : BossAI(creature, BOSS_HALFUS), summons(me)
        {
            initTimer = 5000;
        }

        void Reset()
        {
            roarCnt = 0;
            _Reset();

            if (!initTimer)
            {
                for (int i=0; i<MAX_ACTIVE_DRAKES; ++i)
                {
                    switch(drakes[i])
                    {
                    case NPC_NETHER_SCION:
                        DoCast(me, SPELL_FRENZIED_ASSAULT, true);
                        break;
                    case NPC_STORM_RIDER:
                        DoCast(me, SPELL_SHADOW_WRAPPED, true);
                        events.ScheduleEvent(EVENT_SHADOW_NOVA, urand(10000, 15000));
                        break;
                    case NPC_SLATE_DRAGON:
                        DoCast(me, SPELL_MALEVOLENT_STRIKES, true);
                        break;
                        // Affects Proto-Behemoth
                    case GO_WHELP_CAGE:
                    if (Creature* creature = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_PROTO_BEHEMOTH)))
                        creature->AI()->DoAction(ACTION_ENABLE_BLAST);
                        break;
                    case NPC_TIME_WARDEN:
                    if (Creature* creature = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_PROTO_BEHEMOTH)))
                        creature->AI()->DoAction(ACTION_ENABLE_BARRAGE);
                        break;
                    default:
                        break;
                    }
                }
            }
        }

        void SpellHit(Unit * /*caster*/, const SpellInfo *spell)
        {
            if (Spell * curSpell = me->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                if(curSpell->GetSpellInfo()->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_SHADOW_NOVA, me))
                    for (uint8 i = 0; i < 3; ++i)
                        if (spell->Effects[i].Effect == SPELL_EFFECT_INTERRUPT_CAST)
                            me->InterruptSpell(CURRENT_GENERIC_SPELL, false);
        }

        void JustReachedHome()
        {
            for (int i=0; i<MAX_DRAKES; ++i)
            {
                if(IS_CREATURE_GUID(drakeGUIDs[i]))
                {
                    if(Creature * creature = me->GetCreature(*me, drakeGUIDs[i]))
                    {
                        if(creature->isDead())
                        {
                            creature->Respawn(true);
                            creature->GetMotionMaster()->MoveTargetedHome();
                        }
                        if (i < MAX_ACTIVE_DRAKES)
                            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    }
                }
                else
                    if(GameObject * go = me->GetMap()->GetGameObject(drakeGUIDs[i]))
                        go->SetGoState(GO_STATE_READY);
            }

            for(int i=0; i<MAX_WHELPS; ++i)
                me->SummonCreature(NPC_ORPHANED_WHELP, whelpPos[i]);
        }

        void InitDrakes()
        {
            for (int i = 0; i < MAX_DRAKES; ++i)
                drakes[i] = i;

            std::random_shuffle(drakes, drakes + MAX_DRAKES);

            if (Creature * creature = me->SummonCreature(NPC_PROTO_BEHEMOTH, behemothPos))
                creature->SetCanFly(true);

            for (int i=0; i<MAX_DRAKES; ++i)
            {
                if (DRAKE_HELPER[drakes[i]] == GO_WHELP_CAGE)
                {
                    if (GameObject * go = me->SummonGameObject(DRAKE_HELPER[drakes[i]], drakePos[drakes[i]].GetPositionX(), drakePos[drakes[i]].GetPositionY(), drakePos[drakes[i]].GetPositionZ(), drakePos[drakes[i]].GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, 0))
                    {
                        me->RemoveGameObject(go, false);
                        drakeGUIDs.push_back(go->GetGUID());
                        // guid of a hostile creature makes the GO non-interactable
                        if(i < MAX_ACTIVE_DRAKES)
                            go->SetUInt64Value(OBJECT_FIELD_CREATED_BY, 0);
                        go->SetUserData(me->GetGUID());
                    }
                }
                else
                {
                    if (Creature * creature = me->SummonCreature(DRAKE_HELPER[drakes[i]], drakePos[drakes[i]]))
                    {
                        drakeGUIDs.push_back(creature->GetGUID());
                        if (i < MAX_ACTIVE_DRAKES)
                        {
                            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            std::list<Creature*> cList;
                            creature->GetCreatureListWithEntryInGrid(cList, NPC_SPIKE, 15.0f);
                            std::cout << cList.size() << std::endl;
                            for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                                (*itr)->CastSpell(creature, SPELL_CHAIN, true);
                        }
                        else
                            creature->CastSpell(creature, SPELL_UNRESPONSIVE, true);
                    }
                }
                drakes[i] = DRAKE_HELPER[drakes[i]];
            }

            Reset();

            for(int i=0; i<MAX_WHELPS; ++i)
                me->SummonCreature(NPC_ORPHANED_WHELP, whelpPos[i]);
        }

        void EnterCombat(Unit * /*who*/)
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_ENRAGE, 360000);
        if (Creature* creature = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_PROTO_BEHEMOTH)))
            creature->AI()->DoAction(ACTION_ENTER_COMBAT);
            _EnterCombat();
        }

        void JustSummoned(Creature * summon)
        {
            if(summon->GetEntry() == NPC_ORPHANED_WHELP)
                BossAI::JustSummoned(summon);
            else
                summons.Summon(summon);
        }

        void JustDied(Unit * )
        {
            _JustDied();
            summons.DespawnAll();
        }

        void KilledUnit(Unit*)
        {
            Talk(SAY_SLAY);
        }

        void SummonedCreatureDies(Creature* summoned, Unit* /*who*/)
        {
            switch(summoned->GetEntry())
            {
            case NPC_ORPHANED_WHELP:
                ++whelpCnt;
                if(whelpCnt != MAX_WHELPS)
                    return;
            case NPC_NETHER_SCION:
            case NPC_STORM_RIDER:
            case NPC_SLATE_DRAGON:
            case NPC_TIME_WARDEN:
                summoned->CastSpell(summoned, SPELL_DRAGONS_VENGEANCE, true);
                break;
            default:
                break;
            }

            Talk(SAY_BIND_WILL, summoned->GetGUID());
        }

        void DamageTaken(Unit * /*done_by*/, uint32 &damage)
        {
            if (!roarCnt && me->HealthBelowPctDamaged(50, damage))
            {
                ++roarCnt;
                events.DelayEvents(18000);
                events.ScheduleEvent(EVENT_FURIOUS_ROAR, 500);
            }
        }

        void SetGUID(uint64 guid, int32)
        {
            int i=0;
            for (; i<MAX_ACTIVE_DRAKES; ++i)
                if (guid == drakeGUIDs[i])
                    break;

            if (i >= MAX_ACTIVE_DRAKES)
                return;

            if(!me->isInCombat())
                me->SetInCombatWithZone();

            if (IS_CREATURE_GUID(guid))
            {
                Creature * creature = me->GetCreature(*me, guid);
                if (!creature)
                    return;

                switch(drakes[i])
                {
                case NPC_TIME_WARDEN:
                    creature->CastSpell(creature, SPELL_TIME_DILATION, true);
                    break;
                case NPC_NETHER_SCION:
                    creature->CastSpell(creature, SPELL_NETHER_BLINDNESS, true);
                    break;
                case NPC_STORM_RIDER:
                    creature->CastSpell(creature, SPELL_CYCLONE_WINDS, true);
                    break;
                case NPC_SLATE_DRAGON:
                    creature->CastSpell(creature, SPELL_STONE_TOUCH, true);
                    break;
                }

                DoCast(creature, SPELL_BIND_WILL, true);
                creature->SetInCombatWithZone();

            }else
            {
                if (GameObject * go = me->GetMap()->GetGameObject(guid))
                {
                    std::list<Creature*> cList;
                    go->GetCreatureListWithEntryInGrid(cList, NPC_ORPHANED_WHELP, 20.0f);
                    if (cList.empty())
                        return;
                    for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    {
                        (*itr)->CastSpell(*itr, SPELL_ATROPHIC_POISON, true);
                        DoCast(*itr, SPELL_BIND_WILL, true);
                        (*itr)->SetInCombatWithZone();
                    }
                }
            }
        }

        bool sOnDummyEffect(Unit* /*caster*/, uint32 spellId, SpellEffIndex /*effIndex*/)
        {
            if (spellId == SPELL_STONE_TOUCH)
                DoCast(me, SPELL_PARALYSIS, true);
            return true;
        }

        void UpdateAI(uint32 diff)
        {
            if (initTimer)
            {
                if (initTimer <= diff)
                {
                    initTimer = 0;
                    InitDrakes();
                }else initTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_SHADOW_NOVA:
                    DoCast(SPELL_SHADOW_NOVA);
                    events.ScheduleEvent(EVENT_SHADOW_NOVA, urand(25000, 30000));
                    break;
                case EVENT_ENRAGE:
                    DoCast(SPELL_BERSERK);
                    break;
                case EVENT_FURIOUS_ROAR:
                    DoCast(me, SPELL_FURIOUS_ROAR);
                    if (roarCnt < 3)
                    {
                        ++roarCnt;
                        Talk(SAY_ROAR);
                        events.ScheduleEvent(EVENT_FURIOUS_ROAR, 3000);
                    }
                    else
                    {
                        roarCnt = 1;
                        events.ScheduleEvent(EVENT_FURIOUS_ROAR, urand(20000, 25000));
                    }
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        uint32 initTimer;
        uint8 whelpCnt;
        uint8 roarCnt;
        std::vector<uint64> drakeGUIDs;
        uint32 drakes[MAX_DRAKES];
        SummonList summons;
    };

public:
    boss_halfus_wyrmbreaker() : CreatureScript("boss_halfus_wyrmbreaker") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_halfus_wyrmbreakerAI(creature);
    }
};

class npc_proto_behemoth : public CreatureScript
{
    enum
    {
        SPELL_FIREBALL                  = 86058,
        SPELL_FIREBALL_BUFF             = 83862,
        SPELL_FIREBALL_BARRAGE          = 83706,
        SPELL_SCORCHING_BLAST           = 77679,
        SPELL_DANCING_FLAMES            = 84106, // Fireball Barrage buff
        SPELL_SUPERHEATED_BREATH        = 83956, // Scorching Blast buff
        EVENT_FIREBALL_BARRAGE          = 1,
        EVENT_SCORCHING_BLAST,
        EVENT_FIREBALL
    };

    struct npc_proto_behemothAI : ScriptedAI
    {
        npc_proto_behemothAI(Creature * creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
            enableBlast = false;
            enableBarrage = false;
        }

        void Reset()
        {
            events.Reset();
            if (enableBlast)
                DoCast(me, SPELL_DANCING_FLAMES, true);
            if (enableBarrage)
                DoCast(me, SPELL_SUPERHEATED_BREATH, true);
        }

        void DoAction(int32 action)
        {
            if (action == ACTION_ENABLE_BLAST)
            {
                enableBlast = true;
                DoCast(me, SPELL_SUPERHEATED_BREATH, true);
            }
            else if (action == ACTION_ENABLE_BARRAGE)
            {
                enableBarrage = true;
                DoCast(me, SPELL_DANCING_FLAMES, true);
            }
            else if (action == ACTION_ENTER_COMBAT)
                me->SetInCombatWithZone();
        }

        void EnterCombat(Unit * /*who*/)
        {
            events.ScheduleEvent(EVENT_FIREBALL, urand(5000, 8000));
            if (enableBarrage)
                events.ScheduleEvent(EVENT_FIREBALL_BARRAGE, urand(12000, 15000));
            if (enableBlast)
                events.ScheduleEvent(EVENT_SCORCHING_BLAST, urand(10000, 12000));
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_FIREBALL:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), me->HasAura(SPELL_TIME_DILATION) ? SPELL_FIREBALL_BUFF : SPELL_FIREBALL, false); 
                    events.ScheduleEvent(EVENT_FIREBALL, urand(5000,10000));
                    break;
                case EVENT_FIREBALL_BARRAGE:
                    DoCast(SPELL_FIREBALL_BARRAGE);
                    events.ScheduleEvent(EVENT_FIREBALL_BARRAGE, urand(20000, 25000));
                    break;
                case EVENT_SCORCHING_BLAST:
                    DoCastVictim(SPELL_SCORCHING_BLAST, true);
                    events.ScheduleEvent(EVENT_SCORCHING_BLAST, urand(20000, 25000));
                    break;
                }
            }
        }
    private:
        EventMap events;
        bool enableBlast;
        bool enableBarrage;
    };

public:
    npc_proto_behemoth() : CreatureScript("npc_proto_behemoth") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_proto_behemothAI(creature);
    }
};

class spell_halfus_fireball : public SpellScriptLoader
{
    enum
    {
        SPELL_FIREBALL_BARRAGE          = 83720,
        SPELL_FIREBALL_BARRAGE_BUFF     = 83733,
    };

    class spell_halfus_fireball_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_halfus_fireball_SpellScript)

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit * target = GetHitUnit();
            Unit * caster = GetCaster();
            if (!target)
                return;

            caster->CastSpell(target, caster->HasAura(SPELL_TIME_DILATION) ? SPELL_FIREBALL_BARRAGE_BUFF : SPELL_FIREBALL_BARRAGE, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_halfus_fireball_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };
public:
    spell_halfus_fireball() : SpellScriptLoader("spell_halfus_fireball") {}

    SpellScript* GetSpellScript() const
    {
        return new spell_halfus_fireball_SpellScript();
    }
};

class npc_halfus_dragon : public CreatureScript
{
    bool OnGossipHello(Player* /*player*/, Creature* creature)
    {
        if (TempSummon * temp = creature->ToTempSummon())
            if (Unit * owner = temp->GetSummoner())
                owner->ToCreature()->AI()->SetGUID(creature->GetGUID());

        return true;
    }

public:
    npc_halfus_dragon() : CreatureScript("npc_halfus_dragon") { }
};

class go_halfus_whelp_cage : public GameObjectScript
{
    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        if (Creature * summoner = go->GetMap()->GetCreature(go->GetUserData()))
            summoner->AI()->SetGUID(go->GetGUID());
        return true;
    }

public:
    go_halfus_whelp_cage() : GameObjectScript("go_halfus_whelp_cage") { }
};

void AddSC_boss_halfus_wyrmbreaker()
{
    new boss_halfus_wyrmbreaker();
    new npc_proto_behemoth();
    new spell_halfus_fireball();
    new npc_halfus_dragon();
    new go_halfus_whelp_cage();
}