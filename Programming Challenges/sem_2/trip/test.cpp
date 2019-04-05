#include <iostream>
#include <iterator>
#include <cmath>
#include <vector>
#include <numeric>
 
using namespace std;
 
int main(int argc, char *argv[])
{
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);
 
	int count;
	cin>>count;
	while(count != 0) {
		vector< double > v;
		for(int i = 0; i < count; i++) {
			v.push_back(*istream_iterator< double >(cin));
		}
 
		double avg = accumulate(v.begin(), v.end(), 0.0) / v.size();
		double low = 0, high = 0;
		for(int i = 0; i < count; i++) {
			double diff = v.at(i) - avg;
 
			if(diff < 0) {
				low -= ceil(diff * 100) / 100;
			} else {
				high += floor(diff * 100) / 100;
			}
		}
 
		cout<<"$"<<(low > high? low : high)<<endl;
 
		cin>>count;
	}
 
	return 0;
}