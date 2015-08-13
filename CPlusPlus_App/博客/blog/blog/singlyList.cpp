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
	this->data = new Type;
	this->data = data;
	this->next = NULL;
}

template<class Type>
node<Type>::~node(){
	delete this->next;
	this->next = NULL;
}

template<class Type>
list<Type>::list(){
	this->head = NULL;
}

template<class Type>
void list<Type>::pushFront(Type data){
	if (!this->head){
		this->head = new node<Type>*;
		*this->head = new node<Type>(data);
		return;
	}
	node<Type> *pNode = *this->head;
	*this->head = new node<Type>(data);
	(*this->head)->next = pNode;
	return;
}

template<class Type>
void list<Type>::pushBack(Type data){
	if (!this->head){
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
Type list<Type>::popFront(){
	if (!this->head)
		return;
	node<Type> *pNode = *this->head;
	this->head = &(*this->head)->next;
	delete pNode;
}

template<class Type>
Type list<Type>::popBack(){

}

template<class Type>
void list<Type>::clear(){

}

template<class Type>
bool list<Type>::isEmpty(){
	if (!this->head)
		return true;
	return false;
}

template<class Type>
int list<Type>::length(){
	if (!this->head)
		return 0;
	int length = 0;
	node<Type> *pNode = *this->head;
	while (1)
	{
		if (!pNode->next)
			return ++length;
		pNode = pNode->next;
		length++;
	}
}

template<class Type>
Type list<Type>::front(){
	return *this->head;
}

template<class Type>
Type list<Type>::back(){

}