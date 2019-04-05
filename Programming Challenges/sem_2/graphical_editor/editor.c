#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int *one, int *two)
{
  int aux;
  aux = *two;
  *two = *one;
  *one = aux;
}

void create_img(char *cmd, int *N, int *M, int *pos)
{
  int p = *pos;
  *M = parse_cmd_int(cmd, &p);
  *N = parse_cmd_int(cmd, &p);
  *pos = p;
}

void sweep(char img[255][255
  ], int b_posx, int b_posy, int f_posx, int f_posy, char color)
{ 
  int i, j;
  for(i = b_posx; i < f_posx; i++)
  {
    for(j = b_posy; j < f_posy; j++)
    {
      img[i][j] = color;
    }
  }
}


int parse_cmd_int(char *cmd, int *pos)
{
  int p = *pos, i = 0, j;
  char next[3] = {'-'};
  while(cmd[p] == ' ')
    p++;
  while(isdigit(cmd[p]))
  {
    next[i] = cmd[p];
    p++;
    i++;
  }
  p++;
  *pos = p;
  return atoi(&next[0]);
}

bool valid_pos(int pos, int pos2, int N, int M)
{
	if(pos >= 0 && pos < M && pos2 >= 0 && pos2 < N)
		return true;
	else
		return false;
}


char parse_color(char *cmd, int *pos)
{
  char next;
  int p = *pos;
  while(cmd[p] == ' ')
    p++;
  next = cmd[p];
  p++;
  *pos = p;
  return next;
}

void fill(char img[255][255], int x, int y, char color, char old_color, int M, int N)
{
  int i, j;
  if(old_color == color)
    return;
  img[y][x] = color;
  if(valid_pos(x, y+1, N, M) && img[y+1][x] == old_color)
    fill(img, x, y+1, color, old_color, M, N);
  if(valid_pos(x, y-1, N, M) && img[y-1][x] == old_color)
    fill(img, x, y-1, color, old_color, M, N);
  if(valid_pos(x+1, y, N, M) && img[y][x+1] == old_color)
    fill(img, x+1, y, color, old_color, M, N);
  if(valid_pos(x-1, y, N, M) && img[y][x-1] == old_color)
    fill(img, x-1, y, color, old_color, M, N);
}

int main(void)
{
  char cmd[250], img[255][255], color;
  char aux[250];
  int N = 0, M = 0, i = 0, j = 0, x, y, x2, y2;
  scanf(" %[^\n]", cmd);
  while(cmd[0] != 'X')
  {
    x = 0;
    y = 0;
    x2 = 0;
    y2 = 0;
    i = 1;
    switch(cmd[0])
    {
      case 'I':
        create_img(cmd, &N, &M, &i);
        sweep(img, 0, 0, N, M, 'O');
        break;
      case 'C':
        sweep(img, 0, 0, N, M, 'O');
      break;
      case 'L':
        create_img(cmd, &x, &y, &i);
        color = parse_color(cmd, &i);
        sweep(img, x-1, y-1, x, y, color);
        break;
      case 'V':
        create_img(cmd, &y, &x, &i);
        y2 = parse_cmd_int(cmd, &i);
        color = parse_color(cmd, &i);
        if(y > y2)
          swap(&y2, &y);
        sweep(img, y-1, x-1, y2, x, color);
        break;
      case 'H':
        create_img(cmd, &x2, &x, &i);
        y = parse_cmd_int(cmd, &i);
        color = parse_color(cmd, &i);
        if(x > x2)
          swap(&x2, &x);
        sweep(img, y-1, x-1, y, x2, color);
        break;
      case 'K':
        create_img(cmd, &y, &x, &i);
        create_img(cmd, &y2, &x2, &i);
        color = parse_color(cmd, &i);
        if(x > x2)
          swap(&x2, &x);
        if(y > y2)
          swap(&y2, &y);
        sweep(img, y-1, x-1, y2, x2, color);
        break;
      case 'F':
        create_img(cmd, &y, &x, &i);
        color = parse_color(cmd, &i);
        fill(img, x-1, y-1, color, img[y-1][x-1], M, N);
        break;
      case 'S':
        i = strlen(cmd);
        j = 0;
        while(cmd[i] != ' ')
        {
          aux[j] = cmd[i];
          i--;
          j++;
        }
        for(j--; j>0; j--)
        {
          printf("%c", aux[j]);
        }
        printf("\n");
        for(i = 0; i < N; i++)
        {
          for(j = 0; j < M; j++)
            printf("%c", img[i][j]);
          printf("\n");
        }
        break;
      case 'X':
        break;
      default:
        break;
   }
   scanf(" %[^\n]", cmd);
 }
 return 0;
}