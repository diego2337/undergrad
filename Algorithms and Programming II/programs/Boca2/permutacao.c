#include<stdio.h>
// Programa: permutacao.c
// Programador: Diego Cintra
// Data: 16/11/2012
// O dialogo: Esse programa ira calcular a k-esima permutacao de um vetor.
void perm(char V[], char ini, char fim)
{
	int i;
	char aux;
	if(ini == fim)
	{
		for(i = 0; i < t; i++)
		printf("%d", V[i]);
	}
	else
	{
		for(i = ini; i <= fim; i++)
		{
			aux = V[i];
			V[i] = V[ini];
			V[ini] = aux;
			perm(V, ini-1, fim);
			aux = V[i];
			V[i] = V[ini];
			V[ini] = aux;
		}
	}
}

int main(void)
{
	int f, 
}
