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
	system("title ˮľ�廪�˼ʹ�ϵ����ϵͳ");
m1:
	cout<<"���������룬���س������������˸���������롣"<<endl;
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
	cout<<"�������������룬���س������������˸���������롣"<<endl;
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
		cout<<"����������ȷ"<<endl;
		Sleep(1000);
		cout<<"���ڽ��������˻�"<<endl;
		for(int wait=0;wait<65;wait++){
			Sleep(15);
			cout<<".";
		}
		cout<<endl;
		goto m3;
	}
	cout<<"������������"<<endl<<"���򼴽��˳�"<<endl;
	Sleep(1000);
	return 0;
m3:
	system("cls");
	point(72);
	cout<<"��ӭ������ˮľ�廪���˼ʹ�ϵ����ϵͳ"<<Version<<endl;
	point(72);
	cout<<"��ѡ�����Ĳ���"<<endl;
	system("pause");
	return 0;
}