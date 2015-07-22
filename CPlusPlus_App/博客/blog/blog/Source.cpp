#include<iostream>
using std::cout;
using std::endl;

typedef struct _stack{
	_stack *next;
	int data;
	_stack() :data(0), next(NULL){}
	_stack(int data) :data(data), next(NULL){}
}stackNode;

stackNode* createStackNode(int data){
	return new stackNode(data);
}

int length(_stack** stack){
	if (!stack || !*stack)
		return 0;
	return length(&((*stack)->next)) + 1;
}

_stack** push(int data, _stack**& stack){
	stackNode *pNode = new stackNode(data);
	if (!stack)
	{
		stack = &pNode;
	}
	else{
		pNode->next = *stack;
		stack = &pNode;
	}
	return stack;
}

_stack** push(stackNode* newStackNode, _stack**& stack){
	if (!stack)
		stack = &newStackNode;
	else{
		newStackNode->next = *stack;
		stack = &newStackNode;
	}
	return stack;
}

int pop(_stack** stack){
	/*if (stack){
		int data = (*stack)->data;
		stackNode *pNext = (*stack)->next;
		delete *stack;
		if (pNext)
		stack = &pNext;
		else
		stack = NULL;
		return data;
		}
		return NULL;*/

	cout << stack << " " << *stack << endl;

	return 0;
}

stackNode* get(_stack** stack){
	if (stack)
		return *stack;
	return NULL;
}

bool isEmpty(_stack**& stack){
	if (!stack)
		return true;
	return false;
}


struct t{
	int a;
	t(int i){
		a = i;
		next = NULL;
	}
	t *next;
};

void test(int a, t** ppT){
	t *p = new t(a);
	cout << p << " " << ppT << " " << *ppT << endl;
	p->next = *ppT;
	*ppT = p;
	cout << p << " " << ppT << " " << *ppT << endl;
}

int main(int argc, char**args){
	_stack **stack = NULL;

	t *p = new t(10), **ppT = &p;
	test(5, ppT);

	delete p;

	cout << ppT << " " << *ppT << (*ppT)->a << endl;

	system("pause");
	return 0;
}