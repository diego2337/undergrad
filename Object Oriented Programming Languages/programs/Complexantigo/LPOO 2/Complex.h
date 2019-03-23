#ifndef __Complex_h
#define __Complex_h

#include <iostream>

using namespace std;
using std::ostream;

class Complex
{
public:
  float a; // parte real
  float b; // parte imaginária

  // construtor
  Complex(float a1 = 0, float b1 = 0)
  {
    a = a1;
    b = b1;
  }
  // construtor de cópia (rasa)
  Complex(const Complex& c)
  {
    a = c.a;
    b = c.b;
  }

  // Cópia (rasa)
  Complex& operator =(const Complex&);

  // Complex add (const Complex& c) const;
  // Complex sub (const Complex& c) const;

  Complex operator +(const Complex&) const;
  Complex operator -(const Complex&) const;
  Complex& operator +=(const Complex&);
  Complex& operator -=(const Complex&);

  bool operator ==(const Complex&) const;
  bool operator !=(const Complex&) const;

  void print() const;

  friend ostream& operator<<(ostream& o, const Complex& c)
  {
    if(c.a == 0)
    {
      if(c.b == 0)
        o << 0;
      else
        o << c.b << 'i';
    }
    else
    {
      if(c.b == 0)
        o << c.a;
      else
        o << c.a << "+(" << c.b << ")i";
    }
    o << '\n';
    return o;
  }

}; // Complex

inline Complex&
Complex::operator =(const Complex& c)
{
  a = c.a;
  b = c.b;
  return *this;
}


#endif // __Complex_h
