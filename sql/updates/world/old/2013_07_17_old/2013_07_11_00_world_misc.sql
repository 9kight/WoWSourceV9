DELETE FROM `smart_scripts` WHERE `entryorguid` = 17591;

UPDATE `creature_template` SET `spell1` = '0', `spell2` = '0', `spell3` = '0',  `AIName` = '' WHERE `entry` =17591;

UPDATE `creature` SET `spawntimesecs` = '300' WHERE `id` =17591;

DELETE FROM `creature` WHERE `guid` = 155014;

UPDATE `creature_template` SET `mindmg` = '10000', `maxdmg` = '10000', `attackpower` = '5000', `dmg_multiplier` = '1', `Health_mod` = '6.604', `mechanic_immune_mask` = '16', `equipment_id` = '50615' WHERE `entry` =50615;

UPDATE `creature_template` SET `mindmg` = '10000', `maxdmg` = '10000', `attackpower` = '5000', `dmg_multiplier` = '1', `Health_mod` = '6.604', `mechanic_immune_mask` = '16', `equipment_id` = '50613' WHERE `entry` =50613;

DELETE FROM `creature_equip_template` WHERE `entry` IN (50615,50613);
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(50613, 1, 3432, 0, 0),
(50615, 1, 2147, 2052, 0);
