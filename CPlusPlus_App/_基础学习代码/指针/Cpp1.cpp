#include<iostream>
using namespace std;
/*void test(int *p1){  //指针指定函数外变量测试
	*p1+=1;
	int i=29;
	p1=&i;
	cout<<"pointer"<<*p1<<endl;
}*/
void main(){/*
	int a,b,*p1,*p2;
	cin>>a>>b;
	p1=&a;
	p2=&b;
	if(b>a){
		p1=&b; //指针赋值测试
		p2=&a;
	}
	cout<<*p1<<">"<<*p2<<endl;*/
/*	int *pointer,i=3; //指针指定函数外变量测试
	pointer=&i;
	test(pointer);
	cout<<*pointer;  */
/*	int *pointer,i=30;  //指针指向测试
	pointer=&i;
	*pointer+=*pointer;
	cout<<"i="<<i<<"pointer="<<*pointer<<endl; */
/*	void test(int pointer[5]); //指针指向数组测试
	int a[5];
	for (int i=0;i<=4;i++){
		cin>>a[i];
	}
	test (a);
	for (int i2=0;i2<=4;i2++){
	cout<<"main中的数组"<<a[i2]<<endl;
	}*/
}
/*
void test(int *pointer){  //指针指向数组测试
	for (int i=0;i<=4;i++){
		*(pointer+i) =*(pointer+i)+1;
		cout<<"test中的数组"<<pointer[i]<<endl;
	}
}*/