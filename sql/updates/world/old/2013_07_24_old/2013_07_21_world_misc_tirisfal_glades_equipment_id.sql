-- Text + equip fix and spawn around Tirisfal Glades and delete duplicates :

DELETE FROM creature_equip_template WHERE entry=39002;
INSERT INTO `creature_equip_template` VALUES ('39002', '1', '1899', '0', '0');
UPDATE creature_template SET equipment_id=49423 WHERE entry=49423;
UPDATE creature_template SET equipment_id=2130 WHERE entry=2130;
UPDATE creature_template SET equipment_id=1934 WHERE entry=1934;
UPDATE creature_template SET equipment_id=1934 WHERE entry=1935;
UPDATE creature_template SET equipment_id=1934 WHERE entry=1936;
UPDATE creature_template SET equipment_id=1535 WHERE entry=1535;
UPDATE creature_template SET equipment_id=39002 WHERE entry=39002;
UPDATE creature_template SET equipment_id=1543 WHERE entry=1543;
UPDATE creature_template SET equipment_id=1910 WHERE entry=1910;
UPDATE creature_template SET equipment_id=1544 WHERE entry=1544;
UPDATE creature_template SET equipment_id=1520 WHERE entry=1520;
UPDATE creature_template SET equipment_id=1522 WHERE entry=1522;
UPDATE creature_template SET equipment_id=1657 WHERE entry=1657;
UPDATE creature_template SET equipment_id=1753 WHERE entry=1753;
UPDATE creature_template SET equipment_id=1941 WHERE entry=1941;
UPDATE creature_template SET equipment_id=6390 WHERE entry=6390;
UPDATE creature_template SET equipment_id=1742 WHERE entry=1742;
UPDATE creature_template SET equipment_id=1743 WHERE entry=1743;
UPDATE creature_template SET equipment_id=2131 WHERE entry=2131;
UPDATE creature_template SET equipment_id=1745 WHERE entry=1745;
UPDATE creature_template SET equipment_id=10665 WHERE entry=10665;
UPDATE creature_template SET equipment_id=2128 WHERE entry=2128;
UPDATE creature_template SET equipment_id=5695 WHERE entry=5695;
UPDATE creature_template SET equipment_id=1744 WHERE entry=1744;
UPDATE creature_template SET equipment_id=44047 WHERE entry=44047;
UPDATE creature_template SET equipment_id=5759 WHERE entry=5759;
UPDATE creature_template SET equipment_id=3548 WHERE entry=3548;
UPDATE creature_template SET equipment_id=2132 WHERE entry=2132;
UPDATE creature_template SET equipment_id=2114 WHERE entry=2114;
UPDATE creature_template SET equipment_id=3547 WHERE entry=3547;
UPDATE creature_template SET equipment_id=1746 WHERE entry=1746;
UPDATE creature_template SET equipment_id=1652 WHERE entry=1652;
UPDATE creature_template SET equipment_id=33996 WHERE entry=33996;
UPDATE creature_template SET equipment_id=2210 WHERE entry=2210;
UPDATE creature_template SET equipment_id=2209 WHERE entry=2209;
UPDATE creature_template SET equipment_id=2135 WHERE entry=2135;
UPDATE creature_template SET equipment_id=2136 WHERE entry=2136;
UPDATE creature_template SET equipment_id=4731 WHERE entry=4731;
UPDATE creature_template SET equipment_id=4773 WHERE entry=4773;
UPDATE creature_template SET equipment_id=6785 WHERE entry=6785;
UPDATE creature_template SET equipment_id=10055 WHERE entry=10055;
UPDATE creature_template SET equipment_id=2309 WHERE entry=2309;
UPDATE creature_template SET equipment_id=5724 WHERE entry=5724;
UPDATE creature_template SET equipment_id=39100 WHERE entry=39100;
UPDATE creature_template SET equipment_id=2129 WHERE entry=2129;
UPDATE creature_template SET equipment_id=39117 WHERE entry=39117;
UPDATE creature_template SET equipment_id=1738 WHERE entry=1738;
UPDATE creature_template SET equipment_id=5688 WHERE entry=5688;
UPDATE creature_template SET equipment_id=2137 WHERE entry=2137;
UPDATE creature_template SET equipment_id=2134 WHERE entry=2134;
UPDATE creature_template SET equipment_id=2118 WHERE entry=2118;
UPDATE creature_template SET equipment_id=5750 WHERE entry=5750;
UPDATE creature_template SET equipment_id=2127 WHERE entry=2127;
UPDATE creature_template SET equipment_id=1499 WHERE entry=1499;
UPDATE creature_template SET equipment_id=47405 WHERE entry=47405;
UPDATE creature_template SET equipment_id=1735 WHERE entry=1735;
UPDATE creature_template SET equipment_id=1496 WHERE entry=1496;
UPDATE creature_template SET equipment_id=3522 WHERE entry=3522;
UPDATE creature_template SET equipment_id=3523 WHERE entry=3523;
UPDATE creature_template SET equipment_id=39196 WHERE entry=39196;
UPDATE creature_template SET equipment_id=48612 WHERE entry=48612;
UPDATE creature_template SET equipment_id=48614 WHERE entry=48614;
UPDATE creature_template SET equipment_id=48613 WHERE entry=48613;
UPDATE creature_template SET equipment_id=48616 WHERE entry=48616;
UPDATE creature_template SET equipment_id=48615 WHERE entry=48615;
UPDATE creature_template SET equipment_id=48618 WHERE entry=48618;
UPDATE creature_template SET equipment_id=44034 WHERE entry=44034;
UPDATE creature_template SET equipment_id=1519 WHERE entry=1519;
UPDATE creature_template SET equipment_id=1518 WHERE entry=1518;
UPDATE creature_template SET equipment_id=51850 WHERE entry=51850;
UPDATE creature_template SET equipment_id=7980 WHERE entry=7980;
UPDATE creature_template SET equipment_id=6784 WHERE entry=6784;
UPDATE creature_template SET equipment_id=1919 WHERE entry=1919;
UPDATE creature_template SET equipment_id=1918 WHERE entry=1918;
UPDATE creature_template SET equipment_id=1916 WHERE entry=1916;
UPDATE creature_template SET equipment_id=1917 WHERE entry=1917;
UPDATE creature_template SET equipment_id=49425 WHERE entry=49425;
UPDATE creature_template SET equipment_id=1890 WHERE entry=1890;
UPDATE creature_template SET equipment_id=49422 WHERE entry=49422;
UPDATE creature_template SET equipment_id=49428 WHERE entry=49428;
UPDATE creature_template SET equipment_id=49424 WHERE entry=49424;
UPDATE creature_template SET equipment_id=1736 WHERE entry=1736;
UPDATE creature_template SET equipment_id=1739 WHERE entry=1739;
UPDATE creature_template SET equipment_id=1741 WHERE entry=1741;
UPDATE creature_template SET equipment_id=1740 WHERE entry=1740;
UPDATE creature_template SET equipment_id=38911 WHERE entry=38911;
UPDATE creature_template SET equipment_id=2113 WHERE entry=2113;
UPDATE creature_template SET equipment_id=2122 WHERE entry=2122;
UPDATE creature_template SET equipment_id=2119 WHERE entry=2119;
UPDATE creature_template SET equipment_id=2115 WHERE entry=2115;
UPDATE creature_template SET equipment_id=2116 WHERE entry=2116;
UPDATE creature_template SET equipment_id=2117 WHERE entry=2117;
UPDATE creature_template SET equipment_id=2123 WHERE entry=2123;
UPDATE creature_template SET equipment_id=2124 WHERE entry=2124;
UPDATE creature_template SET equipment_id=1661 WHERE entry=1661;
UPDATE creature_template SET equipment_id=1569 WHERE entry=1569;
UPDATE creature_template SET equipment_id=5749 WHERE entry=5749;
UPDATE creature_template SET equipment_id=2126 WHERE entry=2126;
UPDATE creature_template SET equipment_id=5667 WHERE entry=5667;
UPDATE creature_template SET equipment_id=1568 WHERE entry=1568;
UPDATE creature_template SET equipment_id=38898 WHERE entry=38898;
UPDATE creature_template SET equipment_id=38899 WHERE entry=38899;
UPDATE creature_template SET equipment_id=1570 WHERE entry=1570;
UPDATE creature_template SET equipment_id=1545 WHERE entry=1545;
UPDATE creature_template SET equipment_id=1497 WHERE entry=1497;
UPDATE creature_template SET equipment_id=5690 WHERE entry=5690;
UPDATE creature_template SET equipment_id=1660 WHERE entry=1660;
UPDATE creature_template SET equipment_id=39097 WHERE entry=39097;
UPDATE creature_template SET equipment_id=1665 WHERE entry=1665;
UPDATE creature_template SET equipment_id=1539 WHERE entry=1539;
UPDATE creature_template SET equipment_id=1540 WHERE entry=1540;
UPDATE creature_template SET equipment_id=1538 WHERE entry=1538;
UPDATE creature_template SET equipment_id=4281 WHERE entry=4281;
UPDATE creature_template SET equipment_id=4282 WHERE entry=4282;
UPDATE creature_template SET equipment_id=4280 WHERE entry=4280;
UPDATE creature_template SET equipment_id=4283 WHERE entry=4283;
UPDATE creature_template SET equipment_id=4285 WHERE entry=4285;
UPDATE creature_template SET equipment_id=4284 WHERE entry=4284;
UPDATE creature_template SET equipment_id=6289 WHERE entry=6289;
UPDATE creature_template SET equipment_id=1495 WHERE entry=1495;
UPDATE creature_template SET equipment_id=3549 WHERE entry=3549;
UPDATE creature_template SET equipment_id=3550 WHERE entry=3550;
UPDATE creature_template SET equipment_id=17099 WHERE entry=17099;
UPDATE creature_template SET equipment_id=11608 WHERE entry=11608;
UPDATE creature_template SET equipment_id=46271 WHERE entry=46271;
UPDATE creature_template SET equipment_id=11615 WHERE entry=11615;
UPDATE creature_template SET equipment_id=11194 WHERE entry=11194;
UPDATE creature_template SET equipment_id=11055 WHERE entry=11055;
UPDATE creature_template SET equipment_id=11057 WHERE entry=11057;
UPDATE creature_template SET equipment_id=10837 WHERE entry=10837;
UPDATE creature_template SET equipment_id=10839 WHERE entry=10839;
UPDATE creature_template SET equipment_id=10856 WHERE entry=10856;
UPDATE creature_template SET equipment_id=26539 WHERE entry=26539;
UPDATE creature_template SET equipment_id=16096 WHERE entry=16096;
UPDATE creature_template SET equipment_id=3150 WHERE entry=3150;
UPDATE creature_template SET equipment_id=1536 WHERE entry=1536;
UPDATE creature_template SET equipment_id=1537 WHERE entry=1537;
UPDATE creature_template SET equipment_id=1662 WHERE entry=1662;
UPDATE creature_template SET equipment_id=44792 WHERE entry=44792;
UPDATE creature_template SET equipment_id=44791 WHERE entry=44791;
UPDATE creature_template SET equipment_id=46483 WHERE entry=46483;
UPDATE creature_template SET equipment_id=49141 WHERE entry=49141;

