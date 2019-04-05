

#include <iostream>
#include <list>
#include <iterator>
#include <numeric>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;
unsigned long no_of_students =0;

double compute(const list<double>& data) {
    double avg = accumulate(data.begin(), data.end(), 0.0) / data.size();
    list<double>::const_iterator it = data.begin();
    double positive = 0.0;    
    double negative = 0.0;
    while(it != data.end()) {
        if(*it >= avg)
            positive += (double) (long) ((*it - avg)*100.0)/100.0;
        else
            negative += (double) (long) ((avg- *it)*100.0)/100.0;
        it++;
    }
    return max<double>(positive, negative);
}

/* main
 *  * */
int main() {
    double exchange = 0.0;
    list<double> data;    
    cin >> no_of_students;
    while(no_of_students != 0) {
        data.clear();    
        while(no_of_students-- > 0) {
            double amount;
            cin >> amount;
            data.push_back(amount);
        }
        exchange = compute(data);
        cout.precision(2);
        cout.setf(ios::fixed,ios::floatfield);
        cout << "$" << exchange << endl;
        cin >> no_of_students;
    }
    return 0;
}