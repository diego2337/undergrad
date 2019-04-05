#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int x, y;
}rational;

void rational_b_search(rational q, rational l, rational r)
{
	rational median;
	median.x = (l.x+r.x);
	median.y = (l.y+r.y);
	if(median.x == q.x && median.y == q.y)
		return;
	else if((double)median.x/(double)median.y < (double)q.x/(double)q.y)
	{
		printf("R");
		rational_b_search(q, median, r);
	}
	else if((double)median.x/(double)median.y > (double)q.x/(double)q.y)
	{
		printf("L");
		rational_b_search(q, l, median);	
	}
}

int main(void)
{
	rational a, b, c;
	scanf("%d %d", &c.x, &c.y);
	while(c.x != 1 || c.y != 1)
	{
		a.x = 0;
		a.y = 1;
		b.x = 1;
		b.y = 0;
		rational_b_search(c, a, b);
		printf("\n");
		scanf("%d %d", &c.x, &c.y);
	}
	return 0;
}