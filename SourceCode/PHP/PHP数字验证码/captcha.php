<?php
session_start(); 
getCode(4,60,20); 
function getCode($num,$w,$h) { 
    $code = ""; 
	$w = 80;
	$h = 30;
	$num = 5;
    for ($i = 0; $i < $num; $i++) { 
        $code .= rand(0, 9); 
    } 
    //4λ��֤��Ҳ������rand(1000,9999)ֱ������ 
    //�����ɵ���֤��д��session������֤ʱ�� 
    $_SESSION["helloweba_num"] = $code; 
    //����ͼƬ��������ɫֵ 
    header("Content-type: image/PNG"); 
    $im = imagecreate($w, $h); 
    $nums = imagecolorallocate($im, 0, 255, 144); 
    $bg = imagecolorallocate($im, 0, 100, 200); 
    $bgcolor = imagecolorallocate($im, 255, 255, 255); 
    //��䱳�� 
    imagefill($im, 0, 0, $bg); 
 
    //���߿� 
    imagerectangle($im, 0, 0, $w-1, $h-1, $nums); 
 
    //��������������ߣ���������� 
    $style = array ($nums,$nums,$nums,$nums,$nums, 
        $bg,$bg,$bg,$bg,$bg 
    ); 
    imagesetstyle($im, $style); 
    $y1 = rand(0, $h); 
    $y2 = rand(0, $h); 
    $y3 = rand(0, $h); 
    $y4 = rand(0, $h); 
    imageline($im, 0, $y1, $w, $y3, IMG_COLOR_STYLED); 
    imageline($im, 0, $y2, $w, $y4, IMG_COLOR_STYLED); 
 
    //�ڻ�����������ɴ����ڵ㣬���������; 
    for ($i = 0; $i < 80; $i++) { 
        imagesetpixel($im, rand(0, $w), rand(0, $h), $nums); 
    } 
    //�����������ʾ�ڻ�����,�ַ���ˮƽ����λ�ö���һ��������Χ������� 
    $strx = rand(0, 35); //����
    for ($i = 0; $i < $num; $i++) { 
        $strpos = rand(1, 10); 
        imagestring($im, 5, $strx, $strpos, substr($code, $i, 1), $nums); 
        $strx += rand(8, 10); 
    } 
    imagepng($im);//���ͼƬ 
    imagedestroy($im);//�ͷ�ͼƬ��ռ�ڴ� 
} 
?>