#ifndef __FREQUENCIA_H
#define __FREQUENCIA_H



#include <iostream>
#include <stdio.h>
using namespace std;
#include "string.h"

class Frequencia
{
private:
	char *msgC;
	char *msgD;
	int lengthC;
	int lengthD;

public:
	Frequencia(char*);
	void encodes();
};

#endif