#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

void park(int movement, int number, stack<int> &cars)
{
	if(movement == 1)
	{
		if(cars.size() >= 10)
			cout << "Nao ha vaga no estacionamento" << endl;
		else
		{
			cars.push(number);
			cout << "Carro estacionado" << endl;
		}
	}
	else if(movement == 2)
	{
		stack<int> aux;
		int count = 0;
		bool found = false;
		for(int i = 0; i < size; i = i + 1)
		{
			if(number == cars.top())
			{
				cars.pop();
				i = i + cars.size() + 10;
				cout << "Carro liberado apos " << count << " movimentos" << endl;
				found = true;
			}
			else
			{
				aux.push(cars.top());
				cars.pop();
				count++;
			}
		}
		if(!found)
			cout << "Carro nao encontrado" << endl;
		size = aux.size();
		for(int i = 0; i < size; i++)
		{
			cars.push(aux.top());
			aux.pop();
		}
	}
}

int main(void)
{
	stack<int> cars;
	int movement, number;
	while(scanf("%d %d", &movement, &number) != EOF)
	{
		park(movement, number, cars);
	}
	return 0;
}