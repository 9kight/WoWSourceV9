DELETE FROM `pool_template` WHERE `entry` IN (50003,50004,50005,50006,50007,50008);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(50003, 1, 'Cataclysm Horde Cooking Daily'),
(50004, 1, 'Cataclysm Ally Cooking Daily'),
(50005, 1, 'Cataclysm Horde Jewel Daily'),
(50006, 1, 'Cataclysm Ally Jewel Daily'),
(50007, 1, 'Cataclysm Horde Fishing Daily'),
(50008, 1, 'Cataclysm Ally Fishing Daily');

DELETE FROM `pool_quest` WHERE `pool_entry` IN (50003,50004,50005,50006,50007,50008);
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(26220, 50003, 'Everything Is Better with Bacon'),
(26226, 50003, 'Crawfish Creole'),
(26227, 50003, 'Careful, This Fruit Bites Back'),
(26233, 50003, 'Stealing From Our Own'),
(26235, 50003, 'Even Thieves Get Hungry'),

(26153, 50004, 'Penny''s Pumpkin Pancakes'),
(26177, 50004, 'Feeling Crabby?'),
(26183, 50004, 'The Kings Cider'),
(26190, 50004, 'A Fishermans Feast'),
(26192, 50004, 'Orphans Like Cookies Too!'),

(25158, 50005, 'Nibbler! No!'),
(25159, 50005, 'The Latest Fashion!'),
(25160, 50005, 'A Present for Lila'),
(25161, 50005, 'Ogrezonians in the Mood'),
(25162, 50005, 'Elemental Goo'),

(25105, 50006, 'Nibbler! No!'),
(25154, 50006, 'A Present for Lila'),
(25155, 50006, 'Ogrezonians in the Mood'),
(25156, 50006, 'Elemental Goo'),
(25157, 50006, 'The Latest Fashion!'),

(26543, 50007, 'Clammy Hands'),
(26556, 50007, 'No Dumping Allowed'),
(26557, 50007, 'A Staggering Effort'),
(26572, 50007, 'A Golden Opportunity'),
(26588, 50007, 'A Furious Catch'),

(26414, 50008, 'Hitting a Walleye'),
(26420, 50008, 'Diggin For Worms'),
(26442, 50008, 'Rock Lobster'),
(26488, 50008, 'Big Gulp'),
(26536, 50008, 'Thunder Falls');
