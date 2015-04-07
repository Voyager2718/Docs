#include <iostream>
#include <windows.h>
#include <conio.h>
#define Version "v0.0.0 00002"
using namespace std;
void point(int a){
	for (int i=0;i<a;i++){
		cout<<".";
	}
	cout<<endl;
}
int main(){
	system("title 水木清华人际关系管理系统");
m1:
	cout<<"请输入密码，按回车键结束，按退格键重新输入。"<<endl;
	char a,b[16],c[16];
	for(int i=0;i<16;i++){
		a=getch();
		if (a==8){
			system("cls");
			i=0;
			goto m1;
		}
		b[i]=a;
		if (a==13){
			b[i]=-99;
			break;
		}
		printf("*");

	}
	cout<<endl;
m2:
	cout<<"请重新输入密码，按回车键结束，按退格键重新输入。"<<endl;
	for(i=0;i<16;i++){
		a=getch();
		if (a==8){
			system("cls");
			i=0;
			goto m2;
		}
		c[i]=a;
		if (a==13){
			c[i]=-99;
			break;
		}
		printf("*");
	}
	bool PW;
	for (i=0;i<16&&b[i]!=-99;i++){
		if(b[i]==c[i]){
			PW=true;
			continue;
		}
		PW=false;
	}
	cout<<endl;
	if (PW==true){
		cout<<"密码输入正确"<<endl;
		Sleep(1000);
		cout<<"正在进入您的账户"<<endl;
		for(int wait=0;wait<65;wait++){
			Sleep(15);
			cout<<".";
		}
		cout<<endl;
		goto m3;
	}
	cout<<"密码输入有误"<<endl<<"程序即将退出"<<endl;
	Sleep(1000);
	return 0;
m3:
	system("cls");
	point(72);
	cout<<"欢迎来到“水木清华”人际关系管理系统"<<Version<<endl;
	point(72);
	cout<<"请选择您的操作"<<endl;
	system("pause");
	return 0;
}