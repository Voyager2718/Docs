<?//能运行
		echo "document.write('<table><tr><th>诗句</th></tr>');";
		mysql_select_db("poetry",$con);
		$result=mysql_query("SELECT * FROM `poetry`");
		while($row=mysql_fetch_row($result)){
			echo "document.write('<tr><td>".$row[1]."</td></tr>');";
		}
		echo "document.write('</table>');";
		exit();


//不能运行
		mysql_select_db("poetry",$con);
		$result=mysql_query("SELECT * FROM `poetry`");
		echo "document.write('<table><tr><th>诗句</th></tr>');";
		while($row=mysql_fetch_row($result)){
			echo "document.write('<tr><td>".$row[1]."</td></tr>');";
		}
		echo "document.write('</table>');";
		exit();
?>