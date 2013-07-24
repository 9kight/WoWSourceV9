-- General Husam HC
SET @ENTRY_HC = 48932;
SET @ENTRY = 44577;

UPDATE creature_template SET lootid = @ENTRY_HC WHERE entry = @ENTRY_HC;

DELETE FROM creature_loot_template WHERE entry = @ENTRY_HC;
INSERT INTO creature_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY_HC, 1, 100, 1, 1, -@ENTRY_HC, 1);

DELETE FROM reference_loot_template WHERE entry = @ENTRY_HC;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY_HC, 56379, 0, 1, 1, 1, 1),
   (@ENTRY_HC, 56380, 0, 1, 1, 1, 1),
   (@ENTRY_HC, 56381, 0, 1, 1, 1, 1),
   (@ENTRY_HC, 56382, 0, 1, 1, 1, 1),
   (@ENTRY_HC, 56383, 0, 1, 1, 1, 1);

-- General Husam NHC
DELETE FROM creature_loot_template WHERE entry = @ENTRY;
INSERT INTO creature_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 1, 100, 1, 1, -@ENTRY, 1);

DELETE FROM reference_loot_template WHERE entry = @ENTRY;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 55856, 0, 1, 1, 1, 1),
   (@ENTRY, 55857, 0, 1, 1, 1, 1),
   (@ENTRY, 55858, 0, 1, 1, 1, 1),
   (@ENTRY, 55859, 0, 1, 1, 1, 1),
   (@ENTRY, 55860, 0, 1, 1, 1, 1);
