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

#include "ScriptMgr.h"
#include "throne_of_the_tides.h"

enum Phase
{
    PHASE_NONE          = 0,
    PHASE_MINDLASHES    = 1,
    PHASE_SAPPERS       = 2,
    PHASE_OZUMAT        = 3,
    PHASE_OZUMAT_FIGHT  = 4,
};

const Position spawns[] =
{
    {-122.412041f, 947.492188f, 231.579025f, 2.279974f},
    {-118.400780f, 1014.799866f, 230.195724f, 4.366778f},
};

enum spawnCounters
{
    COUNTER_DEEP_MURLOC = 0,
    COUNTER_MINDLASHER,
    COUNTER_BEHEMOTH,
    COUNTER_SAPPER,
    COUNTER_BEAST,
    COUNTER_MAX = 5,
};

enum encounterSpells
{
    SPELL_ENTANGLING_GRASP  = 83463,
    SPELL_GRIP_STUN         = 74653,
    SPELL_BLIGHT_OF_OZUMAT  = 83672,
};

enum eNeptulonYells
{
    SAY_PHASE_1_1           = 0,
    SAY_PHASE_1_2           = 1,
    SAY_PHASE_2_1           = 2,
    SAY_PHASE_2_2           = 3,
    SAY_PHASE_3_1           = 4,
    SAY_PHASE_3_2           = 5,
    SAY_DEATH               = 6,
};

class npc_neptulon : public CreatureScript
{
public:
    npc_neptulon() : CreatureScript("npc_neptulon") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_neptulonAI (pCreature);
    }

    struct npc_neptulonAI : public ScriptedAI
    {
        npc_neptulonAI(Creature *c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        bool isEncounterStarted;
        InstanceScript* instance;
        uint8 phase;
        uint8 phaseCounter;
        std::list<uint64> summons;
        uint8 spawnCounter[5];
        // Spawn timers
        uint32 summonMurlocTimer;
        uint32 summonMindlasherTimer;
        uint32 summonBehemothTimer;
        uint32 summonBeastTimer;

        void Reset()
        {
            me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            summons.clear();
            isEncounterStarted      = false;
            phase                   = PHASE_NONE;
            phaseCounter            = 3;
            //Summon Timers
            summonMurlocTimer       = 8000;
            summonMindlasherTimer   = 20000;
            summonBehemothTimer     = 30000;
            summonBeastTimer        = 10000;

            for(uint8 i = 0; i < COUNTER_MAX; ++i)
                spawnCounter[i] = 0;
        }

        void SummonedCreatureDies(Creature* summon, Unit * /*killer*/)
        {
            uint32 entry = summon->GetEntry();
            switch(entry)
            {
                case NPC_DEEP_MURLOC: --spawnCounter[COUNTER_DEEP_MURLOC];  break;
                case NPC_BEAST:       --spawnCounter[COUNTER_BEAST];        break;
                case NPC_MINDLASHER:
                case NPC_SAPPER:
                {
                    if (--phaseCounter == 0)
                    {
                        ++phase;
                        if (phase == PHASE_SAPPERS)
                            Talk(RAND(SAY_PHASE_2_1, SAY_PHASE_2_2));
                        else if (phase == PHASE_OZUMAT)
                            Talk(RAND(SAY_PHASE_3_1, SAY_PHASE_3_2));

                        phaseCounter = 3;
                    }
                    break;
                }
            }
        }

        void DespawnSummons()
        {
            for (std::list<uint64>::iterator itr = summons.begin(); itr != summons.end(); ++itr)
                if (Creature* cr = Unit::GetCreature(*me,(*itr)))
                    cr->DisappearAndDie();
        }

        void JustSummoned(Creature* pSummon)
        {
            switch(pSummon->GetEntry())
            {
                case NPC_DEEP_MURLOC: ++spawnCounter[COUNTER_DEEP_MURLOC];  break;
                case NPC_MINDLASHER:  ++spawnCounter[COUNTER_MINDLASHER];   break;
                case NPC_BEHEMOTH:    ++spawnCounter[COUNTER_BEHEMOTH];     break;
                case NPC_BEAST:       ++spawnCounter[COUNTER_BEAST];        break;
                case NPC_SAPPER:      ++spawnCounter[COUNTER_SAPPER];       break;
            }

            if (pSummon->GetEntry() == NPC_SAPPER)
            {
                pSummon->CastSpell(me, SPELL_ENTANGLING_GRASP, true);
            }

            summons.push_back(pSummon->GetGUID());
            pSummon->AI()->AttackStart(me);
        }

        void JustDied(Unit* /*pKiller*/)
        {
            Talk(SAY_DEATH);

            if (instance)
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TIDAL_SURGE);
                instance->HandleGameObject(instance->GetData64(GO_OZUMAT_DOOR), true);
            }

            DespawnSummons();
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_ENTANGLING_GRASP)
            {
                me->CastSpell(me, SPELL_GRIP_STUN, true);
            }
        }

        void SummonAdd(uint32 entry, uint8 spawnCount)
        {
            if (entry == NPC_SAPPER)
            {
                me->SummonCreature(entry,-143.599869f, 985.389221f, 230.390076f, 0.024302f,TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                me->SummonCreature(entry,-130.816040f, 968.372253f, 230.172058f, 1.370475f,TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                me->SummonCreature(entry,-140.050064f, 1004.192871f, 229.926407f, 5.370507f,TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                return;
            }

            for (uint8 i = 0; i < spawnCount; ++i)
               me->SummonCreature(entry,RAND(spawns[0],spawns[1]),TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
        }

        void StartEvent()
        {
            isEncounterStarted = true;
            phase = PHASE_MINDLASHES;
            DoZoneInCombat();
            Talk(RAND(SAY_PHASE_1_1, SAY_PHASE_1_2));
            me->SetOrientation(0.166467f);
            me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
            if (instance)
                instance->HandleGameObject(instance->GetData64(GO_OZUMAT_DOOR), false);
            // me->MonsterSay(SAY_1,LANG_UNIVERSAL,NULL);
        }

        void UpdateAI(uint32 diff)
        {
            if (!isEncounterStarted || phase == PHASE_OZUMAT_FIGHT)
                return;

            if (phase == PHASE_MINDLASHES)
            {
                if (summonMurlocTimer <= diff && spawnCounter[COUNTER_DEEP_MURLOC] < 9)
                {
                    SummonAdd(NPC_DEEP_MURLOC, 3);
                    summonMurlocTimer = 10000;
                } else summonMurlocTimer -= diff;

                if (summonMindlasherTimer <= diff && spawnCounter[COUNTER_MINDLASHER] < 3)
                {
                    SummonAdd(NPC_MINDLASHER, 1);
                    summonMindlasherTimer = 20000;
                } else summonMindlasherTimer -= diff;

                if (summonBehemothTimer <= diff && !spawnCounter[COUNTER_BEHEMOTH])
                    SummonAdd(NPC_BEHEMOTH, 1);
                else summonBehemothTimer -= diff;
            }
            else if (phase == PHASE_SAPPERS)
            {
                if (summonBeastTimer <= diff && spawnCounter[COUNTER_BEAST] < 3)
                    SummonAdd(NPC_BEAST, 1);
                else summonBeastTimer -= diff;

                if (!spawnCounter[COUNTER_SAPPER])
                    SummonAdd(NPC_SAPPER,3);
            }
            else if (phase == PHASE_OZUMAT)
            {
                me->RemoveAurasDueToSpell(SPELL_GRIP_STUN);
                if (instance)
                {
                    instance->DoCastSpellOnPlayers(SPELL_TIDAL_SURGE);
                    if (Creature * ozumat = Unit::GetCreature(*me, instance->GetData64(DATA_OZUMAT)))
                    {
                        ozumat->setFaction(16);
                        if (Creature * blight = ozumat->SummonCreature(44801, -145.697f, 985.088f, 230.406f, 6.137f, TEMPSUMMON_TIMED_DESPAWN, 300000))
                        {
                            blight->CastSpell(blight, 83607, true, NULL, NULL, ozumat->GetGUID());
                            ozumat->CastSpell(blight, SPELL_BLIGHT_OF_OZUMAT, true);
                        }
                        phase = PHASE_OZUMAT_FIGHT;
                    }
                }
            }
        }
    };

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == 1000) //Start battle
            CAST_AI(npc_neptulon::npc_neptulonAI, pCreature->AI())->StartEvent();

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "We are ready!", GOSSIP_SENDER_MAIN, 1000);
        pPlayer->PlayerTalkClass->SendGossipMenu(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }
};

