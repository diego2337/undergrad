// Arquivo: DoubleListException.h

#ifndef _DOUBLELISTEXCEPTION_H
#define _DOUBLELISTEXCEPTION_H

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

class DoubleListException 
{
	public: 
		DoubleListException(int t_exception)
		{
			this->t_exception = t_exception;
		}
		void treatment();
		int t_exception;
};

void 
DoubleListException::treatment()
{

	switch(this->t_exception)
	{
		case 0:
			cout << "\nExceção do tipo 0. Erro na alocação de memória.";
			// invoca método para tratar a exceção do tipo 0, se necessário.
			break;
		case 1:
			cout << "\nExceção do tipo 1. Delete não executado; lista vazia.";
			// invoca método para tratar a exceção do tipo 1, se necessário.
			break;
		case 2:
			cout << "\nExceção do tipo 2. Delete não executado; elemento não encontrado.";
			// invoca método para tratar a exceção do tipo 2, se necessário.
			break;
		default:
			cout << "\nExceção desconhecida. Programa finalizado.";
			exit(1);
	}

}

/*
class NewError
{
	public:
		NewError()
		{
			
		}
};



class EmptyListError
{
	public:
		EmptyListError()
		{
			
		}
};


class NotFoundError
{
	public:
		NotFoundError()
		{
			
		}
};

*/

#endif

