#include<iostream>
using namespace std;
struct Test {
	int a;
	float b;
	struct Test *next;
};
int main(){
	void Cout(Test *);
	Test a,b,*head,*p;
	a.a=1;
	a.b=2.5;
	b.a=3;
	b.b=4.5;
	head =& a;
	a.next=&b;
	p=head;
	Cout(head);
	return 0;
}
void Cout(Test *p){
	cout<<p->a<<" "<<p->b<<endl<<"pause1"<<endl;
	p=p->next;
	cout<<p->a<<" "<<p->b<<endl;
	system("pause");
}