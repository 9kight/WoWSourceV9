-- 43438, 49642 Corborus
-- 43214, 49538 Slabhide
-- 42188, 49654 Ozruk
-- 42333, 49624 High Priestess Azil

DELETE FROM `creature_loot_template` WHERE `entry`='43438';
INSERT INTO `creature_loot_template` VALUES ('43438', '1', '100', '1', '0', '-58050', '2');
UPDATE `creature_template` SET lootid='43438' WHERE entry='43438';
DELETE FROM `reference_loot_template` WHERE `entry`='58050';
INSERT INTO `reference_loot_template` VALUES ('58050', '55795', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58050', '55796', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58050', '55794', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58050', '55792', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58050', '55793', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='52506' WHERE entry='43438';

DELETE FROM `creature_loot_template` WHERE `entry`='49642';
INSERT INTO `creature_loot_template` VALUES ('49642', '1', '100', '1', '0', '-58051', '2');
UPDATE `creature_template` SET lootid='49642' WHERE entry='49642';
DELETE FROM `reference_loot_template` WHERE `entry`='58051';
INSERT INTO `reference_loot_template` VALUES ('58051', '56330', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58051', '56331', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58051', '56329', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58051', '56328', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58051', '56332', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='52506' WHERE entry='49642';

DELETE FROM `creature_loot_template` WHERE `entry`='43214';
INSERT INTO `creature_loot_template` VALUES ('43214', '1', '100', '1', '0', '-58052', '2');
UPDATE `creature_template` SET lootid='43214' WHERE entry='43214';
DELETE FROM `reference_loot_template` WHERE `entry`='58052';
INSERT INTO `reference_loot_template` VALUES ('58052', '55799', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58052', '55797', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58052', '55801', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58052', '55798', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58052', '63043', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='49538';
INSERT INTO `creature_loot_template` VALUES ('49538', '1', '100', '1', '0', '-58053', '2');
UPDATE `creature_template` SET lootid='49538' WHERE entry='49538';
DELETE FROM `reference_loot_template` WHERE `entry`='58053';
INSERT INTO `reference_loot_template` VALUES ('58053', '56334', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58053', '56336', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58053', '56335', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58053', '56333', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58053', '63043', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71715' WHERE entry='49538';

DELETE FROM `creature_loot_template` WHERE `entry`='42188';
INSERT INTO `creature_loot_template` VALUES ('42188', '1', '100', '1', '0', '-58054', '2');
UPDATE `creature_template` SET lootid='42188' WHERE entry='42188';
DELETE FROM `reference_loot_template` WHERE `entry`='58054';
INSERT INTO `reference_loot_template` VALUES ('58054', '55811', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58054', '55804', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58054', '55810', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58054', '55802', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58054', '55803', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='49654';
INSERT INTO `creature_loot_template` VALUES ('49654', '1', '100', '1', '0', '-58055', '2');
UPDATE `creature_template` SET lootid='49654' WHERE entry='49654';
DELETE FROM `reference_loot_template` WHERE `entry`='58055';
INSERT INTO `reference_loot_template` VALUES ('58055', '56339', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58055', '56341', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58055', '56340', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58055', '56338', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58055', '56342', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='42333';
INSERT INTO `creature_loot_template` VALUES ('42333', '1', '100', '1', '0', '-58056', '2');
UPDATE `creature_template` SET lootid='42333' WHERE entry='42333';
DELETE FROM `reference_loot_template` WHERE `entry`='58056';
INSERT INTO `reference_loot_template` VALUES ('58056', '55815', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58056', '55814', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58056', '55820', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58056', '55817', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58056', '55819', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58056', '55813', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58056', '55812', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58056', '55816', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58056', '55818', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58056', '21524', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58056', '22206', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='49624';
INSERT INTO `creature_loot_template` VALUES ('49624', '1', '100', '1', '0', '-58057', '2');
UPDATE `creature_template` SET lootid='49624' WHERE entry='49624';
DELETE FROM `reference_loot_template` WHERE `entry`='58057';
INSERT INTO `reference_loot_template` VALUES ('58057', '51078', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '56351', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '56352', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '56343', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '56346', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '56344', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '56347', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '56345', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '56349', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '56348', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '21524', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58057', '22206', '0', '1', '1', '1', '1');