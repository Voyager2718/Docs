#include "singlylist.h"
#include<iostream>
using std::cout;
using std::endl;

_linkedlist::_linkedlist() :data(0), next(NULL){
}
_linkedlist::_linkedlist(int data) : data(data), next(NULL){
}

listNode* createlistNode(int data){
	return new listNode(data);
}

int length(_linkedlist ** linkedlistNode){
	if (!linkedlistNode || !*linkedlistNode)
		return 0;
	return length(&((*linkedlistNode)->next)) + 1;
}

void printlistNode(_linkedlist** linkedlistNode){
	if (!linkedlistNode || !*linkedlistNode)
		return;
	cout << (*linkedlistNode)->data << " ";
	printlistNode(&(*linkedlistNode)->next);
}

bool isEmpty(_linkedlist** linkedlistNode){
	if (!linkedlistNode)
		return true;
	return false;
}

listNode* getFront(_linkedlist** linkedlistNode){
	if (!linkedlistNode)
		return NULL;
	return *linkedlistNode;
}

listNode* getBack(_linkedlist** linkedlistNode){
	if (!linkedlistNode)
		return NULL;
	if (!(*linkedlistNode)->next)
		return *linkedlistNode;
	return getBack(&((*linkedlistNode)->next));
}

void clearlistNode(_linkedlist**& linkedlistNode){
	listNode *plistNode = *linkedlistNode;
	while (plistNode){
		listNode *pNext = plistNode->next;
		delete plistNode;
		plistNode = pNext;
		pNext = plistNode->next;
	}
	linkedlistNode = NULL;
}

void clearlistNodeRec(_linkedlist**& linkedlistNode){
	if (!linkedlistNode || !*linkedlistNode)
		return;
	_linkedlist **plistNode = &(*linkedlistNode)->next;
	clearlistNodeRec(plistNode);
	delete *linkedlistNode;
	linkedlistNode = NULL;
}

listNode** pushFront(listNode* newLinkedlistNode, _linkedlist**& existLinkedlistNode){
	if (!existLinkedlistNode)
	{
		existLinkedlistNode = &newLinkedlistNode;
	}
	else{
		newLinkedlistNode->next = *existLinkedlistNode;
		existLinkedlistNode = &newLinkedlistNode;
	}
	return existLinkedlistNode;
}

listNode** pushFront(int data, _linkedlist**& existLinkedlistNode){
	listNode *pNode = new listNode(data);
	if (!existLinkedlistNode)
	{
		existLinkedlistNode = &pNode;
	}
	else{
		pNode->next = *existLinkedlistNode;
		existLinkedlistNode = &pNode;
	}
	return existLinkedlistNode;
}

listNode** pushBack(listNode* newLinkedlistNode, _linkedlist**& existLinkedlistNode){
	if (!existLinkedlistNode)
	{
		existLinkedlistNode = &newLinkedlistNode;
	}
	else{
		getBack(existLinkedlistNode)->next = newLinkedlistNode;
	}
	return existLinkedlistNode;
}

listNode** pushBack(int data, _linkedlist**& existLinkedlistNode){
	listNode *pNode = new listNode(data);
	if (!existLinkedlistNode)
	{
		existLinkedlistNode = &pNode;
	}
	else{
		getBack(existLinkedlistNode)->next = pNode;
	}
	return existLinkedlistNode;
}

listNode** popFront(_linkedlist**& linkedList){
	if (linkedList){
		listNode *pNext = (*linkedList)->next;
		delete *linkedList;
		linkedList = &pNext;
	}
	return linkedList;
}

listNode** popBack(_linkedlist**& linkedlistNode){
	if (linkedlistNode){
		_linkedlist *plistNode = *linkedlistNode,
			*pNext = (*linkedlistNode)->next;
		while (true){
			if (!pNext->next)
			{
				plistNode->next = NULL;
				delete pNext;
				return linkedlistNode;
			}
			plistNode = plistNode->next;
			pNext = pNext->next;
		}
	}
	return linkedlistNode;
}
