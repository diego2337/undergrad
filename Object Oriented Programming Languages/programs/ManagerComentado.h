#ifndef MANAGER_H
#define MANAGER_H
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "Memory.h"
#include "Cache.h"
#include "Directory.h"
#include "Statistics.h"
#include "ManagerException.h"
#include <vector>
#include <stdlib.h>
#include <stdint.h>
template <typename T>
class Manager
{
private:
	Cache<T> **c;
	Directory* d;
	Memory<T>* m;
	Statistics s;
	unsigned int MAX_RAM;
	int MAX_BLOCKS;
	int N_WORKERS;
public:

	Manager(unsigned int Max_Ram, int Max_Blocks, short int N_Workers)
	{
		d = new Directory(Max_Blocks);
		m = new Memory<T>[Max_Ram];
		MAX_RAM = Max_Ram;
		MAX_BLOCKS = Max_Blocks;
		N_WORKERS = N_Workers;
	}
	~Manager()
	{
		delete []m;
		delete []c;
	}
	void simulatesystem();
	void startSimulation(FILE*);
	void readmiss(unsigned int, int, int);
	void writemiss(unsigned int, int, T, int);
	void readone(unsigned int, int, int);
	void writeone(unsigned int, int, T, int);
	void readmissone(unsigned int, int, int);
	void writehitone(T, int, unsigned int, int);
	void writemissone(unsigned int, int, T, int);
	void readtwo(unsigned int, int, int);
	void readmisstwo(unsigned int, int, int, int);
	void writetwo(unsigned int, int, T, int);
	void writemisstwo(unsigned int, int, T, int, int);
};

template <typename T>
void Manager<T>::simulatesystem()
{

}

