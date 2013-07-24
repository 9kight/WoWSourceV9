DELETE FROM `creature_text` WHERE entry = 34850;
INSERT INTO `creature_text` VALUES 
(34850, 0, 0, 'I want the perimeter secured and the gates manned by two guards at all times. No one gets in, no one gets out.', 12, 0, 100, 0, 0, 19615, 'YELL_PRINCE_LIAM_GREYMANE_1'),
(34850, 1, 0, 'We protected Gilneas from the Scourge. We protected Gilneas during the Northgate rebellion. We will protect Gilneas from whatever this new threat may be.', 12, 0, 100, 0, 0, 19616, 'YELL_PRINCE_LIAM_GREYMANE_2'),
(34850, 2, 0, 'Stand ready, guards! We don\'t know how many intruders we\'re dealing with, but the Headlands are overrun and we\'re cut off from the harbor towns. Expect to be outnumbered.', 12, 0, 100, 0, 0, 19614, 'YELL_PRINCE_LIAM_GREYMANE_2');

DELETE FROM `creature_text` WHERE entry = 34913;
INSERT INTO `creature_text` VALUES 
(34913, 1, 0, 'Stand your ground, men!', 14, 0, 100, 0, 0, 19617, 'YELL_PRINCE_LIAM_GREYMANE_4'),
(34913, 1, 1, 'Defeat these foul beasts!', 14, 0, 100, 0, 0, 19618, 'YELL_PRINCE_LIAM_GREYMANE_5'),
(34913, 1, 2, 'Protect the civilians!', 14, 0, 100, 0, 0, 19619, 'YELL_PRINCE_LIAM_GREYMANE_6'),
(34913, 1, 3, 'Take heart, men! We must protect our city!', 14, 0, 100, 0, 0, 19621, 'YELL_PRINCE_LIAM_GREYMANE_7');

DELETE FROM `creature_text` WHERE entry = 50415;
INSERT INTO `creature_text` VALUES 
(50415, 1, 0, 'You\'ve been bitten by a worgen. It\'s probably nothing, but it sure stings a little.$B$B|TInterfaceIconsINV_Misc_monsterfang_02.blp:32|t', 42, 0, 100, 0, 0, 0, 'Josiah Event Trigger');

UPDATE creature_template
SET ScriptName = 'npc_bloodfang_lurker'
WHERE entry = 35463;
