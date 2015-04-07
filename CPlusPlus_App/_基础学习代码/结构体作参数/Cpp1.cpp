#include<iostream>
using namespace std;
struct Test{
	int a;
	float b;
	struct Test *next;
};
int main(){
	void Cout(Test,Test);
	Test a,b;//,*head,*p;
	a.a=1;a.b=1.5;b.a=2;b.b=2.5;b.next=NULL;
//	head =& a;
//	a.next =& b;
	system("pause");
	Cout(a,b);
	return 0;
}
void Cout(Test str,Test str2){
	Test *p,*head;
	head =& str;
	str.next=& str2;
	p=head;
	cout<<p->a<<" "<<p->b<<endl;
	p=p->next;
	cout<<p->a<<" "<<p->b<<endl;
}
