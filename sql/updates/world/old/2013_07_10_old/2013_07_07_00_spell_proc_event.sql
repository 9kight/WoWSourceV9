SET @HURRICANE = 89086;
DELETE FROM spell_proc_event WHERE entry = @HURRICANE;
INSERT INTO spell_proc_event
   (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`)
VALUES
   (@HURRICANE, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0);
