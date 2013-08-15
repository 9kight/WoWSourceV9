-- orgrimmar and deathknell + brill and razor hill, vengeance landing small adjustments waypoints missing add and creature text

SET @Frezza := 9564;
DELETE FROM `creature_text` WHERE `entry`=@Frezza;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Frezza,0,0, 'The zeppelin to Undercity has  just arrived! All aboard for Tirisfal Glades!',12,0,100,412,0,6941, 'Frezza');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Frezza;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Frezza AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Frezza, 0, 0, 0, 1, 0, 100, 0, 0, 0, 120000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Frezza - Random Say');

SET @SnurkB := 12136;
DELETE FROM `creature_text` WHERE `entry`=@SnurkB;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SnurkB,0,0, 'The zeppelin to Grom"gol has  just arrived! All aboard for Stranglethorn!',12,0,100,412,0,6941, 'SnurkB');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@SnurkB;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SnurkB AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@SnurkB, 0, 0, 0, 1, 0, 100, 0, 0, 0, 120000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SnurkB - Random Say');

SET @GremR := 26537;
DELETE FROM `creature_text` WHERE `entry`=@GremR;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@GremR,0,0, 'The zeppelin to Warsong Hold has  just arrived! All aboard for Borean Tundra!',12,0,100,412,0,6941, 'GremR');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@GremR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GremR AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GremR, 0, 0, 0, 1, 0, 100, 0, 0, 0, 120000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'GremR - Random Say');

SET @ZelliH := 34765;
DELETE FROM `creature_text` WHERE `entry`=@ZelliH;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ZelliH,0,0, 'The zeppelin to Thunder Bluff has  just arrived! All aboard for a smooth ride across the  Barrens!',12,0,100,412,0,6941, 'ZelliH');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ZelliH;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ZelliH AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ZelliH, 0, 0, 0, 1, 0, 100, 0, 0, 0, 120000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ZelliH - Random Say');

SET @ZAPETTA := 9566;
DELETE FROM `creature_text` WHERE `entry`=@ZAPETTA;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ZAPETTA,0,0, 'The zeppelin to Orgrimmar has  just arrived! All aboard for Durotar!',12,0,100,412,0,6941, 'ZAPETTA');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ZAPETTA;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ZAPETTA AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ZAPETTA, 0, 0, 0, 1, 0, 100, 0, 0, 0, 120000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'ZAPETTA - Random Say');

SET @HinDenburg := 3150;
DELETE FROM `creature_text` WHERE `entry`=@HinDenburg;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@HinDenburg,0,0, 'The zeppelin to Grom"gol has  just arrived! All aboard for Stranglethorn!',12,0,100,412,0,6941, 'HinDenburg');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@HinDenburg;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@HinDenburg AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@HinDenburg, 0, 0, 0, 1, 0, 100, 0, 0, 0, 120000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'HinDenburg - Random Say');

SET @MeefiFarthrottle := 26539;
DELETE FROM `creature_text` WHERE `entry`=@MeefiFarthrottle;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@MeefiFarthrottle,0,0, 'The zeppelin to Vengeance Landing has  just arrived! All aboard for Howling Fjord!',12,0,100,412,0,6941, 'MeefiFarthrottle');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@MeefiFarthrottle;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MeefiFarthrottle AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@MeefiFarthrottle, 0, 0, 0, 1, 0, 100, 0, 0, 0, 120000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'MeefiFarthrottle - Random Say');

SET @DrenkSpannerspark := 26540;
DELETE FROM `creature_text` WHERE `entry`=@DrenkSpannerspark;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@DrenkSpannerspark,0,0, 'The zeppelin to Undercity has  just arrived! All aboard for Tirisfal Glades!',12,0,100,412,0,6941, 'DrenkSpannerspark');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@DrenkSpannerspark;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DrenkSpannerspark AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@DrenkSpannerspark, 0, 0, 0, 1, 0, 100, 0, 0, 0, 120000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'DrenkSpannerspark - Random Say');

DELETE FROM `creature_template` WHERE `entry`=60322 LIMIT 1;
INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 60322, 0, 0, 0, 0, 0, 4449, 0, 0, 0, "Fizzle", "Dhugru Gorelust's Pet", "", 0, 37, 37, 0, 85, 85, 0, 1.0, 1.0, 1.0, 0, 58, 72, 0, 18, 1.0, 2000, 2000, 8, 0, 2048, 0, 0, 0, 0, 0, 58, 72, 18, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "NullAI", 0, 3, 1.5186, 0.7267, 1.0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "", "12340");

