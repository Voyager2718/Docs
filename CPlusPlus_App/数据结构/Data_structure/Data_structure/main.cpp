#include"data_structure.h"
using namespace double_cycle_list;

#include<iostream>
#include<assert.h>
using namespace std;

//template <int N>
//struct Factorial
//{
//	enum { value = N * Factorial<N - 1>::value };
//};
//
//template <>
//struct Factorial<0>
//{
//	enum { value = 1 };
//};
//
//// Factorial<4>::value == 24
//// Factorial<0>::value == 1
//void foo()
//{
//	cout<<Factorial<10>::value<<endl; // == 24
//	cout<<Factorial<0>::value<<endl; // == 1
//}
//
//template<int T>
//void print(int(&a)[T])
//{
//	printf("%lu   ", sizeof(a));
//	printf("%lu   ", sizeof(a[0]));
//}
//int main(int argc, const char * argv[]) {
//	// insert code here...
//	int a[8] = { 56, 12, 45, 75, 21, 32, 90, 22 };
//	print(a);
//	printf("%lu  ", sizeof(a));
//	printf("%lu  \n", sizeof(a[0]));
//	foo();
//	system("pause");
//	return 0;
//}

//struct node
//{
//	int value;
//	node *prev;
//	node *next;
//	node(int value, node*prev = NULL, node *next = NULL) :value(value), prev(prev), next(next){}
//};
//
//node* CreateList(int value){
//	node *List = new node(value);
//
//}

int main(int argc, char *argv[]){
	int a[] = { 1, 2, 3, 4, 5, 7, 8, 9, 10 };
	node *n = CreateList(a[0]);
	for (int i = 1; i < sizeof(a) / sizeof(int); i++){
		Insert(n, a[i]);
		n = n->next;
	}
	n = n->next;
	PrintList(n);

	cout << Find(5, n)->value << endl;

	Delete(5, n);
	PrintList(n);

	Insert(Find(4, n), 6);
	Insert(Find(4, n), 5);

	PrintList(n);

	SwitchPlace(2, 10, n);
	PrintList(n);

	cout << ListSize(n) << endl;

	ChangeValue(1, 100, 2, n);
	PrintList(n);

	system("pause");
	return 0;
	exit(0);
}