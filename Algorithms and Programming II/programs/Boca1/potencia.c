#include<stdio.h>
int pot(int num, int expoente)
{
	if(expoente == 0)
	return 1;
	else
	return num * pot(num, expoente -1);
}
int main(void)
{
	int i, n, num, expoente;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &num, &expoente);
		pot(num, expoente);
		printf("%d\n", pot(num, expoente));
	}
	return 0;
}
