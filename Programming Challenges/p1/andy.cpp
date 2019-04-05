#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <map>
#include <vector>
using namespace std;

int main(void)
{
	char c;
	string word;
	map<string, int> words;
	c = tolower(getchar());
	while(c != EOF)
	{
		word.clear();
		while(!isalpha(c) && c != EOF)
		{
			c = tolower(getchar());
		}
		if(c != EOF)
		{
			word.append(1, c);
			c = tolower(getchar());
			while(isalpha(c) && c != '\n' && c != EOF)
			{
				word.append(1, c);
				c = tolower(getchar());
			}
			words[word]++;
		}
		c = tolower(getchar());
	}
	for(map<string, int>::iterator it = words.begin(); it != words.end(); it++)
	{
		cout << it->first << endl;
	}
	return 0;
}