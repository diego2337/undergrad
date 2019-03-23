#ifndef __Queue_h
#define __Queue_h
#include "QueueException.h"
#include "NodeQueue.h"
#include <iostream>
using namespace std;
#include <stdlib.h>


template <typename T>
class Queue
{
  
  public:
     void enqueue(const T&);
     T desqueue();
     void print();
     int size();
     bool isEmpty();
    Queue()
    {
	begin = end = 0;
	numbOfElements = 0;
    }
      //destrutor
      ~Queue();
    
    
    
  private:
   NodeQueue<T>* begin;
   NodeQueue<T>* end;
   int numbOfElements;
   

  
  
};

template <typename T>
void Queue<T>::enqueue(const T& valor)
{
  if(isEmpty())
  {
   ;//exceção 
  }
  else
  {
    NodeQueue<T> *novo = new  NodeQueue<T>(valor, begin);
    novo->prox = end;
    end = novo;
    
    
  }
  numbOfElements++;
  
}

template <typename T>
T Queue<T>::desqueue()
{
  
  

  if (isEmpty()) throw QueueException(1);
 else
 {
    if(this->begin == this->end) //caso em que o elemento é o último a ser removido da fila
    {
      ;//exceção 
      
    }else //caso de remoção comum
    {
	NodeQueue<T> *tmp;
	tmp = end;
	end = end->prox;
	delete(tmp);
	numbOfElements--;
      
    }
 }
  
}

template <typename T>
void Queue<T>::print()
{
 NodeQueue<T> *tmp;

  if (isEmpty()) throw QueueException(1);
 else
 {
   tmp = end;
   while(tmp->prox != 0)
   {
      cout<<tmp->valor<<" ";
     
   }
   cout<<"\n";
   
 }
}

template <typename T>
bool Queue<T>::isEmpty()
{
 if(numbOfElements == 0)
  return 1;
 
 return 0;
  
}

#endif