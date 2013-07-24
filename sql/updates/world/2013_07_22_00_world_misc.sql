UPDATE creature_template SET VehicleID = 862, ScriptName = 'npc_electron' WHERE entry = 42179;
UPDATE creature_template SET VehicleID = 865, ScriptName = 'npc_magmatron' WHERE entry = 42178;
UPDATE creature_template SET VehicleID = 864, ScriptName = 'npc_toxitron' WHERE entry = 42180;
UPDATE creature_template SET VehicleID = 863, ScriptName = 'npc_arcanotron' WHERE entry = 42166;
UPDATE creature_template SET ScriptName = 'npc_victor_nefarius_omnotron' WHERE entry = 49226;
UPDATE creature_template SET faction_A = 14, faction_H = 14, ScriptName = 'boss_omnotron', flags_extra = 128, InhabitType = 5 WHERE entry = 42186;
UPDATE creature_template SET difficulty_entry_1 = 49121, difficulty_entry_2 = 49122, difficulty_entry_3 = 49123, ScriptName = 'npc_poison_bomb_bwd' WHERE entry = 42897;
UPDATE creature_template SET faction_A = 14, faction_H = 14, flags_extra = 256 WHERE entry IN (42897,49121,49122,49123);
UPDATE creature_template SET minlevel = 88, maxlevel = 88, faction_A = 14, faction_H = 14, flags_extra = 128 WHERE entry IN (42920, 42934);
UPDATE creature_template SET minlevel = 85, maxlevel = 85, flags_extra = 128, ScriptName = 'npc_power_generator' WHERE entry = 42733;
UPDATE creature_template SET RegenHealth = 0 WHERE entry IN (42179, 42178, 42180, 42166);
UPDATE creature_template SET exp = 3 WHERE entry IN (42897,49121,49122,49123,49050,49053);
UPDATE creature_template SET faction_A = 14, faction_H = 14 WHERE entry = 49226;

DELETE FROM spell_script_names WHERE spell_id IN(92051,92135,91858,79582);
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(79582, 'spell_magmatron_barrier'),
(92051, 'spell_shadow_conductor'),
(92135, 'spell_shadow_conductor'),
(91858, 'spell_power_generator_periodic');

