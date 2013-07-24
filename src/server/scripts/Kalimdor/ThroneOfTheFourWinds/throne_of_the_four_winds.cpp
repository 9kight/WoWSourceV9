/*
 * Copyright (C) 2005 - 2011 MaNGOS <http://www.getmangos.org/>
 *
 * Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
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
#include "throne_of_the_four_winds.h"

enum SlipstreamEnums
{
	// Land Positions
	DIR_WEST_TO_SOUTH,
	DIR_SOUTH_TO_WEST,
	DIR_NORTH_TO_WEST,
	DIR_WEST_TO_NORTH,
	DIR_EAST_TO_NORTH,
	DIR_NORTH_TO_EAST,
	DIR_SOUTH_TO_EAST,
	DIR_EAST_TO_SOUTH,
	DIR_ERROR,

	// Spells
	SPELL_SLIPSTREAM_BUFF = 87740,
	SPELL_SLIPSTREAM_PLAYER_VISUAL = 85063,
};

Position const SlipstreamPositions[8] =
{
       {-255.724442f, 851.088196f,  197.458450f, 0},
       {-81.460991f,  1021.332886f, 197.457794f, 0},
       {-16.013720f,  1021.263489f, 197.457809f, 0},
       {154.722855f,  846.790833f,  197.457855f, 0},
       {154.254684f,  780.857056f,  197.457703f, 0},
       {-19.915119f,  610.227173f,  197.457764f, 0},
       {-85.522423f,  610.501892f,  197.457733f, 0},
       {-256.007965f, 785.272095f,  197.457764f, 0},
};

class npc_slipstream_raid : public CreatureScript
{
public:
	npc_slipstream_raid() : CreatureScript("npc_slipstream_raid") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_slipstream_raidAI (creature);
	}

	struct npc_slipstream_raidAI : public ScriptedAI
	{
		npc_slipstream_raidAI(Creature* creature) : ScriptedAI(creature)
		{
			creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);

			SlipstreamPosition = 8;

			for(uint8 i = 0; i<=7; i++)
				if(me->GetDistance2d(SlipstreamPositions[i].GetPositionX(), SlipstreamPositions[i].GetPositionY()) < 10)
				{
					SlipstreamPosition = i;
					break;
				}

				if(SlipstreamPosition >= DIR_ERROR)
					return;

				SlipstreamPosition += (SlipstreamPosition == DIR_WEST_TO_SOUTH || SlipstreamPosition == DIR_NORTH_TO_WEST ||
					SlipstreamPosition == DIR_EAST_TO_NORTH || SlipstreamPosition == DIR_SOUTH_TO_EAST ) ? 1 : -1;
		}

		uint8 SlipstreamPosition;

		void MoveInLineOfSight(Unit* who)
		{
			if(SlipstreamPosition >= DIR_ERROR || who->GetTypeId() != TYPEID_PLAYER)
				return;

			if(who->GetExactDist(me) <= 5.f)
			{
				me->AddAura(SPELL_SLIPSTREAM_BUFF,who);
				me->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL,who);

				who->UpdatePosition(SlipstreamPositions[SlipstreamPosition],false);

				who->GetMotionMaster()->MoveJump(SlipstreamPositions[SlipstreamPosition].GetPositionX(),SlipstreamPositions[SlipstreamPosition].GetPositionY(),198.458481f,1,6);
			}
		}
	};
};

void AddSC_throne_of_the_four_winds()
{
	new npc_slipstream_raid();
}