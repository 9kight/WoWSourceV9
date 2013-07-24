-- Commander Springvale
SET @ENTRY = 49710;

DELETE FROM creature_loot_template WHERE entry = @ENTRY;
INSERT INTO creature_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 1, 100, 1, 1, -@ENTRY, 1);

DELETE FROM reference_loot_template WHERE entry = @ENTRY;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 63445, 0, 1, 1, 1, 1),
   (@ENTRY, 63446, 0, 1, 1, 1, 1),
   (@ENTRY, 63447, 0, 1, 1, 1, 1),
   (@ENTRY, 63448, 0, 1, 1, 1, 1),
   (@ENTRY, 63449, 0, 1, 1, 1, 1),
   (@ENTRY, 71715, 0, 1, 1, 1, 1);
