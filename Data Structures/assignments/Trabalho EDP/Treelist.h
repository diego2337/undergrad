#ifndef _TREELIST_H_
#define _TREELIST_H_
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
    IntNode *prev;

  IntNode()
  {
    info = 0;
    unit = 0;
    next = NULL;
    prev = NULL;
  }
  IntNode(int info, char* name, char* brand, int unit, char* storage, IntNode *next=NULL, IntNode *prev=NULL)
  {
    info=this->info;
    name = this->name;
    brand = this->brand;
    unit = this->unit;
    storage = this->storage;
    next = this->next;
    prev = this->prev;
  }
};

class IntList
{
  public:
    IntList()
    {
     head=tail=0; 
    }
  IntNode* addToHead(int, char*, char*, int, char*);
  void addToTail(int, char*, char*, int, char*);
  void deleteFromHead();
  //int deleteFromtail(int);
  void deleterandom(IntNode*);
  bool isEmpty(){
    return head==0;
  }
  void printList();
    IntNode *head;
    IntNode *tail;
};

class Node {
public:
	Node* lft;
	Node* rgt;
	Node* parent;
	int value;
	bool black;
	IntNode *ptr;
	Node() 
	{
		lft = rgt = parent = 0;
		black = true;
		ptr = new IntNode();
	}

	Node(int value) 
	{
		this->value = value;
	}	
};

class RNTree {
public:
	Node* root;
	Node* nil;
	int numberOfNodes;

	void rotationLeft(Node*);
	void rotationRight(Node*);
	void print(Node*);
	void fixUp(Node*&);
	void deleteTree(Node*);

	RNTree();
	~RNTree();

	Node* add(int);
	bool contains(int);
	Node* suc(Node*);
	bool remove(int);
	void RNTroca(Node*, Node*);
	void fixUp2(Node*&);

	void print() {
		print(root);
	}

	int size() const {
		return numberOfNodes;
	}
	
	bool isEmpty() const {
		return numberOfNodes == 0;
	}
	
};
