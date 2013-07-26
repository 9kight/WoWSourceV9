-- Top portal
DELETE from gameobject_template WHERE entry = 191539;
INSERT INTO `gameobject_template` VALUES 
(191539, 6, 6699, 'Doodad_Nox_portal_purple_bossroom17', '', '', '', 114, 32, 0.703538, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 15595);

DELETE FROM gameobject WHERE id = 191539;
INSERT INTO `gameobject` VALUES 
(106001, 191539, 609, 0, 0, 1, 197, 2383.65, -5645.2, 420.772, 0.59341, 0, 0, 0.292372, 0.956305, 180, 0, 0),
(106002, 191539, 0, 0, 0, 1, 32768, 2383.65, -5645.2, 420.773, 0.59341, 0, 0, 0.292371, 0.956305, 180, 100, 0);


-- Lower portal
DELETE from gameobject_template WHERE entry = 191538;
INSERT INTO `gameobject_template` VALUES 
(191538, 1, 6699, 'Doodad_Nox_portal_purple_bossroom01', '', '', '', 114, 32, 0.703538, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 15595);

DELETE FROM gameobject WHERE id = 191538;
INSERT INTO `gameobject` VALUES 
(106003, 191538, 609, 0, 0, 1, 197, 2390.02, -5640.91, 377.093, 0.59341, 0, 0, 0.292372, 0.956305, 180, 0, 0),
(106004, 191538, 0, 0, 0, 1, 32768, 2390.02, -5640.91, 377.094, 0.59341, 0, 0, 0.292371, 0.956305, 180, 100, 0);
