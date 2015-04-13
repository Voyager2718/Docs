#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef float freq_t[1 << 8];

void frequence(freq_t f, FILE *fp){
	for (int i = 0; i < 1 << 8; i++)
		f[i] = 0;
	char r;
	while ((r = fgetc(fp)) != EOF){
		f[(int)r] += 1;
	}
	for (int i = 0; i < 1 << 8; i++)
		printf("%f ", f[i]);
}

int main(int argc, char *args[]){
	/*if (argc <= 1){
		printf("Faut passer un parametre qui contient un fichier.");
		system("pause");
		return 1;
		}
		FILE *fp = fopen(args[1], "r");
		if (!fp)
		return 2;
		char buf[20];
		if (!buf)
		return 3;
		while (fp != NULL){
		fread(buf, sizeof(char), strlen(buf), fp);
		printf("%s", buf);
		}
		fclose(fp);*/

	FILE *fp = fopen(args[1], "r");

	freq_t f;

	frequence(f, fp);
	system("pause");
}