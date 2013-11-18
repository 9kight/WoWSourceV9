
-- correcting mob http://www.wowhead.com/npc=41442
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `exp`=3, `mindmg`=3107, `maxdmg`=4606, `dmg_multiplier`=4.8, `unit_flags`=0, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1, `Health_mod`=201 WHERE `entry`=41442;

-- correcting mob http://www.wowhead.com/npc=43126
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `exp`=3, `mindmg`=846, `maxdmg`=1027, `dmg_multiplier`=3.2, `unit_flags`=0, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1, `Health_mod`=25.3724, `Mana_mod`=0.02 WHERE `entry`=43126;

-- correcting mob http://www.wowhead.com/npc=43296
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `exp`=3, `mindmg`=2981, `maxdmg`=3422, `dmg_multiplier`=5.1, `unit_flags`=0, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1, `Health_mod`=311 WHERE `entry`=43296;

-- rong place for him there 
DELETE FROM creature WHERE guid=308696;

-- text for  Finkle 
DELETE FROM creature_text WHERE entry=44202;
INSERT INTO `creature_text` VALUES ('44202', '0', '0', 'Hey over here , Please  help me !', '12', '0', '100', '0', '0', '0', 'Finkle text 1');

-- nefarian platform
DELETE FROM gameobject WHERE id=207834;
INSERT INTO `gameobject` VALUES ('1056708', '207834', '669', '5094', '5094', '1', '1', '-107.832', '-224.645', '7.03043', '3.13705', '0', '0', '0.956305', '-0.292372', '120', '255', '1');


-- correcting mob http://www.wowhead.com/npc=41270
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `exp`=3, `mindmg`=2916, `maxdmg`=3011, `dmg_multiplier`=5.1, `unit_flags`=0, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1, `Health_mod`=244 WHERE `entry`=41270;

-- correcting mob http://www.wowhead.com/npc=41376
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `exp`=3, `mindmg`=2802, `maxdmg`=3027, `dmg_multiplier`=5.3, `unit_flags`=0, `dynamicflags`=1, `type_flags`=0, `InhabitType`=4, `Health_mod`=311 WHERE `entry`=41376;

-- modify nefarian visual stats
DELETE FROM creature_template WHERE entry=51106;
INSERT INTO `creature_template` VALUES ('51106', '0', '0', '0', '0', '0', '32716', '0', '0', '0', 'Nefarian', '', '', '0', '85', '85', '3', '0', '35', '35', '0', '1', '1.14286', '1', '2.2', '1', '3', '2817', '3056', '0', '24', '4.2', '2000', '2000', '1', '0', '0', '0', '0', '0', '0', '0', '0', '2817', '3056', '24', '2', '108', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '2503500', '2503500', '', '0', '4', '1', '238.721', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '172', '1', '0', '0', '0', '', '13623');

-- adding wp for  visual nefarian that flys
DELETE FROM waypoint_data WHERE id=307706;
INSERT INTO `waypoint_data` VALUES ('327706', '1', '-59.7159', '-247.199', '203.857', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '2', '-36.0383', '-238.02', '163.409', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '3', '-26.5209', '-225.953', '138.277', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '4', '-25.1936', '-207.515', '118.99', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '5', '-39.6047', '-189.542', '113.406', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '6', '-62.2509', '-168.893', '108.042', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '7', '-97.5542', '-153.17', '104.693', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '8', '-116.173', '-153.515', '106.165', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '9', '-154.796', '-168.56', '106.703', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '10', '-176.549', '-194.878', '105.654', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '11', '-181.373', '-231.112', '105.026', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '12', '-159.754', '-272.388', '102.622', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '13', '-138.617', '-285.9', '99.9464', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '14', '-91.0353', '-286.677', '94.8191', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '15', '-64.144', '-258.512', '90.5491', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '16', '-62.8196', '-240.323', '89.1619', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '17', '-104.568', '-212.173', '84.6294', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '18', '-129.192', '-216.051', '77.1012', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '19', '-150.721', '-218.836', '76.9552', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '20', '-168.79', '-220.585', '91.5436', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '21', '-176.697', '-213.354', '116.111', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '22', '-174.547', '-203.417', '139.192', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '23', '-154.262', '-215.795', '159.412', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '24', '-147.899', '-237.963', '177.028', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '25', '-143.905', '-258.743', '197.031', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '26', '-135.019', '-278.525', '222.935', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '27', '-111.659', '-292.945', '237.522', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '28', '-87.7416', '-278.457', '236.85', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('327706', '29', '-74.3059', '-265.297', '239.823', '0', '0', '0', '0', '100', '0', '0');

-- spawning nefarian visual
DELETE FROM creature WHERE guid=327706;
INSERT INTO `creature` VALUES ('327706', '51106', '669', '5094', '5094', '1', '65535', '0', '0', '-69.6991', '-258.958', '229.9', '1.03814', '300', '0', '0', '14008375', '0', '2', '0', '0', '0');

-- update rank for 56350
UPDATE creature_template SET rank=1 WHERE entry=56350;


-- fireland
DELETE FROM gameobject_template WHERE entry=208967;
INSERT INTO `gameobject_template` VALUES ('208967', '3', '10684', 'Cache of the Fire Lord', '', '', '', '1634', '40061', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '15211');

DELETE FROM `gameobject_loot_template` WHERE entry='208967';
INSERT INTO `gameobject_loot_template` VALUES ('208967', '69237', '63.74', '1', '0', '1', '3');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71141', '-53.12', '1', '0', '1', '3');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '69815', '-32.63', '1', '0', '1', '55');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71668', '31.09', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71682', '25.45', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71675', '24.04', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71354', '18.27', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '68995', '17.35', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71355', '16.71', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '68994', '16.48', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '68925', '15.78', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71353', '13.58', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71358', '13.51', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71798', '13.1', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71357', '12.67', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71356', '8.77', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '70921', '8.35', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71352', '4.38', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '69224', '1.14', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71611', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71610', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71616', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71677', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71684', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71670', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71617', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71614', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71615', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71613', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '69150', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71612', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '70723', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '69110', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '69167', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71779', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71778', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71787', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71786', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71776', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71777', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71785', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71784', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71782', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71783', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71797', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71775', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71774', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71780', '0.02', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('208967', '71781', '0.02', '1', '0', '1', '1');

DELETE FROM `gameobject` WHERE id='208967';


-- correcting mob http://www.wowhead.com/npc=40586
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=87, `exp`=3, `mindmg`=3107, `maxdmg`=4202, `dmg_multiplier`=2.5, `unit_flags`=0, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1, `Health_mod`=19.5118 WHERE `entry`=40586;


UPDATE `creature_template` SET `unit_flags`=0, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1  WHERE `entry`=48639; 
