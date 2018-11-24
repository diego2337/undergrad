// Programa: hotel.c
// Programador: Diego Cintra
// Data: 05/02/2013
// O dialogo: Esse programa ira fazer o gerenciamento de um hotel - listando os quartos disponiveis, fazendo check-in ou check-out.

#include "hotel.h"

void date(char tempo[50])
{
	// Armazenando a data atual
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(tempo, 50, "%Y%m%d", timeinfo);
}


int compare(const void *a, const void *b)
{
	return ((*(int*)a) - (*(int *)b));
}

int compare2(const void *a, const void *b)
{
	return strcmp(a, b);
}
void sorting(FILE *quartos, qtxt aux[200], int *counter)
{
	// Devemos ordenar o arquivo .txt, caso necessite da busca binaria.
	quartos = fopen("quartos.txt", "r");
		rewind(quartos);
		while(!feof(quartos))
		{
			fscanf(quartos, "%d %d\n",  &aux[*counter].numquarto, &aux[*counter].index2);
			*counter = *counter + 1;
			//printf("hey ho lets go5\n");
		}
		fclose(quartos);
}
	
void sorting2(FILE *nomes, ntxt aux2[200], int *counter)
{
	// Devemos ordenar o arquivo .txt, caso necessite da busca binaria.
	nomes = fopen("nomes.txt", "r");
		rewind(nomes);
		while(!feof(nomes))
		{
			fscanf(nomes, "%s %d\n",  aux2[*counter].nompess, &aux2[*counter].index3);
			*counter = *counter + 1;
		}
		fclose(nomes);
}

void cadastro(quarto cadastro, int numquarto, int type, char date[20], char name[200])
{

	// char temp[200];
	int counter2 = 0, i, counterx = 0;
	qtxt aux[200];
	ntxt aux2[200];
	// strcpy(temp, name); 
	FILE *hotelbin, *quartos, *nomes;
	int barq, bstruct, index;
	// Armazenando o cadastro na struct
	strcpy(cadastro.nome, name);
	cadastro.numero_quarto = numquarto;
	strcpy(date, cadastro.data_check_in);
	cadastro.data_check_out = 0;
	cadastro.tipo_quarto = type;
	cadastro.ocupado = 1;
	hotelbin = fopen("hotel.bin", "a+b");

		// Iremos descobrir o tamanho (em bytes) dos arquivos hotel.bin e quarto.txt. Dividindo os dois saberemos, atraves do quociente, em qual posicao o cadastro ficara.
		fseek(hotelbin, 0, SEEK_END);
		bstruct = sizeof(quarto);
		barq = ftell(hotelbin);
		if(barq == 0)
		index = 0;
		else if(barq == bstruct)
		index = 1;
		else
		index = barq/bstruct;
		fwrite(&cadastro, sizeof(quarto), 1, hotelbin);
		fclose(hotelbin);
	
	// Agora iremos escrever os dados em quartos.txt e nomes.txt.
	quartos = fopen("quartos.txt", "a+b");
		fprintf(quartos, "%d %d\n", numquarto, index);
		fclose(quartos);

	sorting(quartos, aux, &counterx);


	qsort(aux, counterx, sizeof(qtxt), compare);

	quartos = fopen("quartos.txt", "w+");
		for(i = 0; i < counterx; i++)
		{
			fprintf(quartos, "%d %d\n",  aux[i].numquarto, aux[i].index2);
		}
		fclose(quartos);
		
	nomes = fopen("nomes.txt", "a+b");
		fprintf(nomes, "%s %d\n", name, index);
		fclose(nomes);
	
	sorting2(nomes, aux2, &counter2);
	
	qsort(aux2, counter2, sizeof(ntxt), compare2);

	nomes = fopen("nomes.txt", "w+");
	for(i = 0; i < counter2; i++)
	{
		fprintf(nomes, "%s %d\n", aux2[i].nompess, aux2[i].index3);
	}
	fclose(nomes);
		
}

int bbinstring(char nameroom[200], int lines2, ntxt aux2[50], int *bin)
{
	int esq, dir, meio;
	esq = -1;
	dir = lines2;
	while(esq < dir-1)
	{
		meio = (esq+dir)/2;
		if(strcmp(aux2[meio].nompess, nameroom) < 0)
		{
			esq = meio;
		}
		else
		{
			dir = meio;
		}
	}
	if(strcmp(aux2[dir].nompess, nameroom) == 0)
	{
		*bin = aux2[dir].index3;
		return 1;
	}
	else
	return -1;
}
int bbin(int nameroom, int lines, qtxt aux[20], int *p, int *bin)
{
	int esq, dir, meio;
	//FILE *quartos;
	//FILE *nomes;
	esq = -1;
	dir = lines;
	while(esq < dir-1)
	{
		meio = (esq+dir)/2;
		if(aux[meio].numquarto < nameroom)
		{
			esq = meio;
		}
		else
		{
			dir = meio;
		}
	}
	if(aux[dir].numquarto == nameroom)
	{
		*p = aux[dir].index2;
		*bin = dir;
		return dir;
	}
	else
	return -1;
}

