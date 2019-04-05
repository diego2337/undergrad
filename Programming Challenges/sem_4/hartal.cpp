#include<iostream>
#define MAX 3650
using namespace std;

int t, n, p;
bool hartals[MAX];

void solve()
{
        int hartal, counter = 0;
        for(int i=0; i<p; i++)
        {
                cin >> hartal;
                for(int j=1; j<=n; j++)
                        if(j%hartal == 0)
                                hartals[j] = true;
        }
       
        for(int i=1; i<=n; i++)
        {
                if(hartals[i] && i%7 != 0 && i%7 != 6)
                        counter++;
                       
        }
        cout << counter << endl;
}

void setToFalse()
{
        for(int i = 1; i<=n; i++)
                hartals[i] = false;
}

void read()
{
        cin >> t;
        while(t--)
        {
                cin >> n >> p;
                setToFalse();
                solve();
        }      
}

int main()
{
        read();
        return 0;
}
