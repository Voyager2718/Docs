#include<iostream>
//#define NULL 0 可有可无 头文件自带
using namespace std;
struct Test {
	int Test_a;
	struct Test *next;
};
int main(){
	Test a,b,*head,*pointer;
	a.Test_a=100;
	b.Test_a=105;
	head =& a;
	a.next =& b;
	b.next =& a;//NULL
	pointer=head;
	do {
		cout<< pointer->Test_a<<endl;
		pointer=pointer->next;
	}while (pointer!=NULL);
	pointer=head;
	cout<<pointer->Test_a<<endl;
	system("pause");
	return (0);
}