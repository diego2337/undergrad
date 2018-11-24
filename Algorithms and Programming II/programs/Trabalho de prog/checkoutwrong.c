// Programa: checkout.c
// Programador: Diego Cintra
// Data: 06/02/2013
// O dialogo: Esse programa, sendo uma subrotina do arquivo hotel.c, ira efetuar o check-out de uma pessoa de um hotel.
#include "hotel.h"
int checkout(char name[200])
{
	FILE *quartos;
	FILE *nomes;
	FILE *hotelbin;
	ntxt aux2[200];
	int i = 0, r = -1, j;
	// Devemos ter certeza de que a pessoa que quer fazer checkout realmente esta no hotel.
	/*if(pesquisar("pessoa", name) == -1)
	{
		printf("Essa pessoa não foi cadastrada no hotel.\n");
		return 0;
	}*/
	//else
	//{
		// Iremos agora apagar o cadastro dessa pessoa dos arquivos .txt e do .bin.
		nomes = fopen("nomes.txt", "r");
		rewind(nomes);
		printf("hey ho lets go\n");
			while(!feof(nomes))
			{
				printf("hey ho lets go2\n");
				fscanf(nomes, "%s %d\n", aux2[i].nompess, &aux2[i].index3);
				if(strcmp(aux2[i].nompess, name) == 0)
				{
					r = i;
				}
				i++;
			}
			printf("hey ho lets go3\n");
		rewind(nomes);
		for (j = r; j < i; j += 1)
		{
			printf("hey ho lets go4\n");
				strcpy(aux2[j].nompess, aux2[j+1].nompess);
				aux2[j].index3 = aux2[j+1].index3;
		}
			printf("hey ho lets go5\n");
		for (j = 0; j < i; j += 1)
		{
					printf("%s %d\n", aux2[j].nompess, aux2[j].index3);
		}
		/*
		nomes = fopen("nomes.txt", "a+b");
			rewind(nomes);
			j = 0;
			while(!feof(nomes))
			{
				fprintf(nomes, "%s %d\n", aux2[j].nompess, aux2[j].index3);
				j++;
			}
			fclose(nomes);*/
//	}
	return 0;
}
