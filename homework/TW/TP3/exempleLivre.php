<?php
	function propriete ($ligne= "123:456"){
		$decoupe = explode(":",$ligne);
		$info = trim($decoupe[1]);
		$type = trim($decoupe[0]);
		$type = str_replace("(","",$type);
		$type = str_replace(")","",$type);
		return array($type => $info);
	}
	function proprieteToHTML($arr){
		return "<div class=\"".$arr[0]."\">".$arr[1]."</div>";
	}
	function couvertureToHTML($path){
		return "<div class=\"couverture\"><img src=\"couvertures/".$path."\" alt=\"couverture\" /></div>";
	}
?>
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
        <section>
            <article class="livre">
                <div class="couverture">
                    <img src="couvertures/scorpion.jpg" alt="couverture" />
                </div>
                <div class="description">
                    <h2 class="titre">La marque du diable</h2>
                    <div class="auteurs"><span>Marini</span> <span>Desberg</span></div>
                    <time class="année">2000</time>
                    <div class="série">Le Scorpion</div>
                    <div class="catégorie">bandes-dessinées</div>  
                </div>
            </article>
        </section>
    </body>
    
</html>
