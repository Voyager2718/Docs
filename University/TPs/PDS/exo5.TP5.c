#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>

typedef int (*func_t)(int);

int testFunc(int i){
	return i;
}

void changeResult(int resultOfFunction, int *result){
	if( resultOfFunction != 0 ){
		*result = *result & 1;
	}else{
		*result = 0;
	}
}

int multif(func_t f[], int args[], int n){
	int i, result = 1, child;
	pid_t pid;
	
	for( i = 0 ; i < n ; i++ ){
		switch(fork()){
			case -1:
				perror("Error.");
				exit(EXIT_FAILURE);
			case 0: 
				exit(f[i](args[i]));
			default:
				wait(&child);
				changeResult(WEXITSTATUS(child),&result);
		}
	}
	return result;
}

int main(void){
	func_t f[3] = {testFunc, testFunc, testFunc};
	int args[3] = {2,1,3};

	printf("%d\n",multif(f,args,3));
}
