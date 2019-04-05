#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char * ajs(char answers[300][300], char tries[300][300], int n, int m)
{
	int i, j, k, l, menor;
	int presentation = 0;
	if (n < m)
		menor = n;
	else
		menor = m;
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while(i < n && j < m)
	{
		if(k >= strlen(answers[i]))
		{
			if(strlen(answers[i]) != strlen(tries[i]))
				presentation = 1;
			k = 0;
			i++;
		}
		else if(l >= strlen(tries[j]))
		{
			if(strlen(answers[i]) != strlen(tries[i]))
				presentation = 1;
			l = 0;
			j++;
		}
		if(answers[i][k] != tries[j][l] && isdigit(answers[i][k]))
		{
			while(!isdigit(tries[j][l]))
				l++;
			if(answers[i][k] == tries[j][l])
			{
				presentation = 1;
			}
			else
			{
				return "Wrong Answer";
			}
		}
		else if(answers[i][k] != tries[j][l] && isdigit(tries[j][l]))
		{
			while(!isdigit(answers[i][k]))
				k++;
			if(answers[i][k] == tries[j][l])
			{
				presentation = 1;
			}
			else
			{	
				return "Wrong Answer";
			}	
		}
		else if(answers[i][k] != tries[j][l])
			presentation = 1;
		/*if(j != k || strlen(answers[i]) != strlen(tries[i]))
			presentation = 1;*/
		k++;
		l++;
	}
	if(presentation || n != m)
		return "Presentation Error";
	else
		return "Accepted";
}

int main(void)
{
	int n, m, i, j, k, tests = 1;
	char c, answers[300][300], tries[300][300];
	scanf("%d", &n);
	c = getchar();
	c = getchar();
	while(n != 0)
	{
		m = 0;
		for(i = 0; i < 300; i++)
		{
			for(j = 0; j < 300; j++)
			{
				answers[i][j] = 0;
				tries[i][j] = 0;
			}
		}
		for(i = 0; i < n; i++)
		{
			k = 0;
			while(c != '\n' && c != EOF)
			{
				answers[i][k] = c;
				k++;
				c = getchar();
			}
			answers[i][k] = '\0';
			c = getchar();
		}
		i = 0;
		while(isdigit(c))
		{
			m = m * pow(10, i) + atoi(&c);
			i++;
			c = getchar();
		}
		c = getchar();
		for(i = 0; i < m; i++)
		{
			k = 0;
			while(c != '\n' && c != EOF)
			{
				tries[i][k] = c;
				k++;
				c = getchar();
			}
			tries[i][k] = '\0';
			c = getchar();	
		}
		printf("Run #%d: %s\n", tests, ajs(answers, tries, n, m));
		i = 0;
		n = 0;
		while(isdigit(c))
		{
			n = n * pow(10, i) + atoi(&c);
			i++;
			c = getchar();
		}
		c = getchar();
		tests++;
	}
	return 0;
}