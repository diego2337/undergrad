// Programa: biblioteca.c
// Programador: Diego Cintra
// Data: 30/06/2012
// O dialogo: Esse programa ira ler o titulo do livro e procura-lo numa lista pre-determinada de livros existentes.
// Declaracao das bibliotecas
#include<stdio.h> // printf, scanf
#include<string.h>
#include<stdbool.h>
// Declaracao de tipos
typedef struct
{
    char livro[50];
    char autor[50];
    int prat;
}
DADOS;
typedef DADOS LIVRO[50];
// Inicio da funcao main
int main(void)
{
    // Declaracao das variaveis
    int numlivros, i, j, k, livros, pos;
    LIVRO nomelivro;
    char nome[50];
    bool encontrou;
    // Passo 1: Insira o numero de livros existentes
    scanf("%d", &numlivros);
    // Passo 2: Insira o nome dos livros
    for(i = 0; i < numlivros; i++)
    {
        scanf("%s", nomelivro[i].livro);
        scanf("%s", nomelivro[i].autor);
        scanf("%s", nomelivro[i].prat);
    }
    // Passo 3: Diga quantos livros ira procurar
    scanf("%d", &livros);
    for(j = 0; j < livros; j++)
    {
            // Passo 4: Insira o livro que ira procurar
            scanf("%s", nome);

        // Passo 5: Procure-o
        encontrou = false;
        for(k = 0; k < numlivros && !encontrou; k++)
        {
            if(strcmp(nome, nomelivro[k].livro) == 0)
            {
                encontrou = true;
                pos = k;
            }
        }
        // Passo 6: Imprima os resultados
        if(encontrou)
        printf("%c %d\n", nomelivro[pos].livro, nomelivro[pos].prat);
        else
        printf("-1\n");
    }
    return 0;
} // Fim da funcao main
