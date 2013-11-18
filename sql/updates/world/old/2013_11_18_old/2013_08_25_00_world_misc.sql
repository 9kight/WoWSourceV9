UPDATE `creature_template` SET spell1='76185', spell2='82393', spell3='76186', spell4='76242', spell5='76274', spell6='76200', spell7='76188' WHERE entry='39705';

UPDATE `creature_template` SET spell1='82395', spell2='76030', spell3='76032', spell4='76031', spell5='76028' WHERE entry='39700';
DELETE FROM `skinning_loot_template` WHERE entry='39700';
INSERT INTO `skinning_loot_template` VALUES ('39700', '52976', '74.54', '1', '0', '1', '9');
INSERT INTO `skinning_loot_template` VALUES ('39700', '52977', '51.9', '1', '0', '1', '12');
UPDATE `creature_template` SET skinloot='39700' WHERE entry='39700';

UPDATE `creature_template` SET spell1='75817', spell2='75823', spell3='75645', spell4='75610', spell5='75732' WHERE entry='39679';

UPDATE `creature_template` SET spell1='15284', spell2='75842', spell3='75846' WHERE entry='39698';

UPDATE `creature_template` SET spell1='82137', spell2='75539', spell3='75272', spell4='75543', spell5='75571' WHERE entry='39665';

