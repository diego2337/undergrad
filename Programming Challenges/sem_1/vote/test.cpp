#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>
 
using namespace std;
 
#define NBALLOTS 1000
 
typedef vector< vector< int > > twod_vector;
 
vector< int > calculate(vector< int > &votes, int ncand, bool atleast_50)
{
	vector< int > winners;
 
	int total = votes.size();
	int max = 0;
	for(int i = 0; i < ncand; i++) {
		int vote_count = count(votes.begin(), votes.end(), i);
		bool cond = !atleast_50 || (vote_count > total / 2);
		if(vote_count > 0 &&
				vote_count >= max &&
				cond) {
			max = vote_count;
			winners.push_back(i);
		}
	}
 
	return winners;
}
 
bool compare(pair< int, int > a, pair< int, int > b)
{
	return a.second < b.second;
}
 
map< int, int > vote_map(vector< int > &votes)
{
	map< int, int > table;
 
	for(vector< int >::iterator p = votes.begin();
			p < votes.end();
			p++) {
		table[*p]++;
	}
 
	return table;
}
 
vector< int > least_votes(vector< int > &votes)
{
	map< int, int > table = vote_map(votes);
	vector< int > min_keys;
	int min_value =
		min_element(table.begin(), table.end(), compare)->second;
 
	map< int, int >::iterator p;
	for( p = table.begin(); p != table.end(); p++ ) {
		if(p->second == min_value) {
			min_keys.push_back(p->first);
		}
	}
 
	return min_keys;
}
 
void eliminate(twod_vector &ballots, int value)
{
	for(int i = 0; i < (int) ballots.size(); i++) {
		for(int j = 0; j < (int) ballots.at(i).size(); j++) {
			if(ballots.at(i).at(j) == value) {
				for(int k = i;
					k < (int) ballots.size() - 1;
					k++) {
					ballots.at(k).at(j)
						= ballots.at(k + 1).at(j);
				}
			}
		}
	}
}
 
void eliminate(twod_vector &ballots)
{
	vector< int > min_values = least_votes(ballots.at(0));
 
	for(vector< int >::iterator p = min_values.begin();
			p != min_values.end();
			p++) {
		eliminate(ballots, *p);
	}
}
 
bool draw(vector< int > &votes)
{
	if(!votes.size()) {
		return true;
	}
 
	map< int, int > table = vote_map(votes);
	map< int, int >::iterator p = table.begin();
	int n = p->second;
	p++;
	for(; p != table.end(); p++) {
		if( n != p->second ) {
			return false;
		}
	}
 
	return true;
}
 
int main(int argc, char *argv[])
{
	twod_vector ballots;
	int ncases;
	cin>>ncases;
	cin.ignore();
	string dummy;
	getline(cin, dummy);
 
	for(int i = 0; i < ncases; i++) {
		int ncand;
		cin>>ncand;
		cin.ignore();
 
		vector< string > candidates(ncand);
		for(int j = 0; j < ncand; j++) {
			getline(cin, candidates.at(j));
		}
 
		twod_vector ballots(ncand);
		string str;
		istringstream iss;
		for(int j = 0; j < NBALLOTS; j++) {
			getline(cin, str);
 
			if(str == "") {
				break;
			}
			iss.str(str);
 
			for(int k = 0; k < ncand; k++) {
				int value = *istream_iterator< int >(iss);
				ballots.at(k).push_back(
						value - 1
						);
			}
			iss.clear();
		}
 
		vector< int > winners;
		int j = 0;
		while(winners.size() == 0) {
			if(draw(ballots.at(0))) {
				winners = calculate(ballots.at(0),
						ncand,
						false);
				break;
			}
 
			winners = calculate(ballots.at(0), ncand, true);
			eliminate(ballots);
			j++;
		}
 
		if(!ballots.at(0).size()) {
			for(int k = 0; k < ncand; k++) {
				winners.push_back(k);
			}
		}
 
 
 
		sort(winners.begin(), winners.end());
		if(i > 0) {
			cout<<endl;
		}
		vector< int >::const_iterator p;
		for(p = winners.begin(); p < winners.end(); p++) {
			cout<<candidates.at(*p)<<endl;
		}
	}
 
	return 0;
}