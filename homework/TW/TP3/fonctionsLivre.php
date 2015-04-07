<?php
require "exe3.php";
	function propriete ($ligne){//ligne是一行
		$str   = explode(":",$ligne);
		$key   = trim($str[0]);
		$value = isset($str[1])?trim($str[1]):"";
		$key   = str_replace("(","",$key);
		$key   = str_replace(")","",$key);
		return array($key => $value);//返回一个关联数组
	}
	
	function proprieteToHTML($arr){//输出<div class = "项目名">项目内容</div>
		if(key($arr)=="titre")
			return "<h2 class = \"".key($arr)."\">".$arr[key($arr)]."</h2>";
		else if(key($arr)=="année")
			return "<time class = \"".key($arr)."\">".$arr[key($arr)]."</time>";
		else
			return "<div class = \"".key($arr)."\">".$arr[key($arr)]."</div>";
	}
	
	function couvertureToHTML($url){//输入url，输出图片的HTML代码
		return "<div class=\"couverture\"><img src=\"couvertures/".$url."\" title=\"couverture\" /></div>";
	}
	
	function writeToHTML($file){
		while(!feof($file)){
			$ligne = fgets($file);
			$prop = propriete($ligne);
			echo couvertureToHTML($prop[key($prop)]);
			while(trim($ligne)!=""){
				$ligne = fgets($file);
				$prop = propriete($ligne);
				echo proprieteToHTML($prop);
			}
		}
	}
	
	/*
	
			$ligne = fgets($file);
			$prop = propriete($ligne);
			echo couvertureToHTML($prop[key($prop)]);
			while(trim($ligne)!=""){
				$ligne = fgets($file);
				$prop = propriete($ligne);
				echo proprieteToHTML($prop);
			}
	
/*
	function descriptionToHTML($propriete){
		reset($propriete);
		$type = key($propriete);
		if($type == "année")
			$balise="time";
		else
			$balise="div";
		if($type == "auteurs")
			$info = enSpan($propriete[$type]);
		else
			$info = $propriete[$type];
		return "<$balise class = \"$type\">$info</$balise>";
	}	
	function couvertureToHTML($path){
		return "<div class=\"couverture\"><img src=\"couvertures/".$path."\" alt=\"couverture\" /></div>";
	}
	
	function lireLivreToHTML($file){
		$ligne = fgets($file);
		if($ligne == FALSE)
			return FALSE;
		$prop = propriete($ligne);
		$resultat .= couvertureToHTML($prop["couverture"]);
		$ligne = fgets($file);
		$resultat .= "<div class=\"description\">\n";
		while($ligne !== FALSE && trim($ligne) != ""){
			$prop = propriete($ligne);
			$resultat .= descriptionToHTML($prop);
			$ligne = fgets($file);
			
		}
	}
	function prochainLivre($file){
		$ligne = fgets($file);
		if($ligne === FALSE)
			return FALSE;
		$livre = array();
		while($ligne !== FALSE && trim($ligne)!=""){
			$prop = propriete($ligne);
			$livre[key($prop)]=current($prop);
			$ligne = fgets($file);
		}
		return $livre;
	}
	*/
?>
