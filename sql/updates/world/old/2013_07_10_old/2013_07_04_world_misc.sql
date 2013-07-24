DELETE FROM `spell_proc_event` WHERE `entry` = 89086;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(89086, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0);

DELETE FROM `spell_bonus_data` WHERE `entry` = 89087;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(89087, 0, 0, 0, 0, 'Darkmoon Card - Hurricane - Lightning Strike');

UPDATE `creature` SET `spawndist` = '0', `MovementType` = '0' WHERE `id` =51346;
