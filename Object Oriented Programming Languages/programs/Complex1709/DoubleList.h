// Arquivo: DoubleList.h
// Implementação de listas duplamente encadeadas usando templates.
// Exigências para instanciar uma Lista DoubleList utilizando o template abaixo:
//	- O tipo T deve especificar o construtor vazio: T() (usado no primeiro construtor de DoubleNode)
//	- O tipo T ter implementado o operador ==
// Obs: o ctor DoubleNode(const T& el, DoubleNode *ptr=0, DoubleNode *ptr2=0) utilizará o construtor de cópia de T (implementado ou fornecido pelo compilador) para criação e inicialização de info. Repare a sintaxe deste construtor;
// Uma alternativa é utilizar a versão comentada do construtor onde um operador de cópia é utilizado. Nesse caso, T deve ter implementado um operador de 
// cópia ou será utilizado o operador de cópia rasa fornecido pelo compilador.



#ifndef _DOUBLELIST_H
#define _DOUBLELIST_H

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;


template <typename T>
class DoubleNode
{
	public:
		DoubleNode()
		{
			next = prev = 0;
		}

		DoubleNode(const T& el, DoubleNode *ptr=0, DoubleNode *ptr2=0):
 		info(el)
		{
			this->prev = ptr;
			this->next = ptr2;				
		}
		
		T info;
		DoubleNode* next;
		DoubleNode* prev;
};


template <typename T>
class DoubleList 
{
	public:
		DoubleList()
		{
			head = tail = 0;
			numberOfNodes = 0;
		}

	    ~DoubleList();

		bool isEmpty() const
		{
			return head == 0;	    	
	    }
		bool contains(const T& element) const
		{
			return isInList(element)!=0;
		}
	 	void addHead(const T&);
		void addTail(const T&);
		void deleteHead();   
		void deleteTail();   
		void deleteNode(const T&);
		void print() const;
		int size() const;
                

	private:

		DoubleNode<T>* isInList(const T&) const;

		DoubleNode<T> *head, *tail;
		int numberOfNodes;
};

template <typename T>
DoubleList<T>::~DoubleList()
{
	DoubleNode<T> *p;
	
	while(!isEmpty())
	{
		p = head->next;
		delete head;
		head = p;
	}
}

template <typename T>
void DoubleList<T>::addHead (const T& newElement)
{
	DoubleNode<T> *newNode = new DoubleNode<T>(newElement,0,head);
	if(newNode == 0)
	{
		cout << "\nProblemas na alocação de um nó";
		exit(0);
	}
	if(isEmpty())
		tail = newNode;
	else
		head->prev = newNode;
	head = newNode;
	numberOfNodes++;

}



template <typename T>
void DoubleList<T>::addTail (const T& newElement)
{
	DoubleNode<T> *newNode = new DoubleNode<T>(newElement,tail,0);
	if(newNode == 0)
	{
		cout << "\nProblemas na alocação de um nó";
		exit(0);
	}
	if(isEmpty())
		head = newNode;
	else
		tail->next = newNode;
	tail = newNode;
	numberOfNodes++;

}


template <typename T>
void DoubleList<T>::deleteHead ()
{
	if(isEmpty()) 
		cout << "\nLista vazia.";
	else
	{
		DoubleNode<T> *tmp = head;
		head = head->next;
		if(head) head->prev = 0;
		else tail = 0;
		
		numberOfNodes--;
		delete tmp;
	}
}

template <typename T>
void DoubleList<T>::deleteTail ()
{
	if(isEmpty()) 
		cout << "\nLista vazia.";
	else
	{
		DoubleNode<T> *tmp = tail;
		tail = tail->prev;
		if(tail) tail->next = 0;
		else head = 0;
		
		numberOfNodes--;
		delete tmp;
	}

}

template <typename T>
void DoubleList<T>::deleteNode (const T& element)
{
	DoubleNode<T> *f = isInList(element);
	if(f==0) 
		cout << "Elemento nao se encontra na lista.\n";
	else
	{
		
		/*if(f->prev) f->prev ->next = f->next;
		else head = f->next;
		
		if(f->next) f->next->prev = f->prev;
		else tail = f->prev;*/
		
		if(f==tail) 
			deleteTail();
		
		else if(f==head) 
			deleteHead();
		
		else
		{
			f->prev->next = f->next;
			f->next->prev = f->prev;
			numberOfNodes--;
			delete f;
		}
	}	
}

template <typename T>
DoubleNode<T>* DoubleList<T>::isInList (const T& element) const
{
	DoubleNode<T> *tmp;
	
	for(tmp=head; tmp!=0 && !(tmp->info == element); tmp=tmp->next)
		return tmp;
		
}




template <typename T>
void DoubleList<T>::print() const
{
	DoubleNode<T> *tmp;
	cout << "Quantidade de elementos: " << size();
	cout << "\n";
	
	for(tmp=head; tmp!=0; tmp=tmp->next)
		cout << tmp->info<< " ";
		cout << "\n"; 


}


template <typename T>
inline
int DoubleList<T>::size() const
{
	return numberOfNodes;
}

#endif
