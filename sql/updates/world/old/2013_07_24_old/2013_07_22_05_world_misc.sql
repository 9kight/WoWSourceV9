DELETE FROM creature_template_addon WHERE entry IN (43662, 42692, 49661);
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
('43662','81710'),
('42692','80222'),
('49661','80222');

DELETE FROM creature WHERE id = 43391 AND guid IN(7260669, 7260665, 7260659, 7260662);
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry IN (43537, 42696, 42808, 43430, 42695, 42692, 42691);
UPDATE `creature_template` SET `minlevel`='84',`maxlevel`='85',`exp`='3',`faction_A`='16',`faction_H`='16',`mindmg`='700',`maxdmg`='800',`attackpower`='805',`baseattacktime`='2000' WHERE entry IN (49667, 49662, 43014, 49666, 49661, 49665);
UPDATE `creature_template` SET `maxlevel` = 82 WHERE `entry` = 42695;
UPDATE `creature_template` SET `minlevel` = 85 WHERE `entry` = 49666;

DELETE FROM smart_scripts WHERE entryorguid IN (43537, 42696, 42808, 43430, 42695, 42692, 42691) AND source_type = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_flags`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`target_type`,`target_param1`,`target_param2`,`comment`) VALUES
('42696','0','0','0','6','0','3000','3000','5000','5000','11','15496','0','0','2','0','0','Stonecore: Stonecore Warbringer - Cleave'), -- Stonecore Warbringer
('42696','0','1','0','7','2','0','30','0','0','11','80158','0','0','1','0','0','Stonecore: Stonecore Warbringer - Rage'),
('43537','0','0','0','6','0','5000','8000','18000','20000','11','81463','0','0','1','0','0','Stonecore: Stonecore Earthshaper - Dust Storm'), -- Stonecore Earthshaper
('43537','0','1','0','6','0','3500','4000','15000','20000','11','81530','0','0','2','0','0','Stonecore: Stonecore Earthshaper - Ground Shock'),
('43537','0','2','0','6','0','500','1000','5000','6000','11','81576','0','0','2','0','0','Stonecore: Stonecore Earthshaper - Lava Burst'),
('42808','0','0','0','6','0','8000','10000','10000','15000','11','79922','0','0','1','0','0','Stonecore: Stonecore Flayer - Flay'),
('43430','0','0','0','7','0','1','200','0','0','11','81574','0','0','2','0','0','Stonecore: Stonecore Berserker - Charge'),
('43430','0','1','0','6','0','8000','8000','15000','25000','11','81568','0','0','1','0','0','Stonecore: Stonecore Berserker - Spinning Slash'),
('42695','0','0','0','6','4','0','0','0','0','39','50','0','0','1','0','0','Stonecore: Stonecore Sentry - Call for Help'),
('42695','0','1','0','6','4','0','0','0','0','1','0','0','0','1','0','0','Stonecore: Stonecore Sentry - Call for Help - Yell'),
('42692','0','0','0','6','0','8000','8000','10000','15000','11','80195','0','0','1','0','0','Stonecore: Stonecore Bruiser - Shockwave'),
('42692','0','1','0','6','0','5000','6000','15000','20000','11','80180','2','0','5','0','0','Stonecore: Stonecore Bruiser - Body Slam'),
('42691','0','0','0','6','0','1000','1000','2000','2000','11','80279','0','0','2','0','0','Stonecore: Stonecore Rift Conjurer - Shadowbolt'),
('42691','0','1','0','6','0','8000','8000','20000','25000','11','80308','0','0','1','0','0','Stonecore: Stonecore Rift Conjurer - Demon Portal');

DELETE FROM conditions WHERE SourceEntry IN(86862,86863,79332,79251);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 86863, 0, 18, 1, 42333, 0, 0, '', 'Seismic Shard - Enter Azil'),
(13, 1, 86862, 0, 18, 1, 42355, 0, 0, '', 'Seismic Shard - Target Shard'),
(13, 1, 79332, 0, 18, 1, 42428, 0, 0, '', 'Gravity Well - Target Follower'),
(13, 1, 79332, 0, 18, 1, 0, 0, 0, '', 'Gravity Well - Target Player'),
(13, 1, 79251, 0, 18, 1, 42428, 0, 0, '', 'Gravity Well - Target Follower'),
(13, 1, 79251, 0, 18, 1, 0, 0, 0, '', 'Gravity Well - Target Player');

DELETE FROM spell_target_position WHERE id IN (86856,86858,86860);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES 
('86856','725','1361.89','920.219','196.308','0'),
('86858','725','1341.19','913.399','197.092','0'),
('86860','725','1350.75','919.133','194.769','0');

DELETE FROM game_graveyard_zone WHERE ghost_zone = 5088;
INSERT INTO game_graveyard_zone (id,ghost_zone) VALUES 
('1757','5088');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (86299, 88282);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 88282, 0, 18, 1, 0, 0, 0, '', 'Upwind of Altairus'),
(13, 1, 86299, 0, 18, 1, 0, 0, 0, '', 'Grand Vizier Ertan - Storm''s Edge');

DELETE FROM `spell_area` WHERE `spell` = '93075';
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_start_active`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(93075, 5035, 0, 0, 0, 0, 0, 2, 0, 64, 11);

UPDATE `gameobject_template` SET `data0` = '22', `data1` = '28800' WHERE `entry` =207408;

UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (17307,17537,17536,17517);

UPDATE `gameobject_template` SET `flags` = '0' WHERE `entry` =185169;

DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (17307,17537,17536,17517);
