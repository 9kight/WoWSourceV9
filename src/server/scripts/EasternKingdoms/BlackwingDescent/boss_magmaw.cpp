#include "ScriptMgr.h"
#include "blackwing_descent.h"
#include "Map.h"
#include "Vehicle.h"
#include "MoveSplineInit.h"

enum Spells
{
    // magmaw
    SPELL_LAVA_SPEW                 = 77839,
    SPELL_MAGMA_SPIT                = 78068,
    SPELL_MOLTEN_TANTRUM            = 78403,
    SPELL_PILLAR_OF_FLAME           = 78006,
    SPELL_PILLAR_OF_FLAME_SUMMON    = 77998,
    SPELL_BERSERK                   = 26662,
    SPELL_MANGLE                    = 89773,
    SPELL_MANGLE_PERIODIC           = 78412,
    SPELL_SWELTERING_ARMOR          = 78199,
    SPELL_IMPALE_SELF               = 77907,
    SPELL_MASSIVE_CRASH             = 88253,
    SPELL_QUEST_INVIS_5             = 95478,
    SPELL_POINT_OF_VULNERABILITY    = 79010,
    SPELL_POINT_OF_VULNERABILITY2   = 79011,
    SPELL_BLAZING_INFERNO           = 92153,
    SPELL_SHADOWFLAME_BARRAGE       = 78621,

    // spine stalker
    SPELL_LOCATION_MARKER           = 88458,
    SPELL_CHAIN_R                   = 77929,
    SPELL_CHAIN_L                   = 77940,

    // Room stalker
    SPELL_LIGHT_SHOW                = 87949,

    // blazing bone construct
    SPELL_FIERY_SLASH               = 92144,
    SPELL_ARMAGEDDON                = 92177,
    SPELL_IGNITION_AURA             = 92131, 
    SPELL_IGNITION_SUMMON           = 92129,
    SPELL_IGNITION_TRIGGER_SPAWN    = 92121,

    // lava parasite
    SPELL_PARASITIC_INFECTION       = 78097,
    SPELL_LAVA_PARASITE_AURA        = 78019
};

enum Events
{
    EVENT_LAVA_SPEW                 = 1,
    EVENT_MAGMA_SPIT,
    EVENT_PILLAR_OF_FLAME,
    EVENT_MANGLE,
    EVENT_IGNITION,
    EVENT_MASSIVE_CRASH,
    EVENT_MASSIVE_CRASH_END,
    EVENT_IMPALE_END,
    EVENT_EJECT,
    EVENT_BLAZING_INFERNO,
    EVENT_BERSERK,
    EVENT_SHADOWFLAME_BARRAGE
};

enum Phases
{
    PHASE_ALL                       = 0,
    PHASE_NORMAL,
    PHASE_HEAD
};

enum Quotes
{
    EMOTE_CRASH,
    EMOTE_IMPALE,
    EMOTE_PILLAR
};

enum Misc
{
    DATA_CHAINS                     = 1,
    DATA_BELOW_30                   = 2,
    NPC_HEROIC_NEFARIAN             = 49427,
    SEAT_MANGLE                     = 2,
    SEAT_HEAD                       = 4,
    PLAYER_VEHICLE                  = 1548, // temp id
};

