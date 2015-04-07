<?php
	header("Content-Type: text/html;charset=utf-8"); 
	$login=false;
	session_start();
	if($_SESSION[login]){
		echo "logined.";	
	}
	else{
		echo "<script>alert('Please login.');self.location.href='index.html'</script>";
	}
?>