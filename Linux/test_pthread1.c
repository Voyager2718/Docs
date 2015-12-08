#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define AMOUNT_THREADS 10

struct args{
	int a;
	char b;
};

void  printHello(struct args *arg){
	printf("Hello, %c\n", arg->b);
	int *pa = (int*)malloc(sizeof(int));
	*pa = (arg->a + 10);
	free(arg);
	pthread_exit(pa);
}

int main(int argc, char *argv[]){
	int amount_of_threads = AMOUNT_THREADS;
	pthread_t thread_id[AMOUNT_THREADS];

	char a = 'a';
	int i;
	for (i = 0; i < amount_of_threads; i++){
		struct args *tmp = (struct args*)malloc(sizeof(struct args));
		tmp->a = i;
		tmp->b = a + i;
		pthread_create(&thread_id[i], NULL, (void*)printHello, tmp);
	}

	for (i = 0; i < amount_of_threads; i++){
		int *pa = (int*)malloc(sizeof(int));
		pthread_join(thread_id[i], (void**)&pa);
		printf("%i\n", *pa);
		free(pa);
	}
}
