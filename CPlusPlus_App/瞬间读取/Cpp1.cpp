#include <iostream>
#include<conio.h>
using namespace std;
int main(){
	cout<<"ready"<<endl;
	char a;
	for(;;){
		a=getch();
		if (a==13){
			cout<<endl;
			break;
		}
		printf("*");

	}
	return 0;
}