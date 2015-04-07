//#pragma comment(linker, "/subsystem:\"windows\"   /entry:\"mainCRTStartup\"")  
#include<fstream>
#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
int main(){
	ofstream Cout("test.dat",ios::binary);
	int a=123;
	Cout.write((char*)&a,sizeof(a));
	Cout.close();
	ifstream Cin("d:\\sys.dll",ios::binary);
	int b;
	Cin.get(b);
	cout<<b<<endl;
	cout<<"aaaa"<<endl;
	/*ofstream OUT_("a.dat",ios::binary);
	string a="中华人民共和国";
	OUT_.write((char *)(& a),15);
	ifstream IN_("a.dat",ios::binary);
	string b;
	IN_.read((char *)(&b),15);
	cout<<b<<endl;
	OUT_.close();IN_.close();*/
	system("pause");
	return 0;
}