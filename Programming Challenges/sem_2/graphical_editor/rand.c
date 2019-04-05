#include <stdio.h>
#include <time.h>

int main(void)
{
	int i, j, N, M, cas, x, y, x2, y2,count = 1;
	char color;
	srand(time(NULL));
	N = rand() % 25 + 1;
	M = rand() % 25 + 1;
	printf("I 25 25\n");
	for(i = 0; i < 700; i++)
	{
		cas = rand() % 8;
		switch(cas)
		{
			case 0:
			break;
			case 1:
				printf("C\n");
			break;
			case 2:
				x = rand() % 25 + 1;
				y = rand() % 25 + 1;
				color = 'A' + rand() % (26);
				printf("L %d %d %c\n", x, y, color);
			break;
			case 3:
				x = rand() % 25 + 1;
				y = rand() % 25 + 1;
				y2 = rand() % 25 + 1;
				color = 'A' + rand() % (26);
				printf("V %d %d %d %c\n", x, y, y2, color);
			break;
			case 4:
				x = rand() % 25 + 1;
				x2 = rand() % 25 + 1;
				y = rand() % 25 + 1;
				color = 'A' + rand() % (26);
				printf("H %d %d %d %c\n", x, x2, y, color);
			break;
			case 5:
				x = rand() % 25 + 1;
				y = rand() % 25 + 1;
				x2 = rand() % 25 + 1;
				y2 = rand() % 25 + 1;
				color = 'A' + rand() % (26);
				printf("K %d %d %d %d %c\n", x, y, x2, y2, color);
			break;
			case 6:
				x = rand() % 25 + 1;
				y = rand() % 25 + 1;
				color = 'A' + rand() % (26);
				printf("F %d %d %c\n", x, y, color);
			break;
			case 7:
				printf("S teste%d.bmp\n", count);
				count++;
			break;
			default:
			break;
		}
	}
	printf("X\n");
}