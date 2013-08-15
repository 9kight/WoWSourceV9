-- Scarlet monastery mobs ability and  pickpocket
UPDATE `creature_template` SET spell1='7068' WHERE entry='6426';

UPDATE `creature_template` SET spell1='9438', spell2='34517', spell3='9435', spell4='13323', spell5='8988' WHERE entry='6487';

UPDATE `creature_template` SET spell1='5137', spell2='9373', spell3='7399' WHERE entry='6490';

UPDATE `creature_template` SET spell1='12470', spell2='23038', spell3='8814', spell4='20825' WHERE entry='4543';

UPDATE `creature_template` SET spell1='83264' WHERE entry='44637';

DELETE FROM `npc_vendor` WHERE entry='32641';
INSERT INTO `npc_vendor` VALUES ('32641', '0', '6532', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32641', '1', '3371', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32641', '2', '63388', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32641', '3', '38426', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32641', '4', '20815', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32641', '5', '39354', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32641', '6', '14341', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32641', '7', '4565', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32641', '9', '64670', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32641', '10', '39505', '0', '0', '0', '1');

UPDATE `creature_template` SET spell1='15496', spell2='77720' WHERE entry='6488';

UPDATE `creature_template` SET spell1='8986' WHERE entry='6427';

UPDATE `creature_template` SET spell1='15496', spell2='8269', spell3='8260', spell4='8989' WHERE entry='3975';

UPDATE `creature_template` SET spell1='8282', spell2='15090', spell3='22678', spell4='12039', spell5='11647', spell6='8399' WHERE entry='4542';
DELETE FROM `pickpocketing_loot_template` WHERE entry='4542';
INSERT INTO `pickpocketing_loot_template` VALUES ('4542', '16883', '77.78', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('4542', '5433', '35.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('4542', '4607', '24.44', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('4542', '1529', '2.22', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='4542' WHERE entry='4542';

UPDATE `creature_template` SET spell1='9256', spell2='7645', spell3='12039', spell4='25054', spell5='9481' WHERE entry='3977';
DELETE FROM `pickpocketing_loot_template` WHERE entry='3977';
INSERT INTO `pickpocketing_loot_template` VALUES ('3977', '16884', '21.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3977', '4601', '14.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3977', '4602', '14.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3977', '3928', '14.29', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3977', '1707', '7.14', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3977', '5432', '7.14', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='3977' WHERE entry='3977';

UPDATE `creature_template` SET spell1='77808', spell2='6742' WHERE entry='3974';

UPDATE `creature_template` SET spell1='9034', spell2='14032' WHERE entry='3983';

UPDATE `creature_template` SET spell1='21007', spell2='3815' WHERE entry='6489';
DELETE FROM `pickpocketing_loot_template` WHERE entry='6489';
INSERT INTO `pickpocketing_loot_template` VALUES ('6489', '4607', '60', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('6489', '5433', '40', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('6489', '3864', '20', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('6489', '16883', '20', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='6489' WHERE entry='6489';

DELETE FROM `npc_vendor` WHERE entry='32642';
INSERT INTO `npc_vendor` VALUES ('32642', '0', '44571', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '1', '35952', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '2', '33449', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '3', '44573', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '4', '33451', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '5', '44575', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '6', '44570', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '7', '33452', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '8', '33445', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '9', '35953', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '10', '35951', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '11', '33444', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '12', '159', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '13', '33454', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '14', '35948', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '15', '4470', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '16', '44574', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '17', '33443', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '18', '35947', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '19', '35950', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '20', '35954', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '21', '60335', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('32642', '22', '35949', '0', '0', '0', '1');

UPDATE `creature_template` SET spell1='12039', spell2='8362' WHERE entry='4303';

UPDATE `creature_template` SET spell1='11642', spell2='20820' WHERE entry='4296';

UPDATE `creature_template` SET spell1='7896', spell2='6660' WHERE entry='4288';

UPDATE `creature_template` SET spell1='31403' WHERE entry='4301';

UPDATE `creature_template` SET spell1='17143' WHERE entry='4302';

UPDATE `creature_template` SET spell1='22187', spell2='25058' WHERE entry='4299';

UPDATE `creature_template` SET spell1='14518', spell2='63148', spell3='77787', spell4='9257', spell5='8990' WHERE entry='3976';
DELETE FROM `pickpocketing_loot_template` WHERE entry='3976';
INSERT INTO `pickpocketing_loot_template` VALUES ('3976', '5432', '45.31', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3976', '16884', '34.38', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3976', '4601', '23.44', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3976', '3928', '15.63', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3976', '4602', '9.38', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3976', '3927', '7.81', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3976', '16883', '1.56', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('3976', '5431', '1.56', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='3976' WHERE entry='3976';

UPDATE `creature_template` SET spell1='20823', spell2='8985' WHERE entry='4297';

UPDATE `creature_template` SET spell1='3639', spell2='11972' WHERE entry='4298';

UPDATE `creature_template` SET spell1='20815', spell2='11981' WHERE entry='4291';

UPDATE `creature_template` SET spell1='18968', spell2='20815', spell3='20296' WHERE entry='4289';

UPDATE `creature_template` SET spell1='14517', spell2='77787' WHERE entry='4287';

UPDATE `creature_template` SET spell1='6713' WHERE entry='4290';

UPDATE `creature_template` SET spell1='76583', spell2='3391' WHERE entry='4540';

UPDATE `creature_template` SET spell1='8258', spell2='31713' WHERE entry='4292';

UPDATE `creature_template` SET spell1='9613', spell2='77773' WHERE entry='4293';

DELETE FROM `pickpocketing_loot_template` WHERE entry='4283';
INSERT INTO `pickpocketing_loot_template` VALUES ('4283', '16882', '8.94', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('4283', '5374', '4.95', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('4283', '4542', '1.62', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('4283', '422', '1.21', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('4283', '4538', '1.04', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('4283', '929', '1', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='4283' WHERE entry='4283';

UPDATE `creature_template` SET spell1='3639' WHERE entry='4286';

UPDATE `creature_template` SET spell1='8364', spell2='20819', spell3='6146' WHERE entry='4294';

UPDATE `creature_template` SET spell1='9275' WHERE entry='4306';

UPDATE `creature_template` SET spell1='34517', spell2='32749' WHERE entry='4300';
