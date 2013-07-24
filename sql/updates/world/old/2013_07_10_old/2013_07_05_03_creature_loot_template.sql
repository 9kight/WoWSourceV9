-- Lord Walden
SET @ENTRY = 49711;

DELETE FROM creature_loot_template WHERE entry = @ENTRY;
INSERT INTO creature_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 1, 100, 1, 1, -@ENTRY, 1);

DELETE FROM reference_loot_template WHERE entry = @ENTRY;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 63450, 0, 1, 1, 1, 1),
   (@ENTRY, 63452, 0, 1, 1, 1, 1),
   (@ENTRY, 63453, 0, 1, 1, 1, 1),
   (@ENTRY, 63454, 0, 1, 1, 1, 1),
   (@ENTRY, 63455, 0, 1, 1, 1, 1);
