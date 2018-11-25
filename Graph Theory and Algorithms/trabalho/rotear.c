/* Aluno: Diego Cintra */
/* Programa: rotear.c */
/* Descrição: Esse programa tem a finalidade de achar o caminho mínimo entre dois vértices, que representam cruzamentos de ruas
 em um mapa. Ele utiliza do algoritmo de Dijsktra para calcular a distância mínima. Para uma otimização de tempo, o mesmo
 foi implementado não só com o algoritmo de Dijkstra, como também com o algoritmo de Dijkstra alternado e o algoritmo de Dijkstra com
 limitantes (método heurístico). */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define PI 3.141592653589793

typedef struct{
	char Nvertice;
	int numvertice;
	double latitude;
	double longitude;
	int neighborhood;
	int *nneighbor;
	double *nweight;
}grafo;

typedef struct{
	int vertice;
	double weight;
}peso;


/*Codigos da heap, necessarios para execuçao eficiente do dijkstra*/


/*Retorna o pai de i*/
int pai(int i)
{
	int r;
	if(i == 0)
	r = 0;
	else
	r = (i-1)/2;
	return r;
}

/*Retorna o filho direito de i*/
int dir(int i)
{
	return 2*(i + 1);
}

/*Retorna o filho esquerdo de i*/
int esq(int i)
{
	return (2*(i+1)-1);
}

/*Funcao que mantem a condiçao "min-heap" para a heap em questao*/
void sobe(peso V[], int i)
{
	peso aux;
	while(V[pai(i)].weight > V[i].weight)
	{
		aux = V[pai(i)];
		V[pai(i)] = V[i];
		V[i] = aux;
		i = pai(i);
	}	
}

/*Insere na heap um novo elemento*/
void insere(int *n, peso V[], double X, int currentneighbor)
{
	*n = *n + 1;
	V[*n-1].weight = X;
 	V[*n-1].vertice = currentneighbor;
	sobe(V, *n-1);
}

/*Funcao que mantem a condiçao "min-heap" para a heap em questao*/
void desce(int n, peso V[], int i)
{
	int e, d, maior;
	peso aux;
	e = esq(i);
	d = dir(i);
	maior = i;
	if(e < n && V[e].weight < V[maior].weight) 
	maior = e;
	if(d < n && V[d].weight < V[maior].weight)
	maior = d;
	if(i != maior)
	{
		aux = V[maior];
		V[maior] = V[i];
		V[i] = aux;
		desce(n, V, maior);
	}
}

/*Funçao que cria a heap*/
void cheap(int n, peso V[])
{
	int i;
	i = pai(n-1);
	while(i >= 0)
	{
		desce(n, V, i);
		i--;
	}
}

/*Recebe a prioridade p e insere ela na posicao i*/
void diminui_prioridade(int n, peso H[], int i, double p)
{
  if (p > H[i].weight)
    printf("Nova prioridade é maior que existente\n");
  else {
    H[i].weight = p;
    sobe(H, i);
  }
}

/*Procura na heap um numero (vertice)*/
int heapsearch(peso H[], int n, int search)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(H[i].vertice == search)
			return i;
	}
	return -1;
}

/*Remove da heap o menor elemento (menor prioridade) e retorna-o (caso a heap tenha pelo menos 1 elemento)*/
int find_smallest(int *n, peso H[])
{
  int menor;
  if(*n > 0)
  {
    menor = H[0].vertice;
    H[0] = H[*n - 1];
    *n = *n - 1;
    desce(*n, H, 0);
    return menor;
  }
  else
    return -1;
}

/*-----------------------------------------------------------------------------------------------------------------------------*/


/*A funcao caminho utiliza recursividade para imprimir o caminho em ordem crescente*/
void caminho(int origem, int destino, int *previous, double *distance)
{
	//printf("entrou aqui!!! %d %d\n", origem, destino);
	if(destino != origem)
		caminho(origem, previous[destino-1], previous, distance);
	printf("%d %.3lf ", destino, distance[destino-1]);
}


/*Essa funcao e para o caso do dijkstra alternado, onde, seguindo as restriçoes do trabalho, deve-se imprimir o primeiro dijsktra
em ordem crescente (ate o meio) e o segundo dijkstra em ordem decrescente (a partir do meio) ate o destino*/
void ohnimac(int origem, int destino, int *previous, double *distance)
{
	while(origem != destino)
	{
		printf("%d %.3lf ", origem, distance[origem-1]);
		origem = previous[origem-1];
	}
}


