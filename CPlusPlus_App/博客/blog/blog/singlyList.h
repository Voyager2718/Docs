#ifndef singlyList_h
#define singlyList_h

template < class Type >
class node {
public:
	Type data;
	node *next;
	node();
	node(Type);
	~node();
};

template < class Type >
class list{
private:
	//	node<Type> **head;
public:

	node<Type> **head;

	list();
	void pushFront(Type);
	void pushBack(Type);
	Type popFront();
	Type popBack();
	void clear();
	bool isEmpty();
	int length();
	Type front();
	Type back();
};

#endif