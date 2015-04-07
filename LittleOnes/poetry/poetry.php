<?php
	header("Content-Type: text/html;charset=utf-8"); 
	$con = mysql_connect("localhost","poetry","2B62DBB531911713");
	if($_GET['action']=="show"){
		mysql_query("SET NAMES utf8");
		echo "document.write('<table><tr><th style=\"width: 70%\">诗句</th><th style=\"width: 20%\">出处</th></tr>');";
		mysql_select_db("poetry",$con);
		$result=mysql_query("SELECT * FROM `poetry` ORDER BY `pid` DESC;");
		while($row=mysql_fetch_row($result)){
			echo "document.write('<tr><td>".$row[1]."</td><td>《".$row[2]."》</td></tr>');";
		}
		echo "document.write('</table>');";
		exit();
	}
	mysql_query("SET NAMES utf8");
	if (!$con)
	  {
	  die('数据库连接出错，错误代码：' . mysql_error()).".";
	  }
	$poem=$_POST['poem'];
	$password=$_POST['password'];
	$provenance=$_POST['provenance'];
	$cquery=$_POST['query'];
	$qpassword=$_POST['qpassword'];
	if($_GET['action']=='query'){
		if($qpassword=='yangzhipeng'){
			mysql_query($cquery);
			echo "<script>alert('成功查询数据库');self.location.href='index.html';</script>";
			exit();
		}
		echo "<script>alert('密码错误');self.location.href='index.html';</script>";
		exit();
	}
	if($poem==''||$password==''||$provenance=='')
	{
		echo "<script>alert('有未填写空缺.');self.location.href='index.html';</script>";
		exit();
	}
	else{
		mysql_select_db("poetry", $con);
		$query=sprintf("SELECT * FROM users WHERE BINARY codes='%s'",mysql_real_escape_string($password));
		$result = mysql_query($query);
		$row = mysql_fetch_array($result);
		if($row['codes']==$password)
		{
			$UID=$row['uid'];
			$query2=sprintf("INSERT INTO `poetry`.`poetry` (`pid`, `poems`, `provenance`, `uid`) VALUES (NULL, '%s','%s','%s');",mysql_real_escape_string($poem),mysql_real_escape_string($provenance),mysql_real_escape_string($UID));
			mysql_query($query2);
			echo "<script>alert('成功输入');self.location.href='index.html';</script>";
		}
		else{
			echo "<script>alert('识别码错误.');self.location.href='index.html';</script>";
		}
	}
?>