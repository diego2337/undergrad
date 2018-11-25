#include <stdio.h>

class Node {
public:
    int value;
    Node* lft;
    Node* rgt;
    Node* parent;

    Node(int value, Node* parent = 0) {
        this->value = value;
	this->parent = parent;
        lft = rgt = 0;
    }
};

class BinaryTree {
public:

    BinaryTree() {
        root = 0;
        numberOfNodes = 0;
    }

    ~BinaryTree() {
        clear();
    }

    int size() const {
        return numberOfNodes;
    }

    bool isEmpty() const {
        return root == 0;
    }

    bool add(int);
    bool remove(int);
    Node* findNode(int, Node*&);
    Node* suc(int value);
    Node* level(Node *p, int level, int level2);
    Node *retRoot(){return root;}
    void preOrdTree(Node*);
     void clear();
    int min(Node*);
    void height(); // Altura
    int height(Node*);
    void inLevel(Node *, int atual, int i);
    bool complete(Node *);
    void completa();
    bool completa(Node *, int, int);
private:
    Node* root;
    int numberOfNodes;
    
    void addNode(int, Node*);
    void removeNode(Node*);
    void visitNode(Node*);
    void deleteTree(Node*);


};