Position const IgnitionPositions[2][21] =
{
    { // Left Side
        {-355.258f, -66.156f, 215.363f, 3.32963f},
        {-349.104f, -57.5792f, 214.837f, 3.35319f},
        {-355.983f, -79.9935f, 213.749f, 3.91082f},
        {-348.35f, -71.9141f, 213.26f, 3.96973f},
        {-341.228f, -63.2021f, 212.833f, 3.96973f},
        {-335.636f, -53.1296f, 212.332f, 5.80755f},
        {-344.959f, -47.9226f, 212.061f, 6.07851f},
        {-354.565f, -47.2949f, 213.04f, 3.04373f},
        {-350.721f, -88.5883f, 213.92f, 3.97443f},
        {-342.783f, -80.5202f, 213.868f, 3.93124f},
        {-335.879f, -72.941f, 212.87f, 4.06083f},
        {-330.037f, -64.3112f, 212.393f, 4.14329f},
        {-324.021f, -54.4161f, 211.863f, 4.19434f},
        {-317.603f, -44.6127f, 211.952f, 0.96793f},
        {-329.399f, -43.7365f, 211.748f, 6.02982f},
        {-341.139f, -38.8838f, 211.426f, 6.12014f},
        {-350.813f, -26.2997f, 211.345f, 2.15388f},
        {-352.253f, -37.0172f, 211.603f, 2.95734f},
        {-338.237f, -27.1878f, 211.154f, 3.06337f},
        {-327.528f, -32.3648f, 211.394f, 3.06337f},
        {-316.344f, -33.1654f, 211.428f, 3.17725f},
    },
    { // Right Side
        {-313.627f, -72.6881f, 213.266f, 1.00637f},
        {-319.881f, -82.0775f, 213.552f, 4.27756f},
        {-306.833f, -83.4444f, 213.633f, 4.36788f},
        {-302.725f, -74.0836f, 213.345f, 4.69382f},
        {-304.055f, -63.3109f, 212.826f, 4.57601f},
        {-300.848f, -54.0836f, 212.39f, 4.18332f},
        {-308.972f, -52.744f, 212.326f, 5.62846f},
        {-315.607f, -58.0178f, 212.578f, 1.02995f},
        {-320.357f, -65.927f, 212.802f, 1.0378f},
        {-326.56f, -74.2884f, 213.145f, 0.841454f},
        {-333.371f, -83.2f, 213.706f, 0.566564f},
        {-343.042f, -91.8511f, 213.916f, 3.12304f},
        {-334.444f, -92.7097f, 213.903f, 3.06413f},
        {-324.424f, -93.0766f, 213.909f, 2.98166f},
        {-315.574f, -93.3725f, 213.924f, 3.12696f},
        {-304.845f, -93.5295f, 213.919f, 3.10733f},
        {-296.142f, -88.6009f, 214.03f, 4.72919f},
        {-292.752f, -78.8147f, 213.567f, 4.71348f},
        {-295.368f, -68.4218f, 213.065f, 4.71741f},
        {-293.046f, -56.9843f, 212.531f, 4.62709f},
        {-295.83f, -46.4565f, 212.04f, 1.27344f},
        }
};

static const Position ejectPos = {-317.484100f, -55.254810f, 212.445892f, 0.0f};
static const Position nefarianPos = {-419.323914f, 13.946201f, 231.422546f, 0.0f};
static const Position movePos = {-286.590424f, 0.089617f, 245.260162f, 4.6f};

class boss_magmaw : public CreatureScript
{
public:
    boss_magmaw() : CreatureScript("boss_magmaw") {}

    struct boss_magmawAI : public BossAI
    {
        boss_magmawAI(Creature* creature) : BossAI(creature, DATA_MAGMAW),  vehicle(creature->GetVehicleKit())
        {
            ASSERT(vehicle);
            me->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
            me->SetFloatValue(UNIT_FIELD_HOVERHEIGHT, 213.0f);
        }

        void Reset()
        {
            below30 = false;
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            SetPincers(false);
            if(Unit* head = vehicle->GetPassenger(SEAT_HEAD))
            {
                head->ToCreature()->AI()->EnterEvadeMode();
                me->CastSpell(head, SPELL_POINT_OF_VULNERABILITY, true);
            }
            if(IsHeroic())
                if(Creature* nefarian = me->GetCreature(*me, nefarianGUID))
                    nefarian->DespawnOrUnsummon();
            _Reset();
        }

