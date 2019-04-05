#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
	int points;
	char name[501];
} estudante;

int compare(const void * a, const void * b)
{
	estudante aux = *(estudante*)a;
	estudante aux2 = *(estudante*)b;
	if(aux.points != aux2.points) return aux.points - aux2.points;
	return strcmp(aux2.name, aux.name);
}

int main(void)
{
	int n, i, tests = 1;
	estudante students[500];
	/*c = getchar();
	c = getchar();*/
	while(scanf("%d", &n) != EOF)
	{
		for(i = 0; i < n; i++)
		{
			scanf("%s", students[i].name);
			scanf("%d", &students[i].points);
		}
		qsort(students, n, sizeof(estudante), compare);
		printf("Instancia %d\n", tests);
		tests++;
		printf("%s\n\n", students[0].name);
	}
	return 0;
}