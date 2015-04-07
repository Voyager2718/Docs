<?php
	header("Content-Type: text/html;charset=utf-8"); 
	$login=false;
	session_start();
	if($_SESSION[login]){
		echo "<!DOCTYPE html>

<html lang='en' xmlns='http://www.w3.org/1999/xhtml'>
<head>
    <meta charset='utf-8' />
    <title>長樂科技</title>
    <meta name='keywords' content='長樂科技' />
    <meta name='description' content='長樂科技' />
    <link rel='icon' href='http://voyager2718.github.io/CLT/resources/favicon.ico' />
    <link rel='stylesheet' href='http://voyager2718.github.io/CLT/resources/index.css' />
    <script type='text/javascript' src='http://voyager2718.github.io/CLT/resources/index.js'>
    </script>
    <script type='text/javascript'>
        var noti = false;
    </script>
    <!--<link rel='stylesheet' type='text/css' href='index.css' />-->
    <!--<script src='http://ajax.microsoft.com/ajax/jquery/jquery-1.4.min.js'></script>
    -->
</head>
<body onresize='ResetPage();' onload='ResetPage()'>
    <div class='acc_bar'>
        <input type='button' value='管理' class='acc_button' onclick=\"self.location.href = 'management.php'\" />
        <input style='left: 105px;' type='button' value='退出' class='acc_button' onclick=\"self.location.href = 'logout.php'\" />
    </div>
    <!--登陆栏-->
    <!--
    <div id='test' style='position: absolute; top: 50px;'></div>-->
    <div id='top_bar'></div>
    <br />
    <br />
    <div class='main'>
        <div style='height: 100px;'>
            <!--标题栏-->
            <img class='title_icon' src='http://voyager2718.github.io/CLT/resources/icon_small.png' />
            <table class='title'>
                <tr>
                    <td style='font-size: 40px;'>長樂科技</td>
                </tr>
                <tr>
                    <td style='font-size: 10px;'>ChangLe Technology Dev Group</td>
                </tr>
            </table>
            <table id='title_list'>
                <tr style='color: white;'>
                    <td class='title_list-box '><a class='a_no_under_line_white' href='index.html'>
                        <div>主页</div>
                    </a>
                    </td>
                    <td class='title_list-box '><a class='a_no_under_line_white' href='intro.html'>
                        <div>项目</div>
                    </a>
                    </td>
                    <td class='title_list-box '><a class='a_no_under_line_white' href='activities.html'>
                        <div>新闻</div>
                    </a>
                    </td>
                    <td class='title_list-box '><a class='a_no_under_line_white' href='resources.html'>
                        <div>小组简介</div>
                    </a>
                    </td>
                    <td class='title_list-box '><a class='a_no_under_line_white' href='news.html'>
                        <div>社会责任</div>
                    </a>
                    </td>
                </tr>
            </table>
        </div>
        <div class='showbar'>
            <!--布告栏-->
            <div class='showbar-introduction_layer'>
            </div>
            <div class='showbar-introduction'>
                <table>
                    <tr>
                        <th><a style='text-decoration: none; color: wheat;' href='dynamic'>最新动态</a>
                        </th>
                    </tr>
                    <tr>
                        <td><a class='a_no_under_line_white' href='test3'>长乐科技工作组成立了！</a>
                        </td>
                    </tr>
                    <tr>
                        <td><a class='a_no_under_line_white' href='test3'>测试条目1</a>
                        </td>
                    </tr>
                    <tr>
                        <td><a class='a_no_under_line_white' href='test3'>测试条目2</a></td>
                    </tr>
                </table>
            </div>
            <input id='more_info' value='更多信息' type='button' onclick=\"location.href = 'infos.html'\" />
        </div>
    </div>
    <p style='text-align: center; float: none;'>長樂科技工作组首页-Alpha-0001 Created by 長樂科技 2014 All rights reserved</p>
</body>
</html>
";	
	}
	else{
		echo "<!DOCTYPE html>

<html lang='en' xmlns='http://www.w3.org/1999/xhtml'>
<head>
    <meta charset='utf-8' />
    <title>長樂科技</title>
    <meta name='keywords' content='長樂科技' />
    <meta name='description' content='長樂科技' />
    <link rel='icon' href='http://voyager2718.github.io/CLT/resources/favicon.ico' />
    <link rel='stylesheet' href='http://voyager2718.github.io/CLT/resources/index.css' />
    <script type='text/javascript' src='http://voyager2718.github.io/CLT/resources/index.js'>
    </script>
    <script type='text/javascript'>
        var noti = false;
    </script>
    <!--<link rel='stylesheet' type='text/css' href='index.css' />-->
    <!--<script src='http://ajax.microsoft.com/ajax/jquery/jquery-1.4.min.js'></script>
    -->
</head>
<body onresize='ResetPage();' onload='ResetPage()'>
    <div class='acc_bar'>
        <input type='button' value='登陆' class='acc_button' onclick=\"self.location.href = 'login.html'\" />
    </div>
    <!--登陆栏-->
    <!--
    <div id='test' style='position: absolute; top: 50px;'></div>-->
    <div id='top_bar'></div>
    <br />
    <br />
    <div class='main'>
        <div style='height: 100px;'>
            <!--标题栏-->
            <img class='title_icon' src='http://voyager2718.github.io/CLT/resources/icon_small.png' />
            <table class='title'>
                <tr>
                    <td style='font-size: 40px;'>長樂科技</td>
                </tr>
                <tr>
                    <td style='font-size: 10px;'>ChangLe Technology Dev Group</td>
                </tr>
            </table>
            <table id='title_list'>
                <tr style='color: white;'>
                    <td class='title_list-box '><a class='a_no_under_line_white' href='index.html'>
                        <div>主页</div>
                    </a>
                    </td>
                    <td class='title_list-box '><a class='a_no_under_line_white' href='intro.html'>
                        <div>项目</div>
                    </a>
                    </td>
                    <td class='title_list-box '><a class='a_no_under_line_white' href='activities.html'>
                        <div>新闻</div>
                    </a>
                    </td>
                    <td class='title_list-box '><a class='a_no_under_line_white' href='resources.html'>
                        <div>小组简介</div>
                    </a>
                    </td>
                    <td class='title_list-box '><a class='a_no_under_line_white' href='news.html'>
                        <div>社会责任</div>
                    </a>
                    </td>
                </tr>
            </table>
        </div>
        <div class='showbar'>
            <!--布告栏-->
            <div class='showbar-introduction_layer'>
            </div>
            <div class='showbar-introduction'>
                <table>
                    <tr>
                        <th><a style='text-decoration: none; color: wheat;' href='dynamic'>最新动态</a>
                        </th>
                    </tr>
                    <tr>
                        <td><a class='a_no_under_line_white' href='test3'>长乐科技工作组成立了！</a>
                        </td>
                    </tr>
                    <tr>
                        <td><a class='a_no_under_line_white' href='test3'>测试条目1</a>
                        </td>
                    </tr>
                    <tr>
                        <td><a class='a_no_under_line_white' href='test3'>测试条目2</a></td>
                    </tr>
                </table>
            </div>
            <input id='more_info' value='更多信息' type='button' onclick=\"location.href = 'infos.html'\" />
        </div>
    </div>
    <p style='text-align: center; float: none;'>長樂科技工作组首页-Alpha-0001 Created by 長樂科技 2014 All rights reserved</p>
</body>
</html>";
	}
?>