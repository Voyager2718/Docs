#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int testFunc(){
	return 100;
}

int main(void){
	int child;
	pid_t pid;
	switch(fork()){
		case -1:
			perror("Error");
			exit(EXIT_FAILURE);
		case 0:
			printf("Son=%d\n",getpid());
			exit(testFunc());
		default:
			printf("Father=%d\n",getpid());
			wait(&child);
			printf("tmp=%d\n",WEXITSTATUS(child));
			break;
	}
}
