/* Autor: Diego Silva Cintra 
   Data: 28/02/2015 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _tlista{
  int val;
  struct _tlista *next;
}tlista;
typedef tlista *Lista;

void init(Lista *L)
{
  (*L) = NULL;
}

void insere(Lista *L, int val)
{
  Lista L2, atual;
  L2 = (tlista*)malloc(sizeof(tlista));
  atual = (tlista*)malloc(sizeof(tlista));
  L2->val = val;
  L2->next = NULL;
  if((*L) == NULL)
  {
    (*L) = L2;
  }
  else if((*L)->next == NULL)
  {
    (*L)->next = L2;
  }
  else
  {
    atual = (*L);
    while(atual->next != NULL)
      atual = atual->next;
    atual->next = L2;
  }
}

void remover(Lista *L, int val)
{
  Lista atual;
  atual = (tlista*)malloc(sizeof(tlista));
  if((*L) == NULL)
    printf("Lista vazia.\n");
  else if((*L)->next == NULL)
  {
    (*L) = NULL;
  }
  else if((*L)->val == val)
  {
    atual = (*L);
    (*L) = atual->next;
  }
  else
  {
    atual = (*L);
    if(search(&atual, val))
    {
      while(atual->next->val != val)
        atual = atual->next;
      atual->next = atual->next->next;  
    }
    else
      printf("Elemento nao se encontra.\n");
  }
}

int search(Lista *L, int valor)
{
  Lista aux;
  aux = (Lista)malloc(sizeof(Lista*));
  aux = (*L);
  while(aux != NULL)
  {
    if(aux->val == valor)
      return 1;
    else
      aux = aux->next;
  }
  return 0;
}

int size(Lista *L)
{
  int count = 0;
  Lista aux;
  aux = (tlista*)malloc(sizeof(tlista));
  aux = (*L);
  while(aux != NULL)
  {
    aux = aux->next;
    count++;
  }
  return count;
}

bool isBiggerThanFifty(int max, int candidates)
{
	if(max*100 / candidates >= 50)
		return true;
	else
		return false;
}

void contar(int **votes, char **names, int *pos, int candidates, int n_candidates, int max, int min, Lista *mat_pos)
{
	int i = 0, j, k, v_count = 0;
	for(i = 0; i < 1000; i++)
	{
		if(votes[i][0] != 0)
		{
			v_count++;
			pos[(votes[i][0])-1]++;
			insere(&mat_pos[votes[i][0]-1], i);
		}
	}
	/*for(i = 0; i < candidates; i++)
		printf("%d ", pos[i]);
	printf("\n");*/
	for(i = 0; i < candidates; i++)
	{
		if(pos[i] > max)
			max = pos[i];
		else if(pos[i] < min)
			min = pos[i];
	}
	for(i = 0; i < candidates; i++)
	{
		if(pos[i] == min)
		{
			pos[i] = -1;
			n_candidates--;
		}
	}
	/*for(i = 0; i < 10; i++)
	{
		while(mat_pos[i] != NULL)
		{
			printf("%d ", mat_pos[i]->val);
			mat_pos[i] = mat_pos[i]->next;
		}
		printf("\n");
	}*/
	while(n_candidates != 1 && !isBiggerThanFifty(max, v_count))
	{
		for(i = 0; i < candidates; i++)
		{
			if(pos[i] == -1)
			{
				while(mat_pos[i] != NULL)
				{
					j = 0;
					while(votes[mat_pos[i]->val][j] == -1 || pos[votes[mat_pos[i]->val][j]-1] == -1 
						|| votes[mat_pos[i]->val][j] == (i+1))
					{
						j++;
					}
					pos[votes[mat_pos[i]->val][j]-1]++;
					votes[mat_pos[i]->val][j] = -1;
					mat_pos[i] = mat_pos[i]->next;
					/*for(j = 0; j < 10; j++)
					{
						for(k = 0; k < candidates; k++)
							printf("%d ", votes[j][k]);
						printf("\n");
					}*/
				}
			}
		}
		min = 10000;
		for(i = 0; i < candidates; i++)
		{
			if(pos[i] > max)
				max = pos[i];
			else if(pos[i] < min && pos[i] != -1)
				min = pos[i];
		}
		for(i = 0; i < candidates; i++)
		{
			if(pos[i] == min && min != max)
			{
				pos[i] = -1;
				n_candidates--;
			}
		}
	}
}

int main(void)
{
	char **names, enter;
	Lista mat_pos[20];
	int ** votes, i, j, n, k, cases, candidates, *pos, max = 0, min = 10000, aux;
	scanf("%d", &n);
	printf("\n");
	for(i = 0; i < 20; i++)
	{
		init(&mat_pos[i]);
	}
	for(cases = 0; cases < n; cases++)
	{
		if(cases != 0)
		{
			printf("\n");
			candidates = aux;
			printf("%d\n", aux);
			exit(0);
		}
		scanf("%d", &candidates);
		printf("%d\n", candidates);
		pos = (int*)malloc(candidates*sizeof(int));
		names = (char**)malloc(candidates*sizeof(char*));
		for(i = 0; i < candidates; i++)
		{
			*(names+i) = (char*)malloc(80*sizeof(char*));
			scanf(" %80[^\n]", names[i]);
			printf("%s\n", names[i]);
		}
		votes = (int**)malloc(1000*sizeof(int*));
		for(i = 0; i < 1000; i++)
		{
			votes[i] = (int*)malloc(candidates*sizeof(int*));
		}
		if(candidates != 0)
		{
			i = 0;
			char entry[60] = {' '};
			memset(entry, ' ', 60);
			while(i < 1000)
			{
				scanf(" %60[^\n]", entry);
				for(j = 0; entry[j] != '\0'; j++)
					printf("%c", entry[j]);
				if(entry[1] == '\0')
				{
					aux = entry[2];
					break;
				}
				else
				{
					k = 0;
					j = 0;
					while(entry[k] != '\0')
					{
						if(entry[k] != ' ')
						{
							votes[i][j] = atoi(&entry[k]);
							j++;
							k++;
						}
						else
							k++;
					}
					i++;
				}
			}
			for(i = 0; i < 10; i++)
			{
				for(j = 0; j < candidates; j++)
					printf("%d ", votes[i][j]);
				printf("\n");
			}
			contar(votes, names, pos, candidates, candidates, max, min, mat_pos);
			for(i = 0; i < candidates; i++)
			{
				if(pos[i] != -1)
					printf("%s\n", names[i]);
			}
		}
		for(i = 0; i < 1000; i++)
		{
			free(votes[i]);
			if(i < candidates)
				free(*(names+i));
		}
		free(votes);
		free(pos);
	}
	return 0;
}