UPDATE creature_template SET faction_A = 14, faction_H = 14, exp = 3, minlevel = 88, maxlevel = 88, VehicleId = 0, unit_flags = 33554434 WHERE entry IN (48270,42347,51248,51251); -- Exposed Head of Magmaw
UPDATE `creature_template` SET `Health_mod` = 1180, `Mana_mod` = 1 WHERE `entry` = 51251; -- Exposed Head of Magmaw (1)
UPDATE creature_template SET VehicleId = 834, InhabitType = 5 WHERE entry IN (41570, 51101); -- Magmaw
UPDATE creature_template SET ScriptName = 'boss_magmaw' WHERE entry = 41570;
UPDATE creature_template SET faction_A = 35, faction_H = 35, unit_flags = 33554434, modelId1 = 34532, modelId2 = 34532, modelId3 = 34532, VehicleId = 833, ScriptName = 'npc_magmaws_pincer' WHERE entry IN(41620,41789); -- Magmaw's Pincer
UPDATE creature_template SET flags_extra = 0, ScriptName = 'npc_spike_stalker' WHERE entry = 41767;
UPDATE creature_template SET spell1 = 77917 WHERE entry = 41789; -- Pincer L
UPDATE creature_template SET spell1 = 77941 WHERE entry = 41620; -- Pincer R
UPDATE creature_template SET modelid2 = 11686, minlevel = 87, maxlevel = 87, faction_A = 14, faction_H = 14, flags_extra =128, ScriptName = 'npc_pillar_of_flame' WHERE entry = 41843; -- Pillar of Flame
UPDATE creature_template SET faction_A = 14, faction_H = 14, ScriptName = 'npc_lava_parasite' WHERE entry IN(41806,42321); -- Lava Parasite
UPDATE creature_template SET faction_A = 14, faction_H = 14 WHERE entry IN(51456,51457,51458,51459,51460,51461);
UPDATE creature_template SET faction_A = 14, faction_H = 14, modelid2 = 11686, flags_extra = 128 WHERE entry = 49447; -- Ignition
UPDATE creature_template SET mindmg = 2014, maxdmg = 2709.4, AIName = '', ScriptName = 'npc_drakonid_drudge' WHERE entry = 42362;
UPDATE creature_template SET InhabitType = 5 WHERE entry = 41767; -- Spike Stalker
UPDATE creature_template SET faction_A = 14, faction_H = 14, minlevel = 88, maxlevel = 88, InhabitType = 5 WHERE entry = 49427; -- Nefarian
UPDATE creature_template SET faction_A = 14, faction_H = 14, ScriptName = 'npc_blazing_bone_construct' WHERE entry = 49416; -- Blazing Bone Construct

UPDATE creature_model_info SET bounding_radius = 0, combat_reach = 15 WHERE modelid = 32679; -- Magmaw
UPDATE instance_template SET script = 'instance_blackwing_descent' WHERE map = 669;

UPDATE creature SET position_x = -305.279633, position_y = -34.858326, position_z = 211.476913, orientation = 4.04995 WHERE id = 41570;

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

DELETE FROM npc_spellclick_spells WHERE npc_entry IN (41620,41789);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`) VALUES 
('41789','77901','0'),
('41620','77901','0');

-- DELETE FROM vehicle_accessory WHERE guid = 300502;
-- INSERT INTO `vehicle_accessory` (`guid`,`accessory_entry`,`seat_id`,`minion`,`description`) VALUES 
-- ('300502','41620','0','1','Magmaw''s Pincer R'),
-- ('300502','41789','1','1','Magmaw''s Pincer L'),
-- 2 - player
-- ('300502','42347','3','1','Magmaw''s Head'), -- Unattackable Head
-- ('300502','48270','4','1','Magmaw''s Head 2');

DELETE FROM conditions WHERE SourceEntry IN(77917, 77941, 77929, 77940, 78010, 78360, 79025, 80035, 92134);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 77917, 0, 18, 1, 41767, 0, 0, '', 'Launch Hook R - target Stalker'),
(13, 1, 77941, 0, 18, 1, 41767, 0, 0, '', 'Launch Hook L - target Stalker'),
(13, 1, 77929, 0, 18, 1, 41570, 0, 0, '', 'Chain Visual R - target Head'),
(13, 1, 77940, 0, 18, 1, 41570, 0, 0, '', 'Chain Visual L - target Head'),
(13, 1, 78010, 0, 18, 1, 41843, 0, 0, '', 'Pillar Missile - target Pillar of Flame'),
(13, 1, 78360, 0, 18, 1, 41570, 0, 0, '', 'Mangle - target Magmaw'),
(13, 1, 79025, 0, 18, 1, 41570, 0, 0, '', 'Chain Visual - target Head'),
(13, 1, 80035, 0, 18, 1, 42362, 0, 0, '', 'Vengeful Dredge - target Drakonid'),
(13, 1, 92134, 0, 18, 1, 49416, 0, 0, '', 'Ignition - target Bone Construct');

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

DELETE FROM creature_text WHERE entry = 41570;
INSERT INTO creature_text (entry,groupid,id,text,type,probability,emote,sound,comment) VALUES 
(41570,0,0,'%s slumps forward, exposing his pincers!',41,100,0,0,'Magmaw - EMOTE_CRASH'),
(41570,1,0,'%s becomes impaled on the spike, exposing his head!',41,100,0,0,'Magmaw - EMOTE_IMPALE'),
(41570,2,0,'%s begins to erupt, spewing Lava Parasites onto the ground!',41,100,0,0,'Magmaw - EMOTE_PILLAR');

-- Lava Parasite
UPDATE `creature_template` SET `minlevel` = 85, `maxlevel` = 85, `exp` = 3, `mindmg` = 1007, `maxdmg` = 1354.7, `attackpower` = 1571, `dmg_multiplier` = 7.5, `baseattacktime` = 2000, `AIName` = '' WHERE `entry` IN (41806, 42321, 51456, 51457, 51458, 51459, 51460, 51461); -- normal modes
UPDATE `creature_template` SET `difficulty_entry_1` = 51456, `difficulty_entry_2` = 51457, `difficulty_entry_3` = 51458 WHERE `entry` = 41806;
UPDATE `creature_template` SET `difficulty_entry_1` = 51459, `difficulty_entry_2` = 51460, `difficulty_entry_3` = 51461 WHERE `entry` = 42321;
UPDATE `creature_template` SET `dmg_multiplier` = 9 WHERE `entry` IN (51458, 51460); -- 25 man normal
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` IN (51456, 51459, 51457, 51461); -- heroic modes
