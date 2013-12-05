DELETE FROM `creature` WHERE guid IN (118012,400484);
INSERT INTO `creature` VALUES ('118012', '111222', '1', '616', '5039', '1', '65535', '0', '0', '3979.41', '-2925.71', '1014.8', '2.01215', '300', '0', '0', '33628', '0', '0', '0', '0', '0');

DELETE FROM `gameobject` WHERE guid=11363;
INSERT INTO `gameobject` VALUES ('11363', '206968', '1', '616', '5039', '1', '1', '3983.5', '-2936.41', '1002.55', '1.91127', '0', '0', '0.81668', '0.577091', '300', '0', '1');

DELETE FROM `areatrigger_teleport` WHERE `id` = 6866;
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(6866, 'Firelands (Exit)', 1, 3987.777588, -2945.166992, 1002.631653, 5.146775);
