#ifndef PATRICIA_H
#include "Patricia.h"
#endif

int main()
{
	 Patricia p;
	 char s[100];

	 scanf("%s[^\n]", s);

	 while(strcmp(s,"fim")!=0){
	    p.add(s);
	    p.imprime(p.retRaiz());
	    scanf("\n%s[^\n]", s);
	 }

	return 0;
}

