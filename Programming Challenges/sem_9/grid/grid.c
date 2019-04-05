#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXDIGITOS 101
#define MAIS 1
#define MENOS -1

typedef struct{
	char digitos[MAXDIGITOS]; /* representa o numero */
	int sinal; /* representa o sinal */
	int ultimodigito; /* indice do digito de mais alta ordem */
}numerogrande;

void inicializa_numgrande(numerogrande *n);
void imprime_numgrande(numerogrande *n);
void soma_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);
void subtrai_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);
void justifica_zero(numerogrande *n);
int compara_numgrandes(numerogrande *a, numerogrande *b);
void multiplica_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);
void desloca_digito(numerogrande *n, int d);
void divide_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c);

int max(int a, int b)
{
	return a > b ? a : b;
}

void inicializa_numgrande(numerogrande *n)
{
	int i;
	n->sinal = MAIS;
	n->ultimodigito = 0;
	for(i = 0; i < MAXDIGITOS; i++)
		n->digitos[i] = '0';
}

void imprime_numgrande(numerogrande *n)
{
	int i;
	if(n->sinal == MENOS) printf("-");
	for(i = n->ultimodigito; i >= 0; i--)
		printf("%c", n->digitos[i]);
	printf("\n");
}

void soma_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c)
{
	int vaium; /* vai um */
	int i; /* contador */
	char c2, c3;
	/*inicializa_numgrande(c); inicializa digitos com 0 */
	if(a->sinal == b->sinal) 
		c->sinal = a->sinal;
	else
	{
		if(a->sinal == MENOS)
		{
			a->sinal = MAIS; subtrai_numgrandes(b,a,c); a->sinal = MENOS;
		}
		else
		{
			b->sinal = MAIS; subtrai_numgrandes(a,b,c); b->sinal = MENOS;
		}
		return;
	}
	c->ultimodigito = max(a->ultimodigito, b->ultimodigito)+1;
	vaium = 0;
	for(i = 0; i <=(c->ultimodigito); i++)
	{
		c2 = (*a).digitos[i];
		c3 = (*b).digitos[i];
		/*printf("%d\t%d\t%d\t%d\t%d\t%c\n", c2, c3, (c2-'0'), (c3-'0'), (c2-'0')+(c3-'0'), ((c2-'0')+(c3-'0'))+'0');*/
		c->digitos[i] = ((vaium+(c2-'0')+(c3-'0'))%10) +'0';
		vaium = (vaium+((c2-'0')+(c3-'0'))) / 10;
	}
	/*for(i = 0; i <=(c->ultimodigito); i++)
	{
		c2 = a->digitos[i];
		c3 = b->digitos[i];
		printf("%d\t%d\t%d\t%c\n", a->digitos[i], b->digitos[i], atoi(&c2)+atoi(&c3), (atoi(&c2)+atoi(&c3))+'0');
		c->digitos[i] = ((atoi(&c2)+atoi(&c3))%10)+'0';
		vaium = (vaium+(atoi(&c2)+atoi(&c3))) / 10;
	}*/
	justifica_zero(c);
}

void justifica_zero(numerogrande *n)
{
	while((n->ultimodigito > 0) && (n->digitos[n->ultimodigito] == '0'))
		n->ultimodigito--;
	if((n->ultimodigito == 0) && (n->digitos[0] == '0'))
		n->sinal = MAIS; /* para evitar o -0 */
}

void subtrai_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c)
{
	int empresta; /* empresta do vizinho */
	int v; /* digito componente da solucao */
	int i; /* contador */
	inicializa_numgrande(c); /* inicializa digitos com 0 */
	if((a->sinal == MENOS) || (b->sinal == MENOS))
	{
		b->sinal = -1 * b->sinal; soma_numgrandes(a, b, c);
		b->sinal = -1 * b->sinal; return;
	}
	if(compara_numgrandes(a,b) == MAIS)
	{
		subtrai_numgrandes(b,a,c); c->sinal = MENOS;
		return;
	}
	c->ultimodigito = max(a->ultimodigito, b->ultimodigito);
	empresta = 0;
	for(i = 0; i <= (c->ultimodigito); i++)
	{
		v = ((a->digitos[i]-'0') - empresta - (b->digitos[i]-'0'));
		if(v < 0) v = v + 10, empresta = 1;
		else empresta = 0;
		c->digitos[i] = v+'0';
	}
	justifica_zero(c);
}