DELETE FROM creature_template_addon WHERE entry IN (1736,1739,1741);
INSERT INTO `creature_template_addon` VALUES ('1736', '0', '0', '0', '257', '0', '');
INSERT INTO `creature_template_addon` VALUES ('1739', '0', '0', '0', '257', '0', '');
INSERT INTO `creature_template_addon` VALUES ('1741', '0', '0', '0', '257', '0', '');

DELETE FROM creature_addon WHERE guid=45928;
INSERT INTO `creature_addon` VALUES ('45928', '4912900', '0', '50331648', '1', '0', '');
INSERT INTO `waypoint_data` VALUES ('4912900', '1', '1724.14', '1678.18', '130.253', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '2', '1723.62', '1676.63', '130.269', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '3', '1723.03', '1675.23', '130.267', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '4', '1721.65', '1672.02', '130.324', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '5', '1720.27', '1668.8', '130.536', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '6', '1718.89', '1665.58', '130.638', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '7', '1717.93', '1663.34', '130.428', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '8', '1714.06', '1664.4', '131.087', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '9', '1714.28', '1667.5', '131.761', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '10', '1715.23', '1671.94', '131.767', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '11', '1715.7', '1675.29', '131.982', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '12', '1716.13', '1678.88', '132.441', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '13', '1716.51', '1682.36', '132.659', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '14', '1716.8', '1685.03', '132.749', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '15', '1717.14', '1687.57', '132.766', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '16', '1718.69', '1692.56', '132.082', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '17', '1719.58', '1694.21', '131.587', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '18', '1722.13', '1698.25', '130.081', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '19', '1723.63', '1699.71', '129.423', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '20', '1726.99', '1702.41', '128.356', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '21', '1731.06', '1703.17', '128.032', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '22', '1732.44', '1700.33', '127.485', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '23', '1731.61', '1696.81', '127.282', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '24', '1730.54', '1693.48', '127.519', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '25', '1729.33', '1690.2', '128.114', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '26', '1728.12', '1687.04', '128.891', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '27', '1726.79', '1683.81', '129.613', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('4912900', '28', '1725.69', '1681.11', '129.964', '0', '0', '0', '0', '100', '0', '0');

DELETE FROM creature_addon WHERE guid=63965;
INSERT INTO `creature_addon` VALUES ('63965', '63965', '0', '0', '0', '0', '');
INSERT INTO `waypoint_data` VALUES ('63965', '1', '1843.16', '1632.61', '96.9336', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '2', '1843.15', '1630.62', '96.9336', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '3', '1843.15', '1628.88', '96.9336', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '4', '1843.16', '1627.24', '96.9336', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '5', '1843.19', '1624.44', '96.9336', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '6', '1843.21', '1621.29', '96.9336', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '7', '1843.24', '1615.93', '96.9336', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '8', '1843.22', '1614.18', '96.9386', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '9', '1843.15', '1611.15', '96.7869', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '10', '1843.14', '1610.68', '96.5972', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '11', '1843.08', '1608.58', '95.6838', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '12', '1842.95', '1603.57', '94.5521', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '13', '1842.86', '1600.07', '94.5489', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '14', '1842.81', '1598.32', '94.2699', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '15', '1842.75', '1596.1', '93.9496', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '16', '1842.67', '1592.95', '93.5038', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '17', '1842.67', '1592.95', '93.5038', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '18', '1842.72', '1587.83', '93.3735', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '19', '1844.69', '1587.51', '93.2601', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '20', '1845.73', '1587.39', '93.2098', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '21', '1849.46', '1587.19', '93.1518', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '22', '1854.23', '1586.91', '92.9252', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '23', '1858.38', '1586.27', '92.675', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '24', '1859.19', '1584.59', '92.7546', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '25', '1860.21', '1582.1', '92.9085', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '26', '1860.4', '1580.36', '93.1907', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '27', '1860.48', '1578.85', '94.1212', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '28', '1860.83', '1573.62', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '29', '1861.72', '1570.62', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '30', '1862.18', '1569.94', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '31', '1865.74', '1568.88', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '32', '1867.71', '1568.67', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '33', '1869.45', '1568.85', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '34', '1871.32', '1569.8', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '35', '1870.79', '1571.34', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '36', '1869.75', '1572.27', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '37', '1867.56', '1572.64', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '38', '1866.05', '1572.8', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '39', '1863.25', '1573.54', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '40', '1860.83', '1575.83', '94.3135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '41', '1860.8', '1578.37', '94.1896', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '42', '1860.95', '1579.76', '93.6303', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '43', '1862.45', '1581.33', '92.9659', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '44', '1864.13', '1583.42', '92.2196', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '45', '1865.07', '1584.76', '91.9799', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '46', '1865.84', '1585.94', '91.8331', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '47', '1867.9', '1588.88', '91.5271', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '48', '1866.53', '1589.53', '91.769', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '49', '1862.34', '1590.55', '92.3317', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '50', '1856.31', '1591.09', '92.852', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '51', '1854.1', '1591.1', '92.9768', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '52', '1846.44', '1591.6', '93.2416', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '53', '1844.18', '1595.34', '93.767', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '54', '1843.73', '1600.34', '94.5373', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '55', '1843.51', '1603.85', '94.5563', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '56', '1843.35', '1608.52', '95.6551', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '57', '1843.23', '1615.5', '96.9339', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '58', '1843.18', '1619', '96.9339', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '59', '1843.09', '1626', '96.9339', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '60', '1843.04', '1629.85', '96.9339', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('63965', '61', '1842.94', '1634.06', '96.9339', '0', '0', '0', '0', '100', '0', '0');

DELETE FROM creature_addon WHERE guid=64044;
INSERT INTO `creature_addon` VALUES ('64044', '64044', '0', '0', '0', '0', '');
INSERT INTO `waypoint_data` VALUES ('64044', '1', '1877.81', '1588.14', '90.3928', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '2', '1877.81', '1588.14', '90.3928', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '3', '1870.81', '1588.16', '91.2537', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '4', '1865.81', '1588.43', '91.7959', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '5', '1862.32', '1588.79', '92.2594', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '6', '1858.84', '1589.14', '92.5987', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '7', '1852.81', '1589.69', '92.9232', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '8', '1848.96', '1589.93', '93.1455', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '9', '1844.07', '1590.16', '93.2807', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '10', '1840.57', '1590.27', '93.4899', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '11', '1835.44', '1590.44', '93.8577', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '12', '1830.55', '1590.77', '94.1806', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '13', '1827.07', '1591.09', '94.5899', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '14', '1822.07', '1591.38', '95.4266', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '15', '1818.57', '1591.56', '96.1179', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '16', '1813.8', '1591.86', '97.2249', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '17', '1810.31', '1592.16', '98.2251', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '18', '1806.83', '1592.46', '99.2303', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '19', '1803.34', '1592.77', '100.022', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '20', '1798.46', '1593.21', '101.236', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '21', '1794.98', '1593.62', '102.174', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '22', '1790.73', '1591.9', '103.574', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '23', '1793.27', '1589.76', '103.212', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '24', '1797.57', '1588.8', '101.885', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '25', '1799.08', '1588.83', '101.282', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '26', '1804.91', '1589', '99.7383', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '27', '1812.02', '1589.12', '97.593', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '28', '1815.05', '1588.85', '96.8174', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '29', '1820.38', '1588.24', '95.702', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '30', '1823.75', '1588.08', '95.2152', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '31', '1830.74', '1587.74', '94.2571', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '32', '1833.42', '1587.63', '94.0095', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '33', '1839.37', '1587.58', '93.6335', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '34', '1842.87', '1587.59', '93.3707', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '35', '1849.17', '1587.74', '93.1166', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '36', '1852.67', '1587.84', '92.9392', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '37', '1856.17', '1587.93', '92.7417', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '38', '1859.67', '1588.03', '92.4746', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '39', '1865.14', '1588.16', '91.8722', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '40', '1868.64', '1588.17', '91.457', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '41', '1874.59', '1588.2', '90.7874', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('64044', '42', '1879.96', '1588.21', '90.156', '0', '0', '0', '0', '100', '0', '0');

DELETE FROM creature WHERE guid=320932;
INSERT INTO `creature` VALUES ('320932', '60322', '1', '14', '362', '1', '1', '0', '0', '354.7', '-4838.68', '10.9772', '2.13698', '300', '0', '0', '1473', '2079', '0', '0', '0', '0');
