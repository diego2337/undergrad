#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

typedef struct
{
	char license[21];
	int hour, km;
} bill;

bill enters[1000], exits[1000];

void parseLine(string line, int pos)
{
	int i = line.size()-1;
	while(line[i] != ' ')
	{
		i--;
	}
	i--;
	if(line[i] == 'r')
	{
		i = 0;
		while(line[i] != ' ')
		{
			enters[pos].license[i] = line[i];
			i++;
		}
		i++;
		while(line[i] != ':')
			i++;
		i++;
		while(line[i] != ':')
			i++;
		i++;
		enters[pos].hour = 0;
		int k = 0;
		while(line[i] != ':')
		{
			char c = line[i];
			enters[pos].hour = enters[pos].hour * pow(10, k) + atoi(&c);
			i++;
		}
		i++;
		while(line[i] != ' ')
			i++;
		i++;
		while(line[i] != ' ')
			i++;
		i++;
		k = 0;
		enters[pos].km = 0;
		while(i < line.size())
		{
			char c = line[i];
			enters[pos].km = enters[pos].km * pow(10, k) + atoi(&c);
			i++;
			k++;
		}
	}
	else
	{
		i = 0;
		while(line[i] != ' ')
		{
			exits[pos].license[i] = line[i];
			i++;
		}
		i++;
		while(line[i] != ':')
			i++;
		i++;
		while(line[i] != ':')
			i++;
		i++;
		exits[pos].hour = 0;
		int k = 0;
		while(line[i] != ':')
		{
			char c = line[i];
			exits[pos].hour = exits[pos].hour * pow(10, k) + atoi(&c);
			i++;
		}
		i++;
		while(line[i] != ' ')
			i++;
		i++;
		while(line[i] != ' ')
			i++;
		i++;
		k = 0;
		exits[pos].km = 0;
		while(i < line.size())
		{
			char c = line[i];
			exits[pos].km = exits[pos].km * pow(10, k) + atoi(&c);
			i++;
			k++;
		}
	}
}

int main(void)
{
	int N, fare[24];
	string line;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		scanf("\n");
		for(int j = 0; j < 24; j++)
		{
			cin >> fare[j];
		}
		scanf("\n");
		getline(cin, line);
		int count = 0;
		while(line[0] != '\n' && count <= 1000)
		{
			parseLine(line, i);
			cout << "license" << enters[0].license << endl;
			cout << "hours" << enters[0].hour << endl;
			cout << "km" << enters[0].km << endl;
			cout << endl;
			cout << "license" << exits[0].license << endl;
			cout << "hours" << exits[0].hour << endl;
			cout << "km" << exits[0].km << endl;
			getline(cin, line);
			if(ios::eofbit)
				break;
			count++;
		}
	}
}