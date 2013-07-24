DELETE FROM `npc_trainer` WHERE `entry` = 200007 AND `spell` = 32182;
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
(200007, 32182, 132000, 373, 0, 70);

UPDATE `creature_template` SET `gossip_menu_id` = '0' WHERE `entry` =44726;

UPDATE `gameobject` SET `spawntimesecs` = '300' WHERE `id` IN (202741,202740);

UPDATE `creature_template` SET `AIName` = '', `equipment_id` = '30022' WHERE `entry` =30022;

UPDATE `creature_template` SET `AIName` = '' WHERE `entry` =30014;

UPDATE `creature_template` SET `AIName` = '', `equipment_id` = '30017' WHERE `entry` =30017;

UPDATE `creature_equip_template` SET `itemEntry1` = '41691', `itemEntry2` = '41691' WHERE `entry` =30017;

UPDATE `creature_template` SET `AIName` = '' WHERE `entry` =30019;

UPDATE `creature_template` SET `AIName` = '', `equipment_id` = '30020' WHERE `entry` =30020;

UPDATE `creature_template` SET `AIName` = '' WHERE `entry` =30023;

DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (30022,30014,30017,30019,30020,30023);

UPDATE `creature_template` SET `ScriptName` = 'npc_vladof_the_butcher' WHERE `entry` =30022;

UPDATE `creature_template` SET `flags_extra` = '130' WHERE `entry` =51713;

DELETE FROM `creature` WHERE `guid` IN (117340,117342,117345,117341,117344);

DELTE FROM `creature` WHERE `guid` = 301534;
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(301534, 3334, 1, 1637, 5166, 1, 1, 0, 0, 1811.76, -4268.02, 7.40636, 4.07226, 300, 0, 0, 1003, 0, 0, 0, 0, 0);

DELETE FROM `access_requirement` WHERE `mapId` = 36;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `quest_failed_text`, `comment`) VALUES
(36, 0, 90, 0, 0, 0, 0, 0, 0, NULL, 'DeadMines Entrance'),
(36, 1, 90, 0, 0, 0, 0, 0, 0, NULL, 'DeadMines Entrance Heroic');

UPDATE `gameobject_template` SET `data1` = '202751' WHERE `entry` =202751;

DELETE FROM `gameobject_loot_template` WHERE `entry` = 202751;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(202751, 52329, 39, 1, 0, 1, 3),
(202751, 52987, 100, 1, 0, 2, 9),
(202751, 63122, 10, 1, 0, 1, 1);
