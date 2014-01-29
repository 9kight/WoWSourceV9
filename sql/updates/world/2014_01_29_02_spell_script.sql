DELETE FROM `spell_script_names` WHERE `spell_id`=78; -- Warrior - Heroic Strike
INSERT INTO `spell_script_names` VALUES (78, 'spell_script_names');

DELETE FROM `spell_bonus_data` WHERE `entry`=78; -- Warrior - Heroic Strike
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES (78, 0, 0, 0.6, 0, 'Warrior - Heroic Strike')
