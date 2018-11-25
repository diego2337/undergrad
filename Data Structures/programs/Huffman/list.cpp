#ifndef __LIST_H
#include "list.h"
#endif

Node *List::min()
{
	if(head != 0)
	{
		Node* ptr = head->node;
		NodeList* aux = head;
		head = head->next;
		delete aux;
		numberOfNodes--;
		return ptr;
	}
	return 0;
}

/* Criando uma lista ordenada */

void List::build(int *f, char *car, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		Node* newNode = new Node(f[i], car[i]);
		add(newNode);
	}
}

void List::add(Node* no)
{
	NodeList *newNode = new NodeList(no);
	if(head == 0)
		head = newNode;
	else
	{
		NodeList *ant = 0;
		NodeList *cur = head;
		while(cur != 0 && cur->node->freq < no->freq)
		{
			ant = cur;
			cur = cur->next;
		} 
		if(ant == 0)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			newNode->next = cur;
			ant->next = newNode;
		}
	}
	numberOfNodes++;
}