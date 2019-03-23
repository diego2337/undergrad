#ifndef __COMPLEX_H
#include "Complex.h"
#endif



Complex&
Complex::operator =(const Complex& c)
{
  this->a = c.a;
  this->b = c.b;
  return *this;
}

Complex
Complex::operator +(const Complex& c) const
{
  return Complex(this->a + c.a, this->b + c.b);
}

Complex
Complex::operator -(const Complex& c) const
{
  return Complex(this->a - c.a, this->b - c.b);
}

Complex&
Complex::operator +=(const Complex& c)
{
  this->a = this->a + c.a;
  this->b = this->b + c.b;
  return *this;
}

Complex&
Complex::operator -=(const Complex& c)
{
  this->a = this->a - c.a;
  this->b = this->b - c.b;
  return *this;
}

bool
Complex::operator ==(const Complex& c) const
{
  if(this->a == c.a && this->b == c.b)
    return true;
  else
    return false;
}

bool
Complex::operator !=(const Complex& c) const
{
  if(this->a != c.a && this->b != c.b)
    return true;
  else
    return false;
}


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
      cout << a << "+(" << b << ")i";
  }
}
