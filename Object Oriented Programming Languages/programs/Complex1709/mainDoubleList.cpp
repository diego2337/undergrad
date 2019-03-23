// arquivo: main.cpp


#include "DoubleList.h"
#include "Complex.h"
#include "DoubleListException.h"
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

       DoubleList<int> list;       

	try
	{
		list.addHead(1);
		list.print();
		list.addTail(2);
		list.print();	
		list.addTail(3);
		list.print();
		list.addTail(4);
		list.print();
		list.addHead(0);
		list.print();
	}
	catch(DoubleListException &exp)
	{
		
		exp.treatment();
	}

	try
	{
		list.deleteNode(4);
		list.print();
		list.deleteNode(7);			
		list.print();
		list.deleteNode(1);
		list.print();
		list.deleteNode(2);
		list.print();
		list.deleteHead();
		list.print();
		list.deleteTail();

		
	}
	catch(DoubleListException &exp)
	{
		exp.treatment();
	}


	list.print();

        DoubleList<Complex> complexList;

 	Complex x (1,2);
	Complex y (4,8);
	Complex z(x);
	Complex w(y);

	try
	{
		complexList.addHead(x);
		complexList.addHead(y);  
		complexList.addTail(z);  
		complexList.addTail(w);   
		complexList.print();
	}
	catch(DoubleListException &exp)
	{
		exp.treatment();
	}
	
	try
	{

		complexList.deleteHead();
		complexList.print();
		complexList.deleteNode(z);
		complexList.print();
		complexList.deleteNode(w);
		complexList.print();
		complexList.deleteNode(Complex(9,10));

		
	}
	catch(DoubleListException &exp)
	{
		exp.treatment();
	}
	
	complexList.print();
	

        return 0;
}
