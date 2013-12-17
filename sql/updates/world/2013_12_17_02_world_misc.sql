-- http://www.wowhead.com/npc=3771#abilities quest id  284 level of the npc fixed 
Update creature_template set spell1=8599,spell2=13878,spell3=11939,spell4=12746,minlevel=19,maxlevel=20,mindmg=27,maxdmg=36,faction_A=90,faction_H=90,Health_mod=1 WHERE entry =3771;

-- spell of the npc fixed
Update creature_template set spell1=8599,spell2=77471,spell3=11939,
minlevel=19,maxlevel=20, mindmg=27,maxdmg=36 WHERE entry =3770;

-- Quest http://www.wowhead.com/quest=26455#. objet id 181681 spawned 
DELETE FROM `gameobject` WHERE (`guid`=201139);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`)
VALUES (201139, 181681, 1, 1, 65535, 2781.75, -2977.88, 148.918, 5.32427, 0, 0, 0.461296, -0.887246, 300, 0, 1);

-- removing rong spells (talents) from npc trainers
DELETE FROM npc_trainer WHERE spell IN (23881,1329,18562);
