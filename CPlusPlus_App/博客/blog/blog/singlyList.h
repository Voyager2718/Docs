#ifndef SINGLYlistNode_H
#define SINGLYlistNode_H

template < class Type >
class node {
public:
	Type data;
	node *next;
	node();
	node(Type);
};

template < class Type >
class list{
private:

public:
	node<Type> **head;
	list();
	void pushBack(Type);
	void pushFront(Type);
};

#endif