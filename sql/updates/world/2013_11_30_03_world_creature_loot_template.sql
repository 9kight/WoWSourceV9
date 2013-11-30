-- 39625, 48337 General Umbriss
-- 40177, 48702 Forgemaster Throngus
-- 40319, 48784 Drahga Shadowburner
-- 40484, 48822 Erudax
DELETE FROM `creature_loot_template` WHERE `entry`='39625';
INSERT INTO `creature_loot_template` VALUES ('39625', '1', '100', '1', '0', '-58015', '2');
UPDATE `creature_template` SET lootid='39625' WHERE entry='39625';
DELETE FROM `reference_loot_template` WHERE `entry`='58015';
INSERT INTO `reference_loot_template` VALUES ('58015', '56116', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58015', '56115', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58015', '56112', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58015', '56113', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58015', '56114', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48337';
INSERT INTO `creature_loot_template` VALUES ('48337', '1', '100', '1', '0', '-58016', '2');
UPDATE `creature_template` SET lootid='48337' WHERE entry='48337';
DELETE FROM `reference_loot_template` WHERE `entry`='58016';
INSERT INTO `reference_loot_template` VALUES ('58016', '56443', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58016', '56442', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58016', '56441', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58016', '56440', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58016', '56444', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58016', '71715', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='40177';
INSERT INTO `creature_loot_template` VALUES ('40177', '1', '100', '1', '0', '-58017', '2');
UPDATE `creature_template` SET lootid='40177' WHERE entry='40177';
DELETE FROM `reference_loot_template` WHERE `entry`='58017';
INSERT INTO `reference_loot_template` VALUES ('58017', '56120', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58017', '56118', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58017', '56121', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58017', '56122', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58017', '56119', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58017', '71638', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48702';
INSERT INTO `creature_loot_template` VALUES ('48702', '1', '100', '1', '0', '-58018', '2');
UPDATE `creature_template` SET lootid='48702' WHERE entry='48702';
DELETE FROM `reference_loot_template` WHERE `entry`='58018';
INSERT INTO `reference_loot_template` VALUES ('58018', '56447', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58018', '56448', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58018', '56445', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58018', '56449', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58018', '56446', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='40319';
INSERT INTO `creature_loot_template` VALUES ('40319', '1', '100', '1', '0', '-58019', '2');
UPDATE `creature_template` SET lootid='40319' WHERE entry='40319';
DELETE FROM `reference_loot_template` WHERE `entry`='58019';
INSERT INTO `reference_loot_template` VALUES ('58019', '56126', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58019', '56123', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58019', '56127', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58019', '21525', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58019', '56125', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58019', '56124', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58019', '22206', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48784';
INSERT INTO `creature_loot_template` VALUES ('48784', '1', '100', '1', '0', '-58020', '2');
UPDATE `creature_template` SET lootid='48784' WHERE entry='48784';
DELETE FROM `reference_loot_template` WHERE `entry`='58020';
INSERT INTO `reference_loot_template` VALUES ('58020', '56452', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58020', '56451', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58020', '56450', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58020', '56453', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58020', '56454', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58020', '21525', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58020', '66927', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58020', '22206', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='40484';
INSERT INTO `creature_loot_template` VALUES ('40484', '1', '100', '1', '0', '-58021', '2');
UPDATE `creature_template` SET lootid='40484' WHERE entry='40484';
DELETE FROM `reference_loot_template` WHERE `entry`='58021';
INSERT INTO `reference_loot_template` VALUES ('58021', '56137', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58021', '56131', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58021', '56138', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58021', '56132', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58021', '56129', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58021', '56136', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58021', '56133', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58021', '56130', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58021', '56128', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58021', '56135', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48822';
INSERT INTO `creature_loot_template` VALUES ('48822', '1', '100', '1', '0', '-58022', '2');
UPDATE `creature_template` SET lootid='48822' WHERE entry='48822';
DELETE FROM `reference_loot_template` WHERE `entry`='58022';
INSERT INTO `reference_loot_template` VALUES ('58022', '52078', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58022', '56457', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58022', '56463', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58022', '56462', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58022', '56459', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58022', '56458', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58022', '56461', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58022', '56456', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58022', '56464', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58022', '56460', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58022', '56455', '0', '1', '1', '1', '1');