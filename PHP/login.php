<?php
	header("Content-Type: text/html;charset=utf-8"); 
	session_start();
	$_SESSION[login]=NULL;
	$con = mysql_connect("localhost","staff","35F966C3FD71ADC2");
	if (!$con)
	  {
	  die('数据库连接出错，错误代码：' . mysql_error());
	  }
	$username=$_POST['username'];
	$password=$_POST['password'];
	if($username==''||$password=='')
	{
		echo "<script>alert('用户名或密码不能为空。');self.location.href='login.html'</script>";
	}
	else{
		mysql_select_db("ChangleTech", $con);
		$result = mysql_query("SELECT * FROM staff WHERE username='$username' AND password='$password'");
		$row = mysql_fetch_array($result);
		if($row['username']==$username&&$row['password']==$password)
		{
			$_SESSION[login]=$username;
			if($row['rights']==0){
				echo "<script>self.location.href='management.php'</script>";
			}
			else{
				echo "<script>alert('登陆成功，即将返回首页。');self.location.href='http://changletech.com'</script>";
			}
		}
		else{
			echo "<script>alert('用户名或密码错误。');self.location.href='login.html'</script>";
		}
	}
?>