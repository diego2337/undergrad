#ifndef __RNTree_h
/*#include "RNTree.h"
#include "intList.h"*/
#include "Treelist.h"
#endif

#include <string.h>
#include <iostream>
using namespace std;

int main(void)
{
	int option = 1, i;
	int chave;
	char name[50];
	char brand[20];
	int unit;
	char storage[10];
	RNTree* B = new RNTree();
	Node* tlnode = new Node();
	IntList* L = new IntList();
	cout << "Esse programa ira fazer as operações de inserção, remoção e atualização de dados postos em uma lista duplamente encadeada, acessada através de uma árvore RB.\n";
	cout << "As seguintes operações estão disponíveis: \n";
	cout << "0 : finaliza as consultas feitas até então;\n";
	cout << "1 : irá inserir o que se deseja na árvore e lista;\n";
	cout << "2 : irá remover o produto desejado. Só é necessário informar a chave do mesmo para sua remoção;\n";
	cout << "3 : irá executar a atualização da árvore e lista.\n";
	cout << "Qualquer outro comando é inválido. Escolha sua opção:\n";
	while(option != 0)
	{
		cin >> option;
		if(option == 1)
		{
			cout << "Insira os dados do produto que deseja por (código do produto, nome, marca, quantidade e unidade, respectivamente)\n";
			cin >> chave;
			cin >> name;
			cin >> brand;
			cin >> unit;
			cin >> storage;
			tlnode = B->add(chave);
			tlnode->ptr = L->addToHead(chave, name, brand, unit, storage);
		}
		else if(option == 2)
		{
			cout << "Insira somente a chave do produto que deseja remover\n";
			cin >> chave;
			/* E necessario procurar o produto para saber se ele realmente esta na arvore/lista */
			if(B->contains(chave))
			{
				B->remove(chave);

			}
		}
	}
}