void recebe_numgrandes(numerogrande *a, numerogrande *b)
{
	int i;
	a->sinal = b->sinal;
	a->ultimodigito = b->ultimodigito;
	for(i = 0; i <=  b->ultimodigito; i++)
	{
		a->digitos[i] = b->digitos[i];
	}
}

void multiplica_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c)
{
	int i,j; /* contadores */
	numerogrande linha, tmp;
	/*linha = *a;*/
	inicializa_numgrande(c);
	inicializa_numgrande(&linha);
	inicializa_numgrande(&tmp);
	recebe_numgrandes(&linha, a);
	for(i = 0; i <= b->ultimodigito; i++)
	{
		for(j = 1; j <= b->digitos[i] - '0'; j++)
		{
			soma_numgrandes(c, &linha, &tmp);
			recebe_numgrandes(c, &tmp);
		}
		desloca_digito(&linha, 1);
		/*for(j = 1; j <= (b->digitos[i] - '0')*pow(10, i); j++)
		{
			soma_numgrandes(c, a, c);
		}*/
	}
	c->sinal = a->sinal * b->sinal;
	justifica_zero(c);
}

/* Compara dois numeros a e b, retornando MAIS se b > a,
MENOS se a > b e 0 se a = b */
int compara_numgrandes(numerogrande *a, numerogrande *b)
{
	int i; /* contador */
	if((a->sinal==MENOS) && (b->sinal==MAIS)) {/*puts("1");*/ return MAIS;}
	if((a->sinal==MAIS) && (b->sinal==MENOS)) {/*puts("2");*/ return MENOS;}
	if(b->ultimodigito > a->ultimodigito) {/*puts("3");*/ return (MAIS * a->sinal);}
	if(a->ultimodigito > b->ultimodigito) {/*puts("4");*/ return (MENOS * a->sinal);}
	for(i = a->ultimodigito; i >= 0; i--)
	{
		if(a->digitos[i] > b->digitos[i]) {/*puts("5");*/ return (MENOS * a->sinal);}
		if(b->digitos[i] > a->digitos[i]) {/*puts("6");*/ return (MAIS * a->sinal);}
	}
	return 0;
}

/* Desloca digito (multiplica n por 10^d) */
void desloca_digito(numerogrande *n, int d)
{
	int i; /* contador */
	if((n->ultimodigito == 0) && (n->digitos[0] == 0)) return;
	for(i = n->ultimodigito; i >= 0; i--)
	n->digitos[i+d] = n->digitos[i];
	for(i = 0; i < d; i++)
	n->digitos[i] = '0';
	n->ultimodigito = n->ultimodigito + d;
}

void divide_numgrandes(numerogrande *a, numerogrande *b, numerogrande *c)
{
	numerogrande linha; /* linha deslocada */
	numerogrande tmp; /* armazena numero grande */
	int asinal, bsinal; /* sinais temporarios */
	int i; /* contador */
	inicializa_numgrande(c);
	c->sinal = a->sinal * b->sinal;
	asinal = a->sinal; bsinal = b->sinal;
	a->sinal = MAIS; b->sinal = MAIS;
	inicializa_numgrande(&linha);
	inicializa_numgrande(&tmp);
	c->ultimodigito = a->ultimodigito;
	for(i = a->ultimodigito; i >= 0; i--)
	{
		desloca_digito(&linha, 1);
		linha.digitos[0] = a->digitos[i];
		justifica_zero(&linha);
		c->digitos[i] = '0';
		while(compara_numgrandes(&linha, b) != MAIS)
		{
			c->digitos[i] = c->digitos[i] + 1;
			subtrai_numgrandes(&linha, b, &tmp);
			linha = tmp;
		}
	}
	justifica_zero(c);
	a->sinal = asinal;
	b->sinal = bsinal;
}

