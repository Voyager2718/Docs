#include <iostream>
using namespace std;
class Test {
public:
	int a1;
	Test(int a){
		a1=a;
	}
	void OUT(){
		cout<<a1<<" ";
	}
};

class Test1 :private Test
{	
public:
	Test1(int a,int b):Test (b)   //Test构造函数的数值从这里获取。如果写...:Test(a)，那么Test的构造函数将会获得a的数值（不是根据顺序来的）
	{
		b1=b;
		a1=b;    //这样的话，a1的数值就会变成是b的数值。（因为Test的a1是public）
	}
	void OUT2(){
		OUT();
		cout<<b1<<endl;
	}
private:
	int b1;
};

int main(){
	Test1 a(10,20);
	a.OUT2();
	return 0;
}