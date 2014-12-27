-- Fix disconnect normal players who dont use hacks
DELETE FROM spell_script_names WHERE ScriptName IN ('spell_gen_fix_anticheat','spell_gen_fix_anticheat1');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES 
(66601,'spell_gen_fix_anticheat');
DELETE FROM spell_lINked_spell WHERE spell_effect IN (66601);
INSERT INTO `spell_lINked_spell`(`spell_trigger`,`spell_effect`,`type`,`req_aura`,`comment`) VALUES 
(1953,66601,0,0,'Fix Anticheat spell Blink Mage'),
(48020,66601,0,0,'Fix Anticheat spell Demonic Circle: Teleport'),
(36554,66601,0,0,'Fix Anticheat spell Shadowstep Rogue'),
(8690,66601,0,0,'Fix Anticheat spell Hearthstone all'),
(6544,66601,0,0,'Fix Anticheat spell Heroic Leap Warrior'),
(100,66601,0,0,'Fix Anticheat spell Charge Warrior');