template <typename T>
void Manager<T>::startSimulation(FILE *in)
{
	int n_worker;
	char operation;
	int trash;
	unsigned int ram_address;
	T value;
	int status, index;
	for(int i = 0; i < 2; i++)
	{
		if(i == 0) // Primeiramente, vamos executar o esquema de caches Writethrough.
		{
			c = new Cache<T>*[N_WORKERS];
			for(int j = 0; j < N_WORKERS; j++)
				c[j] = new WriteThrough<T>(MAX_BLOCKS);
		}
		else if(i == 1) // Agora, vamos executar o mesmo arquivo, mas com a política Writeback.
		{
			c = new Cache<T>*[N_WORKERS];
			for(int j = 0; j < N_WORKERS; j++)
				c[j] = new WriteBack<T>(MAX_BLOCKS);
			m = new Memory<T>[MAX_RAM];
		}
		rewind(in); // Como vamos ler novamente o arquivo para executa-lo duas vezes, 
		// simplesmente utilizamos uma variavel para armazenar as 4 primeiras informaçoes que
		// ja obtivemos.
		for(int j = 0; j < 4; j++)
			fscanf(in, "%d", &trash);
		while(1)
		{
			/*cout << "------------------------------------------------------------ \n\n";
			cout << "Numero de acessos à memória principal para leitura: " << s.getRead() << "\n";
			cout << "Numero de acessos à memória principal para escrita: " << s.getWrite() << "\n";
			cout << "Numero de HITS de leitura ou escrita na cache: " << s.getHits() << "\n";
			cout << "Numero de MISSES de leitura ou escrita na cache: " << s.getMisses() << "\n";
			cout << "Numero de substituições de blocos de cache: " << s.getSwitches() << "\n\n"; */
			try
			{
				fscanf(in, "%d ", &n_worker);
				if((feof(in)))
				{
					break;
				}
				if(n_worker < 0 || n_worker > N_WORKERS-1)
					throw ManagerException(0);
				else
				{
					fscanf(in, "%c", &operation);
					if(operation != 'W' && operation != 'R' && operation != 'w' && operation != 'r')
						throw ManagerException(1);
					else
					{
						fscanf(in, "%u", &ram_address);
						//printf("n_worker: %d operation: %c ram_address: %u \n", n_worker, operation, ram_address);
						index = ram_address % MAX_BLOCKS;
						if((operation == 'w' || operation == 'W') && (ram_address >= 0 || ram_address <= MAX_RAM))
						{
							fscanf(in, "%hhu", &value);
							status = d->checkStatus(index);
							//printf("status: %d\n", status);
							if(status == 0)
							{
								s.incMisses();
								this->writemiss(ram_address, n_worker, value, index);
							}
							else if(status == 1)
							{
								this->writeone(ram_address, n_worker, value, index);
							}
							else if(status == 2)
							{
								this->writetwo(ram_address, n_worker, value, index);
							}
						}
						else if(ram_address >= 0 || ram_address <= MAX_RAM)
						{
							status = d->checkStatus(index);
							if(status == 0)
							{
								s.incMisses();
								this->readmiss(ram_address, n_worker, index);
							}
							else if(status == 1)
							{
								this->readone(ram_address, n_worker, index);
							}
							else if(status == 2)
							{
								this->readtwo(ram_address, n_worker, index); 
							}
						}
						else
							throw ManagerException(2); // TRATAMENTO DE EXCEÇAO
					}
				}
			}
			catch(ManagerException &exp)
			{
				exp.treatment();
			}
		}
		if(i == 0)
		{
			cout << "Esses são os resultados para a execução utilizando a política de cache Writethrough: \n";
			cout << "Numero de acessos à memória principal para leitura: " << s.getRead() << "\n";
			cout << "Numero de acessos à memória principal para escrita: " << s.getWrite() << "\n";
			cout << "Numero de HITS de leitura ou escrita na cache: " << s.getHits() << "\n";
			cout << "Numero de MISSES de leitura ou escrita na cache: " << s.getMisses() << "\n";
			cout << "Numero de substituições de blocos de cache: " << s.getSwitches() << "\n";
		}
		else if(i == 1)
		{
			cout << "\nEsses são os resultados para a execução utilizando a política de cache Writeback: \n";
			cout << "Numero de acessos à memória principal para leitura: " << s.getRead() << "\n";
			cout << "Numero de acessos à memória principal para escrita: " << s.getWrite() << "\n";
			cout << "Numero de HITS de leitura ou escrita na cache: " << s.getHits() << "\n";
			cout << "Numero de MISSES de leitura ou escrita na cache: " << s.getMisses() << "\n";
			cout << "Numero de substituições de blocos de cache: " << s.getSwitches() << "\n";
		}
		 // Reiniciando o diretorio, para nao manter informaçoes
		// da execuçao anterior
		d->clear(MAX_BLOCKS);
		s.clear();
		for(int v = 0; v < MAX_RAM; v++)
		{
			m[v].clear();
		}
	}
}

template <typename T>
void Manager<T>::readmiss(unsigned int ram_address, int n_worker, int index)
{
	T mem = m[ram_address].getData();
	s.incRead();
	int n = ceil(log(ram_address) - log(MAX_BLOCKS));
	c[n_worker]->setData(mem, index, n);
	d->setStatus(1, index);
	d->setCacheList(n_worker, index);
	c[n_worker]->setValid(true, index);
}

template <typename T>
void Manager<T>::writemiss(unsigned int ram_address, int n_worker, T value, int index)
{
	int sinal;
	int n = ceil(log(ram_address) - log(MAX_BLOCKS));
	sinal = c[n_worker]->WRITEMISS(index, value, n); 
	if(sinal == 0)
	{
		m[ram_address].setData(value);
		s.incWrite(); // Acesso a MP para escrita
	}
	else if(sinal == 1)
		d->setDirty(true, index);
	d->setStatus(1, index);
	d->setCacheList(n_worker, index);
	c[n_worker]->setValid(true, index);
}