        void PassengerBoarded(Unit* who, int8 seatId, bool apply)
        {
            if(seatId == 2 && apply)
            {
                who->ClearUnitState(UNIT_STATE_ONVEHICLE);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            setPlayerVehicle(false);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            _JustDied();
        }

        void SetIdle()
        {
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveIdle();
            me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
        }

        void DoAction(int32 const action)
        {
            if(action == DATA_CHAINS)
            {
                SetIdle();
                SetPincers(false);
                Talk(EMOTE_IMPALE);
                events.SetPhase(PHASE_HEAD);
                Movement::MoveSplineInit init(me);
                init.SetFacing(me->GetHomePosition().GetOrientation());
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                if(Unit* passenger = vehicle->GetPassenger(SEAT_MANGLE)) // Eject the tank
                {
                    passenger->ExitVehicle(&ejectPos);
                    passenger->RemoveAurasDueToSpell(SPELL_MANGLE);
                    passenger->RemoveAurasDueToSpell(SPELL_MANGLE_PERIODIC);
                }

                if(Unit* head = vehicle->GetPassenger(SEAT_HEAD)) // Make the head Visible
                {
                    head->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    head->RemoveAurasDueToSpell(SPELL_QUEST_INVIS_5);
                    if(!head->isInCombat())
                        if(Unit* victim = me->getVictim())
                            head->SetInCombatWith(victim);
                    me->CastSpell(head, SPELL_POINT_OF_VULNERABILITY, true);
                    head->SetHealth(me->GetHealth());
                }

                if(Unit* stalker = me->FindNearestCreature(NPC_SPIKE_STALKER, 100.0f)) // Cast Arrow Visual
                    me->CastSpell(stalker, SPELL_LOCATION_MARKER, true);

                DoCast(SPELL_IMPALE_SELF);
                events.CancelEvent(EVENT_EJECT);
                events.DelayEvents(36000);
                events.ScheduleEvent(EVENT_IMPALE_END, 36000);
            }
        }

        void JustSummoned(Creature* summon)
        {
            switch(summon->GetEntry())
            {
            case NPC_HEROIC_NEFARIAN:
                nefarianGUID = summon->GetGUID();
                return;
            case NPC_MAGMAWS_HEAD2:
                me->CastSpell(summon, SPELL_POINT_OF_VULNERABILITY, true);
                summon->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 50.0f);
                summon->SetFloatValue(UNIT_FIELD_COMBATREACH, 50.0f);
                break;
            case NPC_ROOM_STALKER:
                summon->CastSpell(summon, SPELL_LIGHT_SHOW);
                break;
            case NPC_MAGMAWS_HEAD:
            case NPC_MAGMAWS_PINCER:
            case NPC_MAGMAWS_PINCER2:
                break;
            default:
                BossAI::JustSummoned(summon);
                break;
            }
        }

        void EnterCombat(Unit* who)
        {
            events.SetPhase(PHASE_NORMAL);
            events.ScheduleEvent(EVENT_LAVA_SPEW, urand(5000, 8000), 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_MAGMA_SPIT, urand(8000, 10000), 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_PILLAR_OF_FLAME, urand(12000, 15000), 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_MANGLE, urand(25000, 30000), 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_BERSERK, 600000, 0, PHASE_ALL);
            setPlayerVehicle(true);
            if(IsHeroic())
            {
                if(Creature* nefarian = me->SummonCreature(NPC_HEROIC_NEFARIAN, nefarianPos))
                {
                    nefarian->SetCanFly(true);
                    nefarian->SetReactState(REACT_PASSIVE);
                    nefarian->SetHomePosition(movePos);
                    nefarian->AI()->EnterEvadeMode();
                }
                events.ScheduleEvent(EVENT_BLAZING_INFERNO, 15000);
            }

            BossAI::EnterCombat(who);
        }

        void MoveInLineOfSight(Unit* /*who*/) {}

        void AttackStart(Unit* target)
        {
            if (me->Attack(target, true))
                DoStartNoMovement(target);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if(!below30 && me->HealthBelowPctDamaged(30, damage))
            {
                below30 = true;
                events.CancelEvent(EVENT_BLAZING_INFERNO);
                events.ScheduleEvent(EVENT_SHADOWFLAME_BARRAGE, 2000);
            }
        }

        void SetPincers(bool on)
        {
            for(int8 i=0; i<=1; ++i)
            {
                Unit* pincer = vehicle->GetPassenger(i);
                if(pincer && on)
                {
                    pincer->SetDisplayId(34532);
                    pincer->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 50.0f);
                    pincer->SetFloatValue(UNIT_FIELD_COMBATREACH, 50.0f);
                    pincer->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                }
                else if(pincer)
                {
                    if(Unit* passenger = pincer->GetVehicleKit()->GetPassenger(0))
                        passenger->ExitVehicle(&ejectPos);
                    pincer->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                }
            }
        }

