#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void read_names(vector<string> &old_names, vector<string> &new_names)
{
	char c;
	string name;
	/* Reads the first double quotes */
	while((c = getchar()) != '\"');
	/* Reads the first name */
	while((c = getchar()) != '\"')
	{
		name.append(1, c);
	}
	old_names.push_back(name);
	name.clear();
	/* Reads the new name's first double quotes */
	while((c = getchar()) != '\"');
	/* Reads the first name */
	while((c = getchar()) != '\"')
	{
		name.append(1, c);
	}
	new_names.push_back(name);
}

void print_line(const string &text, const vector<string> &new_names, const vector<int> &indexes)
{
	int j = 0;
	for(int i = 0; i < (int)text.size();)
	{
		if(j < (int)indexes.size() && i == indexes[j])
		{
			cout << new_names[indexes[j+2]];
			i = indexes[j+1];
			j = j + 3;
		}
		else
		{
			cout << text[i];
			i++;
		}
	}
}

void find_patterns(const string text, const vector<string> &old_names, vector<int> &indexes)
{
	int j, k, l;
	string name;
	for(int i = 0; i < (int)old_names.size(); i++)
	{
		j = 0;
		k = 0;
		l = 0;
		name.assign(old_names[i]);
		while(j != (int)text.size())
		{
			/* If yes, pattern was found */
			if(k == (int)name.size())
			{
				/* Index of the first character */
				indexes.push_back(l);
				/* Index of the last character */
				indexes.push_back(j);	
				/* Index to the position in new_names */
				indexes.push_back(i);
				k = 0;
			}
			else if(text[j] == name[k])
			{
				/* Index to the first character */
				if(k == 0)
					l = j;
				k++;
			}
			else
			{
				k = 0;
			}
			j++;
		}
		if(k == (int)name.size())
		{
			/* Index of the first character */
			indexes.push_back(l);
			/* Index of the last character */
			indexes.push_back(j);	
			/* Index to the position in new_names */
			indexes.push_back(i);
			k = 0;
		}
	}
}

int main(void)
{
	int N, M;
	vector<string> old_names, new_names;
	/* Stores the first index of the old_name and the last, respectively */
	vector<int> indexes;
	string text;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		read_names(old_names, new_names);
	}
	cin >> M;
	for(int i = 0; i <= M; i++)
	{
		getline(cin, text);
		find_patterns(text, old_names, indexes);
		print_line(text, new_names, indexes);
		cout << endl;
		indexes.clear();
	}
	/*for(int i = 0; i < N; i++)
	{
		cout << old_names[i] << endl;
		cout << new_names[i] << endl;
	}*/
	return 0;
}