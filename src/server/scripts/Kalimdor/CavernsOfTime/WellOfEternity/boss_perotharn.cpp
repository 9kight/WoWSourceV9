/*
 * Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
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

 /* ScriptData
SDName: boss_perotharn
SD%Complete: 0
SDComment: Placeholder
SDCategory: Well of Eternity
EndScriptData */

#include "well_of_eternity.h"

enum
{
    // ToDo: add spells and yells here
};

class boss_perotharn : public CreatureScript
{
public:
    boss_perotharn() : CreatureScript("boss_perotharn") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_perotharnAI (creature);
    }

    struct boss_perotharnAI : public BossAI
    {
        boss_perotharnAI(Creature* creature) : BossAI(creature, DATA_PEROTHARN_EVENT)
        {
            instance = creature->GetInstanceScript();			
        }

          InstanceScript* instance;
		  
           bool IsRegularMode;

             void Reset() 
                {
                  me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                  me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }

				void EnterCombat(Unit* /*who*/)
                {
                 if (instance)
                     instance->SetData(DATA_PEROTHARN_EVENT, IN_PROGRESS);
                }				
				

             void JustDied(Unit* Killer) 
                {
                 if (instance)
                     instance->SetData(DATA_PEROTHARN_EVENT, DONE);
                }

             void KilledUnit(Unit* Victim) 
               {
               }

             void JustReachedHome() 
               {
                 if (instance)
                    instance->SetData(DATA_PEROTHARN_EVENT, FAIL);
               }

           void UpdateAI(const uint32 uiDiff) 
              {
           if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

                DoMeleeAttackIfReady();
  
              }
	 };
};

void AddSC_boss_perotharn()
{
  new boss_perotharn();
}