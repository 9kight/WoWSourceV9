UPDATE `creature_template` SET spell1='88308', spell2='88357' WHERE entry='43873';
DELETE FROM `pickpocketing_loot_template` WHERE entry='43873';
INSERT INTO `pickpocketing_loot_template` VALUES ('43873', '67495', '10.71', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='43873' WHERE entry='43873';
DELETE FROM `skinning_loot_template` WHERE entry='43873';
INSERT INTO `skinning_loot_template` VALUES ('43873', '52976', '76.2', '1', '0', '1', '10');
INSERT INTO `skinning_loot_template` VALUES ('43873', '52979', '43.05', '1', '0', '1', '7');
UPDATE `creature_template` SET skinloot='43873' WHERE entry='43873';

UPDATE `creature_template` SET spell1='87622', spell2='87618', spell3='86930', spell4='86911' WHERE entry='43875';

UPDATE `creature_template` SET spell1='86331', spell2='86340' WHERE entry='43878';

UPDATE `creature_template` SET spell1='88061', spell2='88058', spell3='88055', spell4='88056' WHERE entry='45915';

UPDATE `creature_template` SET spell1='88073', spell2='88075' WHERE entry='45917';

UPDATE `creature_template` SET spell1='88182', spell2='88184', spell3='88186' WHERE entry='45922';

UPDATE `creature_template` SET spell1='78660', spell2='87761', spell3='87759', spell4='76622' WHERE entry='45928';

UPDATE `creature_template` SET spell1='87933', spell2='87930', spell3='87923' WHERE entry='45477';

UPDATE `creature_template` SET spell1='89105', spell2='85467' WHERE entry='45704';

UPDATE `creature_template` SET spell1='87762', spell2='87768' WHERE entry='45930';

UPDATE `creature_template` SET spell1='87771', spell2='58127', spell3='87772' WHERE entry='45926';

UPDATE `creature_template` SET spell1='87854' WHERE entry='52019';

UPDATE `creature_template` SET spell1='87854' WHERE entry='45932';

UPDATE `creature_template` SET spell1='87780', spell2='87779', spell3='88959' WHERE entry='45935';

UPDATE `creature_template` SET spell1='88175', spell2='88170', spell3='88171' WHERE entry='45924';

UPDATE `creature_template` SET spell1='88080' WHERE entry='47238';

UPDATE `creature_template` SET spell1='88010', spell2='88032', spell3='88029' WHERE entry='45912';

UPDATE `creature_template` SET spell1='88192', spell2='88194', spell3='88201' WHERE entry='45919';
DELETE FROM `skinning_loot_template` WHERE entry='45919';
INSERT INTO `skinning_loot_template` VALUES ('45919', '52976', '77.23', '1', '0', '1', '10');
INSERT INTO `skinning_loot_template` VALUES ('45919', '52979', '46.06', '1', '0', '1', '8');
UPDATE `creature_template` SET skinloot='45919' WHERE entry='45919';
