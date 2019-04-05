#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void redistribute(int costs[1000], int equal, int cents, int students, int *count)
{
  int i;
  for(i = 0; i < students; i++)
  {
    if(costs[i] > equal)
    {
      *count += (costs[i] - equal);
      /* Desconsidera-se a diferença entre um centavo */
      if(cents > 1)
      {
        *count--;
      }
    }
  }
}

int main(void)
{
  int students, i, j, costs[1000], equal, count, cents;
  char money[7], exact_amount[5], decimal_amount[2];
  scanf("%d", &students);
  while(students != 0)
  {
    count = 0;
    equal = 0;
    for(i = 0; i < students; i++)
    {
      scanf("%s", money);
      j = 0;
      while(money[j] != '.')
      {
        exact_amount[j] = money[j];
        j++;
      }
      while(j < strlen(money))
      {
        decimal_amount[j] = money[j];
        j++;
      }
      costs[i] = atoi(exact_amount)*100 + atoi(decimal_amount);
    }
    for(i = 0; i < students; i++)
      equal += costs[i];
    cents = equal % students;
    equal = equal / students; 
    redistribute(costs, equal, cents, students, &count);
    printf("$%d.%02d\n", count/100, count%100);
    scanf("%d", &students);
  }
  return 0;
}