#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_THREAD 10
#define MAX_LENGTH 100

struct _gene{
	char str[MAX_LENGTH];
	int size;
};

void *calc(struct _gene *gene){
	int i, *ptimes = (int *)malloc(sizeof(int));
	
	for (i = 0; i < gene->size; i++){
		if(gene->str[i] == 'G' || gene->str[i] == 'C')
			(*ptimes)++;
	}

	pthread_exit(ptimes);
}

void substr(char* string, char *substring, int fromPosition, int length){
	int i, j;
	for(i = fromPosition, j = 0; j < length; i++, j++){
		*(substring + j) = *(string + i); 
	}
	*(substring + i) = '\0';
}

int main(int argc, char *argv[]){
	char gene[] = "ATCGATGGCTATAGCTAGCTAAGCCGATAACGTACGTACGATCGATCGGGCTAGCTAGCTAGCTAGCTGACTGATCGATCGATGCTAGCTAGCTACGTAGCTACGATCGATGCTGGCTAGCTAGCTGT";
	
	pthread_t thread_id[MAX_THREAD];
	
	struct _gene genes[MAX_THREAD];
	int *returnedValue[MAX_LENGTH];
	
	int amountOfThreads = 2; //TODO : amountOfThreads > 1 ?
	
	int i, pos = 0, sum = 0;
	
	for(i = 0; i < amountOfThreads; i ++){
		char tmp[MAX_LENGTH];
		i != amountOfThreads - 1?substr(gene, tmp, pos, (int)(strlen(gene)/amountOfThreads)):substr(gene, tmp, pos, MAX_LENGTH);
		pos += (int)(strlen(gene)/amountOfThreads);
		strcpy(genes[i].str, tmp);
		genes[i].size = strlen(genes[i].str);
		printf("%s\n", genes[i].str);
		printf("%d\n", genes[i].size);
	}
	
	for(i = 0; i < amountOfThreads; i ++){
		if(pthread_create(&thread_id[i], NULL, (void*)*calc, &genes[i]))
			printf("An exception occured while creating a thread.\n");
	}
	
	for(i = 0; i < amountOfThreads; i ++){
		if(pthread_join(thread_id[i], (void**)&(returnedValue[i]))){
			printf("An exception occured while waiting a thread.\n");
			exit(EXIT_FAILURE);
		}
	}
	
	for(i = 0; i < amountOfThreads; i ++)
		sum += *(returnedValue[i]);
	printf("%d\n", sum);
}
