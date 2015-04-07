#include<stdio.h>
#include<stdlib.h>

typedef struct pile
{
	int donnee; /* La donn¨¦e que notre pile stockera. */
	struct pile *precedent; /* Pointeur vers l'¨¦l¨¦ment pr¨¦c¨¦dent de la pile. */
} Pile_t;

void empiler(Pile_t **p_pile, int donnee)
{
	Pile_t *p_nouveau = (Pile_t*)malloc(sizeof *p_nouveau);
	if (p_nouveau != NULL)
	{
		p_nouveau->donnee = donnee;
		p_nouveau->precedent = *p_pile;
		*p_pile = p_nouveau;
	}
}

int depiler(Pile_t **p_pile)
{
	int ret = -1;
	if (p_pile != NULL)
	{
		Pile_t *temporaire = (*p_pile)->precedent;
		ret = (*p_pile)->donnee;
		free(*p_pile), *p_pile = NULL;
		*p_pile = temporaire;
	}
	return ret;
}

