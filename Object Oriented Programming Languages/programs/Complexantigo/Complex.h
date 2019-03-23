#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <iostream>
using namespace std;
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
   this->a = c.a;
   this->b = c.b;
  }
  ~Complex()
  {
    cout << '\n';
    this->print();
    cout << "Deleted;" << '\n';
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

}; // Complex



#endif // __COMPLEX_H
