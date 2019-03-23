
#include "Vector.h"
#include "Complex.h"

#include <iostream>
using namespace std;

int main()
{
  Vector<Complex> v1(10, 10); // argumentos: capacidade, delta

  for (int i = 0; i < 20; i++)
    v1.add(Complex(i, i * 2));

  Vector<int> v2;
  for (int j = 0; j < 5; j++)
	v2.add(j*10);
 
  
    v1.print();
    v2.print();
    
  //v1.union_(v2);
  //cout << v1.print() << endl;
  //cout << v2.print() << endl ;
  //v2.print();
  // v3.print();
  return 0;
}
