#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc, char *argv[]){
	int fd;
	extern int errno;
	if((fd = open("/dev/dsp",O_CREAT | O_TRUNC | O_RDWR,0666)) < 0){
		printf("errno = %d\n", errno);
		printf("%d\n",EACCES == errno);
	}
	close(fd);
	return 0;
}