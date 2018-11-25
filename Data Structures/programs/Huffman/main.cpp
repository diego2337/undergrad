#ifndef __HUFFMAN_H
#include "huffman.h"
#endif

int main()
{
	char msg[100];
	strcpy(msg, "o rato");
	huffman *hm;
	hm = new huffman(msg);
	hm->encodes();
	//hm->print();
	cout << "\n\n Msg decodificada:";
	//hm->decodes();
	return 0;
}