UPDATE creature SET equipment_id=0 WHERE id IN(1934.1935,1936);

DELETE FROM creature_equip_template WHERE entry=49425;
DELETE FROM creature_equip_template WHERE entry=49141;
DELETE FROM creature_equip_template WHERE entry=49428;
DELETE FROM creature_equip_template WHERE entry=51850;

INSERT INTO `creature_equip_template` VALUES ('49425', '1', '1895', '1957', '0');
INSERT INTO `creature_equip_template` VALUES ('49141', '1', '1895', '1957', '0');
INSERT INTO `creature_equip_template` VALUES ('49428', '1', '1905', '0', '0');
INSERT INTO `creature_equip_template` VALUES ('51850', '1', '5286', '0', '2551');

SET @ENTRY := 1934;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 50% HP');

SET @ENTRY := 1934;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Why dont you leave us alone?',12,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'Go away or die in here!',12,0,100,0,0,0, 'on 50% Text');

SET @ENTRY := 1935;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 50% HP');

SET @ENTRY := 1935;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'You wont steal from us thief!',12,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'You will die in here!',12,0,100,0,0,0, 'on 50% Text');

SET @ENTRY := 1936;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 50% HP');

SET @ENTRY := 1936;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'We dont accept robbers so you will die!',12,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'Go back to grave from where you come!',12,0,100,0,0,0, 'on 50% Text');

