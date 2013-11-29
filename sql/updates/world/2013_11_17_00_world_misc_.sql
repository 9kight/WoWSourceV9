-- update vendor items list
DELETE FROM `npc_vendor` WHERE entry='5124';
INSERT INTO `npc_vendor` VALUES ('5124', '0', '69984', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '1', '4599', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '2', '2287', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '3', '58269', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '4', '35953', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '5', '3770', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '8', '58268', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '9', '8952', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '10', '33454', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '11', '27854', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '12', '117', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('5124', '13', '3771', '0', '0', '0', '1');

-- update quest required npc to fix quest  28879
UPDATE quest_template SET RequiredNpcOrGo1=43878 AND RequiredNpcOrGoCount1=1 WHERE id=28779;

-- add final teleport
DELETE FROM creature WHERE id=45457;
INSERT INTO `creature` VALUES ('335693', '45457', '657', '5035', '5035', '1', '1', '0', '0', '-1197.66', '109.418', '740.707', '1.44061', '300', '0', '0', '5971', '0', '0', '0', '0', '0');

-- create teleport 2 for vortex pinacle for final platform
DELETE FROM creature_template WHERE entry=45457;
INSERT INTO `creature_template` VALUES ('45457', '0', '0', '0', '0', '0', '35080', '0', '0', '0', 'Slipstream', '', 'vehichleCursor', '0', '84', '84', '0', '0', '35', '35', '1', '1', '1', '1', '1', '1', '1', '2', '2', '0', '24', '7.5', '2000', '2000', '1', '1048584', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '4', '1048584', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1112', '0', '0', '', '0', '3', '0', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', 'npc_slipstream_two', '13623');

-- remove hes  auras to becomes visible 
DELETE FROM creature_template_addon WHERE entry=36915;
INSERT INTO `creature_template_addon` VALUES ('36915', '0', '0', '0', '1', '0', '');
