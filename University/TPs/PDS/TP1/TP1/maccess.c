#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

int main(int argc, char *args[]){
	int i;
	if(argc <= 1)
		return 0;
	for(i = 1; i < argc - 1; i++){
		if(0 == strcmp(args[i],"-v")){
			printf("Error.\n");
			return 0;
		}
	}
	if(!access(args[argc - 1], R_OK)&&inString(args, argc, "-r"))
		printf("Reading is ok. ");
	if(!access(args[argc - 1], W_OK)&&inString(args, argc, "-w"))
		printf("Writing is ok. ");
	if(!access(args[argc - 1], X_OK)&&inString(args, argc, "-x"))
		printf("Executing is ok. ");
	printf("\n");
}



int inString(char *str[],int size, char *cmd){
	int i = 1;
	for(i; i < size; i++){
		if(0 == strcmp(str[i], cmd))
			return 1;
	}
	return 0;
}


/*
if(argc <= 1)
	return 0;
char cmd[255];
strcpy(cmd,args[1]);
printf("rights of %s:",cmd);
if(!access(cmd, R_OK))
	printf("-r");
if(!access(cmd, W_OK))
	printf("-w");
if(!access(cmd, X_OK))
	printf("-x");
printf("\n");
*/
