
UPDATE `creature_template` SET spell1='21968', spell2='12747', spell3='21793', spell4='21807' WHERE entry='12225';

UPDATE `creature_template` SET spell1='18670', spell2='21808', spell3='5568' WHERE entry='12203';

UPDATE `creature_template` SET spell1='21655', spell2='21390', spell3='16100', spell4='7964' WHERE entry='12236';
DELETE FROM `pickpocketing_loot_template` WHERE entry='12236';
INSERT INTO `pickpocketing_loot_template` VALUES ('12236', '5430', '33.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('12236', '16884', '28.4', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('12236', '4599', '19.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('12236', '3928', '9.88', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('12236', '7910', '1.23', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='12236' WHERE entry='12236';

UPDATE `creature_template` SET spell1='13446', spell2='15593' WHERE entry='12237';

UPDATE `creature_template` SET spell1='21707', spell2='21687', spell3='10966' WHERE entry='13282';

UPDATE `creature_template` SET spell1='21832', spell2='21909', spell3='22592', spell4='21869', spell5='3391' WHERE entry='12201';

UPDATE `creature_template` SET spell1='40504', spell2='15976' WHERE entry='12258';

UPDATE `creature_template` SET spell1='16495', spell2='15976' WHERE entry='13596';
DELETE FROM `skinning_loot_template` WHERE entry='13596';
INSERT INTO `skinning_loot_template` VALUES ('13596', '4304', '60.66', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('13596', '8170', '22.51', '1', '0', '1', '3');
INSERT INTO `skinning_loot_template` VALUES ('13596', '8169', '6.04', '1', '0', '1', '4');
UPDATE `creature_template` SET skinloot='13596' WHERE entry='13596';

UPDATE `creature_template` SET spell1='9143', spell2='29419', spell3='21833', spell4='16100' WHERE entry='13601';
DELETE FROM `pickpocketing_loot_template` WHERE entry='13601';
INSERT INTO `pickpocketing_loot_template` VALUES ('13601', '5428', '0.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('13601', '16884', '0.48', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('13601', '3928', '0.38', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='13601' WHERE entry='13601';

UPDATE `creature_template` SET spell1='21749' WHERE entry='12219';

UPDATE `creature_template` SET spell1='11428' WHERE entry='12223';

UPDATE `creature_template` SET spell1='16790', spell2='7948' WHERE entry='12224';

UPDATE `creature_template` SET spell1='17201', spell2='7992', spell3='16000' WHERE entry='11793';
DELETE FROM `pickpocketing_loot_template` WHERE entry='11793';
INSERT INTO `pickpocketing_loot_template` VALUES ('11793', '5432', '0.83', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11793', '16884', '0.66', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11793', '3927', '0.61', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11793', '4602', '0.53', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='11793' WHERE entry='11793';

UPDATE `creature_template` SET spell1='11922' WHERE entry='12220';

UPDATE `creature_template` SET spell1='21068', spell2='5413' WHERE entry='12217';

DELETE FROM `pickpocketing_loot_template` WHERE entry='12222';
INSERT INTO `pickpocketing_loot_template` VALUES ('12222', '3419', '47.37', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('12222', '4608', '36.84', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('12222', '16884', '36.84', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('12222', '3928', '15.79', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('12222', '7909', '5.26', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='12222' WHERE entry='12222';

DELETE FROM `creature_loot_template` WHERE entry='11789';
INSERT INTO `creature_loot_template` VALUES ('11789', '3669', '53.49', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('11789', '3676', '53.29', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='11789' WHERE entry='11789';

UPDATE `creature_template` SET spell1='13446', spell2='11876' WHERE entry='13141';

UPDATE `creature_template` SET spell1='21331', spell2='21337' WHERE entry='13142';

UPDATE `creature_template` SET spell1='21070' WHERE entry='12221';
DELETE FROM `pickpocketing_loot_template` WHERE entry='12221';
INSERT INTO `pickpocketing_loot_template` VALUES ('12221', '3419', '0.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('12221', '4608', '0.19', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='12221' WHERE entry='12221';

UPDATE `creature_template` SET spell1='21067' WHERE entry='12216';

UPDATE `creature_template` SET spell1='21071', spell2='5568' WHERE entry='12206';

UPDATE `creature_template` SET spell1='12540', spell2='21062', spell3='15667' WHERE entry='11790';
DELETE FROM `pickpocketing_loot_template` WHERE entry='11790';
INSERT INTO `pickpocketing_loot_template` VALUES ('11790', '5430', '1.96', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11790', '16884', '1.91', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11790', '4599', '1.8', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11790', '3928', '0.36', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='11790' WHERE entry='11790';

UPDATE `creature_template` SET spell1='15087', spell2='9080', spell3='21062', spell4='22766' WHERE entry='11792';
DELETE FROM `pickpocketing_loot_template` WHERE entry='11792';
INSERT INTO `pickpocketing_loot_template` VALUES ('11792', '4599', '1.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11792', '16884', '1.94', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11792', '5430', '1.68', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11792', '3928', '0.53', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='11792' WHERE entry='11792';

UPDATE `creature_template` SET spell1='15657', spell2='13298', spell3='21062', spell4='3391' WHERE entry='11791';
DELETE FROM `pickpocketing_loot_template` WHERE entry='11791';
INSERT INTO `pickpocketing_loot_template` VALUES ('11791', '5430', '2.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11791', '16884', '2.48', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11791', '4599', '1.39', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11791', '3928', '0.33', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='11791' WHERE entry='11791';

UPDATE `creature_template` SET spell1='14516', spell2='15795' WHERE entry='11794';
DELETE FROM `pickpocketing_loot_template` WHERE entry='11794';
INSERT INTO `pickpocketing_loot_template` VALUES ('11794', '4602', '0.5', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11794', '5432', '0.44', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11794', '16884', '0.29', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='11794' WHERE entry='11794';

UPDATE `creature_template` SET spell1='5413' WHERE entry='13533';

DELETE FROM `creature_loot_template` WHERE entry='12240';
INSERT INTO `creature_loot_template` VALUES ('12240', '17761', '96.26', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12240', '17684', '24.3', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12240', '4338', '22.43', '1', '0', '1', '4');
INSERT INTO `creature_loot_template` VALUES ('12240', '4306', '10.28', '1', '0', '1', '4');
INSERT INTO `creature_loot_template` VALUES ('12240', '4599', '5.61', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12240', '1645', '4.67', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12240', '8750', '0.93', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='12240' WHERE entry='12240';

DELETE FROM `creature_loot_template` WHERE entry='12242';
INSERT INTO `creature_loot_template` VALUES ('12242', '17764', '100', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12242', '4338', '38.46', '1', '0', '1', '4');
INSERT INTO `creature_loot_template` VALUES ('12242', '1645', '2.88', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12242', '3928', '2.88', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12242', '4019', '1.92', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='12242' WHERE entry='12242';

DELETE FROM `creature_loot_template` WHERE entry='12243';
INSERT INTO `creature_loot_template` VALUES ('12243', '17765', '98.18', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12243', '4338', '26.36', '1', '0', '1', '4');
INSERT INTO `creature_loot_template` VALUES ('12243', '17684', '6.36', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12243', '4018', '1.82', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12243', '4017', '1.82', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('12243', '4021', '1.82', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='12243' WHERE entry='12243';

DELETE FROM `creature_loot_template` WHERE entry='13599';
INSERT INTO `creature_loot_template` VALUES ('13599', '4555', '57.5', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('13599', '4556', '56.13', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('13599', '3712', '36.97', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('13599', '7973', '33.55', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('13599', '4603', '8.9', '1', '0', '1', '2');
UPDATE `creature_template` SET lootid='13599' WHERE entry='13599';
DELETE FROM `skinning_loot_template` WHERE entry='13599';
INSERT INTO `skinning_loot_template` VALUES ('13599', '4304', '67.32', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('13599', '8167', '44.28', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('13599', '8170', '19.36', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('13599', '8169', '2.41', '1', '0', '1', '6');
UPDATE `creature_template` SET skinloot='13599' WHERE entry='13599';

UPDATE `creature_template` SET spell1='8281' WHERE entry='13323';
DELETE FROM `skinning_loot_template` WHERE entry='13323';
INSERT INTO `skinning_loot_template` VALUES ('13323', '4304', '62.44', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('13323', '8170', '22.62', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('13323', '8169', '4.52', '1', '0', '1', '6');
UPDATE `creature_template` SET skinloot='13323' WHERE entry='13323';

UPDATE `creature_template` SET spell1='16790', spell2='21057' WHERE entry='11784';

UPDATE `creature_template` SET spell1='13584' WHERE entry='11783';

UPDATE `creature_template` SET spell1='21790', spell2='21787', spell3='3391' WHERE entry='12207';
DELETE FROM `skinning_loot_template` WHERE entry='12207';
INSERT INTO `skinning_loot_template` VALUES ('12207', '4304', '62.26', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('12207', '8170', '22.56', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('12207', '8169', '4.34', '1', '0', '1', '5');
UPDATE `creature_template` SET skinloot='12207' WHERE entry='12207';

UPDATE `creature_template` SET spell1='21069', spell2='744' WHERE entry='12218';
