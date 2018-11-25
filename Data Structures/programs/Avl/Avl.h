#ifndef __avl_h
#define __avl_h
#ifndef _stdio_h
#include <stdio.h>
#endif

class Node {
public:
    int value, balance;
    Node* lft;
    Node* rgt;

    Node (int value)
    {
        this->value = value;
        lft = rgt = 0;
        balance = 0;
    }
};

class AvlTree {
public:

    AvlTree() {
        root = 0;
        numberOfNodes = 0;
    }
    ~AvlTree();
    int size(){
        return numberOfNodes;
    }
    bool isEmpty() const {
        return root == 0;
    }
    bool add(int);
    Node* findNode(int, Node*&);
    void preOrdTree(Node*);
     void clear();
    Node *retRoot(){return root;}
     /*bool remove(int);*/
    /*int min(Node*);
    void height(); // Altura*/
private:
    Node* root;
    int numberOfNodes;
    //void deleteTree(Node*);
    bool add(int, Node*&, bool &);
    void rotationLeft(Node*&);
    void rotationRight(Node*&);
    /*void addNode(int, Node*);
    void removeNode(Node*);
    void visitNode(Node*);
    int height(Node*);
    int height2(Node*);*/


};

#endif