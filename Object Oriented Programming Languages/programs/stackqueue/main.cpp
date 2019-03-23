// arquivo: main.cpp

#include "Stack.h"
#include "Queue.h"
#include "Complex.h"
#include "QueueException.h"
#include "StackException.h"

#include <stdio.h>
#include <iostream>



std::ostream& operator << (std::ostream& o, Complex& c)
{
	c.print();
	return o;
}



int main ()
{

       Stack<int> intStack;       

	try
	{
		intStack.push(1);
		intStack.push(2);
		intStack.push(3);
		intStack.push(4);
		intStack.push(5);		
		intStack.push(6);
		int a = intStack.pop();
		int b = intStack.pop();
		int c = intStack.size();

		cout << "\nPilha contem " << c << " elementos\n";

		int d = 9;
		if (!intStack.contains(d))   // contains não precisa ser O(1) por motivos óbvios, ok?
			intStack.push(9);
		if (intStack.isEmpty())	
			cout << "Pilha vazia!";
		
	}
	catch(StackException &exp)
	{
		
		exp.treatment();
	}

	try
	{
		int x = intStack.pop();
		x = intStack.pop();
		x = intStack.pop();
		x = intStack.pop();
		x = intStack.pop();
		x = intStack.pop();
		int c = intStack.size();
		cout << "Pilha contem " << c << " elementos\n";
		intStack.print();
	}
	catch(StackException &exp)
	{
		exp.treatment();
	}

       Stack<Complex> complexStack;       

	try
	{
		complexStack.push(Complex(1,2));
		complexStack.push(Complex(1,3));
		complexStack.push(Complex(1,4));
		complexStack.push(Complex(1,5));
		complexStack.push(Complex(1,6));		
		complexStack.push(Complex(1,7));
		Complex c1 = complexStack.pop();
		Complex c2 = complexStack.pop();
		int c = complexStack.size();

		cout << "Pilha contem " << c << " elementos\n";

		Complex d(1,9);
		if (!complexStack.contains(d))   // contains não precisa ser O(1) por motivos óbvios, ok?
			intStack.push(9);
		if (complexStack.isEmpty())	
			cout << "Fila vazia!";

	}
	catch(StackException &exp)
	{
		
		exp.treatment();
	}

	try
	{
		Complex x = complexStack.pop();
		x = complexStack.pop();
		x = complexStack.pop();
		x = complexStack.pop();
		x = complexStack.pop();
		x = complexStack.pop();
		int c = complexStack.size();
		cout << "Pilha de Complex contem " << c << " elementos\n";
		complexStack.print();
	}
	catch(StackException &exp)
	{
		exp.treatment();
	}

      Queue<int> intQueue;       

	try
	{
		intQueue.enqueue(1);
		intQueue.enqueue(2);
		intQueue.enqueue(3);
		intQueue.enqueue(4);
		intQueue.enqueue(5);		
		intQueue.enqueue(6);
		int a = intQueue.dequeue();
		int b = intQueue.dequeue();
		int c = intQueue.size();

		cout << "Fila contem " << c << " elementos\n";

		int d = 9;
		if (!intQueue.contains(d))   // contains não precisa ser O(1) por motivos óbvios, ok?
			intQueue.enqueue(9);
		if (intQueue.isEmpty())	
			cout << "Fila vazia!";
		
	}
	catch(QueueException &exp)
	{
		
		exp.treatment();
	}

	try
	{
		int x = intQueue.dequeue();
		x = intQueue.dequeue();
		x = intQueue.dequeue();
		x = intQueue.dequeue();
		x = intQueue.dequeue();
		x = intQueue.dequeue();
		int c = intQueue.size();
		cout << "Fila contem " << c << " elementos\n";
		intQueue.print();
	}
	catch(QueueException &exp)
	{
		exp.treatment();
	}

       Queue<Complex> complexQueue;       

	try
	{
		complexQueue.enqueue(Complex(1,2));
		complexQueue.enqueue(Complex(1,3));
		complexQueue.enqueue(Complex(1,4));
		complexQueue.enqueue(Complex(1,5));
		complexQueue.enqueue(Complex(1,6));		
		complexQueue.enqueue(Complex(1,7));
		Complex c1 = complexQueue.dequeue();
		Complex c2 = complexQueue.dequeue();
		int c = complexQueue.size();

		cout << "Fila contem " << c << " elementos\n";

		Complex d(1,9);
		if (!complexQueue.contains(d))   // contains não precisa ser O(1) por motivos óbvios, ok?
			intQueue.enqueue(9);
		if (complexQueue.isEmpty())	
			cout << "Fila vazia!";

	}
	catch(QueueException &exp)
	{
		
		exp.treatment();
	}

	try
	{
		Complex x = complexQueue.dequeue();
		x = complexQueue.dequeue();
		x = complexQueue.dequeue();
		x = complexQueue.dequeue();
		x = complexQueue.dequeue();
		x = complexQueue.dequeue();
		int c = complexQueue.size();
		cout << "Fila de Complex contem " << c << " elementos\n";
		complexQueue.print();
	}
	catch(QueueException &exp)
	{
		exp.treatment();
	}

	

        return 0;
}