class boss_ozumat : public CreatureScript
{
public:
    boss_ozumat() : CreatureScript("boss_ozumat") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_ozumatAI (creature);
    }

    struct boss_ozumatAI : public ScriptedAI
    {
        boss_ozumatAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void AttackStart(Unit * /*who*/) { }
        void MoveInLineOfSight(Unit * /*who*/) { }

        void JustDied(Unit * who)
        {
            // Spawn Chest
            if (GameObject* pChest = who->SummonGameObject(instance->instance->IsHeroic() ? GO_OZUMAT_CHEST_HEROIC : GO_OZUMAT_CHEST_NORMAL, -145.697f, 985.088f, 230.406f, 6.137f, 0, 0, 0, 0, 90000000))
                pChest->SetRespawnTime(pChest->GetRespawnDelay());

            // Remove Blight of Ozumat
            if (Creature * blight = GetClosestCreatureWithEntry(me, 44801, 100.0f))
                blight->DespawnOrUnsummon();

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CLEAR_TIDAL_SURGE);
        }

        void EnterEvadeMode()
        {
            me->setFaction(35);
            me->SetHealth(me->GetMaxHealth());
            me->InterruptNonMeleeSpells(true);
            ScriptedAI::EnterEvadeMode();
            // Evade Neptulon
            if(Creature * neptulon = GetClosestCreatureWithEntry(me, NPC_NEPTULON, 100.0f))
                neptulon->Respawn(true);
            // Remove Blight
            if (Creature * blight = GetClosestCreatureWithEntry(me, 44801, 100.0f))
                blight->DespawnOrUnsummon();

            if (instance)
                instance->HandleGameObject(instance->GetData64(GO_OZUMAT_DOOR), true);
        }
    };
};

void AddSC_boss_ozumat()
{
    new npc_neptulon();
    new boss_ozumat();
}
