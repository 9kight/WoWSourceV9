SET @REF_ENTRY = 35220; 

DELETE FROM creature_loot_template WHERE 
entry IN (42362, 42649, 42764, 42767, 42768, 42800, 42802, 43126, 46083) 
AND item IN (53010, 55378, 55665, 58256, 58268, 59460, 59461, 59462, 59463);

DELETE FROM creature_loot_template WHERE entry = @ENTRY AND mincountOrRef = -@REF_ENTRY;
INSERT INTO creature_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (42362, 1, 1.5, 1, 1, -@REF_ENTRY, 1),
   (42649, 1, 1.5, 1, 1, -@REF_ENTRY, 1),
   (42764, 1, 1.5, 1, 1, -@REF_ENTRY, 1),
   (42767, 1, 1.5, 1, 1, -@REF_ENTRY, 1),
   (42768, 1, 1.5, 1, 1, -@REF_ENTRY, 1),
   (42800, 1, 1.5, 1, 1, -@REF_ENTRY, 1),
   (42802, 1, 1.5, 1, 1, -@REF_ENTRY, 1),
   (43126, 1, 1.5, 1, 1, -@REF_ENTRY, 1),
   (46083, 1, 1.5, 1, 1, -@REF_ENTRY, 1);


DELETE FROM reference_loot_template WHERE entry = @REF_ENTRY;
INSERT INTO reference_loot_template
   (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
   (@REF_ENTRY, 53010, 0, 1, 1, 1, 1),
   (@REF_ENTRY, 55378, 0, 1, 1, 1, 1),
   (@REF_ENTRY, 55665, 0, 1, 1, 1, 1),
   (@REF_ENTRY, 58256, 0, 1, 1, 1, 1),
   (@REF_ENTRY, 58268, 0, 1, 1, 1, 1),
   (@REF_ENTRY, 59460, 0, 1, 1, 1, 1),
   (@REF_ENTRY, 59461, 0, 1, 1, 1, 1),
   (@REF_ENTRY, 59462, 0, 1, 1, 1, 1),
   (@REF_ENTRY, 59463, 0, 1, 1, 1, 1);