/*Funcao que procura um vertice no grafo*/
int search(grafo *R, int search, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(R[i].numvertice == search)
			return i;
	}
	return -1;
}


/*Essa funcao cria um novo grafo R, inverso de G*/
void ofarg(grafo *R, grafo *G, int n)
{
	int i, j, k, indice;
	for(i = 0; i < n; i++) // inicializaremos o grafo so para garantir que ele nao armazene lixo
	{
		R[i].Nvertice = 'N';
		R[i].numvertice = 0;
		R[i].latitude = 0;
		R[i].longitude = 0;
		R[i].neighborhood = 0;
	}
	for(i = 0; i < n; i++)
	{
		k = 0;
			for(j = 0; j < G[i].neighborhood; j++)
			{
				indice = G[i].nneighbor[j]; // para poder armazenar no grafo R na mesma posiçao do vertice
				R[indice-1].numvertice = indice; // inserindo no grafo R o vertice em sua respectiva posicao - como
				// ele é inverso, o vertice ira mudar de orientaçao
				R[indice-1].neighborhood = R[indice-1].neighborhood + 1; // toda vez que precisarmos mudar alguma
				// orientacao relacionada com esse vertice (ou seja, se encontrarmos vizinhos dele em futuras iteraçoes),
				// temos que incrementar o numero de vizinhos
				if(R[indice-1].neighborhood == 1)
				{
					k = R[indice-1].neighborhood - 1; /* necessario para, quando realocarmos o numero de vizinhos de vizinhos 
					de um vertice, ele nao sobreponha algum outro vizinho desse vertice*/
					R[indice-1].nneighbor = (int*)malloc (R[indice-1].neighborhood*(sizeof(int)));
					R[indice-1].nweight = (double*)malloc (R[indice-1].neighborhood*(sizeof(double)));
				}
				else
				{
				    k = R[indice-1].neighborhood - 1;
					R[indice-1].nneighbor = (int*)realloc (R[indice-1].nneighbor, R[indice-1].neighborhood*(sizeof(int)));
					R[indice-1].nweight = (double*)realloc (R[indice-1].nweight, R[indice-1].neighborhood*(sizeof(double)));	
				}
				// vamos entao atribuir os vizinhos desse nosso novo vertice
				for(k = k; k < R[indice-1].neighborhood; k++) 
				{
					R[indice-1].nneighbor[k] = G[i].numvertice;
					R[indice-1].nweight[k] = G[i].nweight[j];
				}
				// atribuindo as coordenadas desse novo vertice
				R[indice-1].latitude = G[indice-1].latitude;
				R[indice-1].longitude = G[indice-1].longitude;
			}
		
	}
}

