#include "Complex.h"

#include <iostream>

using namespace std;

void
Complex::print() const
{
  if (a == 0)
  {
    if (b == 0)
      cout << 0;
    else
      cout << b << 'i';
  }
  else
  {
    if (b == 0)
      cout << a;
    else
      cout << a << "+(" << b << ")i\n";
  }
}

Complex
Complex::operator +(const Complex& c) const
{
  return Complex(a + c.a, b + c.b);
}

Complex
Complex::operator -(const Complex& c) const
{
  return Complex(a - c.a, b - c.b);
}

Complex&
Complex::operator +=(const Complex& c)
{
  a += c.a;
  b += c.b;
  return *this;
}

Complex&
Complex::operator -=(const Complex& c)
{
  a -= c.a;
  b -= c.b;
  return *this;
}

bool
Complex::operator ==(const Complex& c) const
{
  return a == c.a && b == c.b;
}

bool
Complex::operator !=(const Complex& c) const
{
  return !operator ==(c);
}
