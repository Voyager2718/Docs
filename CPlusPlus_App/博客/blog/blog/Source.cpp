#include<iostream>
#include"singlyList.cpp"

#include<vector>

//using std::cout;
//using std::endl;

using namespace std;

struct Obj{
	int a;
	Obj(){}
	Obj(int a){
		this->a = a;
	}
};

int main(int argc, char**args){
	Obj a(10), b(20), c(30);
	list<Obj>lst;
	lst.pushBack(b);
	lst.pushFront(a);
	lst.pushBack(c);

	cout << (*lst.head)->next->data.a << endl;

	vector<Obj>vec;
	vec.push_back(a);

	system("pause");
	return 0;
}