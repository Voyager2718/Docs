#include <stdio.h>

#include<Windows.h>

#include "ArbreBinaire.h"
#pragma warning(once:4996)

#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif


//11和15还没做

/* Manipulation d'arbres binaires */

Noeud_t arbre1(void) {
	Noeud_t root = CreerNoeud(12);
	root->filsgauche = CreerNoeud(9);
	root->filsdroit = CreerNoeud(8);
	return root;
}

Noeud_t arbre2(void) {
	Noeud_t root = CreerNoeud(12);
	root->filsgauche = CreerNoeud(9);
	root->filsgauche->filsdroit = CreerNoeud(5);
	root->filsgauche->filsdroit->filsgauche = CreerNoeud(7);
	return root;
}

Noeud_t arbre3(void) {
	Noeud_t root = CreerNoeud(12);
	root->filsgauche = CreerNoeud(9);
	root->filsgauche->filsgauche = CreerNoeud(1);
	root->filsgauche->filsdroit = CreerNoeud(5);
	root->filsdroit = CreerNoeud(8);
	root->filsdroit->filsdroit = CreerNoeud(4);
	root->filsdroit->filsdroit->filsgauche = CreerNoeud(7);
	root->filsdroit->filsdroit->filsdroit = CreerNoeud(6);
	return root;
}

void imprimer(Noeud_t a) {
	if (!EstVide(a)){
		imprimer(a->filsgauche);
		printf("%ld ", a->val);
		imprimer(a->filsdroit);
	}
}

int taille(Noeud_t a) {
	if (!EstVide(a))
		return 1 + taille(a->filsgauche) + taille(a->filsdroit);
	else
		return 0;
}

int hauteur(Noeud_t a) {
	if (EstVide(a))
		return -1;
	int g, d;
	g = hauteur(a->filsgauche) + 1;
	d = hauteur(a->filsdroit) + 1;
	if (g > d)
		return g;
	else
		return d;
}

int nbFeuilles(Noeud_t a) {
	if (!EstVide(a))
		if (EstFeuille(a))
			return 1;
		else
			return nbFeuilles(a->filsgauche) + nbFeuilles(a->filsdroit);
	else
		return 0;
}

/* Comptage d'arbres */

int nbArbres2(int n) {
	if (n == 0)
		return 1;
	int *tab = (int*)malloc(sizeof(int)*(n));
	for (int i = 1; i <= n; i++)
		*(tab + i) = 0;
	*tab = 1;
	int i, j;
	for (int k = 1; k <= n; k++)
		for (i = 0, j = k - 1; i < k; i++, j--)
			*(tab + k) += *(tab + i) **(tab + j);
	return *(tab + n);
}//iter

int nbArbres(int n){
	if (n == 0)
		return 1;
	int sum = 0;
	for (int k = 0; k < n; k++){
		sum += nbArbres(k)*nbArbres(n - k - 1);
	}
	return sum;
}//rec

/* Manipulation d'arbres binaires de recherche */

Noeud_t abr1(void) {
	Noeud_t root = CreerNoeud(6);
	root->filsgauche = CreerNoeud(4);
	root->filsgauche->filsgauche = CreerNoeud(2);
	root->filsgauche->filsgauche->filsgauche = CreerNoeud(1);
	root->filsgauche->filsdroit = CreerNoeud(5);
	root->filsdroit = CreerNoeud(7);
	return root;
}

Noeud_t ajouter(value_t v, Noeud_t a) {
	Noeud_t tmp = CreerNoeud(v);
	if (a == NULL)
		return tmp;
	if (v > a->val){
		if (a->filsdroit != NULL)
			ajouter(v, a->filsdroit);
		else{
			a->filsdroit = tmp;
			return a;
		}
	}
	if (v < a->val){
		if (a->filsgauche != NULL)
			ajouter(v, a->filsgauche);
		else{
			a->filsgauche = tmp;
			return a;
		}
	}
	else
		return NULL;//==?
}

Noeud_t abr2(void) {
	Noeud_t root = CreerNoeud(5);
	ajouter(4, root);
	ajouter(2, root);
	ajouter(7, root);
	ajouter(6, root);
	ajouter(1, root);
	return root;
}

Noeud_t abr3(void) {
	Noeud_t root = CreerNoeud(7);
	ajouter(1, root);
	ajouter(4, root);
	ajouter(5, root);
	ajouter(6, root);
	ajouter(2, root);
	return root;
}

