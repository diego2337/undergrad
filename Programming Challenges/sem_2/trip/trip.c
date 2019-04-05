#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double redistribute(double costs[1005], double equal, int students)
{
  int i;
  double difference = 0.00, min = 0.00, max = 0.00;
  for(i = 0; i < students; i++)
  {
    difference = costs[i] - equal;
    /* O casting abaixo é utilizado para garantir o equilíbrio de um centavo (0.01) */
    if(difference < 0.00) /* Significa que a pessoa tem de ser reembolsada */
    {
      min = min - (double)(long) (difference * 100.0) / 100.0;
    }
    else
    {
      max = max + (double)(long) (difference * 100.0) / 100.0;
    }
  }
  if(min > max)
    return min;
  else
    return max;
}

int main(void)
{
  int students, i;
  double costs[1005], count, equal;
  scanf("%d", &students);
  while(students != 0)
  {
    count = 0.00;
    equal = 0.00;
    for(i = 0; i < students; i++)
    {
      scanf("%lf", &costs[i]);
    }
    for(i = 0; i < students; i++)
    {
      equal += costs[i];
    }
    equal = equal / students;
    count = redistribute(costs, equal, students);
    printf("$%.2lf\n", count);
    scanf("%d", &students);
  }
  return 0;
}