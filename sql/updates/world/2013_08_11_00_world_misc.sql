DELETE FROM creature WHERE guid IN (157273,9211);

DELETE FROM creature_equip_template WHERE entry IN (45200,45201,45323);
INSERT INTO `creature_equip_template` VALUES ('45200', '1', '21553', '0', '0');
INSERT INTO `creature_equip_template` VALUES ('45201', '1', '14533', '0', '0');
INSERT INTO `creature_equip_template` VALUES ('45323', '1', '1910', '0', '0');

UPDATE creature_template SET equipment_id=45200 WHERE entry=45200;
UPDATE creature_template SET equipment_id=45201 WHERE entry=45201;
UPDATE creature_template SET equipment_id=45323 WHERE entry=45323;

DELETE FROM creature WHERE guid in (320951,320952,320953);
INSERT INTO `creature` VALUES ('320951', '45325', '329', '2017', '2017', '1', '1', '0', '0', '3390.09', '-3383.13', '142.743', '0.0540076', '300', '0', '0', '42', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320952', '45200', '329', '2017', '2017', '1', '1', '0', '0', '3398.65', '-3374.73', '142.673', '3.16593', '300', '0', '0', '4200', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320953', '45201', '329', '2017', '2017', '1', '1', '0', '0', '3399.44', '-3384.84', '142.701', '3.10572', '300', '0', '0', '2100', '0', '0', '0', '0', '0');

UPDATE creature_template SET flags_extra=1 WHERE entry=8477;
