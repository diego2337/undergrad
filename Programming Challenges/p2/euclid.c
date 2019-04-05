/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int ulli;

ulli mdc(ulli A, ulli B)
{
	if(B == 0)
		return A;
	else
		return mdc(B, (A%B));
}

ulli mmc(ulli A, ulli B)
{
	return (A*B)/mdc(A, B);
}

int main(void)
{
	return 0;
}*/

#include <stdio.h>

int d,x,y;
void extEuclid(int,int);

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        extEuclid(a,b);
        printf("%d %d %d\n",x,y,d);
    }
    return 0;
}

void extEuclid(int a,int b)
{
    int x1;

    if(b==0)
    {
        d=a;
        x=1;
        y=0;
        return;
    }
    extEuclid(b,a%b);
    x1 = x-(a/b) * y;
    x = y;
    y = x1;
}