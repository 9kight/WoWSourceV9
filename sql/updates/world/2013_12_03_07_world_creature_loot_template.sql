-- 55085 Peroth'arn
-- 54853 Queen Azshara
-- 54969 Mannoroth
-- 55419 Captain Varo'then

DELETE FROM `creature_loot_template` WHERE `entry`='55085';
INSERT INTO `creature_loot_template` VALUES ('55085', '1', '100', '1', '0', '-58070', '2');
UPDATE `creature_template` SET lootid='55085' WHERE entry='55085';
DELETE FROM `reference_loot_template` WHERE `entry`='58070';
INSERT INTO `reference_loot_template` VALUES ('58070', '72831', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58070', '72832', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58070', '72830', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58070', '72828', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58070', '72827', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58070', '72829', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='54853';
INSERT INTO `creature_loot_template` VALUES ('54853', '1', '100', '1', '0', '-58071', '2');
UPDATE `creature_template` SET lootid='54853' WHERE entry='54853';
DELETE FROM `reference_loot_template` WHERE `entry`='58071';
INSERT INTO `reference_loot_template` VALUES ('58071', '72833', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58071', '72838', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58071', '72835', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58071', '72834', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58071', '72836', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58071', '72837', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58071', '22206', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71635' WHERE entry='54853';

DELETE FROM `creature_loot_template` WHERE `entry`='54969';
INSERT INTO `creature_loot_template` VALUES ('54969', '1', '100', '1', '0', '-58072', '2');
UPDATE `creature_template` SET lootid='54969' WHERE entry='54969';
DELETE FROM `reference_loot_template` WHERE `entry`='58072';
INSERT INTO `reference_loot_template` VALUES ('58072', '72842', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72839', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72841', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72898', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72843', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72847', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72848', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72845', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72844', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72840', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72846', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '72899', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58072', '52078', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71715' WHERE entry='54969';
UPDATE `creature_template` SET questItem2='71638' WHERE entry='54969';

DELETE FROM `creature_loot_template` WHERE `entry`='55419';
INSERT INTO `creature_loot_template` VALUES ('55419', '1', '100', '1', '0', '-58073', '2');
UPDATE `creature_template` SET lootid='55419' WHERE entry='55419';
DELETE FROM `reference_loot_template` WHERE `entry`='58073';
INSERT INTO `reference_loot_template` VALUES ('58073', '52078', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72898', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72844', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72839', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72845', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72841', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72847', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72848', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72846', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72899', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72842', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72843', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58073', '72840', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71715' WHERE entry='55419';
UPDATE `creature_template` SET questItem2='71638' WHERE entry='55419';