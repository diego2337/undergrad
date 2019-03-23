#ifndef MEMORY_H
#define MEMORY_H
#include "Manager.h"

template <typename T>
class Memory
{
private:
	T data;
public:
	T getData();
	void setData(T);
	void clear();
};

template <typename T>
T Memory<T>::getData()
{
	return this->data;
}

template <typename T>
void Memory<T>::setData(T data2)
{
	this->data = data2;
}

template <typename T>
void Memory<T>::clear()
{
	this->data = 0;
}
#endif