/*
* Copyright (C) 2008-2011 Trinity <http://www.trinitycore.org/>
*
* Copyright (C) 2012-2013 StealthCoders
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifdef DEF_ENDTIME_H_
#define DEF_ENDTIME_H_

uint32 const EncounterCount = 5;

enum Data64
{
    DATA_ECHO_OF_BAINE,
    DATA_ECHO_OF_JAINA,
    DATA_ECHO_OF_SYLVANAS,
    DATA_ECHO_OF_TYRANDE,
    DATA_MUROZOND,
    DATA_JAINAS_STAFF,
    DATA_FRAGMENTS
};
enum CreaturesIds
{
    BOSS_BAINE					= 54431,
    BOSS_JAINA					= 54445,
    BOSS_SYLVANAS				= 54123,
    BOSS_TYRANDE				= 54544,
    BOSS_MUROZOND				= 54432,

    NPC_RISEN_GHOUL				= 54191,

    NPC_NOZDORMU_BAINE			= 60000,
};

enum GameObjectsIds
{
    HOURGLASS_OF_TIME			= 209249,
    TIME_TRANSIT_DEVICE			= 209441,
    MUROSZONDS_TEMPORAL_CACHE	= 209547,
    BAINE_PLATFORM_1			= 209693,
    BAINE_PLATFORM_2			= 209695,
    BAINE_PLATFORM_3			= 209670,
    BAINE_PLATFORM_4			= 209694,
    JAINAS_STAFF				= 209318
};

#endif // ENDTIME_H_