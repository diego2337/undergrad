#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int cabeca;
	int requisicao[5];
	int cilindro;
}Resultado;

void init(Resultado *impressao)
{
	int i;
	impressao->cabeca = 0;
	for(i = 0; i < 5; i++)
		impressao->requisicao[i] = 0;
	impressao->cilindro = 0;
}

int cmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int SSTF(int head, int requests[], int j, Resultado *impressao)
{
	int pos = head;
	int cilinder = 0, aux = 0, i = 0, k = 0, y = 0;
	qsort(requests, j, sizeof(int), cmp);
	while(j > 0)
	{
		aux = abs(pos - requests[j-1]); // Maior elemento
		k = j-1;
		for(i = 0; i < j; i++)
		{
			if((pos - requests[i]) < aux && requests[i] != -1 && requests[i] != 0)
			{
				aux = abs(pos -requests[i]);
				k = i;
			}
		}
		cilinder += aux;
		impressao->requisicao[y] = requests[k];
		y++;
		pos = requests[k];
		requests[k] = -1;
		j--;
	}
	impressao->cabeca = pos;
	impressao->cilindro = cilinder;
	return cilinder;
}

int C_LOOK(int head, int requests[], int j, Resultado *impressao)
{
	int pos = head;
	int cilinder = 0, i = 0, z = 0, y = 0;
	qsort(requests, j, sizeof(int), cmp);
	while(pos > requests[i])
		i++;
	if(i == j) // Cabecote e maior que todo mundo; lemos vetor na ordem decrescente entao
	{
		for(i = j-1; i >= 0; i--)
		{
			pos = pos - requests[i];
			cilinder += pos;
			impressao->requisicao[y] = requests[i];
			y++;
			pos = requests[i];
		}
	}
	else // Uma das requisicoes e maior que o valor do cabeçote; entao, vamos fazer dessa posicao (i) ate 0
	{
		z = i;
		for(i -= 1; i >= 0; i--)
		{
			pos = pos - requests[i];
			cilinder += pos;
			impressao->requisicao[y] = requests[i];
			y++;
			pos = requests[i];
		}
		for(i = z; i < j; i++)
		{
			pos = requests[i] - pos;
			cilinder += pos;
			impressao->requisicao[y] = requests[i];
			y++;
			pos = requests[i];
		}
	}
	impressao->cabeca = pos;
	impressao->cilindro = cilinder;
	return cilinder;
}

int C_SCAN(int head, int requests[], int j, Resultado *impressao)
{
	int pos = head;
	int cilinder = 0, i = 0, z = 0, y = 0;
	qsort(requests, j, sizeof(int), cmp);
	while(pos > requests[i])
		i++;
	if(i == j) // Cabecote e maior que todo mundo; lemos vetor na ordem decrescente entao
	{
		for(i = j-1; i >= 0; i--)
		{
			pos = pos - requests[i];
			cilinder += pos;
			impressao->requisicao[y] = requests[i];
			y++;
			pos = requests[i];
		}
	}
	else // Uma das requisicoes e maior que o valor do cabeçote; entao, vamos fazer dessa posicao (i) ate 0
	{
		z = i;
		for(i = i-1; i >= 0; i--)
		{
			pos = pos - requests[i];
			cilinder += pos;
			impressao->requisicao[y] = requests[i];
			y++;
			pos = requests[i];
		}
		if(requests[0] > 0)
		{
			cilinder += requests[0];
		}
		cilinder += 1999;
		pos = 1999;
		for(i = z; i < j; i++)
		{
			pos = pos - requests[i];
			cilinder += pos;
			impressao->requisicao[y] = requests[i];
			y++;
			pos = requests[i];
		}
	}
	impressao->cabeca = pos;
	impressao->cilindro = cilinder;
	return cilinder;
}

int FCFS(int head, int requests[], int j, Resultado *impressao)
{
	int pos = head;
	int cilinder = 0, i;
	int y = 0;
	for(i = 0; i < j; i++)
	{
		pos = pos - requests[i];
		if(pos < 0)
			pos *= -1;
		cilinder += pos;
		impressao->requisicao[y] = requests[i];
		y++;
		pos = requests[i];
	}
	impressao->cabeca = pos;
	impressao->cilindro = cilinder;
	return cilinder;
}

