<?php
require "exe3.php";
$file = fopen('liste_noms.txt','r') or die("Error while opening files.");
echo '<ul>';
while(!feof($file))
	echo '<li>'.fgets($file).'</li>';
echo '</ul>';
fclose($file);
Q3_2("123 - 456");
?>
