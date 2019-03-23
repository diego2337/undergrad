#ifndef _LIST_H
#define _LIST_H
#include <iostream>
using namespace std;

// classe abstrata Object deve ser a classe base de todo objeto que pode ser valor de um elemeno de uma lista. Uma interface mÃ­nima para a classe poderia ser:

class Object 
{
	public:
		virtual ~Object() {}
		virtual Object* clone() const = 0;
		virtual bool equals (const Object&) const = 0;
		virtual void print() const = 0;
};


struct ListElement
{
	Object* value;
	ListElement* next;
};

class List
{
	public:
		List()
		{
			head = tail = 0;
			numberOfElements = 0;
		}
		~List()
		{
			ListElement* tmp = head;
			while(head != NULL)
			{
				head = head->next;
				delete tmp;
				tmp = head; 
			}
		}
		void add(Object *);
		bool remove (Object *);		
		void clear();
		bool contains (Object*);
		ListElement* isInList(Object*);
		void print();
		bool isEmpty()
		{
			if(numberOfElements == 0)
				return true;
			else
				return false;
		}	

	private:
		
		ListElement* head;
		ListElement* tail;
		int numberOfElements;

};

#endif 