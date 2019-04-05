#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long int fact(int n)
{
    return ((n > 1) ? (n*fact(n-1)) : (1));
}
int main()
{
    int n,k, i;
    while(scanf("%d %d", &n, &k) == 2)
    {
        long long int T, output=1;
        for (i=0; i<k; i++)
        {
            scanf("%lld", &T); 
            output *= fact(T);
        }
        output = fact(n)/output;
        printf("%lld\n", output);
    }
    return 0;
}