UPDATE `creature_template` SET spell1='76094', spell2='76047', spell3='76100', spell4='76026' WHERE entry='40765';

UPDATE `creature_template` SET spell1='84931', spell2='76165', spell3='76171', spell4='76170' WHERE entry='40825';

UPDATE `creature_template` SET spell1='80564', spell2='76001', spell3='76008', spell4='75722', spell5='75683' WHERE entry='40586';

UPDATE `creature_template` SET spell1='76307', spell2='76207', spell3='76234', spell4='76339' WHERE entry='40788';

UPDATE `creature_template` SET spell1='83672' WHERE entry='44566';

UPDATE `creature_template` SET spell1='83971' WHERE entry='44841';

DELETE FROM `creature_loot_template` WHERE entry='39960';
INSERT INTO `creature_loot_template` VALUES ('39960', '63312', '100', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='39960' WHERE entry='39960';
DELETE FROM `pickpocketing_loot_template` WHERE entry='39960';
INSERT INTO `pickpocketing_loot_template` VALUES ('39960', '58263', '27.89', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39960', '63312', '26.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39960', '63293', '25.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39960', '63349', '20.25', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39960', '63327', '12.81', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39960', '63321', '3.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39960', '63300', '2.48', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='39960' WHERE entry='39960';

DELETE FROM `creature_loot_template` WHERE entry='40579';
INSERT INTO `creature_loot_template` VALUES ('40579', '63293', '27.27', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('40579', '58263', '18.18', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('40579', '63300', '13.64', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('40579', '63327', '9.09', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='40579' WHERE entry='40579';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40579';
INSERT INTO `pickpocketing_loot_template` VALUES ('40579', '63312', '42.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40579', '63293', '27.66', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40579', '63349', '25.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40579', '58263', '17.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40579', '63327', '14.89', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40579', '63300', '12.77', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40579', '63342', '4.26', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40579' WHERE entry='40579';

UPDATE `creature_template` SET spell1='83463' WHERE entry='44752';

UPDATE `creature_template` SET spell1='76590', spell2='76604' WHERE entry='40936';
DELETE FROM `creature_loot_template` WHERE entry='40936';
INSERT INTO `creature_loot_template` VALUES ('40936', '52326', '12.11', '1', '0', '1', '4');
INSERT INTO `creature_loot_template` VALUES ('40936', '55260', '2.03', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('40936', '55262', '1.93', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='40936' WHERE entry='40936';

UPDATE `creature_template` SET spell1='76560', spell2='76535' WHERE entry='40943';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40943';
INSERT INTO `pickpocketing_loot_template` VALUES ('40943', '63312', '16.35', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40943', '58263', '14.1', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40943', '63293', '13.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40943', '63349', '11.44', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40943', '63327', '5.45', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40943', '63300', '4.36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40943', '63321', '0.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40943', '63342', '0.2', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40943' WHERE entry='40943';

UPDATE `creature_template` SET spell1='76520', spell2='76516' WHERE entry='40935';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40935';
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63293', '7.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63312', '7.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '58263', '6.87', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63349', '6.8', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63327', '2.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63300', '2.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63321', '0.58', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40935' WHERE entry='40935';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40935';
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63293', '7.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63312', '7.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '58263', '6.87', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63349', '6.8', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63327', '2.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63300', '2.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40935', '63321', '0.58', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40935' WHERE entry='40935';

UPDATE `creature_template` SET spell1='75907', spell2='75998' WHERE entry='40633';

UPDATE `creature_template` SET spell1='84507', spell2='76790', spell3='76807' WHERE entry='39616';
DELETE FROM `pickpocketing_loot_template` WHERE entry='39616';
INSERT INTO `pickpocketing_loot_template` VALUES ('39616', '63349', '5.44', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39616', '63293', '5.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39616', '63312', '5.31', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39616', '58263', '4.38', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39616', '63327', '2.37', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39616', '63300', '1.85', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='39616' WHERE entry='39616';

UPDATE `creature_template` SET spell1='84507', spell2='76790', spell3='76807' WHERE entry='40584';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40584';
INSERT INTO `pickpocketing_loot_template` VALUES ('40584', '63293', '4.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40584', '58263', '4.31', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40584', '63349', '4.28', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40584', '63312', '3.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40584', '63327', '1.8', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40584', '63300', '1.34', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40584' WHERE entry='40584';

UPDATE `creature_template` SET spell1='76721' WHERE entry='40577';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40577';
INSERT INTO `pickpocketing_loot_template` VALUES ('40577', '58263', '3.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40577', '63349', '3.46', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40577', '63312', '3.14', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40577', '63293', '2.86', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40577', '63327', '2.05', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40577', '63300', '1.16', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40577', '63321', '0.39', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40577' WHERE entry='40577';

UPDATE `creature_template` SET spell1='76813', spell2='76820', spell3='76815' WHERE entry='41096';
DELETE FROM `pickpocketing_loot_template` WHERE entry='41096';
INSERT INTO `pickpocketing_loot_template` VALUES ('41096', '63312', '3.98', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41096', '63349', '3.87', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41096', '63293', '3.71', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41096', '58263', '3.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41096', '63327', '2.2', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41096', '63300', '1.44', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='41096' WHERE entry='41096';

UPDATE `creature_template` SET spell1='76813', spell2='76820', spell3='76815' WHERE entry='41139';
DELETE FROM `pickpocketing_loot_template` WHERE entry='41139';
INSERT INTO `pickpocketing_loot_template` VALUES ('41139', '63349', '27.84', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41139', '63293', '26.68', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41139', '63312', '24.59', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41139', '58263', '20.88', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41139', '63327', '12.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41139', '63300', '9.98', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41139', '63321', '0.46', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('41139', '63342', '0.23', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='41139' WHERE entry='41139';

UPDATE `creature_template` SET spell1='75813', spell2='75992' WHERE entry='40634';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40634';
INSERT INTO `pickpocketing_loot_template` VALUES ('40634', '63293', '2.62', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40634', '63349', '2.37', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40634', '58263', '2.27', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40634', '63312', '2.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40634', '63327', '1.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40634', '63300', '0.86', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40634' WHERE entry='40634';

UPDATE `creature_template` SET spell1='75813', spell2='75992' WHERE entry='44404';
DELETE FROM `pickpocketing_loot_template` WHERE entry='44404';
INSERT INTO `pickpocketing_loot_template` VALUES ('44404', '63312', '83.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44404', '63293', '50', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44404', '63349', '50', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44404', '58263', '33.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('44404', '63300', '16.67', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='44404' WHERE entry='44404';

UPDATE `creature_template` SET spell1='84037', spell2='76133' WHERE entry='40792';

UPDATE `creature_template` SET spell1='76634' WHERE entry='40925';

UPDATE `creature_template` SET spell1='76363' WHERE entry='40923';

UPDATE `creature_template` SET spell1='83985' WHERE entry='44648';

UPDATE `creature_template` SET spell1='83915', spell2='83914', spell3='83926' WHERE entry='44715';
