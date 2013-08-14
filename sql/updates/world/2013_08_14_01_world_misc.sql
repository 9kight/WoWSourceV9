-- Blackrock Spire ability spells pickpocket skinning
UPDATE `creature_template` SET spell1='15128', spell2='13737', spell3='41056', spell4='41057' WHERE entry='9596';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9596';
INSERT INTO `pickpocketing_loot_template` VALUES ('9596', '5428', '58.62', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9596', '16885', '46.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9596', '8950', '20.69', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9596', '8952', '19.44', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9596', '3928', '12.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9596', '7910', '1.1', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9596' WHERE entry='9596';

UPDATE `creature_template` SET spell1='16046', spell2='16074', spell3='15580', spell4='15548' WHERE entry='10263';

UPDATE `creature_template` SET spell1='16416' WHERE entry='10376';

UPDATE `creature_template` SET spell1='15284', spell2='16805', spell3='16419', spell4='6016', spell5='16789' WHERE entry='10363';
DELETE FROM `skinning_loot_template` WHERE entry='10363';
INSERT INTO `skinning_loot_template` VALUES ('10363', '8170', '61.6', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10363', '15416', '29.27', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10363', '8165', '12.01', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10363', '4304', '5.91', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10363', '8171', '5.38', '1', '0', '1', '4');
UPDATE `creature_template` SET skinloot='10363' WHERE entry='10363';

UPDATE `creature_template` SET spell1='8269', spell2='11972', spell3='87081' WHERE entry='9718';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9718';
INSERT INTO `pickpocketing_loot_template` VALUES ('9718', '16885', '47.85', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9718', '5428', '42.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9718', '8950', '18.32', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9718', '8952', '17.94', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9718', '3928', '8.22', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9718', '7910', '0.75', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9718' WHERE entry='9718';

UPDATE `creature_template` SET spell1='16495', spell2='8269', spell3='16128' WHERE entry='10268';
DELETE FROM `skinning_loot_template` WHERE entry='10268';
INSERT INTO `skinning_loot_template` VALUES ('10268', '8170', '102.49', '1', '0', '1', '9');
INSERT INTO `skinning_loot_template` VALUES ('10268', '8171', '10.54', '1', '0', '1', '4');
UPDATE `creature_template` SET skinloot='10268' WHERE entry='10268';

UPDATE `creature_template` SET spell1='6253', spell2='16172', spell3='15580' WHERE entry='10899';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10899';
INSERT INTO `pickpocketing_loot_template` VALUES ('10899', '29570', '52.05', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10899', '29569', '30.14', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10899', '27854', '21.92', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10899', '27855', '20.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10899', '22829', '13.7', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10899' WHERE entry='10899';

UPDATE `creature_template` SET spell1='16359', spell2='16390', spell3='16350', spell4='110762', spell5='10101', spell6='16328' WHERE entry='10339';
DELETE FROM `skinning_loot_template` WHERE entry='10339';
INSERT INTO `skinning_loot_template` VALUES ('10339', '15415', '113.3', '1', '0', '1', '8');
INSERT INTO `skinning_loot_template` VALUES ('10339', '15412', '113.28', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10339', '15414', '113.15', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10339', '8170', '112.93', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10339', '15416', '112.93', '1', '0', '1', '8');
UPDATE `creature_template` SET skinloot='10339' WHERE entry='10339';

UPDATE `creature_template` SET spell1='13738', spell2='3391' WHERE entry='10220';
DELETE FROM `skinning_loot_template` WHERE entry='10220';
INSERT INTO `skinning_loot_template` VALUES ('10220', '8170', '101.46', '1', '0', '1', '9');
INSERT INTO `skinning_loot_template` VALUES ('10220', '8171', '11.53', '1', '0', '1', '4');
UPDATE `creature_template` SET skinloot='10220' WHERE entry='10220';

UPDATE `creature_template` SET spell1='8269', spell2='10101', spell3='110762' WHERE entry='9196';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9196';
INSERT INTO `pickpocketing_loot_template` VALUES ('9196', '5428', '48.42', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9196', '16885', '44.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9196', '8950', '17.83', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9196', '8952', '16.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9196', '3928', '12.36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9196', '7910', '1.38', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9196' WHERE entry='9196';

UPDATE `creature_template` SET spell1='11972', spell2='15749', spell3='87081' WHERE entry='10509';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10509';
INSERT INTO `pickpocketing_loot_template` VALUES ('10509', '8950', '29.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10509', '3928', '25.93', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10509', '5428', '25.93', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10509', '8952', '22.22', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10509', '16885', '14.81', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10509' WHERE entry='10509';

UPDATE `creature_template` SET spell1='27382', spell2='27338', spell3='27286' WHERE entry='16042';

UPDATE `creature_template` SET spell1='27543', spell2='27545', spell3='27551', spell4='27546', spell5='27556', spell6='27532', spell7='27555', spell8='27554' WHERE entry='16080';

UPDATE `creature_template` SET spell1='16104', spell2='16468', spell3='16103' WHERE entry='10596';

UPDATE `creature_template` SET spell1='15284', spell2='16244', spell3='12887' WHERE entry='9568';
DELETE FROM `skinning_loot_template` WHERE entry='9568';
INSERT INTO `skinning_loot_template` VALUES ('9568', '8170', '61.33', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('9568', '15416', '29.04', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('9568', '8165', '12.06', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('9568', '8171', '5.84', '1', '0', '1', '3');
INSERT INTO `skinning_loot_template` VALUES ('9568', '4304', '5.73', '1', '0', '1', '4');
UPDATE `creature_template` SET skinloot='9568' WHERE entry='9568';

UPDATE `creature_template` SET spell1='16079', spell2='16536' WHERE entry='9816';

UPDATE `creature_template` SET spell1='15504', spell2='15609', spell3='59146', spell4='16497' WHERE entry='9736';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9736';
INSERT INTO `pickpocketing_loot_template` VALUES ('9736', '5428', '48.18', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9736', '16885', '42.95', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9736', '8952', '19.77', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9736', '8950', '16.12', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9736', '3928', '12.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9736', '7910', '1.18', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9736' WHERE entry='9736';

UPDATE `creature_template` SET spell1='16098', spell2='16097' WHERE entry='9236';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9236';
INSERT INTO `pickpocketing_loot_template` VALUES ('9236', '5428', '50.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9236', '16885', '48.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9236', '8952', '19.09', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9236', '8950', '18.38', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9236', '3928', '11.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9236', '7910', '1.11', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9236' WHERE entry='9236';

UPDATE `creature_template` SET spell1='16727' WHERE entry='10264';
DELETE FROM `skinning_loot_template` WHERE entry='10264';
INSERT INTO `skinning_loot_template` VALUES ('10264', '8170', '59.13', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10264', '15416', '27.28', '1', '0', '1', '4');
INSERT INTO `skinning_loot_template` VALUES ('10264', '8165', '11.87', '1', '0', '1', '4');
INSERT INTO `skinning_loot_template` VALUES ('10264', '4304', '7.61', '1', '0', '1', '3');
INSERT INTO `skinning_loot_template` VALUES ('10264', '8171', '5.68', '1', '0', '1', '2');
UPDATE `creature_template` SET skinloot='10264' WHERE entry='10264';

DELETE FROM `pickpocketing_loot_template` WHERE entry='9218';
INSERT INTO `pickpocketing_loot_template` VALUES ('9218', '5428', '40.41', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9218', '16885', '38.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9218', '8952', '24.17', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9218', '8950', '22.14', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9218', '3928', '11.07', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9218', '7910', '2.4', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9218' WHERE entry='9218';

DELETE FROM `pickpocketing_loot_template` WHERE entry='9219';
INSERT INTO `pickpocketing_loot_template` VALUES ('9219', '5428', '52.57', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9219', '16885', '46.14', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9219', '8952', '19.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9219', '8950', '14.91', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9219', '3928', '13.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9219', '7910', '0.64', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9219' WHERE entry='9219';

UPDATE `creature_template` SET spell1='15230', spell2='16170', spell3='8365', spell4='13323' WHERE entry='9217';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9217';
INSERT INTO `pickpocketing_loot_template` VALUES ('9217', '5428', '50.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9217', '16885', '42.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9217', '8950', '16', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9217', '8952', '13.65', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9217', '3928', '11.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9217', '7910', '2.12', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9217' WHERE entry='9217';

UPDATE `creature_template` SET spell1='16636', spell2='16144', spell3='16788', spell4='16785', spell5='15570', spell6='20477', spell7='14100' WHERE entry='10430';
DELETE FROM `skinning_loot_template` WHERE entry='10430';
INSERT INTO `skinning_loot_template` VALUES ('10430', '8170', '88.87', '1', '0', '1', '11');
INSERT INTO `skinning_loot_template` VALUES ('10430', '8171', '18.3', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10430', '12731', '5.13', '1', '0', '1', '1');
UPDATE `creature_template` SET skinloot='10430' WHERE entry='10430';

UPDATE `creature_template` SET spell1='16508', spell2='16509', spell3='15580' WHERE entry='10584';

UPDATE `creature_template` SET spell1='15284', spell2='16856', spell3='15615', spell4='15618', spell5='3391', spell6='16075', spell7='10966' WHERE entry='9237';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9237';
INSERT INTO `pickpocketing_loot_template` VALUES ('9237', '16885', '53.77', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9237', '5428', '50.37', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9237', '8952', '20.01', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9237', '8950', '18.31', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9237', '3928', '11.97', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9237', '7910', '1.03', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9237' WHERE entry='9237';

UPDATE `creature_template` SET spell1='15284', spell2='8269', spell3='16856', spell4='15589', spell5='13736' WHERE entry='10429';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10429';
INSERT INTO `pickpocketing_loot_template` VALUES ('10429', '12587', '71.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10429', '18102', '71.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10429', '27854', '14.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10429', '29569', '14.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10429', '29570', '14.29', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10429' WHERE entry='10429';

UPDATE `creature_template` SET spell1='15582', spell2='12540', spell3='6434' WHERE entry='10318';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10318';
INSERT INTO `pickpocketing_loot_template` VALUES ('10318', '5428', '45.79', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10318', '16885', '43.85', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10318', '8950', '21.52', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10318', '8952', '16.67', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10318', '3928', '16.18', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10318', '7910', '0.49', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10318' WHERE entry='10318';

UPDATE `creature_template` SET spell1='16637' WHERE entry='10742';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10742';
INSERT INTO `pickpocketing_loot_template` VALUES ('10742', '5428', '64.15', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10742', '16885', '50.94', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10742', '8950', '24.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10742', '3928', '20.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10742', '8952', '20.75', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10742' WHERE entry='10742';

UPDATE `creature_template` SET spell1='16247', spell2='12739', spell3='7068' WHERE entry='9817';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9817';
INSERT INTO `pickpocketing_loot_template` VALUES ('9817', '5428', '49.23', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9817', '16885', '47.67', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9817', '8952', '19.19', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9817', '8950', '16.62', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9817', '3928', '12.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9817', '7910', '1.43', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9817' WHERE entry='9817';

UPDATE `creature_template` SET spell1='6253', spell2='16172', spell3='15580' WHERE entry='10317';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10317';
INSERT INTO `pickpocketing_loot_template` VALUES ('10317', '16885', '48.9', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10317', '5428', '42.47', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10317', '8952', '17.47', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10317', '3928', '15.06', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10317', '8950', '13.96', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10317', '7910', '2.41', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10317' WHERE entry='10317';

UPDATE `creature_template` SET spell1='16045', spell2='15580' WHERE entry='10316';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10316';
INSERT INTO `pickpocketing_loot_template` VALUES ('10316', '5428', '50', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10316', '16885', '44.59', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10316', '8952', '19.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10316', '8950', '18.47', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10316', '3928', '13.51', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10316', '7910', '2.7', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10316' WHERE entry='10316';

UPDATE `creature_template` SET spell1='15655', spell2='15062' WHERE entry='10319';
DELETE FROM `pickpocketing_loot_template` WHERE entry='10319';
INSERT INTO `pickpocketing_loot_template` VALUES ('10319', '16885', '47.61', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10319', '5428', '46.2', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10319', '8952', '19.35', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10319', '8950', '18.64', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10319', '3928', '12.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10319', '7910', '1.94', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10319' WHERE entry='10319';

UPDATE `creature_template` SET spell1='12466', spell2='15532', spell3='15794', spell4='15792' WHERE entry='9818';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9818';
INSERT INTO `pickpocketing_loot_template` VALUES ('9818', '5428', '48.2', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9818', '16885', '47.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9818', '8952', '19.69', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9818', '8950', '15.6', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9818', '3928', '11.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9818', '7910', '1.06', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9818' WHERE entry='9818';

DELETE FROM `pickpocketing_loot_template` WHERE entry='10762';
INSERT INTO `pickpocketing_loot_template` VALUES ('10762', '16885', '42.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10762', '5428', '39.38', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10762', '8950', '20.35', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10762', '8952', '16.81', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10762', '3928', '10.62', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10762' WHERE entry='10762';

UPDATE `creature_template` SET spell1='11972', spell2='15749', spell3='87081' WHERE entry='9819';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9819';
INSERT INTO `pickpocketing_loot_template` VALUES ('9819', '5428', '49.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9819', '16885', '47.1', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9819', '8952', '19.23', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9819', '8950', '16.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9819', '3928', '11.79', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9819', '7910', '1.37', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9819' WHERE entry='9819';

UPDATE `creature_template` SET spell1='13748', spell2='15744', spell3='15743' WHERE entry='9693';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9693';
INSERT INTO `pickpocketing_loot_template` VALUES ('9693', '5428', '47.16', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9693', '16885', '46.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9693', '8952', '17.9', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9693', '8950', '16.71', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9693', '3928', '11.69', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9693', '7910', '1.34', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9693' WHERE entry='9693';

UPDATE `creature_template` SET spell1='15496', spell2='15572' WHERE entry='9692';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9692';
INSERT INTO `pickpocketing_loot_template` VALUES ('9692', '5428', '48.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9692', '16885', '46.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9692', '8952', '18.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9692', '8950', '16', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9692', '3928', '11.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9692', '7910', '1.24', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9692' WHERE entry='9692';

UPDATE `creature_template` SET spell1='15791', spell2='15532', spell3='15734' WHERE entry='9717';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9717';
INSERT INTO `pickpocketing_loot_template` VALUES ('9717', '5428', '46.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9717', '16885', '45.11', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9717', '8952', '18.37', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9717', '8950', '15.86', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9717', '3928', '10.94', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9717', '7910', '1.31', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9717' WHERE entry='9717';

UPDATE `creature_template` SET spell1='15615', spell2='15618' WHERE entry='9583';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9583';
INSERT INTO `pickpocketing_loot_template` VALUES ('9583', '5428', '47.01', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9583', '16885', '46.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9583', '8952', '18.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9583', '8950', '16.72', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9583', '3928', '11.32', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9583', '7910', '1.12', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9583' WHERE entry='9583';

UPDATE `creature_template` SET spell1='8269', spell2='10966' WHERE entry='9716';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9716';
INSERT INTO `pickpocketing_loot_template` VALUES ('9716', '5428', '45.81', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9716', '16885', '44.88', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9716', '8952', '19.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9716', '8950', '16.37', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9716', '3928', '11.53', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9716', '7910', '1.15', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9716' WHERE entry='9716';

DELETE FROM `creature_loot_template` WHERE entry='9696';
INSERT INTO `creature_loot_template` VALUES ('9696', '12203', '56.85', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('9696', '12208', '56.1', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('9696', '3299', '34.7', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('9696', '33547', '14.16', '1', '0', '1', '1');
INSERT INTO `creature_loot_template` VALUES ('9696', '8146', '7.31', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='9696' WHERE entry='9696';
DELETE FROM `skinning_loot_template` WHERE entry='9696';
INSERT INTO `skinning_loot_template` VALUES ('9696', '8170', '95.83', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('9696', '4304', '11.94', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('9696', '8171', '5.91', '1', '0', '1', '5');
UPDATE `creature_template` SET skinloot='9696' WHERE entry='9696';

DELETE FROM `skinning_loot_template` WHERE entry='10221';
INSERT INTO `skinning_loot_template` VALUES ('10221', '8170', '58.82', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10221', '4304', '45.67', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10221', '8171', '4.54', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10221', '8169', '3.24', '1', '0', '1', '5');
UPDATE `creature_template` SET skinloot='10221' WHERE entry='10221';

DELETE FROM `skinning_loot_template` WHERE entry='10221';
INSERT INTO `skinning_loot_template` VALUES ('10221', '8170', '58.82', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10221', '4304', '45.67', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10221', '8171', '4.54', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10221', '8169', '3.24', '1', '0', '1', '5');
UPDATE `creature_template` SET skinloot='10221' WHERE entry='10221';
DELETE FROM `skinning_loot_template` WHERE entry='10447';
INSERT INTO `skinning_loot_template` VALUES ('10447', '8170', '63.06', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10447', '15416', '8.27', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10447', '15414', '8.1', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10447', '15412', '7.87', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10447', '8165', '7.63', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10447', '15415', '7.57', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10447', '4304', '5.44', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10447', '8171', '5.42', '1', '0', '1', '6');
UPDATE `creature_template` SET skinloot='10447' WHERE entry='10447';

UPDATE `creature_template` SET spell1='11428', spell2='16856', spell3='15580' WHERE entry='10814';
DELETE FROM `skinning_loot_template` WHERE entry='10814';
INSERT INTO `skinning_loot_template` VALUES ('10814', '8170', '64.87', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10814', '15412', '8.32', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10814', '15414', '7.97', '1', '0', '1', '4');
INSERT INTO `skinning_loot_template` VALUES ('10814', '15416', '7.86', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10814', '15415', '7.78', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10814', '8165', '6.97', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10814', '8171', '5.5', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10814', '4304', '5.23', '1', '0', '1', '5');
UPDATE `creature_template` SET skinloot='10814' WHERE entry='10814';

UPDATE `creature_template` SET spell1='16250', spell2='16249', spell3='12167' WHERE entry='10442';
DELETE FROM `skinning_loot_template` WHERE entry='10442';
INSERT INTO `skinning_loot_template` VALUES ('10442', '8170', '83.02', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10442', '4304', '11.56', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10442', '8171', '5.48', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10442', '15414', '3.6', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10442', '15416', '3.57', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10442', '15412', '3.47', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10442', '15415', '3.44', '1', '0', '1', '6');
UPDATE `creature_template` SET skinloot='10442' WHERE entry='10442';

UPDATE `creature_template` SET spell1='16071', spell2='15090', spell3='15128', spell4='12471', spell5='14887' WHERE entry='9261';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9261';
INSERT INTO `pickpocketing_loot_template` VALUES ('9261', '5428', '49.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9261', '16885', '47.2', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9261', '8952', '21.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9261', '8950', '17.27', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9261', '3928', '12.08', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9261', '7910', '1.42', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9261' WHERE entry='9261';

UPDATE `creature_template` SET spell1='16071', spell2='15128', spell3='15728', spell4='15729' WHERE entry='9263';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9263';
INSERT INTO `pickpocketing_loot_template` VALUES ('9263', '16885', '50.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9263', '5428', '48.48', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9263', '8950', '17.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9263', '8952', '17.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9263', '3928', '12.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9263', '7910', '1.09', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9263' WHERE entry='9263';

UPDATE `creature_template` SET spell1='8269', spell2='15128', spell3='13737' WHERE entry='9259';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9259';
INSERT INTO `pickpocketing_loot_template` VALUES ('9259', '16885', '48.92', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9259', '5428', '48.83', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9259', '8952', '19.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9259', '8950', '16.85', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9259', '3928', '12.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9259', '7910', '1.41', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9259' WHERE entry='9259';

UPDATE `creature_template` SET spell1='12470', spell2='12466', spell3='12468', spell4='15128' WHERE entry='9262';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9262';
INSERT INTO `pickpocketing_loot_template` VALUES ('9262', '5428', '50.19', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9262', '16885', '48.3', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9262', '8952', '19.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9262', '8950', '16.73', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9262', '3928', '12.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9262', '7910', '1.42', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9262' WHERE entry='9262';

UPDATE `creature_template` SET spell1='3248', spell2='15128', spell3='11972' WHERE entry='9260';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9260';
INSERT INTO `pickpocketing_loot_template` VALUES ('9260', '16885', '50.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9260', '5428', '49.92', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9260', '8952', '18.27', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9260', '8950', '15.59', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9260', '3928', '12.45', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9260', '7910', '1.46', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9260' WHERE entry='9260';

UPDATE `creature_template` SET spell1='15096', spell2='15732', spell3='15128' WHERE entry='9264';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9264';
INSERT INTO `pickpocketing_loot_template` VALUES ('9264', '16885', '50.9', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9264', '5428', '50.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9264', '8952', '19.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9264', '8950', '16.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9264', '3928', '12.71', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9264', '7910', '1.46', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9264' WHERE entry='9264';

UPDATE `creature_template` SET spell1='16169', spell2='10101', spell3='16856' WHERE entry='10371';
DELETE FROM `skinning_loot_template` WHERE entry='10371';
INSERT INTO `skinning_loot_template` VALUES ('10371', '8170', '62.75', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10371', '15416', '27.82', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10371', '8165', '12.46', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10371', '8171', '5.82', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10371', '4304', '5.52', '1', '0', '1', '5');
UPDATE `creature_template` SET skinloot='10371' WHERE entry='10371';

UPDATE `creature_template` SET spell1='15284', spell2='15655', spell3='16145' WHERE entry='10366';
DELETE FROM `skinning_loot_template` WHERE entry='10366';
INSERT INTO `skinning_loot_template` VALUES ('10366', '8170', '63.42', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10366', '15416', '27.9', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10366', '8165', '11.07', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10366', '4304', '6.04', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10366', '8171', '5.32', '1', '0', '1', '5');
UPDATE `creature_template` SET skinloot='10366' WHERE entry='10366';

UPDATE `creature_template` SET spell1='12021', spell2='8269', spell3='15580', spell4='15572', spell5='3391' WHERE entry='9096';
DELETE FROM `skinning_loot_template` WHERE entry='9096';
INSERT INTO `skinning_loot_template` VALUES ('9096', '8170', '62.94', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('9096', '15416', '28.04', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('9096', '8165', '11.03', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('9096', '4304', '5.88', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('9096', '8171', '5.56', '1', '0', '1', '6');
UPDATE `creature_template` SET skinloot='9096' WHERE entry='9096';

UPDATE `creature_template` SET spell1='16144', spell2='16635', spell3='16168' WHERE entry='10372';
DELETE FROM `skinning_loot_template` WHERE entry='10372';
INSERT INTO `skinning_loot_template` VALUES ('10372', '8170', '62.98', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10372', '15416', '28.57', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10372', '8165', '11.89', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10372', '4304', '6.04', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('10372', '8171', '5.38', '1', '0', '1', '4');
UPDATE `creature_template` SET skinloot='10372' WHERE entry='10372';

UPDATE `creature_template` SET spell1='12470', spell2='15285', spell3='18399' WHERE entry='10083';
DELETE FROM `skinning_loot_template` WHERE entry='10083';
INSERT INTO `skinning_loot_template` VALUES ('10083', '8170', '61.94', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10083', '15416', '28.11', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10083', '8165', '11.27', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10083', '4304', '5.88', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10083', '8171', '5.6', '1', '0', '1', '5');
UPDATE `creature_template` SET skinloot='10083' WHERE entry='10083';

UPDATE `creature_template` SET spell1='15580', spell2='15572' WHERE entry='10258';
DELETE FROM `skinning_loot_template` WHERE entry='10258';
INSERT INTO `skinning_loot_template` VALUES ('10258', '8170', '61.91', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10258', '15416', '26.98', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10258', '8165', '11.21', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10258', '8171', '5.99', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10258', '4304', '5.52', '1', '0', '1', '6');
UPDATE `creature_template` SET skinloot='10258' WHERE entry='10258';

UPDATE `creature_template` SET spell1='15746', spell2='15580', spell3='15572' WHERE entry='10683';
DELETE FROM `skinning_loot_template` WHERE entry='10683';
INSERT INTO `skinning_loot_template` VALUES ('10683', '8170', '60.97', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('10683', '15416', '28.74', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10683', '8165', '11.52', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('10683', '4304', '5.54', '1', '0', '1', '4');
INSERT INTO `skinning_loot_template` VALUES ('10683', '8171', '5.42', '1', '0', '1', '4');
UPDATE `creature_template` SET skinloot='10683' WHERE entry='10683';

UPDATE `creature_template` SET spell1='12039', spell2='8362', spell3='14032' WHERE entry='9045';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9045';
INSERT INTO `pickpocketing_loot_template` VALUES ('9045', '16885', '52.12', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9045', '5428', '51.68', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9045', '8952', '20.31', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9045', '8950', '17.83', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9045', '3928', '12.8', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9045', '7910', '1.46', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9045' WHERE entry='9045';

UPDATE `creature_template` SET spell1='15496', spell2='11972' WHERE entry='9097';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9097';
INSERT INTO `pickpocketing_loot_template` VALUES ('9097', '16885', '51.07', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9097', '5428', '50.28', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9097', '8952', '20.46', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9097', '8950', '17.39', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9097', '3928', '12.55', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9097', '7910', '1.46', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9097' WHERE entry='9097';

UPDATE `creature_template` SET spell1='14030', spell2='12057' WHERE entry='9258';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9258';
INSERT INTO `pickpocketing_loot_template` VALUES ('9258', '5428', '51.73', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9258', '16885', '50.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9258', '8952', '20.89', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9258', '8950', '17.75', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9258', '3928', '13.46', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9258', '7910', '1.44', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9258' WHERE entry='9258';

UPDATE `creature_template` SET spell1='13748', spell2='15122', spell3='14033', spell4='15123' WHERE entry='9098';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9098';
INSERT INTO `pickpocketing_loot_template` VALUES ('9098', '16885', '51.85', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9098', '5428', '51.61', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9098', '8952', '20.13', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9098', '8950', '17.31', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9098', '3928', '12.64', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9098', '7910', '1.21', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9098' WHERE entry='9098';

UPDATE `creature_template` SET spell1='15125', spell2='12471' WHERE entry='9257';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9257';
INSERT INTO `pickpocketing_loot_template` VALUES ('9257', '5428', '49.52', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9257', '16885', '48.62', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9257', '8952', '20.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9257', '8950', '17.03', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9257', '3928', '11.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9257', '7910', '1.6', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9257' WHERE entry='9257';

DELETE FROM `pickpocketing_loot_template` WHERE entry='9416';
INSERT INTO `pickpocketing_loot_template` VALUES ('9416', '16885', '61.01', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9416', '5428', '49.69', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9416', '8952', '22.01', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9416', '3928', '20.13', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9416', '8950', '13.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9416', '7910', '1.26', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9416' WHERE entry='9416';
DELETE FROM `skinning_loot_template` WHERE entry='9416';
INSERT INTO `skinning_loot_template` VALUES ('9416', '8170', '57.85', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('9416', '4304', '47.73', '1', '0', '1', '7');
INSERT INTO `skinning_loot_template` VALUES ('9416', '8171', '4.98', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('9416', '8169', '3.41', '1', '0', '1', '5');
UPDATE `creature_template` SET skinloot='9416' WHERE entry='9416';

UPDATE `creature_template` SET spell1='11428', spell2='3391', spell3='15795' WHERE entry='9267';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9267';
INSERT INTO `pickpocketing_loot_template` VALUES ('9267', '5428', '50.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9267', '16885', '49.59', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9267', '8952', '20.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9267', '8950', '17.51', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9267', '3928', '12.36', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9267', '7910', '1.47', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9267' WHERE entry='9267';

UPDATE `creature_template` SET spell1='8269', spell2='19643', spell3='13446' WHERE entry='9268';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9268';
INSERT INTO `pickpocketing_loot_template` VALUES ('9268', '5428', '50.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9268', '16885', '47.5', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9268', '8952', '19.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9268', '8950', '16.87', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9268', '3928', '11.71', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9268', '7910', '1.59', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9268' WHERE entry='9268';

UPDATE `creature_template` SET spell1='16001', spell2='6016', spell3='15795' WHERE entry='9241';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9241';
INSERT INTO `pickpocketing_loot_template` VALUES ('9241', '16885', '61.19', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9241', '5428', '55.91', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9241', '8952', '20.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9241', '8950', '19.89', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9241', '3928', '12.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9241', '7910', '1.65', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9241' WHERE entry='9241';

UPDATE `creature_template` SET spell1='15799', spell2='16006' WHERE entry='9239';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9239';
INSERT INTO `pickpocketing_loot_template` VALUES ('9239', '5428', '50.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9239', '16885', '50.87', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9239', '8952', '20.23', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9239', '8950', '17.35', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9239', '3928', '12.82', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9239', '7910', '1.18', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9239' WHERE entry='9239';

UPDATE `creature_template` SET spell1='12492', spell2='15801', spell3='13585', spell4='15802' WHERE entry='9269';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9269';
INSERT INTO `pickpocketing_loot_template` VALUES ('9269', '16885', '55.3', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9269', '5428', '53.11', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9269', '8952', '20', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9269', '8950', '18.49', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9269', '3928', '12.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9269', '7910', '1.44', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9269' WHERE entry='9269';

UPDATE `creature_template` SET spell1='15582', spell2='12540', spell3='76583' WHERE entry='9265';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9265';
INSERT INTO `pickpocketing_loot_template` VALUES ('9265', '5428', '52.41', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9265', '16885', '47.81', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9265', '8952', '20.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9265', '8950', '17.02', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9265', '3928', '13.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9265', '7910', '1.54', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9265' WHERE entry='9265';

UPDATE `creature_template` SET spell1='15090', spell2='11641', spell3='14033' WHERE entry='9240';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9240';
INSERT INTO `pickpocketing_loot_template` VALUES ('9240', '5428', '50.13', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9240', '16885', '49.27', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9240', '8952', '19.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9240', '8950', '17.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9240', '3928', '12.3', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9240', '7910', '1.54', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9240' WHERE entry='9240';

UPDATE `creature_template` SET spell1='8262', spell2='15867', spell3='15869' WHERE entry='9266';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9266';
INSERT INTO `pickpocketing_loot_template` VALUES ('9266', '16885', '55.67', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9266', '5428', '52.79', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9266', '8952', '20.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9266', '8950', '19.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9266', '3928', '13.71', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9266', '7910', '1.74', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9266' WHERE entry='9266';

DELETE FROM `creature_loot_template` WHERE entry='10177';
INSERT INTO `creature_loot_template` VALUES ('10177', '56204', '105.91', '1', '0', '1', '1');
UPDATE `creature_template` SET lootid='10177' WHERE entry='10177';

DELETE FROM `skinning_loot_template` WHERE entry='9701';
INSERT INTO `skinning_loot_template` VALUES ('9701', '8170', '50.49', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('9701', '15408', '46.66', '1', '0', '1', '6');
INSERT INTO `skinning_loot_template` VALUES ('9701', '4304', '11.89', '1', '0', '1', '5');
INSERT INTO `skinning_loot_template` VALUES ('9701', '8169', '5.47', '1', '0', '1', '5');
UPDATE `creature_template` SET skinloot='9701' WHERE entry='9701';

UPDATE `creature_template` SET spell1='16104', spell2='16103' WHERE entry='10374';

UPDATE `creature_template` SET spell1='16170', spell2='15305' WHERE entry='9197';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9197';
INSERT INTO `pickpocketing_loot_template` VALUES ('9197', '5428', '47.39', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9197', '16885', '45.44', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9197', '8952', '18.15', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9197', '8950', '15.86', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9197', '3928', '12.12', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9197', '7910', '1.25', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9197' WHERE entry='9197';

UPDATE `creature_template` SET spell1='15976', spell2='14516' WHERE entry='9199';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9199';
INSERT INTO `pickpocketing_loot_template` VALUES ('9199', '5428', '49.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9199', '16885', '46.33', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9199', '8952', '18.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9199', '8950', '17.41', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9199', '3928', '12.58', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9199', '7910', '1.48', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9199' WHERE entry='9199';

UPDATE `creature_template` SET spell1='15659', spell2='8435', spell3='15982', spell4='15981' WHERE entry='9198';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9198';
INSERT INTO `pickpocketing_loot_template` VALUES ('9198', '5428', '48.44', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9198', '16885', '47.99', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9198', '8952', '18.6', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9198', '8950', '17.49', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9198', '3928', '11.87', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9198', '7910', '1.17', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9198' WHERE entry='9198';

UPDATE `creature_template` SET spell1='15979', spell2='6742', spell3='13747' WHERE entry='9201';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9201';
INSERT INTO `pickpocketing_loot_template` VALUES ('9201', '5428', '48.5', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9201', '16885', '47.76', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9201', '8952', '19.67', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9201', '8950', '15.59', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9201', '3928', '12.27', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9201', '7910', '1.17', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9201' WHERE entry='9201';

UPDATE `creature_template` SET spell1='15284', spell2='11876' WHERE entry='9200';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9200';
INSERT INTO `pickpocketing_loot_template` VALUES ('9200', '5428', '47.65', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9200', '16885', '47.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9200', '8952', '19.54', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9200', '8950', '17.66', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9200', '3928', '11.42', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9200', '7910', '1.59', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9200' WHERE entry='9200';

UPDATE `creature_template` SET spell1='16171', spell2='8269' WHERE entry='9216';
DELETE FROM `pickpocketing_loot_template` WHERE entry='9216';
INSERT INTO `pickpocketing_loot_template` VALUES ('9216', '5428', '47.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9216', '16885', '46.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9216', '8952', '17.98', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9216', '8950', '16.24', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9216', '3928', '11.41', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('9216', '7910', '1.53', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='9216' WHERE entry='9216';

UPDATE `creature_template` SET spell1='16247', spell2='12739', spell3='7068' WHERE entry='10680';

UPDATE `creature_template` SET spell1='11972', spell2='15749', spell3='87081' WHERE entry='10681';

UPDATE `creature_template` SET spell1='15976', spell2='14516' WHERE entry='10601';

UPDATE `creature_template` SET spell1='15979', spell2='6742', spell3='13747' WHERE entry='10602';
