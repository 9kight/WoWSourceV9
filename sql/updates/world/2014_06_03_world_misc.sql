DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (66548,66549,66550,66551);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (66550,66551);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,66550,0,0,31,0,3,22515,0,0,0,0,'','Isle of Conquest - Teleport Fortress Out'),
(13,1,66550,0,0,35,0,1,10,1,0,0,0,'','Isle of Conquest - Teleport Fortress Out'),
(13,1,66551,0,0,31,0,3,22515,0,0,0,0,'','Isle of Conquest - Teleport Fortress In'),
(13,1,66551,0,0,35,0,1,10,1,0,0,0,'','Isle of Conquest - Teleport Fortress In');

DELETE FROM `creature` WHERE id=22515 and map=628;
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '392.4965', '-859.4583', '48.99871', '3.036873', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '313.2344', '-918.0452', '48.85597', '4.869469', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '279.8698', '-832.8073', '51.55094', '0', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '323.4965', '-883.8021', '48.99959', '1.466077', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '430.6007', '-857.0052', '48.31177', '0.1396263', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '325.9167', '-781.8993', '49.00521', '4.590216', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '326.2135', '-744.0243', '49.43576', '1.308997', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '1139.498', '-779.4739', '48.73496', '3.001966', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '1162.913', '-745.908,', '48.71506', '0.1396263', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '1234.304', '-688.2986', '49.22296', '4.677482', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '1232.524', '-666.3246', '48.13402', '2.303835', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '1233.106', '-838.316,', '48.99958', '1.466077', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '1232.387', '-861.0243', '48.99959', '3.560472', '7200', '0', '0', '1', '0', '0', '0', '0', '0');
INSERT INTO `creature` VALUES ('NULL', '22515', '628', '0', '0', '3', '1', '0', '0', '1296.526', '-766.1823', '50.70293', '3.089233', '7200', '0', '0', '1', '0', '0', '0', '0', '0');

-- my bad  they auto spawn after gate broken from script BG 
DELETE FROM creature WHERE entry IN (292332,292330);