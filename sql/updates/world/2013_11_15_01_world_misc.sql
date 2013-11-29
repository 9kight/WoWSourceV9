-- Creature text for Mennu the Betrayer
SET @ENTRY = 17941;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'The work must continue.', 14, 0, 100, 0, 0, 10376, 'Mennu the Betrayer - Aggro'),
(@ENTRY, 0, 1, 'You brought this on yourselves.', 14, 0, 100, 0, 0, 10378, 'Mennu the Betrayer - Aggro'),
(@ENTRY, 0, 2, 'Don''t make me kill you!', 14, 0, 100, 0, 0, 10379, 'Mennu the Betrayer - Aggro'),
(@ENTRY, 1, 0, 'It had to be done.', 14, 0, 100, 0, 0, 10380, 'Mennu the Betrayer - Kill'),
(@ENTRY, 1, 1, 'You should not have come.', 14, 0, 100, 0, 0, 10381, 'Mennu the Betrayer - Kill'),
(@ENTRY, 2, 0, 'I... Deserve this.', 14, 0, 100, 0, 0, 10382, 'Mennu the Betrayer - Death');

-- Creature text for Dalliah the Doomsayer
SET @ENTRY = 20885;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'Don''t worry about me; kill that worthless dullard instead!', 14, 0, 100, 0, 0, 11085, 'Dalliah the Doomsayer - Aggro Soccothrates First'),
(@ENTRY, 1, 0, 'It is unwise to anger me.', 14, 0, 100, 0, 0, 11086, 'Dalliah the Doomsayer - Aggro'),
(@ENTRY, 2, 0, 'Completely ineffective. Just like someone else I know.', 14, 0, 100, 0, 0, 11087, 'Dalliah the Doomsayer - Kill'),
(@ENTRY, 2, 1, 'You chose the wrong opponent.', 14, 0, 100, 0, 0, 11088, 'Dalliah the Doomsayer - Kill'),
(@ENTRY, 3, 0, 'Reap the Whirlwind!', 14, 0, 100, 0, 0, 11089, 'Dalliah the Doomsayer - Cast Whirlwind'),
(@ENTRY, 3, 1, 'I''ll cut you to pieces!', 14, 0, 100, 0, 0, 11090, 'Dalliah the Doomsayer - Cast Whirlwind'),
(@ENTRY, 4, 0, 'Ahh... That is much better.', 14, 0, 100, 0, 0, 11091, 'Dalliah the Doomsayer - Cast Heal'),
(@ENTRY, 4, 1, 'Ahh... Just what I needed.', 14, 0, 100, 0, 0, 11092, 'Dalliah the Doomsayer - Cast Heal'),
(@ENTRY, 5, 0, 'Now I''m really... angry...', 14, 0, 100, 0, 0, 11093, 'Dalliah the Doomsayer - Death'),
(@ENTRY, 6, 0, 'More than you can handle, scryer?', 14, 0, 100, 0, 0, 11094, 'Dalliah the Doomsayer - Soccothrates at 25%'),
(@ENTRY, 6, 1, 'I suppose I''ll end up fighting them all myself.', 14, 0, 100, 0, 0, 11095, 'Dalliah the Doomsayer - Soccothrates at 25%'),
(@ENTRY, 6, 2, 'I''ve grown used to cleaning up your messes.', 14, 0, 100, 0, 0, 11096, 'Dalliah the Doomsayer - Soccothrates at 25%'),
(@ENTRY, 7, 0, 'Congratulations. I''ve wanted to do that for years.', 14, 0, 100, 0, 0, 11097, 'Dalliah the Doomsayer - Soccothratess dies');

-- Creature text for Wrath-Scryer Soccothrates
SET @ENTRY = 20886;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'Have you come to kill Dalliah? Can I watch?', 14, 0, 100, 0, 0, 11237, 'Wrath-Scryer Soccothrates - Aggro Dalliah First'),
(@ENTRY, 1, 0, 'At last, a target for my frustrations!', 14, 0, 100, 0, 0, 11238, 'Wrath-Scryer Soccothrates - Aggro'),
(@ENTRY, 2, 0, 'Yes, that was quite satisfying', 14, 0, 100, 0, 0, 11239, 'Wrath-Scryer Soccothrates - Kill'),
(@ENTRY, 3, 0, 'On guard!', 14, 0, 100, 0, 0, 11241, 'Wrath-Scryer Soccothrates - Charge'),
(@ENTRY, 3, 1, 'Defend yourself, for all the good it will do...', 14, 0, 100, 0, 0, 11242, 'Wrath-Scryer Soccothrates - Charge'),
(@ENTRY, 4, 0, 'Knew this was... the only way out', 14, 0, 100, 0, 0, 11243, 'Wrath-Scryer Soccothrates - Death'),
(@ENTRY, 5, 0, 'Having problems, Dalliah? How nice.', 14, 0, 100, 0, 0, 11244, 'Wrath-Scryer Soccothrates - Dalliah at 25%'),
(@ENTRY, 5, 1, 'This may be the end of you Dalliah, what a shame that would be.', 14, 0, 100, 0, 0, 11245, 'Wrath-Scryer Soccothrates - Dalliah at 25%'),
(@ENTRY, 5, 2, 'I suggest a new strategy, you draw the attackers while I gather reinforcements. Hahaha!', 14, 0, 100, 0, 0, 11246, 'Wrath-Scryer Soccothrates - Dalliah at 25%'),
(@ENTRY, 6, 0, 'Finally! Well done!', 14, 0, 100, 0, 0, 11247, 'Wrath-Scryer Soccothrates - Dalliah dies');



UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (20813,20815,20816,20814);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20813,20815,20816,20814) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20813,0,0,0,8,0,100,0,35724,0,0,0,33,20813,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zeth''Gor Quest Credit Marker, Barracks - On Spell Hit (Throw Torch) - Quest Credit'),
(20814,0,0,0,8,0,100,0,35724,0,0,0,33,20814,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zeth''Gor Quest Credit Marker, Stable - On Spell Hit (Throw Torch) - Quest Credit'),
(20815,0,0,0,8,0,100,0,35724,0,0,0,33,20815,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zeth''Gor Quest Credit Marker, East Hovel - On Spell Hit (Throw Torch) - Quest Credit'),
(20816,0,0,0,8,0,100,0,35724,0,0,0,33,20816,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zeth''Gor Quest Credit Marker, West Hovel - On Spell Hit (Throw Torch) - Quest Credit');

UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry` =29811;
DELETE FROM `smart_scripts` WHERE `entryorguid` =29811;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29811,0,0,1,62,0,100,0,9843,0,0,0,15,12864,0,0,0,0,0,7,0,0,0,0,0,0,0,'Frostborn Scout - On Gossip Select - Give Quest Credit'),
(29811,0,1,0,61,0,100,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frostborn Scout - Linked with Previous Event - Despawn'),
(29811,0,2,0,25,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frostborn Scout - On Spawn - Set Bytes 1');


-- add missing creatures
DELETE FROM `creature_template_addon` WHERE `entry`=3617;
INSERT INTO `creature_template_addon` VALUES ('3617', '0', '0', '0', '0', '0', '34426');

SET @GUID := 334436;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+37;
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@GUID, 3617, 0, 85, 85, 1, 1, 0, 0, 1834.213, 249.057, 59.82264, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+1, 3617, 0, 85, 85, 1, 1, 0, 0, 1823.905, 252.862, 60.02497, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+2, 3617, 0, 85, 85, 1, 1, 0, 0, 1829.434, 259.207, 59.58340, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+3, 3617, 0, 85, 85, 1, 1, 0, 0, 1819.516, 264.184, 59.89560, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+4, 3617, 0, 85, 85, 1, 1, 0, 0, 1806.351, 265.815, 65.39972, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+5, 3617, 0, 85, 85, 1, 1, 0, 0, 1816.986, 281.063, 70.39969, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+6, 3617, 0, 85, 85, 1, 1, 0, 0, 1831.261, 282.122, 70.39969, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+7, 3617, 0, 85, 85, 1, 1, 0, 0, 1843.583, 278.447, 70.39969, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+8, 3617, 0, 85, 85, 1, 1, 0, 0, 1794.100, 284.269, 70.39969, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+9, 3617, 0, 85, 85, 1, 1, 0, 0, 1769.915, 285.161, 70.39969, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+10, 3617, 0, 85, 85, 1, 1, 0, 0, 1806.014, 254.011, 60.65592, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+11, 3617, 0, 85, 85, 1, 1, 0, 0, 1782.721, 267.958, 59.61376, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+12, 3617, 0, 85, 85, 1, 1, 0, 0, 1783.947, 251.046, 59.50742, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+13, 3617, 0, 85, 85, 1, 1, 0, 0, 1782.661, 226.650, 59.36586, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+14, 3617, 0, 85, 85, 1, 1, 0, 0, 1785.052, 210.563, 59.70694, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+15, 3617, 0, 85, 85, 1, 1, 0, 0, 1805.750, 210.858, 65.39980, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+16, 3617, 0, 85, 85, 1, 1, 0, 0, 1803.131, 192.819, 70.39975, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+17, 3617, 0, 85, 85, 1, 1, 0, 0, 1819.385, 193.334, 70.39975, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+18, 3617, 0, 85, 85, 1, 1, 0, 0, 1841.260, 196.939, 70.39975, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+19, 3617, 0, 85, 85, 1, 1, 0, 0, 1788.094, 193.416, 70.39975, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+20, 3617, 0, 85, 85, 1, 1, 0, 0, 1768.284, 193.266, 70.39975, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+21, 3617, 0, 85, 85, 1, 1, 0, 0, 1836.373, 229.404, 60.23154, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+22, 3617, 0, 85, 85, 1, 1, 0, 0, 1830.285, 213.645, 60.38905, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+23, 3617, 0, 85, 85, 1, 1, 0, 0, 1817.453, 225.251, 59.52800, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+24, 3617, 0, 85, 85, 1, 1, 0, 0, 1820.128, 250.549, 60.04744, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+25, 3617, 0, 85, 85, 1, 1, 0, 0, 1805.220, 291.655, 70.39964, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+26, 3617, 0, 85, 85, 1, 1, 0, 0, 1846.193, 271.665, 70.39966, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+27, 3617, 0, 85, 85, 1, 1, 0, 0, 1797.379, 321.783, 70.81464, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+28, 3617, 0, 85, 85, 1, 1, 0, 0, 1795.755, 336.788, 70.81464, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+29, 3617, 0, 85, 85, 1, 1, 0, 0, 1816.091, 339.486, 70.81320, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+30, 3617, 0, 85, 85, 1, 1, 0, 0, 1818.251, 324.754, 70.81323, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+31, 3617, 0, 85, 85, 1, 1, 0, 0, 1806.574, 325.978, 70.39765, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+32, 3617, 0, 85, 85, 1, 1, 0, 0, 1806.596, 337.597, 70.39765, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+33, 3617, 0, 85, 85, 1, 1, 0, 0, 1779.739, 208.601, 60.31278, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+34, 3617, 0, 85, 85, 1, 1, 0, 0, 1774.185, 238.088, 60.69822, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+35, 3617, 0, 85, 85, 1, 1, 0, 0, 1784.677, 238.470, 60.40865, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+36, 3617, 0, 85, 85, 1, 1, 0, 0, 1821.226, 239.487, 60.64784, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0),
(@GUID+37, 3617, 0, 85, 85, 1, 1, 0, 0, 1837.954, 238.254, 60.51441, 0, 300, 5, 0, 656, 0, 1, 0, 0, 0);

DELETE FROM `npc_vendor` WHERE `entry` IN(33238,33239);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `type`) VALUES
(33238, 24, 33443, 0, 0, 0, 1),
(33238, 26, 35952, 0, 0, 0, 1),
(33238, 23, 33454, 0, 0, 0, 1),
(33238, 21, 33449, 0, 0, 0, 1),
(33238, 22, 33451, 0, 0, 0, 1),
(33238, 25, 35949, 0, 0, 0, 1),
(33238, 30, 35950, 0, 0, 0, 1),
(33238, 27, 35953, 0, 0, 0, 1),
(33238, 28, 35951, 0, 0, 0, 1),
(33238, 29, 35948, 0, 0, 0, 1),
(33238, 2, 5237, 0, 0, 0, 1),
(33238, 3, 5565, 0, 0, 0, 1),
(33238, 4, 16583, 0, 0, 0, 1),
(33238, 1, 3775, 0, 0, 0, 1),
(33238, 6, 17030, 0, 0, 0, 1),
(33238, 9, 17033, 0, 0, 0, 1),
(33238, 10, 21177, 0, 0, 0, 1),
(33238, 8, 17032, 0, 0, 0, 1),
(33238, 5, 17020, 0, 0, 0, 1),
(33238, 7, 17031, 0, 0, 0, 1),
(33238, 16, 43235, 0, 0, 0, 1),
(33238, 13, 41586, 0, 0, 0, 1),
(33238, 11, 37201, 0, 0, 0, 1),
(33238, 14, 43231, 0, 0, 0, 1),
(33238, 15, 43233, 0, 0, 0, 1),
(33238, 18, 44605, 0, 0, 0, 1),
(33238, 19, 44614, 0, 0, 0, 1),
(33238, 17, 43237, 0, 0, 0, 1),
(33238, 12, 41584, 0, 0, 0, 1),
(33238, 20, 44615, 0, 0, 0, 1),
(33239, 24, 33443, 0, 0, 0, 1),
(33239, 26, 35952, 0, 0, 0, 1),
(33239, 23, 33454, 0, 0, 0, 1),
(33239, 21, 33449, 0, 0, 0, 1),
(33239, 22, 33451, 0, 0, 0, 1),
(33239, 25, 35949, 0, 0, 0, 1),
(33239, 30, 35950, 0, 0, 0, 1),
(33239, 27, 35953, 0, 0, 0, 1),
(33239, 28, 35951, 0, 0, 0, 1),
(33239, 29, 35948, 0, 0, 0, 1),
(33239, 2, 5237, 0, 0, 0, 1),
(33239, 3, 5565, 0, 0, 0, 1),
(33239, 4, 16583, 0, 0, 0, 1),
(33239, 1, 3775, 0, 0, 0, 1),
(33239, 6, 17030, 0, 0, 0, 1),
(33239, 9, 17033, 0, 0, 0, 1),
(33239, 10, 21177, 0, 0, 0, 1),
(33239, 8, 17032, 0, 0, 0, 1),
(33239, 5, 17020, 0, 0, 0, 1),
(33239, 7, 17031, 0, 0, 0, 1),
(33239, 16, 43235, 0, 0, 0, 1),
(33239, 13, 41586, 0, 0, 0, 1),
(33239, 11, 37201, 0, 0, 0, 1),
(33239, 14, 43231, 0, 0, 0, 1),
(33239, 15, 43233, 0, 0, 0, 1),
(33239, 18, 44605, 0, 0, 0, 1),
(33239, 19, 44614, 0, 0, 0, 1),
(33239, 17, 43237, 0, 0, 0, 1),
(33239, 12, 41584, 0, 0, 0, 1),
(33239, 20, 44615, 0, 0, 0, 1);

-- Blazerunner's Script from EAI to SAI
UPDATE creature_template SET npcflag=129 WHERE entry IN (33238,33239);
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 9376;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=9376;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9376 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9376, 0, 0, 0,11, 0, 100, 0, 0, 0, 0, 0, 11, 13913, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blazerunner - On Spawn - Cast Blazerunner Aura'),
(9376, 0, 1, 0, 9, 0, 100, 0, 0, 10, 10000, 20000, 11, 17277, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blazerunner - On Range - Cast Blast Wave'),
(9376, 0, 2, 0, 8, 0, 100, 0, 14247, 0, 0, 0, 28, 13913, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blazerunner - On Spellhit (Blazerunner Dispel) - Remove Blazerunner Aura');


-- DB/Misc: Astor Hadren
DELETE FROM `smart_scripts` WHERE `entryorguid`=6497;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6497, 0, 0, 1, 62, 0, 100, 0, 125, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - On Gossip Select - Close Menu'),
(6497, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - Linked with Previous Event - Set Hostile'),
(6497, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 55, 120000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - Linked with Previous Event - Stop WP'),
(6497, 0, 3, 4, 11, 0, 100, 0, 0, 0, 0, 0, 2, 68, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - On Spawn - Set Friendly'),
(6497, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 6497, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - Linked with previous Event - Start WP'),
(6497, 0, 5, 0, 64, 0, 100, 0, 0, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astor Hadren - On Gossip Hello - Pause WP');

UPDATE `creature` SET `MovementType`=0 WHERE `guid`=24990;
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid`=24990;

DELETE FROM `waypoints` WHERE `entry`=6497;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(6497, 1, 1597.4, 566.768, 37.8602, 'Astor Hadren'),
(6497, 2, 1613.91, 562.333, 35.146, 'Astor Hadren'),
(6497, 3, 1631.83, 557.812, 33.7566, 'Astor Hadren'),
(6497, 4, 1661.1, 550.278, 33.3758, 'Astor Hadren'),
(6497, 5, 1689.98, 545.014, 33.4033, 'Astor Hadren'),
(6497, 6, 1714.5, 540.561, 33.6137, 'Astor Hadren'),
(6497, 7, 1737.88, 533.75, 33.3961, 'Astor Hadren'),
(6497, 8, 1772.23, 525.741, 33.3961, 'Astor Hadren'),
(6497, 9, 1802.45, 516.861, 33.4219, 'Astor Hadren'),
(6497, 10, 1836.05, 504.973, 34.1916, 'Astor Hadren'),
(6497, 11, 1850.21, 496.778, 34.6882, 'Astor Hadren'),
(6497, 12, 1867.39, 481.534, 34.5889, 'Astor Hadren'),
(6497, 13, 1877.67, 463.224, 34.1472, 'Astor Hadren'),
(6497, 14, 1890.49, 434.482, 33.8649, 'Astor Hadren'),
(6497, 15, 1898.6, 404.11, 34.3546, 'Astor Hadren'),
(6497, 16, 1909.06, 371.483, 34.0201, 'Astor Hadren'),
(6497, 17, 1927.47, 333.806, 35.1605, 'Astor Hadren'),
(6497, 18, 1948.33, 293.56, 38.7782, 'Astor Hadren'),
(6497, 19, 1960.17, 272.962, 38.3855, 'Astor Hadren'),
(6497, 20, 1981.05, 237.328, 36.6631, 'Astor Hadren'),
(6497, 21, 1955.89, 236.574, 41.3907, 'Astor Hadren'),
(6497, 22, 1922.53, 240.366, 49.3415, 'Astor Hadren'),
(6497, 23, 1938.41, 259.961, 44.9292, 'Astor Hadren'),
(6497, 24, 1949.26, 286.982, 38.8665, 'Astor Hadren'),
(6497, 25, 1941.21, 306.375, 37.5792, 'Astor Hadren'),
(6497, 26, 1927.42, 334.68, 35.107, 'Astor Hadren'),
(6497, 27, 1912.91, 362.632, 33.9933, 'Astor Hadren'),
(6497, 28, 1899.77, 399.685, 34.2583, 'Astor Hadren'),
(6497, 29, 1894.23, 419.938, 34.2863, 'Astor Hadren'),
(6497, 30, 1883.81, 449.623, 33.9371, 'Astor Hadren'),
(6497, 31, 1865.35, 482.581, 34.6089, 'Astor Hadren'),
(6497, 32, 1839.53, 502.555, 34.3171, 'Astor Hadren'),
(6497, 33, 1810.76, 513.551, 33.4393, 'Astor Hadren'),
(6497, 34, 1780.72, 522.962, 33.3959, 'Astor Hadren'),
(6497, 35, 1744.62, 532.56, 33.3959, 'Astor Hadren'),
(6497, 36, 1713.98, 539.842, 33.5092, 'Astor Hadren'),
(6497, 37, 1683.12, 546.073, 33.4104, 'Astor Hadren'),
(6497, 38, 1642.1, 554.955, 33.448, 'Astor Hadren'),
(6497, 39, 1612.29, 563.53, 35.3895, 'Astor Hadren');

-- DB/Misc: The Broken Front
UPDATE `creature_template` SET `gossip_menu_id`=10036 WHERE `entry`=31273;
DELETE FROM `gossip_menu` WHERE `entry`IN(10036,10037);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10036, 13930),
(10037, 13931);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10036;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(10036, 0, 0, 'Hold on friend. Tell me what happened here.', 1, 1, 10037, 0, 0, 0, NULL);
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=31273;
DELETE FROM `smart_scripts` WHERE `entryorguid` =31273;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31273, 0, 0, 0, 62, 0, 100, 0, 10036, 0, 0, 0, 33, 31272, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dying Berserker - On Gossip Select - Give Kill Credit');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10036;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10036,0,0,0,9,0,13228,0,0,0,0,'','Dying Berserker show gossip only if player on quest The Broken Front');

-- [11258] [11247] Burn Skorn ,Burn

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(24098,24100,24102);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24098,24100,24102);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24102, 0, 0, 0, 8,  0, 100, 0, 43057, 0, 0, 0, 11, 43065 , 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Barraks Bunny - On Spellhit  - Cast Burn Skorn, Burn!: Barracks Kill Credit'),
(24098, 0, 0, 0, 8,  0, 100, 0, 43057, 0, 0, 0, 11, 43058 , 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Longhouse NW Bunny - On Spellhit - Cast Burn Skorn, Burn!: NW Kill Credit'),
(24100, 0, 0, 0, 8,  0, 100, 0, 43057, 0, 0, 0, 11, 43061 , 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Longhouse NE Bunny - On Spellhit - Cast Burn Skorn, Burn!: NE Kill Credit');

-- [11259] [11245] Towers of Certain Doom

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(24087,24092,24093,24094);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24087,24092,24093,24094) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =2408700 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24087, 0, 0, 2, 8,  0, 100, 0, 49625, 0, 15000, 15000, 11, 43067 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower NW Bunny - On Spellhit - Cast Towers of Certain Doom: NW Kill Credit'),
(24092, 0, 0, 2, 8,  0, 100, 0, 49625, 0, 15000, 15000, 11, 43077 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower E Bunny - On Spellhit - Cast Towers of Certain Doom: E Kill Credit'),
(24093, 0, 0, 2, 8,  0, 100, 0, 49625, 0, 15000, 15000, 11, 43086 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SW Bunny - On Spellhit - Cast Towers of Certain Doom: SW Kill Credit'),
(24094, 0, 0, 2, 8,  0, 100, 0, 49625, 0, 15000, 15000, 11, 43087 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SE Bunny - On Spellhit - Cast Towers of Certain Doom: SE Kill Credit'),
(24087, 0, 1, 2, 8,  0, 100, 0, 49634, 0, 15000, 15000, 11, 43067 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower NW Bunny - On Spellhit - Cast Towers of Certain Doom: NW Kill Credit'),
(24092, 0, 1, 2, 8,  0, 100, 0, 49634, 0, 15000, 15000, 11, 43077 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower E Bunny - On Spellhit - Cast Towers of Certain Doom: E Kill Credit'),
(24093, 0, 1, 2, 8,  0, 100, 0, 49634, 0, 15000, 15000, 11, 43086 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SW Bunny - On Spellhit - Cast Towers of Certain Doom: SW Kill Credit'),
(24094, 0, 1, 2, 8,  0, 100, 0, 49634, 0, 15000, 15000, 11, 43087 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SE Bunny - On Spellhit - Cast Towers of Certain Doom: SE Kill Credit'),
(24087, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 80, 2408700 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower NW Bunny - Linked with Previous Event - Run Timed Script'),
(24092, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 80, 2408700 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower E Bunny - Linked with Previous Event - Run Timed Script'),
(24093, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 80, 2408700 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SW Bunny - Linked with Previous Event - Run Timed Script'),
(24094, 0, 2, 0, 61,  0, 100, 0, 0, 0, 0, 0, 80, 2408700 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower SE Bunny - Linked with Previous Event - Run Timed Script'),
(2408700, 9, 0, 0, 0,  0, 100, 0, 2000, 2000, 0, 0, 11, 56511 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower Bunny - Script - Cast Towers of Certain Doom: Tower Bunny Smoke Flare Effect'),
(2408700, 9, 1, 0, 0,  0, 100, 0, 15000, 15000, 0, 0, 11, 43069 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower Bunny - Script - Cast Towers of Certain Doom: Skorn Cannonfire'),
(2408700, 9, 2, 0, 0,  0, 100, 0, 100, 100, 0, 0, 85, 43072 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skorn Tower Bunny - Script - Cast Towers of Certain Doom: Tower Caster Instakill');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13  AND `SourceEntry`IN(49625,49634,43072);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,49625,0,0,31,0,3,24087,0,0,0,0,'','Braves Flare targets Skorn Tower NW Bunny'),
(13,1,49625,0,1,31,0,3,24092,0,0,0,0,'','Braves Flare targets Skorn Tower E Bunny'),
(13,1,49625,0,2,31,0,3,24093,0,0,0,0,'','Braves Flare targets Skorn Tower SW Bunny'),
(13,1,49625,0,3,31,0,3,24094,0,0,0,0,'','Braves Flare targets Skorn Tower SE Bunny'),
(13,1,49634,0,0,31,0,3,24087,0,0,0,0,'','Seargents Flare targets Skorn Tower NW Bunny'),
(13,1,49634,0,1,31,0,3,24092,0,0,0,0,'','Seargents Flare targets Skorn Tower E Bunny'),
(13,1,49634,0,2,31,0,3,24093,0,0,0,0,'','Seargents Flare targets Skorn Tower SW Bunny'),
(13,1,49634,0,3,31,0,3,24094,0,0,0,0,'','Seargents Flare targets Skorn Tower SE Bunny'),
(13,1,43072,0,0,31,0,3,23668,0,0,0,0,'','Towers of Certain Doom: Tower Caster Instakill targets Winterskorn Rune-Caster'),
(13,1,43072,0,1,31,0,3,23667,0,0,0,0,'','Towers of Certain Doom: Tower Caster Instakill targets Winterskorn Rune-Seer'),
(13,1,43072,0,2,31,0,3,23669,0,0,0,0,'','Towers of Certain Doom: Tower Caster Instakill targets Winterskorn Oracle');

-- DB/Misc: Lupus Pupus
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=25791;

DELETE FROM `smart_scripts` WHERE `entryorguid`=25791;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25791, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 45948, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - On Respawn - Cast Oil Coat'),
(25791, 0, 1, 0, 8 ,0, 100, 1, 53326, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - On Spellhit - Increment Phase'),
(25791, 0, 2, 3, 1 ,1, 100, 1, 1000, 1000, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - OOC - Set Faction'),
(25791, 0, 3, 4,61 ,1, 100, 1, 0, 0, 0, 0, 11, 46075, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Cast Summon Wolf Droppings'),
(25791, 0, 4, 5,61 ,1, 100, 1, 0, 0, 0, 0, 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Set Random Movement'),
(25791, 0, 5, 0,61 ,1, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Despawn'),
(25791, 0, 6, 7, 0 ,1, 100, 1, 1000, 1000, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - IC - Set Faction'),
(25791, 0, 7, 8,61 ,1, 100, 1, 0, 0, 0, 0, 11, 46075, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Cast Summon Wolf Droppings'),
(25791, 0, 8, 9,61 ,1, 100, 1, 0, 0, 0, 0, 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Set Random Movement'),
(25791, 0, 9,10,61 ,1, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Despawn'),
(25791, 0,10, 0,61 ,1, 100, 1, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oil-stained Wolf - Linked with Previous Event - Evade');

-- Words for Delivery (25500)
UPDATE `quest_template` SET `Details` = 'Here we go. This is the speech, $N!$b$bIt has everything to be a great battle starter: It''s inspirational, has eloquent language and speaks directly to gnomes. Never has a finer speech been written!$b$bTurn this in to Captain Tread Sparknozzle and see if there''s anything else he needs of you.', `OfferRewardText` = 'This is the speech from Toby? Fantastic!$bRecruit, you''ve done all we could possibly ask for and the Gnomeregan Army thanks you!$bWe''ve got a strike team heading to Gnomeregan now and that wouldn''t have been possible without your assistance. For all of your help, we''d like you to join the Gnomeregan Reserves!$bIt doesn''t pay very well, but you do get this snazzy helmet. Hang on to that, you might need it someday!' WHERE `Id`=25500;

-- Words for Delivery (25286)
UPDATE `quest_template` SET `Details` = 'Here we go. This is the speech, $N!$b$bIt has everything to be a great battle starter: It''s inspirational, has eloquent language and speaks directly to gnomes. Never has a finer speech been written!$b$bTurn this in to Captain Tread Sparknozzle and get some transportation to High Tinker Mekkatorque!', `OfferRewardText` = 'Toby is all done with the speech? Let me see...$b<Reads the speech> Pumping pistons! What a fantastic speech! I knew Toby was a good writer, but this is perhaps the best he''s ever written.$bI think it''s time to get you out to the battle.' WHERE `Id`=25286;


SET @ARTRUIS := 28659;
SET @JALOOT := 28667;
SET @ZEPIK := 28668;
SET @ARTRUISGUID := 202971;
SET @JALOOTGUID := 202969;
SET @ZEPIKGUID := 202970;



UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= @ARTRUIS;

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ARTRUIS;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ARTRUIS;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ARTRUIS, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Respawn- Respawn Jaloot'),
(@ARTRUIS, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Respawn Zephik'),
(@ARTRUIS, 0, 2, 0, 0, 0, 100, 0, 5000, 9000, 9000, 15000, 11, 15530, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - IC - Cast Frostbolt (Phase 1)'),
(@ARTRUIS, 0, 3, 0, 0, 0, 100, 0, 7000, 11000, 11000, 15000, 11, 54261, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - IC - Cast Ice Lance (Phase 1)'),
(@ARTRUIS, 0, 4, 0, 9, 0, 100, 0, 0, 10, 14000, 18000, 11, 11831, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Range - Cast Frost Nova (Phase 1)'),
(@ARTRUIS, 0, 5, 0, 0, 0, 100, 0, 9000, 13000, 25000, 35000, 11, 54792, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Cast Icy Veins (Phase 1)'),
(@ARTRUIS, 0, 6, 7, 6, 0, 100, 0, 0, 0, 0, 0, 11, 52518, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - On death - Spawn Artruis Phylactery'),
(@ARTRUIS, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 4, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event- Send Data 1 4 to Jaloot'),
(@ARTRUIS, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 4, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Send Data 1 4 to Zephik'),
(@ARTRUIS, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 5, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Say Line 5'),
(@ARTRUIS, 0, 10, 11, 2, 0, 100, 1, 0, 30, 0, 0, 11, 52185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - At 20% Hp Cast Bindings of Submission'),
(@ARTRUIS, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Send Data 1 1 to Jaloot'),
(@ARTRUIS, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Send Data 1 1 to Zephik'),
(@ARTRUIS, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 1, 3, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Say Line 3'),
(@ARTRUIS, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 4, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Say Line 4'),
(@ARTRUIS, 0, 15, 16, 25, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Reset - Send Data 1 2 to Jaloot'),
(@ARTRUIS, 0, 16, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Send Data 1 2 to Zephik'),
(@ARTRUIS, 0, 17, 18, 38, 0, 100, 0, 1, 2, 0, 0, 45, 1, 3, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Receive Data 1 2- Send Data 1 3 to Jaloot'),
(@ARTRUIS, 0, 18, 19, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Remove Bindings of Submission'),
(@ARTRUIS, 0, 19, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Set Data 1 0'),
(@ARTRUIS, 0, 20, 21, 4, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @JALOOTGUID, @JALOOT, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Agro- Respawn Jaloot'),
(@ARTRUIS, 0, 21, 22, 61, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Respawn Zephik'),
(@ARTRUIS, 0, 22, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Say Line 0'),
(@ARTRUIS, 0, 23, 0, 2, 0, 100, 1, 0, 75, 0, 0, 1, 1, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - On 75% HP - Say Line 1'),
(@ARTRUIS, 0, 24, 0, 2, 0, 100, 1, 0, 50, 0, 0, 1, 2, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - On 50% HP - Say Line 2'),
(@ARTRUIS, 0, 25, 26, 38, 0, 100, 0, 1, 1, 0, 0, 45, 1, 5, 0, 0, 0, 0, 10, @ZEPIKGUID, @ZEPIK, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Receive Data 1 1- Send Data 1 5 to Zepik'),
(@ARTRUIS, 0, 26, 27, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Remove Bindings of Submission'),
(@ARTRUIS, 0, 28, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - Linked with Previous Event - Set Data 1 0'),
(@ARTRUIS, 0, 29, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 11, 53163, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - IC - Cast Dessawn Retainer'),
(@ARTRUIS, 0, 30, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 53163, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Artruis the Heartless - On Agro - Cast Dessawn Retainer');

DELETE FROM `creature_text` WHERE `entry` =@ARTRUIS;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ARTRUIS,0,0,'Ah, the hero. Your little friends said you would come. This certainly saves me the trouble of hunting you down myself.',14,0,100,2,0,0,'Artruis the Heartless'),
(@ARTRUIS,1,0,'I have weathered a hundred years of war and suffering. Do you truly think it wise to pit your mortals boddies against a being that cannot die? I''d venture you have more to lose',14,0,100,2,0,0,'Artruis the Heartless'),
(@ARTRUIS,2,0,'Even shattered into countless pieces, the crystals all around weaken me... perhaps I should not have underestimated the titans so...',14,0,100,2,0,0,'Artruis the Heartless'),
(@ARTRUIS,3,0,'These two brave, ignorant fools despise each other, yet somehow they both spoke of you as a hero. Perhaps you just lack the will to choose a side... let me extend you that opportunity.',14,0,100,2,0,0,'Artruis the Heartless'),
(@ARTRUIS,4,0,'Artruis is shielded. You must choose your side quickly to break his spell.',41,0,100,2,0,0,'Artruis the Heartless'),
(@ARTRUIS,5,0,'Arthas once mustered strength...of the very same sort... perhaps his is the path that you will follow.',14,0,100,2,0,0,'Artruis the Heartless');

UPDATE `creature_template` SET `AIName`= 'SmartAI',`npcflag`=0,`unit_flags`=32832 WHERE `entry`= @JALOOT;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@JALOOT;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@JALOOT, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Spawn - Remove quest giver flag'),
(@JALOOT, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Set Unit Flags'),
(@JALOOT, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Cast Tomb of the Heartless'),
(@JALOOT, 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Data Set 1 1 - Set Hostile'),
(@JALOOT, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Remove Tomb of the Heartless'),
(@JALOOT, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 40, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Attack'),
(@JALOOT, 0, 6, 7, 38, 0, 100, 0, 1, 2, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Data Set 1 2 - Set Friendly'),
(@JALOOT, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Set Unit Flags'),
(@JALOOT, 0, 8 ,0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Cast Tomb of the Heartless'),
(@JALOOT, 0, 9, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @ARTRUISGUID, @ARTRUIS, 0, 0, 0, 0, 0, 'Jaloot - On Death - Send Data 1 1 to Artruis'),
(@JALOOT, 0, 10,11, 38, 0, 100, 0, 1, 3, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Data Set 1 3 - Set Friendly'),
(@JALOOT, 0, 11,12, 61, 0, 100, 0, 0, 0, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Remove Unit Flags'),
(@JALOOT, 0, 12,13, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Say Line 0'),
(@JALOOT, 0, 13,14, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, @ARTRUISGUID, @ARTRUIS, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Attack Artruis'),
(@JALOOT, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Remove Bindings of Submission'),
(@JALOOT, 0, 15,16, 38, 0, 100, 0, 1, 4, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Data Set 1 4 - Set Friendly'),
(@JALOOT, 0, 16,17, 61, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Set Unit Flags'),
(@JALOOT, 0, 17,18, 61, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Add quest giver flag'),
(@JALOOT, 0, 18,19 , 61, 0, 100, 0, 0, 0, 0, 0, 41, 120000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Despawn After 2 mins'),
(@JALOOT, 0, 19,0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - Linked with Previous Event - Evade'),
(@JALOOT, 0, 20, 0, 9, 0, 100, 0, 0, 5, 15000, 20000, 11, 52943, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Range - Cast Lightning Whirl'),
(@JALOOT, 0, 21, 0, 9, 0, 100, 0, 0, 5, 15000, 18000, 11, 52944, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Range - Cast Lightning Strike'),
(@JALOOT, 0, 22, 0, 9, 0, 100, 0, 0, 5, 20000, 25000, 11, 52964, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Range - Cast Spark Frenzy'),
(@JALOOT, 0, 23, 0, 2, 0, 100, 0, 0, 30, 9000, 12000, 11, 52969, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jaloot - On Less than 30% HP - Cast Energy Siphon');

DELETE FROM `creature_text` WHERE `entry` =@JALOOT;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@JALOOT, 0, 0, 'Now you not catch us with back turned. Now we hurt you bad undead. BAD!', 12, 0, 100, 0, 0, 0, 'Jaloot');

UPDATE `creature_template` SET `AIName`= 'SmartAI',`npcflag`=0,`unit_flags`=32832 WHERE `entry`= @ZEPIK;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ZEPIK;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ZEPIK, 0, 0, 1, 11, 0, 100, 1, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Spawn - Remove quest giver flag'),
(@ZEPIK, 0, 1, 2, 61, 0, 100, 1, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Set Unit Flags'),
(@ZEPIK, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Cast Tomb of the Heartless'),
(@ZEPIK, 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Data Set 1 1 - Set Hostile'),
(@ZEPIK, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Remove Tomb of the Heartless'),
(@ZEPIK, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 40, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Attack'),
(@ZEPIK, 0, 6, 7, 38, 0, 100, 0, 1, 2, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Data Set 1 2 - Set Friendly'),
(@ZEPIK, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Set Unit Flags'),
(@ZEPIK, 0, 8 ,0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 52182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Cast Tomb of the Heartless'),
(@ZEPIK, 0, 9, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 10, @ARTRUISGUID, @ARTRUIS, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Death - Send Data 1 2 to Artruis'),
(@ZEPIK, 0, 10, 11, 38, 0, 100, 0, 1, 5, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Data Set 1 5 - Set Friendly'),
(@ZEPIK, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Remove Unit Flags'),
(@ZEPIK, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Say Line 0'),
(@ZEPIK, 0, 13,14, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, @ARTRUISGUID, @ARTRUIS, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Attack Artruis'),
(@ZEPIK, 0, 14,0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 52185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Remove Bindings of Submission'),
(@ZEPIK, 0, 15,16, 38, 0, 100, 0, 1, 4, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Data Set 1 4 - Set Friendly'),
(@ZEPIK, 0, 16,17, 61, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Set Unit Flags'),
(@ZEPIK, 0, 17,18, 61, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Add quest giver flag'),
(@ZEPIK, 0, 18,19 ,61, 0, 100, 0, 0, 0, 0, 0, 41, 120000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Despawn After 2 mins'),
(@ZEPIK, 0, 19,0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - Linked with Previous Event - Evade'),
(@ZEPIK, 0, 20, 0, 9, 0, 100, 0, 0, 20, 15000, 18000, 11, 52761, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Range - Cast Barbed Net'),
(@ZEPIK, 0, 21, 0, 9, 0, 100, 0, 5, 30, 12000, 15000, 11, 52889, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Range - Cast Envenomed Shot'),
(@ZEPIK, 0, 22, 0, 9, 0, 100, 0, 0, 5, 15000, 18000, 11, 52873, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Range - Cast Open Wound'),
(@ZEPIK, 0, 23, 0, 9, 0, 100, 0, 5, 30, 3000, 7000, 11, 52758, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Range - Cast Piercing Arrow'),
(@ZEPIK, 0, 24, 0, 9, 0, 100, 0, 0, 5, 30000, 40000, 11, 52886, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Range - Cast Spike Trap'),
(@ZEPIK, 0, 25, 0, 2, 0, 100, 0, 0, 30, 30000, 30000, 11, 52895, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zepik the Gorloc Hunter - On Less than 30% HP Cast Bandage - Cast Bandage');

DELETE FROM `creature_text` WHERE `entry` =@ZEPIK;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ZEPIK, 0, 0, 'You going die big bad undead thing! You not catch Zepik sleeping this time!', 12, 0, 100, 0, 0, 0, 'Zepik the Gorloc Hunter');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=52185;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,52185,0,0,31,0,3,@ZEPIK,0,0,0,'','bindings of submission can hit Zepik the Gorloc Hunter'),
(13,1,52185,0,1,31,0,3,@JALOOT,0,0,0,'','bindings of submission can hit Jaloot'),
(13,1,52185,0,2,31,0,3,@ARTRUIS,0,0,0,'','bindings of submission can hit Artruis the Heartless');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN(51186,51188,51189,51190,51191,51192);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 51186, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Goregek the Bristlepine Hunter cannot be used near artruis'),
(17, 0, 51188, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Dajik the Wasp Hunter cannot be used near artruis'),
(17, 0, 51189, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Zepik the Gorloc Hunter cannot be used near artruis'),
(17, 0, 51190, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Lafoo cannot be used near artruis'),
(17, 0, 51191, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Jaloot cannot be used near artruis'),
(17, 0, 51192, 0, 0, 29, 0, 28659, 50, 0, 1, 0, 0, '', 'Summon Moodle cannot be used near artruis');

UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry` IN (28667,28668);


-- DB/Misc: Kaganishu
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=25425;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25425;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25425,0,0,0,8,0,100,0,45607,0,0,0,33,25425,0,0,0,0,0,7,0,0,0,0,0,0,0,'On Spell Hit(Kaganishu''s Fetish Trigger) - Quest Credit');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=45607;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,45607,0,0,31,0,3,25425,0,0,0,0,'','Kaganishu''s Fetish Trigger hits Farseer Grimwalker''s Spirit');


-- DB/SAI: Little Morsels cannot feed mobs
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(17111,17112,17113);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17111,17112,17113);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17111, 0, 0, 0, 8, 0, 100, 0, 29916, 0, 0, 0, 33, 17111 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Captive Jaguar - On Spellhit - Kill Credit'),
(17112, 0, 0, 0, 8, 0, 100, 0, 29916, 0, 0, 0, 33, 17112 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Captive Tarantula - On Spellhit - Kill Credit'),
(17113, 0, 0, 0, 8, 0, 100, 0, 29916, 0, 0, 0, 33, 17113 , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Captive Crocolisk - On Spellhit - Kill Credit');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`IN (29916,29917);
INSERT INTO `disables`(`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,29917,64,'Ignore LOS on Feed Captured Animal'),
(0,29916,64,'Ignore LOS on Feed Captured Animal');

-- DB/Misc: Lunar Festival Invitation - Teleport Moonglade
DELETE FROM spell_scripts WHERE id=26373;
DELETE FROM spell_linked_spell WHERE spell_trigger=26373;
INSERT INTO spell_linked_spell VALUES (26373,26448,0,0,'Lunar Festival Invitation - Teleport Moonglade');

-- DB/SAI: Book of the Ancients

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE `entry`=177673;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` =12369;

DELETE FROM `smart_scripts` WHERE `entryorguid` =177673 AND `source_type`=1 OR `entryorguid`=17767300 AND `source_type`=9 OR `entryorguid`=12369 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(177673, 1, 0 ,1, 70, 0, 100, 0, 2, 0, 0,0,80,17767300,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Serpent Statue - On State Changed - Run Script'),
(17767300, 9, 0 ,0, 0, 0, 100, 0, 5000, 5000, 0,0,12,12369,1,180000,0,0,0,8,0,0,0,254.166855,2966.883545,1.367331,0.957399, 'Serpent Statue - Script - Spawn Lord Kragaru'),
(17767300, 9, 1 ,0, 0, 0, 100, 0, 185000, 185000, 0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Serpent Statue - Script - Reset Go'),
(12369, 0, 0 ,0, 9, 0, 100, 0, 0, 5, 3000,4000,11,15496,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Lord Kragaru - On Range - Cast Cleave'),
(12369, 0, 1 ,0, 13, 0, 100, 0, 10000, 15000, 0,0,11,12555,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Lord Kragaru - On Target Casting - Cast Pummel');

-- A Valiant`s Field Training (All) (Horde) progress
UPDATE `quest_template` SET `RequestItemsText` = 'A good day of training will never hurt anyone. It''s good to see you keeping up.' WHERE `id` IN (13765, 13771, 13776, 13781, 13786);

-- Taking Battle To The Enemy (Horde and Alliance) progress
UPDATE `quest_template` SET `RequestItemsText` = 'Have you tested yourself in combat against the Scourge?' WHERE `id` IN (13813, 13791);

-- Stop The Aggressors (Horde) progress
UPDATE `quest_template` SET `RequestItemsText` = 'Have you shown the Kvaldir that we will not let them threaten us?' WHERE `id` = 14140;

-- You`ve Really Done It This Time, Kul (Horde) progress
UPDATE `quest_template` SET `RequestItemsText` = 'Did you free Kul and those hopeless aspirants?' WHERE `id` = 14142;

-- Threat From Above (Horde) progress
UPDATE `quest_template` SET `RequestItemsText` = 'Have you defeated the Cult of the Damned raiding party?' WHERE `id` = 13812;

-- Rescue at Sea (Horde) progress
UPDATE `quest_template` SET `RequestItemsText` = 'Have you helped fend off the Kvaldir attack?' WHERE `id` = 14136;
