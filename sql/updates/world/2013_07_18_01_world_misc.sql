-- Fix Blackrock Battle Worg Human start zone
UPDATE creature
SET curhealth = 45
WHERE id = 49871;

UPDATE creature_template
SET faction_A = 32
WHERE entry = 49871;

UPDATE creature_template
SET faction_H = 32
WHERE entry = 49871;

UPDATE creature_template
SET npcflag  = 0
WHERE entry = 49871;

-- Goblin Assassin
UPDATE creature_template
SET faction_A = 7
WHERE entry = 49871;

UPDATE creature_template
SET faction_H = 7
WHERE entry = 50039;

UPDATE creature_template
SET npcflag  = 0
WHERE entry = 50039;

-- Injured Stormwind Infantry Quest Fear no Evil can now be Completed
DELETE FROM smart_scripts WHERE entryorguid = 50047;
INSERT INTO `smart_scripts` VALUES 
(50047, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 99, 20, 50, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset, set my hp between 20 and 50%'),
(50047, 0, 1, 0, 8, 0, 100, 0, 93097, 0, 0, 0, 80, 5004700, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - On Spellhit - Run Script'),
(50047, 0, 1, 2, 8, 0, 100, 0, 93097, 0, 200, 200, 33, 50047, 0, 0, 0, 0, 0, 21, 5, 0, 0, 0, 0, 0, 0, 'Give Quest Credit to player'),
(50047, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 5004700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Spellhit, Start timed event');

DELETE from npc_spellclick_spells WHERE npc_entry = 50047;
INSERT INTO `npc_spellclick_spells` VALUES 
(50047, 93072, 1, 0),
(50047, 93097, 0, 0);

-- Stormwind Infantry
UPDATE creature_template
SET equipment_id = 49869
WHERE entry = 49869;