template <typename T>
void Manager<T>::readone(unsigned int ram_address, int n_worker, int index)
{
	int j = d->returnNumberOfElements(index);
	int n = ceil(log(ram_address) - log(MAX_BLOCKS)); // Achando a tag do endereço requisitado
	for(int i = 0; i < j; i++)
	{
	//	cout << "VC vem daqui? 1\n";
		int element = d->getCacheList(i, index);
		if(n_worker == element)
		{
			if(c[n_worker]->getValid(index))
			{
				if(c[n_worker]->checkTag(index, n))
				{
					/* Achou - READHIT */
					s.incHits();
					return;
				}
				else
				{
					/* Se a tag nao e a mesma, entao indica uma substituiçao */
					s.incSwitches();
					this->readmissone(ram_address, n_worker, index);
					return;
				}
			}
		}
	}
	/* Se nao achou - READMISS */
	s.incMisses();
	this->readmissone(ram_address, n_worker, index);
}

template <typename T>
void Manager<T>::writeone(unsigned int ram_address, int n_worker, T value, int index)
{
	int j = d->returnNumberOfElements(index);
	int n = ceil(log(ram_address) - log(MAX_BLOCKS)); // Calculando a tag do endereço requisitado
	for(int i = 0; i < j; i++)
	{
		//	cout << "VC vem daqui? 2\n";
		int element = d->getCacheList(i, index);
		if(n_worker == element)
		{
			if(c[n_worker]->getValid(index))
			{
				if(c[n_worker]->checkTag(index, n))
				{
					s.incHits();
					this->writehitone(value, n_worker, ram_address, index);
					return;
				}
				else
				{
					s.incSwitches();
					this->writemissone(ram_address, n_worker, value, index);
					return;
				}
			}
		}
	}
	/* Se nao achou - WRITEMISS */
	s.incMisses();
	this->writemissone(ram_address, n_worker, value, index);
}

template <typename T>
void Manager<T>::readmissone(unsigned int ram_address, int n_worker, int index)
{
	//	cout << "VC vem daqui? 3\n";
	int element = d->getCacheList(0, index);
	int n = ceil(log(ram_address) - log(MAX_BLOCKS));
	T mem;
	if(c[element]->checkTag(index, n)) // Vamos checar a tag para ter certeza de que sao os mesmos valores
	{	
		mem = c[element]->getData(index);
	}
	else
	{
		mem = m[ram_address].getData();
		s.incRead();
	}
	c[n_worker]->setData(mem, index, n);	
	d->setStatus(2, index);
	d->setCacheList(n_worker, index);
	c[n_worker]->setValid(true, index);
}

template <typename T>
void Manager<T>::writehitone(T value, int n_worker, unsigned int ram_address, int index)
{
	int n = ceil(log(ram_address) - log(MAX_BLOCKS));
	int sinal = c[n_worker]->WRITEHIT(index, value, n);
	if(sinal == 0)
	{	
		d->setDirty(false, index);
		m[ram_address].setData(value);
		s.incWrite();
	}
	else
		d->setDirty(true, index);
}

template <typename T>
void Manager<T>::writemissone(unsigned int ram_address, int n_worker, T value, int index)
{
	//	cout << "VC vem daqui? 4\n";
	int element = d->getCacheList(0, index);
	int n = ceil(log(ram_address) - log(MAX_BLOCKS));
	T mem;
	if(c[element]->checkTag(index, n)) // Vamos checar a tag para ter certeza de que sao os mesmos valores
	{	
		mem = c[element]->getData(index);
	}
	else
	{
		mem = m[ram_address].getData();
		s.incRead();
	}
	int sinal = c[n_worker]->WRITEMISS(index, value, n);
	if(sinal == 0)
	{
		// Caso de política Writethrough
		d->setDirty(false, index);
		m[ram_address].setData(value);
		s.incWrite();
	}
	else // Política Writeback
		d->setDirty(true, index);
	d->removeCacheList(0, index);
	d->setCacheList(n_worker, index);
	c[n_worker]->setValid(true, index);
}

