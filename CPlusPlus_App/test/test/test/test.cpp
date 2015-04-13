#include <iostream>
#include <bitset>
#include <typeinfo>
#include <cstdio>
//
using namespace std;
//template<typename T, typename P, T P:: *s>
//struct H
//{
//
//};
//
//struct AA
//{
//	int i, j;
//	double d;
//	char c;
//};
//
//template<int a>struct Z
//{
//	Z(){
//		cout << a << endl;
//	}
//};
//
//int main()
//{
//	typedef  int const AA::*PI;
//	const PI pi = &AA::i;
//	cout << typeid(pi).name() << endl;
//	cout << typeid(&AA::i).name() << endl;
//
//	H<int, AA, &AA::i> h1; /// ok
//	//H<int, AA, pi> h2; /// compile error
//
//	Z<10> z;
//	system("pause");
//	return 0;
//}


int main(void){
	int a = 10, b = 20, *pa = &a;
	system("pause");
	int *pb = &b;
	cout << (int)pa - (int)pb << endl;
	system("pause");
	return 0;
}