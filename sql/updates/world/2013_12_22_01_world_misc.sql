UPDATE `creature_template` SET `ScriptName` = 'mob_grippe_feu_du_crepuscule' WHERE `entry` = 39870;
UPDATE `creature_template` SET `ScriptName` = 'mob_braise_ardente_asservie' WHERE `entry` = 39892;
UPDATE `creature_template` SET `ScriptName` = 'npc_augh_fake' WHERE `entry` = 48104;
UPDATE `creature_template` SET `ScriptName` = 'mob_gardien_de_la_nuee_cramoisie' WHERE `entry` = 39381;
UPDATE `creature_template` SET `ScriptName` = 'mob_brise_tempete_du_crepuscule' WHERE `entry` = 39962;
UPDATE `creature_template` SET `ScriptName` = 'mob_esprit_de_leau_asservi' WHERE `entry` = 39961;
UPDATE `creature_template` SET `ScriptName` = 'mob_elementaire_de_roche_asservi' WHERE `entry` = 39900;
UPDATE `creature_template` SET `ScriptName` = 'mob_sculpte_terre_du_crepuscule' WHERE `entry` = 39890;
UPDATE `creature_template` SET `ScriptName` = 'mob_chercheflamme_rehausse' WHERE `entry` = 39415;
UPDATE `creature_template` SET `ScriptName` = 'mob_marche_vent_rehausse' WHERE `entry` = 39414;
UPDATE `creature_template` SET `ScriptName` = 'mob_brute_gronn_asservie' WHERE `entry` = 40166;
UPDATE `creature_template` SET `ScriptName` = 'mob_esprit_du_tonnerre_asservie' WHERE `entry` = 40269;
UPDATE `creature_template` SET `ScriptName` = 'mob_mande_wyrm_du_crepuscule' WHERE `entry` = 39873;
UPDATE `creature_template` SET `ScriptName` = 'gob_fronde_gobelin' WHERE `entry` = 36514;
UPDATE `creature_template` SET `ScriptName` = 'npc_frostborn_scout' WHERE `entry` = 29811;
UPDATE `creature_template` SET `ScriptName` = 'npc_chipie_quest_giver_end_event' WHERE `entry` = 37680;
UPDATE `creature_template` SET `ScriptName` = 'npc_blaze_of_heavens_egg' WHERE `entry` = 48904;
UPDATE `creature_template` SET `ScriptName` = 'npc_lorna_crowley_event' WHERE `entry` = 35378;
UPDATE `creature_template` SET `ScriptName` = 'npc_rockjaw_defender' WHERE `entry` = 1117;
UPDATE `creature_template` SET `ScriptName` = 'npc_original_hot_rod' WHERE `entry` = 37676;
UPDATE `creature_template` SET `ScriptName` = 'mob_vortex_wind_rotation_manager' WHERE `entry` = 30090;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (86181,86209);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(86181, 'spell_mage_nether_vortex'),
(86209, 'spell_mage_nether_vortex');

DELETE FROM  spell_script_names spell_id=74634;
INSERT INTO `spell_script_names` VALUES ('74634', 'spell_ground_siege');

DELETE FROM  spell_script_names spell_id=62789;
INSERT INTO `spell_script_names` VALUES ('62789', 'spell_xt002_heart_overload_periodic');
