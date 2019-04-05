#include <stdio.h>
#include <time.h>

int main(void)
{
  int i, j;
  int r, l;
  srand(time(NULL));
  for(i = 0; i < 9; i++)
  {
    r = rand() % 1000 + 1;
    printf("%d\n", r);
    for(j = 0; j < r; j++)
    {
      l = rand() % 10000 + 9000;
      printf("%d.", l);
      l = rand() % 99;
      printf("%d\n", l);
    }
  }
  printf("0");
  return 0;
}