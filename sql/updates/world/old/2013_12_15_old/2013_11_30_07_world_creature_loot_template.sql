-- 39425, 49262 Temple Guardian Anhuur
-- 39428, 48714 Earthrager Ptah
-- 39788, 48902 Anraphet
-- 39587, 48710 Isiset
-- 39731, 48715 Ammunae
-- 39732, 48776 Setesh
-- 39378, 48815 Rajh

DELETE FROM `creature_loot_template` WHERE `entry`='39425';
INSERT INTO `creature_loot_template` VALUES ('39425', '1', '100', '1', '0', '-58023', '2');
UPDATE `creature_template` SET lootid='39425' WHERE entry='39425';
DELETE FROM `reference_loot_template` WHERE `entry`='58023';
INSERT INTO `reference_loot_template` VALUES ('58023', '55889', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58023', '55888', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58023', '55886', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58023', '55887', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58023', '55890', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58023', '71637', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='49262';
INSERT INTO `creature_loot_template` VALUES ('49262', '1', '100', '1', '0', '-58024', '2');
UPDATE `creature_template` SET lootid='49262' WHERE entry='49262';
DELETE FROM `reference_loot_template` WHERE `entry`='58024';
INSERT INTO `reference_loot_template` VALUES ('58024', '56407', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58024', '56410', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58024', '56411', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58024', '56409', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58024', '56408', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='39428';
INSERT INTO `creature_loot_template` VALUES ('39428', '1', '100', '1', '0', '-58025', '2');
UPDATE `creature_template` SET lootid='39428' WHERE entry='39428';
DELETE FROM `reference_loot_template` WHERE `entry`='58025';
INSERT INTO `reference_loot_template` VALUES ('58025', '56097', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58025', '56095', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58025', '56093', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58025', '56096', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58025', '56094', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48714';
INSERT INTO `creature_loot_template` VALUES ('48714', '1', '100', '1', '0', '-58026', '2');
UPDATE `creature_template` SET lootid='48714' WHERE entry='48714';
DELETE FROM `reference_loot_template` WHERE `entry`='58026';
INSERT INTO `reference_loot_template` VALUES ('58026', '56425', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58026', '56424', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58026', '56423', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58026', '56426', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58026', '56422', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='39788';
INSERT INTO `creature_loot_template` VALUES ('39788', '1', '100', '1', '0', '-58027', '2');
UPDATE `creature_template` SET lootid='39788' WHERE entry='39788';
DELETE FROM `reference_loot_template` WHERE `entry`='58027';
INSERT INTO `reference_loot_template` VALUES ('58027', '57855', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58027', '57857', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58027', '57860', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58027', '57858', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58027', '57856', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48902';
INSERT INTO `creature_loot_template` VALUES ('48902', '1', '100', '1', '0', '-58028', '2');
UPDATE `creature_template` SET lootid='48902' WHERE entry='48902';
DELETE FROM `reference_loot_template` WHERE `entry`='58028';
INSERT INTO `reference_loot_template` VALUES ('58028', '57870', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58028', '57868', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58028', '57867', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58028', '57866', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58028', '57869', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='39587';
INSERT INTO `creature_loot_template` VALUES ('39587', '1', '100', '1', '0', '-58029', '2');
UPDATE `creature_template` SET lootid='39587' WHERE entry='39587';
DELETE FROM `reference_loot_template` WHERE `entry`='58029';
INSERT INTO `reference_loot_template` VALUES ('58029', '55994', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58029', '55996', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58029', '55995', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58029', '55993', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58029', '55992', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48710';
INSERT INTO `creature_loot_template` VALUES ('48710', '1', '100', '1', '0', '-58030', '2');
UPDATE `creature_template` SET lootid='48710' WHERE entry='48710';
DELETE FROM `reference_loot_template` WHERE `entry`='58030';
INSERT INTO `reference_loot_template` VALUES ('58030', '56414', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58030', '56416', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58030', '56413', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58030', '56415', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58030', '56412', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='39731';
INSERT INTO `creature_loot_template` VALUES ('39731', '1', '100', '1', '0', '-58031', '2');
UPDATE `creature_template` SET lootid='39731' WHERE entry='39731';
DELETE FROM `reference_loot_template` WHERE `entry`='58031';
INSERT INTO `reference_loot_template` VALUES ('58031', '56000', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58031', '55997', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58031', '55998', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58031', '55999', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48715';
INSERT INTO `creature_loot_template` VALUES ('48715', '1', '100', '1', '0', '-58032', '2');
UPDATE `creature_template` SET lootid='48715' WHERE entry='48715';
DELETE FROM `reference_loot_template` WHERE `entry`='58032';
INSERT INTO `reference_loot_template` VALUES ('58032', '56418', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58032', '56419', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58032', '56417', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58032', '56421', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='39732';
INSERT INTO `creature_loot_template` VALUES ('39732', '1', '100', '1', '0', '-58033', '2');
UPDATE `creature_template` SET lootid='39732' WHERE entry='39732';
DELETE FROM `reference_loot_template` WHERE `entry`='58033';
INSERT INTO `reference_loot_template` VALUES ('58033', '57865', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58033', '57864', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58033', '57863', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58033', '57862', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58033', '57861', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58033', '71635', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48776';
INSERT INTO `creature_loot_template` VALUES ('48776', '1', '100', '1', '0', '-58034', '2');
UPDATE `creature_template` SET lootid='48776' WHERE entry='48776';
DELETE FROM `reference_loot_template` WHERE `entry`='58034';
INSERT INTO `reference_loot_template` VALUES ('58034', '57875', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58034', '57873', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58034', '57871', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58034', '57874', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58034', '57872', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='39378';
INSERT INTO `creature_loot_template` VALUES ('39378', '1', '100', '1', '0', '-58035', '2');
UPDATE `creature_template` SET lootid='39378' WHERE entry='39378';
DELETE FROM `reference_loot_template` WHERE `entry`='58035';
INSERT INTO `reference_loot_template` VALUES ('58035', '56108', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58035', '56100', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58035', '56106', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58035', '56102', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58035', '56107', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58035', '56098', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58035', '56101', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58035', '56099', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58035', '56105', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58035', '56104', '0', '1', '1', '1', '1');

DELETE FROM `creature_loot_template` WHERE `entry`='48815';
INSERT INTO `creature_loot_template` VALUES ('48815', '1', '100', '1', '0', '-58036', '2');
UPDATE `creature_template` SET lootid='48815' WHERE entry='48815';
DELETE FROM `reference_loot_template` WHERE `entry`='58036';
INSERT INTO `reference_loot_template` VALUES ('58036', '52078', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '56433', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '56428', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '56436', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '56435', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '56429', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '56431', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '56434', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '56430', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '56432', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '56427', '0', '1', '1', '1', '1');
INSERT INTO `reference_loot_template` VALUES ('58036', '71715', '0', '1', '1', '1', '1');