/*#include "intList.h"
#include "RNTree.h"*/
#include "Treelist.h"

IntNode* IntList::addToHead(int value, char* name, char* brand, int unit, char* storage)
{
  if(head == 0 && tail == 0)
    head=tail= new IntNode(value, name, brand, unit, storage);
  else
    head=new IntNode(value, name, brand, unit, storage, head, head->prev);
    head->next->prev = head;

    return head;
}
void IntList::addToTail(int value, char* name, char* brand, int unit, char* storage)
{
  if(tail == 0)
    head=tail= new IntNode(value, name, brand, unit, storage);
  else{
    tail->next=new IntNode(value, name, brand, unit, storage);
    tail=tail->next;
  }
}

void IntList::deleteFromHead(){
  int value=head->info;
  IntNode *p = head;
  head = head->next;
  delete p;

}

void IntList::deleterandom(IntNode* ptr)
{
  IntNode *remov = ptr;
  /*while(remov->info != value)
  {
    remov = remov->prev;
  }*/
  remov->prev->next = remov->next;
  remov->next->prev = remov->prev;
  delete remov;
}

void IntList::printList()
{
  IntNode *p;
  for(p=head; p!=NULL; p=p->next){
    printf("%d %s %s %d %s", p->info, p->name, p->brand, p->unit, p->storage);
  }

}




