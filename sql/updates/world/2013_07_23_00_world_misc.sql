UPDATE creature_template SET VehicleId = 494, ScriptName = 'npc_king_greymanes_horse' WHERE entry = 35905;
UPDATE creature_template SET InhabitType = 5 WHERE entry = 35753;
UPDATE creature_template SET ScriptName = 'npc_krennan_aranas' WHERE entry = 35907;

DELETE FROM creature WHERE guid = 300715;
INSERT INTO creature (guid, id, map, spawnMask, phaseMask, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, MovementType) VALUES
(300715, 35753, 654, 1, 4, -1677.106812, 1346.708862, 21.215927, 0.374957, 7200, 0, 0);

DELETE FROM creature_template_addon WHERE entry = 35753;
INSERT INTO creature_template_addon (entry, emote, auras) VALUES
(35753, 472, '49414');

DELETE FROM conditions WHERE SourceEntry = 68228;
INSERT INTO conditions (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ElseGroup,ConditionTypeOrReference,ConditionValue1,ConditionValue2,ConditionValue3) VALUES 
(13,1,68228,0,18,1,35753,0);

DELETE FROM spell_script_names WHERE spell_id IN (68219, 68228);
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(68219, 'spell_rescue_krennan');

DELETE FROM spell_area WHERE spell = 49416;
INSERT INTO spell_area (spell,area,quest_start,quest_start_active,aura_spell,racemask,gender) VALUES 
(49416,4757,14293,1,0,0,2);

DELETE FROM waypoint_data WHERE id IN(3590700, 3590701);
INSERT INTO waypoint_data (id,point,position_x,position_y,position_z,move_flag) VALUES 
(3590700, 1, -1798.511108, 1398.395630, 19.863216, 1),
(3590700, 2, -1793.586548, 1377.932983, 19.794540, 1),
(3590700, 3, -1770.100342, 1355.922852, 19.730570, 1),
(3590700, 4, -1745.694702, 1360.722656, 19.721403, 1),
(3590700, 5, -1707.294556, 1349.699951, 19.896275, 1),
(3590701, 1, -1667.122437, 1348.478394, 15.189490, 1),
(3590701, 2, -1665.192261, 1360.726563, 15.134825, 1),
(3590701, 3, -1676.682861, 1361.144653, 15.134825, 1),
(3590701, 4, -1692.466431, 1352.553833, 15.121456, 1),
(3590701, 5, -1705.095947, 1347.391357, 19.896536, 1),
(3590701, 6, -1737.430908, 1371.958618, 19.811749, 1),
(3590701, 7, -1767.937622, 1403.527466, 19.726831, 1),
(3590701, 8, -1775.702637, 1424.763672, 19.783419, 1);

DELETE FROM creature_text WHERE entry IN(35753, 35905);
INSERT INTO creature_text (entry,groupid,id,text,type,probability,comment) VALUES 
(35905,0,0,'Rescue Krennan Aranas by using your vehicle\'s ability.$B|TInterface\\Icons\\inv_misc_groupneedmore.blp:64|t',5,100,'King Greymane\'s Horse'),
(35753,0,0,'Help!  Up here!',1,100,'King Greymane\'s Horse');

UPDATE `creature_template` SET `faction_A` = '35', `faction_H` = '35' WHERE `entry` IN (46965,43735);

UPDATE `creature_template` SET `faction_A` = '35', `faction_H` = '35', `flags_extra` = '130' WHERE `creature_template`.`entry` IN (45420,45685);