void doubledijkstra(grafo *G, int origem, int destino, int n)
{
	/*O algoritmo de dijkstra alternado constroi um grafo inverso de G e faz um dijkstra que e executado a partir do destino. Note que
	o dijkstra que comeca pela origem tambem e executado, utilizando o grafo original G. Para tal algoritmo, e necessario duplicar 
	a maioria das variaveis trabalhada ate entao - o peso (distance), predecessor (previous), visitado e as heaps. quando eles 
	acharem um mesmo vertice visitado nos dois vetores criados, entao a expansao das duas arvores se encontraram e o algoritmo e 
	finalizado. O dijkstra alternado visa aumentar ainda mais a velocidade da execuçao do dijkstra.*/

	/* Declaraçao das duas Heaps (HE e HD) e dos respectivos vetores para cada*/
	double distanceE[n];
	double distanceD[n];
	double distanceED;
	int previousE[n];
	int previousD[n];
	bool visitadoE[n];
	bool visitadoD[n];
	int i, v, middle, n1, n2, counter = 1;
	int check; // para verificar se o vizinho esta na heap
	int currentneighbor;
	n1 = n;
	n2 = n;
	int n3 = n2;
	peso HE[n1];
	peso HD[n2];
	grafo R[n];
	for(i = 0; i < n; i++)
	{
		distanceE[i] = 1000000000;
		distanceD[i] = 1000000000;
		previousE[i] = -1; // indefinido
		previousD[i] = -1;
		visitadoE[i] = false;
		visitadoD[i] = false;
	}
	ofarg(R, G, n); // invertendo o grafo G
	distanceE[origem-1] = 0;
	distanceD[destino-1] = 0;
	HE[0].vertice = origem;
	HE[0].weight = 0;
	n1 = 1; // n1 corresponde ao numero de elementos da HE
	HD[0].vertice = destino;
	HD[0].weight = 0;
	n2 = 1; // n2 corresponde ao numero de elementos da HD
	cheap(n1, HE);
	cheap(n2, HD);
	middle = 0; // o vertice onde os dijkstras se encontram
	while(n1 > 0 && n2 > 0 && visitadoE[destino-1] == false && visitadoD[origem-1] == false)
	{
		if(HE[0].weight <= HD[0].weight) // primeiro comparamos qual heap esta com menor topo
		{
			v = find_smallest(&n1, HE);
			v--;
			visitadoE[v] = true;
			if(visitadoD[v] == true) // se ambos foram visitados os dijkstras se encontraram; a funçao deve ser terminada
			{
				middle = v;
				break;
			}
			// os procedimentos a seguir sao similares ao do dijkstra (ja comentado)
			for(i = 0; i < G[v].neighborhood; i++)
			{
				currentneighbor = G[v].nneighbor[i];
				if(distanceE[currentneighbor-1] > distanceE[v] + G[v].nweight[i] && visitadoE[currentneighbor-1] == false)
				{
					distanceE[currentneighbor-1] = distanceE[v] + G[v].nweight[i];
					previousE[currentneighbor-1] = v+1; 
					check = heapsearch(HE, n1, currentneighbor);
					if(check > -1)
						diminui_prioridade(n1, HE, check, distanceE[currentneighbor-1]);
					else
						insere(&n1, HE, distanceE[currentneighbor-1], currentneighbor);
					//printf("\n%d\n", n2);
				}
			}
		}
		else // caso a HD tenha o topo maior
		{
			v = find_smallest(&n2, HD);
			v--;
			visitadoD[v] = true;
			if(visitadoE[v] == true) // novamente, se ambos foram visitados os dijkstras se encontraram; a funçao deve ser terminada
			{
				middle = v;
				break;
			}
			// novamente, os procedimentos a seguir sao similares ao do dijkstra (ja comentado)
			for(i = 0; i < R[v].neighborhood; i++)
			{
				currentneighbor = R[v].nneighbor[i];
				if(distanceD[currentneighbor-1] > distanceD[v] + R[v].nweight[i] && visitadoD[currentneighbor-1] == false)
				{
					distanceD[currentneighbor-1] = distanceD[v] + R[v].nweight[i];
					previousD[currentneighbor-1] = v+1; 
					check = heapsearch(HD, n2, currentneighbor);
					if(check > -1)
						diminui_prioridade(n2, HD, check, distanceD[currentneighbor-1]);
					else
						insere(&n2, HD, distanceD[currentneighbor-1], currentneighbor);
				}
			}
		}
		counter++; // armazenando o numero de vertices visitados
	} // fim do while
	if(middle != 0) // possiveis caminhos mais eficientes do que o encontrado
	{
		distanceED = distanceE[middle] + distanceD[middle];
		for(i = 0; i < n1; i++)
		{
			if(HE[i].weight + distanceD[HE[i].vertice-1] < distanceED)
			{
				middle = HE[i].vertice-1;
				distanceED = HE[i].weight + distanceD[HE[i].vertice-1];
			}
		}
		for(i = 0; i < n2; i++)
		{
			if(HD[i].weight + distanceE[HD[i].vertice-1] < distanceED)
			{
				middle = HD[i].vertice-1;
				distanceED = HD[i].weight + distanceE[HD[i].vertice-1];
			}
		}
	}
	// caso ele encontre o caminho
	if(distanceED != 0 && distanceED != 1000000000.000)
	{
		printf("1 %.3f \n", distanceED); 
		caminho(origem, middle+1, previousE, distanceE);
		ohnimac(middle+1, destino, previousD, distanceD);
		printf("%d %.3lf", destino, distanceD[destino-1]);
		printf("\n");
		printf("%d\n", counter);
	}
	// caso ele nao encontre o caminho
	else
	{
		printf("0 0.000\n");
		printf("%d 0.000 %d 0.000\n", origem, destino);
		printf("%d\n", counter-1);
	}
}


/*A funcao radius converte graus para radianos*/
double radius(double coordenada)
{
	// a conversao de graus para radianos e feita atraves de uma simples regra de tres
	double z;
	coordenada = coordenada * PI;
	z = coordenada / 180;
	return z;
}


