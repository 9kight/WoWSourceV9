/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Player.h"

/*######
## Quest 25134: Lazy Peons
## npc_lazy_peon
######*/

enum LazyPeonYells
{
    SAY_SPELL_HIT                                 = 0
};

enum LazyPeon
{
    QUEST_LAZY_PEONS    = 25134,
    GO_LUMBERPILE       = 175784,
    SPELL_BUFF_SLEEP    = 17743,
    SPELL_AWAKEN_PEON   = 19938
};

class npc_lazy_peon : public CreatureScript
{
public:
    npc_lazy_peon() : CreatureScript("npc_lazy_peon") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_lazy_peonAI(creature);
    }

    struct npc_lazy_peonAI : public ScriptedAI
    {
        npc_lazy_peonAI(Creature* creature) : ScriptedAI(creature) {}

        uint64 PlayerGUID;

        uint32 RebuffTimer;
        bool work;

        void Reset()
        {
            PlayerGUID = 0;
            RebuffTimer = 0;
            work = false;
        }

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            if (id == 1)
                work = true;
        }

        void SpellHit(Unit* caster, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_AWAKEN_PEON && caster->GetTypeId() == TYPEID_PLAYER
                && CAST_PLR(caster)->GetQuestStatus(QUEST_LAZY_PEONS) == QUEST_STATUS_INCOMPLETE)
            {
                caster->ToPlayer()->KilledMonsterCredit(me->GetEntry(), me->GetGUID());
                Talk(SAY_SPELL_HIT, caster->GetGUID());
                me->RemoveAllAuras();
                if (GameObject* Lumberpile = me->FindNearestGameObject(GO_LUMBERPILE, 20))
                    me->GetMotionMaster()->MovePoint(1, Lumberpile->GetPositionX()-1, Lumberpile->GetPositionY(), Lumberpile->GetPositionZ());
            }
        }

        void UpdateAI(const uint32 Diff)
        {
            if (work == true)
                me->HandleEmoteCommand(EMOTE_ONESHOT_WORK_CHOPWOOD);
            if (RebuffTimer <= Diff)
            {
                DoCast(me, SPELL_BUFF_SLEEP);
                RebuffTimer = urand(60000, 90000); //Rebuff again between 1min and 1min30
            }
            else
                RebuffTimer -= Diff;
            if (!UpdateVictim())
                return;
            DoMeleeAttackIfReady();
        }
    };
};

enum VoodooSpells
{
    SPELL_BREW      = 16712, // Special Brew
    SPELL_GHOSTLY   = 16713, // Ghostly
    SPELL_HEX1      = 16707, // Hex
    SPELL_HEX2      = 16708, // Hex
    SPELL_HEX3      = 16709, // Hex
    SPELL_GROW      = 16711, // Grow
    SPELL_LAUNCH    = 16716, // Launch (Whee!)
};

// 17009
class spell_voodoo : public SpellScriptLoader
{
    public:
        spell_voodoo() : SpellScriptLoader("spell_voodoo") {}

        class spell_voodoo_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_voodoo_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_BREW) || !sSpellMgr->GetSpellInfo(SPELL_GHOSTLY) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HEX1) || !sSpellMgr->GetSpellInfo(SPELL_HEX2) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HEX3) || !sSpellMgr->GetSpellInfo(SPELL_GROW) ||
                    !sSpellMgr->GetSpellInfo(SPELL_LAUNCH))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                uint32 spellid = RAND(SPELL_BREW, SPELL_GHOSTLY, RAND(SPELL_HEX1, SPELL_HEX2, SPELL_HEX3), SPELL_GROW, SPELL_LAUNCH);
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, spellid, false);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_voodoo_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_voodoo_SpellScript();
        }
};


/*####
# npc_darkspear_jailor
####*/

enum SayDarkspear
{
    SAY_DARKSPERAR_1   = 0, 
    SAY_SPITESCALE_1   = 1, 

};

#define GOSSIP_ITEM_1 "I'm ready to face my challange."

class npc_darkspear_jailor : public CreatureScript
{
public:
    npc_darkspear_jailor() : CreatureScript("npc_darkspear_jailor") { }

