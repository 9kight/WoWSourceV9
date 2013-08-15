-- elvyn forest duplicates and  some rong equipments  fix

UPDATE creature_template SET equipment_id =0  WHERE entry=113;
DELETE FROM creature_equip_template WHERE entry=113;

UPDATE creature_template SET equipment_id=0 WHERE entry=30;
DELETE FROM creature_equip_template WHERE entry=30;

DELETE FROM creature WHERE guid IN (46888,46889,46932,30018,29953,46715,46713,46714);

UPDATE creature_template SET equipment_id=0 WHERE entry=4269;
DELETE FROM creature_equip_template WHERE entry=4269;

UPDATE creature_template SET equipment_id=0 WHERE entry=308;
DELETE FROM creature_equip_template WHERE entry=308;

UPDATE creature_template SET equipment_id=0 WHERE entry=284;
DELETE FROM creature_equip_template WHERE entry=284;
