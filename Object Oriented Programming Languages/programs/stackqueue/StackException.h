#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H

#include <stdlib.h>
#include <iostream>
using namespace std;

class StackException{
public:
	StackException(int t_exception)
	{
		this->t_exception = t_exception;
	}
	void treatment();
	int t_exception;

};

void StackException::treatment()
{
	switch(this->t_exception)
	{
		case 0:
			cout << "Node alocation problem.\n";
			break;
		case 1:
			cout << "The stack is empty.\n";
			break;
		default:
			cout << "Unknown error. Exiting program.\n";
			exit(0);
	}
}

#endif