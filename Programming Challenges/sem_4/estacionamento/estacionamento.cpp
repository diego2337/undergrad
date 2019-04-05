#include <iostream>
#include <stack>
#include <stdbool.h>
#include <stdio.h>

using namespace std;

int main(void)
{
    stack<int> cars;
    int movement, number;
    while(scanf("%d %d", &movement, &number) != EOF)
    {
        //park(cars, movement, number);
        //park(cars, movement, number);
        if(movement == 1)
        {
            /* push */
            if(cars.size() == 10)
            {
                cout << "Nao ha vaga no estacionamento" << endl;
            }
            else
            {
                cars.push(number);
                cout << "Carro estacionado" << endl;
            }
        }
        else if(movement == 2)
        {
            int i, count = 0, j;
            bool found = false;
            /* pop */
            stack<int> aux;
            j = cars.size();
            for(i = 0; i < j; i++)
            {
                if(cars.top() == number)
                {
                    i = cars.size()+10; 
                    found = true;
                }
                count++;
                if(!found)
                    aux.push(cars.top());
                cars.pop();
            }
            if(found)
            {
                count=count-1;
                cout << "Carro liberado apos " << count << " movimentos" << endl;
            }
            else
                cout << "Carro nao encontrado" << endl;
            for(i = 0; i < (int)aux.size(); i++)
            {
                cars.push(aux.top());
                aux.pop();
            }
        }
    }
    return 0;
}