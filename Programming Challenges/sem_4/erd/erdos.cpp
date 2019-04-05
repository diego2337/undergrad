#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

/* The approach to this solution is as it follows:

	- Find the line in which Erdos is; from here, find the co-authors and map them to key 1;
	- From here, every author must be found in the database and his/her co-authors must be mapped with key k+1;
	- Scan the publishers; if the kth publisher is in the map, print the key associated; else, if he is Erdos, his key is 0.
	Finally, if he is not in the map then he is 'infinity'. */

void find_author_partners(map<string, int> &erdos, string works, vector<string> &db, int l,
 vector<string> &publishers, int erdos_number, string author_name)
{
	//cout << "nome do autor: " << author_name << endl;
	string author;
	for(int i = 0; i < (int) works.size(); i++)
	{
		if(works[i] == '.' && (works[i+1] == ',' || works[i+1] == ':'))
		{
			author.append(1, works[i]);
			i = i + 2;
			while(works[i] == ' ')
				i++;
			if(author.compare(author_name) != 0)
			{
				for(int j = 0; j < (int) publishers.size(); j++)
				{
					size_t pos = publishers[j].find(author);
					if(pos != string::npos && author.compare("Erdos, P.") == 0)
					{
						erdos.insert(pair<string, int>(author, 0));
						publishers.erase(publishers.begin()+j);
					}
					else if(pos != string::npos)
					{
						erdos.insert(pair<string, int>(author, erdos_number+1));
						publishers.erase(publishers.begin()+j);
					}
				}
			}
			//cout << "autor: " << author << endl;
			author.clear();
		}
		else if(works[i] == ':')
		{
			i = i + works.size();
		}
		author.append(1, works[i]);
	}
}

void print_map(map<string, int> erdos)
{
	cout << "------------------------------" << endl;
	for(map<string, int>::iterator it = erdos.begin(); it != erdos.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << "------------------------------" << endl;
}

void count_erdos(vector<string> works, vector<string> publishers, map<string, int> &erdos)
{
	/* Ache erdos */
	size_t pos;
	int j;
	for(int i = 0; i < (int) works.size(); i++)
	{
		/* Ache SOMENTE a primeira ocorrência de Erdos */
		pos = works[i].find("Erdos, P.");
		if(pos != string::npos)
		{
			j = i;
			i = i + works.size();
		}
	}
	if(pos != string::npos)
	{
		erdos.insert(pair<string, int>("Erdos, P.", 0));
		// find_author_partners(erdos, works[j], works, j, publishers, 0, "Erdos, P.");
		for(map<string, int>::iterator it = erdos.begin(); it != erdos.end(); it++)
		{
			for(j = 0; j < (int) works.size(); j++)
			{
				pos = works[j].find(it->first);
				if(pos != string::npos)
				{
					//if(it == erdos.begin()) cout << "put my name in bold " << endl;
					find_author_partners(erdos, works[j], works, j, publishers, it->second, it->first);
					//print_map(erdos);
				}
			}
		}
	}
}

void print_erdos(map<string, int> erdos, int test_cases, vector<string> publishers)
{
	bool found;
	cout << "Scenario " << test_cases << endl;
	for(int i = 0; i < (int) publishers.size(); i++)
	{
		found = false;
		for(map<string, int>::iterator it = erdos.begin(); it != erdos.end(); it++)
		{
			if(publishers[i].compare(it->first) == 0)
			{
				cout << it->first << " " << it->second << endl;
				found = true;
			}
		}
		if(!found)
			cout << publishers[i] << " infinity" << endl;
	}
}

int main(void)
{
	int test_cases, P, N;
	map<string, int> erdos;
	vector<string> *works, *publishers;
	string names;
	cin >> test_cases;
	for(int j = 0; j < test_cases; j++)
	{
		cin >> P >> N;
		works = new vector<string>[P];
		publishers = new vector<string>[N];
		scanf("\n");
		for(int i = 0; i < P; i++)
		{
			getline(cin, names);
			works->push_back(names);
		}
		for(int i = 0; i < N; i++)
		{
			getline(cin, names);
			publishers->push_back(names);
		}
		count_erdos(*works, *publishers, erdos);
		print_erdos(erdos, j+1, *publishers);
		delete []works;
		delete []publishers;
		erdos.clear();
	}
	return 0;
}