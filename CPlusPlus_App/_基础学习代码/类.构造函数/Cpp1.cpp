#include <iostream>
using namespace std;
class Test {
public:
	Test(int a,int b,int c){
		d=a;
		e=b;
		f=c;
	}
	Test(){
		d=1;
		e=2;
		f=3;
	}
	void Output(){
		g=d*e*f;
		cout<<g<<endl;
	}
	void Input(){
		d=7;
		e=8;
		f=9;
	}
private:
	int d,e,f,g;
};
int main (){
	Test a,b(4,5,6),c;
	a.Output();
	b.Output();
	c.Input();
	c.Output();
	return 0;
}
