-- Dancing Rune Weapon damage reduction
DELETE FROM creature_template_addon WHERE entry=27893;
INSERT INTO creature_template_addon (entry, path_id, mount, bytes1, bytes2, emote, auras) VALUES (27893, 0, 0, 0, 0, 0, '51906');

DELETE FROM spell_proc_event WHERE entry=49028;
INSERT INTO `spell_proc_event` VALUES (49028, 0, 0, 0, 0, 0, 65552, 0, 0, 0, 0);

-- Add parry buff
DELETE FROM spell_linked_spell WHERE spell_trigger=49028;
INSERT INTO `spell_linked_spell` VALUES (49028, 81256, 0, 0, 'Dancing Rune Weapon parry application');

-- Custom template of the npc
DELETE FROM creature_template WHERE entry=27893;
INSERT INTO `creature_template` VALUES ('27893', '0', '0', '0', '0', '0', '1126', '11686', '0', '0', 'Rune Weapon', '', '', '0', '85', '85', '3', '0', '6', '6', '0', '1', '1.14286', '1', '1', '1', '0', '215', '271', '0', '24', '1.7', '3500', '2000', '1', '0', '0', '8', '0', '0', '0', '0', '0', '215', '271', '24', '10', '1096', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', null, null, '', '0', '3', '1', '0.0905', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', 'npc_dancing_rune_weapon', '15595');

