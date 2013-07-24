DELETE FROM `spell_script_names` WHERE `spell_id` IN(93423,93710,93424);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(93423 ,'spell_ashbury_asphyxoate_periodic'),
(93710 ,'spell_ashbury_asphyxoate_periodic');


UPDATE `creature_template` SET `mechanic_immune_mask` = 617299967 WHERE `entry` in(46962,49708);
UPDATE `creature_template` SET `dmg_multiplier` = 30 WHERE `entry` = 49708;

SET @ASHBURY := 46962;
DELETE FROM `creature_text` WHERE `entry`=@ASHBURY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ASHBURY,0,0,"Tally ho! Die Jagd beginnt!",14,0,100,0,0,0,'Ashbury AGGRO'),
(@ASHBURY,1,0,"Von gemeinen Burgern getotet, wie skurril...",14,0,100,0,0,0,'Ashbury DEATH '),
(@ASHBURY,2,0,"Erbärmlich.",14,0,100,0,0,0,'Ashbury SLAY '),
(@ASHBURY,3,0,"Diese Jagd ermüdet mich... Zeit zu sterben!",14,0,100,0,0,0,'Ashbury ARCHANGEL'),
(@ASHBURY,4,0,"Das ist einfach zu leicht...",14,0,100,0,0,0,'ASHBURY Asphyxiate'),
(@ASHBURY,5,0,"HA! Lasst es uns wenigstens interessant gestalten.",14,0,100,0,0,0,'Ashbury Stay of Execution'),
(@ASHBURY,6,0,"|TInterface\\ICONS\\Spell_Holy_HealingAura.blp:20|t%s beginnt, |cFFFF0000|Hspell:93705 |h[Hinrichtungsaufschub]|h|r zu wirken!",41,0,100,0,0,0,'Ashbury EMOTE Stay of Execution');
