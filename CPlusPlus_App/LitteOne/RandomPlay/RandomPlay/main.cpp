#define ArrLen 1000
#define Loop 500000

#include<iostream>
#include<time.h>

using namespace std;

bool AllTrue(bool PlayList[], int ArrLength){
	for(int i = 0; i < ArrLength; i++){
		if (PlayList[i]==false)
			return false;
	}
	return true;
}

int Play(){
	int times = 0LL;
	bool PlayList[ArrLen]={false};

	while (!AllTrue(PlayList,ArrLen))
	{
		PlayList[(rand()%ArrLen)]=true;
		times++;
	}
	return times;
}

int main(void){
	cout<<"初始化成功"<<endl;
	srand((int)time(NULL));
	unsigned long long TotalTimes = 0LL;
	for(int i = 0 ; i < Loop ; i++){
		unsigned long long times = (unsigned long long) Play();
		//cout<<"总随机次数："<<times<<endl;
		TotalTimes += times;		
	}
	cout<<endl<<"平均交换次数："<<TotalTimes/Loop<<endl;
	system("pause");
	return 0;
}