        void DoMeleeAttackIfReady()
        {
            if (me->isAttackReady() && !me->IsNonMeleeSpellCasted(false))
            {
                if (me->IsWithinMeleeRange(me->getVictim()))
                {
                    me->AttackerStateUpdate(me->getVictim());
                    me->resetAttackTimer();
                } else DoCast(me, SPELL_MOLTEN_TANTRUM, true);
            }
        }

        void setPlayerVehicle(bool remove)
        {
            Map::PlayerList const& players = me->GetMap()->GetPlayers();

            if (!players.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* player = itr->getSource())
                    {
                        if (player->CreateVehicleKit(843, 0))
                        {
                            WorldPacket data(SMSG_PLAYER_VEHICLE_DATA, player->GetPackGUID().size()+4);
                            data.appendPackGUID(player->GetGUID());
                            data << uint32(remove ? 0 : 843);
                            player->SendMessageToSet(&data, true);
                        }
                        
                    }
                }
            }
        }

        void UpdateAI(uint32 const diff)
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_LAVA_SPEW:
                        DoCast(me, SPELL_LAVA_SPEW);
                        events.ScheduleEvent(EVENT_LAVA_SPEW, urand(15000, 20000), 0, PHASE_NORMAL);
                        break;
                    case EVENT_MAGMA_SPIT:
                        if(Unit* victim = me->getVictim())
                        {
                            float dist = me->GetDistance(victim);
                            if(dist >= 60.0f)
                                EnterEvadeMode();
                            else if(dist >= INTERACTION_DISTANCE)
                                DoCast(victim, SPELL_MAGMA_SPIT, true);
                        }
                        events.ScheduleEvent(EVENT_MAGMA_SPIT, urand(3000, 5000), 0, PHASE_NORMAL);
                        break;
                    case EVENT_PILLAR_OF_FLAME:
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -15.0f, true);
                            if(!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                            if(target)
                                me->SummonCreature(NPC_PILLAR_OF_FLAME, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                            Talk(EMOTE_PILLAR);
                            DoCast(me, SPELL_PILLAR_OF_FLAME);
                            events.ScheduleEvent(EVENT_PILLAR_OF_FLAME, 30000, 0, PHASE_NORMAL);
                        }
                        break;
                    case EVENT_MANGLE:
                        DoCastVictim(SPELL_SWELTERING_ARMOR);
                        DoCastVictim(SPELL_MANGLE, true);
                        SetIdle();
                        events.ScheduleEvent(EVENT_MANGLE, 95000);
                        events.ScheduleEvent(EVENT_IGNITION, 2000);
                        events.SetPhase(PHASE_HEAD);
                        break;
                    case EVENT_IGNITION:
                    {
                        SummonLightShow();
                        events.DelayEvents(10000);
                        events.ScheduleEvent(EVENT_MASSIVE_CRASH, 3000);
                        events.ScheduleEvent(EVENT_EJECT, 40000);
                        break;
                    }
                    case EVENT_MASSIVE_CRASH:
                        Talk(EMOTE_CRASH);
                        DoCast(SPELL_MASSIVE_CRASH);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        SetPincers(true);
                        events.ScheduleEvent(EVENT_MASSIVE_CRASH_END, 10000);
                        break;
                    case EVENT_IMPALE_END:
                        if(Unit* head = vehicle->GetPassenger(SEAT_HEAD)) // make the head unattackable
                        {
                            head->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            head->CastSpell(head, SPELL_QUEST_INVIS_5, true);
                        }
                        me->RemoveAurasDueToSpell(SPELL_CHAIN_R);
                        me->RemoveAurasDueToSpell(SPELL_CHAIN_L);
                        events.RescheduleEvent(EVENT_MAGMA_SPIT, 5000);
                        events.RescheduleEvent(EVENT_LAVA_SPEW, 8000);
                        events.RescheduleEvent(EVENT_MAGMA_SPIT, urand(8000, 10000));
                        events.RescheduleEvent(EVENT_PILLAR_OF_FLAME, urand(8000, 12000));
                        events.RescheduleEvent(EVENT_MANGLE, urand(25000, 30000));
                    case EVENT_MASSIVE_CRASH_END:
                        me->SetStunned(false);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.SetPhase(PHASE_NORMAL);
                        if(Unit* victim = me->getVictim()) // resume combat
                        {
                            DoStartNoMovement(victim);
                            me->SetUInt64Value(UNIT_FIELD_TARGET, victim->GetGUID());
                        }
                        break;
                    case EVENT_EJECT:
                        // Tank in seat 3 will be dead by then
                        SetPincers(false);
                        break;
                    case EVENT_BLAZING_INFERNO:
                        if(Creature* nefarian = me->GetCreature(*me, nefarianGUID))
                            if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -5.0f, true))
                                nefarian->CastSpell(target, SPELL_BLAZING_INFERNO, true);
                        events.ScheduleEvent(EVENT_BLAZING_INFERNO, urand(20000, 25000));
                        break;
                    case EVENT_BERSERK:
                        DoCast(SPELL_BERSERK);
                        break;
                    case EVENT_SHADOWFLAME_BARRAGE:
                        if(Creature* nefarian = me->GetCreature(*me, nefarianGUID))
                        {
                            if(nefarian->HasUnitState(UNIT_STATE_CASTING))
                                events.ScheduleEvent(EVENT_SHADOWFLAME_BARRAGE, 200);
                            else
                            {
                                nefarian->CastSpell(nefarian, SPELL_SHADOWFLAME_BARRAGE, false);
                                events.ScheduleEvent(EVENT_SHADOWFLAME_BARRAGE, 2100);
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            inline void SummonLightShow()
            {
                uint8 side = urand(0,1);
                me->SetOrientation(side ? 4.7f : 3.47f);
                me->SetStunned(true);
                for(uint8 i=0; i<21 ; i++)
                    me->SummonCreature(NPC_ROOM_STALKER, IgnitionPositions[side][i].GetPositionX(),IgnitionPositions[side][i].GetPositionY(),IgnitionPositions[side][i].GetPositionZ(), IgnitionPositions[side][i].GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 3500);
            }
            bool below30;
            uint64 nefarianGUID;
            Vehicle* vehicle;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_magmawAI(creature);
    }
};

