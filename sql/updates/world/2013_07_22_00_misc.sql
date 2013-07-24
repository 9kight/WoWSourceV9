-- Magmaw 10NHC Entry
SET @MAGMAW = 41570;

-- set loot id
UPDATE creature_template SET lootid=@MAGMAW WHERE entry=@MAGMAW;

-- insert link to reference_loot_template (drop only 2 items)
DELETE FROM creature_loot_template WHERE entry = @MAGMAW;
INSERT INTO creature_loot_template
   (`entry`,`item`,`ChanceOrQuestChance`,`mincountOrRef`,`maxcount`) 
VALUES 
   (@MAGMAW, 0, 100, -@MAGMAW, 2);

-- insert loot list for magmaw
DELETE FROM reference_loot_template WHERE entry = @MAGMAW;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@MAGMAW, 59328, 0, 1, 1, 1, 1),
   (@MAGMAW, 59329, 0, 1, 1, 1, 1),
   (@MAGMAW, 59331, 0, 1, 1, 1, 1),
   (@MAGMAW, 59332, 0, 1, 1, 1, 1),
   (@MAGMAW, 59333, 0, 1, 1, 1, 1),
   (@MAGMAW, 59334, 0, 1, 1, 1, 1),
   (@MAGMAW, 59335, 0, 1, 1, 1, 1),
   (@MAGMAW, 59336, 0, 1, 1, 1, 1),
   (@MAGMAW, 59340, 0, 1, 1, 1, 1),
   (@MAGMAW, 59341, 0, 1, 1, 1, 1),
   (@MAGMAW, 59452, 0, 1, 1, 1, 1),
   (@MAGMAW, 59492, 0, 1, 1, 1, 1);

-- Atramedes 10NHC Entry
SET @ATRAMEDES = 41442;

-- set loot id
UPDATE creature_template SET lootid=@ATRAMEDES WHERE entry=@ATRAMEDES;

-- insert link to reference_loot_template (drop only 2 items)
DELETE FROM creature_loot_template WHERE entry = @ATRAMEDES;
INSERT INTO creature_loot_template
   (`entry`,`item`,`ChanceOrQuestChance`,`mincountOrRef`,`maxcount`) 
VALUES 
   (@ATRAMEDES, 0, 100, -@ATRAMEDES, 2);

-- insert loot list for Atramedes
DELETE FROM reference_loot_template WHERE entry = @ATRAMEDES;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@ATRAMEDES, 59312, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59315, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59316, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59317, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59318, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59319, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59320, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59322, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59324, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59325, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59326, 0, 1, 1, 1, 1),
   (@ATRAMEDES, 59327, 0, 1, 1, 1, 1);

-- CHIMAERON 10NHC Entry
SET @CHIMAERON = 43296;

-- set loot id
UPDATE creature_template SET lootid=@CHIMAERON WHERE entry=@CHIMAERON;

-- insert link to reference_loot_template (drop only 2 items)
DELETE FROM creature_loot_template WHERE entry = @CHIMAERON;
INSERT INTO creature_loot_template
   (`entry`,`item`,`ChanceOrQuestChance`,`mincountOrRef`,`maxcount`) 
VALUES 
   (@CHIMAERON, 64663, 7, 1, 1), -- Bile-Etched Brass Key - Not sure about this 
   (@CHIMAERON, 0, 100, -@CHIMAERON, 2);

-- insert loot list for CHIMAERON
DELETE FROM reference_loot_template WHERE entry = @CHIMAERON;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@CHIMAERON, 59221, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59223, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59224, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59225, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59233, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59234, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59310, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59311, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59313, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59314, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59329, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59340, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59355, 0, 1, 1, 1, 1),
   (@CHIMAERON, 59451, 0, 1, 1, 1, 1);

-- Maloriak 10NHC Entry
SET @MALORIAK = 41378;

-- set loot id
UPDATE creature_template SET lootid=@MALORIAK WHERE entry=@MALORIAK;

-- insert link to reference_loot_template (drop only 2 items)
DELETE FROM creature_loot_template WHERE entry = @MALORIAK;
INSERT INTO creature_loot_template
   (`entry`,`item`,`ChanceOrQuestChance`,`mincountOrRef`,`maxcount`) 
VALUES 
   (@MALORIAK, 0, 100, -@MALORIAK, 2);

-- insert loot list for Maloriak
DELETE FROM reference_loot_template WHERE entry = @MALORIAK;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@MALORIAK, 59342, 0, 1, 1, 1, 1),
   (@MALORIAK, 59343, 0, 1, 1, 1, 1),
   (@MALORIAK, 59344, 0, 1, 1, 1, 1),
   (@MALORIAK, 59346, 0, 1, 1, 1, 1),
   (@MALORIAK, 59347, 0, 1, 1, 1, 1),
   (@MALORIAK, 59348, 0, 1, 1, 1, 1),
   (@MALORIAK, 59349, 0, 1, 1, 1, 1),
   (@MALORIAK, 59350, 0, 1, 1, 1, 1),
   (@MALORIAK, 59351, 0, 1, 1, 1, 1),
   (@MALORIAK, 59352, 0, 1, 1, 1, 1),
   (@MALORIAK, 59353, 0, 1, 1, 1, 1),
   (@MALORIAK, 59354, 0, 1, 1, 1, 1);

SET @NEFARIAN = 41376;
SET @RNDITEM = 41376;
SET @SETITEM = 41377;

DELETE FROM creature_loot_template WHERE entry = @NEFARIAN;
INSERT INTO creature_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@NEFARIAN, 0, 100, 1, 1, -@SETITEM, 2),
   (@NEFARIAN, 1, 100, 1, 1, -@RNDITEM, 1);

DELETE FROM reference_loot_template WHERE entry = @RNDITEM;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@RNDITEM, 59222, 0, 1, 1, 1, 1),
   (@RNDITEM, 59321, 0, 1, 1, 1, 1),
   (@RNDITEM, 59337, 0, 1, 1, 1, 1),
   (@RNDITEM, 59356, 0, 1, 1, 1, 1),
   (@RNDITEM, 59441, 0, 1, 1, 1, 1),
   (@RNDITEM, 59442, 0, 1, 1, 1, 1),
   (@RNDITEM, 59443, 0, 1, 1, 1, 1),
   (@RNDITEM, 59444, 0, 1, 1, 1, 1),
   (@RNDITEM, 59450, 0, 1, 1, 1, 1),
   (@RNDITEM, 59454, 0, 1, 1, 1, 1),
   (@RNDITEM, 59457, 0, 1, 1, 1, 1),
   (@RNDITEM, 59459, 0, 1, 1, 1, 1),
   (@RNDITEM, 63679, 0, 1, 1, 1, 1);

DELETE FROM reference_loot_template WHERE entry = @SETITEM;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@SETITEM, 63682, 0, 1, 1, 1, 1),
   (@SETITEM, 63683, 0, 1, 1, 1, 1),
   (@SETITEM, 63684, 0, 1, 1, 1, 1);
