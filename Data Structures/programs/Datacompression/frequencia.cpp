#ifndef __FREQUENCIA_H
#include "frequencia.h"
#endif

Frequencia::Frequencia(char *s)
{
	lengthC = strlen(s);
	msgC = new char[lengthC+1];
	msgD = new char[lengthC+1];
	strcpy(msgC, s);
	// L = new List();
}

void Frequencia::encodes()
{
	int i, j = 0, counter = 1;
	char pos;
	char aux[4];
	pos = msgC[0];
	for(i = 1; i <= lengthC; i++)
	{
		if(pos == msgC[i])
		{
			counter++;
		}
		else
		{
			if(counter != 1)
			{
				sprintf(aux, "%d", counter);
				msgD[j] = aux[0];
				if(strlen(aux) >= 2)
				{
					j++;
					msgD[j] = aux[1];
					if(strlen(aux) == 3)
					{
						j++;
						msgD[j] = aux[2];
					}
				}
				j++;
			}
			msgD[j] = pos;
			j++;
			counter = 1; // resetando o contador para outros caracteres
			pos = msgC[i]; // comecara a partir de uma nova posica do vetor
		}
	}
	msgD[j] = '\0';
		cout << msgD;
	cout << "\n";
}
// sprintf(aux, "%d", counter)