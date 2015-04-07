#include<iostream>
using namespace std;
int main(){
	system("title 动能计算器");
	for(;;){
		float mass=0;long velocity=0;
		cout<<"重量（g）："<<endl;
		cin>>mass;
		cout<<"速度（m/s）:"<<endl;
		cin>>velocity;
		cout<<"动能:"<<0.5*0.001*mass*velocity*velocity<<endl;
		system("pause");
		system("cls");
	}
	return 0;
}