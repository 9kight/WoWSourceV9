
-- Delete Stonetalone Montain duplicates and Southern Barrens 
DELETE FROM creature WHERE guid IN (126614,98446,97205,97075,91112,91741,126633,90647,126848,108083,126378,106735,108032,138975,138981,138979,107307,138786,138787,124979,124973,124950);
DELETE FROM creature WHERE guid IN (106868,107131,107452,124940,106923,107819,124881,106992,124862,124928,107782,107163,124917,124922,124926,124912,107723,107963,106866,124890,108177);
DELETE FROM creature WHERE guid IN (107745,106958,106979,124915,124916,108184,108353,106805,108214,108059,108050,106793,124864,125027,107530,124997,138482,138490,138489,138467,138473,138186);
DELETE FROM creature WHERE guid IN (138480,138498,138493,138504,138492,138531,138529,138544,138545,138547,138552,101793,101975,138561,138566,138576,138589,102237,101843,101389,80175,80099,80088);
DELETE FROM creature WHERE guid IN (103517,72678,103300,103098,102873,103940,103722,72669,103244,102410,102343,125366,125365,125361,125362,125357,125360,125378,125377,125379,125386,107728,125445,107703);
DELETE FROM creature WHERE guid IN (107701,108072,125482);

-- update the  rong npc equipments
UPDATE creature_template SET equipment_id=0 WHERE entry=3246;
DELETE FROM creature_equip_template WHERE entry=3246;

UPDATE creature_template SET equipment_id=0 WHERE entry=3242;
DELETE FROM creature_equip_template WHERE entry=3242;

UPDATE creature_template SET equipment_id=0 WHERE entry=3632;
DELETE FROM creature_equip_template WHERE entry=3632;

UPDATE creature_template SET equipment_id=0 WHERE entry=3630;
DELETE FROM creature_equip_template WHERE entry=3630;

UPDATE creature_template SET equipment_id=0 WHERE entry=3633;
DELETE FROM creature_equip_template WHERE entry=3633;

UPDATE `creature_template` SET `faction_A`='1077', `faction_H`='1077' WHERE entry=37180;

UPDATE `creature_template` SET `faction_A`='1077', `faction_H`='1077' WHERE entry=37216;

UPDATE creature_template SET equipment_id=0 WHERE entry=3277;
DELETE FROM creature_equip_template WHERE entry=3277;

UPDATE creature_template SET equipment_id=0 WHERE entry=3276;
DELETE FROM creature_equip_template WHERE entry=3276;

UPDATE creature_template SET equipment_id=0 WHERE entry=3256;
DELETE FROM creature_equip_template WHERE entry=3256;

UPDATE creature_template SET equipment_id=0 WHERE entry=3241;
DELETE FROM creature_equip_template WHERE entry=3241;

DELETE FROM creature_addon WHERE guid IN (106868,101389);

-- add missing objects and  npc
DELETE FROM gameobject WHERE guid IN (178876,178877);
INSERT INTO `gameobject` VALUES ('178876', '21631', '1', '17', '17', '1', '1', '787.327', '-1820.39', '91.6666', '6.01802', '0', '0', '0.132194', '-0.991224', '300', '0', '1');
INSERT INTO `gameobject` VALUES ('178877', '192628', '1', '17', '17', '1', '1', '785.361', '-1818.39', '91.6666', '6.01802', '0', '0', '0.132194', '-0.991224', '300', '0', '1');

DELETE FROM creature WHERE guid=72678;
INSERT INTO `creature` VALUES ('72678', '3682', '1', '17', '17', '1', '1', '0', '3682', '789.012', '-1812.86', '91.6676', '4.10623', '300', '0', '0', '2578', '0', '0', '0', '0', '0');

-- update  zeppelin  announce  from normal text to  yell state
UPDATE  creature_text SET type=14 WHERE entry IN (9564,12136,26537,34765,9566,3150,26539,26540);
