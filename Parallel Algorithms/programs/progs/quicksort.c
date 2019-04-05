#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int separa(int v[], int p, int r)
{
   int c = v[p], i = p+1, j = r, t;
   while(/*A*/ i <= j)
   {
      if(v[i] <= c)
         ++i;
      else if(c < v[j]) 
         --j; 
      else
      {
         t = v[i], v[i] = v[j], v[j] = t;
         ++i; --j;
      }
   }
   // agora i == j+1                 
   v[p] = v[j], v[j] = c;
   return j; 
}

void quicksort(int v[], int p, int r)
{
   int j;                 // 1
   if(p < r)                      // 2
   {
      printf("{");
      for(j = p; j <= r; j++)
      {
         printf("%d ", v[j]);
      }
      printf("}\n");
      j = separa(v, p, r);       // 3
      quicksort(v, p, j-1);      // 4
      quicksort(v, j+1, r);      // 5
   }
}

int main(void)
{
   int v[MAX], n, k, i, j;
   scanf("%d", &k);
   for(i = 0; i < k; i++)
   {
      scanf("%d", &n);
      for(j = 0; j < n; j++)
      {
         scanf("%d", &v[j]);
      }
      quicksort(v, 0, n-1);
      printf("%d ", n);
      for(j = 0; j < n; j++)
      {
         printf("%d ", v[j]);
      }
      printf("\n");
   }
   return 0;
}