/* Autor: Diego Silva Cintra 
   Data: 27/02/2015 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool valid_pos(int pos, int pos2)
{
	if(pos >= 0 && pos < 8 && pos2 >= 0 && pos2 < 8)
		return true;
	else
		return false;
}

bool equals(int pos, int pos2, int x, int y)
{
	if(valid_pos(pos, pos2))
	{
		if(pos == x && pos2 == y)
			return true;
	}
	return false;
}

bool findAnyPieceInPos(char ** table, int pos, int pos2)
{
	if(valid_pos(pos, pos2) && table[pos][pos2] != '.')
		return true;
	else
		return false;
}

bool findPiece(char **table, int *pos, int *pos2, char piece, bool *upper)
{
	int i, j;
	bool up = false;
	for(i = 0; !up && i < 8; i++)
	{
		for(j = 0; !up && j < 8; j++)
		{
		/*	if(table[i][j] == isupper(piece))
			{
				*pos = i;
				*pos2 = j;
				up = true;
				*upper = true;
				table[i][j] = '0';
			}
			else*/ 
			if(table[i][j] == piece)
			{
				*pos = i;
				*pos2 = j;
				up = true;
				if(isupper(piece))
					*upper = true;
				else
					*upper = false;
				table[i][j] = '0';
			}
		}
	}
	return up;
}

bool attack_span(char **table, int enemy_pos, int enemy_pos2, int kings_pos, int kings_pos2, char piece, bool upper)
{
	int span_x, span_y, i, j;
	bool enemy = false;
	/* Vetor indicando as 8 possiveis direçoes */
	int x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	switch(piece)
	{
		case 'k':
			if(equals(enemy_pos-1, enemy_pos2, kings_pos, kings_pos2)
				|| equals(enemy_pos-1, enemy_pos2+1, kings_pos, kings_pos2)
				|| equals(enemy_pos, enemy_pos2+1, kings_pos, kings_pos2)
				|| equals(enemy_pos+1, enemy_pos2+1, kings_pos, kings_pos2)
				|| equals(enemy_pos+1, enemy_pos2+1, kings_pos, kings_pos2)
				|| equals(enemy_pos+1, enemy_pos2, kings_pos, kings_pos2)
				|| equals(enemy_pos-1, enemy_pos2-1, kings_pos, kings_pos2)
				|| equals(enemy_pos-1, enemy_pos2, kings_pos, kings_pos2)
				|| equals(enemy_pos-1, enemy_pos2+1, kings_pos, kings_pos2))
			{
				return true;
			}
			break;
		case 'n':
			if(equals(enemy_pos-2, enemy_pos2+1, kings_pos, kings_pos2)
				|| equals(enemy_pos-2, enemy_pos2-1, kings_pos, kings_pos2)
				|| equals(enemy_pos+1, enemy_pos2+2, kings_pos, kings_pos2)
				|| equals(enemy_pos-1, enemy_pos2+2, kings_pos, kings_pos2)
				|| equals(enemy_pos+2, enemy_pos2+1, kings_pos, kings_pos2)
				|| equals(enemy_pos+2, enemy_pos2-1, kings_pos, kings_pos2)
				|| equals(enemy_pos-1, enemy_pos2-2, kings_pos, kings_pos2)
				|| equals(enemy_pos+1, enemy_pos2-2, kings_pos, kings_pos2))
			{
				return true;
			}
			break;
		case 'p':
			if(upper)
			{
				if(equals(enemy_pos-1, enemy_pos2+1, kings_pos, kings_pos2)
					|| equals(enemy_pos-1, enemy_pos2-1, kings_pos, kings_pos2))
				{
					return true;
				}
			}
			else
			{
				if(equals(enemy_pos+1, enemy_pos2+1, kings_pos, kings_pos2)
					|| equals(enemy_pos+1, enemy_pos2-1, kings_pos, kings_pos2))
				{
					return true;
				}
			}
			break;
		case 'b':
			/* Iteraçao do for indica as direçoes de ataque */
			for(i = 1; i < 8; i = i + 2)
			{
				span_x = enemy_pos;
				span_y = enemy_pos2;
				enemy = false;
				while(valid_pos(span_x, span_y))
				{
					span_x = span_x + x[i];
					span_y = span_y + y[i];
					if(equals(span_x, span_y, kings_pos, kings_pos2) && enemy == false)
						return true;
					else if(findAnyPieceInPos(table, span_x, span_y))
						enemy = true;
				}
			}
			break;
		case 'r':
			for(i = 0; i < 8; i = i + 2)
			{
				span_x = enemy_pos;
				span_y = enemy_pos2;
				enemy = false;
				while(valid_pos(span_x, span_y))
				{
					span_x = span_x + x[i];
					span_y = span_y + y[i];
					if(equals(span_x, span_y, kings_pos, kings_pos2) && enemy == false)
						return true;
					else if(findAnyPieceInPos(table, span_x, span_y))
						enemy = true;
				}
			}
			break;
		case 'q':
			for(i = 0; i < 8; i = i++)
			{
				span_x = enemy_pos;
				span_y = enemy_pos2;
				enemy = false;
				while(valid_pos(span_x, span_y))
				{
					span_x = span_x + x[i];
					span_y = span_y + y[i];
					if(equals(span_x, span_y, kings_pos, kings_pos2) && enemy == false)
						return true;
					else if(findAnyPieceInPos(table, span_x, span_y))
						enemy = true;
				}
			}
			break;
		default:
			break;
	}
	return false;
}

