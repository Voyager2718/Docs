#include <iostream>
#include <string>
using namespace std;
template <typename T>
T A(T a){
	a++;
	return a;
}
void main (){
	int a=8;
	float b=8.1;
	//string c="8.2";
	cout<<A(a)<<'\n';
	cout<<A(b)<<endl;
	//cout<<A(c)<<endl;
	//类型不符
}//template必须被使用。否则不能被定义。