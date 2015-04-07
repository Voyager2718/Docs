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
}                                    //此函数体不能写在类A里面，因为如果写在里面，Output("B" &f)的B会让编译器不知道该分配。
int main(){
	A a11(10);
	B b11(20);
	a11.Output(b11);
	return 0;
}