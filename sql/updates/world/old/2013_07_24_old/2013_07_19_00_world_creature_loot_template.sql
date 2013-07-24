DELETE FROM `creature_loot_template` WHERE `entry` IN (49624,49538);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(49624, 52078, 100, 1, 0, 1, 1),
(49624, 56343, 18, 1, 0, 1, 1),
(49624, 56344, 18.2, 1, 0, 1, 1),
(49624, 56345, 18.5, 1, 0, 1, 1),
(49624, 56346, 20, 1, 0, 1, 1),
(49624, 56347, 18, 1, 0, 1, 1),
(49624, 56348, 17, 1, 0, 1, 1),
(49624, 56349, 18.1, 1, 0, 1, 1),
(49624, 56351, 19, 1, 0, 1, 1),
(49624, 56352, 19.4, 1, 0, 1, 1),
(49538, 56333, 20, 1, 0, 1, 1),
(49538, 56334, 19.3, 1, 0, 1, 1),
(49538, 56335, 19.5, 1, 0, 1, 1),
(49538, 56336, 19, 1, 0, 1, 1),
(49538, 63043, 0.9, 1, 0, 1, 1),
(49538, 71715, 0.6, 1, 0, 1, 1);

UPDATE `creature_template` SET `lootid` = '49624' WHERE `entry` =49624;

UPDATE `creature_template` SET `equipment_id` = '42333' WHERE `entry` =42333;

DELETE FROM `creature_equip_template` WHERE `entry` = 42333;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(42333, 1, 33766, 0, 0);

UPDATE `creature_template` SET `lootid` = '49538' WHERE `entry` =49538;
