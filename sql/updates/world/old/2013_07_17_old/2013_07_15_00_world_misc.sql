DELETE FROM `creature` WHERE `guid` = 14254;
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(14254, 50248, 0, 4922, 5136, 1, 1, 0, 0, -3890.34, -6473.32, 18.4459, 3.23954, 300, 0, 0, 73685, 0, 0, 0, 0, 0);

DELETE FROM `npc_vendor` WHERE `entry` = 50248;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `type`) VALUES
(50248, 0, 3371, 0, 0, 0, 1),
(50248, 0, 39354, 0, 0, 0, 1),
(50248, 0, 39489, 0, 0, 0, 1),
(50248, 0, 39505, 0, 0, 0, 1),
(50248, 0, 62323, 0, 0, 0, 1),
(50248, 0, 63388, 0, 0, 0, 1),
(50248, 0, 64670, 0, 0, 0, 1),
(50248, 0, 67319, 0, 0, 0, 1),
(50248, 0, 67335, 0, 0, 0, 1),
(50248, 0, 67348, 0, 0, 0, 1),
(50248, 0, 68047, 0, 0, 0, 1),
(50248, 0, 68810, 0, 0, 0, 1);

UPDATE `gameobject_template` SET `data1` = '206586' WHERE `entry` =206586;

DELETE FROM `gameobject_loot_template` WHERE `entry` = 206586;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(206586, 62818, -100, 1, 0, 1, 2);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 48283;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(48283, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 1000, 1000, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wellson Cannon - OOC - Prevent Combat Movement');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` =48283;

DELETE FROM conditions WHERE SourceEntry IN(77917, 77941, 77929, 77940, 78010, 78360, 79025, 80035, 92134);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 77917, 0, 0, 18, 0, 1, 41767, 0, 0, 0, 0, '', 'Launch Hook R - target Stalker'),
(13, 0, 77941, 0, 0, 18, 0, 1, 41767, 0, 0, 0, 0, '', 'Launch Hook L - target Stalker'),
(13, 0, 77929, 0, 0, 18, 0, 1, 41570, 0, 0, 0, 0, '', 'Chain Visual R - target Head'),
(13, 0, 77940, 0, 0, 18, 0, 1, 41570, 0, 0, 0, 0, '', 'Chain Visual L - target Head'),
(13, 0, 78010, 0, 0, 18, 0, 1, 41843, 0, 0, 0, 0, '', 'Pillar Missile - target Pillar of Flame'),
(13, 0, 78360, 0, 0, 18, 0, 1, 41570, 0, 0, 0, 0, '', 'Mangle - target Magmaw'),
(13, 0, 79025, 0, 0, 18, 0, 1, 41570, 0, 0, 0, 0, '', 'Chain Visual - target Head'),
(13, 0, 80035, 0, 0, 18, 0, 1, 42362, 0, 0, 0, 0, '', 'Vengeful Dredge - target Drakonid'),
(13, 0, 92134, 0, 0, 18, 0, 1, 49416, 0, 0, 0, 0, '', 'Ignition - target Bone Construct');

DELETE FROM spell_linked_spell WHERE spell_trigger IN (78941, 91913, 94678, 94679, 88253, 89773, 91912, 94616, 94617);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES 
('78941','78097','0','Parasitic Infection'),
('91913','78097','0','Parasitic Infection'),
('94678','78097','0','Parasitic Infection'),
('94679','78097','0','Parasitic Infection'),
('89773','78412','1','Mangle'),
('91912','78412','1','Mangle'),
('94616','78412','1','Mangle'),
('94617','78412','1','Mangle'),
('88253','88287','0','Massive Crash');

DELETE FROM creature_template_addon WHERE entry IN (41806,42321,49447,51251,48270,51456,51457,51458,51459,51460,51461,51252,51253);
INSERT INTO creature_template_addon (entry, auras) VALUES
(41806,'78019'),
(42321,'78019'),
(51456,'78019'),
(51457,'78019'),
(51458,'78019'),
(51459,'78019'),
(51460,'78019'),
(51461,'78019'),
(49447,'92128'),
(48270,'95478 79011'),
(51251,'95478 79011'),
(51252,'95478 79011'),
(51253,'95478 79011');

UPDATE creature_model_info SET bounding_radius = 0, combat_reach = 15 WHERE modelid = 32679;

