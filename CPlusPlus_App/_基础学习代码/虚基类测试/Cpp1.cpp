#include<iostream>
using namespace std;
class A{
public:
	int a;
};
class B:public A{//①//如果这里和②都定义为虚基类，就是说A::a,B::a,C::a其实是同一个数据
public:
//	int a;
};
class C:public A{//②//如果这里和①都定义为虚基类，就是说A::a,B::a,C::a其实是同一个数据
public:
//	int a;
};
class D:public B,public C{ //若只在这里定义BC为虚基类，结果无影响
public:
	int a;
};
void main(){
	D a;
	a.B::a=10;
	a.C::a=20;
	a.a=30;
	cout<<a.a<<a.B::a<<a.C::a<<endl;
}