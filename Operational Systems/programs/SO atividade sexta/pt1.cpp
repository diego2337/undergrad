#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entrada_diretorio
{
	char nome_arquivo[8];
	char extensao[3];
	short int first_cluster;
	int tamanho;
};

void findi(short int FAT[], short int iesimo, short int cluster)
{
	int counter = 1;
	while(counter != iesimo)
	{
		cluster = FAT[cluster];
		counter++;
	}
	cout << cluster;
	cout << "\n";

}

void printblocks(short int cluster, short int FAT[])
{
	if(cluster == -1)
		return;
	printf("%d ", cluster);
	cluster = FAT[cluster];
	printblocks(cluster, FAT);
}

void search_file(char* nome_file, int b, char o, entrada_diretorio diretorio[], short int FAT[], short int iesimo)
{
	short int cluster;
	bool x = false;
	for(int i = 0; i < b; i++)
	{
		if(strcmp(diretorio[i].nome_arquivo, nome_file) == 0)
		{
			cluster = diretorio[i].first_cluster;
			if(o == 'a' || o == 'A')
				printblocks(cluster, FAT);
			else
				findi(FAT, iesimo, cluster);
			cout << "\n";
			x = true;
		}
	}
	if(x == false)
		cout << "Arquivo nao encontrado. \n";
}

int main(void)
{
	int b, n;
	char o = 'x';
	char nome_file[8];
	FILE* atual;
	entrada_diretorio diretorio[100];
	cout << "Digite a quantidade total de blocos de disco: ";
	cin >> b;
	cout << "\n";
	short int FAT[b], iesimo;
	cout << "Digite a quantidade total de arquivos no disco: ";
	cin >> n;
	cout << "\n";
	cout << "Digite o nome e o endereço inicial dos arquivos: ";
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		scanf("%s %hd", diretorio[i].nome_arquivo, &diretorio[i].first_cluster);
	}
	/*	for(int i = 0; i < n; i++)
	{
		printf("%s %d", diretorio[i].nome_arquivo, diretorio[i].first_cluster);
	}*/
	atual = fopen("atual.fat", "r");
	for(int i = 0; i < b; i++)
		fscanf(atual, "%hd", &FAT[i]);
	fclose(atual);
	while(o != 'c' && o != 'C')
	{
		cout << "Escolha 'a', 'b' ou 'c' para uma das opçoes seguintes: ";
		cout << "\n";
		cout << "a) Listar os blocos de disco de um arquivo; ";
		cout << "\n";
		cout << "b) Encontrar no disco o endereco do i-esimo bloco logico; \n";
		cout << "c) Sair do programa.";
		cout << "\nDigite a opção desejada: ";
		cin >> o;
		//if(o != 'a' && o != 'A' && o != 'b' && o != 'B')
		//	cout << "Opçao invalida. Tente novamente. \n";
		if(o == 'A' || o == 'a')
		{
			cout << "Digite o nome do arquivo: ";
			scanf("%s", nome_file);
			search_file(nome_file, b, o, diretorio, FAT, iesimo);
			cout << "\n";

		}	
		else if(o == 'B' || o == 'b')
		{
			cout << "Digite o nome do arquivo: ";
			scanf("%s", nome_file); 
			cout << "Digite a i-ésima posiçao do endereço logico: ";
			scanf("%hd", &iesimo);
			search_file(nome_file, b, o, diretorio, FAT, iesimo);
			cout << "\n";
		}
		else if(o != 'c' && o != 'C')
			cout << "Opçao invalida. Tente novamente. \n\n";
	} // fim while
	return 0;
}