#include<stdio.h>
#include<stdlib.h>
#include"mcu_affiche_entier.h"
#define ERROR_FAILURE 100
int main(int argc, char *argv[]){
	int quantity = 0, input;
	input = getchar();
	if(input != EOF)
		quantity++;
	while(input != EOF){
		input = getchar();
		quantity++;
	}
	affiche_entier(quantity);
	putchar('\n');	
	return 0;
}
