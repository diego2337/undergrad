#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <map>
using namespace std;

bool highest(int card1, int card2)
{

}

bool consecutive(map<int, char> hand)
{

}

bool same_suit(map<int, char> hand, int size)
{

}

void find_hand(map<int, char> hand, int strength)
{
	/* Straight flush */
}

int main(void)
{
	char first_char, first_number;
	int strength, strength2;
	string final_result;
	map<int, char> hand1, hand2;
	while(scanf("%c %c", &first_number, &first_char) != EOF)
	{
		hand1.insert(pair<int, char>(atoi(&first_number), first_char));
		/* Insere para o Black */
		for(int i = 0; i < 4; i++)
		{
			cin >> first_number >> first_char;
			hand1.insert(pair<int, char>(atoi(&first_number), first_char));
		}
		/*for(map<char, char>::iterator it = hand1.begin(); it != hand1.end(); it++)
		{
			cout << it->first << " => " << it->second << "\n";
		}*/
		for(int i = 0; i < 5; i++)
		{
			cin >> first_number >> first_char;
			hand2.insert(pair<int, char>(atoi(&first_number), first_char));
		}
		cout << "-------------" << endl;
		for(map<int, char>::iterator it = hand2.begin(); it != hand2.end(); it++)
		{
			cout << it->first << " => " << it->second << "\n";
		}
		return 0;
		find_hand(hand1, strength);
		find_hand(hand2, strength2);
		//find_winner(hand1, hand2, final_result);
		cout << final_result << endl;
	}
	return 0;
}