DELETE FROM creature_text WHERE entry IN (49226, 42179, 42178, 42180, 42166, 42186);
INSERT INTO creature_text (entry,groupid,id,text,type,probability,emote,sound,comment) VALUES 
(49226,0,0,'Stupid dwarves and your fascination with runes. Why would you create something that would help your enemy?',14,100,0,23376,'Omnotron - SAY_EMPOWER_ARCANOTRON'),
(49226,1,0,'Lightning Conductor works much better in a crowd, yes?',14,100,0,23377,'Omnotron - SAY_EMPOWER_ELECTRON'),
(49226,2,0,'You would like to move away from that, wouldn''t you? Too bad.',14,100,0,23375,'Omnotron - SAY_EMPOWER_MAGMATRON'),
(49226,3,0,'Were you planing on using Toxitron''s chemicals to damage the other constructs? Clever plan. Let me ruin that for you.',14,100,0,23378,'Omnotron - SAY_EMPOWER_TOXITRON'),
(49226,4,0,'Hmm, the Omnotron Defense System. Centuries ago, these constructs were considered the dwarves greatest tactical achievements. With so many counters to each construct''s attacks, I''ll have to rectify these designs for them to provide me ANY entertainment!',14,100,0,23374,'Omnotron - SAY_AGGRO'),
-- (49226,5,0,'That malfunctioning piece of junk was murder on the repair bills.',14,100,0,0,'Omnotron - SAY_DEATH'), -- missing sound id
(49226,5,0,'I should''ve known better than to rely on something so stupidly named... to entertain me for long.',14,100,0,23373,'Omnotron - SAY_DEATH_HC'),
(42186,0,0,'Arcanotron unit activated.',14,100,0,21868,'Omnotron - SAY_ARCANOTRON_ACTIVATE'),
(42186,1,0,'Electron unit activated.',14,100,0,21865,'Omnotron - SAY_ELECTRON_ACTIVATE'),
(42186,2,0,'Magmatron unit activated.',14,100,0,21866,'Omnotron - SAY_MAGMATRON_ACTIVATE'),
(42186,3,0,'Toxitron unit activated.',14,100,0,21867,'Omnotron - SAY_TOXITRON_ACTIVATE'),
(42186,4,0,'Arcanotron unit shield systems online.',14,100,0,21872,'Omnotron - SAY_ARCANOTRON_SHIELD'),
(42186,5,0,'Electron unit shield systems online.',14,100,0,21869,'Omnotron - SAY_ELECTRON_SHIELD'),
(42186,6,0,'Magmatron unit shield systems online.',14,100,0,21870,'Omnotron - SAY_MAGMATRON_SHIELD'),
(42186,7,0,'Toxitron unit shield systems online.',14,100,0,21871,'Omnotron - SAY_TOXITRON_SHIELD'),
(42186,8,0,'Rerouting excess energy to Magmatron unit. Engage flamethrower device.',14,100,0,21873,'Omnotron - SAY_MAGMATRON_FLAMETHROWER'),
(42186,9,0,'Intruders detected. Primary defense matrix initiated.',14,100,0,21863,'Omnotron - SAY_AGGRO'),
(42186,10,0,'Defense systems obliterated. Powering down.',14,100,0,21864,'Omnotron - SAY_DEATH'),
(42166,0,0,'|TInterface\\Icons\\spell_arcane_arcaneresilience.blp:20|t%s begins to cast|cFFFE1CF7|Hspell:79729|h [Power Conversion]!|r',41,100,0,0,'Arcanotron - EMOTE_SHIELD'),
(42179,0,0,'|TInterface\\Icons\\spell_nature_lightningshield.blp:20|t%s begins to cast|cFF1CF2FE|Hspell:79900|h [Unstable Shield]!|r',41,100,0,0,'Electron - EMOTE_SHIELD'),
(42179,1,0,'|TInterface\\Icons\\spell_shaman_staticshock.blp:20|t%s casts|cFF1CF2FE|Hspell:79888|h [Lightning Conductor]|h|r at |cFF1CF2FE$n|r!',41,100,0,0,'Electron - EMOTE_CONDUCTOR'),
(42178,0,0,'|TInterface\\Icons\\spell_fire_firearmor.blp:20|t%s begins to cast|cFFFF9A20|Hspell:79582|h [Barrier]!|r',41,100,0,0,'Magmatron - EMOTE_SHIELD'),
(42178,1,0,'|TInterface\\Icons\\ability_hunter_mastermarksman.blp:20|t%s sets his eye on |cFFFF0000$n|r and begins to cast|cFFFF0000|Hspell:79501|h [Acquiring Target]!|r',41,100,0,0,'Magmatron - EMOTE_FLAMETHROWER'),
(42180,0,0,'|TInterface\\Icons\\spell_nature_nullifydisease.blp:20|t%s begins to cast|cFF1CFE1C|Hspell:79835|h [Poison Soaked Shell]!|r',41,100,0,0,'Toxitron - EMOTE_SHIELD');

UPDATE creature_model_info SET bounding_radius = 0.62, combat_reach = 3 WHERE modelid IN(32687,32685,32688,32684);

