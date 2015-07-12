#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef struct _linkedList{
	int data;
	_linkedList *next;
	_linkedList();
	_linkedList(int data);
} node;

node* createNode(int);

int length(node **);

void printList(node**);

bool isEmpty(node**);

node* getFront(node**);

node* getBack(node**);

void clearList(node**&);

void clearListRec(node**&);

node** pushFront(node*, node**&);

node** pushBack(node*, node**&);

node** popFront(node**&);

node** popBack(node**&);

void printTest();

#endif