#include<iostream>
#include<string>
#include<time.h>
using namespace std;

/*

class A{
public:
int a;
A(){
a=1;b=2;c=3;
}
A(int,int,int);
virtual void display(){ //虚函数测试1
cout<<a<<" "<<b<<" "<<c<<endl;
}
~A(){
cout<<"A deleted"<<endl;
}
A(A&a){
this->a=a.a;
this->b=a.b;
this->c=a.c;
cout<<"Copy Constructor called."<<endl;
}
void VirtualFunTest(){ //虚函数测试2
cout<<"Class A"<<endl;
}
protected:
int b;
private:
int c;
};

class B: public A{
public:
int d;
B(){
d=4;e=5;f=6;
}
void display(int){
cout<<d<<" "<<e<<" "<<f<<endl;
}
~B(){
cout<<"B deleted"<<endl;
}
void VirtualFunTest(){ //虚函数测试
cout<<"Class B"<<endl;
}
protected:
int e;
private:
int f;
};

class C: protected B{
public:
int g;
C(){
g=7;h=8;i=9;
}
~C(){
cout<<"C deleted"<<endl;
}
protected:
int h;
private:
int i;
};

class D: private C{
public:
int j;
D(){
j=10;k=11;l=12;
}
protected:
int k;
private:
int l;
};

class E: public D{
public:
int j;
E(){
j=13;k=14;l=15;
}
~E(){
cout<<j<<D::j<<endl;
}
protected:
int k;
private:
int l;
};

class C2:public A{
public:
int g;
C2(){
g=7;h=8;i=9;
}
protected:
int h;
private:
int i;
};

class C3: public A{
public:
int g;
C3(int x,int y,int z):A(x,y,z){}
protected:
int h;
private:
int i;
};

class C4: public A{
public:
int g;
int a;
C4():g(7),h(8),i(9){
}
protected:
int h;
private:
int i;
};

A::A(int x,int y,int z){
a=x;b=y;c=z;
}

class T{
public:
T(){
a=0;b=0;
}
T(int a,int b){
this->a=a;
this->b=b;
}
operator int(){
return a;
}
T(int i){
a=i;b=0;
}
T operator + (T t){
t.a=this->a+t.a;
t.b=this->b+t.b;
return t;
}

private:
int a,b;
};

class Test1A{
public:
virtual void display()=0;
int a,b;
Test1A():a(1),b(2){}
void display2(){
cout<<a<<" "<<b<<endl;
}
};

class Test1B:public Test1A{
public:
void display(){
cout<<a<<endl;
}
};

class Test1C:public Test1A{
public:
void display(){
cout<<b<<endl;
}
};

A ReturnA(){
cout<<"step 1"<<endl;
A a;
cout<<"step 2"<<endl;
return a;//这里调用Copy Constructor复制A并return
}

class StaticTest{
public:
static int a;
int b;
StaticTest():b(30){}
static void printa();
static void printab(StaticTest);
};

int StaticTest::a=0;//Warning:静态成员变量必须在类/函数外被声明


void StaticTest::printa(){
cout<<a<<endl;
}

void StaticTest::printab(StaticTest a){
cout<<"a="<<StaticTest::a<<" b="<<a.b<<endl;
}

int FuncPtrTest(int a=10){
cout<<"Success. "<<a<<endl;
return a;
}

void FuncPtrTest2(int(*)(int)){
cout<<"Success2."<<endl;
}

int FuncPtrTest3(void(*p)(int(*)(int))){
cout<<"Success3."<<endl;
return NULL;
}

typedef int(*FuncPtr1)(int);

FuncPtr1 FuncPtrTest4(int(*p)(int)){
return p;
}

auto FuncPrtTest5(int(*p)(int))->int(*)(int)
{
return p;
}//auto方法返回一个函数指针

auto FuncAutoTest(int a=20,int b=30)->int{
return a*b;
}

*/

class A{
public:
	int a;
	A(){
		this->a = 1;
	}
	virtual void show_a(){
		cout << this->a << endl;
	}
};

