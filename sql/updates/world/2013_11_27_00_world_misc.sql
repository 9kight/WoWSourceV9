-- Tanaris Duplicates
DELETE FROM creature WHERE guid IN (134617,134636,134618);
-- Insert items into the vendor list
DELETE FROM `npc_vendor` WHERE entry='38847';
INSERT INTO `npc_vendor` VALUES ('38847', '0', '4497', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('38847', '1', '4499', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('38847', '2', '1205', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('38847', '3', '4542', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('38847', '4', '1645', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('38847', '5', '159', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('38847', '6', '4470', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('38847', '7', '4601', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('38847', '8', '1708', '0', '0', '0', '1');
-- Update flag to become vendor
UPDATE creature_template SET npcflag=128 WHERE entry=38847;

-- The Forsaken Front
DELETE FROM creature WHERE guid IN (59416,59333,59330,59329,59332);

-- Shadowfang Keep 5 Normal duplicates
DELETE FROM creature WHERE guid IN (302396,302353,302352,302476,302373,302444,302376,302409,302472,302365,302463,302358,302394,302315,302388,302318,302398,302383,302397,302282,302471,302407);

-- Update creatures Equipment
UPDATE creature_template SET equipment_id=0 WHERE entry IN (3865,3864,1502);

-- Horde quest giver action and postion
UPDATE creature_template SET faction_A=7, faction_H=68 WHERE entry=47293;
DELETE FROM creature WHERE guid=134617;
INSERT INTO `creature` VALUES ('134617', '47293', '33', '209', '209', '1', '1', '0', '47293', '-222.066', '2123.99', '80.3611', '4.37582', '300', '0', '0', '5004', '0', '0', '0', '0', '0');

-- Alliance quest giver faction and postion
UPDATE creature_template SET faction_A=11, faction_H=7 WHERE entry=47006;
DELETE FROM creature WHERE guid=134618;
INSERT INTO `creature` VALUES ('134618', '47006', '33', '209', '209', '1', '1', '0', '0', '-221.347', '2137.15', '80.8887', '4.47008', '300', '0', '0', '9680', '0', '0', '0', '0', '0');

-- The Blood Furnance Instance
-- rong unit flag makes untargetable
UPDATE creature_template SET unit_flags=0, mechanic_immune_mask=0 WHERE entry=17398;
-- rong unit flag makes untargetable
UPDATE creature_template SET unit_flags=0 WHERE entry=17380;
-- rong unit flag makes untargetable
UPDATE creature_template SET unit_flags=0 WHERE entry=17377;
-- Open door from The Shatterd Halls
UPDATE gameobject_template SET flags=33 WHERE entry=184912;
