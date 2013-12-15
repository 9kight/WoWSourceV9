-- 40586, 49079 Lady Naz'jar
-- 40765, 49064 Commander Ulthok
-- 40825, 49072 Erunak Stonespeaker
-- 40788, 49082 Mindbender Ghur'sha
-- 44566, 49097 Ozumat

Update `creature_template` set `difficulty_entry_1`=49082 where `entry`=40788;
Update `creature_template` set `difficulty_entry_1`=49097 where `entry`=44566;

DELETE FROM `creature_loot_template` WHERE `entry`='40586';
INSERT INTO `creature_loot_template` VALUES ('40586', '1', '100', '1', '0', '-58076', '2');
UPDATE `creature_template` SET lootid='40586' WHERE entry='40586';
DELETE FROM `reference_loot_template` WHERE `entry`='58076';
INSERT INTO `reference_loot_template` VALUES ('58076', '55202', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58076', '55195', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58076', '55203', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58076', '55198', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58076', '55201', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71636' WHERE entry='40586';

DELETE FROM `creature_loot_template` WHERE `entry`='49079';
INSERT INTO `creature_loot_template` VALUES ('49079', '1', '100', '1', '0', '-58077', '2');
UPDATE `creature_template` SET lootid='49079' WHERE entry='49079';
DELETE FROM `reference_loot_template` WHERE `entry`='58077';
INSERT INTO `reference_loot_template` VALUES ('58077', '56269', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58077', '56270', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58077', '56266', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58077', '56267', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58077', '56268', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='40765';
INSERT INTO `creature_loot_template` VALUES ('40765', '1', '100', '1', '0', '-58078', '2');
UPDATE `creature_template` SET lootid='40765' WHERE entry='40765';
DELETE FROM `reference_loot_template` WHERE `entry`='58078';
INSERT INTO `reference_loot_template` VALUES ('58078', '55228', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58078', '55204', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58078', '55206', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58078', '55205', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58078', '55207', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='49064';
INSERT INTO `creature_loot_template` VALUES ('49064', '1', '100', '1', '0', '-58079', '2');
UPDATE `creature_template` SET lootid='49064' WHERE entry='49064';
DELETE FROM `reference_loot_template` WHERE `entry`='58079';
INSERT INTO `reference_loot_template` VALUES ('58079', '56273', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58079', '56271', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58079', '56274', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58079', '56275', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58079', '56272', '0', '1', '1', '1', '1');
UPDATE `creature_template` SET questItem1='71715' WHERE entry='49064';

DELETE FROM `creature_loot_template` WHERE `entry`='40788';
INSERT INTO `creature_loot_template` VALUES ('40788', '1', '100', '1', '0', '-58080', '2');
UPDATE `creature_template` SET lootid='40788' WHERE entry='40788';
DELETE FROM `reference_loot_template` WHERE `entry`='58080';
INSERT INTO `reference_loot_template` VALUES ('58080', '55236', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58080', '55229', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58080', '55237', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58080', '55235', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='49082';
INSERT INTO `creature_loot_template` VALUES ('49082', '1', '100', '1', '0', '-58081', '2');
UPDATE `creature_template` SET lootid='49082' WHERE entry='49082';
DELETE FROM `reference_loot_template` WHERE `entry`='58081';
INSERT INTO `reference_loot_template` VALUES ('58081', '56278', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58081', '56276', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58081', '56277', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58081', '56280', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='44566';
INSERT INTO `creature_loot_template` VALUES ('44566', '1', '100', '1', '0', '-58082', '2');
UPDATE `creature_template` SET lootid='44566' WHERE entry='44566';
DELETE FROM `reference_loot_template` WHERE `entry`='58082';
INSERT INTO `reference_loot_template` VALUES ('58082', '55252', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58082', '55258', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58082', '55251', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58082', '55259', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58082', '55250', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58082', '55256', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58082', '55255', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58082', '55253', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58082', '55254', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58082', '55249', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='49097';
INSERT INTO `creature_loot_template` VALUES ('49097', '1', '100', '1', '0', '-58083', '2');
UPDATE `creature_template` SET lootid='49097' WHERE entry='49097';
DELETE FROM `reference_loot_template` WHERE `entry`='58083';
INSERT INTO `reference_loot_template` VALUES ('58083', '52289', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58083', '56285', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58083', '56277', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58083', '56288', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58083', '56290', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58083', '56284', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58083', '56282', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58083', '56283', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58083', '56281', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58083', '56291', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58083', '56286', '0', '1', '1', '1', '1');

