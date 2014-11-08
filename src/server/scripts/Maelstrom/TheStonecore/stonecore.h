/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_STONECORE_H
#define DEF_STONECORE_H

#define SCScriptName "instance_stonecore"
#define DataHeader "SC"

enum DataTypes
{
	// Encounter States/Boss GUIDs
	DATA_CORBORUS,
	DATA_SLABHIDE,
	DATA_OZRUK,
	DATA_HIGH_PRIESTESS_AZIL,

	// Additional Data
	DATA_CORBORUS_INTRO,
	DATA_MILLHOUSE_MANASTORM,
	DATA_CORBORUS_INTRO_TRASH, // Trash guids
	DATA_CORBORUS_INTRO_TRASH_LAST = DATA_CORBORUS_INTRO_TRASH + 8,

	DATA_SLABHIDE_INTRO,

	DATA_SLABHIDE_ROCK_WALL,
};

enum Misc
{
	ACTION_CORBORUS_INTRO,
	ACTION_SLABHIDE_INTRO,

	NPC_WORLDTRIGGER = 22515,
	NPC_MILLHOUSE_MANASTORM = 43391,
	NPC_SEISMIC_SHARD = 42355,
	NPC_FOLLOWER = 42428,

	NPC_CORBORUS = 43438,
	NPC_SLABHIDE = 43214,
	NPC_OZRUK = 42188,
	NPC_HIGH_PRIESTESS_AZIL = 42333,

	// Stonecore Teleporter misc
	NPC_STONECORE_TELEPORTER = 51396, // Entrance teleporter
	NPC_STONECORE_TELEPORTER_2 = 51397, // Slabhide teleporter
	SPELL_TELEPORTER_ACTIVE_VISUAL = 95298,

	GAMEOBJECT_TWILIGHT_DOCUMENTS = 207415,
	GAMEOBJECT_CORBORUS_ROCKDOOR = 207343,
	GAMEOBJECT_SLABHIDE_ROCK_WALL = 204381,

	VEHICLE_GRIP = 892,
	VEHICLE_NORMAL = 903,
	POINT_FLY = 1,
	POINT_PLATFORM = 2,
};

#endif // DEF_STONECORE