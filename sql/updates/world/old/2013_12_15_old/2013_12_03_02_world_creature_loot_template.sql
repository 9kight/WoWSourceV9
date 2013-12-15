-- 44577, 48932 General Husam
-- 43612, 48951 High Prophet Barim
-- 43614, 49043 Lockmaw
-- 49045, 48104 Augh
-- 44819, 51088 Siamat

DELETE FROM `creature_loot_template` WHERE `entry`='44577';
INSERT INTO `creature_loot_template` VALUES ('44577', '1', '100', '1', '0', '-58040', '2');
UPDATE `creature_template` SET lootid='44577' WHERE entry='44577';
DELETE FROM `reference_loot_template` WHERE `entry`='58040';
INSERT INTO `reference_loot_template` VALUES ('58040', '55860', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58040', '55859', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58040', '55858', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58040', '55856', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58040', '55857', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71638' WHERE entry='58040';

DELETE FROM `creature_loot_template` WHERE `entry`='48932';
INSERT INTO `creature_loot_template` VALUES ('48932', '1', '100', '1', '0', '-58041', '2');
UPDATE `creature_template` SET lootid='48932' WHERE entry='48932';
DELETE FROM `reference_loot_template` WHERE `entry`='58041';
INSERT INTO `reference_loot_template` VALUES ('58041', '56380', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58041', '56381', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58041', '56383', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58041', '56379', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58041', '56382', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='43612';
INSERT INTO `creature_loot_template` VALUES ('43612', '1', '100', '1', '0', '-58042', '2');
UPDATE `creature_template` SET lootid='43612' WHERE entry='43612';
DELETE FROM `reference_loot_template` WHERE `entry`='58042';
INSERT INTO `reference_loot_template` VALUES ('58042', '55864', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58042', '55861', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58042', '55863', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58042', '55865', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58042', '55862', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48951';
INSERT INTO `creature_loot_template` VALUES ('48951', '1', '100', '1', '0', '-58043', '2');
UPDATE `creature_template` SET lootid='48951' WHERE entry='48951';
DELETE FROM `reference_loot_template` WHERE `entry`='58043';
INSERT INTO `reference_loot_template` VALUES ('58043', '56385', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58043', '56386', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58043', '56387', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58043', '56384', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58043', '56388', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71715' WHERE entry='48951';

DELETE FROM `creature_loot_template` WHERE `entry`='43614';
INSERT INTO `creature_loot_template` VALUES ('43614', '1', '100', '1', '0', '-58044', '2');
UPDATE `creature_template` SET lootid='43614' WHERE entry='43614';
DELETE FROM `reference_loot_template` WHERE `entry`='58044';
INSERT INTO `reference_loot_template` VALUES ('58044', '55868', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58044', '55870', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58044', '55869', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58044', '55866', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58044', '55867', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71636' WHERE entry='43614';

DELETE FROM `creature_loot_template` WHERE `entry`='49043';
INSERT INTO `creature_loot_template` VALUES ('49043', '1', '100', '1', '0', '-58045', '2');
UPDATE `creature_template` SET lootid='49043' WHERE entry='49043';
DELETE FROM `reference_loot_template` WHERE `entry`='58045';
INSERT INTO `reference_loot_template` VALUES ('58045', '56390', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58045', '56393', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58045', '56392', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58045', '56389', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58045', '56391', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='49045';
INSERT INTO `creature_loot_template` VALUES ('49045', '1', '100', '1', '0', '-58046', '2');
UPDATE `creature_template` SET lootid='49045' WHERE entry='49045';
DELETE FROM `reference_loot_template` WHERE `entry`='58046';
INSERT INTO `reference_loot_template` VALUES ('58046', '55870', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58046', '55868', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58046', '55867', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58046', '55866', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58046', '55869', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48104';
INSERT INTO `creature_loot_template` VALUES ('48104', '1', '100', '1', '0', '-58047', '2');
UPDATE `creature_template` SET lootid='48104' WHERE entry='48104';
DELETE FROM `reference_loot_template` WHERE `entry`='58047';
INSERT INTO `reference_loot_template` VALUES ('58047', '56391', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58047', '56390', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58047', '56393', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58047', '56392', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58047', '56389', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='44819';
INSERT INTO `creature_loot_template` VALUES ('44819', '1', '100', '1', '0', '-58048', '2');
UPDATE `creature_template` SET lootid='44819' WHERE entry='44819';
DELETE FROM `reference_loot_template` WHERE `entry`='58048';
INSERT INTO `reference_loot_template` VALUES ('58048', '55879', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58048', '55874', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58048', '55876', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58048', '55872', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58048', '55875', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58048', '55871', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58048', '55873', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58048', '55878', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58048', '55877', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='51088';
INSERT INTO `creature_loot_template` VALUES ('51088', '1', '100', '1', '0', '-58049', '2');
UPDATE `creature_template` SET lootid='51088' WHERE entry='51088';
DELETE FROM `reference_loot_template` WHERE `entry`='58049';
INSERT INTO `reference_loot_template` VALUES ('58049', '52078', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58049', '56395', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58049', '56397', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58049', '56396', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58049', '56401', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58049', '56398', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58049', '56400', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58049', '56402', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58049', '56403', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58049', '56399', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58049', '56394', '0', '1', '1', '1', '1');