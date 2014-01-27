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


enum eNazjarYells
{
    SAY_AGGRO                   = 0,
    SAY_DEATH                   = 1,
    SAY_KILL_1                  = 2,
    SAY_KILL_2                  = 3,

    SAY_66_PRECENT              = 4, // New Yells after a Patch?
    SAY_33_PRECENT              = 5, // New Yells after a Patch?
};

enum eNazjarSpells
{
    SPELL_WATERSPOUT            = 75683,

    SPELL_FUNGAL_SPORE          = 76001,
    SPELL_SHOCK_BLAST           = 76008,
    SPELL_SUMMON_GEYSER         = 75722,
    SPELL_GEYSER_ERUPTION       = 75700,

    // Heroic
    SPELL_WATERSPOUT_SUMMON     = 90495,
    SPELL_WATERSPOUT_AURA       = 90440,
    SPELL_WATERSPOUT_TORNADO    = 90479,
    SPELL_SHOCK_BLAST_H         = 91477,
    SPELL_GEYSER_ERUPTION_H     = 91469,
};

struct Coords
{
    uint32 entry;
    float x, y, z, o;
};

static Coords Info[3] =
{
    { NPC_SUMMONED_WITCH, 191.638672f, 761.246704f, 821.372498f, 1.618042f },
    { NPC_SUMMONED_WITCH, 232.307297f, 801.006836f, 821.372498f, 3.161349f },
    { NPC_SUMMONED_GUARD, 192.254059f, 843.380981f, 821.372498f, 4.472963f }
};

class boss_lady_nazjar : public CreatureScript
{
public:
    boss_lady_nazjar() : CreatureScript("boss_lady_nazjar") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lady_nazjarAI (creature);
    }

    struct boss_lady_nazjarAI : public ScriptedAI
    {
        boss_lady_nazjarAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint8 SummonCount;
        uint32 GeyserTimer;
        uint32 FungalSporeTimer;
        uint32 ShockBlastTimer;
        uint32 WaterSpoutPhaseTimer;
        bool WaterSpoutCounter;
        bool IsWaterSpoutPhase;

        void Reset()
        {
            WaterSpoutCounter = false;
            IsWaterSpoutPhase = false;
            SummonCount = 0;

            FungalSporeTimer = urand(9000, 15000);
            ShockBlastTimer = urand(14000, 20000);
            GeyserTimer = urand(6000, 10000);

            if (instance)
                instance->SetData(DATA_LADY_NAZJAR_EVENT, NOT_STARTED);
        }

        void JustDied(Unit* /*Kill*/)
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(DATA_LADY_NAZJAR_EVENT, DONE);
        }

        void EnterCombat(Unit* /*Ent*/)
        {
            Talk(SAY_AGGRO);

            if (instance)
            {
                instance->HandleGameObject(instance->GetData64(GO_LADY_NAZJAR_DOOR), false);
                instance->SetData(DATA_LADY_NAZJAR_EVENT, IN_PROGRESS);
            }
        }

        void JustReachedHome()
        {
            if (instance)
                instance->HandleGameObject(instance->GetData64(GO_LADY_NAZJAR_DOOR), true);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(RAND(SAY_KILL_1,SAY_KILL_2));
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            switch(summon->GetEntry())
            {
                case NPC_SUMMONED_WITCH:
                case NPC_SUMMONED_GUARD:
                    --SummonCount;
                    break;
            }
        }

        void JustSummoned(Creature * pcreat)
        {
            if (pcreat->GetEntry() == NPC_SUMMONED_WATERSPOUT)
            {
                pcreat->CastSpell(pcreat, SPELL_WATERSPOUT_AURA, true);
                // Move to random position in around the world
                Position pos;
                pcreat->GetNearPosition(pos, 30.0f, (float)rand_norm()*static_cast<float>(2*M_PI));
                pcreat->GetMotionMaster()->MovePoint(1, pos);
                pcreat->DespawnOrUnsummon(15000);
            }
        }

        void UpdateAI(uint32 const Diff) 
        {
            if (!UpdateVictim())
                return;

            // Waterspout on 60% and 30% of health
            if((me->GetHealthPct() < 60 && !WaterSpoutCounter && me->GetHealthPct() > 30) || (me->GetHealthPct() < 30 && WaterSpoutCounter))
            {
                Talk(WaterSpoutCounter ? SAY_33_PRECENT : SAY_66_PRECENT);

                WaterSpoutCounter = !WaterSpoutCounter;
                IsWaterSpoutPhase = true;
                WaterSpoutPhaseTimer = 60000;

                if (IsHeroic())
                    DoTeleportTo(192.056f, 802.527f, 807.638f, 3.13f);

                // Stop movement
                SetCombatMovement(false);

                for(uint8 i = 0; i < 3; ++i)
                    if (Creature * creature = me->SummonCreature(Info[i].entry, Info[i].x, Info[i].y, Info[i].z, Info[i].o, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000))
                    {
                        DoZoneInCombat(creature);
                        float x,y,z;
                        creature->GetClosePoint(x, y, z, creature->GetObjectSize(), 10);
                        creature->GetMotionMaster()->MoveJump(x, y, 807.638f, 15, 15);
                    }

                SummonCount = 3;

                me->CastSpell(me, SPELL_WATERSPOUT, false);
                // On heroic apply aura to summon tornado periodically
                if (IsHeroic())
                    me->AddAura(SPELL_WATERSPOUT_SUMMON, me);
            }

            if (IsWaterSpoutPhase)
            {
                if (WaterSpoutPhaseTimer < Diff || SummonCount == 0)
                {
                    me->RemoveAurasDueToSpell(SPELL_WATERSPOUT);
                    me->RemoveAurasDueToSpell(SPELL_WATERSPOUT_SUMMON);
                    SetCombatMovement(true);
                    IsWaterSpoutPhase = false;
                }
                else
                    WaterSpoutPhaseTimer -= Diff;

                return;
            }

            if (ShockBlastTimer <= Diff)
            {
                if (me->IsNonMeleeSpellCasted(false))
                    return;

                DoCastVictim(SPELL_SHOCK_BLAST);
                ShockBlastTimer = 16000;
            }
            else
                ShockBlastTimer -= Diff;

            if (GeyserTimer <= Diff)
            {
                if (me->IsNonMeleeSpellCasted(false))
                    return;

                if (Unit * pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    me->CastSpell(pTarget, SPELL_SUMMON_GEYSER, false);

                GeyserTimer = urand(9000, 14000);
            }
            else
                GeyserTimer -= Diff;

            if (FungalSporeTimer <= Diff)
            {
                if (me->IsNonMeleeSpellCasted(false))
                    return;

                if (Unit * pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    me->CastSpell(pTarget, SPELL_FUNGAL_SPORE, false);

                FungalSporeTimer = urand(12000, 16000);
            }
            else
                FungalSporeTimer -= Diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_nazjar()
{
    new boss_lady_nazjar();
}