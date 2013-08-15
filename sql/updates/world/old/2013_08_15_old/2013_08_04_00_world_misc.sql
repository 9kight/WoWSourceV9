-- brill and undercity missing mobs and  corect level
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=33 WHERE `entry`=17051;
DELETE FROM creature WHERE guid IN (320877,320878,320879,320880,320881,320882,320883,320884,320885,320886,320887,320888,320889,320890,320891);
INSERT INTO `creature` VALUES ('320877', '1500', '0', '85', '159', '1', '1', '0', '1500', '2251.67', '297.308', '33.6875', '4.76286', '300', '0', '0', '328', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320878', '2311', '0', '85', '159', '1', '1', '0', '2311', '2263.31', '308.429', '33.3899', '5.66151', '300', '0', '0', '102', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320879', '36213', '0', '85', '153', '1', '1', '0', '36213', '1877.22', '230.404', '60.1345', '0.22463', '300', '0', '0', '105453', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320880', '36213', '0', '85', '153', '1', '1', '0', '36213', '1878.08', '245.437', '60.0024', '6.19671', '300', '0', '0', '105453', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320881', '36213', '0', '85', '85', '1', '1', '0', '36213', '1837.3', '232.334', '60.3412', '1.61544', '300', '0', '0', '105453', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320882', '36213', '0', '85', '85', '1', '1', '0', '36213', '1733.05', '224.351', '62.7942', '0.09931', '300', '0', '0', '105453', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320883', '36213', '0', '85', '85', '1', '1', '0', '36213', '1737.18', '238.991', '62.6666', '0.0986429', '300', '0', '0', '105453', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320884', '36213', '0', '85', '85', '1', '1', '0', '36213', '1837.56', '244.242', '60.2995', '4.84692', '300', '0', '0', '105453', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320885', '53590', '0', '85', '85', '1', '1', '0', '0', '1756.27', '262.636', '51.9778', '6.03606', '300', '0', '0', '42', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320886', '25974', '0', '1497', '1497', '1', '1', '0', '0', '1637.6', '226.6', '62.592', '1.26412', '300', '0', '0', '42', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320887', '36213', '0', '85', '85', '1', '1', '0', '36213', '1736.03', '253.933', '62.2322', '0.190499', '300', '0', '0', '105453', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320888', '53590', '0', '85', '85', '1', '1', '0', '0', '1757.8', '216.077', '52.0315', '0.314875', '300', '0', '0', '42', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320889', '36213', '0', '1497', '1497', '1', '1', '0', '36213', '1672.91', '234.655', '62.5965', '0.0650528', '300', '0', '0', '105453', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320890', '36213', '0', '1497', '1497', '1', '1', '0', '36213', '1672.95', '243.953', '62.5965', '6.2529', '300', '0', '0', '105453', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320891', '17051', '0', '1497', '1497', '1', '1', '0', '17051', '1644.05', '233.81', '62.592', '0.476319', '300', '0', '0', '42', '0', '0', '0', '0', '0');