template <typename T>
void Manager<T>::readtwo(unsigned int ram_address, int n_worker, int index)
{
	int j = d->returnNumberOfElements(index);
	int z = 0, element = 0;
	int n = ceil(log(ram_address) - log(MAX_BLOCKS)); // Calculando a tag do endereço requisitado
	//printf("j: %d\n\n", j);
	for(int i = 0; i < j; i++)
	{
		/* E aqui que ta o erro */
	//	cout << "VC vem daqui? 5\n";
		element = d->getCacheList(i, index);
	//	printf("writetwo: %d\n", element);
		if(n_worker == element)
		{
			z = i;
			if(c[n_worker]->getValid(index))
			{
				if(c[n_worker]->checkTag(index, n))
				{
					s.incHits();
					return;
				}
				else
				{
					s.incSwitches();
					this->readmisstwo(ram_address, n_worker, index, z);
					return;
				}
			}
		}
	}
	/* Se nao achou - READMISS */
	s.incMisses();
	this->readmisstwo(ram_address, n_worker, index, z);
}

template <typename T>
void Manager<T>::writetwo(unsigned int ram_address, int n_worker, T value, int index)
{
	int j = d->returnNumberOfElements(index);
	int element = 0;
	int n = ceil(log(ram_address) - log(MAX_BLOCKS)); // Calculando a tag do endereço requisitado
	//printf("j: %d\n\n", j);
	for(int i = 0; i < j; i++)
	{
		/* E aqui que ta o erro */
	//	cout << "VC vem daqui? 5\n";
		element = d->getCacheList(i, index);
	//	printf("writetwo: %d\n", element);
		if(n_worker == element)
		{
			if(c[n_worker]->getValid(index))
			{
				if(c[n_worker]->checkTag(index, n))
				{
					s.incHits();
					this->writehitone(value, n_worker, ram_address, index);
					return;
				}
				else
				{
					s.incSwitches();
					this->writemisstwo(ram_address, n_worker, value, index, element);
					return;
				}
			}
		}
	}
	/* Se nao achou - WRITEMISS */
	s.incMisses();
	this->writemisstwo(ram_address, n_worker, value, index, element);
}

template <typename T>
void Manager<T>::readmisstwo(unsigned int ram_address, int n_worker, int index, int z)
{
	//	cout << "VC vem daqui? 3\n";
	int element = d->getCacheList(z, index);
	int n = ceil(log(ram_address) - log(MAX_BLOCKS));
	T mem;
	if(c[element]->checkTag(index, n)) // Vamos checar a tag para ter certeza de que sao os mesmos valores
	{	
		mem = c[element]->getData(index);
	}
	else
	{
		mem = m[ram_address].getData();
		s.incRead();
	}
	c[n_worker]->setData(mem, index, n);	
	d->setCacheList(n_worker, index);
	c[n_worker]->setValid(true, index);
}

template <typename T>
void Manager<T>::writemisstwo(unsigned int ram_address, int n_worker, T value, int index, int element)
{
	int n = ceil(log(ram_address) - log(MAX_BLOCKS));
	T mem;
	//printf("element: %d\n", element);
	if(c[element]->checkTag(index, n)) // Vamos checar a tag para ter certeza de que sao os mesmos valores
	{	
		mem = c[element]->getData(index);
	}
	else
	{
		mem = m[ram_address].getData();
		s.incRead();
	}
	int sinal = c[n_worker]->WRITEMISS(index, value, n);
	/* Apagando todos as caches da cacheList */
	for(int i = 0; i < d->returnNumberOfElements(index); i++)
	{
	//	cout << "VC vem daqui? 6\n";
		element = d->getCacheList(i, index);
		d->removeCacheList(i, index);
	}
	d->setCacheList(n_worker, index);
	d->setStatus(1, index);
	if(sinal == 1)
	{
		d->setDirty(false, index);
		m[ram_address].setData(value);
		s.incWrite();
	}
	else
		d->setDirty(true, index);
	c[n_worker]->setValid(true, index);
}
#endif