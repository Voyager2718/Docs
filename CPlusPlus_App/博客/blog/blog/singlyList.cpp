#include "singlylist.h"
#include<iostream>
using std::cout;
using std::endl;

template<class Type>
node<Type>::node(){
	this->data = NULL;
	this->next = NULL;
}

template<class Type>
node<Type>::node(Type data){
	this->data = data;
	this->next = NULL;
}

template<class Type>
list<Type>::list(){
	this->head = NULL;
}

template<class Type>
void list<Type>::pushBack(Type data){
	if (this->head == NULL){
		this->head = new node<Type>*;
		*this->head = new node<Type>(data);
		return;
	}
	node<Type> *pNode = *this->head,
		*pNextNode = (*this->head)->next;
	while (1){
		if (!pNextNode){
			pNode->next = new node<Type>(data);
			return;
		}
		pNode = pNextNode;
		pNextNode = pNextNode->next;
	}
}

template<class Type>
void list<Type>::pushFront(Type data){
	if (this->head == NULL){
		this->head = new node<Type>*;
		*this->head = new node<Type>(data);
		return;
	}
	node<Type> *pNode = *this->head;
	*this->head = new node<Type>(data);
	(*this->head)->next = pNode;
	return;
}