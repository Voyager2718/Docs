#include <iostream>
#include <string>
using namespace std;
struct Test {
	string a;
	char b;
	int c;
	float d;
};
void main(){
	Test test[2];
	Test *pointer =& test[0];
	cin>>test[0].a>>test[1].b>>test[0].c>>test[1].d;
	cout<<test[0].a<<test[1].b<<test[0].c<<test[1].d<<'\n'<<endl;
	cout<<pointer->a<<pointer->c<<endl;
	int *pointer2 =& test[0].c;
	cout<<*pointer2<<endl;
}