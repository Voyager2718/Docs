#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   char optstring[]="rwx"; 
   int c;
   
   
char *path=argv[optind];
   while( (c=getopt(argc,argv,optstring))!=EOF)
  {
	switch (c)
	{	
		case 'r':
			if (access(path,R_OK))
				return 1;
		case 'w':
			if (access(path,W_OK))
				return 1;
		case 'x':
			if (access(path,X_OK))
				return 1;
		default:
			printf("-%c\n",c);
			
	}
   }
	
return 0;
   
   
   
  
}
