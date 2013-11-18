UPDATE `creature_template` SET spell1='83776', spell2='91415', spell3='84799', spell4='91408' WHERE entry='49045';

UPDATE `creature_template` SET spell1='83113', spell2='91263', spell3='83445' WHERE entry='44577';

UPDATE `creature_template` SET spell1='82506', spell2='88814', spell3='82622', spell4='82320', spell5='81947', spell6='82139' WHERE entry='43612';

UPDATE `creature_template` SET spell1='81642', spell2='81690', spell3='81706', spell4='81630' WHERE entry='43614';

UPDATE `creature_template` SET spell1='83151', spell2='84589', spell3='84982', spell4='91853', spell5='73564', spell6='83089', spell7='83066' WHERE entry='44819';

UPDATE `creature_template` SET spell1='84784' WHERE entry='45378';

UPDATE `creature_template` SET spell1='84768' WHERE entry='45377';

UPDATE `creature_template` SET spell1='84797' WHERE entry='44895';

UPDATE `creature_template` SET spell1='84799', spell2='84768' WHERE entry='45379';

UPDATE `creature_template` SET spell1='95248' WHERE entry='48906';

UPDATE `creature_template` SET spell1='84125' WHERE entry='45063';

DELETE FROM `skinning_loot_template` WHERE entry='47720';
INSERT INTO `skinning_loot_template` VALUES ('47720', '52976', '102.25', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('47720', '67495', '3.22', '1', '0', '1', '1');
UPDATE `creature_template` SET skinloot='47720' WHERE entry='47720';

DELETE FROM `pickpocketing_loot_template` WHERE entry='45007';
INSERT INTO `pickpocketing_loot_template` VALUES ('45007', '63273', '5.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45007', '63349', '5.28', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45007', '63275', '5.23', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45007', '63274', '5.23', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45007', '63272', '2.98', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45007', '58261', '2.51', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45007', '63300', '2.41', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45007', '63271', '2.28', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45007', '58259', '1.78', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45007', '68196', '0.4', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='45007' WHERE entry='45007';

DELETE FROM `pickpocketing_loot_template` WHERE entry='45001';
INSERT INTO `pickpocketing_loot_template` VALUES ('45001', '63274', '4.31', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45001', '63275', '4.2', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45001', '63349', '3.2', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45001', '63273', '3.13', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45001', '63272', '2.07', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45001', '63271', '1.71', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45001', '58261', '1.62', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45001', '58259', '1.58', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45001', '63300', '1.19', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45001', '68196', '0.36', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='45001' WHERE entry='45001';

UPDATE `creature_template` SET spell1='81677' WHERE entry='43658';

UPDATE `creature_template` SET spell1='82255', spell2='82533', spell3='82425' WHERE entry='43927';

UPDATE `creature_template` SET spell1='83455', spell2='84550' WHERE entry='44704';

UPDATE `creature_template` SET spell1='82760', spell2='84032', spell3='82765' WHERE entry='44982';

DELETE FROM `pickpocketing_loot_template` WHERE entry='44982';
INSERT INTO `pickpocketing_loot_template` VALUES ('44982', '63348', '16.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44982', '63349', '14.65', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44982', '63317', '14.19', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44982', '63291', '13.97', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44982', '58269', '11.8', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44982', '63300', '7.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44982', '63310', '6.86', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44982', '63316', '1.37', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44982', '63318', '0.42', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44982' WHERE entry='44982';

UPDATE `creature_template` SET spell1='73976', spell2='82768' WHERE entry='44976';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44976';
INSERT INTO `pickpocketing_loot_template` VALUES ('44976', '63349', '25.78', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44976', '63348', '24.66', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44976', '63291', '23.6', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44976', '63317', '22.57', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44976', '58269', '14.95', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44976', '63310', '12.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44976', '63300', '7.88', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44976', '63316', '1.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44976', '63318', '1.05', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44976' WHERE entry='44976';

UPDATE `creature_template` SET spell1='82759', spell2='82753', spell3='82757' WHERE entry='44980';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44980';
INSERT INTO `pickpocketing_loot_template` VALUES ('44980', '63317', '9.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44980', '63348', '9.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44980', '63291', '9.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44980', '63349', '8.96', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44980', '58269', '7.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44980', '63310', '5.94', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44980', '63300', '3.46', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44980', '63316', '0.49', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44980', '63318', '0.39', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44980' WHERE entry='44980';

UPDATE `creature_template` SET spell1='82744', spell2='82750' WHERE entry='44977';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44977';
INSERT INTO `pickpocketing_loot_template` VALUES ('44977', '63291', '3.34', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44977', '63348', '3.23', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44977', '63317', '3.19', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44977', '63349', '3.06', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44977', '58269', '2.59', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44977', '63310', '1.51', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44977', '63300', '1.18', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44977', '63316', '0.4', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44977', '63318', '0.3', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44977' WHERE entry='44977';

UPDATE `creature_template` SET spell1='84256', spell2='82763' WHERE entry='44922';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44922';
INSERT INTO `pickpocketing_loot_template` VALUES ('44922', '63349', '9.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44922', '63348', '8.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44922', '63317', '8.2', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44922', '63291', '8.1', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44922', '58269', '6.32', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44922', '63310', '4.06', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44922', '63300', '3.06', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44922', '63316', '0.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44922', '63318', '0.3', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44922' WHERE entry='44922';

UPDATE `creature_template` SET spell1='82670' WHERE entry='45122';
DELETE FROM `pickpocketing_loot_template` WHERE entry='45122';
INSERT INTO `pickpocketing_loot_template` VALUES ('45122', '63348', '3.73', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45122', '63349', '3.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45122', '63291', '3.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45122', '63317', '3', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45122', '58269', '2.67', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45122', '63310', '1.98', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45122', '63300', '0.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45122', '63316', '0.46', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='45122' WHERE entry='45122';

UPDATE `creature_template` SET spell1='82671', spell2='82673' WHERE entry='44924';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44924';
INSERT INTO `pickpocketing_loot_template` VALUES ('44924', '63291', '15.36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44924', '63348', '15.05', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44924', '63349', '14.68', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44924', '63317', '13.64', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44924', '58269', '11.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44924', '63310', '7.15', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44924', '63300', '5.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44924', '63316', '1.11', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44924', '63318', '0.54', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44924' WHERE entry='44924';

UPDATE `creature_template` SET spell1='82792', spell2='83877', spell3='82764' WHERE entry='44932';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44932';
INSERT INTO `pickpocketing_loot_template` VALUES ('44932', '63348', '3.05', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44932', '63291', '3.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44932', '63317', '2.79', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44932', '63349', '2.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44932', '58269', '2.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44932', '63310', '1.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44932', '63300', '1.22', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44932', '63316', '0.35', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44932' WHERE entry='44932';

UPDATE `creature_template` SET spell1='84123', spell2='84126', spell3='84122' WHERE entry='45062';
DELETE FROM `pickpocketing_loot_template` WHERE entry='45062';
INSERT INTO `pickpocketing_loot_template` VALUES ('45062', '63348', '2', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45062', '63349', '1.71', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45062', '63291', '1.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45062', '63317', '1.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45062', '58269', '1.06', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45062', '63310', '0.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45062', '63300', '0.5', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45062', '63316', '0.31', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='45062' WHERE entry='45062';

UPDATE `creature_template` SET spell1='82789', spell2='84031' WHERE entry='44981';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44981';
INSERT INTO `pickpocketing_loot_template` VALUES ('44981', '63348', '8.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44981', '63317', '8.44', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44981', '63291', '8.36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44981', '63349', '7.95', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44981', '58269', '6.22', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44981', '63310', '3.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44981', '63300', '3.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44981', '63316', '1.3', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44981', '63318', '0.5', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44981' WHERE entry='44981';

UPDATE `creature_template` SET spell1='84230', spell2='84237' WHERE entry='45097';
DELETE FROM `pickpocketing_loot_template` WHERE entry='45097';
INSERT INTO `pickpocketing_loot_template` VALUES ('45097', '63348', '9.98', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45097', '63349', '9.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45097', '63317', '8.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45097', '63291', '7.18', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45097', '58269', '6.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45097', '63310', '5.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45097', '63300', '2.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45097', '63316', '0.74', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='45097' WHERE entry='45097';

UPDATE `creature_template` SET spell1='82791', spell2='82794', spell3='83877' WHERE entry='44926';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44926';
INSERT INTO `pickpocketing_loot_template` VALUES ('44926', '63291', '3.92', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44926', '63349', '3.91', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44926', '63317', '3.9', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44926', '63348', '3.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44926', '58269', '2.69', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44926', '63310', '2.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44926', '63300', '1.45', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44926', '63316', '0.28', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44926' WHERE entry='44926';

UPDATE `creature_template` SET spell1='83783', spell2='83785' WHERE entry='44896';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44896';
INSERT INTO `pickpocketing_loot_template` VALUES ('44896', '63317', '6.37', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44896', '63291', '6.05', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44896', '63349', '5.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44896', '63348', '5.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44896', '58269', '4.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44896', '63310', '2.74', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44896', '63300', '2.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44896', '63316', '0.34', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44896', '63318', '0.34', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44896' WHERE entry='44896';

UPDATE `creature_template` SET spell1='83776', spell2='83778' WHERE entry='44898';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44898';
INSERT INTO `pickpocketing_loot_template` VALUES ('44898', '63317', '3.88', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44898', '63349', '3.74', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44898', '58269', '3.31', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44898', '63348', '3.23', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44898', '63291', '2.88', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44898', '63310', '1.3', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44898', '63300', '0.96', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44898', '63316', '0.27', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44898' WHERE entry='44898';

UPDATE `creature_template` SET spell1='83780' WHERE entry='44897';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44897';
INSERT INTO `pickpocketing_loot_template` VALUES ('44897', '63291', '4.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44897', '63349', '4.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44897', '58269', '4.42', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44897', '63348', '4.38', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44897', '63317', '4.34', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44897', '63310', '2.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44897', '63300', '1.34', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44897', '63316', '0.33', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44897' WHERE entry='44897';

UPDATE `creature_template` SET spell1='91872', spell2='91871', spell3='93959', spell4='84544', spell5='84521' WHERE entry='45259';

UPDATE `creature_template` SET spell1='91872', spell2='91871', spell3='93959', spell4='84544', spell5='84521' WHERE entry='45269';

UPDATE `creature_template` SET spell1='91872', spell2='91871', spell3='93959', spell4='84544', spell5='84521' WHERE entry='45268';

UPDATE `creature_template` SET spell1='89212' WHERE entry='44261';

UPDATE `creature_template` SET spell1='82263' WHERE entry='43934';

DELETE FROM `skinning_loot_template` WHERE entry='45096';
INSERT INTO `skinning_loot_template` VALUES ('45096', '52976', '98.06', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('45096', '67495', '0.92', '1', '0', '1', '1');
UPDATE `creature_template` SET skinloot='45096' WHERE entry='45096';

DELETE FROM `pickpocketing_loot_template` WHERE entry='45065';
INSERT INTO `pickpocketing_loot_template` VALUES ('45065', '63348', '24.37', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45065', '63291', '22.69', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45065', '63349', '22.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45065', '63317', '22.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45065', '58269', '16.96', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45065', '63310', '11.51', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45065', '63300', '6.91', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45065', '63316', '2.18', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45065', '63318', '1.22', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='45065' WHERE entry='45065';
