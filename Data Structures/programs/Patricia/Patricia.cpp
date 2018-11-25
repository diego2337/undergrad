#ifndef PATRICIA_H
#include "Patricia.h"
#endif

Node::Node()
{
  esq = 0;
  dir = 0;
}

Node::Node(char* s1)
{
  s = new char[strlen(s1)+1];
  strcpy(s, s1);
  esq = 0;
  dir = 0;
  folha = true;
}

Node::Node(int v)
{
  valor = v;
  esq = 0;
  dir = 0;
  folha = false;
}


Patricia::Patricia()
{	 
  raiz = 0;
}

Node* Patricia::retRaiz()
{
  return raiz;
}

Patricia::~Patricia()
{
    // apagar toda a árvore
}


Node* Patricia::busca(char* x)
{
  Node *pt = raiz;
  int a = 0;
  search(x, pt, a);
  if(a == 1)
  {
    if(strcmp(pt->s, x) == 0)
      return pt;
    else
      printf("\n Chave não encontrada\n");
  }
  else 
    printf("\n Chave não encontrada\n");
}

void Patricia::search(char *x, Node *&pt, int &a)
{
  if(pt->esq == 0)
    a = 1;
  else if(strlen(x) < pt->valor)
    a = 2;
  else if(x[pt->valor] == '0')
  {
    pt = pt->esq;
    search(x, pt, a);
  } 
  else
  {
    pt = pt->dir;
    search(x, pt, a);
  }
}
void Patricia::add(char *x)
{
  if(raiz == 0)
  {
    raiz = new Node(x);
  }
  else
  {
    int a= 0;
    Node *pty = raiz;
    search(x, pty, a);    
    while(pty->esq != 0)
      pty = pty->esq;
    int l = -1;
    int K = strlen(x);
    int c = strlen(pty->s);
    int min = K;
    if(c < K)
      min = c;
    while(l < min && x[l+1] == pty->s[l+1])
      l++;
    if(l == min)
      printf("\nInclusao invalida\n");
    else
      add2(x, raiz, l);
  }
}

void Patricia::add2(char *x, Node *pt, int l)
{
  bool descer = true;
  bool esquerdo;
  Node *ptv = new Node(l+1);
  Node* ptq = new Node();
  Node *ptw = new Node(x);
  Node *ptz = pt;
  while(ptz->esq != NULL && descer)
  {
    if(ptz->valor <= l+1)
    {
      ptq = ptz;
      if(x[ptz->valor] == '0')
      {
        ptz = ptz->esq;
        esquerdo = true;
      }
      else
      {
        ptz = ptz->dir;
        esquerdo = false;
      }
    }
    else
    {
      descer = false;
    }
  }
  if(x[l+1] == '0')
  {
    ptv->esq = ptw;
    ptv->dir = ptz;
  }
  else
  {
    ptv->esq = ptz;
    ptv->dir = ptw;
  }
  if(ptz == raiz)
    raiz = ptv;
  else if(esquerdo)
    ptq->esq = ptv;
  else
    ptq->dir = ptv;
}

void Patricia::imprime(Node* p)
{
  if(p!=0)
  {
    if(p->folha)
	printf("\n%s", p->s);
    
    imprime(p->esq);
    imprime(p->dir);
  }
}
