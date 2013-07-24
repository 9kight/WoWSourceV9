UPDATE creature_template SET ScriptName = 'boss_maloriak' WHERE entry = 41378;
UPDATE creature_template SET mechanic_immune_mask = mechanic_immune_mask &~ 0x2000000 WHERE entry IN (41378, 49974, 49980, 49986);
UPDATE creature_template SET InhabitType = 5, flags_extra = 128 WHERE entry = 41505; -- Cauldron Stalker
UPDATE creature_template SET minlevel = 88, maxlevel = 88, flags_extra = 0, modelid1 = 11686, modelid2 = 11686, faction_A = 16, faction_H = 16, Health_mod = 0.116425, AIName = 'NullCreatureAI' WHERE entry = 41576; -- Flash Freeze
UPDATE creature_template SET flags_extra = 128, modelid1 = 11686, modelid2 = 11686, faction_A = 16, faction_H = 16, minlevel = 85, maxlevel = 85, AIName = 'NullCreatureAI' WHERE entry IN (41901, 50030); -- Magma Jets
UPDATE creature_template SET flags_extra = 128 WHERE entry = 42045; -- Summon Stalker
UPDATE creature_template SET mindmg = 1225.5, maxdmg = 1544.7, attackpower = 1651, dmg_multiplier = 5, exp = 3, minlevel = 88, maxlevel = 88, faction_A = 16, faction_H = 16, AIName = '' WHERE entry IN (41440, 41841); -- Aberration, Prime Subject
UPDATE creature_template SET ScriptName = 'npc_prime_subject' WHERE entry = 41841; -- Prime Subject
UPDATE creature_template SET minlevel = 88, maxlevel = 88, faction_A = 16, faction_H = 16, flags_extra = 0, ScriptName = 'npc_absolute_zero' WHERE entry = 41961;
UPDATE gameobject_template SET size = 0.731427, flags = 32 WHERE entry = 401904; -- BLACKROCKV2_LABROOM_CAULDRON
DELETE FROM creature WHERE id = 41440; -- Aberration

DELETE FROM creature WHERE id IN (41505, 42045, 41378);
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(407583,41505,669, 0, 0, 15,1,0,0,-105.903717,-485.134888,81.348686,1.55,604800,0,0,57,0,0,0,0,0), -- Cauldron Stalker
(407584,42045,669, 0, 0, 15,1,0,0,-68.747261,-447.177094,74.849403,0.0,604800,0,0,57,0,0,0,0,0), -- Spawn Stalker
(407585,42045,669, 0, 0, 15,1,0,0,-69.210327,-433.842407,74.849403,0.0,604800,0,0,57,0,0,0,0,0),
(407586,42045,669, 0, 0, 15,1,0,0,-144.928314,-438.317230,73.323967,0.0,604800,0,0,57,0,0,0,0,0),
(407587,41378,669, 0, 0, 3,1,0,0,-106.295998,-460.505005,73.4552,1.67146,604800,0,0,3150,0,0,0,0,0); -- Maloriak

UPDATE `gameobject` SET `position_x` = '-105.7541', `position_y` = '-485.3891', `orientation` = '3.141593' WHERE `guid` =100149;

DELETE FROM creature_template_addon WHERE entry IN (49485, 41841, 41440);
INSERT INTO creature_template_addon (entry, auras) VALUEs
(41440, '77987'),
(41841, '77987');

DELETE FROM disables WHERE entry = 15269;
INSERT INTO disables (sourceType, entry, comment) VALUES
(4, 15269, 'Aberrant Behavior');

