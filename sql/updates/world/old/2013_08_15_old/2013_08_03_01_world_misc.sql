-- add  missing brill mobs http://www.wowhead.com/npc=38967 from quest http://www.wowhead.com/quest=24993
-- also fix hes equipment and movement , ability and pickpockething...
DELETE FROM creature WHERE guid IN (320864,320865,320866,320867,320868,320869,320870,320871,320872,320873,320874,320875);
INSERT INTO `creature` VALUES ('320864', '38967', '0', '85', '159', '1', '1', '0', '0', '2240.42', '293.576', '33.5748', '1.22377', '300', '0', '0', '156', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320865', '38967', '0', '85', '159', '1', '1', '0', '0', '2223.76', '283.85', '33.6463', '1.92124', '300', '0', '0', '137', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320866', '38967', '0', '85', '159', '1', '1', '0', '0', '2227.88', '261.168', '33.3994', '3.00509', '300', '0', '0', '137', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320867', '38967', '0', '85', '159', '1', '1', '0', '0', '2285.66', '235.206', '33.6909', '5.18283', '300', '0', '0', '137', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320868', '38967', '0', '85', '159', '1', '1', '0', '0', '2273.73', '255.28', '33.6891', '5.11759', '300', '0', '0', '137', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320869', '38967', '0', '85', '159', '1', '1', '0', '0', '2252.07', '254.926', '33.4855', '0.154096', '300', '0', '0', '156', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320870', '38967', '0', '85', '159', '1', '1', '0', '0', '2247.29', '270.481', '33.4582', '5.02728', '300', '0', '0', '137', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320871', '38967', '0', '85', '159', '1', '1', '0', '0', '2294.17', '339.917', '33.7506', '1.02305', '300', '0', '0', '137', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320872', '38967', '0', '85', '159', '1', '1', '0', '0', '2271.21', '331.981', '33.5737', '1.10334', '300', '0', '0', '156', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320873', '38967', '0', '85', '159', '1', '1', '0', '0', '2277.34', '312.701', '33.6618', '1.60512', '300', '0', '0', '156', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320874', '38967', '0', '85', '159', '1', '1', '0', '0', '2267.03', '292.963', '33.6908', '0.902624', '300', '0', '0', '137', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320875', '38967', '0', '85', '159', '1', '1', '0', '0', '2254.13', '297.438', '33.6888', '0.45102', '300', '0', '0', '156', '0', '0', '0', '0', '0');
UPDATE creature SET MovementType=1 WHERE guid IN (320864,320865,320866,320867,320868,320869,320870,320871,320872,320873,320874,320875);
UPDATE creature SET spawndist=1 WHERE guid IN (320864,320865,320866,320867,320868,320869,320870,320871,320872,320873,320874,320875);
UPDATE `creature_template` SET `MovementType`='1' WHERE `entry`='38967';
UPDATE `creature_template` SET `equipment_id`='38967' WHERE `entry`='38967';
DELETE FROM creature_equip_template WHERE entry=38967;
INSERT INTO `creature_equip_template` VALUES ('38967', '1', '0', '7947', '0');
UPDATE `creature_template` SET spell1='32615' WHERE entry='38967';
UPDATE creature_template SET pickpocketloot=38967 WHERE entry=38967;
DELETE FROM `pickpocketing_loot_template` WHERE entry='38967';
INSERT INTO `pickpocketing_loot_template` VALUES ('38967', '6150', '1.26', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('38967', '5363', '0.98', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('38967', '4540', '0.66', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('38967', '2070', '0.47', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('38967', '4536', '0.42', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('38967', '118', '0.23', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('38967', '774', '0.19', '1', '0', '1', '1');

-- fix startup errors from console 
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='70008';
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='44245';
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='44380';
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='47242';
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='48446';
DELETE FROM creature_equip_template WHERE entry=25729;
INSERT INTO `creature_equip_template` VALUES ('25729', '1', '33428', '7947', '0');
DELETE FROM creature WHERE guid=31306;
DELETE FROM creature_equip_template WHERE entry=31306;
INSERT INTO `creature_equip_template` VALUES ('31306', '1', '0', '50672', '0');
INSERT INTO `creature` VALUES ('320876', '31306', '571', '210', '4531', '1', '1', '0', '31306', '6887.21', '3532.57', '709.379', '5.77258', '300', '0', '0', '37800', '11982', '0', '0', '0', '0');
