#include<iostream>
#include<string>
using namespace std;

int main(int argc, char * argv[]){
	int* p=(int*)malloc(10*sizeof(int));
	delete p;
	system("pause");
}