    bool OnGossipHello(Player* Player, Creature* Creature)
    {
        if (Player)
        {
            Player->PrepareGossipMenu(Creature);
            if (Player->GetQuestStatus(24786) == QUEST_STATUS_INCOMPLETE || Player->GetQuestStatus(24754) == QUEST_STATUS_INCOMPLETE ||
                Player->GetQuestStatus(24762) == QUEST_STATUS_INCOMPLETE || Player->GetQuestStatus(24774) == QUEST_STATUS_INCOMPLETE ||
                Player->GetQuestStatus(26276) == QUEST_STATUS_INCOMPLETE || Player->GetQuestStatus(24642) == QUEST_STATUS_INCOMPLETE ||
                Player->GetQuestStatus(24768) == QUEST_STATUS_INCOMPLETE || Player->GetQuestStatus(24780) == QUEST_STATUS_INCOMPLETE)
                    Player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            
            Player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, Creature->GetGUID());
        }
        return true;
    }

    bool OnGossipSelect(Player* Player, Creature* Creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        Player->PlayerTalkClass->ClearMenus();
                
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF:
                if (Creature->GetGUIDLow() == 306002)
                    Creature->GetMotionMaster()->MovePath(0, false);
                else if (Creature->GetGUIDLow() == 127668)
                    Creature->GetMotionMaster()->MovePath(1, false);
                   
                npc_darkspear_jailorAI* AI = CAST_AI(npc_darkspear_jailorAI,Creature->AI());
                if (AI)
                    AI->StartMovingToCage();
                
                Player->KilledMonsterCredit(39062, Creature->GetGUID());

                Player->CLOSE_GOSSIP_MENU();
                break;
        }
        Player->CLOSE_GOSSIP_MENU();
        return true;
    }

    CreatureAI* GetAI(Creature* Creature) const
    {
        return new npc_darkspear_jailorAI (Creature);
    }

    struct npc_darkspear_jailorAI : public ScriptedAI
    {
        npc_darkspear_jailorAI(Creature* Creature) : ScriptedAI(Creature)
        { }

        uint8 uiPhase;
        uint32 uiTimer;
        
        void Reset()
        {
            uiPhase = 0;
            uiTimer = 2000;
        }
        
        void StartMovingToCage()
        {
            uiPhase = 1;
            uiTimer = 8000;
            Talk(SAY_DARKSPERAR_1);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (uiTimer <= uiDiff)
            {
                switch(uiPhase)
                {
                    case 0:
                        break;
                    case 1:
                        uiPhase = 2;
                        uiTimer = 8000;
                    case 2:
                        if (GameObject* Cage = me->FindNearestGameObject(201968, 5.0f))
                                Cage->SetGoState(GO_STATE_ACTIVE);

                        if (Creature* Spitescale = me->FindNearestCreature(38142, 30.0f, true))
                        {
                            Talk(SAY_SPITESCALE_1);
                            if (me->GetGUIDLow() == 306002)
                                Spitescale->GetMotionMaster()->MovePoint(0, -1144.48f, -5414.22f, 10.59f);
                            else if (me->GetGUIDLow() == 127668)
                                Spitescale->GetMotionMaster()->MovePoint(0, -1149.88f, -5527.07f, 8.10f);

                            Spitescale->setFaction(16);
                            Spitescale->SetReactState(REACT_AGGRESSIVE);
                            Spitescale->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            Spitescale->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        }
                        uiPhase = 3;
                        uiTimer = 2000;
                        break;
                    case 3:
                        if (GameObject* Cage = me->FindNearestGameObject(201968, 5.0f))
                            Cage->SetGoState(GO_STATE_READY);

                        me->DealDamage(me, 10000);
                        me->RemoveCorpse();
                        uiPhase = 0;
                        uiTimer = 1000;
                        break;
                }
            } else
                uiTimer -= uiDiff;
        }
    };

};

void AddSC_durotar()
{
    new npc_lazy_peon();
    new spell_voodoo();
    new npc_darkspear_jailor();
}
