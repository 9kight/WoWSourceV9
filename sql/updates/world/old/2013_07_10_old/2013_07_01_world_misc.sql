UPDATE `creature_template` SET `AIName` = '' WHERE `entry` =6109;

DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 6109;

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `faction_A` = '16', `faction_H` = '16', `flags_extra` = '128' WHERE `entry` =50503;

UPDATE `creature_template` SET `modelid1` = '11686', `modelid2` = '11686' WHERE `entry` =50439;

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `faction_A` = '16', `faction_H` = '16', `flags_extra` = '130' WHERE `entry` =52065;

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `faction_A` = '16', `faction_H` = '16', `flags_extra` = '130' WHERE `entry` =44798;

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `faction_A` = '16', `faction_H` = '16', `flags_extra` = '130' WHERE `entry` =44712;

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `faction_A` = '16', `faction_H` = '16', `flags_extra` = '130' WHERE `entry` =44711;

UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `faction_A` = '16', `faction_H` = '16', `flags_extra` = '130' WHERE `entry` =44840;

UPDATE `creature_template` SET `flags_extra` = '128' WHERE `entry` =48907;
