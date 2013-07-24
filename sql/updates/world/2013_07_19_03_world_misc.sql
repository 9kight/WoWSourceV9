-- Volatile Mutation
UPDATE creature_template
SET npcflag  = 0
WHERE entry = 16516;

-- Blood Elf Scout
UPDATE creature_template
SET npcflag  = 0
WHERE entry = 16521;

UPDATE creature_template
SET equipment_id  = 16521
WHERE entry = 16521;

-- Surveyor Candress
UPDATE creature_template
SET npcflag  = 0
WHERE entry = 16522;

UPDATE creature_template
SET equipment_id  = 16522
WHERE entry = 16522;

-- Red Crystal Bunny
UPDATE creature_template
SET flags_extra  = 130
WHERE entry = 17947;
