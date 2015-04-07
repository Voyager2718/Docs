#include   <iostream>   
using   namespace   std;   
//此程序也展示了内嵌汇编应如何使用C++中的指针   
void   main(   )   
{   
	unsigned int a,b;   
	cin>>a;   
	cin>>b;   
	unsigned int *c = &a;   
	__asm					//下面是内嵌汇编...   
	{   
		mov   eax,   c;		//c中存储的a的地址->eax     
		mov   eax,   [eax];	//a的值->eax   
		//注意直接mov   eax,   [c]是错误的   
		mov   ebx,   b;		//可以像这样直接对ebx赋值   
		lea   eax,   [eax+ebx];   
		mov   a,   eax;		//可以直接将eax的值->a   
	}//内嵌汇编部分结束...   
	cout<<a<<endl;
	system("pause");
}   