#include"dico.h"
#include"pile.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int MatriceAdjacence_t[TAILLE_DICO][TAILLE_DICO];

static bool Valid(const char *a, const char *b){
	if (strlen(a) != strlen(b))
		return false;
	if (!strcmp(a, b))
		return false;
	unsigned int i = 0, j = 0;
	while (i < strlen(a))
	{
		if (a[i] != b[i])
			if (j >= 1 || (i == strlen(a) - 1 && j < 1))
				return false;
			else
				j++;
		i++;
	}
	return true;
}

static int Compare(const void *a, const void *b){
	return strcmp(*(char**)a, *(char**)b);
}

static void CreeMatriceAdjacence(MatriceAdjacence_t mat){
	/*qsort(dico, TAILLE_DICO, sizeof(dico[0]), Compare);*/
	/*Je ne sais pas sil faut mettre qsort*/
	for (int i = 0; i < TAILLE_DICO; i++)
		for (int j = 0; j < TAILLE_DICO; j++)
			mat[i][j] = Valid(dico[i], dico[j]);
}

static int ConvertionMotIndice(char *mot, char *dico_trie[TAILLE_DICO]){
	int low = 0, high = TAILLE_DICO - 1, mid;
	while (low <= high){
		mid = (low + high) / 2;
		if (strcmp(mot, *(dico_trie + mid)) < 0)
			high = mid - 1;
		else if (strcmp(mot, *(dico_trie + mid)) > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

//Comprend pas faut faire quoi
static int Chemin(int sommetcourant, int sommetdestination, MatriceAdjacence_t mat, Pile_t *parcours, int dejaparcouru[TAILLE_DICO]){
	if (sommetcourant == sommetdestination)
		return 0;
	return 0;
}