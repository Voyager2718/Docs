#include "monmalloc_infra.h"
#include "monmalloc_afaire.h"
#define true 1

#include<stdio.h>
#include<stdlib.h>

//void inserer(liste_t *list, liste_t cell) {
//	int a = (int)(cell->userspacestop) - (int)(cell->userspacestop);
//	liste_t tmp0 = NULL, tmp1 = *list;
//	while (true){
//		if (a < (int)(tmp1->userspacestop) - (int)(tmp1->userspacestart)){
//			cell->next = tmp1;
//			if (tmp0 == NULL){
//				tmp0->next = cell;
//				*list = cell;
//			}
//			break;
//		}
//		else
//		{
//			tmp0 = tmp1;
//			tmp1 = tmp1->next;
//		}
//	}
//}

void inserer(liste_t *list, liste_t cell) {
	liste_t *tmp = list;
	int size_of_cell = ((int)cell->userspacestop) - ((int)cell->userspacestart);
	if (size_of_cell < (((int)((*list)->userspacestop)) - ((int)((*list)->userspacestart))))
		cell->next = *list;
	else{
		while ((*tmp)->next){
			if (size_of_cell <= (int)((*tmp)->next->userspacestop) - (int)((*tmp)->next->userspacestart)){
				cell->next = (*tmp)->next;
				(*tmp)->next = cell;
				return;
			}
			*tmp = (*tmp)->next;
		}
		(*tmp)->next = cell;
	}
}

liste_t extraire(liste_t *list, unsigned int size) {
	if (((int)(*list)->userspacestop) - ((int)(*list)->userspacestart) >= size)
		return *list;
	else if ((*list)->next == NULL)
		return NULL;
	*list = (*list)->next;
	return extraire(list, size);
}

