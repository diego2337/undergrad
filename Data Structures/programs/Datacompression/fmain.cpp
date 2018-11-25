#ifndef __FREQUENCIA_H
#include "frequencia.h"
#endif

int main()
{
	int i;
	char msg[100];
	char palavra[100];
	cout << "Digite uma palavra: ";
	cin >> palavra;
	strcpy(msg, palavra);
	Frequencia *fq;
	fq = new Frequencia(msg);
	cout << "Msg codificada: ";
	fq->encodes();
	return 0;
}