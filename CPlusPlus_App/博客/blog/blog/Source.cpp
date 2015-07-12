#include"singlyList.h"
#include<iostream>
using std::cout;
using std::endl;

int main(int argc, char**args){
	node **list = NULL;
	pushFront(new node(3), list);
	pushFront(new node(2), list);
	pushBack(new node(4), list);
	pushFront(new node(1), list);
	popFront(list);
	popBack(list);
	printList(list);
	system("pause");
	return 0;
}