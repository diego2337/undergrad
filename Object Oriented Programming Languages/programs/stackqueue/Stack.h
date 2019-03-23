#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include "Node.h"
#include "StackException.h"
using namespace std;

#include <stdlib.h>

template <typename T>
class Stack{
private:
	Node<T>* top;
	int numberOfElements;

public:
	Stack()
	{
		this->top = 0;
		numberOfElements = 0;
	}
	Stack(const T &value, Node<T> *ptr=0)
	{
		top->info = value;
		top->next = ptr;
		numberOfElements++;
	}
	~Stack()
	{
		Node<T> *d;
		while(top != NULL)
		{
			d = top->next;
			delete top;
			top = d;
		}
	}
	void push(const T&);
	const T pop();
	int size();
	int contains(const T &value);
	int isEmpty();
	void print();
};

template <typename T>
void Stack<T>::push(const T& newElement)
{
	Node<T> *newNode = new Node<T>(newElement, 0);
	if(newNode == 0)
	{
		throw StackException(0);
	}
	else if(numberOfElements == 0)
	{
		top = newNode;
		newNode->next = NULL;
		numberOfElements++;
	}
	else
	{
		newNode->next = this->top;
		top = newNode;
		numberOfElements++;
	}
}

template <typename T>
const T Stack<T>::pop()
{
	Node<T> *newNode;
	if(numberOfElements == 0)
	{
		throw StackException(1);
	}
	if(top->next == NULL)
	{
		newNode = top;
		numberOfElements--;
		top = top->next;
		return newNode->info;
	}
	newNode = top;
	top = top->next;
	numberOfElements--;
	return newNode->info;
}

template <typename T>
int Stack<T>::size()
{
	return numberOfElements;
}

template <typename T>
int Stack<T>::contains(const T &value)
{
	Node<T> *aux = top;
	while(aux != NULL)
	{
		if(aux->info == value)
			return 1;
		aux = aux->next;
	}
	return 0;
}

template <typename T>
int Stack<T>::isEmpty()
{
	if(numberOfElements == 0)
		return 1;
	else
		return 0;
}

template <typename T>
std::ostream& operator << (std::ostream& o, Stack<T>& c)
{
	c.print();
	return o;
}

template <typename T>
void Stack<T>::print()
{
	Node<T> *p = top;
	while(p != NULL)
	{
		cout << p->info << "\n";
		p = p->next;
	}
}

#endif