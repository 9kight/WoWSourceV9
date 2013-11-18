UPDATE quest_template SET SourceItemId=39329 AND SourceItemCount=1 WHERE Id=12717;
DELETE FROM creature WHERE guid=255441;
DELETE FROM creature WHERE guid=7293502;
INSERT INTO `creature` VALUES ('255441', '29110', '609', '4298', '4356', '1', '64', '0', '0', '2319.7', '-5733.97', '155.102', '0.702342', '300', '0', '0', '27890000', '0', '0', '0', '0', '0');

DELETE FROM gameobject WHERE guid=2000186;
DELETE FROM gameobject WHERE guid=2000187;
INSERT INTO `gameobject` VALUES ('2000186', '190960', '0', '139', '4281', '1', '256', '2346.47', '-5675.81', '426.029', '3.69573', '0', '0', '0.961861', '-0.273539', '1', '0', '1');
INSERT INTO `gameobject` VALUES ('2000187', '191009', '0', '139', '4281', '1', '256', '2342.67', '-5669.64', '426.029', '3.82118', '0', '0', '0.942824', '-0.333292', '1', '0', '1');
UPDATE creature_template SET npcflag=2 WHERE entry=38038;
DELETE FROM creature_addon WHERE guid=233899;
DELETE FROM creature_addon WHERE guid=233892;
DELETE FROM creature_addon WHERE guid=234411;
DELETE FROM creature_addon WHERE guid=234410;
DELETE FROM creature_addon WHERE guid=233896;
DELETE FROM creature_addon WHERE guid=233889;
DELETE FROM creature_addon WHERE guid=234396;
DELETE FROM creature_addon WHERE guid=233708;
DELETE FROM creature_addon WHERE guid=233886;
INSERT INTO `creature_addon` VALUES ('233899', '0', '0', '0', '1', '234', '');
INSERT INTO `creature_addon` VALUES ('233892', '0', '0', '0', '1', '234', '');
INSERT INTO `creature_addon` VALUES ('234411', '0', '2404', '0', '1', '0', '');
INSERT INTO `creature_addon` VALUES ('234410', '0', '2404', '0', '1', '0', '');
INSERT INTO `creature_addon` VALUES ('233896', '0', '0', '0', '1', '234', '');
INSERT INTO `creature_addon` VALUES ('233889', '0', '0', '0', '1', '234', '');
INSERT INTO `creature_addon` VALUES ('234396', '0', '0', '0', '1', '0', '');
INSERT INTO `creature_addon` VALUES ('233708', '0', '0', '0', '1', '0', '');
INSERT INTO `creature_addon` VALUES ('233886', '0', '0', '0', '1', '234', '');

DELETE FROM creature_text WHERE entry=28914;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28914,0,0,"Make haste, $N. Use the portal!",12,0,100,25,0,0,"Orbaz Bloodlane");
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29176;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=29176;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29176 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29176,0,0,0,0,0,100,2,10000,20000,10000,10000,11,53631,0,0,0,0,0,2,0,0,0,0,0,0,0,"Korfax, Champion of the Light - In Combat - Cast Cleave"),
(29176,0,1,2,0,0,100,0,10000,20000,10000,10000,11,53625,0,0,0,0,0,2,0,0,0,0,0,0,0,"Korfax, Champion of the Light - In Combat - Cast Heroic Leap");

DELETE FROM creature_text WHERE entry=28939;
INSERT INTO creature_text(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28939,1,0,12,0,100,"crusader SAY_CRUSADER1","You'll be hanging in the gallows shortly, Scourge fiend!"),
(28939,1,1,12,0,100,"crusader SAY_CRUSADER2","You'll have to kill me, monster! I will tell you NOTHING!"),
(28939,1,2,12,0,100,"crusader SAY_CRUSADER3","You hit like a girl. Honestly. Is that the best you can do?"),
(28939,1,3,12,0,100,"crusader SAY_CRUSADER4","ARGH! You burned my last good tabard!"),
(28939,1,4,12,0,100,"crusader SAY_CRUSADER5","Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child."),
(28939,1,5,12,0,100,"crusader SAY_CRUSADER6","I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!"),
(28939,2,0,12,0,100,"break crusader SAY_PERSUADED1","I'll tell you everything! STOP! PLEASE!"),
(28939,3,0,12,0,100,"break crusader SAY_PERSUADED2","We... We have only been told that the \"Crimson Dawn\" is an awakening. You see, the Light speaks to the High General. It is the Light..."),
(28939,4,0,12,0,100,"break crusader SAY_PERSUADED3","The Light that guides us. The movement was set in motion before you came... We... We do as we are told. It is what must be done."),
(28939,5,0,12,0,100,"break crusader SAY_PERSUADED4","I know very little else... The High General chooses who may go and who must stay behind. There's nothing else... You must believe me!"),
(28939,6,0,12,0,100,"break crusader SAY_PERSUADED6","NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It..."),
(28939,7,0,12,0,100,"break crusader SAY_PERSUADED7","Over"),
(28939,8,0,12,0,100,"break crusader SAY_PERSUADED8","Over");

DELETE FROM `creature_text` WHERE `entry`=28406;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28406,0,0,12,0,100,"dk initiate SAY_DUEL_A","No potions!"),
(28406,0,1,12,0,100,"dk initiate SAY_DUEL_B","Remember this day, $n, for it is the day that you will be thoroughly owned."),
(28406,0,2,12,0,100,"dk initiate SAY_DUEL_C","I'm going to tear your heart out, cupcake!"),
(28406,0,3,12,0,100,"dk initiate SAY_DUEL_D","Don't make me laugh."),
(28406,0,4,12,0,100,"dk initiate SAY_DUEL_E","Here come the tears..."),
(28406,0,5,12,0,100,"dk initiate SAY_DUEL_F","You have challenged death itself!"),
(28406,0,6,12,0,100,"dk initiate SAY_DUEL_G","The Lich King will see his true champion on this day!"),
(28406,0,7,12,0,100,"dk initiate SAY_DUEL_H","You're going down!"),
(28406,0,8,12,0,100,"dk initiate SAY_DUEL_I","You don't stand a chance, $n");
