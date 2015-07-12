#include "singlyList.h"
#include<iostream>
using std::cout;
using std::endl;

_linkedList::_linkedList(){
	this->next = NULL;
}
_linkedList::_linkedList(int data) :data(data), next(NULL){
}

node* createNode(int data){
	return new node(data);
}

int length(node ** linkedList){
	if (!linkedList || !*linkedList)
		return 0;
	return length(&((*linkedList)->next)) + 1;
}

void printList(node** linkedList){
	if (!linkedList || !*linkedList)
		return;
	cout << (*linkedList)->data << " ";
	printList(&(*linkedList)->next);
}

bool isEmpty(node** linkedList){
	if (!linkedList)
		return true;
	return false;
}

node* getFront(node** linkedList){
	if (!linkedList)
		return NULL;
	return *linkedList;
}

node* getBack(node** linkedList){
	if (!linkedList)
		return NULL;
	if (!(*linkedList)->next)
		return *linkedList;
	return getBack(&((*linkedList)->next));
}

void clearList(node**& linkedList){
	node *pNode = *linkedList;
	while (pNode){
		node *pNext = pNode->next;
		delete pNode;
		pNode = pNext;
		pNext = pNode->next;
	}
	linkedList = NULL;
}

void clearListRec(node**& linkedList){
	if (!linkedList || !*linkedList)
		return;
	node **pNode = &(*linkedList)->next;
	clearListRec(pNode);
	delete *linkedList;
	linkedList = NULL;
}

node** pushFront(node* newLinkedList, node**& existLinkedList){
	if (!existLinkedList)
	{
		existLinkedList = &newLinkedList;
	}
	else{
		newLinkedList->next = *existLinkedList;
		existLinkedList = &newLinkedList;
	}
	return existLinkedList;
}

node** pushBack(node* newLinkedList, node**& existLinkedList){
	if (!existLinkedList)
	{
		existLinkedList = &newLinkedList;
	}
	else{
		getBack(existLinkedList)->next = newLinkedList;
	}
	return existLinkedList;
}

node** popFront(node**& linkedList){
	if (linkedList){
		node *pNext = (*linkedList)->next;
		delete *linkedList;
		linkedList = &pNext;
	}
	return linkedList;
}

node** popBack(node**& linkedList){
	if (linkedList){
		node *pNode = *linkedList,
			*pNext = (*linkedList)->next;
		while (true){
			if (!pNext->next)
			{
				pNode->next = NULL;
				delete pNext;
				return linkedList;
			}
			pNode = pNode->next;
			pNext = pNext->next;
		}
	}
	return linkedList;
}
