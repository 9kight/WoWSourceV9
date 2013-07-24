-- Fix quest 14461 feed no evil
UPDATE quest_template
SET RequiredSpellCast1 = 69228
WHERE id = 14461;

UPDATE quest_template
SET RequiredSpellCast2 = 69228
WHERE id = 14461;

UPDATE quest_template
SET RequiredSpellCast3 = 69228
WHERE id = 14461;
