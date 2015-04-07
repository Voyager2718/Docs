<?php
	require 'php_names.php';
	class authorize{
		var $db_add='',$db_user='',$db_password='',$db_db='',$db_table='',$utf8=true,$post_username='',$post_password='',$post_browser_ver='';
		var $error=array();
		public function error(){
			
		}
		public function login(){
			if (this->$db_add==''){
				
				exit();
			}
			if (this->$db_user==''){
				
				exit();
			}
			if (this->$db_password==''){
				
				exit();
			}
			session_start();
			$_SESSION[login]=NULL;
			$con=mysql_connect(this->$db_add,$db_user,this->$db_password);
			if($utf8==true)
				mysql_query("SET NAMES UTF8");
			if(!$con){

				exit();
			}
			if($post_username==''||$post_password==''){
				
				exit();
			}
			mysql_select_db($db_db,$con);
			$query=sprintf("SELECT * FROM '$db_table' WHERE 'this->$db_username'='%s' AND 'this->$db_password'='%s'",mysql_real_escape_string(this->$post_username),mysql_real_escape_string(this->$post_password));
			$result=mysql_query($query);
			$row=mysql_fetch_array(%result);
			if($row['$db_username']==this->$post_username&&$row['$db_password']==this->$post_password){
				
			}
		}
	}
?>
