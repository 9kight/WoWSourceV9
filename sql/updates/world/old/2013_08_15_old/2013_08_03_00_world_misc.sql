DELETE FROM `npc_vendor` WHERE entry='43495';
INSERT INTO `npc_vendor` VALUES ('43495', '0', '2325', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '1', '6260', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '2', '2320', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '3', '38426', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '4', '2321', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '5', '4340', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '6', '2605', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '7', '8343', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '8', '6261', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '9', '10290', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '10', '4342', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '11', '2604', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '12', '14341', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '13', '4289', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '14', '4291', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '15', '7005', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43495', '16', '4341', '0', '0', '0', '1');

DELETE FROM gameobject WHERE guid=106008;
INSERT INTO `gameobject` VALUES ('106008', '203147', '1', '616', '4990', '1', '1', '4940.94', '-2642.01', '1428.6', '0.68275', '0', '0', '0.334783', '0.942295', '300', '0', '1');

UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35 WHERE `entry` = 43487;

UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35 WHERE `entry` = 40843;

UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35 WHERE `entry` = 43378;

DELETE FROM `npc_vendor` WHERE entry='43550';
INSERT INTO `npc_vendor` VALUES ('43550', '0', '2325', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '1', '6260', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '2', '2320', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '3', '38426', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '4', '2321', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '5', '4340', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '6', '2605', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '7', '8343', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '8', '6261', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '9', '10290', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '10', '4342', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '11', '2604', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '12', '14341', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '13', '4289', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '14', '4291', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '15', '7005', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43550', '16', '4341', '0', '0', '0', '1');

DELETE FROM `npc_vendor` WHERE entry='43551';
INSERT INTO `npc_vendor` VALUES ('43551', '0', '63388', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43551', '1', '58274', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43551', '2', '58260', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43551', '3', '4565', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43551', '4', '58256', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43551', '5', '58279', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43551', '7', '64670', '0', '0', '0', '1');

DELETE FROM `creature_template` WHERE `entry`=52838 LIMIT 1;
INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 52838, 0, 0, 0, 0, 0, 31605, 0, 0, 0, "Arch Druid Hamuul Runetotem", "", "Cast", 0, 88, 88, 3, 2233, 2233, 3, 1.0, 1.14286, 1.0, 1, 2409, 3278, 0, 0, 5.4, 2000, 2000, 8, 0, 0, 0, 0, 0, 0, 0, 2409, 3278, 0, 7, 266244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", 0, 3, 234.3606, 48.8295, 1.0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "", "13623");

DELETE FROM `npc_vendor` WHERE entry='43554';
INSERT INTO `npc_vendor` VALUES ('43554', '0', '2325', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '1', '6260', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '2', '2320', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '3', '38426', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '4', '2321', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '5', '4340', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '6', '2605', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '7', '8343', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '8', '6261', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '9', '10290', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '10', '4342', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '11', '2604', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '12', '14341', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '13', '4289', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '14', '4291', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '15', '7005', '0', '0', '0', '1');
INSERT INTO `npc_vendor` VALUES ('43554', '16', '4341', '0', '0', '0', '1');

UPDATE creature_template SET equipment_id=39828 WHERE entry=39828;
DELETE FROM creature_equip_template WHERE entry=39828;
INSERT INTO `creature_equip_template` VALUES ('39828', '1', '51947', '0', '0');

UPDATE `creature_template` SET `faction_A` = 7, `faction_H` = 7 WHERE `entry` = 39752;
