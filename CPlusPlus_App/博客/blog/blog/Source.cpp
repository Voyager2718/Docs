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
	{
		stack = &newStackNode;
	}
	else{
		newStackNode->next = *stack;
		stack = &newStackNode;
	}
	return stack;
}

stackNode* pop(_stack**& stack){
	if (stack){
		stackNode *pNext = (*stack)->next, *pNode = *stack;
		delete *stack;
		stack = &pNext;
		return pNode;
	}
	return NULL;
}//bug

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

int main(int argc, char**args){
	_stack** stack = NULL;
	for (int i = 5; i > 0; i--){
		push(new stackNode(i), stack);
	}
	cout << pop(stack)->data << endl;
	cout << endl;
	system("pause");
	return 0;
}