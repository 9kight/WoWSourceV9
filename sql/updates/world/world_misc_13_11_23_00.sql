DELETE FROM spell_script_names WHERE ScriptName = 'spell_dk_spell_deflection';
DELETE FROM spell_script_names WHERE ScriptName = 'spell_dru_primal_tenacity';
DELETE FROM spell_script_names WHERE ScriptName = 'spell_hun_ascpect_of_the_viper';
DELETE FROM spell_script_names WHERE ScriptName = 'spell_hun_aspect_of_the_beast';

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




DELETE FROM creature_text WHERE entry=44202;
INSERT INTO `creature_text` VALUES ('44202', '0', '0', 'Help,Im trap in here!', '41', '0', '100', '0', '0', '20833', 'text 1 bile otron');
INSERT INTO `creature_text` VALUES ('44202', '1', '0', 'Hey, over here!', '41', '0', '100', '0', '0', '20834', 'text 2 bile otron');
INSERT INTO `creature_text` VALUES ('44202', '2', '0', 'A litlle help?', '41', '0', '100', '0', '0', '20835', 'text 3 bile otron');
INSERT INTO `creature_text` VALUES ('44202', '3', '0', 'Poor litle fellow...', '41', '0', '100', '0', '0', '20836', 'text 4 bile otron');
INSERT INTO `creature_text` VALUES ('44202', '4', '0', 'Oo he looks pretty bad now!', '41', '0', '100', '0', '0', '20837', 'text 5 bile otron');
INSERT INTO `creature_text` VALUES ('44202', '5', '0', 'Great job guys a the key it should be in hes guts some where just a fish around in thiere in till you fiind it.', '41', '0', '100', '0', '0', '20838', 'text 6 bile otron');
INSERT INTO `creature_text` VALUES ('44202', '6', '0', 'Thanks for freeing me , im often to play more amazing adventures.', '41', '0', '100', '0', '0', '20839', 'text 7 bile otron');

DELETE FROM creature_text WHERE entry=43296;
INSERT INTO `creature_text` VALUES ('43296', '0', '0', 'Yeaah , yeah!', '41', '0', '100', '0', '0', '20828', 'text 1 chimaeron');
INSERT INTO `creature_text` VALUES ('43296', '1', '0', 'Yeaah , yeah!', '41', '0', '100', '0', '0', '20830', 'text 2 chimaeron');
INSERT INTO `creature_text` VALUES ('43296', '2', '0', 'Roar!', '41', '0', '100', '0', '0', '20831', 'text 3 chimaeron');


DELETE FROM creature_text WHERE entry=49799;
INSERT INTO `creature_text` VALUES ('49799', '0', '0', 'Ah Maloriak, how gracious of you to fiindly appear from that quarantine you calling that laboratory. What you ve got this time?', '41', '0', '100', '0', '0', '20833', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('49799', '1', '0', 'By all means inliten me.', '41', '0', '100', '0', '0', '20092', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('49799', '2', '0', 'It appears of your experiment has failed. The world has got completly blind. Look at him', '41', '0', '100', '0', '0', '20093', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('49799', '3', '0', 'MIRACLE!', '41', '0', '100', '0', '0', '0', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('49799', '4', '0', 'No, not yet.', '41', '0', '100', '0', '0', '20094', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('49799', '5', '0', 'This object of your sugrem its still proves valuable to me.', '41', '0', '100', '0', '0', '20095', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('49799', '6', '0', 'Leave now patethic alchemist! Ancestors await your next failure', '41', '0', '100', '0', '0', '20096', 'Atramedes: Intro');


DELETE FROM creature_text WHERE entry=43404;
INSERT INTO `creature_text` VALUES ('43404', '0', '0', 'My apologies for the trouble, my lord. But I think I have something you might be very interested in!', '41', '0', '100', '0', '0', '19860', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('43404', '1', '0', 'Yes, yes!', '41', '0', '100', '0', '0', '19861', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('43404', '2', '0', 'By extracting agents of different dragons blood, I created an ointment that gives a special view to the user', '41', '0', '100', '0', '0', '19862', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('43404', '3', '0', 'It feels beyond the mortal realm!', '41', '0', '100', '0', '0', '19863', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('43404', '4', '0', 'Atramedes! Your teacher calls you!', '41', '0', '100', '0', '0', '19864', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('43404', '5', '0', 'I present the experiment 25463-D!', '41', '0', '100', '0', '0', '19865', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('43404', '6', '0', 'What could it be? I delivered them out of the immediately', '41', '0', '100', '0', '0', '19866', 'Atramedes: Intro');
INSERT INTO `creature_text` VALUES ('43404', '7', '0', 'Yes, my lord', '41', '0', '100', '0', '0', '19867', 'Atramedes: Intro');

DELETE FROM waypoint_data WHERE id=401535;
INSERT INTO `waypoint_data` VALUES ('401535', '15', '-135.682', '14.3668', '73.1653', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '14', '-131.726', '23.4939', '73.016', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '13', '-127.365', '29.1172', '72.0576', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '12', '-118.459', '32.6543', '72.0576', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '11', '-106.8', '34.3929', '72.0576', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '10', '-98.6358', '34.0884', '72.0576', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '9', '-90.118', '31.1505', '72.4277', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '8', '-84.6083', '24.9477', '73.1438', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '7', '-80.8747', '18.4347', '73.1467', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '6', '-80.7042', '8.66511', '73.0947', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '5', '-82.6228', '2.3104', '73.0302', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '4', '-87.2064', '-4.88842', '73.0459', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '3', '-92.9907', '-9.86047', '72.9425', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '2', '-100.52', '-13.2508', '72.8621', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '1', '-110.441', '-14.8702', '72.8539', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '16', '-137.116', '5.19426', '73.1702', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '17', '-136.121', '-3.82228', '73.1646', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '18', '-132.445', '-11.2962', '73.0674', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '19', '-126.586', '-14.031', '72.9535', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '20', '-117.881', '-14.3374', '72.9052', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '21', '-111.587', '-14.6692', '72.8653', '0', '0', '0', '0', '100', '0', '0');
INSERT INTO `waypoint_data` VALUES ('401535', '22', '-104.003', '-14.2077', '72.8472', '0', '0', '0', '0', '100', '0', '0');

DELETE FROM creature WHERE guid IN (401539,401541);
INSERT INTO `creature` VALUES ('401539', '48964', '669', '5094', '5094', '1', '1', '0', '48964', '126.699', '-211.718', '75.4534', '4.62518', '300', '0', '0', '667920', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('401541', '43404', '669', '5094', '5094', '1', '1', '0', '0', '125.406', '-225.326', '75.4534', '1.48359', '300', '0', '0', '21588350', '0', '0', '0', '0', '0');

