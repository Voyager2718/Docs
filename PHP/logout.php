<?php  
	header("Content-Type: text/html;charset=utf-8"); 
    session_start();  
    unset($_SESSION[login]);  
    session_destroy();  
    echo "<script>alert('退出成功.');window.location.href='http://changletech.com';</script>";  
?>  