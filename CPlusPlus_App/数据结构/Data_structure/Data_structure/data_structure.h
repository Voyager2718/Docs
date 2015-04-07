#include<iostream>
#include<assert.h>
using namespace std;

namespace double_cycle_list{
	struct node{
		int value;
		node *prev, *next;
		node(int value, node *prev = NULL, node *next = NULL) :value(value), prev(prev), next(next){}
	};

	node* CreateList(int value){
		node *List = new node(value);
		List->next = List->prev = List;
		return List;
	}

	void DeleteList(node *List){
		assert(List);
		node *p = List->next, *tmp;
		List->next = p->prev = NULL;
		while (p != List){
			tmp = p->next;
			p->next = tmp->prev = NULL;
			delete p;
			p = tmp;
		}
		delete List;
	}

	node* Find(int value, node *List){
		assert(List);
		node *p = List;
		do{
			if (p->value == value)
				return p;
			else
				p = p->next;
		} while (p != List);
		return NULL;
	}

	//找第n个
	node* Find(int value, int n, node *List){
		assert(List&&n > 0);
		int i = 1;
		node *p = List;
		do{
			if (p->value == value){
				if (i == n)
					return p;
				else{
					i++;
					p = p->next;
				}
			}
			else
				p = p->next;
		} while (p != List);
		return NULL;
	}

	void Delete(int value, node *List){
		assert(List);
		node *p = Find(value, List);
		if (p){
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p->prev = p->next = NULL;
			delete p;
		}
	}

	void Insert(node *List, int value){
		assert(List);
		node *p = new node(value);
		p->prev = List;
		p->next = List->next;
		List->next->prev = p;
		List->next = p;
	}

	void PrintList(node *List){
		assert(List);
		node *p = List;
		do{
			std::cout << p->value << " ";
			p = p->next;
		} while (p != List);
		std::cout << std::endl;
	}

	int ListSize(node *List){
		assert(List);
		int size = 1;
		node *p = List->next;
		while (p != List)
		{
			size++;
			p = p->next;
		}
		return size;
	}

	void SwitchPlace(int a, int b, node *List){/*有空优化一下*/
		node
			*tmpa = Find(a, List),
			*tmpb = Find(b, List);
		if (!tmpa || !tmpb)
			return;

		node
			*tmp1 = tmpa->next,
			*tmp2 = tmpb->next,
			*tmp3 = tmpa->prev,
			*tmp4 = tmpb->prev,
			*tmp5 = tmpa->prev->next,
			*tmp6 = tmpb->prev->next,
			*tmp7 = tmpa->next->prev,
			*tmp8 = tmpb->next->prev;

		tmpa->prev->next = tmp6;
		tmpb->prev->next = tmp5;
		tmpa->next->prev = tmp8;
		tmpb->next->prev = tmp7;
		tmpa->next = tmp2;
		tmpb->next = tmp1;
		tmpa->prev = tmp4;
		tmpb->prev = tmp3;
	}

	//修改第一个找到的值或改变全部值
	void ChangeValue(int toChange, int value, node *List, bool change_all = false){
		assert(List);
		if (toChange == value)
			return;
		while (Find(toChange, List) != NULL){
			Find(toChange, List)->value = value;
			if (!change_all)
				break;
		}
	}

	//修改第n个的值
	void ChangeValue(int toChange, int value, int n, node *List){
		assert(List&&n > 0);
		int i = 1;
		if (toChange == value)
			return;
		node *p = Find(toChange, n, List);
		if (p)
			p->value = value;
	}

	//直接修改
	void ChangeValue(int value, node *List){
		List->value = value;
	}
}