<?//������
		echo "document.write('<table><tr><th>ʫ��</th></tr>');";
		mysql_select_db("poetry",$con);
		$result=mysql_query("SELECT * FROM `poetry`");
		while($row=mysql_fetch_row($result)){
			echo "document.write('<tr><td>".$row[1]."</td></tr>');";
		}
		echo "document.write('</table>');";
		exit();


//��������
		mysql_select_db("poetry",$con);
		$result=mysql_query("SELECT * FROM `poetry`");
		echo "document.write('<table><tr><th>ʫ��</th></tr>');";
		while($row=mysql_fetch_row($result)){
			echo "document.write('<tr><td>".$row[1]."</td></tr>');";
		}
		echo "document.write('</table>');";
		exit();
?>