class npc_spike_stalker : public CreatureScript
{
public:
    npc_spike_stalker() : CreatureScript("npc_spike_stalker") {}

    enum
    {
        SPELL_LAUNCH_HOOK_R         = 77917,
        SPELL_LAUNCH_HOOK_L         = 77941,
    };

    struct npc_spike_stalkerAI : public ScriptedAI
    {
        npc_spike_stalkerAI(Creature * creature) : ScriptedAI(creature) 
        {
            instance = me->GetInstanceScript();
        }

        void SpellHit(Unit * /*caster*/, const SpellInfo * spell)
        {
            if((spell->Id == SPELL_LAUNCH_HOOK_R && me->HasAura(SPELL_LAUNCH_HOOK_L)) ||
                (spell->Id == SPELL_LAUNCH_HOOK_L && me->HasAura(SPELL_LAUNCH_HOOK_R)))
            {
                if(Creature* magmaw = Creature::GetCreature(*me, instance->GetData64(DATA_MAGMAW_GUID)))
                {
                    magmaw->AI()->DoAction(DATA_CHAINS);
                    DoCast(me, SPELL_CHAIN_R, true);
                    DoCast(me, SPELL_CHAIN_L, true);
                }
            }
        }

        void UpdateAI(uint32 const /*diff*/)
        {
        }
    private:
        InstanceScript* instance;
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_spike_stalkerAI(creature);
    }
};

class npc_pillar_of_flame : public CreatureScript
{
public:
    npc_pillar_of_flame() : CreatureScript("npc_pillar_of_flame") {}
    enum
    {
        SPELL_PILLAR_OF_FLAME_PRE       = 78017,
        SPELL_PILLAR_OF_FLAME_PERIODIC  = 77970,
        NPC_LAVA_PARASITE               = 41806,
    };

