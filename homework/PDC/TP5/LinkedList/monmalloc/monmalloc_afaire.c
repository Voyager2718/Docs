#include "monmalloc_infra.h"
#include "monmalloc_afaire.h"
#define true 1

#include<stdio.h>
#include<stdlib.h>

void inserer(liste_t *list, liste_t cell) {
	int a = (int)(cell->userspacestop) - (int)(cell->userspacestop);
	liste_t tmp0 = NULL, tmp1 = *list;
	while (true){
		if (a < (int)(tmp1->userspacestop) - (int)(tmp1->userspacestart)){
			cell->next = tmp1;
			if (tmp0 == NULL){
				tmp0->next = cell;
				*list = cell;
			}
			break;
		}
		else
		{
			tmp0 = tmp1;
			tmp1 = tmp1->next;
		}
	}
}

liste_t extraire(liste_t *list, unsigned int size) {
	/* votre code ici */
	return NULL;
}

