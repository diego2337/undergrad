#ifndef __COMPLEX_H
#define __COMPLEX_H
#include <stdio.h>
#include <iostream>
using namespace std;

class Complex
{
public:
	float a;
	float b;
	Complex()
	{
		this->a = 0;
		this->b = 0;
	}
	Complex(float a, float b)
	{
		this->a = a;
		this->b = b;
	}
	Complex add(Complex&);
	Complex sub(Complex&);
	Complex operator+(Complex m)
	{
		return Complex(this->a + m.a, this->b + m.b);
	}
	Complex operator-(Complex m)
	{
		return Complex(this->a - m.a, this->b - m.b);
	}
	Complex operator=(Complex m)
	{
		this->a = m.a;
		this->b = m.b;
		return *this;
	}
	Complex operator+=(Complex m)
	{
		this->a = this->a + m.a;
		this->b = this->b + m.b;
		return *this;
	}
	Complex operator-=(Complex m)
	{
		this->a = this->a - m.a;
		this->b = this->b - m.b;
		return *this;
	}
};

#endif