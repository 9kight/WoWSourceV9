#include "blackwing_descent.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum Entities
{
    NPC_INTRO_NEFARIUS_THRONE             = 43401,
    NPC_INTRO_DWARVEN_BRAZIER             = 43402,
    NPC_INTRO_MEMORY_FOG                  = 43400,
    NPC_INTRO_MALORIAK                    = 43404,
    NPC_INTRO_ATRAMEDES                   = 43407,
    NPC_LARGE_SPOTLIGHT                   = 15897
    //NPC_INTRO_NEFARIAN                    = 43396
};

enum Spells
{
    SPELL_BLIND_WHELP               = 81214,
    SPELL_POTION_IN_HAND            = 81217,
    SPELL_APPLY_MIXTURE             = 81221,
    SPELL_COWER                     = 49775,
    SPELL_SPOTLIGHT                 = 46975
};

struct spawn
{
    uint32 entry;
    Position pos;
};

static const spawn introSpawn[7] =
{
    {NPC_INTRO_NEFARIUS_THRONE, {146.355988f, -245.029099f, 74.929497f, 2.260429f}},
    //{NPC_INTRO_NEFARIAN, {143.501663f, -241.307678f, 74.920464f, 2.260429f}},
    {NPC_INTRO_DWARVEN_BRAZIER, {137.310654f, -255.867554f, 74.922279f, 0.0f}},
    {NPC_INTRO_DWARVEN_BRAZIER, {159.494232f, -238.714050f, 74.963463f, 0.0f}},
    {NPC_INTRO_MALORIAK, {142.082611f, -208.269547f, 74.907280f, 4.443843f}},
    {NPC_INTRO_ATRAMEDES, {133.746094f, -195.026901f, 74.907272f, 4.589140f}},
    {NPC_INTRO_MEMORY_FOG, {157.851318f, -225.106094f, 75.453415f, 6.203718f}},
    //{NPC_INTRO_MEMORY_FOG, {178.018478f, -226.712082f, 75.453415f, 6.203718}},
};

static const Position centerPos = {139.053238f, -225.190063f, 75.453407f, 0.0f};

enum Events
{
    EVENT_N_TALK_1          = 1,
    EVENT_M_TALK_1,
    EVENT_N_TALK_2,
    EVENT_M_TALK_2,
    EVENT_M_TALK_3,
    EVENT_M_TALK_4,
    EVENT_M_TALK_5,
    EVENT_A_MOVE,
    EVENT_M_TALK_6,
    EVENT_M_THROW,
    EVENT_N_TALK_3,
    EVENT_A_AURA,
    EVENT_N_TALK_4,
    EVENT_M_TALK_7,
    EVENT_N_TALK_5,
    EVENT_N_TALK_6,
    EVENT_N_TALK_7,
    EVENT_M_TALK_8,
    EVENT_DESPAWN,
    EVENT_SPOTLIGHT
};

class npc_nefarian_atramedes_intro : public CreatureScript
{
    struct npc_nefarian_atramedes_introAI : public ScriptedAI
    {
        npc_nefarian_atramedes_introAI(Creature * creature) : ScriptedAI(creature), summons(me) {}

        void Reset()
        {
            timerNext = 0;
            atramedesGUID = 0;
            maloriakAI = NULL;
            events.Reset();

            for(int i=0; i<6; ++i)
                me->SummonCreature(introSpawn[i].entry, introSpawn[i].pos);

            events.ScheduleEvent(EVENT_N_TALK_1, 5000);
        }

        void JustSummoned(Creature * summon)
        {
            if(summon->GetEntry() == NPC_INTRO_MALORIAK)
                maloriakAI = summon->AI();
            else if (summon->GetEntry() == NPC_INTRO_ATRAMEDES)
                atramedesGUID = summon->GetGUID();
            summons.Summon(summon);
        }