/*A funcao limits calcula uma aproximacao entre a distancia de dois pontos, usando suas coordenadas (latitude e longitude) 
e o raio da Terra*/
double limits(grafo L[])
{
	double R = 6356.75; // o raio da terra (informado pela descriçao do trabalho)
	double rdistance; // armazenara o resultado final
	double x, y;
	double long2, long1, lat2, lat1; // as latitudes e longitudes que converteremos para radiano
	long2 = radius(L[1].longitude);
	lat2 = radius(L[1].latitude);
	long1 = radius(L[0].longitude);
	lat1 = radius(L[0].latitude);
	x = (long2 - long1) * cos((lat1+lat2)/2);
	y = (lat2 - lat1);
	rdistance = R * (sqrt((x*x) + (y*y)));
	return rdistance;
}

void aStar(grafo *G, int origem, int destino, int n)
{
	/*A execuçao desse algoritmo e similar ao do dijkstra, portanto a maior parte das linhas executadas recebem a mesma observaçao.
	O grande diferencial desse algoritmo, entretanto, e que ele atinge uma melhor performance de tempo, atraves da utilizaçao de
	heuristica.*/

	double distance[n];
	int previous[n];
	double limitante[n];
	bool visitado[n];
	int i, v, counter = 1;
	int check; // para verificar se o vizinho esta na heap
	double R; // ira armazenar a distancia da funcao limits
	int currentneighbor;
	peso H[n];
	grafo L[3];
	for(i = 0; i < n; i++)
	{
		distance[i] = 1000000000;
		previous[i] = -1; // indefinido
		limitante[i] = 1000000000;
		visitado[i] = false;
	}
	H[0].vertice = origem;
	H[0].weight = 0;
	n = 1;
	cheap(n, H);
	distance[origem-1] = 0;
	while(n > 0 && visitado[destino-1] == false)
	{
		v = find_smallest(&n, H);
		v--;
		visitado[v] = true;
		for(i = 0; i < G[v].neighborhood; i++)
		{
			currentneighbor = G[v].nneighbor[i];
			L[0] = G[currentneighbor-1];
			L[1] = G[destino-1];
			R = limits(L); /* armazenara a distancia minima entre dois vertices - minimo(G, w, d),onde G e o grafo, w e o 
			vizinho atual e d e o destino. a condiçao abaixo tambem foi alterada, incluindo a soma desse minimo */
			if(visitado[currentneighbor-1] == false)
			{
				
				if(limitante[currentneighbor-1] > distance[v] + G[v].nweight[i] + R) 
				{
					distance[currentneighbor-1] = distance[v] + G[v].nweight[i];
					previous[currentneighbor-1] = v+1;
					limitante[currentneighbor-1] = distance[currentneighbor-1] + R; /* atualizamos o limitante nao so com o peso(w),
					como tambem com o minimo(G, w, d) */
					check = heapsearch(H, n, currentneighbor);
					if(check > -1)
						diminui_prioridade(n, H, check, limitante[currentneighbor-1]);
					else
						insere(&n, H, limitante[currentneighbor-1], currentneighbor);
				}
			}
			// aqui tratamos os custos de vertices ja visitados
			else
			{
				if(distance[currentneighbor-1] > distance[v] + G[v].nweight[i])
				{
					distance[currentneighbor-1] = distance[v] + G[v].nweight[i];
					limitante[currentneighbor-1] = distance[currentneighbor-1] + R;
					previous[currentneighbor-1] = v+1;
					check = heapsearch(H, n, currentneighbor);
					if(check > -1)
						diminui_prioridade(n, H, check, limitante[currentneighbor-1]);
					else
						insere(&n, H, limitante[currentneighbor-1], currentneighbor);
				}
			}
		}
		counter++;
	}
	// caso ele encontre o caminho
	if(distance[destino-1] != 0 && distance[destino-1] != 1000000000.000)
	{
		printf("1 %.3f \n", distance[destino-1]); 
		caminho(origem, destino, previous, distance);
		printf("\n");
		printf("%d\n", counter);
	}
	// caso ele nao encontre o caminho
	else
	{
		printf("0 0.000\n");
		printf("%d 0.000 %d 0.000\n", origem, destino);
		printf("%d\n", counter);
	}
}


