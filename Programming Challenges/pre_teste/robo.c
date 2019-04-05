#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool valid_pos(int x, int y, int N, int M)
{
	if(x < 0 || x > M || y < 0 || y > N)
		return false;
	else
		return true;
}

bool forward(int x, int y, int N, int M, char direction, char arena[100][100], int *x2, int *y2)
{
	switch(direction)
	{
		case 'N':
		if(!valid_pos(x, y-1, N, M) || arena[x-1][y] == '#')
			return false;
		else
		{
			*x2 = x;
			*y2 = y-1;
			return true;
		}
		break;
		case 'L':
		if(!valid_pos(x+1, y, N, M) || arena[x][y+1] == '#')
			return false;
		else
		{
			*x2 = x+1;
			*y2 = y;
			return true;
		}
		break;
		case 'S':
		if(!valid_pos(x, y+1, N, M) || arena[x+1][y] == '#')
			return false;
		else
		{
			*x2 = x;
			*y2 = y+1;
			return true;
		}
		break;
		case 'O':
		if(!valid_pos(x-1, y, N, M) || arena[x][y-1] == '#')
			return false;
		else
		{
			*x2 = x-1;
			*y2 = y;
			return true;
		}
		break;
	}
}


void execute(char arena[100][100], char instruction, int *stickers, int *x, int *y, int N, int M)
{
	int x2 = *x, y2 = *y;
	switch(instruction)
	{
		case 'D':
		if(arena[*x][*y] == 'N')
			arena[*x][*y] = 'L';
		else if(arena[*x][*y] == 'L')
			arena[*x][*y] = 'S';
		else if(arena[*x][*y] == 'S')
			arena[*x][*y] = 'O';
		else if(arena[*x][*y] == 'O')
			arena[*x][*y] = 'N';
		break;
		case 'E':
		if(arena[*x][*y] == 'N')
			arena[*x][*y] = 'O';
		else if(arena[*x][*y] == 'O')
			arena[*x][*y] = 'S';
		else if(arena[*x][*y] == 'S')
			arena[*x][*y] = 'L';
		else if(arena[*x][*y] == 'L')
			arena[*x][*y] = 'N';
		break;
		case 'F':
		if(forward(*x, *y, N, M, arena[*x][*y], arena, &x2, &y2))
		{
			*x = x2;
			*y = y2;
			if(arena[*x][*y] == '*')
			{
				*stickers++;
				arena[*x][*y] == '.';
			}
		}
		break;
	}
}

int main(void)
{
	int N, M, S, i, j, x, y, stickers;
	char arena[100][100], instruction;
	scanf("%d %d %d", &N, &M, &S);
	while(N != 0 && M != 0 && S != 0)
	{
		stickers = 0;
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < M; j++)
			{
				scanf(" %c", &arena[i][j]);
				if(arena[i][j] == 'N' ||
					arena[i][j] == 'S' ||
					arena[i][j] == 'L' ||
					arena[i][j] == 'O')
				{
					x = i;
					y = j;
				}
			}
		}
		for(i = 0; i < S; i++)
		{
			scanf(" %c", &instruction);
			execute(arena, instruction, &stickers, &x, &y, N, M);
		}
		printf("%d\n", stickers);
		scanf("%d %d %d", &N, &M, &S);
	}
}