class B : virtual public A{
public:
	int b;
	B(){
		this->b = 3;
	}
	void show_a(){
		cout << this->a << endl;
	}
};

class C : virtual public A{
public:
	int c;
	C(){
		this->c = 5;
	}
	void show_a(){
		cout << this->a << endl;
	}
};

class D :public B, public C{
public:
	void show_a(){
		cout << a << endl;
	}
};

int main(void){

	/*
	/*
	A a;B b;C c;C2 c2;C3 c3(101,102,103);C4 c4;D d;E e;
	E *pe=new E;
	delete pe;
	////////////////////////////////////////
	T t1(2,3),t2(3,4);
	t1=t1+T(3);
	cout<<int(t1)<<endl;
	////////////////////////////////////////
	cout<<b.a<<" "<<c2.a<<endl;
	////////////////////////////////////////
	cout<<c2.a<<" "<<c3.a<<endl;
	////////////////////////////////////////
	cout<<c4.a<<" "<<c4.A::a<<endl;
	////////////////////////////////////////
	A *pt=&a;
	pt->display();
	pt=&b;
	pt->display();
	////////////////////////////////////////
	A*ptB=new B;
	delete ptB;
	////////////////////////////////////////
	Test1A*ptTest1a=new Test1B;
	Test1C test1c;
	ptTest1a->display();
	ptTest1a=&test1c;
	ptTest1a->display();
	test1c.display2();
	////////////////////////////////////////
	*/
	/*
	int a[5]={1,2,3,4,5},*pa=a;
	cout<<*(pa+3)<<endl;
	char b='a',c='b';
	b^=c;
	c^=b;
	b^=c;
	cout<<b<<" "<<c<<endl;
	*/
	/*int a=10,b(a);
	cout<<b<<endl;*/
	/*
	cout<<ReturnA().a<<endl;//由于ReturnA()没有被赋值储存，所以执行完以后就释放A的对象，cout出A Deleted.
	*/
	/*auto a=10;
	cout<<a<<endl;*/
	/*StaticTest ST1,ST2;
	ST1.a=10;ST2.a=20;
	StaticTest::printa();
	StaticTest::printab(ST2);*/
	/*
	//函数指针测试
	int ConstPointerTest0=10,ConstPointerTest1=20;

	//①
	int *const pCPT0=&ConstPointerTest0;
	//pCPT0=&ConstPointerTest1; 错误 pCPT0不可修改
	*pCPT0=30;//正确 *pCPT0可以修改


	//②
	const int *pCPT1=&ConstPointerTest0;
	//*pCPT1=30; 错误 *pCPT1不可修改
	pCPT1=&ConstPointerTest1;//正确 pCPT1可以修改


	//③
	int const *pCPT2=&ConstPointerTest0;
	//*pCPT2=30; 错误 *pCPT2不可修改
	pCPT2=&ConstPointerTest1;//正确 pCPT2可以修改

	//①=③
	*/
	/*
	FuncPtr1 p;
	p=FuncPtrTest;
	void (*p2)(int(*p)(int))=FuncPtrTest2;
	p2(p);
	FuncPtr1(*p3)(FuncPtr1)=FuncPtrTest4;
	(p3(p))(10);
	*/
	/*
	cout<<FuncAutoTest(10,20)<<endl;
	*/
	/*
	int a[10]={1,2,3,4,5,6,7,8,9,0},*pa[10];
	for(int i=0;i<10;i++)
	pa[i]=&a[i];
	cout<<*pa[4]<<endl;
	*/

	/*
	//	B b;

	//性能测试
	*/
	/*
	scanf("%d");

	int result = 0;
	for (int i = 0; i < 100000000; i++){
	result++;
	}
	cout << result << endl;
	*/

	///* 虚基类测试 */
	//D d;

	//d.B::a=10;

	//d.show_a();
	//
	//cout<<d.a<<endl;


	long int a = 1000;
	printf("%ld", a);
	cout << sizeof(long int) << endl;
	system("pause");
}