-- orgrimmar missing vendos and delete duplicates
-- vendors Jamus and Gunra are not duplicates  , we split in 2 vendors the huge amount of items so it will be all so i rename them (name-name1) for  same npc's 
DELETE FROM creature WHERE guid=301077;
DELETE FROM creature WHERE guid IN (320891,320892,320893,320894,320895);
INSERT INTO `creature` VALUES ('320892', '52034', '1', '1637', '5356', '1', '3969', '0', '0', '1652.32', '-4345.17', '64.5366', '0.0491524', '300', '0', '0', '2614', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320893', '46555', '1', '1637', '5356', '1', '3969', '0', '46555', '1651.99', '-4348.68', '64.5366', '0.44556', '300', '0', '0', '2614', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320908', '60000', '1', '1637', '5356', '1', '3969', '0', '46555', '1651.99', '-4348.68', '64.5366', '0.44556', '300', '0', '0', '2614', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320894', '60001', '1', '1637', '5356', '1', '3969', '0', '46556', '1655.96', '-4355.28', '64.5366', '0.55595', '300', '0', '0', '2614', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320895', '52037', '1', '1637', '5356', '1', '3969', '0', '0', '1653.61', '-4352.15', '64.5366', '0.445558', '300', '0', '0', '1830', '5013', '0', '0', '0', '0');
DELETE FROM creature WHERE guid=139443;
UPDATE `creature_template` SET `minlevel`=65,`maxlevel`=65 WHERE `entry`=52549;
UPDATE `creature_template` SET `minlevel`=85,`maxlevel`=85 WHERE `entry`=52549;
UPDATE `creature_template` SET `exp`=3 WHERE `entry`=52549;
DELETE FROM creature WHERE guid IN (320896,320897,320898,320899,320900,320901,320902,320903,320904,320905,320906,320907,320908,320909);
INSERT INTO `creature` VALUES ('320896', '52033', '1', '1637', '1637', '1', '3969', '0', '0', '1652.49', '-4182.98', '55.0235', '6.11554', '300', '0', '0', '2614', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320897', '12788', '1', '1637', '5169', '1', '3969', '0', '12788', '1656.91', '-4163.16', '56.0282', '4.87614', '300', '0', '0', '6474', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320898', '54658', '1', '1637', '5169', '1', '3969', '0', '0', '1666.14', '-4165.32', '56.1625', '4.28404', '300', '0', '0', '7048', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320899', '54659', '1', '1637', '1637', '1', '3969', '0', '0', '1671.54', '-4169.24', '56.233', '4.1034', '300', '0', '0', '7048', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320900', '52549', '1', '1637', '1637', '1', '3969', '0', '0', '1676.04', '-4176.31', '56.2913', '3.76972', '300', '0', '0', '84', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320901', '46593', '1', '1637', '1637', '1', '3969', '0', '0', '1677.7', '-4182.81', '56.3077', '3.52385', '300', '0', '0', '9780', '14392', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320902', '46572', '1', '1637', '5170', '1', '3969', '0', '0', '1610.69', '-4349.35', '21.121', '2.60329', '300', '0', '0', '1848', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320903', '51195', '1', '1637', '5170', '1', '3969', '0', '0', '1616.46', '-4342.76', '21.121', '2.25705', '300', '0', '0', '1524', '0', '0', '0', '0', '0');
DELETE FROM creature WHERE guid=16777216;
UPDATE creature_template SET equipment_id=3296 WHERE entry=37869;
INSERT INTO `creature` VALUES ('320904', '40887', '1', '14', '4982', '1', '1', '0', '40887', '1288.07', '-4339.4', '34.0342', '0.16943', '300', '0', '0', '55713', '0', '0', '16777216', '0', '0');
INSERT INTO `creature` VALUES ('320905', '39379', '1', '14', '4982', '1', '1', '0', '0', '1287.11', '-4341.95', '34.0342', '0.299896', '300', '0', '0', '5571', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320906', '39380', '1', '14', '4982', '1', '1', '0', '0', '1286.21', '-4336.15', '34.0356', '0.309931', '300', '0', '0', '4457', '39676', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320907', '37869', '1', '14', '4982', '1', '1', '0', '0', '1295.02', '-4342.46', '34.0569', '3.08065', '300', '0', '0', '63', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320909', '46556', '1', '1637', '5356', '1', '3969', '0', '46556', '1655.96', '-4355.28', '64.5366', '0.55595', '300', '0', '0', '2614', '0', '0', '0', '0', '0');

DELETE FROM trinity_string WHERE entry=842; 
INSERT INTO `trinity_string` VALUES ('842', 'Text4.', null, null, null, null, null, null, null, null); 

UPDATE `creature_template` SET `equipment_id` = 40892 WHERE `entry` = 40892; 
DELETE FROM creature_equip_template WHERE entry=40892;
INSERT INTO `creature_equip_template` VALUES ('40892', '1', '2703', '0', '0');

UPDATE `creature_template` SET `equipment_id` = 40890 WHERE `entry` = 40890; 
DELETE FROM creature_equip_template WHERE entry=40890;
INSERT INTO `creature_equip_template` VALUES ('40890', '1', '12653', '0', '0');

-- nozzelport's outpost  delete duplicates and  fix pet master model id 
DELETE FROM creature WHERE guid IN (66177,125882,107382,125879,125883,125881,125884,125878);
UPDATE `creature_template` SET `modelid1`=7054,`modelid2`=7054 WHERE `entry`=43982;

-- crossroads duplicates delete
DELETE FROM creature WHERE guid IN (139345,107330,139347,139359,107867,138559,138580);

-- hunter hills duplicates delete and  add vendors items
DELETE FROM creature WHERE guid IN (101774,101315,138572,138577,101376,138593,138574,101437,138575,138569,102119,138570,138594);

DELETE FROM `npc_vendor` WHERE entry='44285';
INSERT INTO `npc_vendor` VALUES ('44285', '0', '3597', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44285', '1', '3598', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44285', '2', '203', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44285', '3', '201', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44285', '4', '202', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44285', '5', '200', '0', '0', '0', '1');

DELETE FROM `npc_vendor` WHERE entry='44385';
INSERT INTO `npc_vendor` VALUES ('44385', '0', '2528', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44385', '1', '2530', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44385', '2', '2531', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44385', '3', '2532', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44385', '4', '2534', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44385', '5', '2533', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44385', '6', '2535', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44385', '7', '2529', '0', '0', '0', '1');

DELETE FROM `npc_vendor` WHERE entry='44297';
INSERT INTO `npc_vendor` VALUES ('44297', '0', '4498', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44297', '1', '4541', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44297', '2', '4497', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44297', '3', '1179', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44297', '4', '1205', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44297', '5', '4542', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44297', '6', '159', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44297', '7', '4470', '0', '0', '0', '1');

DELETE FROM `npc_vendor` WHERE entry='44270';
INSERT INTO `npc_vendor` VALUES ('44270', '0', '8953', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '1', '4539', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '2', '1179', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '3', '1205', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '4', '4602', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '5', '1645', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '6', '8766', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '7', '159', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '8', '4536', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '9', '4538', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '10', '1708', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44270', '11', '4537', '0', '0', '0', '1');

-- ad missing  items from vendors in zone Camp una'fe  and duplicates delete
DELETE FROM creature WHERE guid IN (138437,138451,138450,138431,138432,138344,138343,138430,101967,138415,101240,102027,101134,101344,101889,138483,101268,138463,138462,138328,101323);
DELETE FROM creature WHERE guid IN (101639,138354,138510,138511,101896,102006,138537,101392,138500,138439,101998,138184,138758,108220,101652);
DELETE FROM `npc_vendor` WHERE entry='44296';
INSERT INTO `npc_vendor` VALUES ('44296', '0', '4498', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44296', '1', '4541', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44296', '2', '4497', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44296', '3', '1179', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44296', '4', '1205', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44296', '5', '4542', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44296', '6', '159', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44296', '7', '4470', '0', '0', '0', '1');

DELETE FROM `npc_vendor` WHERE entry='44286';
INSERT INTO `npc_vendor` VALUES ('44286', '0', '236', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44286', '1', '1849', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44286', '2', '238', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44286', '3', '1850', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44286', '4', '239', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44286', '5', '237', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44286', '6', '4234', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44286', '7', '4232', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44286', '8', '2319', '0', '0', '0', '1');

UPDATE `creature_template` SET `npcflag` = 128 WHERE `entry` = 44286; 
UPDATE `creature_template` SET `npcflag` = 65536 WHERE `entry` = 7714;

-- Ruins of taurajo zone fixes
DELETE FROM creature WHERE guid IN (102227,102088,111718,101252,117719,101226,117717,117692,117682);

-- Desolation hold zone fixed
DELETE FROM `creature_template` WHERE `entry`=38070 LIMIT 1;
INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 38070, 0, 0, 0, 0, 0, 30913, 30914, 0, 0, "Desolation Guard", "", "", 0, 40, 40, 0, 85, 85, 0, 1.0, 1.14286, 1.0, 0, 66, 87, 0, 24, 1.2, 2000, 2000, 1, 0, 0, 0, 0, 0, 0, 0, 66, 87, 24, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", 0, 3, 4.0, 1.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 38070, 0, 0, "", "13623");
UPDATE `creature_template` SET spell1='40505', spell2='95826' WHERE entry='38070';

DELETE FROM `npc_vendor` WHERE entry='44287';
INSERT INTO `npc_vendor` VALUES ('44287', '0', '2520', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44287', '1', '2523', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44287', '2', '2522', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44287', '3', '2528', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44287', '4', '2521', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44287', '5', '2530', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44287', '6', '2531', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44287', '7', '2526', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44287', '8', '2534', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44287', '9', '2529', '0', '0', '0', '1');

DELETE FROM `creature_template` WHERE `entry`=37811 LIMIT 1;
INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 37811, 0, 0, 0, 0, 0, 30788, 0, 0, 0, "Warlord Gar'dul", "", "", 0, 33, 33, 0, 85, 85, 3, 1.0, 1.14286, 1.0, 1, 42, 56, 0, 24, 1.2, 2000, 2000, 1, 0, 0, 0, 0, 0, 0, 0, 42, 56, 24, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", 0, 3, 4.0, 1.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 37811, 0, 0, "", "13623");

DELETE FROM `npc_vendor` WHERE entry='44276';
INSERT INTO `npc_vendor` VALUES ('44276', '0', '4599', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '1', '2287', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '2', '1179', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '3', '1205', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '4', '1645', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '5', '8766', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '6', '3770', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '7', '159', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '8', '8952', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '9', '1708', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '10', '117', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44276', '11', '3771', '0', '0', '0', '1');

DELETE FROM `npc_vendor` WHERE entry='44300';
INSERT INTO `npc_vendor` VALUES ('44300', '0', '4498', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44300', '1', '4541', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44300', '2', '4497', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44300', '3', '1179', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44300', '4', '1205', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44300', '5', '4542', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44300', '6', '159', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44300', '7', '4470', '0', '0', '0', '1');

UPDATE `creature_template` SET `npcflag` = 66177 WHERE `entry` = 44276;
UPDATE `creature_template` SET `gossip_menu_id` = 66177 WHERE `entry` = 44276;
DELETE FROM creature WHERE guid IN (109915,131943,109918,131946,109920,131931,109913);

-- Ratchet fixes
UPDATE `creature_template` SET `equipment_id` = 0 WHERE `entry` = 3255; 
DELETE FROM creature_equip_template WHERE entry=3255;
UPDATE `creature_template` SET `equipment_id` = 0 WHERE `entry` = 3425; 
DELETE FROM creature_equip_template WHERE entry=3425;

DELETE FROM creature WHERE guid IN (139201,107809,139204,139199,139192,139187,108095,139157,139182,139156,139181,106742,139193,139191,107611,139179,107221,131073,139161,107792,107092,106900);
DELETE FROM creature WHERE guid IN (126362,126363,107934,126367,106736,126359,107888,108211,108052,126354,108295,126353,108127,139203,107677,139180,139170,107779,107268,107595,107083);

-- The merchant coast
DELETE FROM creature WHERE guid IN (108137,106781,139140,139139,108287,139127,139125,139114,107011,139104,108120,106846,139123,107196,139118,139121,139120,139119,107129,106639,139090);
DELETE FROM creature WHERE guid IN (139087,107157,139093,139086,108256,107712,107137,106856,139026,107883,107692,139006,139007,139009,107249,139011,139019,139003,139004,107928,139002);
DELETE FROM creature WHERE guid IN (106766,139134);

-- Valley of Trials
DELETE FROM gameobject WHERE guid IN (14474,13191);
DELETE FROM creature WHERE guid IN (98258,91285,97953,127288,127287,91127,127290,97167,91493,98293,127217,98434);
UPDATE `creature_template` SET `equipment_id` = 0 WHERE `entry` = 3124; 
DELETE FROM creature_equip_template WHERE entry=3124;
UPDATE `creature_template` SET `equipment_id` = 0 WHERE `entry` = 3281; 
DELETE FROM creature_equip_template WHERE entry=3281;
UPDATE `creature_template` SET `equipment_id` = 0 WHERE `entry` = 3098; 
DELETE FROM creature_equip_template WHERE entry=3098;
UPDATE `creature_template` SET `equipment_id` = 0 WHERE `entry` = 3099; 
DELETE FROM creature_equip_template WHERE entry=3099;
UPDATE `creature_template` SET `equipment_id` = 0 WHERE `entry` = 3125; 
DELETE FROM creature_equip_template WHERE entry=3125;
UPDATE `creature_template` SET `equipment_id` = 0 WHERE `entry` = 3106; 
DELETE FROM creature_equip_template WHERE entry=3106;

-- Razor Hills Barracks fixes  adding  missing  npc and corecting  some errors

DELETE FROM creature WHERE guid IN (320910,320911,320912,320913,320914,320915,320916,320917,320918,320919,320920,320921,320922,320923,320924,320925);
INSERT INTO `creature` VALUES ('320910', '3169', '1', '14', '2337', '1', '1', '0', '3169', '312.499', '-4828.67', '9.57966', '1.77506', '300', '0', '0', '2059', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320911', '3706', '1', '14', '2337', '1', '1', '0', '3706', '294.574', '-4831.7', '10.5248', '0.370069', '300', '0', '0', '417', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320912', '3173', '1', '14', '2337', '1', '1', '0', '3173', '306.438', '-4841.1', '10.5228', '1.29837', '300', '0', '0', '328', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320913', '3164', '1', '14', '2337', '1', '1', '0', '3164', '321.511', '-4839.66', '10.524', '2.09118', '300', '0', '0', '300', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320914', '5943', '1', '14', '2337', '1', '1', '0', '0', '330.452', '-4827.3', '10.524', '2.88902', '300', '0', '0', '328', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320915', '5953', '1', '14', '2337', '1', '1', '0', '5953', '302.329', '-4812.81', '10.5171', '5.37262', '300', '0', '0', '656', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320916', '5953', '1', '14', '2337', '1', '1', '0', '5953', '318.346', '-4810.79', '10.5197', '4.68185', '300', '0', '0', '656', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320917', '3881', '1', '14', '362', '1', '1', '0', '3881', '298.299', '-4645.29', '17.7601', '4.82379', '300', '0', '0', '300', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320918', '3191', '1', '14', '362', '1', '1', '0', '3191', '301.464', '-4649.21', '17.4442', '0.577837', '300', '0', '0', '120', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320919', '11943', '1', '14', '362', '1', '1', '0', '0', '347.982', '-4677.75', '16.489', '2.60504', '300', '0', '0', '102', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320920', '10682', '1', '14', '362', '1', '1', '0', '10682', '306.436', '-4736.18', '9.33173', '0.180556', '300', '0', '0', '2440', '0', '0', '0', '134221824', '0');
INSERT INTO `creature` VALUES ('320921', '9987', '1', '14', '362', '1', '1', '0', '9987', '331.029', '-4713.07', '14.1327', '2.9312', '300', '0', '0', '1003', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320922', '6787', '1', '14', '362', '1', '1', '0', '0', '344.562', '-4675.69', '16.489', '1.29539', '300', '0', '0', '356', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320923', '10676', '1', '14', '362', '1', '1', '0', '10676', '308.716', '-4747.96', '9.55995', '3.59355', '300', '0', '0', '2440', '0', '0', '0', '134217728', '0');
INSERT INTO `creature` VALUES ('320924', '3167', '1', '14', '362', '1', '1', '0', '3167', '357.915', '-4705.76', '14.4098', '4.30695', '300', '0', '0', '356', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320925', '3175', '1', '14', '362', '1', '1', '0', '3175', '366.751', '-4702.03', '16.3077', '4.81877', '300', '0', '0', '356', '0', '0', '0', '0', '0');

DELETE FROM smart_scripts WHERE entryorguid=-106900;

DELETE FROM creature WHERE guid IN (320926,320927,320928,320929,320930,320931);
INSERT INTO `creature` VALUES ('320926', '3171', '1', '14', '362', '1', '1', '0', '3171', '276.826', '-4704.85', '11.9037', '4.55936', '300', '0', '0', '356', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320927', '44380', '1', '14', '362', '1', '1', '0', '0', '342.547', '-4770.64', '12.6296', '1.47502', '300', '0', '0', '301', '326', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320928', '5880', '1', '14', '362', '1', '1', '0', '5880', '333.096', '-4766.92', '12.6351', '1.64476', '300', '0', '0', '300', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320929', '3172', '1', '14', '362', '1', '1', '0', '3172', '355.863', '-4837.46', '11.0475', '2.08557', '300', '0', '0', '1536', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320930', '3620', '1', '14', '362', '1', '1', '0', '3620', '272.805', '-4713.52', '11.9057', '1.17118', '300', '0', '0', '1753', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('320931', '3170', '1', '14', '362', '1', '1', '0', '3170', '267.905', '-4711.21', '17.7678', '4.30732', '300', '0', '0', '300', '0', '0', '0', '0', '0');

UPDATE `creature_template` SET `gossip_menu_id` = 3285 WHERE `entry` = 5953;
