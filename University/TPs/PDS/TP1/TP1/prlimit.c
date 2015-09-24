#include<stdio.h>
#include<limits.h>
#include<unistd.h>

int main(int argc, char *args[]){
	printf("NAME_MAX=%d\nPATH_MAX=%d\n",NAME_MAX,PATH_MAX);
	return 0;
}

