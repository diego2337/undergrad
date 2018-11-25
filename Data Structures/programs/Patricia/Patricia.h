#ifndef PATRICIA_H
#define PATRICIA_H

#include <stdio.h>
#include <string.h>

class Node
{
    public:
      int valor;
      char *s;
      Node *esq, *dir;
      bool folha;
        Node(char*);
        Node(int);
        Node();
};


class Patricia
{
public:
  Patricia();
  ~Patricia();

  Node* busca(char* );
  void search(char*, Node*&, int&);
  void add(char*); 
  void add2(char*, Node*, int);
  Node* allocatenode();

  
  Node* retRaiz();
  void imprime(Node*);
    
private:
  Node* raiz;
  
};

#endif // PATRICIA_H
