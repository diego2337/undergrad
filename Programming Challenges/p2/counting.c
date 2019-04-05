#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool aa[1000000];
bool solve(int n)
{
    if(n%7==0)  return true;
    int t=n;
    while(t)
    {
        if(t%10==7)  return true;
        t/=10;
    }    
    return false;
}  
void calc()
{
	int i;
    for(i=1;i<1000000;i++)
    {
        if(solve(i))  aa[i]=true;
        else  aa[i]=false;
    }    
    
}      
int main()
{
    int n,m,k;
    int t;
    int cnt;
    calc();
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        if(n==0&&m==0&&k==0) break;
        t=m;
        cnt=0;
        while(1)
        {
            if(aa[t])cnt++;
            if(cnt==k)
            {
                printf("%d\n",t);
                break;
            }  
            if(n==m)
            {
                t+=2*(m-1); 
                continue;
            }  
            if(m==1)
            {
                t+=2*(n-m);
                continue;
            }      
            t+=2*(n-m);
            if(aa[t])cnt++;
            if(cnt==k)
            {
                printf("%d\n",t);
                break;
            }  
               
            t+=2*(m-1);  
        }    
    } 
    return 0;   
}    

/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void count(int n, int m, int k)
{
	unsigned long long int num = 1;
	int person = it = 1;
	for()
	{
		num++;
		if(person == m)
		{
			if(it == k)
			{
				printf("%llu\n", num);
			}
		}
		else
		{
			person = (person % m) + 1;
		}
	}
}

int main(void)
{
	int n, m, k, test_cases=1;
	scanf("%d %d %d", &n, &m, &k);
	while(n != 0 && m != 0 && k != 0 && test_cases < 101)
	{
		count(n, m, k);
		scanf("%d %d %d", &n, &m, &k);
	}
	return 0;
}*/