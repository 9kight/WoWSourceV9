UPDATE `creature_template` SET spell1='18431', spell2='18576', spell3='18617', spell4='18351', spell5='18596', spell6='17086', spell7='18584', spell8='21131' WHERE entry='10184';
DELETE FROM `skinning_loot_template` WHERE entry='10184';
INSERT INTO `skinning_loot_template` VALUES ('10184', '15410', '89.16', '1', '0', '1', '6');
UPDATE `creature_template` SET skinloot='10184' WHERE entry='10184';

UPDATE `creature_template` SET spell1='68958', spell2='68959' WHERE entry='36561';

UPDATE `creature_template` SET spell1='15284', spell2='20203', spell3='18958', spell4='12097' WHERE entry='12129';
DELETE FROM `skinning_loot_template` WHERE entry='12129';
INSERT INTO `skinning_loot_template` VALUES ('12129', '8170', '73.77', '1', '0', '1', '20');
INSERT INTO `skinning_loot_template` VALUES ('12129', '8171', '18.23', '1', '0', '1', '10');
UPDATE `creature_template` SET skinloot='12129' WHERE entry='12129';

UPDATE `creature_template` SET spell1='42433' WHERE entry='23789';
