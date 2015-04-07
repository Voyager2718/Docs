#include<iostream>
#include<windows.h>
#include<fstream>
using namespace std;
struct data{
	char a[16];
	int b;
};
int main(){
	data a;
	/*
	cin>>a.a;
	cin>>a.b;
	cout<<"1:"<<a.a<<" "<<a.b<<endl;
	ofstream COUT("dat.dat",ios::binary);
	COUT.write((char*)&a,sizeof(a));
	*/
	ifstream CIN("dat.dat",ios::binary);
	CIN.read((char*)&a,sizeof(a));
	cout<<"2:"<<a.a<<" "<<a.b<<endl;
	Sleep(1000);
	return 0;
}