-- missing http://www.wowhead.com/npc=47119
DELETE FROM creature WHERE guid=302487;
INSERT INTO `creature` VALUES ('302487', '47119', '0', '4922', '5140', '1', '1', '0', '0', '-4863.55', '-6736.98', '9.41774', '5.61199', '300', '0', '0', '1305476', '0', '0', '0', '0', '0');


-- Ulag was missing from hes place entry 6390
DELETE FROM creature WHERE guid=302486;
INSERT INTO `creature` VALUES ('302486', '6390', '0', '85', '159', '1', '1', '0', '0', '2390.41', '336.594', '40.0158', '2.2603', '300', '0', '0', '222', '0', '0', '0', '134217728', '0');

-- duplicate 39196
DELETE FROM creature WHERE guid=64360;

-- duplicate 30897
DELETE FROM creature WHERE guid=30897;

-- duplicate 39196
DELETE FROM creature WHERE guid=65619;

-- duplicate 64790
DELETE FROM creature WHERE guid=64790;


-- duplicate 64789
DELETE FROM creature WHERE guid=64789;

-- duplicate 64795
DELETE FROM creature WHERE guid=64795;

-- duplicate 31783
DELETE FROM creature WHERE guid=31783;

-- rong place spawn guid 12633
DELETE FROM creature WHERE guid=12633;
INSERT INTO `creature` VALUES ('12633', '38895', '0', '85', '5692', '1', '1', '0', '0', '1756.93', '1667.05', '121.298', '5.47045', '300', '0', '0', '42', '0', '0', '0', '0', '0');

-- vendor 44040 missing items
DELETE FROM npc_vendor where entry=44040;
INSERT INTO `npc_vendor` VALUES ('44040', '0', '3025', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44040', '0', '3024', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44040', '0', '3027', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44040', '0', '3023', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44040', '0', '3026', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44040', '0', '2507', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44040', '0', '2511', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44040', '0', '2509', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44040', '0', '2506', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44040', '0', '2505', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('44040', '0', '2504', '0', '0', '0', '1');
