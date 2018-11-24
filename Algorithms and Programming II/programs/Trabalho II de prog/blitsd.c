/* Alunos: Diego Cintra e Rogerio Sandim */
#include "listad.h"
int main(void)
{
	/*stdin = fopen("blits.in", "r");*/
	char indice;
	Lista L;
	tipo carro;
	tlista *aux;
	  clock_t antes, agora;
 antes=clock();
	init(&L); // segmentation fault point
	while(scanf("%c", &indice) == 1)
	{
		if(indice == 'r')
		{
			scanf ("%s %d %s %s %s", carro.placa, &carro.ano, carro.marca, carro.modelo, carro.estado);
			if(busca(&L, carro, &aux))
			{
				printf("carro (%s %d %s %s %s) ja foi cadastrado.\n",carro.placa, carro.ano, carro.marca, carro.modelo, carro.estado);
			}
			else
			{
				insere(&L,carro);
				printf("carro (%s %d %s %s %s) roubado.\n", carro.placa, carro.ano, carro.marca, carro.modelo, carro.estado);
			}
		}
		else if(indice == 'a')
		{
				scanf("%s",carro.placa);
		
			if(busca(&L, carro, &aux))
			{
				remover (&L, carro);
				printf("carro (%s %d %s %s %s) recuperado.\n", carro.placa, aux->val.ano, aux->val.marca, aux->val.modelo, aux->val.estado);
			}
			else
			{
				printf("carro %s nao consta na base de dados.\n", carro.placa);
			}
		}
		else if(indice == 'c')
		{
			scanf ("%s", carro.placa);
			if(busca (&L, carro, &aux))
			{
				printf("carro (%s %d %s %s %s) eh um carro roubado, prender motorista.\n", carro.placa, aux->val.ano, aux->val.marca, aux->val.modelo, aux->val.estado);
			}
			else
			{
				printf("carro %s NAO eh um carro roubado, liberar motorista.\n", carro.placa);
			}
		}
	}
 
 agora=clock();
 printf("%g\n", ((double)agora-antes)/CLOCKS_PER_SEC);

	return 0;
}
