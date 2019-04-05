#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int nc, np;
int p[1000][20];
int vote[20];
int totalvotes;
int valid[20];
char s[100];
char cname[20][80];

void count(void)
{
int i,j; totalvotes =0;
for(i=0;i<20;i++) vote[i] = 0;

for(i=0;i<np;i++)
{
for(j=0; (j<20)&&(valid[p[i][j]]==0);j++);
if( valid[p[i][j]] )
{
vote[p[i][j]]++;
totalvotes++;
}
}
}

int iswinner(void)
{
int i,temp;
for(i=0;i<nc;i++)
if( valid[i] )
{
if( vote[i] / totalvotes > .50 )
{ printf("%s", cname[i]);
return 1; }
else temp = vote[i];
}

for(i=0;i<nc;i++)
if( valid[i] )
if( temp != vote[i])
return 0;

for(i=0;i<nc;i++)
if( valid[i] )
printf("%s\n", cname[i]);
return 1;
}

void main()
{
int numoftest;
int i,j,x,k,quit,min;

scanf("%d",&numoftest);

for(x=0;x<numoftest;x++)
{
nc = 0; np = 0;
for(i=0;i<1000;i++)
for(j=0;j<20;j++)
p[i][j]=0;
for(i=0;i<20;i++)
{ vote[i] = 0;
valid[i] = 0; }
for(i=0;i<20;i++)
for(j=0;j<80;j++)
cname[i][j] = 0;

scanf("%d\n",&nc);
for(i=0;i<nc;i++)
{ gets(cname[i]);
valid[i]=1;}


gets(s);
k=0;
while( strlen(s) > 0)
{ for (i=0;i<strlen(s)+1;i++)
{
if(( s[i] >= '0' ) && ( s[i] <= '9'))
p[np][k] = p[np][k] * 10 + (s[i]-'0');
else
p[np][k++]--; }
gets(s);
k=0;
np++; }

quit = 0;
while( quit == 0)
{ count();
if( iswinner() == 0 )
{
min = 9999;
for(i=0;i<nc;i++)
if( valid[i] )
if( min > vote[i])
min = vote[i];

for(i=0;i<nc;i++)
if( valid[i] )
if( min == vote[i])
valid[i] = 0;
}
else
{ quit = 1;
break;}
}
if( x < numoftest-1) printf("\n");
if( x == numoftest) exit(0);
}
} 