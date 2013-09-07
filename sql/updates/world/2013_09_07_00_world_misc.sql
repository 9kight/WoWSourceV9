UPDATE creature SET map=654 WHERE map=655;
UPDATE gameobject SET map=654 WHERE map=655;
DELETE FROM creature WHERE guid IN (7235784,7235163,7235730,7235433,7235115,7235586,7235217,7235685,7235325,7235487,7235099,7235103,7235640,7235101,7235541,7235051,7235796,7235271,7235379);

DELETE FROM creature_template_addon WHERE entry=385;
UPDATE creature_template SET equipment_id=0  WHERE entry=385;

DELETE FROM phase_definitions WHERE zoneId=4714;

UPDATE `quest_template` SET RequiredNpcOrGo1 =0 AND RequiredNpcOrGoCount1=0 WHERE id=14293;

DELETE FROM creature_text WHERE entry=34913;
INSERT INTO `creature_text` VALUES ('34913', '0', '0', 'Push them!', '14', '0', '100', '0', '0', '19620', 'Prince Liam Greymane');
INSERT INTO `creature_text` VALUES ('34913', '0', '1', 'Courage, soldiers! We must protect the city!', '14', '0', '100', '0', '0', '19621', 'Prince Liam Greymane');
INSERT INTO `creature_text` VALUES ('34913', '0', '2', 'Hold on, soldiers!', '14', '0', '100', '0', '0', '19617', 'Prince Liam Greymane');
INSERT INTO `creature_text` VALUES ('34913', '0', '3', 'Protect civilians!', '14', '0', '100', '0', '0', '19619', 'Prince Liam Greymane');
INSERT INTO `creature_text` VALUES ('34913', '0', '4', 'Shoot these beasts!', '14', '0', '100', '0', '0', '19618', 'Prince Liam Greymane');

DELETE FROM creature_text WHERE entry=50415;
INSERT INTO `creature_text` VALUES ('50415', '0', '0', 'This hurts me!', '14', '0', '100', '0', '0', '0', 'Josiah Avery trigger');

UPDATE creature_template SET ScriptName='' WHERE entry =35914;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE entry =35914;
UPDATE creature_template SET ScriptName='npc_commandeered_cannon' WHERE entry =35317; 

UPDATE quest_template SET NextQuestId=14463 WHERE id=14402;

DELETE FROM gameobject WHERE guid IN (2000174,2000175,2000176,2000177,2000178,2000179,2000180);
INSERT INTO `gameobject` VALUES ('2000174', '201607', '654', '4714', '4731', '1', '1032', '-2479.34', '1458.04', '16.8137', '4.06105', '0', '0', '0.896172', '-0.443707', '1', '0', '1');
INSERT INTO `gameobject` VALUES ('2000175', '201607', '654', '4714', '4731', '1', '1032', '-2453.54', '1430.19', '16.795', '4.71338', '0', '0', '0.706758', '-0.707456', '1', '0', '1');
INSERT INTO `gameobject` VALUES ('2000176', '201607', '654', '4714', '4731', '1', '1032', '-2472.99', '1391.15', '16.8076', '4.59796', '0', '0', '0.746383', '-0.665517', '1', '0', '1');
INSERT INTO `gameobject` VALUES ('2000177', '1617', '654', '4714', '4731', '1', '1032', '-2454.36', '1382.48', '16.7936', '4.74349', '0', '0', '0.696027', '-0.718015', '1', '0', '1');
INSERT INTO `gameobject` VALUES ('2000178', '201607', '654', '4714', '4731', '1', '1032', '-2437.16', '1390.63', '16.7936', '6.0431', '0', '0', '0.119755', '-0.992803', '1', '0', '1');
INSERT INTO `gameobject` VALUES ('2000179', '201607', '654', '4714', '4731', '1', '1032', '-2436.9', '1400.68', '16.7952', '5.7069', '0', '0', '0.28417', '-0.958774', '1', '0', '1');
INSERT INTO `gameobject` VALUES ('2000180', '201607', '654', '4714', '4731', '1', '1032', '-2442.26', '1414.68', '16.7941', '0.412521', '0', '0', '0.204801', '0.978804', '1', '0', '1');

DELETE FROM `npc_vendor` WHERE entry='43558';
INSERT INTO `npc_vendor` VALUES ('43558', '0', '5956', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '1', '2324', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '2', '6260', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '3', '4498', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '4', '2320', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '5', '6217', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '6', '3371', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '7', '6256', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '9', '20815', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '10', '39354', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '11', '2678', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '12', '2901', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '13', '2604', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '14', '5042', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '15', '159', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '16', '4289', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '17', '6529', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '18', '30817', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '19', '4470', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '20', '7005', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '21', '4496', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '22', '4540', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '23', '39505', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43558', '24', '2880', '0', '0', '0', '1');
