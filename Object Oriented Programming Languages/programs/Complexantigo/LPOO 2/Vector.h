#ifndef __Vector_h
#define __Vector_h

#include <iostream>

using namespace std;
using std::cout;

#define DEFAULT_V_SIZE 10
template <typename T>
class Vector
{
private:
  int capacity;
  int delta;
  int numberOfElements;
  T* data;

  void resize();

public:
  // construtor
  Vector(int capacity = DEFAULT_V_SIZE, int delta = DEFAULT_V_SIZE)
  {
    this->capacity = capacity > 0 ? capacity : DEFAULT_V_SIZE;
    this->delta = delta > 0 ? delta : DEFAULT_V_SIZE;
    this->numberOfElements = 0;
    this->data = new T[this->capacity];
  }
  // construtor de cópia (profunda)
  Vector(const Vector& v)
  {
    this->capacity = v.capacity;
    this->numberOfElements = v.numberOfElements;
    this->delta = v.delta;
    this->data = new T[this->capacity];
    for (int i=0; i<this->numberOfElements; i++)
      this->data[i]=v.data[i];
  }

  // destrutor
  ~Vector()
  {
    delete []data;
  }

  // Cópia (profunda)
  Vector& operator =(const Vector&);

  int getCapacity() const;
  int indexOf(const T&) const;
  bool contains(const T&) const;
  bool isEmpty() const;
  int size() const;
  void print() const;

  bool equals(const Vector&) const;
  bool operator ==(const Vector&) const;
  bool operator !=(const Vector&) const;

  void addHead(const T&);
  void addTail(const T&);
  void add(const T&);
  bool removeAt(int);
  bool removeLast();
  bool removeHead();
  bool removeValue(const T&);

  void concatenate(const Vector&);
  void union_(const Vector&);
 

}; // Vector
template <typename T>
inline int
Vector<T>::getCapacity() const
{
  return this->capacity;
}

template <typename T>
inline bool
Vector<T>::isEmpty() const
{
  return this->numberOfElements == 0;
}

template <typename T>
inline int
Vector<T>::size() const
{
  return this->numberOfElements;
}

template <typename T>
inline bool
Vector<T>::operator ==(const Vector& v) const
{
  return equals(v);
}

template <typename T>
inline bool
Vector<T>::operator !=(const Vector& v) const
{
  return !operator ==(v);
}

template <typename T>
inline void
Vector<T>::add(const T& number)
{
  addTail(number);  
}

template <typename T>
inline bool
Vector<T>::removeLast()
{
  return removeAt(this->numberOfElements-1);
}

template <typename T>
inline bool
Vector<T>::removeHead()
{
  return removeAt(0);
}

template <typename T>
inline bool
Vector<T>::removeValue(const T& number)
{
  return removeAt(indexOf(number));
}

// .cpp
template <typename T>
void
Vector<T>::concatenate(const Vector& v)
{
  for(int i = 0; i < v.numberOfElements; i++)
    this->add(v.data[i]);   
}

template <typename T>
void
Vector<T>::union_(const Vector& v)
{
   for(int i = 0; i < v.numberOfElements; i++)
   {
          if(!this->contains(v.data[i]))
            this->add(v.data[i]);
   }
  
}  

template <typename T>
bool
Vector<T>::equals(const Vector& v2) const
{
  if(this->numberOfElements != v2.numberOfElements)
    return false;

  for(int i = 0; i < this->numberOfElements; i++)
  {
    if(this->data[i] != v2.data[i])
      return false;
  }
  return true;
}

template <typename T>
void
Vector<T>::resize()
{
  this->capacity += this->delta;
  T *dataTemp = new T[this->capacity];
  for(int i = 0; i < this->numberOfElements; i++)
    dataTemp[i] = this->data[i];
  delete []data;
  this->data = dataTemp;
}

template <typename T>
void
Vector<T>::addHead(const T& number)
{
  if(this->numberOfElements == this->capacity)
  {
    this->resize();
  }
  for(int i = numberOfElements; i > 0; i--)
    this->data[i] = this->data[i-1];
  this->data[0] = number;
}

template <typename T>
void
Vector<T>::addTail(const T& number)
{
  if(this->numberOfElements == this->capacity)
  {
    this->resize();
  }
  this->data[this->numberOfElements++] = number;

  
}

template <typename T>
bool
Vector<T>::removeAt(int position)
{
  if(position < 0 || position >= numberOfElements)
    return false;
  for(int i = numberOfElements; i > position; i--)
    this->data[i] = this->data[i-1];
  this->data[position] = this->data[position-1];
  numberOfElements--;
  return true;
}

template <typename T>
int
Vector<T>::indexOf(const T& number) const
{
  for(int i = 0; i < numberOfElements; i++)
  {
    if(this->data[i] == number)
      return i;
  }
  return -1;
}

template <typename T>
bool
Vector<T>::contains(const T& number) const
{
  for(int i = 0; i < numberOfElements; i++)
  {
    if(this->data[i] == number)
      return true;
  }
  return false;
}

template <typename T>
void
Vector<T>::print() const
{
  //cout << "numberOfElements:" << this->numberOfElements << endl;
  //cout << "capacity:" << this->capacity << endl;
  //for (int i=0; i < this->numberOfElements; i++)
  //{
   // cout << this->data[i] << endl;
  //}
}

#endif // __Vector_h
