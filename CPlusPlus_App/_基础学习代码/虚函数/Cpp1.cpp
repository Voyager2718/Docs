#include <iostream>
#include <windows.h>
using namespace std;
class A{
public:
	int b;
	virtual	void a(){  //���û�ж���Ϊ�麯������b�޷����c����ֵ
		cout<<b<<endl;
	}
};
class B:public A{
public:
	int c;
	void a(){
		cout<<b<<endl;
		cout<<c<<endl;
	}
};
int main(){
	B b;
	A *p=&b;
	b.b=10;b.c=20;
	p->a();
	return 0;
}