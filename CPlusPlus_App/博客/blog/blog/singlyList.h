#ifndef SINGLYlistNode_H
#define SINGLYlistNode_H

typedef struct _linkedlist{
	int data;
	_linkedlist *next;
	_linkedlist();
	_linkedlist(int data);
} listNode;

listNode* createlistNode(int);

int length(listNode **);

void printlistNode(listNode**);

bool isEmpty(listNode**);

listNode* getFront(listNode**);

listNode* getBack(listNode**);

void clearlistNode(listNode**&);

void clearlistNodeRec(listNode**&);

listNode** pushFront(listNode*, listNode**&);

listNode** pushBack(listNode*, listNode**&);

listNode** popFront(listNode**&);

listNode** popBack(listNode**&);

void printTest();

#endif