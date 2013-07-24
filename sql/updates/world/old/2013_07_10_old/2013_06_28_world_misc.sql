UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (40567,40197);

UPDATE `creature_template` SET `ScriptName` = 'npc_malignant' WHERE `entry` =39984;

UPDATE `creature_template` SET `ScriptName` = 'npc_trogg_dweller' WHERE `entry` =39450;

DELETE FROM `spell_script_names` WHERE `spell_id` = 74946;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(74946, 'spell_throngus_arrow_barage');

DELETE FROM `waypoint_data` WHERE `id` = 248924;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `inverse_formation_angle`, `wpguid`) VALUES
(248924, 1, -501.159, -481.415, 272.466, 0, 0, 0, 0, 100, 0, 0),
(248924, 2, -504.826, -478.974, 275.276, 0, 0, 0, 0, 100, 0, 0),
(248924, 3, -508.129, -476.775, 276.595, 0, 0, 0, 0, 100, 0, 0),
(248924, 4, -525.265, -476.063, 276.595, 0, 0, 0, 0, 100, 0, 0),
(248924, 5, -542.05, -475.367, 276.597, 0, 0, 0, 0, 100, 0, 0),
(248924, 6, -556.5, -474.767, 276.597, 0, 0, 0, 0, 100, 0, 0),
(248924, 7, -570.455, -490.777, 276.597, 0, 0, 0, 0, 100, 0, 0),
(248924, 8, -522.758, -465.432, 276.597, 0, 0, 0, 0, 100, 0, 0),
(248924, 9, -506.582, -476.494, 276.65, 0, 0, 0, 0, 100, 0, 0),
(248924, 10, -503.972, -478.257, 275.04, 0, 0, 0, 0, 100, 0, 0),
(248924, 11, -498.553, -481.915, 271.916, 0, 0, 0, 0, 100, 0, 0),
(248924, 12, -468.921, -536.557, 271.907, 0, 0, 0, 0, 100, 0, 0),
(248924, 13, -497.454, -581.664, 271.915, 0, 0, 0, 0, 100, 0, 0),
(248924, 14, -500.877, -583.426, 273.8, 0, 0, 0, 0, 100, 0, 0),
(248924, 15, -504.407, -585.242, 276.277, 0, 0, 0, 0, 100, 0, 0),
(248924, 16, -506.373, -586.254, 276.598, 0, 0, 0, 0, 100, 0, 0),
(248924, 17, -558.374, -586.869, 276.597, 0, 0, 0, 0, 100, 0, 0),
(248924, 18, -578.329, -568.528, 276.597, 0, 0, 0, 0, 100, 0, 0),
(248924, 19, -527.065, -594.196, 276.597, 0, 0, 0, 0, 100, 0, 0),
(248924, 20, -508.09, -582.518, 276.612, 0, 0, 0, 0, 100, 0, 0),
(248924, 21, -504.012, -580.008, 274.311, 0, 0, 0, 0, 100, 0, 0),
(248924, 22, -498.647, -576.706, 271.917, 0, 0, 0, 0, 100, 0, 0),
(248924, 23, -471.727, -560.134, 271.908, 0, 0, 0, 0, 100, 0, 0),
(248924, 24, -474.104, -507.122, 271.908, 0, 0, 0, 0, 100, 0, 0),
(248924, 25, -480.982, -497.275, 271.909, 0, 0, 0, 0, 100, 0, 0);

UPDATE `creature` SET `MovementType` = '1' WHERE `guid` =248924;

DELETE FROM `creature_addon` WHERE `guid` = 248924;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(248924, 248924, 0, 0, 0, 0, NULL);

UPDATE `creature_template` SET `faction_A` = '16', `faction_H` = '16' WHERE `entry` =40600;

UPDATE `creature_template` SET `ScriptName` = 'mob_golden_orb' WHERE `entry` =51157;

DELETE FROM `creature_template_addon` WHERE `entry` = 51157;

UPDATE `creature_template` SET `ScriptName` = 'npc_sanotron_500' WHERE `entry` =46185;

