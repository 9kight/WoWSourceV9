UPDATE creature_template set ScriptName = 'npc_crystalline_elemental' WHERE entry = 55559;
UPDATE creature_template set ScriptName = 'npc_frozen_servitor' WHERE entry = 54555;

DELETE FROM instance_template WHERE map = 940;
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES 
(940, 0, 'instance_hour_of_twilight', 1);