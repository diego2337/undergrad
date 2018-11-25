#ifndef _INTLIST_H_
#define _INTLIST_H_
#endif





#include <stdio.h>
class IntNode
{
 public:

  //atributos
    int info;
    char name[50];
    char brand[20];
    int unit;
    char storage[10];
    IntNode *next;

  IntNode()
  {
    info = 0;
    unit = 0;
    next = 0;
  }
  IntNode(int el, char* name, char* brand, int unit, char* storage, IntNode *ptr=0)
  {
    info=el;
    name = this->name;
    brand = this->brand;
    unit = this->unit;
    storage = this->storage;
    next=ptr;
  }

};

class IntList
{
  public:
    IntList()
    {
     head=tail=0; 
    }
  void addToHead(int, char*, char*, int, char*);
  void addToTail(int, char*, char*, int, char*);
  int deleteFromHead();
  //int deleteFromtail(int);
  bool isEmpty(){
    return head==0;
  }
  void printList();
  private:
    IntNode *head;
    IntNode *tail;
};
