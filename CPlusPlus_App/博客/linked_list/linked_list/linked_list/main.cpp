#include<iostream>
#include<string>
#include"slist.h"
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]){
	slist<int> *list = new slist <int>();
	list->push_front(3);
	list->push_front(2);
	list->push_front(1);
	list->push_back(4);
	list->push_back(5);
	list->remove(2);
	for (int i = 0; i < list->size(); i++)
		cout << list->get(i) << endl;
	system("pause");
}