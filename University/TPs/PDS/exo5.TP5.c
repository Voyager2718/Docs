#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>

typedef int (*func_t)(int);

int testFunc(int i){
	return i;
}

void resultF(int resultOfFunction, int *result){
	if( resultOfFunction != 0 ){
		*result = *result & 1;
	}else{
		*result = 0;
	}
}//Change the value of result.

int multif(func_t f[], int args[], int n){
	int i, result = 1, child;
	pid_t pid;
	for( i = 0 ; i < n ; i++ ){
		switch(fork()){
			case -1:
				perror("Error.");
				exit(EXIT_FAILURE);
			case 0: 
				resultF(f[i](args[i]),&result);
				exit(result);
			default:
				wait(&child);
				int result = WEXITSTATUS(child);
				break;
		}
	}
	return result;
}

int main(void){
	func_t f[3] = {testFunc, testFunc, testFunc};

	int a[3] = {2,1,0};

	printf("%d\n",multif(f,a,3));
}
