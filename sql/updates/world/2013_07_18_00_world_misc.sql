DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 6466;

UPDATE `creature_template` SET `mindmg` = '1007', `maxdmg` = '1354.7', `attackpower` = '1571', `dmg_multiplier` = '58', `minrangedmg` = '758.1', `maxrangedmg` = '1062.1', `rangedattackpower` = '220', `AIName` = 'SmartAI' WHERE `entry` =6466;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 6466;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6466, 0, 0, 0, 0, 0, 100, 1, 1000, 25000, 35000, 45000, 11, 22120, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 'Gamon'),
(6466, 0, 1, 0, 0, 0, 100, 1, 5000, 20000, 40000, 50000, 11, 32064, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gamon');

UPDATE `creature_template` SET `equipment_id` = '6466' WHERE `entry` =6466;

DELETE FROM `creature_equip_template` WHERE `entry` = 6466 AND `id` = 2;

DELETE FROM `gameobject` WHERE `guid` IN (100319,100320);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(100319, 205272, 1, 5034, 5466, 1, 1, -9459.27, -974.283, 111.011, 0.0140994, 0, 0, 0.00704962, 0.999975, 300, 0, 1),
(100320, 205273, 1, 5034, 5466, 1, 1, -9458.96, -963.724, 111.012, 3.19576, 0, 0, 0.999633, -0.0270798, 300, 0, 1);

UPDATE `gameobject_template` SET `data0` = '17334' WHERE `entry` =205272;

UPDATE `gameobject_template` SET `data0` = '17609' WHERE `entry` =205273;

UPDATE `creature_template` SET `flags_extra` = '130', `ScriptName` = '' WHERE `entry` =51759;

DELETE FROM `gameobject` WHERE `guid` IN (740,1753,2946,4110,9968,739,1752,2947,4109,9969);

UPDATE `gameobject_template` SET `flags` = '0' WHERE `entry` IN (101850,101851);

DELETE FROM `game_graveyard_zone` WHERE `id` = 1469;
INSERT INTO `game_graveyard_zone` (`id`, `ghost_zone`, `faction`) VALUES
(1469, 25, 0),
(1469, 46, 0),
(1469, 1583, 0),
(1469, 1584, 0),
(1469, 2677, 0),
(1469, 2717, 0),
(1469, 5094, 0);

DELETE FROM `spell_area` WHERE `spell` = 55164 AND `area` = 46;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_start_active`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(55164, 46, 0, 0, 0, 8326, 0, 2, 1, 64, 11);