UPDATE creature_template SET faction_A = 14, faction_H = 14, exp = 3, minlevel = 88, maxlevel = 88, VehicleId = 0, unit_flags = 33554434 WHERE entry IN (48270,42347,51248,51251);
UPDATE `creature_template` SET `Health_mod` = 1180, `Mana_mod` = 1 WHERE `entry` = 51251;
UPDATE creature_template SET VehicleId = 834, InhabitType = 5 WHERE entry IN (41570, 51101);
UPDATE creature_template SET ScriptName = 'boss_magmaw' WHERE entry = 41570;
UPDATE creature_template SET faction_A = 35, faction_H = 35, unit_flags = 33554434, modelId1 = 34532, modelId2 = 34532, modelId3 = 34532, VehicleId = 833, ScriptName = 'npc_magmaws_pincer' WHERE entry IN(41620,41789);
UPDATE creature_template SET flags_extra = 0, ScriptName = 'npc_spike_stalker' WHERE entry = 41767;
UPDATE creature_template SET spell1 = 77917 WHERE entry = 41789;
UPDATE creature_template SET spell1 = 77941 WHERE entry = 41620;
UPDATE creature_template SET modelid2 = 11686, minlevel = 87, maxlevel = 87, faction_A = 14, faction_H = 14, flags_extra =128, ScriptName = 'npc_pillar_of_flame' WHERE entry = 41843;
UPDATE creature_template SET faction_A = 14, faction_H = 14, ScriptName = 'npc_lava_parasite' WHERE entry IN(41806,42321);
UPDATE creature_template SET faction_A = 14, faction_H = 14 WHERE entry IN(51456,51457,51458,51459,51460,51461);
UPDATE creature_template SET faction_A = 14, faction_H = 14, modelid2 = 11686, flags_extra = 128 WHERE entry = 49447;
UPDATE creature_template SET mindmg = 2014, maxdmg = 2709.4, AIName = '', ScriptName = 'npc_drakonid_drudge' WHERE entry = 42362;
UPDATE creature_template SET InhabitType = 5 WHERE entry = 41767;
UPDATE creature_template SET faction_A = 14, faction_H = 14, minlevel = 88, maxlevel = 88, InhabitType = 5 WHERE entry = 49427;
UPDATE creature_template SET faction_A = 14, faction_H = 14, ScriptName = 'npc_blazing_bone_construct' WHERE entry = 49416;

DELETE FROM `spell_proc_event` WHERE `entry` = 90295;
INSERT INTO `spell_proc_event` (`entry`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`) VALUES
(90295, 0, 4, 4, 8192, 0, 0, 0, 0, 0, 0);

DELETE FROM `npc_vendor` WHERE `entry` = 49386;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `type`) VALUES
(49386, 0, 62423, 0, 0, 0, 1),
(49386, 0, 62424, 0, 0, 0, 1),
(49386, 0, 62425, 0, 0, 0, 1),
(49386, 0, 62426, 0, 0, 0, 1),
(49386, 0, 62428, 0, 0, 0, 1),
(49386, 0, 62429, 0, 0, 0, 1),
(49386, 0, 62431, 0, 0, 0, 1),
(49386, 0, 62432, 0, 0, 0, 1),
(49386, 0, 62433, 0, 0, 0, 1),
(49386, 0, 62434, 0, 0, 0, 1),
(49386, 0, 65908, 0, 0, 0, 1);

DELETE FROM `npc_trainer` WHERE `npc_trainer`.`entry` = 200403 AND `spell` = 82175;

DELETE FROM `npc_trainer` WHERE `npc_trainer`.`entry` = 200433 AND `spell` = 82175;
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
(200403, 82175, 50000, 202, 0, 0),
(200433, 82175, 50000, 202, 0, 0);

DELETE FROM `areatrigger_teleport` WHERE `id` IN (5046,5047);
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(5046, 'The Door Sholazar (Ausgang)', 1, -6170.627, -1324.003, -172.337, 2.33),
(5047, 'The Door Sholazar (Eingang)', 571, 4904.482, 5185.1826, -93.158, 0.445);

DELETE FROM `creature_template_addon` WHERE `entry` = 47829;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(47829, 0, 0, 0, 0, 0, '88999');
