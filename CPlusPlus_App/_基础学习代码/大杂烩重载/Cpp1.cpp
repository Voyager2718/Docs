#include <iostream>
using namespace std;
class Test {
public:
	Test (int r,int i){
		real=r;imag=i;
	}
	operator double (){
		return real;
	}
	Test operator +(Test &c1){
		Test c(0,0);
		c.real=c1.real+real;
		c.imag=c1.imag+imag;
		return c;
	}
	void OUT(){
		cout<<real<<"+"<<imag<<"i"<<endl;
	}
private:
	int real,imag;
	int r,i;
};
int main(){
	Test a(10,20),b(30,40),c(0,0);
	a+b;
	c.OUT();
	cout<<a+b<<endl;
	return 0;
}