#include <iostream>
using namespace std;
class Test {
public:
	int a1;
	Test(int a){
		a1=a;
	}
	void OUT(){
		cout<<a1<<" ";
	}
};

class Test1 :private Test
{	
public:
	Test1(int a,int b):Test (b)   //Test���캯������ֵ�������ȡ�����д...:Test(a)����ôTest�Ĺ��캯��������a����ֵ�����Ǹ���˳�����ģ�
	{
		b1=b;
		a1=b;    //�����Ļ���a1����ֵ�ͻ�����b����ֵ������ΪTest��a1��public��
	}
	void OUT2(){
		OUT();
		cout<<b1<<endl;
	}
private:
	int b1;
};

int main(){
	Test1 a(10,20);
	a.OUT2();
	return 0;
}