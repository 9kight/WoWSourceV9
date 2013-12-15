-- 52155 High Priest Venoxis
-- 52151 Bloodlord Mandokir
-- 52271, 52269, 52286, 52258 Edge of Madness
-- 52059 High Priestess Kilnara
-- 52053 Zanzil
-- 52148 Jin'do the Godbreaker

DELETE FROM `creature_loot_template` WHERE `entry`='52155';
INSERT INTO `creature_loot_template` VALUES ('52155', '1', '100', '1', '0', '-58084', '2');
UPDATE `creature_template` SET lootid='52155' WHERE entry='52155';
DELETE FROM `reference_loot_template` WHERE `entry`='58084';
INSERT INTO `reference_loot_template` VALUES ('58084', '69601', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58084', '69602', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58084', '69600', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58084', '69603', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58084', '69604', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='52151';
INSERT INTO `creature_loot_template` VALUES ('52151', '1', '100', '1', '0', '-58085', '2');
UPDATE `creature_template` SET lootid='52151' WHERE entry='52151';
DELETE FROM `reference_loot_template` WHERE `entry`='58085';
INSERT INTO `reference_loot_template` VALUES ('58085', '69606', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58085', '69605', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58085', '69609', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58085', '69608', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58085', '69607', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58085', '68823', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='52271';
INSERT INTO `creature_loot_template` VALUES ('52271', '1', '100', '1', '0', '-58086', '1');
UPDATE `creature_template` SET lootid='52271' WHERE entry='52271';
DELETE FROM `reference_loot_template` WHERE `entry`='58086';
INSERT INTO `reference_loot_template` VALUES ('58086', '69636', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58086', '69637', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58086', '69633', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58086', '69630', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58086', '69632', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58086', '69631', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='69647' WHERE entry='52271';

DELETE FROM `creature_loot_template` WHERE `entry`='52059';
INSERT INTO `creature_loot_template` VALUES ('52059', '1', '100', '1', '0', '-58087', '2');
UPDATE `creature_template` SET lootid='52059' WHERE entry='52059';
DELETE FROM `reference_loot_template` WHERE `entry`='58087';
INSERT INTO `reference_loot_template` VALUES ('58087', '69612', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58087', '69611', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58087', '69610', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58087', '69613', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58087', '69614', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58087', '68824', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='52053';
INSERT INTO `creature_loot_template` VALUES ('52053', '1', '100', '1', '0', '-58088', '2');
UPDATE `creature_template` SET lootid='52053' WHERE entry='52053';
DELETE FROM `reference_loot_template` WHERE `entry`='58088';
INSERT INTO `reference_loot_template` VALUES ('58088', '69615', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58088', '69618', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58088', '69619', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58088', '69617', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58088', '69616', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='52148';
INSERT INTO `creature_loot_template` VALUES ('52148', '1', '100', '1', '0', '-58089', '2');
UPDATE `creature_template` SET lootid='52148' WHERE entry='52148';
DELETE FROM `reference_loot_template` WHERE `entry`='58089';
INSERT INTO `reference_loot_template` VALUES ('58089', '52078', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58089', '69628', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58089', '69624', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58089', '69626', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58089', '69620', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58089', '69621', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58089', '69625', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58089', '69629', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58089', '69627', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58089', '69622', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58089', '69623', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='69774' WHERE entry='52148';

DELETE FROM `creature_loot_template` WHERE `entry`='52269';
INSERT INTO `creature_loot_template` VALUES ('52269', '1', '100', '1', '0', '-58090', '1');
UPDATE `creature_template` SET lootid='52269' WHERE entry='52269';
DELETE FROM `reference_loot_template` WHERE `entry`='58090';
INSERT INTO `reference_loot_template` VALUES ('58090', '69639', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58090', '69638', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58090', '69630', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58090', '69633', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58090', '69632', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58090', '69631', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='69647' WHERE entry='52269';

DELETE FROM `creature_loot_template` WHERE `entry`='52286';
INSERT INTO `creature_loot_template` VALUES ('52286', '1', '100', '1', '0', '-58091', '1');
UPDATE `creature_template` SET lootid='52286' WHERE entry='52286';
DELETE FROM `reference_loot_template` WHERE `entry`='58091';
INSERT INTO `reference_loot_template` VALUES ('58091', '69640', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58091', '69641', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58091', '69633', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58091', '69630', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58091', '69632', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58091', '69631', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='69647' WHERE entry='52286';

DELETE FROM `creature_loot_template` WHERE `entry`='52258';
INSERT INTO `creature_loot_template` VALUES ('52258', '1', '100', '1', '0', '-58092', '1');
UPDATE `creature_template` SET lootid='52258' WHERE entry='52258';
DELETE FROM `reference_loot_template` WHERE `entry`='58092';
INSERT INTO `reference_loot_template` VALUES ('58092', '69634', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58092', '69635', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58092', '69630', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58092', '69633', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58092', '69632', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58092', '69631', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='69647' WHERE entry='52258';