DELETE FROM `spell_target_position` WHERE `id` IN (88344,88342);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(88344, 732, -603.723, 1387.62, 21.5382, 0.968372),
(88342, 732, -344.6, 1043.8, 21.473, 1.5);

UPDATE `spell_target_position` SET `target_position_x` = '1776.5', `target_position_y` = '-4338.799', `target_position_z` = '-7.50812', `target_position_z` = '0.458649' WHERE `id` =3567;
