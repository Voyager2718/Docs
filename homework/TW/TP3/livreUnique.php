<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <title>Bibliothèque</title>
        <meta charset="UTF-8" />
        <link rel="stylesheet" href="" />
    </head>
    <body>
        <header>
            <h1>Bibliothèque</h1>
        </header>
<?php
	require "fonctionsLivre.php";
	echo "	<section>
		<article class = \"livre\">\n			";
	$file = fopen("exempleLivre.txt","r") or die ("Error while opening file.");
	writeToHTML($file);
	echo "\n		</article>
	</section>";
?>
	</body>
</html>