-- Baron Ashbury
SET @ENTRY = 49708;

DELETE FROM creature_loot_template WHERE entry = @ENTRY;
INSERT INTO creature_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 1, 100, 1, 1, -@ENTRY, 1);

DELETE FROM reference_loot_template WHERE entry = @ENTRY;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 63433, 0, 1, 1, 1, 1),
   (@ENTRY, 63434, 0, 1, 1, 1, 1),
   (@ENTRY, 63435, 0, 1, 1, 1, 1),
   (@ENTRY, 63436, 0, 1, 1, 1, 1),
   (@ENTRY, 63437, 0, 1, 1, 1, 1);