DELETE FROM conditions WHERE SourceEntry IN (77569, 77925, 77932, 77937, 77948, 77615, 92910);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 77569, 0, 18, 1, 42045, 0, 0, '', 'Release Aberrations - target Stalker'),
(13, 1, 77925, 0, 18, 1, 41505, 0, 0, '', 'Throw Vial - target Stalker'),
(13, 1, 77932, 0, 18, 1, 41505, 0, 0, '', 'Throw Vial - target Stalker'),
(13, 1, 77937, 0, 18, 1, 41505, 0, 0, '', 'Throw Vial - target Stalker'),
(13, 1, 77615, 0, 18, 1, 0, 0, 0, '', 'Debilitating Slime - target players'),
(13, 1, 92910, 0, 18, 1, 41440, 0, 0, '', 'Debilitating Slime - target aberrations'),
(13, 1, 77948, 0, 18, 1, 0, 0, 0, '', 'Debilitating Slime - target players'),
(13, 1, 77948, 0, 18, 1, 41440, 0, 0, '', 'Debilitating Slime - target aberrations');

DELETE FROM spell_linked_spell WHERE spell_trigger IN (-92910, 92910, 77615, 77569, 77699, 92978, 92979, 92980, 77715, 95655, 95656, 95657);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES 
('92910','-77987','1','Debilitating Slime - supress Growth Catalyst'),
('-92910','77987','0','Debilitating Slime - supress Growth Catalyst'),
('77569','92228','1','Release Aberrations - trigger summon'),
('77699','77711','1','Flash Freeze - trigger summon'),
('92978','77711','1','Flash Freeze - trigger summon'),
('92979','77711','1','Flash Freeze - trigger summon'),
('92980','77711','1','Flash Freeze - trigger summon'),
('77715','-77699','1','Shatter - Remove flash freeze'),
('95655','-92978','1','Shatter - Remove flash freeze'),
('95656','-92979','1','Shatter - Remove flash freeze'),
('95657','-92980','1','Shatter - Remove flash freeze');

DELETE FROM spell_script_names WHERE spell_id IN (77912, 92965, 92966, 92967, 93018);
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(77912, 'spell_remedy'),
(92965, 'spell_remedy'),
(92966, 'spell_remedy'),
(92967, 'spell_remedy'),
(93018, 'spell_magma_jets_periodic');

DELETE FROM creature_text WHERE entry = 41378;
INSERT INTO creature_text (entry,groupid,id,text,type,probability,emote,sound,comment) VALUES 
(41378,0,0,'|TInterface\\Icons\\inv_potion_24.blp:20|t%s throws a |cFFFF0000red|r vial into the cauldron!',41,100,0,0,'Maloriak - EMOTE_RED_BOTTLE'),
(41378,1,0,'|TInterface\\Icons\\INV_Potion_162.blp:20|t%s throws a |cFF00FF00green|r vial into the cauldron!',41,100,0,0,'Maloriak - EMOTE_GREEN_BOTTLE'),
(41378,2,0,'|TInterface\\Icons\\INV_Potion_20.blp:20|t%s throws a |cFF0000FFblue|r vial into the cauldron!',41,100,0,0,'Maloriak - EMOTE_BLUE_BOTTLE'),
(41378,3,0,'There can be no disruptions! Mustn''t keep the master waiting, mustn''t fail again!',14,100,0,19847,'Maloriak - SAY_AGGRO'),
(41378,4,0,'Nothing goes to waste!',14,100,0,19848,'Maloriak - SAY_SLAY'),
(41378,4,1,'Strip the flesh, harvest the organs!',14,100,0,19849,'Maloriak - SAY_SLAY'),
(41378,5,0,'Mix and stir! Apply heat!',14,100,0,19851,'Maloriak - SAY_RED_PHASE'),
(41378,6,0,'How well does the mortal shell handle extreme temperature change? Must find out! For Science!',14,100,0,19853,'Maloriak - SAY_BLUE'),
(41378,7,0,'This ones a little unstable! But what''s progress without failure?',14,100,0,19852,'Maloriak - SAY_GREEN'),
(41378,8,0,'When pushed to the edge, results may become unpredictable!',14,100,0,19854,'Maloriak - SAY_25'),
(41378,9,0,'There will never be another like me...',14,100,0,19850,'Maloriak - SAY_DEATH');