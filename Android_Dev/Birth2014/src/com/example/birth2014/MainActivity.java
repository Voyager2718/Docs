package com.example.birth2014;

import android.support.v7.app.ActionBarActivity;
import android.app.AlertDialog;
import android.os.Bundle;
//import android.os.SystemClock;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.RelativeLayout;
import android.media.MediaPlayer;

public class MainActivity extends ActionBarActivity {
	int clicked = 0;
	//int times = 0;
	// 控件定义
	public void onClick_Event(View view) {
		RelativeLayout img0 = (RelativeLayout)findViewById(R.id.imageView0);
		/*
		RelativeLayout img1 = (RelativeLayout)findViewById(R.id.imageView1);
		RelativeLayout img2 = (RelativeLayout)findViewById(R.id.imageView2);
		RelativeLayout img3 = (RelativeLayout)findViewById(R.id.imageView3);
		RelativeLayout img4 = (RelativeLayout)findViewById(R.id.imageView4);
		RelativeLayout img5 = (RelativeLayout)findViewById(R.id.imageView5);
		RelativeLayout img6 = (RelativeLayout)findViewById(R.id.imageView6);
		RelativeLayout img7 = (RelativeLayout)findViewById(R.id.imageView7);
		RelativeLayout img8 = (RelativeLayout)findViewById(R.id.imageView8);
		RelativeLayout img9 = (RelativeLayout)findViewById(R.id.imageView9);
		RelativeLayout img10= (RelativeLayout)findViewById(R.id.imageView10);
		RelativeLayout img11= (RelativeLayout)findViewById(R.id.imageView11);
		*/
		if (clicked == 0) {
			new AlertDialog.Builder(this).setMessage("按一下灭一个~")
					.setTitle("吹蜡烛 v0.42b").show();
			// 设置按了确认以后才播放音乐
			// 最好设置成有延迟播放音乐
			MediaPlayer mp;
			mp = MediaPlayer.create(MainActivity.this, R.raw.music0);
			mp.setLooping(false);
			mp.start();
			clicked = 1;
			img0.setVisibility(View.INVISIBLE);//times++;
		}/*
		switch (times){
		case 0:img0.setVisibility(View.INVISIBLE);times++;break;
		case 1:img1.setVisibility(View.INVISIBLE);times++;break;
		case 2:img2.setVisibility(View.INVISIBLE);times++;break;
		case 3:img3.setVisibility(View.INVISIBLE);times++;break;
		case 4:img4.setVisibility(View.INVISIBLE);times++;break;
		case 5:img5.setVisibility(View.INVISIBLE);times++;break;
		case 6:img6.setVisibility(View.INVISIBLE);times++;break;
		case 7:img7.setVisibility(View.INVISIBLE);times++;break;
		case 8:img8.setVisibility(View.INVISIBLE);times++;break;
		case 9:img9.setVisibility(View.INVISIBLE);times++;break;
		case 10:img10.setVisibility(View.INVISIBLE);times++;break;
		case 11:img11.setVisibility(View.INVISIBLE);times++;break;
		default:new AlertDialog.Builder(this).setMessage("所有蜡烛已经吹灭啦")
		.setTitle("吹完鸟").show();break;
		}*/
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		// 主程序
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
}
