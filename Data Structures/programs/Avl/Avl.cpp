#ifndef __avl_h
#include "Avl.h"
#endif

AvlTree::~AvlTree()
{
  clear();
}
void AvlTree::preOrdTree(Node* p)
{
  if(p!=0)
  {
    printf("%d", p->value);
    preOrdTree(p->lft);
    preOrdTree(p->rgt);
  }
}
void AvlTree::clear()
  {
     //deleteTree(root);
  }

bool AvlTree::add(int value)
{

    bool h = false; // altura da arvore
    return add(value, root, h);

}
bool AvlTree::add(int value, Node* &p, bool &h)
{
  if(p == 0)
  {
      p = new Node(value);
      numberOfNodes++;
      h = true;
      return true;
  }
  bool ret = false;
  if(value < p->value)
  {
    ret = add(value, p->lft, h);
    if(h)
    {
      switch(p->balance)
      {
        case -1:
          rotationRight(p);
          h = false;
          break;
        case 0:
          p->balance = -1;
          break;
        case 1:
          p->balance = 0;
          h = false;
      }
    }
  }
  if(value > p->value)
  {
    ret = add(value, p->rgt, h);
    if(h)
    {
      switch(p->balance)
      {
        case -1:
          p->balance = 0;
          h = false;
          break;
        case 0:
          p->balance = 1;
          break;
        case 1:
          rotationLeft(p);
          h = false;
      }
    }
  }
  return ret;
}
void AvlTree::rotationRight(Node* &p)
{
  Node *pu = p->lft;
  if(pu->balance == -1)
  {
    p->lft = pu->rgt;
    pu->rgt = p;
    p = pu;
  }
  else
  {
    Node *pv = pu->rgt;
    pu->rgt = pv->lft;
    p->lft = pv->rgt;
    pv->lft = pu;
    pv->rgt = p;
    if(pv->balance == 1)
      pu->balance = -1;
    else
      pu->balance = 0;
    if(pv->balance == -1)
      p->balance = 1;
    else
      p->balance = 0;
    p = pv;
  }
  p->balance = 0;
}
void AvlTree::rotationLeft(Node* &p)
{
  Node *pu = p->rgt;
  if(pu->balance == 1)
  {
    p->rgt = pu->lft;
    pu->lft = p;
    p->balance = 0;
    p = pu;
  }
  else
  {
    Node *pv = pu->lft;
    p->rgt = pv->lft;
    pu->lft = pv->rgt;
    pv->lft = p;
    pv->rgt = pu;
    if(pv->balance == 1)
      p->balance = -1;
    else
      p->balance = 0;
    if(p->balance == -1)
      pu->balance = 1;
    else
      pu->balance = 0;
    p = pv;
  }
  p->balance = 0;
}


