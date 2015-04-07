<?php
	header("Content-Type: text/html;charset=utf-8"); 
	$con = mysql_connect("localhost","little","AE9A56108DA12CD5");
	mysql_query("SET NAMES utf8");
	if (!$con)
	{
	  die('数据库连接出错，错误代码：' . mysql_error()).".";
	}
	mysql_select_db("little", $con);
	$name=$_POST['name'];
	$desc=$_POST['desc'];
	$ip=$_SERVER['REMOTE_ADDR'];
	$navi=$_POST['navi'];
	$query=sprintf("INSERT INTO `little`.`opinion` (`desc`, `name`, `navi`, `ip`) VALUES ('%s', '%s', '%s', '%s');",mysql_real_escape_string($desc),mysql_real_escape_string($name),mysql_real_escape_string($navi),mysql_real_escape_string($ip));
	mysql_query($query);
	echo "<script>alert('OK^_^');</script><p>请回到微信朋友圈</p>";
	exit();
?>