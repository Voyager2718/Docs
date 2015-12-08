#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TMP 20

struct message{
	char str[MAX_TMP];
	int a;
};

int main(int argc, char *argv[]){
	pid_t pid;
	int tmp;
	int pipedes[2];
	struct message *origin = (struct message*)malloc(sizeof(struct message));
	struct message *destination = (struct message*)malloc(sizeof(struct message));
	
	strcpy(origin->str, "Hello, World!");
	origin->a = 100;
	
	if(pipe(pipedes)==-1){
		perror("PIPE error");
		exit(EXIT_FAILURE);
	}
	
	if((pid = fork())==-1){
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	
	if(pid == 0){
		printf("Son\n");
		sleep(2);
		close(pipedes[0]);
		if(write(pipedes[1], origin, sizeof(struct message))==-1)
		{
			perror("Write error.");
			exit(EXIT_FAILURE);
		}
		free(origin);
		exit(EXIT_SUCCESS);
	}
	if(pid >0){
		printf("Father\n");
		close(pipedes[1]);
		while(read(pipedes[0], destination, sizeof(struct message))==-1 || destination == NULL){
			perror("Read error.");
			exit(EXIT_FAILURE);
		}
		printf("%s\n", destination->str);
		exit(EXIT_SUCCESS);
		free(destination);
	}
	exit(EXIT_SUCCESS);
}