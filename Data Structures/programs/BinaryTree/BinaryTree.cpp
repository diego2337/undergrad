#include "BinaryTree.h"
bool BinaryTree::add(int value)
{

    Node* parent = 0;
    Node* cur = findNode(value,parent);

    if(cur == 0)
    {	
        addNode(value,parent);
        return true;
    }
    return false;

}

void BinaryTree::addNode(int value, Node* parent) 
{

    if(parent != 0) 
    {
	Node* node = new Node(value, parent);
	if(parent->value > value)
              parent->lft = node;
        else
              parent->rgt = node;
    }
    else
    	      root = new Node(value,0);
    
    numberOfNodes++;
}


Node* BinaryTree::findNode(int value, Node*& parent) 
{
    Node* cur = root;

    parent = 0;

    while (cur != 0) {
        if (cur->value == value)
            return cur;

        parent = cur;
        cur = cur->value > value? cur->lft : cur->rgt;
    }

    return cur;
}

Node* BinaryTree::suc(int value)
{
  Node *pai;
  Node *p = findNode(value, pai);
  if(p != NULL)
  {
    if(p->lft == NULL && p->rgt == NULL)
    {
      pai = p->parent;
      if(pai->lft == p)
      {
       return pai;
      }
      else if(pai->rgt == p)
      {
        while(pai->lft != p)
        {
           p = pai;
           pai = pai->parent;
        }
        return pai;
      }   
    }
    else if(p->lft != NULL || p->rgt != NULL)
    {
        p = p->rgt;
        if(p->lft == NULL)
        {
          return p;
        }
        else
        {
          while(p->lft != NULL)
          {
            p = p->lft;
          }
          return p;
        }
    }
    else 
      printf("Nao ha sucessor para esse numero");
  }
   return p;
}

/*void BinaryTree::printtree(Node *p, int level, int level2)
{
  if(p != 0)
  {
    if(level == level2)
    {
      printf("%d", p->value);
    }
    else
    {
      printtree(p->lft, level, level2+1);
      printtree(p->rgt, level, level2+1);
    }
  }
}*/
void BinaryTree::preOrdTree(Node* p)
{
	if(p!=0)
	{
		visitNode(p);
		preOrdTree(p->lft);
		preOrdTree(p->rgt);
	}
}

void BinaryTree::visitNode(Node* p)
{
  if(p->parent != 0)  
	printf("\n%d - pai: %d", p->value, p->parent->value);
  else printf("\n%d ", p->value);
}


bool BinaryTree::remove(int value)
{
    Node *p;
    Node *no = findNode(value,p);
    
    if(no!=0){
      removeNode(no);
      return true;
    }
    return false;
      
  
  
}

void BinaryTree::removeNode(Node *no){
    Node *aux; 
    //se o nó tem 2 filhos
     if(no->lft !=0 && no->rgt!=0){
       aux=no->rgt;
       while(aux->lft!=0)
	 aux=aux->lft;
	 
	no->value=aux->value;
	no=aux;
     }
     //nó tem 0 ou 1 filho
     aux = no->lft==0?no->rgt:no->lft;
     if(no->parent==0)
       root = aux;
     else if(no->value < no->parent->value)
       no->parent->lft=aux;
     else
       no->parent->rgt=aux;
     
     if(aux != 0)
       aux->parent=no->parent;
     delete no;
     numberOfNodes--;
}
 
void BinaryTree::clear()
  {
     deleteTree(root);
     root=0;
     numberOfNodes=0;
  }
 
void BinaryTree::deleteTree(Node *p)
{
    if(p!=0)
    {
	deleteTree(p->lft);
	deleteTree(p->rgt);
	delete p;
      
    }
 }
 
 int BinaryTree::min(Node *ptr)
 {
    while(ptr->lft!=0){
	ptr=ptr->lft;
    }
    return ptr->value;
   
 }

void BinaryTree::inLevel(Node *p, int atual, int i)
{
  if(p != 0)
  {
    if(atual == i)
      printf("%d ", p->value);
    inLevel(p->lft, atual+1, i);
    inLevel(p->rgt, atual+1, i);
  }
}
void BinaryTree::height()
{
    printf("\nAltura da Árvore: %d \n", height(root));
  
}

int BinaryTree::height(Node *p)
{
    if(p!=0)
    {
      int he = height(p->lft);
      int hd = height(p->rgt);
      if(he > hd)
        return 1+he;
      else
        return 1+hd;
    }
    return 0;
}

bool BinaryTree::complete(Node *p)
{
  int h, i;
  if(p!=0)
  {
    h = height(p);
    if(p->lft == NULL || p->rgt == NULL)
    {
      i = height(p);
      if((h - i) <= 2)
        return false;
    }
    else
    { 
      complete(p->lft);
      complete(p->rgt);
    }
  }
  return true;
}

void BinaryTree::completa()
{
  int h = height(root);
  if(completa(root, 1, h))
    printf("\n Completa");
  else
    printf("\n Não é completa");
}

bool BinaryTree::completa(Node *p, int nivel, int h)
{
  if(p != 0)
  {
    if(!(p->lft != 0 && p->rgt != 0))
    {
      if(nivel < h-1)
        return false;
    }
    return completa(p->lft, nivel+1, h) && completa(p->rgt, nivel+1, h);
  }
  return true;
}