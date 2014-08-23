-- incorrect and not needed
DELETE FROM achievement_criteria_data WHERE criteria_id IN (7573,7574) AND type = 12;
DELETE FROM achievement_criteria_data WHERE criteria_id = 6084 AND type = 11;

-- these spells ids dnt exist at all
DELETE FROM spell_script_names WHERE spell_id IN (-50294,-49145,-33851,13161,18541,34074);

-- mising scriptname for boss deathwing
UPDATE creature_template SET ScriptName = 'Teleportation_to_the_platforms' WHERE entry = 57328;

-- myst if you change scriptnames make sure to make the changes in db to plz
UPDATE creature_template SET ScriptName = 'npc_hungry_hobo' WHERE entry = 42617;