    struct npc_pillar_of_flameAI : public ScriptedAI
    {
        npc_pillar_of_flameAI(Creature * creature) : ScriptedAI(creature) {}

        void Reset()
        {
            DoCast(SPELL_PILLAR_OF_FLAME_PRE);
            done = false;
            actionTimer = 3000;
        }

        void UpdateAI(uint32 const diff)
        {
            if(!done)
            {
                if(actionTimer <= diff)
                {
                    done = true;
                    DoCast(SPELL_PILLAR_OF_FLAME_PERIODIC);
                }else actionTimer -= diff;
            }
        }

    private:
        bool done;
        uint32 actionTimer;
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_pillar_of_flameAI(creature);
    }
};

class npc_lava_parasite : public CreatureScript
{
public:
    npc_lava_parasite() : CreatureScript("npc_lava_parasite") {}

    struct npc_lava_parasiteAI : public ScriptedAI
    {
        npc_lava_parasiteAI(Creature * creature) : ScriptedAI(creature) 
        {
            instance = me->GetInstanceScript();
        }

        void IsSummonedBy(Unit * /*summoner*/)
        {
            me->AddAura(SPELL_LAVA_PARASITE_AURA, me);
            if(Unit * victim = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
            {
                me->SetInCombatWithZone();
                me->AddThreat(victim, 5000.0f);
                me->AI()->AttackStart(victim);
            }

            if(Creature* magmaw = Creature::GetCreature(*me, instance->GetData64(DATA_MAGMAW_GUID)))
                magmaw->AI()->JustSummoned(me);
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spellInfo)
        {
            if (spellInfo->Id == SPELL_PARASITIC_INFECTION)
                me->DespawnOrUnsummon();
        }

    private:
        InstanceScript* instance;
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_lava_parasiteAI(creature);
    }
};

class npc_drakonid_drudge : public CreatureScript
{
public:
    npc_drakonid_drudge() : CreatureScript("npc_drakonid_drudge") {}
    enum
    {
        EMOTE_CHANNEL               = 468,
        SPELL_CHAIN_VISUAL          = 79025,
        SPELL_WHIRLWIND             = 79973,
        SPELL_THUNDERCLAP           = 79604,
        SPELL_DRAKONID_RUSH         = 79630,
        SPELL_VENGEFUL_RAGE         = 80035,
    };

    struct npc_drakonid_drudgeAI : public ScriptedAI
    {
        npc_drakonid_drudgeAI(Creature * creature) : ScriptedAI(creature) 
        {
            instance = me->GetInstanceScript();
        }

        void Reset()
        {
            DoCast(SPELL_CHAIN_VISUAL);
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_CHANNEL);
            chargeTimer = 20000;
            thunderclapTimer = 10000;
            whirlwindTimer = 30000;
            whirlwind = false;
        }

        void JustDied(Unit * /*killer*/)
        {
            if(Unit * drudge = me->FindNearestCreature(me->GetEntry(), 100.0f))
                me->CastSpell(drudge, SPELL_VENGEFUL_RAGE, true);

            instance->SetData(DATA_DRAKONID, 0);
        }

        void EnterCombat(Unit * who)
        {
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
            if(Creature* magmaw = Creature::GetCreature(*me, instance->GetData64(DATA_MAGMAW_GUID)))
                magmaw->RemoveAurasDueToSpell(SPELL_CHAIN_VISUAL);
            DoStartMovement(who);
        }

        void UpdateAI(uint32 const diff)
        {
            if(!UpdateVictim())
                return;

            if(chargeTimer <= diff)
            {
                if(Unit * target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 80.0f, true))
                {
                    me->getThreatManager().resetAllAggro();
                    me->TauntApply(target);
                    me->AddThreat(target, 20000.0f);
                    DoCast(target, SPELL_DRAKONID_RUSH, true);
                    whirlwindTimer = 6000;
                    whirlwind = true;
                }
                chargeTimer = 20000;
            }else chargeTimer -= diff;

            if(whirlwind)
            {
                if(whirlwindTimer <= diff)
                {
                    DoCast(SPELL_WHIRLWIND);
                    whirlwind = false;
                }else whirlwindTimer -= diff;
            }

