#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define AMOUNT_THREADS 10

void cleanup(){
	printf("cleanup\n");
}

void *test_cancel(void){
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	pthread_cleanup_push(cleanup, NULL);
	printf("test_cancel\n");
	int i = 0;
	while(1){
		printf("test message\n");
		i ++;
		sleep(1);
		if(i > 10)
			pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	}
	pthread_cleanup_pop(1);
}

int main(void){
	pthread_t tid;
	pthread_create(&tid, NULL, (void*)test_cancel, NULL);
	sleep(2);
	pthread_cancel(tid);
	pthread_join(tid, NULL);
}