DELETE FROM conditions WHERE SourceEntry IN (79920,78699,78698,78697,78700,80164,79629,91555,95019,95025,95022,95028,91858,95020,95026,95023,95029,95021,95027,95024,95030);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 78697, 0, 18, 1, 42179, 0, 0, '', 'Recharge - target Electron'),
(13, 2, 78698, 0, 18, 1, 42178, 0, 0, '', 'Recharge - target Magmatron'),
(13, 2, 78700, 0, 18, 1, 42180, 0, 0, '', 'Recharge - target Toxitron'),
(13, 2, 78699, 0, 18, 1, 42166, 0, 0, '', 'Recharge - target Arcanotron'),
(13, 2, 95019, 0, 18, 1, 42179, 0, 0, '', 'Recharge - target Electron'),
(13, 2, 95025, 0, 18, 1, 42178, 0, 0, '', 'Recharge - target Magmatron'),
(13, 2, 95022, 0, 18, 1, 42180, 0, 0, '', 'Recharge - target Toxitron'),
(13, 2, 95028, 0, 18, 1, 42166, 0, 0, '', 'Recharge - target Arcanotron'),
(13, 2, 95020, 0, 18, 1, 42179, 0, 0, '', 'Recharge - target Electron'),
(13, 2, 95026, 0, 18, 1, 42178, 0, 0, '', 'Recharge - target Magmatron'),
(13, 2, 95023, 0, 18, 1, 42180, 0, 0, '', 'Recharge - target Toxitron'),
(13, 2, 95029, 0, 18, 1, 42166, 0, 0, '', 'Recharge - target Arcanotron'),
(13, 2, 95021, 0, 18, 1, 42179, 0, 0, '', 'Recharge - target Electron'),
(13, 2, 95027, 0, 18, 1, 42178, 0, 0, '', 'Recharge - target Magmatron'),
(13, 2, 95024, 0, 18, 1, 42180, 0, 0, '', 'Recharge - target Toxitron'),
(13, 2, 95030, 0, 18, 1, 42166, 0, 0, '', 'Recharge - target Arcanotron'),
(13, 2, 80164, 0, 18, 1, 42179, 0, 0, '', 'Chemical Cloud - target Electron'),
(13, 2, 80164, 0, 18, 1, 42178, 0, 0, '', 'Chemical Cloud - target Magmatron'),
(13, 2, 80164, 0, 18, 1, 42180, 0, 0, '', 'Chemical Cloud - target Toxitron'),
(13, 2, 80164, 0, 18, 1, 42166, 0, 0, '', 'Chemical Cloud - target Arcanotron'),
(13, 2, 79629, 0, 18, 1, 0, 0, 0, '', 'Power Generator - target players'),
(13, 2, 79629, 0, 18, 1, 42179, 0, 0, '', 'Power Generator - target Electron'),
(13, 2, 79629, 0, 18, 1, 42178, 0, 0, '', 'Power Generator - target Magmatron'),
(13, 2, 79629, 0, 18, 1, 42180, 0, 0, '', 'Power Generator - target Toxitron'),
(13, 2, 79629, 0, 18, 1, 42166, 0, 0, '', 'Power Generator - target Arcanotron'),
(13, 2, 91555, 0, 18, 1, 0, 0, 0, '', 'Power Generator - target players'),
(13, 2, 91555, 0, 18, 1, 42179, 0, 0, '', 'Power Generator - target Electron'),
(13, 2, 91555, 0, 18, 1, 42178, 0, 0, '', 'Power Generator - target Magmatron'),
(13, 2, 91555, 0, 18, 1, 42180, 0, 0, '', 'Power Generator - target Toxitron'),
(13, 2, 91555, 0, 18, 1, 42166, 0, 0, '', 'Power Generator - target Arcanotron'),
(13, 2, 91858, 0, 18, 1, 0, 0, 0, '', 'Overcharged Power Generator - target players'),
(13, 2, 91858, 0, 18, 1, 42179, 0, 0, '', 'Overcharged Power Generator - target Electron'),
(13, 2, 91858, 0, 18, 1, 42178, 0, 0, '', 'Overcharged Power Generator - target Magmatron'),
(13, 2, 91858, 0, 18, 1, 42180, 0, 0, '', 'Overcharged Power Generator - target Toxitron'),
(13, 2, 91858, 0, 18, 1, 42166, 0, 0, '', 'Overcharged Power Generator - target Arcanotron');

DELETE FROM creature_template_addon WHERE entry IN (42733, 42934, 42897, 49121, 49122, 49123, 42920);
INSERT INTO creature_template_addon (entry, auras) VALUES
(42733, '79628'), -- Power Generator
(42934, '80162 80163'), -- Chemical Cloud
(42897, '80086'), -- Poison Bomb
(49121, '80086'), -- Poison Bomb
(49122, '80086'), -- Poison Bomb
(49123, '80086'), -- Poison Bomb
(42920, '80095'); -- Poison Puddle


DELETE FROM waypoint_data WHERE id = 4218600;
INSERT INTO waypoint_data (id,point,position_x,position_y,position_z,move_flag) VALUES 
(4218600, 0, -348.659027, -392.046356, 213.921112, 0),
(4218600, 1, -332.214600, -402.047577, 214.018646, 0),
(4218600, 2, -318.809174, -401.874451, 213.838577, 0),
(4218600, 3, -302.772430, -397.022125, 213.953568, 0),
(4218600, 4, -319.283478, -388.225647, 213.790161, 0),
(4218600, 5, -330.891541, -385.573639, 213.781555, 0);

DELETE FROM spell_linked_spell WHERE spell_trigger IN (78726, -92048, 92050);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES 
('78726','82265','2','Shutting Down - trigger Inactive'),
('92050','-79888','1','Shadow Infusion - remove Lightning Conductor'),
('92050','-91431','1','Shadow Infusion - remove Lightning Conductor'),
('92050','-91432','1','Shadow Infusion - remove Lightning Conductor'),
('92050','-91433','1','Shadow Infusion - remove Lightning Conductor'),
('92050','92053','1','Shadow Infusion - trigger aura');