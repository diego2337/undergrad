#include <stdio.h>
#include "RNTree.h"

RNTree::RNTree() {
	nil = new Node();
	root = nil;
	numberOfNodes = 0;
}

RNTree::~RNTree() {
	numberOfNodes = 0;
	deleteTree(root);
	delete nil;
}

bool RNTree::add(int value) {
	Node* y = nil;   // pai do novo nó a ser inserido
	Node* x = root;

	while(x != nil) {
		y = x;

		if(x->value == value)
			return false;
		
		x = value < x->value ? x->lft : x->rgt;
	}

	Node* node = new Node(value);
	node->parent = y;
	
	if(y == nil)
		root = node;
	else {
		if(value < y->value)
			y->lft = node;
		else
			y->rgt = node;
	}

	node->lft = nil;
	node->rgt = nil;
	node->black = false;
	fixUp(node);

	numberOfNodes++;
	return true;
}

void RNTree::fixUp(Node*& node) {
	// CONSTRUIR
}

bool RNTree::contains(int value) {
	Node* x = root;

	while(x != nil) {
		if(x->value == value)
			return true;

		x = value < x->value ? x->lft : x->rgt;
	}

	return false;
}

void RNTree::rotationLeft(Node* node) {
	Node* y = node->rgt;
	node->rgt = y->lft;

	if(y->lft != nil)
		y->lft->parent = node;

	y->parent = node->parent;
	if(node->parent == nil)
		root = y;
	else {
		if(node == node->parent->lft)
			node->parent->lft = y;
		else
			node->parent->rgt = y;
	}

	y->lft = node;
	node->parent = y;
}

void RNTree::rotationRight(Node* node) {
	Node* y = node->lft;
	node->lft = y->rgt;

	if(y->rgt != nil)
		y->rgt->parent = node;

	y->parent = node->parent;
	if(node->parent == nil)
		root = y;
	else {
		if(node == node->parent->rgt)
			node->parent->rgt = y;
		else
			node->parent->lft = y;
	}

	y->rgt = node;
	node->parent = y;
}

void RNTree::deleteTree(Node* node) {
	if(node != nil) {
		deleteTree(node->lft);
		deleteTree(node->rgt);
		delete node;
	}
}

void RNTree::print(Node* node) {
	static int offset = 0;

	for (int i = 0; i < offset; ++i)
		printf(" ");

	if (node == nil) {
		printf("-[N]\n");
		return;
	}
	
	if(node->black)
		printf("%d[N]\n", node->value);
	else
		printf("%d[R]\n", node->value);

	offset += 3;
	print(node->lft);
	print(node->rgt);
	offset -= 3;
}

