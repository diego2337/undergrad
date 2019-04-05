#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
using namespace std;
 
struct BI
{
    char Digits[110];
    int LastDigit;
};
 
void addBI(BI & a, BI & b, BI& c)
{
    for (int i=0; i<110; i++) c.Digits[i] = 0;
    int carry=0;
    c.LastDigit = max(a.LastDigit, b.LastDigit);
    for (int i=0; i<=c.LastDigit; i++)
    {
        c.Digits[i] = (a.Digits[i] + b.Digits[i] + carry)%10;
        carry = (a.Digits[i] + b.Digits[i] + carry)/10;
    }
    if (carry) 
        c.Digits[++c.LastDigit] = carry;
        return; 
}

int compBI(BI &a, BI&b) 
{     
    if (a.LastDigit != b.LastDigit) return a.LastDigit > b.LastDigit;
 
    for (int i=a.LastDigit; i >=0; i--) if (a.Digits[i] != b.Digits[i]) return a.Digits[i] > b.Digits[i];
 
    return -1;
}
int howManyFibs(BI &small, BI &big)
{
    BI *a,*b,*c;
    a = new BI;
    b = new BI;
    c = new BI;
 
    for (int i=0; i<110; i++) a->Digits[i] = b->Digits[i] = 0;
    a->Digits[0] = 1; b->Digits[0] = 1;
    a->LastDigit = 0; b->LastDigit = 0;
 
    int nFibs=0;
    bool reached=false;
    while(1)
    {
 
        if(compBI(*b,small) && compBI(*b, big) < 1)nFibs++;
        else if (compBI(*b, big) == 1) break;
        addBI(*a,*b,*c);        
        swap(b,c);      
        swap(a,c); 
    }
    return nFibs; 
} 

int main() 
{    
    string a,b;     
    BI large, small;    
    while(1)    
    {       
        cin >> a >> b;
        if (a == "0" && b == "0") return 0;
        small.LastDigit = a.size() - 1;
        for (int i=small.LastDigit, j=0; i>=0; i--, j++)small.Digits[i] = a[j] - '0';
        large.LastDigit = b.size() - 1;
        for (int i=large.LastDigit, j=0; i>=0; i--, j++)large.Digits[i] = b[j] - '0';
        cout << howManyFibs(small,large) << endl;
 
    }
    return 0;
}