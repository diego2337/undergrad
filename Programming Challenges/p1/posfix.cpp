#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	stack<char> temp;
	char c;
	int N;
	scanf("%d", &N);
	scanf("\n");
	for(int i = 0; i < N; i++)
	{
		c = getchar();
		while(!temp.empty())
			temp.pop();
		while(c != '\n')
		{
			if(isalpha(c) || isdigit(c))
			{
				cout << c;
			}
			else if(c == '*' || c == '^' || c == '-' || c == '+' || c == '/' || c == '(')
			{
				switch(c)
				{
					case '+':
						while(!temp.empty() && (temp.top() == '*' || temp.top() == '^' || temp.top() == '/' || temp.top() == '-'))
						{
							cout << temp.top();
							temp.pop();
						}
						temp.push(c);
						break;
					case '-':
						while(!temp.empty() && (temp.top() == '*' || temp.top() == '^' || temp.top() == '/' || temp.top() == '+'))
						{
							cout << temp.top();
							temp.pop();
						}
						temp.push(c);
						break;
					case '*':
						while(!temp.empty() && (temp.top() == '^' || temp.top() == '/' || temp.top() == '*'))
						{
							cout << temp.top();
							temp.pop();	
						}
						temp.push(c);
						break;
					case '/':
						while(!temp.empty() && (temp.top() == '^' || temp.top() == '*' || temp.top() == '/'))
						{
							cout << temp.top();
							temp.pop();	
						}
						temp.push(c);
						break;
					case '^':
						while(!temp.empty() && (temp.top() == '^'))
						{
							cout << temp.top();
							temp.pop();	
						}
						temp.push(c);
						break;
					case '(':
						temp.push(c);
						break;
				}
			}
			else if(c == ')')
			{
				while(!temp.empty() && (temp.top() != '('))
				{
					cout << temp.top();
					temp.pop();
				}
				temp.pop();
			}
			c = getchar();
		}
		while(!temp.empty())
		{
			cout << temp.top();
			temp.pop();
		}
		cout << endl;
	}
	return 0;
}
