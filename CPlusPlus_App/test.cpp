#include<iostream>

using std::cout;
using std::endl;

class father{
public:
	void p(){
		cout<<"father\n";
	}
};

class sonA:public virtual father{
public:
//	void p(){
//		cout<<"son A\n";
//	}

	void p1(){
		cout<<"son A p1\n";
	}
};

class sonB:public virtual father{
public:
	void p1(){
		cout<<"son B p1\n";
	}
};

class grandson:public sonA, public sonB{
};

int main(void){
	grandson *gs = new grandson();
	gs->p();
	gs->sonB::p1();
}
