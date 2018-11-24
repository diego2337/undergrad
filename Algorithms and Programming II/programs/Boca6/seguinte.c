// Programa: seguinte.c
// Programador: Diego Cintra
// Data: 21/12/2012
#include<stdio.h>
typedef struct
{
	int dia;
	int mes;
	int ano;
} data;
int bissexto(data d)
{
	if((d.ano % 400 == 0) || (d.ano % 4 == 0 && d.ano % 100 != 0))
	return 1;
	else
	return 0;
}
int diasMes(data d)
{
	if(d.mes == 1 || d.mes == 3 || d.mes == 5 || d.mes == 7 || d.mes == 8 || d.mes == 10 || d.mes == 12)
	return 31;
	if(d.mes == 2)
	{
		if(bissexto(d) == 1)
		return 29;
		else
		return 28;
	}
	else
	return 30;
}
data diaSeguinte(data d)
{
	d.dia++;
	if(diasMes(d) == 30)
	{
		if(d.dia > 29)
		{
			d.dia = 1;
			d.mes++;
		}
		if(d.mes > 12)
		{
			d.mes = 1;
			d.ano++;		
		}
	}
	if(diasMes(d) == 31)
	{
		if(d.dia > 30)
		{
			d.dia = 1;
			d.mes++;
		}	
		if(d.mes > 12)
		{
			d.mes = 1;
			d.ano++;
		}
	}
	if(bissexto(d) == 1)
	{
		if(d.dia > 29)
		{
			d.dia = 1;
			d.mes++;
		}
		if(d.mes > 12)
		{
			d.mes = 1;
			d.ano++;
		}
	}
	if(bissexto(d) == 0)
	{
		if(d.dia > 27)
		{
			d.dia = 1;
			d.mes++;
		}
		if(d.mes > 12)
		{
			d.mes = 1;
			d.ano++;
		}
	}
	
        return d;
}

int main(void)
{
	int i, rep;
	data d, dmais;
	scanf("%d", &rep);
	for(i = 0; i < rep; i++)
	{
		scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);
		dmais =	diaSeguinte(d);
		printf("%02d/%02d/%04d\n", dmais.dia, dmais.mes, dmais.ano);
	}
	return 0;
}
