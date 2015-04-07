<?php
	function Q3_2($s){
		$str = explode(" - ",$s);
		$ret = "";
		for($i=0;$i<count($str);$i++)
			$ret .= "<span>" . $str[$i] . "</span>";
		echo $ret;
	}
	
	function enSpan($s){
		return explode(" - ",$s);
	}
?>