            if(thunderclapTimer <= diff)
            {
                DoCast(SPELL_THUNDERCLAP);
                thunderclapTimer = urand(10000, 12000);
            }else thunderclapTimer -= diff;

            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript* instance;
        uint32 chargeTimer;
        uint32 thunderclapTimer;
        bool whirlwind;
        uint32 whirlwindTimer;
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_drakonid_drudgeAI(creature);
    }
};

class npc_magmaws_pincer : public VehicleScript
{
public:
    npc_magmaws_pincer() : VehicleScript("npc_magmaws_pincer") { }

    void OnAddPassenger(Vehicle* veh, Unit* /*passenger*/, int8 /*seatId*/)
    {
        if (Unit* unit = veh->GetBase())
        {
            unit->SetDisplayId(11686);
            unit->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 0.5f);
            unit->SetFloatValue(UNIT_FIELD_COMBATREACH, 0.5f);
        }
    }
};

class npc_blazing_bone_construct : public CreatureScript
{
public:
    npc_blazing_bone_construct() : CreatureScript("npc_blazing_bone_construct") {}

    struct npc_blazing_bone_constructAI : public ScriptedAI
    {
        npc_blazing_bone_constructAI(Creature* creature) : ScriptedAI(creature) 
        {
            instance = me->GetInstanceScript();
        }

        void Reset()
        {
            armageddon = false;
            slashTimer = 5000;
            summonTimer = 5000;
        }

        void IsSummonedBy(Unit* /*summoner*/)
        {
            if(Creature* magmaw = Creature::GetCreature(*me, instance->GetData64(DATA_MAGMAW_GUID)))
                magmaw->AI()->JustSummoned(me);
            Position pos;
            for(int i=0; i<=7; ++i)
            {
                me->GetRandomNearPosition(pos, 5.0f);
                me->SummonCreature(NPC_IGNITION, pos, TEMPSUMMON_TIMED_DESPAWN, 45000);
            }
        }

        void JustSummoned(Creature* summon)
        {
            if(summon->GetEntry() == NPC_IGNITION)
            {
                summon->RemoveAllAuras();
                summon->CastSpell(summon, SPELL_IGNITION_AURA, true);
                summon->GetMotionMaster()->MoveRandom(20.0f);
            }

            if(Creature* magmaw = Creature::GetCreature(*me, instance->GetData64(DATA_MAGMAW_GUID)))
               magmaw->AI()->JustSummoned(summon);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if(!armageddon && me->HealthBelowPctDamaged(20, damage))
            {
                armageddon = true;
                DoCast(SPELL_ARMAGEDDON);
            }
        }

        void UpdateAI(uint32 const diff)
        {
            if(!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(summonTimer <= diff)
            {
                DoCast(me, SPELL_IGNITION_SUMMON, true);
                summonTimer = 1000;
            }else summonTimer -= diff;

            if(slashTimer <= diff)
            {
                DoCast(me, SPELL_FIERY_SLASH, true);
                slashTimer = urand(8000, 10000);
            }else slashTimer -= diff;

            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript* instance;
        uint32 slashTimer;
        uint32 summonTimer;
        bool armageddon;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_blazing_bone_constructAI(creature);
    }
};

class spell_parasitic_infection : public SpellScriptLoader
{
    public:
        spell_parasitic_infection() : SpellScriptLoader("spell_parasitic_infection") { }

        class spell_parasitic_infection_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_parasitic_infection_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit * caster = GetCaster();

                for (int i = 0; i < 2; ++i)
                {
                    if (Creature* parasite = caster->SummonCreature(NPC_LAVA_PARASITE, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 240000))
                        parasite->SetInCombatWithZone();
                }
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_parasitic_infection_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_parasitic_infection_AuraScript();
        }
};


void AddSC_boss_magmaw()
{
    new boss_magmaw();
    new npc_pillar_of_flame();
    new npc_lava_parasite();
    new npc_spike_stalker();
    new npc_drakonid_drudge();
    new npc_magmaws_pincer();
    new npc_blazing_bone_construct();
    new spell_parasitic_infection();
};
