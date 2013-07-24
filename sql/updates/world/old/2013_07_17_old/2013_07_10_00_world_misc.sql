DELETE FROM `conditions` WHERE `SourceEntry` IN (94564,76638,84513,94565,82621,76639,84515,85545);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 94565, 0, 0, 27, 0, 80, 3, 0, 0, 48, 48, '', 'Hyjal Levelaccess HORDE'),
(17, 0, 76639, 0, 0, 27, 0, 80, 3, 0, 0, 48, 48, '', 'Vashiir Levelaccess HORDE'),
(17, 0, 84513, 0, 0, 27, 0, 82, 3, 0, 0, 48, 48, '', 'Deepholm Levelaccess HORDE'),
(17, 0, 94564, 0, 0, 27, 0, 83, 3, 0, 0, 48, 48, '', 'Uldum Levelaccess HORDE'),
(17, 0, 82621, 0, 0, 27, 0, 84, 3, 0, 0, 48, 48, '', 'TwilightHighland Levelaccess HORDE'),

(17, 0, 76638, 0, 0, 27, 0, 80, 3, 0, 0, 48, 48, '', 'Vashiir Levelaccess ALLIANCE'),
(17, 0, 84515, 0, 0, 27, 0, 82, 3, 0, 0, 48, 48, '', 'Deepholm Levelaccess ALLIANCE'),
(17, 0, 85545, 0, 0, 27, 0, 84, 3, 0, 0, 48, 48, '', 'TwilightHighland Levelaccess ALLIANCE');

DELETE FROM `spell_target_position` WHERE `id` IN (76639,76638);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(76639, 0, -5671.02, 3720.07, 2, 0),
(76638, 0, -5310.85, 3914.41, 4.22, 0.01);

UPDATE `gameobject` SET `spawntimesecs` = '2700' WHERE `id` IN (202741,202738,202739,202736,202740,202737);
