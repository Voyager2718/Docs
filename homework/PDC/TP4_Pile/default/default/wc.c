#pragma warning(disable:4996)

#include<stdlib.h>
#include<stdio.h>

int getLines(){
	char  ch;
	int i = 1;
	if (ch = getchar() == EOF)
		return 0;
	while ((ch = getchar()) != EOF){
		if (ch == '\n')
			i++;
	}
	return i;
}

int getBytes(){
	char ch;
	int i = 0;
	while ((ch = getchar()) != EOF)
		i++;
	return i;
}

int getWords(){
	char  ch;
	int i = 0;
	ch = getchar();
	if (ch == EOF)
		return 0;
	i++;
	while ((ch = getchar()) != EOF){
		if (ch == ' ' || ch == '\n')
			i++;
	}
	return i;
}

//int main(int argc, char **argv){
//	if (argc >= 2){
//		if (argv[1][0] == '-'){
//			switch (argv[1][1])
//			{
//			case 'c':printf("%d\n", getBytes()); break;
//			case 'l':printf("%d\n", getLines()); break;
//			case 'w':printf("%d\n", getWords()); break;
//			default:break;
//			}
//		}
//	}
//	system("pause");
//	return 0;
//	exit(0);
//}