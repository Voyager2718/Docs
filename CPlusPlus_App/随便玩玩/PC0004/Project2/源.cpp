#include<iostream>
using namespace std;
int main(){
	system("title ���ܼ�����");
	for(;;){
		float mass=0;long velocity=0;
		cout<<"������g����"<<endl;
		cin>>mass;
		cout<<"�ٶȣ�m/s��:"<<endl;
		cin>>velocity;
		cout<<"����:"<<0.5*0.001*mass*velocity*velocity<<endl;
		system("pause");
		system("cls");
	}
	return 0;
}