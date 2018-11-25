#ifndef __HUFFMAN_H
#include "huffman.h"
#endif

huffman::huffman(char* s)
{
	lengthC = strlen(s);
	msgC = new char[lengthC+1];
	strcpy(msgC, s);
	L = new List();
}

void huffman::encodes()
{
	int i;
	Node* min1;
	Node* min2;
	int *table = new int[256];
	char strtemp[100];
	// Contando os caracteres
	for(i = 0; i < lengthC; i++)
		table[int(msgC[i])]++;
	// Considerando apenas "" e a-z (A-Z)

	for(i = 32; i <= 122; i++)
	{
		if(table[i] != 0)
		{
			Node* aux = new Node(table[i], char(i));
			L->add(aux);
		}
	}
	// Algoritmo
	while(L->getNumberOfNodes() > 1)
	{
		Node* newNode;
		min1 = L->min();
		min2 = L->min();
		newNode = new Node(min1->freq+min2->freq);
		newNode->lft = min1;
		newNode->rgt = min2;
		L->add(newNode);
	}
	// Matriz que armazenara codigos binarios 
	matriz = new char*[256];
	// Encontrando a string binaria para cada char
	find(L->getHead()->node, strtemp, 0);
	// Construir a string = compactacao
	msgD = new char[200];
	for(i = 0; i < lengthC; i++)
		strcat(msgD, matriz[int(msgC[i])]);
	lengthD = strlen(msgD);
	cout << "\n\n Msg codificada" << msgD;
	for(i = 0; i < lengthC; i++)
	{
		cout << "\n" << matriz[msgC[i]];
	}
}

void huffman::find(Node* p, char str[], int pos)
{
	if(p != 0)
	{
		if(p->leaf)
		{
			str[pos] = '\0';
			matriz[int(p->c)] = new char[strlen(str)];
			strcpy(matriz[int(p->c)], str);
		}
		if(p->lft)
		{
			str[pos] = '0';
			find(p->lft, str, pos+1);
		}
		if(p->rgt)
		{
			str[pos] = '1';
			find(p->rgt, str, pos+1);
		}
	}
}

void huffman::decodes()
{

}