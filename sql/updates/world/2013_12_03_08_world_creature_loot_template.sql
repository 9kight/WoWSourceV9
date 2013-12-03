-- 23574 Akil'zon (Eagle)
-- 23576 Nalorakk (Bear)
-- 23578 Jan'alai (Dragonhawk)
-- 23577 Halazzi (Lynx)
-- 24239 Hex Lord Malacrass
-- 23863 Daakara

DELETE FROM `creature_loot_template` WHERE `entry`='23574';
INSERT INTO `creature_loot_template` VALUES ('23574', '1', '100', '1', '0', '-58064', '2');
UPDATE `creature_template` SET lootid='23574' WHERE entry='23574';
DELETE FROM `reference_loot_template` WHERE `entry`='58064';
INSERT INTO `reference_loot_template` VALUES ('58064', '69549', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58064', '69552', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58064', '69551', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58064', '69550', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58064', '69553', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='23576';
INSERT INTO `creature_loot_template` VALUES ('23576', '1', '100', '1', '0', '-58065', '2');
UPDATE `creature_template` SET lootid='23576' WHERE entry='23576';
DELETE FROM `reference_loot_template` WHERE `entry`='58065';
INSERT INTO `reference_loot_template` VALUES ('58065', '69557', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58065', '69554', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58065', '69555', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58065', '69556', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58065', '69558', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='23578';
INSERT INTO `creature_loot_template` VALUES ('23578', '1', '100', '1', '0', '-58066', '2');
UPDATE `creature_template` SET lootid='23578' WHERE entry='23578';
DELETE FROM `reference_loot_template` WHERE `entry`='58066';
INSERT INTO `reference_loot_template` VALUES ('58066', '69559', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58066', '69560', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58066', '69563', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58066', '69562', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58066', '69561', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='23577';
INSERT INTO `creature_loot_template` VALUES ('23577', '1', '100', '1', '0', '-58067', '2');
UPDATE `creature_template` SET lootid='23577' WHERE entry='23577';
DELETE FROM `reference_loot_template` WHERE `entry`='58067';
INSERT INTO `reference_loot_template` VALUES ('58067', '69566', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58067', '69564', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58067', '69565', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58067', '69568', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58067', '69567', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='24239';
INSERT INTO `creature_loot_template` VALUES ('24239', '1', '100', '1', '0', '-58068', '2');
UPDATE `creature_template` SET lootid='24239' WHERE entry='24239';
DELETE FROM `reference_loot_template` WHERE `entry`='58068';
INSERT INTO `reference_loot_template` VALUES ('58068', '69572', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58068', '69569', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58068', '69571', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58068', '69570', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58068', '69573', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58068', '70080', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58068', '69762', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='69264' WHERE entry='24239';

DELETE FROM `creature_loot_template` WHERE `entry`='23863';
INSERT INTO `creature_loot_template` VALUES ('23863', '1', '100', '1', '0', '-58069', '2');
UPDATE `creature_template` SET lootid='23863' WHERE entry='23863';
DELETE FROM `reference_loot_template` WHERE `entry`='58069';
INSERT INTO `reference_loot_template` VALUES ('58069', '52078', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58069', '69581', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58069', '69577', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58069', '69576', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58069', '69582', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58069', '69574', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58069', '69575', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58069', '69579', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58069', '69578', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58069', '69580', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58069', '69583', '0', '1', '1', '1', '1');