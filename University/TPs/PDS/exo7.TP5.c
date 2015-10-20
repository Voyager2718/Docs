#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>

void print100m(int ord){
	int i;
	for( i = 0 ; i < 100000000 ; i++ ){}
	printf("First 100 millions(i=%d)\n",ord);
	for( i = 0 ; i < 100000000 ; i++ ){}
}

void create10proc(){
	int i, j, p, pid_count = 0;
	int *children = malloc(10*sizeof(int)), child;
	pid_t pid;
	for( i = 0 ; i < 10 ; i++){
		child = fork();
		switch(child){
			case -1:
				perror("Error.");
				exit(EXIT_FAILURE);
			case 0:
				print100m(i);
				printf("Process = %d, pid = %d\n",i,getpid());
				exit(EXIT_SUCCESS);
			default:break;
		}
	}
}

int main(void){
	create10proc();
	return 0;
}
