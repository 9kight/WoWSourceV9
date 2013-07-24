DELETE FROM `command` WHERE `name` = 'delstrafe';
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('delstrafe','7','Syntax: .delstrafe $StrafID');
DELETE FROM `command` WHERE `name` = 'tempban' OR `name` = 'deltempban';
INSERT INTO `command` (`name`,`security`,`help`) VALUES 
('tempban','5','Syntax: .tempban $Playername $Reason'),
('deltempban','5','Syntax: .deltempban $Playername');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('ticket sendsurvey','7','Syntax: .ticket sendsurvey $Charaktername');
INSERT INTO `command` (`name`,`help`) VALUES ('verwarnungen','Syntax: .verwarnungen - Zeigt die Verwarnungen eines Accounts an');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('verwarnen','1','Syntax: .verwarnen $Charaktername $Grund');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('strafen','0','Syntax: .strafen - Zeigt die Strafen eines Accounts an');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('strafe','1','Syntax: .strafe $Charaktername $Strafpunkte $Grund');
