#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	printf("entering main process---\n");
    execlp("ls", "ls","-l",NULL);
}