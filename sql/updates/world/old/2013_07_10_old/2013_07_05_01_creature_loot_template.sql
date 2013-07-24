-- Baron Silverlaine
SET @ENTRY = 49709;

DELETE FROM creature_loot_template WHERE entry = @ENTRY;
INSERT INTO creature_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 1, 100, 1, 1, -@ENTRY, 1);

DELETE FROM reference_loot_template WHERE entry = @ENTRY;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 63438, 0, 1, 1, 1, 1),
   (@ENTRY, 63439, 0, 1, 1, 1, 1),
   (@ENTRY, 63440, 0, 1, 1, 1, 1),
   (@ENTRY, 63441, 0, 1, 1, 1, 1),
   (@ENTRY, 63444, 0, 1, 1, 1, 1);
