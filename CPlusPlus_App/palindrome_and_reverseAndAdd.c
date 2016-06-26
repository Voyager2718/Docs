#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cell_m{
	unsigned int decimal;
	unsigned int position;
	struct cell_m *next;
	struct cell_m *previous;
};

struct cell_m* newCell(unsigned int value){
	struct cell_m* cell = (struct cell_m*)malloc(sizeof(struct cell_m));
	cell->decimal = value;
	cell->position = 0;
	cell->next = NULL;
	cell->previous = NULL;
	return cell;
}

void push(struct cell_m* toAdd, struct cell_m** list){
	if(*list == NULL){
		*list = toAdd;
		return;
	}

	if((*list)->next == NULL){
		(*list)->next = toAdd;
		toAdd->previous = *list;
		toAdd->position += (*list)->position + 1;
		return;
	}

	push(toAdd, &((*list)->next));
}

void print(struct cell_m* list){
	if(list == NULL){
		return;
	}
	printf("%d\n", list->decimal);
	print(list->next);
}

int getLength(struct cell_m* list){
	if(list->next == NULL){
		return list->position + 1;
	}
	return getLength(list->next);
}

int getDecimal(struct cell_m* list){
	return list->decimal;
}

struct cell_m* getCell(struct cell_m* list, int position){
	if(list->position == position){
		return list;
	}
	if(list->next == NULL){
		return NULL;
	}
	return getCell(list->next, position);
}

int palindrome(struct cell_m* list){
	int length = getLength(list);
	int i = 0;
	printf("length: %d\n", length);
	for(i; i < (int)(length / 2 + 1); i++){
		if(getCell(list, i)->decimal != getCell(list, length - i -1)->decimal){
			return 0;
		}
	}
	return 1;
}

char* inverseString(char* str){
	char* str2 = (char*)malloc(sizeof(char)*16);
	int i = 0;
	for(i; i < strlen(str); i++){
		*(str2 + i) = *(str + (strlen(str) - i - 1)); 
	}
	return str2;
}

int inverseAdd(struct cell_m* list){
	int i = 0;
	char str[16];
	char* str2 = NULL;
	int sum = 0;
	for(i; i < getLength(list); i++){
		sprintf(str, "%d", getCell(list, i)->decimal);
		if(str2){
			free(str2);
		}
		str2 = inverseString(str);
		sum += atoi(str2);
		sum += getCell(list, i)->decimal;
	}
	free(str2);
	return sum;
}

main(){
	struct cell_m* c1 = newCell(23);
	struct cell_m* c2 = newCell(34);
	struct cell_m* c3 = newCell(45);
	struct cell_m* c4 = newCell(56);
	//struct cell_m* c4_2 = newCell(4);  //Decommenter ici pour tester.
	//struct cell_m* faux = newCell(99);  //Decommenter ici pour tester.
	struct cell_m* c5 = newCell(45);
	struct cell_m* c6 = newCell(34);
	struct cell_m* c7 = newCell(23);

	struct cell_m* list = NULL;

	push(c1, &list);
	push(c2, &list);
	push(c3, &list);
	push(c4, &list);
	//push(c4_2, &list);  //Decommenter ici pour tester.
	//push(faux, &list);  //Decommenter ici pour tester.
	push(c5, &list);
	push(c6, &list);
	push(c7, &list);

	print(list);

	printf("--------\n");

	printf("Is palindrome: %d\n", palindrome(list));

	printf("Rnverse and add: %d\n", inverseAdd(list));
}
