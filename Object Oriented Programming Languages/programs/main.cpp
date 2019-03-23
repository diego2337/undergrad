#include "MyString.h"
#include <stdio.h>

int main(void)
{
	MyString<char> doh(6, "D'OH!");
	MyString<char> wooho(7, "WOOHO!");
	MyString<char> haha(wooho);
	doh.print();
	wooho.print();
	//wooho = doh;
	//wooho.print();
	if(wooho != doh)
		cout << 1;
	else
		cout << 0;
	return 0;
}