UPDATE `creature_template` SET spell1='76622' WHERE entry='40084';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40084';
INSERT INTO `pickpocketing_loot_template` VALUES ('40084', '63348', '11.1', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40084', '63291', '9.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40084', '63349', '9.4', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40084', '63317', '9.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40084', '58269', '6.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40084', '63310', '4.58', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40084', '63300', '2.97', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40084', '63316', '0.98', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40084', '63318', '0.42', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40084' WHERE entry='40084';

UPDATE `creature_template` SET spell1='76628', spell2='76665' WHERE entry='40013';
DELETE FROM `skinning_loot_template` WHERE entry='40013';
INSERT INTO `skinning_loot_template` VALUES ('40013', '52977', '47.12', '1', '0', '1', '8');
INSERT INTO `skinning_loot_template` VALUES ('40013', '52976', '45.82', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('40013', '67495', '2.93', '1', '0', '1', '1');
UPDATE `creature_template` SET skinloot='40013' WHERE entry='40013';

UPDATE `creature_template` SET spell1='75441' WHERE entry='40447';

UPDATE `creature_template` SET spell1='76617', spell2='76618' WHERE entry='39994';

UPDATE `creature_template` SET spell1='76509', spell2='76508', spell3='54792' WHERE entry='39982';
DELETE FROM `pickpocketing_loot_template` WHERE entry='39982';
INSERT INTO `pickpocketing_loot_template` VALUES ('39982', '63317', '5.79', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39982', '63349', '5.36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39982', '63348', '4.81', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39982', '58269', '4.64', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39982', '63291', '3.91', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39982', '63310', '3.86', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39982', '63300', '1.12', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39982', '63316', '0.17', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='39982' WHERE entry='39982';

UPDATE `creature_template` SET spell1='76716', spell2='76717' WHERE entry='40023';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40023';
INSERT INTO `pickpocketing_loot_template` VALUES ('40023', '63317', '2.1', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40023', '63291', '2.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40023', '63348', '1.45', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40023', '63349', '1.39', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40023', '58269', '1.14', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40023', '63310', '0.86', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40023', '63300', '0.83', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40023' WHERE entry='40023';

UPDATE `creature_template` SET spell1='76575', spell2='76522', spell3='76561', spell4='76524', spell5='82362' WHERE entry='39987';
DELETE FROM `pickpocketing_loot_template` WHERE entry='39987';
INSERT INTO `pickpocketing_loot_template` VALUES ('39987', '63291', '3.12', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39987', '63317', '3.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39987', '63348', '2.95', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39987', '63349', '2.91', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39987', '58269', '2.34', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39987', '63310', '1.52', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39987', '63300', '1.08', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='39987' WHERE entry='39987';

UPDATE `creature_template` SET spell1='76718', spell2='76719' WHERE entry='40021';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40021';
INSERT INTO `pickpocketing_loot_template` VALUES ('40021', '58269', '40', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40021', '63349', '20', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40021', '63310', '20', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40021', '63317', '20', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40021', '63348', '20', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40021' WHERE entry='40021';

UPDATE `creature_template` SET spell1='76628', spell2='76665' WHERE entry='40008';
DELETE FROM `skinning_loot_template` WHERE entry='40008';
INSERT INTO `skinning_loot_template` VALUES ('40008', '52977', '47.95', '1', '0', '1', '9');
INSERT INTO `skinning_loot_template` VALUES ('40008', '52976', '44.87', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('40008', '67495', '3.31', '1', '0', '1', '1');
UPDATE `creature_template` SET skinloot='40008' WHERE entry='40008';

UPDATE `creature_template` SET spell1='8599', spell2='77568', spell3='76512' WHERE entry='39985';
DELETE FROM `pickpocketing_loot_template` WHERE entry='39985';
INSERT INTO `pickpocketing_loot_template` VALUES ('39985', '63349', '1.49', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39985', '63317', '1.38', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39985', '63291', '1.35', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39985', '63348', '1.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39985', '58269', '1.07', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39985', '63300', '0.87', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39985', '63310', '0.6', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='39985' WHERE entry='39985';

UPDATE `creature_template` SET spell1='80218' WHERE entry='39670';

UPDATE `creature_template` SET spell1='76628', spell2='76665' WHERE entry='40015';

UPDATE `creature_template` SET spell1='76189' WHERE entry='40817';

UPDATE `creature_template` SET spell1='76680', spell2='76677', spell3='58025', spell4='76682' WHERE entry='40017';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40017';
INSERT INTO `pickpocketing_loot_template` VALUES ('40017', '63348', '12.98', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40017', '63317', '12.51', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40017', '63349', '12.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40017', '63291', '12.07', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40017', '58269', '8.9', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40017', '63310', '7.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40017', '63300', '4.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40017', '63316', '1.31', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40017', '63318', '0.67', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40017' WHERE entry='40017';

UPDATE `creature_template` SET spell1='76473', spell2='76325' WHERE entry='39708';
DELETE FROM `pickpocketing_loot_template` WHERE entry='39708';
INSERT INTO `pickpocketing_loot_template` VALUES ('39708', '63317', '2.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39708', '63348', '2.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39708', '63291', '2.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39708', '63349', '2.34', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39708', '58269', '1.87', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39708', '63310', '1.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39708', '63300', '0.9', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='39708' WHERE entry='39708';

UPDATE `creature_template` SET spell1='76688', spell2='76686' WHERE entry='40019';
DELETE FROM `pickpocketing_loot_template` WHERE entry='40019';
INSERT INTO `pickpocketing_loot_template` VALUES ('40019', '63349', '13.57', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40019', '63291', '13.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40019', '63317', '13.3', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40019', '63348', '12.26', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40019', '58269', '8.81', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40019', '63310', '6.19', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40019', '63300', '4.17', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40019', '63316', '1.4', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('40019', '63318', '0.66', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='40019' WHERE entry='40019';

UPDATE `creature_template` SET spell1='76502', spell2='75590', spell3='76497', spell4='76572', spell5='76500' WHERE entry='39980';
DELETE FROM `pickpocketing_loot_template` WHERE entry='39980';
INSERT INTO `pickpocketing_loot_template` VALUES ('39980', '63349', '3.92', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39980', '63317', '3.85', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39980', '63348', '3.17', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39980', '63291', '2.79', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39980', '58269', '2.46', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39980', '63310', '1.69', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39980', '63300', '1.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39980', '63316', '0.36', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='39980' WHERE entry='39980';

UPDATE `creature_template` SET spell1='75590', spell2='76478', spell3='76484', spell4='76487' WHERE entry='39978';
DELETE FROM `pickpocketing_loot_template` WHERE entry='39978';
INSERT INTO `pickpocketing_loot_template` VALUES ('39978', '63291', '3.42', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39978', '63317', '2.92', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39978', '63348', '2.92', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39978', '63349', '2.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39978', '58269', '1.98', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39978', '63310', '1.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39978', '63300', '1.11', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39978', '63316', '0.34', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='39978' WHERE entry='39978';

UPDATE `creature_template` SET spell1='76589', spell2='76592', spell3='76612', spell4='76591', spell5='76582', spell6='76583', spell7='13737', spell8='76594' WHERE entry='39990';
DELETE FROM `pickpocketing_loot_template` WHERE entry='39990';
INSERT INTO `pickpocketing_loot_template` VALUES ('39990', '63349', '21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39990', '63291', '20.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39990', '63348', '20.36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39990', '63317', '19.84', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39990', '58269', '14.88', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39990', '63310', '9.97', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39990', '63300', '7.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39990', '63316', '2.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('39990', '63318', '1.04', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='39990' WHERE entry='39990';

UPDATE `creature_template` SET spell1='75697', spell2='76522', spell3='76561', spell4='76524', spell5='75608', spell6='82362' WHERE entry='50284';
DELETE FROM `pickpocketing_loot_template` WHERE entry='50284';
INSERT INTO `pickpocketing_loot_template` VALUES ('50284', '63349', '24.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('50284', '63291', '21.47', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('50284', '63317', '19.27', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('50284', '63348', '18.9', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('50284', '58269', '16.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('50284', '63310', '10.83', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('50284', '63300', '5.5', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('50284', '63316', '4.59', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('50284', '63318', '1.65', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='50284' WHERE entry='50284';
