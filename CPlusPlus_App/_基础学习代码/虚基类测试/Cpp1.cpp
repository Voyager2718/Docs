#include<iostream>
using namespace std;
class A{
public:
	int a;
};
class B:public A{//��//�������͢ڶ�����Ϊ����࣬����˵A::a,B::a,C::a��ʵ��ͬһ������
public:
//	int a;
};
class C:public A{//��//�������͢ٶ�����Ϊ����࣬����˵A::a,B::a,C::a��ʵ��ͬһ������
public:
//	int a;
};
class D:public B,public C{ //��ֻ�����ﶨ��BCΪ����࣬�����Ӱ��
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