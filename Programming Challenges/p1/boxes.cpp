#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	vector<stack<int> > boxes;
	stack<int> aux;
	int N, P, Q, box, min, min_index, inventory, count, j;
	scanf("%d %d", &N, &P);
	while(N != 0 && P != 0)
	{
		boxes.clear();
		inventory = 0;
		count = 0;
		for(int i = 0; i < P; i++)
			boxes.push_back(aux);
		for(int i = 0; i < P; i++)
		{
			scanf("%d", &Q);
			for(int j = 0; j < Q; j++)
			{
				scanf("%d", &box);
				if(box == 1)
					inventory = i;
				boxes[i].push(box);
			}
		}
		if(inventory == 0 || inventory == P-1 || boxes[inventory-1].empty() || boxes[inventory+1].empty())
		{
			while(boxes[inventory].top() != 1)
			{
				boxes[inventory].pop();
				count++;
			}
		}
		else
		{
			if(boxes[inventory].size() > boxes[inventory-1].size() && boxes[inventory].size() > boxes[inventory+1].size())
			{
				while(boxes[inventory].top() != 1)
				{
					boxes[inventory].pop();
					count++;
				}
			}
			else
			{
				if(boxes[inventory-1].size() > boxes[inventory+1].size())
				{
					j = inventory-1;
				}
				else
					j = inventory+1;
				while(!boxes[j].empty())
				{
					boxes[j].pop();
					count++;	
				}
				while(boxes[inventory].top() != 1)
				{
					boxes[inventory].pop();
					count++;
				}
			}
		}
		cout << count << endl;
		scanf("%d %d", &N, &P);
	}
	return 0;
}