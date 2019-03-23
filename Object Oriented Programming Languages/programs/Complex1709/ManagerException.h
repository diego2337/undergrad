#ifndef MANAGEREXCEPTION_H
#define MANAGEREXCEPTION_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class ManagerException
{
public:
	ManagerException(int t_exception)
	{
		this->t_exception = t_exception;
	}
	void treatment();
	int t_exception;
};

void ManagerException::treatment()
{
	switch(this->t_exception)
	{
		case 0:
			cout << "\nExceção do tipo 0: O numero do processador não corresponde à quantidade especificada.\n";
			exit(1);
		case 1:
			cout << "\nExceção do tipo 1: A operação requisitada é inválida. Tente 'r' para leitura e 'w' para escrita.\n";
			exit(1);
		case 2:
			cout << "\nExceção do tipo 2: O endereço da memória principal não existe. Tente um valor entre os limites especificados.\n";
			exit(1);
	}
}

#endif