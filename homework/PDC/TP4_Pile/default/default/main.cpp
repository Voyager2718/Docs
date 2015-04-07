#pragma warning(disable:4996)
#include"pile.h"
#include"jeu_lettre_saute.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[]){
	MatriceAdjacence_t *mat = (MatriceAdjacence_t *)malloc(sizeof(MatriceAdjacence_t));

	qsort(dico, TAILLE_DICO, sizeof(dico[0]), Compare);

	CreeMatriceAdjacence(*mat);

	char str0[10], str1[10];
	scanf("%s", str0);
	scanf("%s", str1);
	if (strlen(str0) > 4 || -1 == ConvertionMotIndice(str0, dico) || strlen(str1) > 4 || -1 == ConvertionMotIndice(str1, dico))
		exit(10);

	int int_str0 = ConvertionMotIndice(str0, dico), int_str1 = ConvertionMotIndice(str1, dico);

	system("pause");
	return 0;
}