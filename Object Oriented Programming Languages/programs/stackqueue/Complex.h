#ifndef __Complex_h
#define __Complex_h

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

}; // Complex

inline Complex&
Complex::operator =(const Complex& c)
{
  a = c.a;
  b = c.b;
  return *this;
}


#endif // __Complex_h
