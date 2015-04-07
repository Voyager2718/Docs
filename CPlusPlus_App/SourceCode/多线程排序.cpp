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

void BubSort(int *pArr0, int *pArr1, int MaxVal){
	int beginTime = 60000*getMinute()+1000*getSecond()+getMinSec();

	BubbleSort(pArr0,MaxVal);

	cout<<"BubbleSort:"<<60000*getMinute()+1000*getSecond()+getMinSec()-beginTime<<endl;

	ArrCpy(pArr0, pArr1, MaxVal);
}

void InsSort(int *pArr0, int *pArr1, int MaxVal){
	int beginTime = 60000*getMinute()+1000*getSecond()+getMinSec();

	InsertionSort(pArr0,MaxVal);

	cout<<"InsertionSort:"<<60000*getMinute()+1000*getSecond()+getMinSec()-beginTime<<endl;

	ArrCpy(pArr0, pArr1, MaxVal);
}

void SelSort(int *pArr0, int *pArr1, int MaxVal){
	int beginTime = 60000*getMinute()+1000*getSecond()+getMinSec();

	SelectionSort(pArr0,MaxVal);

	cout<<"SelectionSort:"<<60000*getMinute()+1000*getSecond()+getMinSec()-beginTime<<endl;

	ArrCpy(pArr0, pArr1, MaxVal);
}

void SheSort(int *pArr0, int *pArr1, int MaxVal){
	int beginTime = 60000*getMinute()+1000*getSecond()+getMinSec();

	ShellSort(pArr0,MaxVal);

	cout<<"ShellSort:"<<60000*getMinute()+1000*getSecond()+getMinSec()-beginTime<<endl;

	ArrCpy(pArr0, pArr1, MaxVal);
}

void QuiSort(int *pArr0, int *pArr1, int MaxVal){
	int beginTime = 60000*getMinute()+1000*getSecond()+getMinSec();

	QuickSort(pArr0,0,MaxVal-1);

	cout<<"QuickSort:"<<60000*getMinute()+1000*getSecond()+getMinSec()-beginTime<<endl;

	ArrCpy(pArr0, pArr1, MaxVal);
}

int main(int argc, char* argv){
	/*
	int MaxVal = 0;
	cout<<"输入数组大小:";
	cin>>MaxVal;
	*/

	srand((unsigned int)time(NULL));

	int MaxVal = 100000;
	while(MaxVal <= 1000000){

		int * pArr0 = new int [MaxVal], * pArr1 = new int [MaxVal];
		for(int i = 0 ; i < MaxVal ; i++)
			*(pArr0+i) = rand()%(2*MaxVal)+1;
		ArrCpy(pArr1, pArr0, MaxVal);

		cout<<MaxVal<<"个随机数"<<endl;

		InsSort(pArr0, pArr1, MaxVal);

		//thread t0(InsSort, pArr0, pArr1, MaxVal);//在这里插入多线程
		thread t1(BubSort, pArr0, pArr1, MaxVal);
		thread t2(QuiSort, pArr0, pArr1, MaxVal);
		thread t3(SheSort, pArr0, pArr1, MaxVal);
		thread t4(SelSort, pArr0, pArr1, MaxVal);

		//t0.join();
		t1.join();
		t2.join();
		t3.join();
		t4.join();

		MaxVal *= 10;
		cout<<"\n";
	}

	system("pause");
	return 0;
}