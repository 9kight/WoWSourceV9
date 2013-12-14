-- fix vendor Edlan Halsing <Honor Trade Goods>
DELETE FROM `npc_vendor` WHERE `entry`='52029';
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `ExtendedCost`) VALUES ('52029', '1', '52722', '3750');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `ExtendedCost`) VALUES ('52029', '1', '52721', '600');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `ExtendedCost`) VALUES ('52029', '2', '68813', '1500');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `ExtendedCost`) VALUES ('52029', '3', '52719', '400');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `ExtendedCost`) VALUES ('52029', '4', '52185', '1000');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `ExtendedCost`) VALUES ('52029', '5', '53010', '1250');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `ExtendedCost`) VALUES ('52029', '6', '52555', '100');
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `ExtendedCost`) VALUES ('52029', '7', '52976', '375');