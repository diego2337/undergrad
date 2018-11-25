#ifndef _RNTREE_H_
#define _RNTREE_H_

class Node {
public:
	Node* lft;
	Node* rgt;
	Node* parent;
	int value;

	bool black;

	Node() {
		lft = rgt = parent = 0;
		black = true;
	}

	Node(int value) {
		this->value = value;
	}	
};

class RNTree {
private:
	Node* root;
	Node* nil;
	int numberOfNodes;

	void rotationLeft(Node*);
	void rotationRight(Node*);
	void print(Node*);
	void fixUp(Node*&);
	void deleteTree(Node*);

public:
	RNTree();
	~RNTree();

	bool add(int);
	bool contains(int);

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


#endif
