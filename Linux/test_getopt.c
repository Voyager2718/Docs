#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	char optString[] = "Ilo:v:h?";
	int opt = getopt(argc, argv, optString);
	int i = 1;
	while(opt != -1){
		i ++;
		switch(opt){
			case 'I':printf("I\n");break;
			case 'o':printf("o--");printf("%s\n", argv[i]);break;
			case 'p':printf("p\n");break;
			case 'l':printf("l\n");break;
			case 'v':printf("v--");printf("%s\n", argv[i]);break;
			case 'h':printf("h\n");break;
			case '?':printf("?\n");break;
			default :printf("none\n");
		}
		opt = getopt(argc, argv, optString);
	}
}