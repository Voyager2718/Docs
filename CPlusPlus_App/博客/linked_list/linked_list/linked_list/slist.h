#ifndef LIST_H
#define LIST_H

#include "Exceptions.h"

template<typename T>
class slist  {
private:
	struct _node{
		T element;
		_node *next;
	};
	_node *_pnode;
	int _size;

public:
	slist() :_size(0), _pnode(nullptr) {}

	~slist(){
		if (_pnode == nullptr)
			return;
		if (_pnode->next)
			;//TODO : free the list
	}

	void push_front(T);

	void push_back(T);

	T pop_front(void);

	T pop_back(void);

	T get(int);

	int size(void);

	T remove(int);


};

template <typename T>
void slist<T>::push_front(T element){
	_node *node = new _node();
	node->element = element;
	if (_size == 0)
		node->next = nullptr;
	else
		node->next = _pnode;
	_pnode = node;
	_size++;
}

template <typename T>
void slist<T>::push_back(T element){
	_node *node = new _node();
	node->element = element;
	if (_size == 0)
		_pnode = node;
	else{
		_node *tmp_node = _pnode;
		while (tmp_node->next != nullptr)
			tmp_node = tmp_node->next;
		tmp_node->next = node;
	}
	_size++;
}

template <typename T>
T slist<T>::get(int index){
	if (index >= _size)
		throw new IndexOutOfRangeException();
	_node *tmp_node = _pnode;
	for (int i = 0; i < index; i++){
		tmp_node = tmp_node->next;
	}
	return tmp_node->element;
}

template<typename T>
T slist<T>::pop_front(void){
	if (_size == 0)
		throw new IndexOutOfRangeException();
	T t = _pnode->element;
	_node *tmp_node = _pnode;
	_pnode = _pnode->next;
	delete (tmp_node);
	_size--;
	return t;
}

template<typename T>
T slist<T>::pop_back(void){
	if (_size == 0)
		throw new IndexOutOfRangeException();
	T e;
	if (_size == 1){
		e = _pnode->element;
		delete(_pnode);
		_pnode = nullptr;
		_size--;
		return e;
	}
	_node *tmp_node = _pnode;
	while (tmp_node->next->next != nullptr)
		tmp_node = tmp_node->next;
	e = tmp_node->next->element;
	delete(tmp_node->next);
	tmp_node->next = nullptr;
	_size--;
	return e;
}

template <typename T>
int slist<T>::size(){
	return _size;
}

template <typename T>
T slist<T>::remove(int index){
	if (index >= _size)
		throw new IndexOutOfRangeException();
	_node *tmp_node0 = _pnode, *tmp_node1 = nullptr;
	for (int i = 0; i < index - 1; i++){
		tmp_node0 = tmp_node0->next;
	}
	tmp_node1 = tmp_node0->next;
	tmp_node0->next = tmp_node0->next->next;
	T e = tmp_node1->element;
	delete(tmp_node1);
	_size--;
	return e;
}
#endif