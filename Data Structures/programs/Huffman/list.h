#ifndef __LIST_H
#define __LIST_H

class Node
{
  public:
    int freq;
    char c;
    bool leaf;
    Node* lft;
    Node* rgt;
    
    Node(int f)
    {
     freq = f;
     leaf = false;
     lft = rgt = 0;
    }
    
    Node(int f, char c)
    {
     freq = f;
     this->c = c;
     leaf = true;
     lft = rgt = 0;
    }
};

class NodeList
{
  public:
    Node *node;
    NodeList *next;
    
    NodeList(Node *no)
    {
     node = no;
     next = 0;
    }  
};

class List
{
  private:
    NodeList *head;
    int numberOfNodes;
    
  public:
    List()
    {
     head = 0;
     numberOfNodes = 0;
    }
    
    int getNumberOfNodes()
    {
     return numberOfNodes;
    }
    
    NodeList *getHead()
    {
     return head; 
    }
    
    void build(int *, char*, int);
    Node *min();
    void add(Node*);
   
};

#endif