// Programa: Fatorial.c
// Programador: Diego Cintra
// Data: 29 de outubro de 2012
// O dialogo: Esse programa ira receber um numero n e achar seu fatorial.
// Declaracao das funcoes
#include<stdio.h> // scanf, printf

// Inicio da funcao fatorial
int fatorial(int n)
{
	// O dialogo: Essa funcao ira ler um numero n e retornar seu fatorial.
	// Declaracao das variaveis
	int result;
	if(n <= 1)
	{
		result = 1;
	}
	else
	{
		result = n * fatorial(n-1);
	}
	// printf("%d\n", result);
	return result;
} // Fim da funcao fatorial

// Inicio da funcao main
int main(void)
{
	// Declaracao das variaveis
	int n;
	// Passo 1: Insira o numero n
	scanf("%d", &n);
	// Passo 2: Ache o fatorial desse numero
	fatorial(n);
	// Passo 3: Imprima o resultado
	printf("%d\n", fatorial(n));
return 0;
} // Fim da funcao main