        void UpdateAI(uint32 const diff)
        {
            events.Update(diff);

            if(uint32 eventId = events.ExecuteEvent())
            {
                if(!maloriakAI)
                    return;

                switch(eventId)
                {
                case EVENT_N_TALK_1:
                    Talk(0);
                    timerNext = 11000;
                    break;
                case EVENT_M_TALK_1:
                    maloriakAI->Talk(0);
                    timerNext = 10000;
                    break;
                case EVENT_N_TALK_2:
                    Talk(1);
                    timerNext = 4500;
                    break;
                case EVENT_M_TALK_2:
                    maloriakAI->Talk(1);
                    timerNext = 2000;
                    break;
                case EVENT_M_TALK_3:
                    maloriakAI->Talk(2);
                    timerNext = 10000;
                    break;
                case EVENT_M_TALK_4:
                    maloriakAI->Talk(3);
                    timerNext = 4500;
                    break;
                case EVENT_M_TALK_5:
                    maloriakAI->Talk(4);
                    timerNext = 2000;
                    break;
                case EVENT_A_MOVE:
                    if(Creature * atramedes = me->GetCreature(*me, atramedesGUID))
                        atramedes->GetMotionMaster()->MovePoint(0, centerPos);
                    timerNext = 4000;
                    break;
                case EVENT_M_TALK_6:
                    maloriakAI->DoCast(SPELL_POTION_IN_HAND);
                    maloriakAI->Talk(5);
                    timerNext = 8000;
                    break;
                case EVENT_M_THROW:
                    maloriakAI->DoCast(SPELL_APPLY_MIXTURE);
                    timerNext = 12000;
                    break;
                case EVENT_N_TALK_3:
                    Talk(2);
                    timerNext = 3000;
                    break;
                case EVENT_A_AURA:
                    if(Creature * atramedes = me->GetCreature(*me, atramedesGUID))
                        atramedes->CastSpell(atramedes, SPELL_BLIND_WHELP, true);
                    timerNext = 6000;
                    break;
                case EVENT_N_TALK_4:
                    maloriakAI->DoCast(SPELL_COWER);
                    Talk(3);
                    timerNext = 4000;
                    break;
                case EVENT_M_TALK_7:
                    maloriakAI->Talk(6);
                    timerNext = 5000;
                    break;
                case EVENT_N_TALK_5:
                    Talk(4);
                    timerNext = 3000;
                    break;
                case EVENT_N_TALK_6:
                    Talk(5);
                    timerNext = 7000;
                    break;
                case EVENT_N_TALK_7:
                    Talk(6);
                    timerNext = 7000;
                    break;
                case EVENT_M_TALK_8:
                    maloriakAI->Talk(7);
                    timerNext = 8000;
                    break;
                case EVENT_DESPAWN:
                    summons.DespawnAll();
                    me->SetVisible(false);
                    me->DespawnOrUnsummon(15000);
                    timerNext = 3000;
                    break;
                case EVENT_SPOTLIGHT:
                    if(InstanceScript * instance = me->GetInstanceScript())
                        instance->SetData(DATA_ATRAMEDES_INTRO, 1);
                    if(Creature * spotlight = me->SummonCreature(NPC_LARGE_SPOTLIGHT, 226.463699f, -224.728439f, 74.841087f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 10000))
                    {
                        //spotlight->SetFloatValue(OBJECT_FIELD_SCALE_X, 4.0f);
                        spotlight->CastSpell(spotlight, SPELL_SPOTLIGHT, true);
                    }
                    return;
                default:
                    return;
                };

                if(timerNext)
                    events.ScheduleEvent(++eventId, timerNext);
            }
        }

    private:
        SummonList summons;
        EventMap events;
        CreatureAI * maloriakAI;
        uint64 atramedesGUID;
        uint32 timerNext;
    };
public:
    npc_nefarian_atramedes_intro() : CreatureScript("npc_nefarian_atramedes_intro") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_nefarian_atramedes_introAI(creature);
    };
};

void AddSC_blackwing_descent()
{
    new npc_nefarian_atramedes_intro();
};
