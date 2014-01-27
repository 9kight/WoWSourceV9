<?php

const MYSQL_HOST        = 'localhost';
const MYSQL_USER        = 'root';
const MYSQL_PASSWORD    = '';
const WORLD_DB          = 'world';

mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD) or die (mysql_error());
mysql_select_db(WORLD_DB) or die (mysql_error());

$changeData = '-- set npc invisible data<br>';
$backupData = '-- set npc backup data<br>';
$itr = 0;
$dataSave = array();

$result = mysql_query("SELECT * FROM item_template WHERE itemlevel >= 375") or die (mysql_error());
while ($row = mysql_fetch_object($result)) {
	$itemEntry = $row->entry;

	$res = mysql_query("SELECT * FROM npc_vendor WHERE item = $itemEntry") or die (mysql_error());
	while ($r = mysql_fetch_object($res)) {
		$npcEntry = $r->entry;
		$data = mysql_query("SELECT * FROM creature WHERE id = $npcEntry") or die (mysql_error());
		while ($npcInfo = mysql_fetch_object($data)) {
			if (!in_array($dataSave, $npcInfo->guid)) {
				$changeData .= "UPDATE creature SET phaseMask = 4096 WHERE guid = ".$npcInfo->guid."; <br>";
				$backupData .= "UPDATE creature SET phaseMask = ".$npcInfo->phaseMask." WHERE guid = ".$npcInfo->guid."; <br>";
				$dataSave[$itr] = $npcInfo->guid;
				$itr++;
			}
		}
	}
}

echo $changeData.'<br><br><br><br>';
echo $backupData;

?>
