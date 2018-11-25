/*#include <stdio.h>
#include "RNTree.h"
#include "intList.h"*/
#include "Treelist.h"

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

Node* RNTree::add(int value) {
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
	return node;
}

Node* RNTree::suc(Node* node) {
	Node* suc = node->rgt;
	while(suc->lft != nil)
		suc = suc->lft;
	return suc;
}

void RNTree::fixUp(Node*& node) {
	Node *uncle;
	while(node != root && node->parent->black == false)
	{
		if(node->parent == node->parent->parent->lft)
		{
			uncle = node->parent->parent->rgt;
			if(uncle->black == false)
			{
				node->parent->black = true;
				uncle->black = true;
				node->parent->parent->black = false;
				node = node->parent->parent;
			}
			else
			{
				if(node == node->parent->rgt)
				{
					node = node->parent;
					rotationLeft(node);
				}
				node->parent->black = true;
				node->parent->parent->black = false;
				rotationRight(node->parent->parent);
			}
		}
		else
		{
			uncle = node->parent->parent->lft;
			if(uncle->black == false)
			{
				node->parent->black = true;
				uncle->black = true;
				node->parent->parent->black = false;
				node = node->parent->parent;
			}
			else
			{
				if(node == node->parent->lft)
				{
					node = node->parent;
					rotationRight(node);
				}
				node->parent->black = true;
				node->parent->parent->black = false;
				rotationLeft(node->parent->parent);
			}
		}
	}
	root->black = true;
}

bool RNTree::remove(int value)
{
	Node* r = root;
	Node* a;
	Node* b;
	while(r->value != value && r != nil)
	{
		if(value < r->value)
			r = r->lft;
		else
			r = r->rgt;
	}
	if(root == nil)
		return false; /* o elemento nao foi encontrado */

	b = r;
	bool cor = b->black;
	/* r tem um filho */
	if(r->lft == nil)
	{
		a = r->rgt;
		RNTroca(r, r->rgt);
	}
	else
	{
		if(r->rgt == nil)
		{
			a = r->lft;
			RNTroca(r, r->lft);
		}
		else
		{
			/* dois filhos */
			b = suc(r);
			cor = b->black;
			a = b->rgt;
			if(b->parent == r)
				a->parent = b;
			else
			{
				RNTroca(b, b->rgt);
				b->rgt = r->rgt;
				b->rgt->parent = b;
			}
			RNTroca(r, b);
			b->lft = r->lft;
			b->lft->parent = b;
			b->black = r->black;
		}
	}
	if(cor == true)
		fixUp2(a);
	delete r;
	return true;
}
void RNTree::RNTroca(Node *x, Node *y)
{
	if(x->parent == nil)
		root = y;
	else
	{
		if(x == x->parent->lft)
			x->parent->lft = y;
		else
			x->parent->rgt = y;
		y->parent = x->parent;
	}
}

void RNTree::fixUp2(Node*& x)
 {
	Node* w;
	while(x != root && x->black == true)
	{
		if(x == x->parent->lft)
		{
			w = x->parent->rgt;
			if(w->black == false)
			{
				w->black = true;
				x->parent->black = false;
				rotationLeft(x->parent);
				w = x->parent->rgt;
			}
			if(w->lft->black == true && w->rgt->black == true)
			{
				w->black = false;
				x = x->parent;
			}
			else
			{
				if(w->rgt->black = true)
				{
					w->lft->black = true;
					w->black = false;
					rotationRight(w);
					w = x->parent->rgt;
				}
				w->black = x->parent->black;
				x->parent->black = true;
				w->rgt->black = true;
				rotationLeft(x->parent);
				x = root;
			}
		}
		else
		{
			// caso simetrico
			w = x->parent->lft;
			if(w->black == false){
				w->black = true;
				x->parent->black = false;
				rotationLeft(x->parent);
				w = x->parent->lft;
			}
			if(w->rgt->black == true && w->lft->black == true)
			{
				w->black = false;
				x = x->parent;
			}
			else
			{
				if(w->lft->black == true)
				{
					w->rgt->black = true;
					w->black = false;
					rotationLeft(w);
					w = x->parent->lft;
				}
				w->black = x->parent->black;
				x->parent->black = true;
				w->lft->black = true;
				rotationRight(x->parent);
				x = root;
			}
		}
	}
	x->black = true;
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

