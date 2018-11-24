#include <stdio.h>
int verifica (int vet[8], int b, int c)
{
	int pode=1, i;
	for(i=0;i<b;i++)
	{
		if(vet[i]==c)
			pode=0;
		if(i-vet[i]==b-c)
			pode=0;
		if(i+vet[i]==b+c)
			pode=0;
	}
	return pode;
}
int procura(int vet[8], int b, int quant)
{
	int i;
	if(b<8)
	{
		for(i=0;i<8;i++){
			if(verifica(vet,b,i)){
				vet[b]=i;
				quant = procura(vet,b+1,quant);
			}
		}
	}
	else
	{
		for(i=0;i<8;i++)
			printf("%d ", vet[i]+1);
		quant++;
		printf("\n");
	}
	return quant;
}

int main(void)
{

	int vet[8]={0}, quant;
	quant = procura(vet,0, 0);
	printf("\n%d\n", quant);
	return 0;
}