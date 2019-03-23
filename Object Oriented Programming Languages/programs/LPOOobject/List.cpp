#include "List.h"

void List::add(Object* newElement)
{
	ListElement* newNode = new ListElement();
	newNode->value = newElement;
	if(isEmpty())
	{
		this->head = newNode;
		numberOfElements++;
	}
	else if(this->numberOfElements == 1)
	{
		this->head->next = newNode;
		this->tail = newNode;
		numberOfElements++;
	}
	else
	{
		this->tail->next = newNode;
		tail = newNode;
		this->tail->next = NULL;
		numberOfElements++;
	}
}
ListElement* List::isInList(Object* search)
{
	ListElement* searchNode;
	//for(searchNode = head; searchNode != NULL && !(searchNode->next->value == search); searchNode = searchNode->next)
	searchNode = head;
	if(search == head->value)
		return searchNode;
	while(searchNode != NULL)
	{
		if(searchNode->next->value == search)
			return searchNode;
		searchNode = searchNode->next;	
	}
}
bool List::contains(Object* ElementToSearch)
{
	return isInList(ElementToSearch) != 0;
}
bool List::remove(Object* ElementToRemove)
{
	/* A variavel r ira receber o elemento que antecede o elemento a ser removido; por isso, 
	tratamos caso o elemento que quisermos remover seja cabeça ou seja o segundo elemento*/
	ListElement* r = isInList(ElementToRemove);
	if(r == 0)
	{
		cout << "This element wasn't found in the list.\n";
		return false;
	}
	else if(r->next->value == ElementToRemove)
	{
		if(r->next->next != NULL)
			r->next = r->next->next;
		else
			r->next = NULL;
		numberOfElements--;
	}
	else if(r == head)
	{
		head = head->next;
		numberOfElements--;
	}
	else
	{
		if(r->next->next != NULL)
			r->next = r->next->next;
		else
			r->next = NULL;
		numberOfElements--;
	}
	return true;
}

void List::print()
{
	ListElement* p2 = head;
	Object* p = p2->value;
	while(p2 != NULL)
	{
		p = p2->value;
		p->print(); 
		cout << " ";
		p2 = p2->next;
	}
	cout << "\n";
}

void List::clear()
{
	ListElement* tmp = head;
			while(head != NULL)
			{
				head = head->next;
				delete tmp;
				tmp = head; 
			}
	numberOfElements = 0;
}