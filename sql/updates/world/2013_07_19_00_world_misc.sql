UPDATE `creature` SET `spawntimesecs` = '7200' WHERE `map` IN (33,725,657,36,755,670,644,645,643);

UPDATE `creature` SET `spawntimesecs` = '86400' WHERE `id` IN (46962,3887,50834,4278,46963,46964,43438,43214,42188,42333,
                                                               43878,43873,43875,44577,43614,49045,43612,44819,39625,40177,
                                                               40319,40484,39425,39788,39428,39378,39731,39587,39732,40586,
                                                               40765,40788,44566);

UPDATE `gameobject` SET `spawntimesecs` = '1800' WHERE `id` =202747;

UPDATE `creature_template` SET `faction_A` = '35', `faction_H` = '35', `flags_extra` = '128' WHERE `entry` =53488;

UPDATE `creature_template` SET `mindmg` = '1225.5', `maxdmg` = '1544.7', `attackpower` = '1651', `minrangedmg` = '1160.9', `maxrangedmg` = '1328.1', `rangedattackpower` = '225' WHERE `entry` =29611;

UPDATE `creature_template` SET `mindmg` = '1225.5', `maxdmg` = '1544.7', `attackpower` = '1651', `minrangedmg` = '1160.9', `maxrangedmg` = '1328.1', `rangedattackpower` = '225' WHERE `entry` =39605;

UPDATE creature_model_info SET bounding_radius = 0, combat_reach = 15 WHERE modelid = 32679; -- Magmaw

DELETE FROM creature_template_addon WHERE entry IN (41806,42321,49447,42347,48270);
INSERT INTO creature_template_addon (entry, auras) VALUES
(41806,'78019'),
(42321,'78019'),
(49447,'92128'),
(48270,'95478');

DELETE FROM npc_spellclick_spells WHERE npc_entry IN (41620,41789);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`) VALUES 
('41789','77901'),
('41620','77901');

DELETE FROM conditions WHERE SourceEntry IN(77917, 77941, 77929, 77940, 78010, 78360);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 77917, 0, 18, 1, 41767, 0, 0, '', 'Launch Hook R - target Stalker'),
(13, 0, 77941, 0, 18, 1, 41767, 0, 0, '', 'Launch Hook L - target Stalker'),
(13, 0, 77929, 0, 18, 1, 41570, 0, 0, '', 'Chain Visual R - target Head'),
(13, 0, 77940, 0, 18, 1, 41570, 0, 0, '', 'Chain Visual L - target Head'),
(13, 0, 78010, 0, 18, 1, 41843, 0, 0, '', 'Pillar Missile - target Pillar of Flame'),
(13, 0, 78360, 0, 18, 1, 41570, 0, 0, '', 'Mangle - target Magmaw');

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

UPDATE `quest_template` SET `RewardCurrencyId1` = '0' WHERE `Id` IN (26414,26420,26442,26488,26536,26543,26556,26557,26572,26588);

DELETE FROM `pickpocketing_loot_template` WHERE `entry` = 68729;

DELETE FROM `game_graveyard_zone` WHERE `id` IN (109,1458,389);
INSERT INTO `game_graveyard_zone` (`id`, `ghost_zone`, `faction`) VALUES
(109, 214, 0),
(109, 5339, 0),
(1458, 214, 0),
(1458, 5339, 0),
(389, 214, 0),
(389, 1581, 0),
(389, 5339, 0);

UPDATE `creature_template` SET `npcflag` = '2' WHERE `entry` IN (49871,50039);

DELETE FROM `creature` WHERE `id` = 15999;

UPDATE `creature` SET `MovementType` = '0' WHERE `guid` =248924;

UPDATE `creature_template` SET `unit_class` = '2' WHERE `entry` =49043;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (14968,14942,14941,14940,14939,14937,14936,14934,14935,14967,7573,7574,10568);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(7573, 1, 30249, 0, ''),
(7573, 11, 0, 0, 'achievement_denyin_the_scion'),
(7574, 1, 30249, 0, ''),
(7574, 11, 0, 0, 'achievement_denyin_the_scion');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 35077;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35077, 0, 0, 0, 0, 0, 100, 0, 0, 0, 5000, 5000, 11, 67827, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coup de pied rapide'),
(35077, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 5000, 5000, 11, 67825, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Crochet du gauche'),
(35077, 0, 2, 0, 0, 0, 100, 0, 500, 500, 10000, 10000, 11, 61044, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 'Cri démoralisant'),
(35077, 0, 3, 0, 19, 0, 100, 0, 14154, 0, 0, 0, 11, 67503, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Vaillance des rebelles'),
(35077, 0, 4, 0, 20, 0, 100, 0, 14154, 0, 0, 0, 28, 67503, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Vaillance des rebelles'),
(35077, 0, 5, 0, 19, 0, 100, 0, 14154, 0, 0, 0, 12, 35188, 1, 120000, 0, 0, 0, 7, 0, 0, 0, -1636.57, 1473.01, 61.3751, 4.00132, 'Invoke worgens'),
(35077, 0, 6, 0, 19, 0, 100, 0, 14154, 0, 0, 0, 12, 35188, 1, 120000, 0, 0, 0, 7, 0, 0, 0, -1646.31, 1486.85, 61.462, 3.59411, 'Invoke worgens'),
(35077, 0, 7, 0, 19, 0, 100, 0, 14154, 0, 0, 0, 12, 35188, 1, 120000, 0, 0, 0, 7, 0, 0, 0, -1646.31, 1486.85, 61.462, 3.59411, 'Invoke worgens'),
(35077, 0, 8, 0, 19, 0, 100, 0, 14154, 0, 0, 0, 12, 35188, 1, 120000, 0, 0, 0, 7, 0, 0, 0, -1651.11, 1381.36, 51.7693, 2.02447, 'Invoke worgens');

UPDATE `gameobject_template` SET `faction` = '0', `data0` = '99556', `flags` = '48' WHERE `entry` =208900;

DELETE FROM `spell_proc_event` WHERE `entry` IN (88757,88668,2947);

DELETE FROM `spell_bonus_data` WHERE `entry` IN (88668,2947);

UPDATE `disables` SET `entry` = '568' WHERE `sourceType` =2 AND `entry` =5680;

DELETE FROM `gameobject` WHERE `guid` = 100321;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(100321, 207415, 725, 5088, 5088, 1, 1, 1106.96, 888.927, 287.568, 0.930331, 0, 0, 0.448571, 0.893747, 300, 0, 1);

UPDATE `gameobject_template` SET `flags` = '32' WHERE `entry` =207415;

DELETE FROM `gameobject_loot_template` WHERE `entry` = 207415;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(207415, 65734, -100, 1, 0, 1, 1);