int main(void)
{
	FILE *cabecote, *requisicoes;
	Resultado impressao1, impressao2, impressao3, impressao4;
	int i, z, head, requests[5], result[4], aux = 1000000;
	requisicoes = fopen("requisicoes.txt", "r");
	while(!feof(requisicoes))
	{
		init(&impressao1);
		init(&impressao2);
		init(&impressao3);
		init(&impressao4);
		cabecote = fopen("cabecote.txt", "r");
			fscanf(cabecote, "%d", &head);
		fclose(cabecote);
		for(i = 0; i < 5; i++)
		{
			requests[i] = 0;
		}
		for(i = 0; i < 5 && !feof(requisicoes);  i++)
		{
			fscanf(requisicoes, "%d", &requests[i]);
		}
		//printf("%d", i);
		result[0] = FCFS(head, requests, i, &impressao1); // 552
		result[1] = C_SCAN(head, requests, i, &impressao2); // 3956
		result[2] = C_LOOK(head, requests, i, &impressao3); // 350
		result[3] = SSTF(head, requests, i, &impressao4); // 238
		//printf("\n%d\n", result[1]);
		for(i = 1; i < 4; i++)
		{
			if(result[i] < result[i-1] && result[i] < aux)
			{
				aux = result[i];
				z = i;
			}
		}
		switch(z)
		{
			case 0:
				printf("O algoritmo escolhido foi o FCFS. Resultados:\n");
				printf("Ordem de atendimento das requisições:");
				for(i = 0; i < 5; i++)
					printf(" %d", impressao1.requisicao[i]);
				printf("\n");
				printf("Quantidade de cilindros percorridos: ");
				printf("%d\n", impressao1.cilindro);
				printf("Posição do cabeçote de leitura após requisições: ");
				printf("%d\n\n", impressao1.cabeca);
				cabecote = fopen("cabecote.txt", "w");
					fprintf(cabecote, "%d", impressao1.cabeca);
				fclose(cabecote);
				break;
			case 1:
				printf("O algoritmo escolhido foi o C_SCAN. Resultados:\n");
				printf("Ordem de atendimento das requisições:");
				for(i = 0; i < 5; i++)
					printf(" %d", impressao2.requisicao[i]);
				printf("\n");
				printf("Quantidade de cilindros percorridos: ");
				printf("%d\n", impressao2.cilindro);
				printf("Posição do cabeçote de leitura após requisições: ");
				printf("%d\n\n", impressao2.cabeca);
				cabecote = fopen("cabecote.txt", "w");
					fprintf(cabecote, "%d", impressao2.cabeca);
				fclose(cabecote);
				break;
			case 2:
				printf("O algoritmo escolhido foi o C_LOOK. Resultados:\n");
				printf("Ordem de atendimento das requisições:");
				for(i = 0; i < 5; i++)
					printf(" %d", impressao3.requisicao[i]);
				printf("\n");
				printf("Quantidade de cilindros percorridos: ");
				printf("%d\n", impressao3.cilindro);
				printf("Posição do cabeçote de leitura após requisições: ");
				printf("%d\n\n", impressao3.cabeca);
				cabecote = fopen("cabecote.txt", "w");
					fprintf(cabecote, "%d", impressao3.cabeca);
				fclose(cabecote);
				break;
			case 3:
				printf("O algoritmo escolhido foi o SSTF. Resultados:\n");
				printf("Ordem de atendimento das requisições:");
				for(i = 0; i < 5; i++)
					printf(" %d", impressao4.requisicao[i]);
				printf("\n");
				printf("Quantidade de cilindros percorridos: ");
				printf("%d\n", impressao4.cilindro);
				printf("Posição do cabeçote de leitura após requisições: ");
				printf("%d\n\n", impressao4.cabeca);
				cabecote = fopen("cabecote.txt", "w");
					fprintf(cabecote, "%d", impressao4.cabeca);
				fclose(cabecote);
				break;
		}
	}
	fclose(requisicoes);
}