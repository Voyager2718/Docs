#include <iostream>
#include <string>
using namespace std;
class Test{
public:
	void ABC(int x);
	void Evaluate();
	void ReEvaluate(){
		c=a++;
		d=++b;
	}
	int testk;
	void ReOutput(){
		cout<<c<<d<<endl;
	}

	void Output(){
		cout<<a<<" "<<b<<endl;
	}
private:
	int a,c;
	float b,d;
};
void Test::ABC(int x){
	cout<<x;
}
void Test::Evaluate(){
		a=1;
		b=1.2;
}
void main (){
	Test a,*p;
	Test &z=a;
	p=&a;
	int *p2,f;
	p2=&f;
	*p2=3;
	cout<<"p"<<p2<<" *p"<<*p2<<endl;
	cin>>p->testk;
	cout<<p->testk<<endl;
	z.Evaluate();
	a.Output();
	a.ReEvaluate();
	a.ReOutput();
	p->Output();
	int ab;
	scanf("%d",&ab);
	printf("%d\n",ab);
	system("pause");
}