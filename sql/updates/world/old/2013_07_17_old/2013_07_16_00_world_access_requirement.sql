DELETE FROM `access_requirement` WHERE `access_requirement`.`mapId` = 33 AND `difficulty` = 1;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `quest_failed_text`, `comment`) VALUES
(33, 1, 85, 0, 0, 0, 0, 0, 0, NULL, 'Shadowfang Keep Entrance');
