DELETE FROM `creature` WHERE `guid` = 301533;
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(301533, 45124, 755, 5396, 5631, 3, 65535, 0, 0, -11044.4, -1647.29, 0.745158, 0.961503, 300, 0, 0, 58681, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `difficulty_entry_1` = '49043', `Health_mod` = '27.3396' WHERE `entry` =43614;

UPDATE `creature_template` SET `flags_extra` = '130' WHERE `entry` =45124;

UPDATE `creature_template` SET `Health_mod` = '61.5347' WHERE `entry` =49043;

DELETE FROM `creature` WHERE `id` = 9034959;

DELETE FROM `creature_template` WHERE `entry` = 9034959;

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `faction_A` = '16', `faction_H` = '16', `flags_extra` = '130' WHERE `entry` IN (40255,40228,40567,40030);

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `exp` = '3', `faction_A` = '16', `faction_H` = '16', `mindmg` = '500', `maxdmg` = '800' WHERE `entry` =39388;

DELETE FROM `npc_trainer` WHERE `npc_trainer`.`entry` = 200007 AND `spell` = 2825;
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
(200007, 2825, 117333, 0, 0, 70);
