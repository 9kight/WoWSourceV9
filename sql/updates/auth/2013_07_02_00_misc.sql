DROP TABLE IF EXISTS `account_tempban`;
CREATE TABLE `account_tempban` (
    accountId int(11) PRIMARY KEY,
    reason varchar(255) NOT NULL
);

DROP TABLE IF EXISTS `account_strafe`;
CREATE TABLE `account_strafe` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `account` int(11) unsigned NOT NULL,
  `by` int(11) NOT NULL,
  `strafpunkte` int(11) unsigned NOT NULL,
  `comment` varchar(255) NOT NULL,
  `time` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `account_verwarnung`;
CREATE TABLE `account_verwarnung` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `accountId` int(11) unsigned NOT NULL,
  `by_account` int(11) unsigned NOT NULL,
  `comment` varchar(255) NOT NULL,
  `time` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `account_strafe` ADD COLUMN `active` tinyint(3) NOT NULL AFTER `time`;
UPDATE `account_strafe` SET `active` = '1';
