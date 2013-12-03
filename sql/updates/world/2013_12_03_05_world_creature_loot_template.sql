-- 43878, 43879 Grand Vizier Ertan
-- 43873, 43874 Altairus
-- 43875, 43876 Asaad

DELETE FROM `creature_loot_template` WHERE `entry`='43878';
INSERT INTO `creature_loot_template` VALUES ('43878', '1', '100', '1', '0', '-58058', '2');
UPDATE `creature_template` SET lootid='43878' WHERE entry='43878';
DELETE FROM `reference_loot_template` WHERE `entry`='58058';
INSERT INTO `reference_loot_template` VALUES ('58058', '65660', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58058', '55834', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58058', '55833', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58058', '55830', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58058', '55831', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58058', '55832', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='43879';
INSERT INTO `creature_loot_template` VALUES ('43879', '1', '100', '1', '0', '-58059', '2');
UPDATE `creature_template` SET lootid='43879' WHERE entry='43879';
DELETE FROM `reference_loot_template` WHERE `entry`='58059';
INSERT INTO `reference_loot_template` VALUES ('58059', '56357', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58059', '56358', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58059', '56360', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58059', '56359', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58059', '56356', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58059', '65660', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71715' WHERE entry='43879';

DELETE FROM `creature_loot_template` WHERE `entry`='43873';
INSERT INTO `creature_loot_template` VALUES ('43873', '1', '100', '1', '0', '-58060', '2');
UPDATE `creature_template` SET lootid='43873' WHERE entry='43873';
DELETE FROM `reference_loot_template` WHERE `entry`='58060';
INSERT INTO `reference_loot_template` VALUES ('58060', '55841', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58060', '55839', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58060', '55840', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58060', '55835', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58060', '55838', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58060', '63040', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='43874';
INSERT INTO `creature_loot_template` VALUES ('43874', '1', '100', '1', '0', '-58061', '2');
UPDATE `creature_template` SET lootid='43874' WHERE entry='43874';
DELETE FROM `reference_loot_template` WHERE `entry`='58061';
INSERT INTO `reference_loot_template` VALUES ('58061', '56362', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58061', '56364', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58061', '56363', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58061', '56361', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58061', '56365', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58061', '63040', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='43875';
INSERT INTO `creature_loot_template` VALUES ('43875', '1', '100', '1', '0', '-58062', '2');
UPDATE `creature_template` SET lootid='43875' WHERE entry='43875';
DELETE FROM `reference_loot_template` WHERE `entry`='58062';
INSERT INTO `reference_loot_template` VALUES ('58062', '55850', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58062', '55846', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58062', '55851', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58062', '55847', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58062', '55844', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58062', '55845', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58062', '55842', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58062', '55849', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58062', '55848', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58062', '55853', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71635' WHERE entry='43875';

DELETE FROM `creature_loot_template` WHERE `entry`='43876';
INSERT INTO `creature_loot_template` VALUES ('43876', '1', '100', '1', '0', '-58063', '2');
UPDATE `creature_template` SET lootid='43876' WHERE entry='43876';
DELETE FROM `reference_loot_template` WHERE `entry`='58063';
INSERT INTO `reference_loot_template` VALUES ('58063', '52078', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58063', '56374', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58063', '56373', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58063', '56371', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58063', '56375', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58063', '56369', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58063', '56368', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58063', '56370', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58063', '56367', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58063', '56366', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58063', '56376', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='52506' WHERE entry='43876';