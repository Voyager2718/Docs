#include<iostream>
using namespace std;
class B;
class A{
public:
	int a,a1;
	A(int a){
		a1=a;
	}
	void Output(B &);
};
class B{
public:
	int b,b1;
	B(int b){
		b1=b;
	}
	friend void A::Output(B &);
};
void A::Output(B &f){
	cout<<a1<<" "<<f.b1<<endl;
}                                    //�˺����岻��д����A���棬��Ϊ���д�����棬Output("B" &f)��B���ñ�������֪���÷��䡣
int main(){
	A a11(10);
	B b11(20);
	a11.Output(b11);
	return 0;
}