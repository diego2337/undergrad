#ifndef __COMPLEX_H
#include "Complex.h"
#endif



int main()
{
	Complex z(3,2);
	z.print();
	Complex z2(1,1);
	z = z2;
	//cout << z.a << '\n';
	z = z + z2;
	z.print();
	z = z2 - z;
	z.print();
	
	return 0;
}