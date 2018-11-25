#ifndef __HUFFMAN_H
#define __HUFFMAN_H
#include <iostream>
using namespace std;
#include <string.h>
#ifndef __LIST_H
#include "list.h"
#endif

class huffman
{
private:
	char* msgC;
	char* msgD;
	char** matriz;
	int lengthC, lengthD;
	List *L;

public:
	huffman(char*);
	void encodes();
	void decodes();
	//void print();
	void find(Node*, char*, int);
};

#endif