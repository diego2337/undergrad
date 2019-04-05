#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <stdio.h>
using namespace std;

map<string, int> distancia;
map<string, bool> visited;
vector<string> works;

void findPartners(string work, string name, queue<string> &bfs, int &erdos)
{
	string author;
	for(int i = 0; i < (int) work.size(); i++)
	{
		if(work[i] == '.' && (work[i+1] == ',' || work[i+1] == ':'))
		{
			author.append(1, work[i]);
			i = i + 2;
			while(work[i+1] == ' ')
				i++;
			if(author.compare(name) != 0)
			{
				/* Co-autor */
				if(!visited[author])
				{
					visited[author] = true;
					distancia[author] = (erdos+1);
					bfs.push(author);
					//cout << "inseri na fila " << author << endl;
				}
			}
			author.clear();
		}
		else if(work[i] == ':')
		{
			i = i + work.size();
		}
		else
			author.append(1, work[i]);
	}
}

void breadthsearch(queue<string> &bfs, map<string, list<int> > authors, int &erdos)
{
	int i = 0;
	for(list<int>::iterator it = authors[bfs.front()].begin(); it != authors[bfs.front()].end(); it++)
	{
		//cout << "commit no it " << *it << endl;
		findPartners(works[*it], bfs.front(), bfs, erdos);
	}
}

void find_authors(map<string, list<int> > &authors, string line, int ith_line)
{
	string publisher;
	for(int i = 0; i < (int) line.size(); i++)
	{
		if(line[i] == '.' && (line[i+1] == ',' || line[i+1] == ':'))
		{
			publisher.append(1, line[i]);
			i = i + 2;
			while(line[i+1] == ' ')
				i++;
			authors[publisher].push_back(ith_line);
			publisher.clear();
			/*it = authors.find(publisher);
			if(it != authors.end())
			{
				authors[publisher] = authors[publisher] + 1;
				publisher.clear();
			}
			else
			{
				authors.insert(pair<string, int>(publisher, 1));
				publisher.clear();
			}*/
		}
		else
		{
			publisher.append(1, line[i]);
		}
	}
}

int main(void)
{
	int test_cases, P, N;
	string line;
	/* Key - o nome; value - lista com as linhas onde esse nome aparece */
	map<string, list<int> > authors;
	vector<string> publishers;
	queue<string> bfs;
	cin >> test_cases;
	for(int j = 0; j < test_cases; j++)
	{
		cin >> P >> N;
		authors.clear();
		distancia.clear();
		visited.clear();
		works.clear();
		publishers.clear();
		scanf("\n");
		for(int i = 0; i < P; i++)
		{
			getline(cin, line);
			works.push_back(line);
			find_authors(authors, line, i);
		}
		for(int i = 0; i < N; i++)
		{
			getline(cin, line);
			publishers.push_back(line);
		}
		/*for(map<string, list<int> >::iterator it = authors.begin(); it != authors.end(); it++)
		{
			cout << it->first << "{";
			for(list<int>::iterator it2 = authors[it->first].begin(); it2 != authors[it->first].end(); it2++)
			{
				cout << *it2 << " ";
			}
			cout << "}" << endl;
		}*/
		/* Inicializamos a map de distancia */
		for(map<string, list<int> >::iterator it = authors.begin(); it != authors.end(); it++)
		{
			distancia[it->first] = -1;
			visited[it->first] = false;
		}
		map<string, list<int> >::iterator it = authors.find("Erdos, P.");
		/* Achamos Erdos */
		if(it != authors.end())
		{
			bfs.push(it->first);
			map<string, int>::iterator it2;
			distancia[it->first] = 0;
			visited[it->first] = true;
			while(!bfs.empty())
			{
				breadthsearch(bfs, authors, distancia[bfs.front()]);
				bfs.pop();
			}
		}
		cout << "Scenario " << j+1 << endl;
		for(int i = 0; i < (int) publishers.size(); i++)
		{
			if(distancia[publishers[i]] == -1)
				cout << publishers[i] << " infinity" << endl;
			else
				cout << publishers[i] << " " << distancia[publishers[i]] << endl;
		}
		/*cout << "................" << endl;
		for(vector<string>::iterator it = publishers.begin(); it != publishers.end(); it++)
			cout << *it << endl;*/
	}
	return 0;
}