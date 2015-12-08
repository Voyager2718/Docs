#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define AMOUNT_THREADS 10
#define WORK_SIZE 1024

pthread_mutex_t lock;
char work_area[WORK_SIZE];
int time_to_txit = 0;

void *thread_function(void *arg){
	
}

int main(int argc, char *argv[]){
	pthread_t tid;
	void *thread_result;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&tid, NULL, (void*)thread_function, NULL);
	pthread_mutex_lock(&lock);
	while(!time_to_exit){
		fgets(work_area, WORK_SIZE, stdin);
		pthread_mutex_unlock(&lock);
		while(1){
			pthread_mutex_lock(&lock);
			if(work_area[0] != '\0'){
				pthread_mutex_unlock(&lock);
				sleep(1);
			}else break;
		}
	}
	pthread_mutex_unlock(&lock);
	pthread_join(pid, (void**)&thread_result);
}
