DELETE FROM `trinity_string` WHERE `entry` IN (650,651,657,658,659,660,766,767,757,758,759,760,761,762,768);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(650, 'Alliance', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(651, 'Horde', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(657, 'The %s has taken the %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(658, '$n has defended the %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(659, '$n has assaulted the %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(660, '$n claims the %s! If left unchallenged, the %s will control it in 1 minute!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(766, 'waterworks', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(767, 'lighthouse', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(757, 'The Battle for Gilneas begins in 2 minutes.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(758, 'The Battle for Gilneas begins in 1 minute.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(759, 'The Battle for Gilneas begins in 30 seconds. Prepare yourselves!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(760, 'The Battle for Gilneas has begun!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(761, 'The Alliance has gathered $1776W resources, and is near victory!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(762, 'The Horde has gathered $1777W resources, and is near victory!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(768, 'mine', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
