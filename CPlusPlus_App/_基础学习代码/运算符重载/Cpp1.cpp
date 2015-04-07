#include<iostream>
using namespace std;
class Test{
public:
	int a1,b1;
	Test (int a,int b){
		a1=a;b1=b;
	}
private:
	int a,b;
};
int operator +(Test &c,Test &d){
	int e;
	return (c.a1+c.b1+d.a1+d.b1);
}
int main(){
	Test f(10,20),g(30,40);
	int h;
	h=f+g;
	cout<<h<<endl;
	return 0;
}
