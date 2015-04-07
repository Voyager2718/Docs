//#define MaxVal 10000

#include<thread>

#include<iostream>
#include<time.h>
#include<string.h>
#include"yang.h"
#include<math.h>
#include<Windows.h>

//#include"yang_c.h"

using namespace std;
using namespace yang;

void BubSort(int *pArr0, int MaxVal){
	BubbleSort(pArr0,MaxVal);
}

int main(int argc, char* argv){
	/*
	int MaxVal = 0;
	cout<<"输入数组大小:";
	cin>>MaxVal;
	*/
	srand((unsigned int)time(NULL));

	cout<<"输入测试级别（1~5）：";
	int MaxVal = 0;
	cin>>MaxVal;
	switch(MaxVal){
	case 1:	MaxVal = 10000;cout<<endl<<"测试进行中..\n分数：A";break;
	case 2: MaxVal = 20000;cout<<endl<<"测试进行中..\n分数：B";break;
	case 3: MaxVal = 30000;cout<<endl<<"测试进行中..\n分数：C";break;
	case 4: MaxVal = 40000;cout<<endl<<"测试进行中..\n分数：D";break;
	case 5: MaxVal = 50000;cout<<endl<<"测试进行中..\n分数：E";break;
	default: cout<<"数据出错，自动退出"<<endl; return 0; break;
	}

	int *pArr0 = new int [MaxVal];

	for(int i = 0; i < MaxVal; i++)
		*(pArr0 + i) = rand()%(MaxVal/10);

	int beginTime = 24*60000*getHour()+60000*getMinute()+1000*getSecond()+getMinSec();

	thread t0(BubSort, pArr0, MaxVal);
	thread t1(BubSort, pArr0, MaxVal);
	thread t2(BubSort, pArr0, MaxVal);
	thread t3(BubSort, pArr0, MaxVal);
	thread t4(BubSort, pArr0, MaxVal);
	thread t5(BubSort, pArr0, MaxVal);
	thread t6(BubSort, pArr0, MaxVal);
	thread t7(BubSort, pArr0, MaxVal);
	thread t8(BubSort, pArr0, MaxVal);
	thread t9(BubSort, pArr0, MaxVal);
	thread t10(BubSort, pArr0, MaxVal);
	thread t11(BubSort, pArr0, MaxVal);
	thread t12(BubSort, pArr0, MaxVal);
	thread t13(BubSort, pArr0, MaxVal);
	thread t14(BubSort, pArr0, MaxVal);
	thread t15(BubSort, pArr0, MaxVal);

	t0.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();

	cout<<24*60000*getHour()+60000*getMinute()+1000*getSecond()+getMinSec()-beginTime<<endl;

	system("pause");
	return 0;
}