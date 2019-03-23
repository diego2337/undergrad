/* Alunos: Diego Cintra e Rogério Sandim */
#include "Manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(void)
{
	FILE *in;
	unsigned int MAX_RAM;
	int WORD, MAX_BLOCKS, N_WORKER;
	in = fopen("input1.txt", "r");
	cout << "\n\nBem vindo! Esse programa irá simular um comportamento de caches de processadores, ";  
	cout << "utilizando políticas de escrita 'Writethrough' e 'Writeback'. Nas próximas 4 requisições,";
	cout << " insira, respectivamente, o valor de endereçamento (para cache e memória principal), o ";
	cout << "número máximo de blocos da memória principal, o número máximo de blocos da memória cache e";
	cout << " o número de processadores presente no simulador (e, consequentemente, o número de caches";
	cout << " do sistema). Tenha em mente que todas as caches estão inicialmente vazias, e os valores";
	cout << " armazenados na memória principal são NULL. Agora, por favor, insira os valores: \n\n";
	fscanf(in, "%d", &WORD);
	fscanf(in, "%u", &MAX_RAM);
	fscanf(in, "%d", &MAX_BLOCKS);
	fscanf(in, "%d", &N_WORKER);
	if(WORD == 8)
	{
		Manager<uint8_t> m(MAX_RAM, MAX_BLOCKS, N_WORKER);
		m.simulatesystem(); // Da maneira implementada acima, esse método nao fara nada
		m.startSimulation(in);
	}
	else if(WORD == 16)
	{
		Manager<uint8_t> m(MAX_RAM, MAX_BLOCKS, N_WORKER);
		m.simulatesystem();
		m.startSimulation(in);
	}
	else if(WORD == 32)
	{
		Manager<uint8_t> m(MAX_RAM, MAX_BLOCKS, N_WORKER);
		m.simulatesystem();
		m.startSimulation(in);
	}
	else
	{
		cout << "\nTente 8, 16 ou 32 para valores de endereçamento.\n";
		exit(1);
	}
}