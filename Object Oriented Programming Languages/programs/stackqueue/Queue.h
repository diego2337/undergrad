#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Node.h"
#include "QueueException.h"

template <typename T>
class Queue{
private:
	int numberOfElements;
	Node<T>* begin;
	Node<T>* end;

public:
	Queue()
	{
		numberOfElements = 0;
		begin = end = 0;
	}
	~Queue()
	{
		Node<T> *d = begin;
		while(d != NULL)
		{
			d = begin->next;
			delete begin;
			begin = d;
		}
	}
	void enqueue(const T&);
	const T dequeue();
	int size();
	int contains(const T&);
	int isEmpty();
	void print();

};

template <typename T>
void Queue<T>::enqueue(const T &element)
{
	Node<T> *b = new Node<T>(element, 0);
	if(b == 0)
	{
		throw QueueException(0);
	}
	/* There are no elements on the queue */
	if(numberOfElements == 0)
	{
		begin = b;
		begin->next = NULL;
		end = b;
		end->next = NULL;
		numberOfElements++;
	}
	/* There is one element on the queue */
	else if(begin == end)
	{
		begin->next = b;
		end = b;
		end->next = NULL;
		numberOfElements++;
	}
	else
	{
		end->next = b;
		end = b;
		numberOfElements++;
	}
}

template <typename T>
const T Queue<T>::dequeue()
{
	Node<T> *aux = begin;
	if(numberOfElements == 0)
	{
		throw QueueException(1);
	}
	if(begin->next == NULL)
	{
		numberOfElements--;
		return aux->info;
	}
	begin = begin->next;
	numberOfElements--;
	return aux->info;
}

template <typename T>
int Queue<T>::size()
{
	return numberOfElements;
}

template <typename T>
int Queue<T>::contains(const T &value)
{
	Node<T> *aux = begin;
	while(aux != NULL)
	{
		if(aux->info == value)
			return 1;
		aux = aux->next;
	}
	return 0;
}

template <typename T>
int Queue<T>::isEmpty()
{
	if(numberOfElements == 0)
		return 1;
	else
		return 0;
}

template <typename T>
std::ostream& operator << (std::ostream& o, Queue<T>& c)
{
	c.print();
	return o;
}

template <typename T>
void Queue<T>::print()
{
	Node<T> *p = begin;
	while(p != NULL)
	{
		cout << p->info << "\n";
		p = p->next;
	}
}
#endif