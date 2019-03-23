/*Programa: Bisseccao.c
Alunos: Aimée S. Calepso, Diego Cintra e Rogério Sandim
Descrição: O programa irá realizar o método da bissecção para a funcão: x³-9x+3, até a precisão requerida.*/

// Declaracao das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/* Essa funcao ira fazer o calculo de f(x) = x³ -9x + 3*/
double f(double a)
{
	return(pow (a, 3.0) - 9*a + 3);
}

int main(void)
{
	// Declaracao das variaveis
	double epsilon = 0.001; // Armazena o valor da precisao
	double a = 0, b = 1, x, ab; // Correspondentes a "a", "b" e "x" do metodo da bisseccao. "ab" ira receber o resultado de "b-a"
	double N, M; // Armazenam f(x) e f(a), respectivamente
	int k = 0, N0 = 1000; // k corresponde ao numero de iteracoes e N0 ao numero maximo de iteracoes
	M = f(a);  
	while(k <= N0)
	{
		x = (a+b)/2;
		N = f(x);
		if(N == 0 || (b-a)/2 < epsilon)
		{
			k++;
			printf("\n%d           %lf          %lf          %lf    ", k, x, N, b);
			printf("\nSolução aproximada: %lf\n", x);
			exit(1);
		}
		k++;
		if(M*N > 0)
		{
			a = x;
			M = N;
		}
		else
		{
			b = x;
		}
		ab = b-a;
		if(k == 1)
		{
			printf("ITERACAO |      X      |        f(X)        |       b-a      ");
		}
		printf("\n%d           %lf          %lf          %lf    ", k, x, N, ab);
	}
	printf("\nO método da bissecção falhou.\n");
	return 0;
}