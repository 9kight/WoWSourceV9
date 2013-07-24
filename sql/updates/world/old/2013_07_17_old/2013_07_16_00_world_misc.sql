DELETE FROM `gameobject` WHERE `guid` = 59256;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(59256, 205365, 755, 0, 0, 3, 1, -10953.2, -1390.1, 10.3857, 5.20227, 1.1911e-43, 0, 0.514529, -0.857473, 300, 255, 1);

DELETE FROM `creature_template_addon` WHERE `entry` = 48092;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(48092, 0, 0, 0, 0, 0, '89698');

DELETE FROM `creature` WHERE `guid` IN (301535,301536);
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(301535, 48092, 755, 5396, 5633, 3, 1, 0, 0, -10997.2, -1356.64, 10.8063, 4.78806, 300, 0, 0, 56681, 0, 0, 0, 0, 0),
(301536, 48097, 755, 5396, 5633, 3, 65535, 0, 0, -10967.2, -1362.62, 35.571, 5.12464, 300, 0, 0, 5971, 0, 0, 0, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (86911, 87517, 86715, 87328);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 86911, 0, 18, 1, 46492, 0, 0, '', 'Unstable Grounding Field spell - target Grounding Fields'),
(13, 0, 87517, 0, 18, 1, 47000, 0, 0, '', 'Grounding Field spell - target Grounding Fields'),
(13, 0, 86715, 0, 18, 1, 46387, 0, 0, '', 'Supremacy of the Storm spell - target Storm Target'),
(13, 0, 87328, 0, 18, 1, 46492, 0, 0, '', 'Supremacy of the Storm spell - target Unstable Grounding Field');

UPDATE `creature_template` SET `speed_run` = 0.35, `speed_walk` = 0.35, `minlevel` = 84, `maxlevel` = 84, `faction_A` = 14, `faction_H` = 14, `unit_flags` = 0x2000000, `flags_extra` = 130, ScriptName = 'npc_asaad_grounding_field_trigger' WHERE `entry` = 46492;
UPDATE `creature_template` SET `speed_run` = 0.35, `speed_walk` = 0.35,`minlevel` = 84, `maxlevel` = 84, `faction_A` = 14, `faction_H` = 14, `unit_flags` = 0x2000000, `flags_extra` = 130 WHERE `entry` = 47000;
UPDATE `creature_template` SET `minlevel` = 84, `maxlevel` = 84, `faction_A` = 14, `faction_H` = 14, `unit_flags` = 0x2000000, `flags_extra` = 130 WHERE `entry`= 46387;