/* Si v n'est pas dans l'arbre binaire a, il retoune 0, sinon il retoune un nombre non 0. */
int appartient(value_t v, Noeud_t a) {
	if (!a)
		return 0;
	if (v == a->val)
		return 1 + appartient(v, a->filsgauche) + appartient(v, a->filsdroit);
	return appartient(v, a->filsgauche) + appartient(v, a->filsdroit);
}//？

int valeur_minimale(Noeud_t abr) {
	if (abr->filsgauche)
		return valeur_minimale(abr->filsgauche);
	return abr->val;
}

int valeur_maximale(Noeud_t abr) {
	if (abr->filsdroit)
		return valeur_maximale(abr->filsdroit);
	return abr->val;
}

/* Entier mysterieux */

Noeud_t construitArbreEntierMysterieux2(value_t i, value_t j) {
	if (i >= j)
		return NULL;
	Noeud_t n = CreerNoeud((i + j) / 2);
	n->filsgauche = construitArbreEntierMysterieux2(i, (i + j) / 2);
	n->filsdroit = construitArbreEntierMysterieux2((i + j) / 2 + 1, j);
	return n;//为什么会不包含j
}

Noeud_t construitArbreEntierMysterieux(value_t i, value_t j) {
	return construitArbreEntierMysterieux2(i, j + 1);
}

void jouer(int n) {
	int c;
l0:
	printf("Entrer le nombre que vous voulez choisir:\n");
	scanf("%d", &c);
	if (c > n || c < 0)
	{
		printf("Exception. Faut entre un nombre entre 0 et %d.\n", n);
		goto l0;
	}
	Noeud_t tmp = construitArbreEntierMysterieux(0, n);
	int f = 0;
	while (1){
		if (tmp->val == c){
			printf("Votre nombre est: %d! Gagné! Il a fait %d fois de deviner.\n", tmp->val, ++f);
			return;
		}
		if (tmp->val < c){
			printf("Je devine %d, mais c'est trop petit. Il a fait %d fois de deviner.\n", tmp->val, ++f);
			tmp = tmp->filsdroit;
		}
		if (tmp->val > c){
			printf("Je devine %d, mais c'est trop grand. Il a fait %d fois de deviner.\n", tmp->val, ++f);
			tmp = tmp->filsgauche;
		}
	}
}
/* Tests sur les arbres binaires */

void testArbreBinaire(Noeud_t a) {
	imprimer(a); printf("\n");
	printf("Taille     = %d\n", (taille(a)));
	printf("Hauteur    = %d\n", (hauteur(a)));
	printf("nbFeuilles = %d\n", (nbFeuilles(a)));
}

/* Tests sur les arbres binaires de recherche */
void testABR(Noeud_t a) {
	int i;
	imprimer(a); printf("\n");
	printf("Taille     = %d\n", (taille(a)));
	printf("Hauteur    = %d\n", (hauteur(a)));
	printf("nbFeuilles = %d\n", (nbFeuilles(a)));
	printf("Valeurs présentes dans l'arbre : ");
	for (i = 1; i <= 10; i++) {
		if (appartient(i, a)) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

/* Programme principal */
int main(int argc, char **argv) {

	///*int i;

	//testArbreBinaire(arbre1());
	//testArbreBinaire(arbre2());
	//testArbreBinaire(arbre3());

	//for (i = 0; i <= 19; i++) {
	//printf("Le nombre d'arbres à %d noeuds est %d\n", i, (nbArbres(i)));
	//}

	//testABR(abr1());
	//testABR(abr2());
	//testABR(abr3());

	//printf("Arbre mysterieux entre 12 et 24:\n");
	//imprimer(construitArbreEntierMysterieux(12, 24));
	//printf("\n");

	//jouer(100);*/

	//Noeud_t n = abr2();

	//imprimer(n);

	//ajouter(100, n);

	//printf("\n");

	//imprimer(n);

	//printf("\n");

	//for (int i = 0; i < 20; i++)
	//	printf("%d= %d\n", i, nbArbres2(i));

	/*printf("Valeur min: %d\n", valeur_maximale(n));*/

	//imprimer(construitArbreEntierMysterieux(0, 10));

	//Noeud_t tmp = construitArbreEntierMysterieux(0, 10)->filsdroit;
	//while (tmp){
	//	printf("%d ", tmp->val);
	//	tmp = tmp->filsgauche;
	//}

	jouer(100);

	system("pause");
	return 0;

}