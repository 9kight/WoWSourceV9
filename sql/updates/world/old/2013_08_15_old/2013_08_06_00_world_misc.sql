-- delete the rong equipments from durotar
UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='3126';
DELETE FROM creature_equip_template WHERE entry=3126;

UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='3116';
DELETE FROM creature_equip_template WHERE entry=3116;

UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='3100';
DELETE FROM creature_equip_template WHERE entry=3100;

UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='10685';
DELETE FROM creature_equip_template WHERE entry=10685;

UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='4127';
DELETE FROM creature_equip_template WHERE entry=4127;

UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='3244';
DELETE FROM creature_equip_template WHERE entry=3244;

UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='3426';
DELETE FROM creature_equip_template WHERE entry=3426;

UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='3245';
DELETE FROM creature_equip_template WHERE entry=3245;

UPDATE `creature_template` SET `equipment_id`='0' WHERE `entry`='3122';
DELETE FROM creature_equip_template WHERE entry=3122;

-- delete the duplicates from same  phase 
DELETE FROM creature WHERE guid IN (125989,107043,125990,106854,125984,125864,125860,126472,126490,126489,126475,126469,107636,107747,126478,126463,107451,126867,96784,97728);

-- add missing item for vendor 43956
DELETE FROM `npc_vendor` WHERE entry='43956';
INSERT INTO `npc_vendor` VALUES ('43956', '0', '4599', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43956', '1', '2287', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43956', '2', '3770', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43956', '3', '8952', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43956', '4', '117', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43956', '5', '3771', '0', '0', '0', '1');

-- add missing item for vendor 43949
DELETE FROM `npc_vendor` WHERE entry='43949';
INSERT INTO `npc_vendor` VALUES ('43949', '0', '2371', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '1', '2373', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '2', '2374', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '3', '2375', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '4', '2370', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '5', '2372', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '6', '3606', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '7', '2367', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '8', '3607', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '9', '2369', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '10', '2366', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43949', '11', '2364', '0', '0', '0', '1');

-- wp for 10682
DELETE FROM creature_template_addon WHERE entry=10682;
INSERT INTO `creature_template_addon` VALUES ('10682', '320920', '2328', '0', '0', '0', '');
DELETE FROM creature_addon WHERE guid=320920;
INSERT INTO `creature_addon` VALUES ('320920', '320920', '2328', '0', '0', '0', '');
DELETE FROM waypoint_data WHERE id=320920;
INSERT INTO `waypoint_data` VALUES ('320920', '1', '308.621', '-4735.89', '9.33202', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '2', '308.621', '-4735.89', '9.33202', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '3', '314.742', '-4733.99', '9.67227', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '4', '318.944', '-4732.99', '9.90497', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '5', '323.061', '-4732.16', '10.1623', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '6', '328.813', '-4731.2', '10.2651', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '7', '332.17', '-4730.81', '10.2427', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '8', '337.648', '-4730.7', '10.2427', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '9', '341.147', '-4730.79', '10.2427', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '10', '344.646', '-4730.87', '10.2427', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '11', '351.643', '-4731.05', '10.2427', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '12', '355.142', '-4731.14', '10.2275', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '13', '358.641', '-4731.22', '10.1049', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '14', '365.639', '-4731.4', '9.83562', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '15', '369.138', '-4731.49', '9.66873', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '16', '372.993', '-4732.48', '9.67068', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '17', '375.885', '-4737.39', '9.67386', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '18', '375.275', '-4741.75', '9.67789', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '19', '372.145', '-4745.67', '9.67789', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '20', '370.182', '-4745.63', '9.67789', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '21', '364.659', '-4744.8', '9.67789', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '22', '361.291', '-4743.85', '9.61341', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '23', '354.555', '-4741.94', '9.87174', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '24', '349.067', '-4740.93', '9.5672', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '25', '345.12', '-4741.11', '9.56608', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '26', '333.356', '-4744.06', '9.6135', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '27', '323.256', '-4746.92', '9.56106', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '28', '312.291', '-4749.6', '9.56106', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '29', '300.306', '-4750.51', '9.39745', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '30', '290.198', '-4750.98', '9.40703', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '31', '278.022', '-4748.89', '9.65831', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '32', '267.404', '-4747.44', '9.94989', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '33', '255.632', '-4745.81', '10.1024', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '34', '247.085', '-4742.86', '10.1024', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '35', '244.941', '-4737.65', '10.1024', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '36', '248.536', '-4735.51', '10.1024', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '37', '251.81', '-4736.34', '10.1024', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '38', '262.203', '-4741.86', '10.0168', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '39', '264.81', '-4742.3', '9.95106', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '40', '272.525', '-4740.1', '9.76651', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '41', '286.39', '-4738.16', '9.49013', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320920', '42', '306.816', '-4736.14', '9.33209', '0', '0', '0', '0', '100', '0', '0');

-- wp for 10676
DELETE FROM creature_template_addon WHERE entry=10676;
INSERT INTO `creature_template_addon` VALUES ('10676', '320923', '207', '0', '0', '0', '');
DELETE FROM creature_addon WHERE guid=320923;
INSERT INTO `creature_addon` VALUES ('320923', '320923', '207', '0', '0', '0', '');
DELETE FROM waypoint_data WHERE id=320923;
INSERT INTO `waypoint_data` VALUES ('320923', '1', '308.612', '-4747.89', '9.55943', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '2', '306.989', '-4748.11', '9.5575', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '3', '302.221', '-4748.44', '9.33771', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '4', '295.223', '-4748.59', '9.39812', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '5', '284.725', '-4748.81', '9.51266', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '6', '275.867', '-4749.07', '9.70917', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '7', '268.872', '-4749.33', '9.93212', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '8', '261.426', '-4749.28', '10.1572', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '9', '256.212', '-4747.75', '10.1029', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '10', '252.235', '-4744.19', '10.1029', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '11', '252.513', '-4741.09', '10.1029', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '12', '256.104', '-4739.56', '10.1029', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '13', '259.586', '-4741.18', '10.065', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '14', '267.175', '-4742.44', '9.90376', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '15', '271.23', '-4742.2', '9.81894', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '16', '303.266', '-4735.8', '9.33209', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '17', '313.554', '-4733.74', '9.66161', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '18', '323.521', '-4731.91', '10.205', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '19', '336.156', '-4730.55', '10.2414', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '20', '344.319', '-4730.33', '10.2414', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '21', '354.665', '-4731.12', '10.2682', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '22', '361.605', '-4731.98', '9.93299', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '23', '369.41', '-4733.2', '9.66909', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '24', '372.047', '-4737.03', '9.67467', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '25', '371.384', '-4741.76', '9.67799', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '26', '367.051', '-4743.34', '9.67799', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '27', '359.492', '-4742.92', '9.61291', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '28', '350.444', '-4741.95', '9.69848', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '29', '340.632', '-4741.97', '9.56579', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '30', '326.445', '-4744.63', '9.62985', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '31', '319.672', '-4745.88', '9.56096', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '32', '312.795', '-4747.19', '9.56096', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('320923', '33', '308.675', '-4747.97', '9.56096', '0', '0', '0', '0', '100', '0', '0');

-- guard from razor hill  menu 
DELETE FROM gossip_menu_option WHERE menu_id=3285;
INSERT INTO `gossip_menu_option` VALUES ('3285', '0', '0', 'The bank', '1', '1', '3280', '0', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('3285', '1', '0', 'The wind rider master', '1', '1', '3281', '0', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('3285', '2', '0', 'The inn', '1', '1', '3282', '403', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('3285', '3', '0', 'The stable master', '1', '1', '4901', '404', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('3285', '4', '0', 'A class trainer', '1', '1', '3283', '0', '0', '0', '');
INSERT INTO `gossip_menu_option` VALUES ('3285', '5', '0', 'A profession trainer', '1', '1', '3284', '0', '0', '0', '');
UPDATE creature_template SET gossip_menu_id =3285 WHERE entry=5953;