void dijkstra(grafo *G, int origem, int destino, int n)
{
	int i, v, counter = 0; // o counter conta quantos vertices foram visitados no processo
	int currentneighbor;
	peso H[n];
	double distance[n];
	int previous[n];
	int vvv;
	bool visitado[n];
	for(i = 0; i < n; i++)
	{
		distance[i] = 1000000000; // primeiro inicializamos com "infinito"
		previous[i] = -1; // indefinido
		visitado[i] = false;
	}
	H[0].vertice = origem; // insere na heap o vertice a ser visitado
	H[0].weight = 0;
	n = 1;
	cheap(n, H);
	distance[origem-1] = 0; 
	while(n > 0 && visitado[destino-1] == false)
	{
		v = find_smallest(&n, H); 
		v--;
		visitado[v] = true;
		
		for(i = 0; i < G[v].neighborhood; i++)
		{
			// a variavel "currentneighbor" armazena um vizinho do vertice visitado (iterando ate o total de vizinhos do vertice)
			currentneighbor = G[v].nneighbor[i];

			// como descrito no pseudo-codigo: peso(w) > peso(v) + custo(v, w)
			if(distance[currentneighbor-1] > distance[v] + G[v].nweight[i] && visitado[currentneighbor-1] == false)
			{
				distance[currentneighbor-1] = distance[v] + G[v].nweight[i];
				previous[currentneighbor-1] = v+1;

				// vamos verificar se o vizinho esta na heap
				vvv = heapsearch(H, n, currentneighbor);
				if(vvv > -1)
					diminui_prioridade(n, H, vvv, distance[currentneighbor-1]); // atualizamos o peso de w na heap para distance[currentneighbor-1]
				else
					insere(&n, H, distance[currentneighbor-1], currentneighbor); // inserimos o peso de w na heap com distance[currentneighbor-1]
			}
		}
		counter++;
	}
	// caso ele encontre o caminho
	if(distance[destino-1] != 0 && distance[destino-1] != 1000000000.000) 
	{
		printf("1 %.3f \n", distance[destino-1]); 
		caminho(origem, destino, previous, distance);
		printf("\n");
		printf("%d\n", counter);
	}
	// caso ele nao encontre o caminho
	else
	{
		printf("0 0.000\n");
		printf("%d 0.000 %d 0.000\n", origem, destino);
		printf("%d\n", counter);
	}
}

int main(int argc, char *argv[])
{
	FILE *graph;
	char crcter;
	char NV;
	int numv;
	int neighbors;
	int vizinho;
	double peso;
	int n, m, mdegree, i, k;
	double latitude2, longitude2;
	grafo  *G;
	graph = fopen(argv[1], "r"); // abrindo o arquivo de entrada dentro do programa
	fscanf(graph, "%c", &crcter); 
	if(crcter == 'G')
	{
		fscanf(graph, "%d", &n); // armazenando o numero de vertices
		fscanf(graph, "%d", &m); // armazenando o numero de arestas
		fscanf(graph, "%d\n", &mdegree); // armazenando o maior grau
		G = (grafo*)malloc (n*(sizeof(grafo))); // alocando dinamicamente a variavel G

		for(i = 0; i < n; i++)
		{
				fscanf(graph, "%c", &NV);
				fscanf(graph, "%d", &numv);
				fscanf(graph, "%lf", &latitude2);
				fscanf(graph, "%lf", &longitude2);
				fscanf(graph, "%d", &neighbors);
				G[i].Nvertice = NV;
				G[i].numvertice = numv;
				G[i].latitude = latitude2;
				G[i].longitude = longitude2;
				G[i].neighborhood = neighbors;
				G[i].nneighbor = (int*)malloc (neighbors*(sizeof(int)));
				G[i].nweight = (double*)malloc (neighbors*(sizeof(double)));
				for(k = 0; k < neighbors; k++)
				{
					fscanf(graph, "%d", &vizinho);
					fscanf(graph, "%lf", &peso);
					G[i].nneighbor[k] = vizinho;
					G[i].nweight[k] = peso;
				}
				fscanf(graph, "\n");
		}
		// Essa comparaçao serve para verificar qual tipo de algoritmo deve ser executado: dijsktra simples, 
		// dijkstra com alternantes ou dijkstra com limitantes
		int start, end; // armazenarao os vertices de origem e destino passados pelo argv[3] e argv[4], respectivamente
		if(atoi(argv[2]) == 1)
		{	
			start = atoi(argv[3]);
			end = atoi(argv[4]);
			dijkstra(G, start, end, n);
		}
		else if(atoi(argv[2]) == 2)
		{
			start = atoi(argv[3]);
			end = atoi(argv[4]);
			grafo R[n]; // o grafo que iremos inverter
			ofarg(R, G, n); // funcao de inversao do grafo G
			doubledijkstra(G, start, end, n);
		}
		else if(atoi(argv[2]) == 3)
		{
			start = atoi(argv[3]);
			end = atoi(argv[4]);
			aStar(G, start, end, n);
		}
	}
	free(G);
	return 0;
}
