// arquivo: main.cpp


#include "DoubleList.h"
#include "Complex.h"

#include <stdio.h>
#include <iostream>

class Teste
{
	public:
		int x;
                Teste () {  }
		Teste(int value) 
		{ 
			x = value;
		}
	
		bool operator == (const Teste& v) const
		{
			if (x == v.x)
				return true;
			else
				return false;
		}
};


std::ostream& operator << (std::ostream& o, Teste& t)
{
        o << t.x;
}

std::ostream& operator << (std::ostream& o, Complex& c)
{
	c.print();
	return o;
}



int main ()
{
       // instanciando um objeto da classe IntList

        DoubleList<int> intList;       

	intList.addHead(1);
	intList.addTail(2);
	intList.addTail(3);
	intList.addTail(4);
	
	intList.print();
	
	
	intList.deleteHead();
	intList.deleteTail();

	intList.print();
	
	intList.deleteNode(3);
	intList.deleteNode(5);
	intList.deleteNode(2);
	
	intList.print();

        DoubleList<Complex> complexList;

 	Complex x (1,2);
	Complex y (4,8);
	Complex z (3,6);

	complexList.addHead(x);
	complexList.addHead(y);
	complexList.addTail(z);
	complexList.deleteHead();
	complexList.deleteNode(z);


	complexList.print();

        return 0;
}
