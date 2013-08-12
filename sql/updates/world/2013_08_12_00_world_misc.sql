REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES 
(181251, 10, 409, 'Smoked Meat Rack', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 1655, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 11723);

UPDATE `creature_template` SET spell1='16867', spell2='16868', spell3='17244', spell4='18327' WHERE entry='10436';

DELETE FROM `pickpocketing_loot_template` WHERE entry='11121';
INSERT INTO `pickpocketing_loot_template` VALUES ('11121', '3419', '42.86', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11121', '16884', '28.57', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11121', '3928', '28.57', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11121', '4608', '14.29', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='11121' WHERE entry='11121';

UPDATE `creature_template` SET spell1='12734', spell2='16172', spell3='15245' WHERE entry='11032';
DELETE FROM `pickpocketing_loot_template` WHERE entry='11032';
INSERT INTO `pickpocketing_loot_template` VALUES ('11032', '16884', '47.73', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11032', '3927', '25', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11032', '5432', '22.73', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11032', '4602', '13.64', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11032', '4601', '9.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11032', '3928', '6.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11032', '8932', '2.27', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='11032' WHERE entry='11032';

UPDATE `creature_template` SET spell1='17294', spell2='7964' WHERE entry='11058';

UPDATE `creature_template` SET spell1='16244', spell2='16798', spell3='14443', spell4='15620' WHERE entry='10558';

UPDATE `creature_template` SET spell1='17293', spell2='17366', spell3='33975' WHERE entry='10811';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10811';
INSERT INTO `pickpocketing_loot_template` VALUES ('10811', '16884', '48.15', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10811', '5432', '29.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10811', '7909', '11.11', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10811', '3927', '7.41', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10811', '4601', '7.41', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10811', '3928', '5.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10811', '4602', '3.7', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10811' WHERE entry='10811';

UPDATE `creature_template` SET spell1='15496', spell2='16856', spell3='17393', spell4='17435', spell5='17434', spell6='17467' WHERE entry='45412';
DELETE FROM `pickpocketing_loot_template` WHERE entry='45412';
INSERT INTO `pickpocketing_loot_template` VALUES ('45412', '3419', '81.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45412', '4608', '63.64', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45412', '3928', '18.18', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45412', '13344', '9.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45412', '22409', '9.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('45412', '16884', '9.09', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='45412' WHERE entry='45412';

UPDATE `creature_template` SET spell1='10887', spell2='16793', spell3='16791', spell4='14099' WHERE entry='10435';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10435';
INSERT INTO `pickpocketing_loot_template` VALUES ('10435', '16884', '46.51', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10435', '3419', '41.86', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10435', '4608', '27.91', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10435', '3928', '11.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10435', '7910', '2.33', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10435' WHERE entry='10435';

UPDATE `creature_template` SET spell1='6136', spell2='17620', spell3='54791', spell4='16869' WHERE entry='10438';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10438';
INSERT INTO `pickpocketing_loot_template` VALUES ('10438', '16884', '73.68', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10438', '4608', '55.26', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10438', '3419', '50', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10438', '18737', '5.26', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10438', '3928', '5.26', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10438', '29571', '5.26', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10438' WHERE entry='10438';

UPDATE `creature_template` SET spell1='31602', spell2='4962', spell3='6016', spell4='17235' WHERE entry='10437';

UPDATE `creature_template` SET spell1='6253', spell2='13338', spell3='12741', spell4='12542' WHERE entry='11143';

UPDATE `creature_template` SET spell1='17687', spell2='17307', spell3='5568' WHERE entry='10439';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10439';
INSERT INTO `pickpocketing_loot_template` VALUES ('10439', '3419', '55.77', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10439', '16884', '44.23', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10439', '4608', '26.92', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10439', '7909', '1.92', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10439', '7910', '1.92', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10439', '3928', '1.92', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10439' WHERE entry='10439';

UPDATE `creature_template` SET spell1='17445' WHERE entry='11120';

UPDATE `creature_template` SET spell1='15230', spell2='6136', spell3='12544', spell4='15499', spell5='16799' WHERE entry='10393';

UPDATE `creature_template` SET spell1='14331' WHERE entry='10809';

UPDATE `creature_template` SET spell1='15615', spell2='15618' WHERE entry='11082';
DELETE FROM `pickpocketing_loot_template` WHERE entry='11082';
INSERT INTO `pickpocketing_loot_template` VALUES ('11082', '3419', '65.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11082', '16884', '65.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11082', '4608', '15.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11082', '3928', '12.5', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='11082' WHERE entry='11082';

UPDATE `creature_template` SET spell1='6136', spell2='14907', spell3='122832' WHERE entry='10516';

UPDATE `creature_template` SET spell1='8599', spell2='17470' WHERE entry='10808';

UPDATE `creature_template` SET spell1='10101', spell2='110762', spell3='15615', spell4='59146', spell5='17279' WHERE entry='10997';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10997';
INSERT INTO `pickpocketing_loot_template` VALUES ('10997', '5432', '36.73', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10997', '16884', '26.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10997', '4601', '12.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10997', '3928', '12.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10997', '3927', '8.16', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10997', '7909', '6.12', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10997', '4602', '6.12', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10997' WHERE entry='10997';

DELETE FROM `pickpocketing_loot_template` WHERE entry='10416';
INSERT INTO `pickpocketing_loot_template` VALUES ('10416', '3419', '54.17', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10416', '4608', '20.83', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10416', '16884', '12.5', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10416', '3928', '12.5', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10416', '8948', '8.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10416', '7909', '4.17', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10416', '16885', '4.17', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10416' WHERE entry='10416';

UPDATE `creature_template` SET spell1='15496', spell2='17439' WHERE entry='10394';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10394';
INSERT INTO `pickpocketing_loot_template` VALUES ('10394', '3419', '72.97', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10394', '4608', '48.65', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10394', '16884', '43.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10394', '3928', '43.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10394', '8948', '5.41', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10394', '16885', '5.41', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10394' WHERE entry='10394';

UPDATE `creature_template` SET spell1='4962', spell2='16427' WHERE entry='10413';

UPDATE `creature_template` SET spell1='31601', spell2='15471' WHERE entry='10412';

UPDATE `creature_template` SET spell1='92025', spell2='79934', spell3='13847', spell4='12471' WHERE entry='10820';

UPDATE `creature_template` SET spell1='16380' WHERE entry='10411';

UPDATE `creature_template` SET spell1='16380' WHERE entry='42973';

UPDATE `creature_template` SET spell1='13738' WHERE entry='10407';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10407';
INSERT INTO `pickpocketing_loot_template` VALUES ('10407', '4608', '58.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10407', '16884', '46.34', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10407', '3419', '24.39', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10407', '3928', '9.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10407', '16885', '2.44', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10407' WHERE entry='10407';

UPDATE `creature_template` SET spell1='16336', spell2='6754', spell3='7068' WHERE entry='10385';

UPDATE `creature_template` SET spell1='16172', spell2='16553' WHERE entry='10406';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10406';
INSERT INTO `pickpocketing_loot_template` VALUES ('10406', '3419', '43.84', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10406', '16884', '32.88', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10406', '4608', '24.66', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10406', '3928', '9.59', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10406', '16885', '4.11', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10406', '7909', '2.74', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10406', '7910', '2.74', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10406', '8948', '2.74', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10406' WHERE entry='10406';

UPDATE `creature_template` SET spell1='16143' WHERE entry='10382';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10382';
INSERT INTO `pickpocketing_loot_template` VALUES ('10382', '16884', '47.37', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10382', '3419', '33.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10382', '4608', '31.58', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10382', '3928', '15.79', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10382', '16885', '3.51', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10382', '7909', '1.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10382', '7910', '1.75', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10382' WHERE entry='10382';

UPDATE `creature_template` SET spell1='77978', spell2='18813' WHERE entry='10414';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10414';
INSERT INTO `pickpocketing_loot_template` VALUES ('10414', '4608', '76.47', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10414', '3419', '41.18', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10414', '16884', '17.65', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10414', '3928', '17.65', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10414', '7910', '5.88', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10414' WHERE entry='10414';

UPDATE `creature_template` SET spell1='40505', spell2='8599', spell3='16458' WHERE entry='10405';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10405';
INSERT INTO `pickpocketing_loot_template` VALUES ('10405', '16884', '50.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10405', '3419', '42.25', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10405', '4608', '26.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10405', '3928', '14.08', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10405', '16885', '2.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10405', '7910', '1.41', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10405', '8948', '1.41', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10405' WHERE entry='10405';

UPDATE `creature_template` SET spell1='40505', spell2='8599', spell3='16458' WHERE entry='42975';
DELETE FROM `pickpocketing_loot_template` WHERE entry='42975';
INSERT INTO `pickpocketing_loot_template` VALUES ('42975', '3419', '38', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('42975', '4608', '36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('42975', '16884', '36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('42975', '3928', '12', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('42975', '7909', '2', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('42975', '4338', '2', '1', '0', '1', '4');
UPDATE `creature_template` SET pickpocketloot='42975' WHERE entry='42975';

UPDATE `creature_template` SET spell1='16460' WHERE entry='10461';

UPDATE `creature_template` SET spell1='16449' WHERE entry='10536';

UPDATE `creature_template` SET spell1='16448' WHERE entry='10441';

UPDATE `creature_template` SET spell1='13446', spell2='16324' WHERE entry='10381';

DELETE FROM `pickpocketing_loot_template` WHERE entry='10381';
INSERT INTO `pickpocketing_loot_template` VALUES ('10381', '16884', '55.1', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10381', '4608', '30.61', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10381', '3419', '28.57', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10381', '3928', '8.16', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10381', '7910', '4.08', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10381', '8948', '2.04', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10381' WHERE entry='10381';

UPDATE `creature_template` SET spell1='33860', spell2='17145', spell3='15732' WHERE entry='10425';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10425';
INSERT INTO `pickpocketing_loot_template` VALUES ('10425', '16884', '55.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10425', '4608', '33.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10425', '3419', '28.89', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10425', '3928', '15.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10425', '7909', '4.44', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10425' WHERE entry='10425';

UPDATE `creature_template` SET spell1='15063', spell2='15043', spell3='15241', spell4='17162' WHERE entry='10419';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10419';
INSERT INTO `pickpocketing_loot_template` VALUES ('10419', '3419', '33.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10419', '4608', '28.26', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10419', '16884', '25.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10419', '3928', '20.65', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10419', '16885', '11.96', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10419', '7910', '6.52', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10419', '7909', '1.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10419', '15215', '0.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10419', '1645', '0.54', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10419' WHERE entry='10419';

UPDATE `creature_template` SET spell1='15655' WHERE entry='10421';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10421';
INSERT INTO `pickpocketing_loot_template` VALUES ('10421', '16884', '58.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10421', '3419', '41.18', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10421', '4608', '38.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10421', '3928', '8.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10421', '7910', '2.94', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10421', '7909', '0.74', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10421' WHERE entry='10421';

UPDATE `creature_template` SET spell1='29426', spell2='13737' WHERE entry='10424';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10424';
INSERT INTO `pickpocketing_loot_template` VALUES ('10424', '3419', '43.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10424', '16884', '38.8', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10424', '4608', '34.97', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10424', '3928', '9.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10424', '7909', '1.64', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10424', '1645', '1.64', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10424', '3927', '0.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10424', '4338', '0.55', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10424' WHERE entry='10424';

UPDATE `creature_template` SET spell1='6713', spell2='11972', spell3='19131' WHERE entry='10418';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10418';
INSERT INTO `pickpocketing_loot_template` VALUES ('10418', '16884', '43.07', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10418', '3419', '37.45', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10418', '4608', '28.84', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10418', '3928', '10.11', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10418', '5432', '8.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10418', '8950', '4.12', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10418', '7909', '2.62', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10418' WHERE entry='10418';

UPDATE `creature_template` SET spell1='15587', spell2='15654' WHERE entry='10420';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10420';
INSERT INTO `pickpocketing_loot_template` VALUES ('10420', '16884', '41.77', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10420', '3419', '40.51', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10420', '4608', '36.71', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10420', '3928', '16.46', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10420', '7910', '1.27', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10420' WHERE entry='10420';

UPDATE `creature_template` SET spell1='17165', spell2='17151', spell3='15654' WHERE entry='10426';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10426';
INSERT INTO `pickpocketing_loot_template` VALUES ('10426', '3419', '38.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10426', '16884', '38.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10426', '4608', '36.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10426', '3928', '7.35', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10426', '8932', '1.47', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10426', '5432', '1.47', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10426' WHERE entry='10426';

UPDATE `creature_template` SET spell1='76583', spell2='3391' WHERE entry='11043';
DELETE FROM `pickpocketing_loot_template` WHERE entry='11043';
INSERT INTO `pickpocketing_loot_template` VALUES ('11043', '16884', '27.78', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11043', '5432', '27.78', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11043', '3927', '25.93', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11043', '4602', '14.81', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11043', '4601', '9.26', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('11043', '3928', '9.26', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='11043' WHERE entry='11043';

UPDATE `creature_template` SET spell1='15586', spell2='17141', spell3='25054', spell4='17139' WHERE entry='10423';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10423';
INSERT INTO `pickpocketing_loot_template` VALUES ('10423', '3419', '35.38', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10423', '4608', '33.85', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10423', '16884', '33.85', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10423', '3928', '13.85', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10423', '7910', '4.62', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10423' WHERE entry='10423';

UPDATE `creature_template` SET spell1='17353' WHERE entry='11054';

UPDATE `creature_template` SET spell1='13748', spell2='17150', spell3='6136', spell4='14145', spell5='12544', spell6='13323' WHERE entry='10422';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10422';
INSERT INTO `pickpocketing_loot_template` VALUES ('10422', '16884', '50.49', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10422', '4608', '42.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10422', '3419', '32.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10422', '3928', '6.8', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10422', '1645', '5.83', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10422', '4338', '5.83', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10422', '7909', '0.97', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10422' WHERE entry='10422';

UPDATE `creature_template` SET spell1='13444' WHERE entry='42971';

UPDATE `creature_template` SET spell1='13444' WHERE entry='10408';

UPDATE `creature_template` SET spell1='13730', spell2='80781' WHERE entry='10409';

UPDATE `creature_template` SET spell1='80780', spell2='3589' WHERE entry='10463';

UPDATE `creature_template` SET spell1='15496', spell2='13730', spell3='9080', spell4='12555', spell5='11976' WHERE entry='10391';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10391';
INSERT INTO `pickpocketing_loot_template` VALUES ('10391', '16884', '42.39', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10391', '3419', '41.3', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10391', '4608', '29.35', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10391', '3928', '9.78', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10391', '7909', '2.17', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10391', '4338', '1.09', '1', '0', '1', '2');
INSERT INTO `pickpocketing_loot_template` VALUES ('10391', '8948', '1.09', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10391' WHERE entry='10391';

UPDATE `creature_template` SET spell1='37361', spell2='11975', spell3='8364', spell4='12557', spell5='13787', spell6='9672', spell7='9613' WHERE entry='10390';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10390';
INSERT INTO `pickpocketing_loot_template` VALUES ('10390', '16884', '43.16', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10390', '3419', '36.84', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10390', '4608', '34.74', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10390', '3928', '9.47', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10390', '7909', '4.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10390', '16885', '1.05', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10390' WHERE entry='10390';

UPDATE `creature_template` SET spell1='16333', spell2='16336', spell3='6754' WHERE entry='10384';

UPDATE `creature_template` SET spell1='12531' WHERE entry='10388';

DELETE FROM `creature_loot_template` WHERE entry='10399';
INSERT INTO `creature_loot_template` VALUES ('10399', '3927', '53.48', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('10399', '4338', '31.17', '1', '0', '1', '4');
INSERT INTO `creature_loot_template` VALUES ('10399', '1645', '26.22', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('10399', '3928', '16.91', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('10399', '6149', '7.36', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='10399' WHERE entry='10399';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10399';
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '16884', '54.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '3419', '52.27', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '4608', '34.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '3928', '7.73', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '1645', '5.91', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '7909', '5', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '7910', '1.36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '16885', '1.36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '3927', '0.91', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '4338', '0.91', '1', '0', '1', '2');
INSERT INTO `pickpocketing_loot_template` VALUES ('10399', '4638', '0.45', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10399' WHERE entry='10399';

UPDATE `creature_template` SET spell1='80850', spell2='16430', spell3='12420' WHERE entry='10400';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10400';
INSERT INTO `pickpocketing_loot_template` VALUES ('10400', '3419', '55.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10400', '4608', '42.42', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10400', '16884', '39.39', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10400', '3928', '8.08', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10400', '7910', '3.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10400', '16885', '3.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10400', '5432', '3.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10400', '8950', '1.01', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10400' WHERE entry='10400';

UPDATE `creature_template` SET spell1='11443', spell2='16429', spell3='12739' WHERE entry='10398';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10398';
INSERT INTO `pickpocketing_loot_template` VALUES ('10398', '16884', '60', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10398', '3419', '46.96', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10398', '4608', '25.22', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10398', '3928', '18.26', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10398', '7909', '6.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10398', '5432', '1.74', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10398', '7910', '0.87', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10398', '3927', '0.87', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10398', '16885', '0.87', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10398' WHERE entry='10398';

UPDATE `creature_template` SET spell1='5137', spell2='7713' WHERE entry='11142';

UPDATE `creature_template` SET spell1='13298' WHERE entry='10876';

UPDATE `creature_template` SET spell1='15089' WHERE entry='10387';

UPDATE `creature_template` SET spell1='7992', spell2='16866' WHERE entry='10417';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10417';
INSERT INTO `pickpocketing_loot_template` VALUES ('10417', '4608', '62.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10417', '16884', '54.08', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10417', '3419', '29.59', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10417', '3928', '6.12', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10417', '16885', '2.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10417', '7909', '1.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10417', '4338', '1.02', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10417' WHERE entry='10417';

UPDATE `creature_template` SET spell1='19645', spell2='17105' WHERE entry='10464';

UPDATE `creature_template` SET spell1='7074' WHERE entry='10389';
