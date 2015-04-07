#include<iostream>
using namespace std;
void cuowu(){
	try {
		int a;
		throw a;
	}
	catch(int){
		cout<<"Success"<<endl;
	}
}
int main(){
	cuowu();
	return 0;
}