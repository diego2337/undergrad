#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char grid[50][50], words[50];

bool search_eight_dir(int i, int j, int m, int n)
{
	int l, o, p, z;
	bool found = false;
	char c = 'a';
	/*
		a = E
		b = SE
		c = S
		d = SW
		e = W
		f = NW
		g = N
		h = NE
	*/
	for(z = 0; z < 8 && !found; z++)
	{
		switch(c)
		{
			case 'a':
				l = j;
				p = 0;
				while(l < n)
				{
					if(grid[i][l] != words[p])
					{
						found = false;
						l = n + 10;
					}
					else if(p+1 == strlen(words))
					{
						found = true;
						l = n + 10;
					}
					l++;
					p++;
				}
				break;
			case 'b':
				l = i;
				o = j;
				p = 0;
				while(l < m && o < n)
				{
					if(grid[l][o] != words[p])
					{
						found = false;
						l = m + 10;
					}
					else if(p+1 == strlen(words))
					{
						found = true;
						l = m + 10;
					}
					l++;
					o++;
					p++;
				}
				break;
			case 'c':
				l = i;
				p = 0;
				while(l < m)
				{
					if(grid[l][j] != words[p])
					{
						found = false;
						l = m + 10;
					}
					else if(p+1 == strlen(words))
					{
						found = true;
						l = m + 10;
					}
					l++;
					p++;
				}
				break;
			case 'd':
				l = i;
				o = j;
				p = 0;
				while(l < m && o >= 0)
				{
					if(grid[l][o] != words[p])
					{
						found = false;
						l = m + 10;
					}
					else if(p+1 == strlen(words))
					{
						found = true;
						l = m + 10;
					}
					l++;
					o--;
					p++;
				}
				break;
			case 'e':
				l = j;
				p = 0;
				while(l >= 0)
				{
					if(grid[i][l] != words[p])
					{
						found = false;
						l = -1;
					}
					else if(p+1 == strlen(words))
					{
						found = true;
						l = -1;
					}
					l--;
					p++;
				}
				break;
			case 'f':
				l = i;
				o = j;
				p = 0;
				while(l >= 0 && o >= 0)
				{
					if(grid[l][o] != words[p])
					{
						found = false;
						l = -1;
					}
					else if(p+1 == strlen(words))
					{
						found = true;
						l = -1;
					}
					l--;
					o--;
					p++;
				}
				break;
			case 'g':
				l = i;
				p = 0;
				while(l >= 0)
				{
					if(grid[l][j] != words[p])
					{
						found = false;
						l = -1;
					}
					else if(p+1 == strlen(words))
					{
						found = true;
						l = -1;
					}
					l--;
					p++;
				}
				break;
			case 'h':
				l = i;
				o = j;
				p = 0;
				while(l >= 0 && o < n)
				{
					if(grid[l][o] != words[p])
					{
						found = false;
						l = -1;
					}
					else if(p+1 == strlen(words))
					{
						found = true;
						l = -1;
					}
					l--;
					o++;
					p++;
				}
				break;
		}
		c = c + 1;
		/*printf("%c\n", c);*/
	}
	return found;
}

bool find_word(int m, int n, int *x, int *y)
{
	int i, j;
	bool found = false;
	for(i = 0; i < m && !found; i++)
	{
		for(j = 0; j < n && !found; j++)
		{
			if(grid[i][j] == words[0])
			{
				if(search_eight_dir(i, j, m, n))
				{
					*x = i+1;
					*y = j+1;
					found = true;
				}
			}
		}
	}
	return found;
}

int main(void)
{
	int m, n, k, i, j, l, t, x, y;
	char aux;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d %d", &m, &n);
		scanf("\n");
		for(j = 0; j < m; j++)
		{
			for(l = 0; l < n; l++)
			{
				grid[j][l] = getchar();
				if(isupper(grid[j][l]))
					grid[j][l] = tolower(grid[j][l]);
			}
			scanf("\n");
		}
		scanf("%d", &k);
		scanf("\n");
		for(j = 0; j < k; j++)
		{
			aux = getchar();
			l = 0;
			memset(words, 0, 50);
			while(aux != '\n')
			{
				if(isupper(aux))
					words[l] = tolower(aux);
				else
					words[l] = aux;
				l++;
				aux = getchar();
			}
			/*for(l = 0; l < n; l++)
			{
				printf("%c", words[l]);
			}*/
			if(find_word(m, n, &x, &y))
				printf("%d %d\n", x, y);
		}
		/*for(j = 0; j < m; j++)
		{
			for(l = 0; l < n; l++)
			{
				printf("%c", grid[j][l]);
			}
			printf("\n");
		}
		for(j = 0; j < k; j++)
		{
			for(l = 0; l < n; l++)
			{
				printf("%c", words[j][l]);
			}
		}*/
		if(i+1 != t)
			printf("\n");
	}
	return 0;
}