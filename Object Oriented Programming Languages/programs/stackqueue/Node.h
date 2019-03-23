#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;


template <typename T>
class Node
{
	public:
		Node()
		{
			next = 0;
		}

		Node(const T& el, Node *ptr=0):
 		info(el)
		{
			this->next = ptr;				
		}
		
		T info;
		Node<T>* next;
};

#endif