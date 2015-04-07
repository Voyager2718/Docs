//题目： 编写函数long fun(int high，int n)，功能是：计算并返回high以内（不包含high）最大的n个素数之和。若不足n个，则到最小素数2为止
//。例如：若high=100,n=10，则函数的返回值为：732；若high=11,n=10，则函数返回：17。
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
long fun(int high,int n)
{
    int i,j,sum= 0,x=0,m;
	for(i=high-1; i >=2&&x <n; i--)  
	{
		m=(int)sqrt((double)i);
		for(j = 2; j<= m; j++)  
			if(i % j == 0)
				break;
		if(j>m) {sum = sum + i;printf("%d\n",sum);x++;} 
	}
	return sum;
}
void main()
{   int k,n;
    scanf("%d %d", &k,&n);
	printf("sum=%ld\n", fun(k,n));  
	system("pause");             
}
