#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 10000

int get_x_bits(int msb, int lsb, unsigned long long int *elemento)
{
    return ((*elemento >> lsb) & ~(~0 << (msb-lsb+1))); 
}

unsigned long long int *countingsort(unsigned long long int A[], unsigned long long int k, int n, int a[])
{
    int i, *C;
    unsigned long long int *B;
    B = (unsigned long long int*)malloc(n*sizeof(unsigned long long int));
    C = (int*)malloc((k+1)*sizeof(int));
    for(i = 0; i <= k; i++)
        C[i] = 0;
    for(i = 0; i < n; i++)
        C[a[i]] = C[a[i]] + 1;
    for(i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for(i = n-1; i >= 0; i--)
    {
        B[C[a[i]]-1] = A[i];
        C[a[i]] = C[a[i]] - 1;
    }
    return B;
}

unsigned long long int *radixsort(unsigned long long int A[], int n) 
{
    int i, j, maior, *a, d = 0;
    a = (int*)malloc(n*sizeof(int));
    for(i = 0; i < 8; i++)
    {
        maior = 0;
        for(j = 0; j < n; j++)
        {
            a[j] = get_x_bits(d+7, d, &A[j]);
            if(a[j] > maior)
                maior = a[j];
        }
        A = countingsort(A, maior, n, a);
        d += 8;
    }
    return A;
}

int main(int argc, char const *argv[])
{
    if(argv[1] == NULL || argv[2] == NULL)
    {
        printf("ERRO! Informe um arquivo de entrada/saida ao executar o programa!\n");
        exit(0);
    }
    else
    {
        FILE *fin, *fout;
        struct timeval  tv1, tv2; /* variáveis para calcular o tempo de execução*/
        int i, n; /* variáveis de apoio */
        unsigned long long int *v; /* vetor para guardar os numeros de entrada */
        fin = fopen(argv[1], "r");
        fout = fopen(argv[2], "w");
        
        printf("Entre com o tamanho do vetor a ser ordenado: ");
        scanf("%d", &n);
        v = (unsigned long long int*)malloc(n*sizeof(unsigned long long int));
        for(i = 0; i < n; i++)
        {
            fscanf(fin, "%llu", &v[i]);
        }
        gettimeofday(&tv1, NULL);
        v = radixsort(v, n);
        gettimeofday(&tv2, NULL);
        for(i = 0; i < n; i++)
        {
            fprintf(fout, "%llu\n", v[i]);
        }
        fclose(fin);
        fclose(fout);
	free(vector);
        printf ("Tempo total = %f segundos\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
    }
    return 0;
}
