#include <stdio.h>
#include <stdlib.h>


int last_digit_factorial(int N)
{
    int i,j,ans=1,a2=0,a5=0,a;
 
    for (i = 1; i <= N; i++)
    {
        j = i;
        /*divide i by 2 and 5*/
        while (j%2==0)
        {
              j /= 2;
              a2++;
        }
        while (j%5==0)
        {
              j/=5;
              a5++;
        }
 
        ans = (ans*(j%10))%10;
    }
 
    a=a2-a5;
 
    for (i = 1; i <= a; i++)
        ans=(ans * 2) %10;
 
    return ans;
}

int main(void)
{
    int num;
    scanf("%d", &num);
    printf("%d\n", last_digit_factorial(num));
    return 0;
}