/* Converte inteiros para numeros grandes */
void int_to_numgrandes(int s, numerogrande *n)
{
	int i; /* contador */
	int t; /* guarda copia do inteiro */
	if(s >= 0) n->sinal = MAIS;
	else n->sinal = MENOS;
	for(i = 0; i < MAXDIGITOS; i++) n->digitos[i] = 0;
	n->ultimodigito = -1;
	t = abs(s);
	while(t > 0)
	{
		n->ultimodigito++;
		n->digitos[n->ultimodigito] = t % 10;
		t = t / 10;
	}
	if(s == 0) n->ultimodigito = 0;
}

void big_fact(numerogrande *n, numerogrande *n3)
{
	numerogrande um, zero, tmp, tmp2, tmp3;
	int par;
	inicializa_numgrande(&um);
	inicializa_numgrande(&zero);
	inicializa_numgrande(&tmp);
	inicializa_numgrande(&tmp2);
	inicializa_numgrande(&tmp3);
	um.digitos[0] = '1';
	tmp3.digitos[0] = '1';
	par = 1;
	if(compara_numgrandes(n, &zero) == 0 || compara_numgrandes(n, &um) == 0)
		soma_numgrandes(&zero, &um, n3);
	else
	{
		while(compara_numgrandes(n, &um) != 0)
		{
			subtrai_numgrandes(n, &um, &tmp);
			multiplica_numgrandes(n, &tmp, &tmp2);
			recebe_numgrandes(n, &tmp);
			if(par == 1)
			{
				multiplica_numgrandes(&tmp3, &tmp2, n3);
				recebe_numgrandes(&tmp3, n3);
				par = 0;
			}
			else if(par == 0)
				par = 1;
		}
	}
}

numerogrande comb(numerogrande *n, numerogrande *k)
{
	numerogrande result, tmp, tmp2, k_fatorial, n_fatorial, n_k_fatorial;
	inicializa_numgrande(&result);
	inicializa_numgrande(&tmp);
	inicializa_numgrande(&tmp2);
	inicializa_numgrande(&n_fatorial);
	inicializa_numgrande(&k_fatorial);
	inicializa_numgrande(&n_k_fatorial);
	subtrai_numgrandes(n, k, &tmp);
	big_fact(k, &k_fatorial);
	big_fact(&tmp, &n_k_fatorial);
	big_fact(n, &n_fatorial);
	multiplica_numgrandes(&k_fatorial, &n_k_fatorial, &tmp2);
	divide_numgrandes(&n_fatorial, &tmp2, &result);
	return result;
}

int main(void)
{
	int j, i;
	numerogrande n1, n2, n3, n4;
	char c[3], c2[3];
	scanf("%s %s", c, c2);
	while(strcmp(c, "0") != 0 && strcmp(c2, "0") != 0)
	{
		inicializa_numgrande(&n1);
		inicializa_numgrande(&n2);
		inicializa_numgrande(&n3);
		inicializa_numgrande(&n4);
		j = 0;
		n1.ultimodigito = strlen(c)-1;
		for(i = strlen(c)-1; i >= 0; i--)
		{
			n1.digitos[j] = c[i];
			j++;
		}
		n1.sinal = MAIS;
		j = 0;
		n2.ultimodigito = strlen(c2)-1;
		for(i = strlen(c2)-1; i >= 0; i--)
		{
			n2.digitos[j] = c2[i];
			j++;
		}
		n2.sinal = MAIS;
		soma_numgrandes(&n1, &n2, &n3);
		n4 = comb(&n3, &n1);
		imprime_numgrande(&n4);
		scanf("%s %s", c, c2);
	}
	return 0;
}