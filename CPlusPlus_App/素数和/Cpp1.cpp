//��Ŀ�� ��д����long fun(int high��int n)�������ǣ����㲢����high���ڣ�������high������n������֮�͡�������n��������С����2Ϊֹ
//�����磺��high=100,n=10�������ķ���ֵΪ��732����high=11,n=10���������أ�17��
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
