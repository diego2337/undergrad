#include<stdio.h>
// Programa: labirinto2.c
// Programador: Diego Cintra
// Data: 16/11/2012
// O dialogo: Esse programa ira achar uma saida para Joao dentro de um labirinto, onde 0 e um caminho intransponivel e 1 e a passagem.
int valido(int an, int am, int n, int m, char maze[20][20])
{
	int ret = 0;
	if(an < n && am < m && an >= 0 && am >= 0)
	{
		if(maze[an][am] == '1')
		ret = 1;
	}
	return ret;
}
void procura(int an, int am, char maze[20][20], int n, int m)
{
	int j, k;
	if(an == n - 1 && am == m - 1)
	{
		maze[an][am] = 'x';
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < m; k++)
			{
				printf("%c", maze[j][k]);
			}
			printf("\n");
		}
		return;
	}
	else
	{
		maze[an][am] = 'x';
		if(valido(an, am+1, n, m, maze))
		{
			procura(an, am+1, maze, n, m);
			
		}
		if(valido(an+1, am, n, m, maze))
		{
			procura(an+1, am, maze, n, m);
			
		}
		if(valido(an, am-1, n, m, maze))
		{
			procura(an, am-1, maze, n, m);
			
		}
		if(valido(an-1, am, n, m, maze))
		{
			procura(an-1, am, maze, n, m);
			
		}
	}
	maze[an][am] = '1';
}
int main(void)
{
	int i, rep, j, k, n, m;
	int an = 0, am = 0; // posicao do joao
	char maze[20][20];
	scanf("%d ", &rep);
	for(i = 0; i < rep; i++)
	{
		scanf("%d %d ", &n, &m); // dimensao da matriz
		for(j = 0; j < n; j++)
		{
			printf("j = %d\n", j);
			for(k = 0; k < m; k++)
			{
				printf("k = %d\n", k);
				scanf("%c ", &maze[j][k]); // declarando o labirinto
			}
		}
		procura(an, am, maze, n, m);   // chamada da funcao
		
	}
	return 0;
}