bool attack(char **table, int x, int y, char piece, bool upper)
{
	int pos, pos2;
	bool hit = false, up = true;
	if(!upper)
	{
		switch(piece)
		{
		
			case 'k':
			if(findPiece(table, &pos, &pos2, 'k', &up) && up == false)
			{
				if(attack_span(table, pos, pos2, x, y, 'k', false))
					hit = true;
			}
			break;
			case 'n':
			if(findPiece(table, &pos, &pos2, 'n', &up) && up == false)
			{
				if(attack_span(table, pos, pos2, x, y, 'n', false))
					hit = true;
			}
			break;
			case 'p':
			if(findPiece(table, &pos, &pos2, 'p', &up) && up == false)
			{
				if(attack_span(table, pos, pos2, x, y, 'p', false))
					hit = true;
			}
			break;
			case 'b':
			if(findPiece(table, &pos, &pos2, 'b', &up) && up == false)
			{
				if(attack_span(table, pos, pos2, x, y, 'b', false))
					hit = true;
			}
			break;
			case 'r':
			if(findPiece(table, &pos, &pos2, 'r', &up) && up == false)
			{
				if(attack_span(table, pos, pos2, x, y, 'r', false))
					hit = true;
			}
			break;
			case 'q':
			if(findPiece(table, &pos, &pos2, 'q', &up) && up == false)
			{
				if(attack_span(table, pos, pos2, x, y, 'q', false))
					hit = true;
			}
			break;
		}
	}
	else
	{
		switch(piece)
		{
			case 'K':
			if(findPiece(table, &pos, &pos2, 'K', &up) && up == true)
			{
				if(attack_span(table, pos, pos2, x, y, 'k', true))
					hit = true;
			}
			break;
			case 'N':
			if(findPiece(table, &pos, &pos2, 'N', &up) && up == true)
			{
				if(attack_span(table, pos, pos2, x, y, 'n', true))
					hit = true;
			}
			break;
			case 'P':
			if(findPiece(table, &pos, &pos2, 'P', &up) && up == true)
			{
				if(attack_span(table, pos, pos2, x, y, 'p', true))
					hit = true;
			}
			break;
			case 'B':
			if(findPiece(table, &pos, &pos2, 'B', &up) && up == true)
			{
				if(attack_span(table, pos, pos2, x, y, 'b', true))
					hit = true;
			}
			break;
			case 'R':
			if(findPiece(table, &pos, &pos2, 'R', &up) && up == true)
			{
				if(attack_span(table, pos, pos2, x, y, 'r', true))
					hit = true;
			}
			break;
			case 'Q':
			if(findPiece(table, &pos, &pos2, 'Q', &up) && up == true)
			{
				if(attack_span(table, pos, pos2, x, y, 'q', true))
					hit = true;
			}
			break;
		}
	}
}

bool check(char **table, bool upper, int x, int y)
{
	int i;
	char pieces[16] = {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
	'N', 'N', 'B', 'B', 'R', 'R', 'Q', 'K'};
	bool attacked = false;
	/* Indica que é o Rei branco */
	if(upper)
	{
		for(i = 0; i < 16; i++)
		{
			if(attacked == false && attack(table, x, y, pieces[i], upper))
				attacked = true;
		}
	}
	else 
	{
		for(i = 0; i < 16; i++)
		{
			if(attacked == false && attack(table, x, y, tolower(pieces[i]), upper))
				attacked = true;
		}	
	}
	return attacked;
}

int main(void)
{
	int i, j, pos, pos2, times = 1;
	bool empty = false, upper = true;
	char **table, **aux_table;
	while(!empty)
	{
		table = (char**)malloc(8*sizeof(char*));
		aux_table = (char**)malloc(8*sizeof(char*));
		empty = true;
		for(i = 0; i < 8; i++)
		{
			*(table+i) = (char*)malloc(8*sizeof(char*));
			*(aux_table+i) = (char*)malloc(8*sizeof(char*));
			for(j = 0; j < 8; j++)
			{
				scanf(" %c", &table[i][j]);
				if(table[i][j] != 46)
					empty = false;
				aux_table[i][j] = table[i][j];
			}
		}
		if(!empty)
		{
			if(findPiece(table, &pos, &pos2, 'k', &upper) && check(table, !upper, pos, pos2))
			{
				printf("Game #%d: black king is in check.\n", times);
			}
			else if(findPiece(aux_table, &pos, &pos2, 'K', &upper) && check(aux_table, !upper, pos, pos2))
			{
				printf("Game #%d: white king is in check.\n", times);
			}
			else
			{
				printf("Game #%d: no king is in check.\n", times);
			}
		}
		times++;
		free(table);
		free(aux_table);
	}
	return 0;
}