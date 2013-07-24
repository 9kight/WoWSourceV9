-- Lord Godfrey
SET @ENTRY = 49712;

DELETE FROM creature_loot_template WHERE entry = @ENTRY;
INSERT INTO creature_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 52078, 85, 1, 0, 1, 1),
   (@ENTRY, 1, 100, 1, 1, -@ENTRY, 2);

DELETE FROM reference_loot_template WHERE entry = @ENTRY;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ENTRY, 63456, 0, 1, 1, 1, 1),
   (@ENTRY, 63457, 0, 1, 1, 1, 1),
   (@ENTRY, 63458, 0, 1, 1, 1, 1),
   (@ENTRY, 63459, 0, 1, 1, 1, 1),
   (@ENTRY, 63460, 0, 1, 1, 1, 1),
   (@ENTRY, 63461, 0, 1, 1, 1, 1),
   (@ENTRY, 63462, 0, 1, 1, 1, 1),
   (@ENTRY, 63463, 0, 1, 1, 1, 1),
   (@ENTRY, 63464, 0, 1, 1, 1, 1),
   (@ENTRY, 63465, 0, 1, 1, 1, 1);

