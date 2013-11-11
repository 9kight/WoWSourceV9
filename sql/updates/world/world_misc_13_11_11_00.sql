
-- correcting mob http://www.wowhead.com/npc=52558
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `exp`=3, `mindmg`=3517, `maxdmg`=4022, `dmg_multiplier`=6.9, `unit_flags`=0, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1, `Health_mod`=178 WHERE `entry`=52558;

-- correcting mob http://www.wowhead.com/npc=52498
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `exp`=3, `mindmg`=6024, `maxdmg`=6718, `dmg_multiplier`=4.8, `unit_class`=2, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1, `Health_mod`=196, `Mana_mod`=1.582 WHERE `entry`=52498;
UPDATE `creature_template` SET `unit_class`=2 WHERE entry=53576;
UPDATE `creature_template` SET `unit_class`=2 WHERE entry=53577;
UPDATE `creature_template` SET `unit_class`=2 WHERE entry=53578;

-- correcting mob http://www.wowhead.com/npc=52620
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `exp`=3, `faction_A`=16, `faction_H`=16, `mindmg`=1812, `maxdmg`=1946, `dmg_multiplier`=2.8, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1, `Health_mod`=7.1043 WHERE `entry`=52620;

-- correcting mob http://www.wowhead.com/npc=52571
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `exp`=3, `faction_A`=16, `faction_H`=16, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1  WHERE `entry`=52571;

-- correcting mob http://www.wowhead.com/npc=53872
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `exp`=3, `mindmg`=1231, `maxdmg`=1423, `dmg_multiplier`=9.9, `unit_flags`=0, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1, `Health_mod`=391 WHERE `entry`=53872;

-- correcting mob http://www.wowhead.com/npc=53140
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `exp`=3, `mindmg`=1921, `maxdmg`=2027, `dmg_multiplier`=3.1, `unit_flags`=0, `dynamicflags`=1, `type_flags`=0, `InhabitType`=1, `Health_mod`=1.3583 WHERE `entry`=53140;


-- replace the mob with the right entry
UPDATE creature SET id=52530 WHERE guid=249744;


-- spawn missing mob http://www.wowhead.com/npc=53691
DELETE FROM creature WHERE guid=326651;
INSERT INTO `creature` VALUES ('326651', '53691', '720', '5723', '5767', '1', '1', '0', '53691', '-31.7591', '-63.2071', '57.3044', '2.74199', '300', '0', '0', '14680078', '0', '0', '0', '0', '0');
-- update subname
UPDATE creature_template SET subname='' WHERE entry='53691';

-- set rank
UPDATE `creature_template` SET `rank`=1 WHERE entry=53619;

-- duplicates must be delete
DELETE FROM creature WHERE guid=249347;
DELETE FROM creature WHERE guid=249555;
DELETE FROM creature WHERE guid=249547;
DELETE FROM creature WHERE guid=249546;
DELETE FROM creature WHERE guid=249914;
DELETE FROM creature WHERE guid=249909;
