#include<iostream>
using namespace std;
/*int Test_(int a){
	a++;
	return a;
}*/
struct test1{
	int a;
	int b;
};
void print(test1 str1){
	cout<<str1.a<<" "<<str1.b<<endl;	
}
int main(){
	/*_____________
	int Test_(int a);
	int a=1;
	a=Test_(a);
	cout<<a<<endl;
	_____________Ò»ºÅ*/
	test1 str;
	str.a=2;
	str.b=3;
	print (str);

	return 0;
}

