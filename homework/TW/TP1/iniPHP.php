<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <title>Premier exercice PHP</title>
        <meta charset="UTF-8" />
        <link rel="stylesheet" href="iniPHP.css" />
    </head>
    <body style="font-family:sans-serif">
        <header>
            <h1>Premier exercice PHP</h1>
            <h2>Réalisé par <span class="nom">YANG Zhipeng</span></h2>
        </header>
        <section>
            <h2>Question 1</h2>
	    Nous Sommes le <?php date_default_timezone_set("Europe/Paris");echo date('d/m/Y'); ?>
        </section>
        <section>
            <h2>Question 2</h2>
	    <?php echo 'Version: '.constant('PHP_VERSION').'<br /> OS: '.constant('PHP_OS');?>
        </section>
	<section>
            <h2>Question 3</h2>
	    <?php $n = 8; $texte = "R.P.Chine"; $value = "\$n vaut $n et \$texte vaut $texte"; echo $value;?>
        </section>
	<section>
            <h2>Question 4</h2>
	    <?php for($i = 0; $i < 5; $i++) echo $texte.'<br />';?>
        </section>
	<section>
            <h2>Question 5</h2>
	    <?php echo 'strlen(\$texte)='.strlen($texte).'<br />'; for($i = 0; $i < strlen($texte); $i++) echo substr($texte,0,strlen($texte)-$i).'<br />';?>
        </section>
	<section>
            <h2>Question 6</h2>
	    <?php echo 'strlen(\$texte)='.strlen($texte).'<br /><ul>'; for($i = 0; $i < strlen($texte); $i++) echo '<li>'.substr($texte,0,strlen($texte)-$i).'</li><br />';echo '</ul>';?>
        </section>
	<section>
            <h2>Question 7</h2>
	    <?php $r = 2; for(; $r<=9; $r++) echo '2*'.$r.'='.(2*$r).'<br />';?>
        </section>
	<section>
            <h2>Question 8</h2>
	    <?php $l = 2; $r = 2; for($r = 2; $r <=9; $r++){for($i = 2; $i <= 9; $i++) echo $i.'*'.$r.'='.($i*$r).' ';echo '<br />';} ?>
        </section>
	<section>
	    <h2>Question 9</h2>
	    <?php
		echo("<table id='multiplaction'>\n");
		echo("<thead>\n");
		echo("<tr><th>*</th>");
		for($i = 2; $i <= 9; $i++)
			echo "<th>$i</th>";
		echo("</td>");
		echo("</thead>\n");
		echo("<tbody>\n");
		for($j = 2; $j <=9; $j++){
			echo("<tr><td>$j</td>");
			for($i =2; $i <=9; $i++)
				echo "<td>".($i*$j)."</td>";
			echo("</tr>\n");
		}
		echo("</tbody>\n");
		echo("</table>\n");
	    ?>
	</section>
    </body>
</html>
