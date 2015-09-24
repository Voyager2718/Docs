#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<assert.h>
#include<dirent.h>
#include<string.h>

#define SIZE 100

int opt_apparent_size = 0;
int opt_follow_links  = 0;

static int valid_name(const char *path){
	return strcmp(path,".") && strcmp(path,"..");
}

static int du_file(const char *path){
	struct stat st;
	int status = lstat(path,&st);
	if(status){
		perror("lstat");
		exit(0);
	}
	assert(status == 0);
	if(S_ISREG(st.st_mode)||S_ISLNK(st.st_mode))
		return opt_apparent_size?st.st_size:st.st_blocks;
	if(S_ISDIR(st.st_mode)){
		int size = 0;
		struct dirent *cdir;
		char tmp[PATH_MAX+1];
		DIR  *ldir;
		ldir = opendir(path);
		assert(ldir != NULL);
		while(cdir = readdir(ldir)){
			if(!valid_name(cdir->d_name))
				continue;
			snprintf(tmp, PATH_MAX+1,"%s/%s",path,cdir->d_name);
			size += du_file(tmp);
		}
		size += opt_apparent_size?st.st_size:st.st_blocks;
		status = closedir(ldir);
		return size;
	}
	fprintf(stderr,"Type du fichier %s xxx\n", path);
	return 0;
}

int hash(char *str){
	int res = 0;
	while(*str)
		res += (*str + 1) % SIZE;
	return res;
}

int main(int argc, char *argv[]){
	printf("%d 	%s\n",du_file(argv[1]),argv[1]);
	return 0;
}
