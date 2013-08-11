DELETE FROM creature WHERE guid IN (157273,9211);
DELETE FROM creature_equip_template WHERE entry IN (45200,45201,45323);
INSERT INTO `creature_equip_template` VALUES ('45200', '1', '21553', '0', '0');
INSERT INTO `creature_equip_template` VALUES ('45201', '1', '14533', '0', '0');
INSERT INTO `creature_equip_template` VALUES ('45323', '1', '1910', '0', '0');

UPDATE creature_template SET equipment_id=45200 WHERE entry=45200;
UPDATE creature_template SET equipment_id=45201 WHERE entry=45201;
UPDATE creature_template SET equipment_id=45323 WHERE entry=45323;

DELETE FROM creature WHERE guid in (320951,320952,320953,320954);
INSERT INTO `creature` VALUES ('320951', '45325', '329', '2017', '2017', '1', '1', '0', '0', '3390.09', '-3383.13', '142.743', '0.0540076', '300', '0', '0', '42', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320952', '45200', '329', '2017', '2017', '1', '1', '0', '0', '3398.65', '-3374.73', '142.673', '3.16593', '300', '0', '0', '4200', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320953', '45201', '329', '2017', '2017', '1', '1', '0', '0', '3399.44', '-3384.84', '142.701', '3.10572', '300', '0', '0', '2100', '0', '0', '0', '0', '0');

UPDATE creature_template SET flags_extra=1 WHERE entry=8477;


INSERT INTO `creature` VALUES ('320954', '10813', '329', '5916', '5916', '1', '1', '0', '0', '3423.39', '-3055.82', '136.498', '5.43897', '300', '0', '0', '19104', '9840', '0', '0', '0', '0');

UPDATE `creature_template` SET spell1='17405', spell2='80750', spell3='13704', spell4='17399', spell5='66290' WHERE entry='10813';

DELETE FROM `pickpocketing_loot_template` WHERE entry='10813';
INSERT INTO `pickpocketing_loot_template` VALUES ('10813', '3419', '48.65', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10813', '4608', '45.95', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10813', '16884', '32.43', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10813', '7909', '2.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10813', '7910', '2.7', '1', '0', '1', '1');
INSERT INTO `pickpocketing_loot_template` VALUES ('10813', '3928', '2.7', '1', '0', '1', '1');
UPDATE `creature_template` SET pickpocketloot='10813' WHERE entry='10813';

UPDATE `creature_template` SET `health_mod`=37.5, `mana_mod`=6  WHERE `entry`=10813;
