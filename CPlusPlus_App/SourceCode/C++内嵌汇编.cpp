#include   <iostream>   
using   namespace   std;   
//�˳���Ҳչʾ����Ƕ���Ӧ���ʹ��C++�е�ָ��   
void   main(   )   
{   
	unsigned int a,b;   
	cin>>a;   
	cin>>b;   
	unsigned int *c = &a;   
	__asm					//��������Ƕ���...   
	{   
		mov   eax,   c;		//c�д洢��a�ĵ�ַ->eax     
		mov   eax,   [eax];	//a��ֵ->eax   
		//ע��ֱ��mov   eax,   [c]�Ǵ����   
		mov   ebx,   b;		//����������ֱ�Ӷ�ebx��ֵ   
		lea   eax,   [eax+ebx];   
		mov   a,   eax;		//����ֱ�ӽ�eax��ֵ->a   
	}//��Ƕ��ಿ�ֽ���...   
	cout<<a<<endl;
	system("pause");
}   