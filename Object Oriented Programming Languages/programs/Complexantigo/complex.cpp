#ifndef __COMPLEX_H
#include "complex.h"
#endif

Complex Complex::add(Complex &m)
{
	return Complex(this->a + m.a, this->b + m.b);
}
Complex Complex::sub(Complex &m)
{
	return Complex(this->a - m.a, this->b - m.b);
}