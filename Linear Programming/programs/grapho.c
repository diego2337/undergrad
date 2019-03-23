#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, m;
	char c;
	FILE *arq, *arq2;
	arq = fopen("graph.txt", "r");
	arq2 = fopen("graphss.txt", "w");
	while(!feof(arq))
	{
		fscanf(arq, "%c", &c);
		fscanf(arq, "%d %d\n", &n, &m);
		fprintf(arq2, "%d %d\n", n, m);
	}
	fclose(arq);
	fclose(arq2);
	return 0;
}

