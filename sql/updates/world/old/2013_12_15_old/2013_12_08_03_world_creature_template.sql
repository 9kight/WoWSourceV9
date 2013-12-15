DELETE FROM `creature_template` WHERE `entry` IN (47243,47244);
INSERT INTO `creature_template` VALUES (47243, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'Mirror Image', '', '', 0, 1, 1, 0, 0, 35, 35, 0, 1, 1.14286, 1, 1.14286, 1, 0, 2, 2, 6, 24, 1, 2000, 2000, 8, 8, 2064, 8, 0, 0, 0, 0, 0, 1, 1, 0, 7, 16777216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56969, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_mirror_image', 13623);
INSERT INTO `creature_template` VALUES (47244, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'Mirror Image', '', '', 0, 1, 1, 0, 0, 35, 35, 0, 1, 1.14286, 1, 1.14286, 1, 0, 2, 2, 2, 24, 1, 2000, 2000, 8, 8, 2064, 8, 0, 0, 0, 0, 0, 1, 1, 0, 7, 16777216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54095, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_mirror_image', 13623);

DELETE FROM `spell_script_names` WHERE `spell_id` = 55342;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (55342, 'spell_mage_mirror_image');

DELETE FROM `spell_bonus_data` WHERE `entry` IN (54095,56969);
INSERT INTO `spell_bonus_data` VALUES (54095, 0.01, 0, 0, 0, 'Mirror Image FireBall Hack');
INSERT INTO `spell_bonus_data` VALUES (56969, 0.01, 0, 0, 0, 'Mirror Image Arcane Deflags Hack');