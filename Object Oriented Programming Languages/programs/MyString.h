#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
using namespace std;
template <typename T>
clss MyString
{
private:
	int length;
	T sPtr[];

public:
	MyString(int length, T sPtr[] = NULL)
	{
		this->length = length;
		for(int i = 0; i < this->length; i++)
			this->sPtr[i] = sPtr[i];
	}
	/*~MyString()
	{
		delete []sPtr;
	}*/
	MyString(const MyString& usrString)
	{
		this->length = usrString.length;
		this->sPtr = new T[usrString.length];	
	}
	void setMyString(const MyString&);
	int getLength();
	void operator +=(const MyString&);
	void operator =(const MyString&);
	bool operator ==(const MyString&);
	bool operator !=(const MyString&);
	void print();

};

template <typename T> inline
void MyString<T>::setMyString(const MyString& usrString)
{
	this->sPtr = usrString->sPtr;
}
template <typename T> inline
int MyString<T>::getLength()
{
	return this->length;
}
template  <typename T> inline
void MyString<T>::operator +=(const MyString& usrString)
{
	this->length = this->length + usrString.length;
	int j = 0;
	for(int i = (this->length - usrString.length) + 1; i < this->length; i++)
	{
		this->sPtr[i] = usrString.sPtr[j];
		j++;
	}
	this->sPtr[length] = '\0';
}
template <typename T> inline
void MyString<T>::operator =(const MyString& usrString)
{
	this->length = usrString.length;
	for(int i = 0; i < this->length; i++)
	{
		this->sPtr[i] = usrString.sPtr[i];
	}
}
template <typename T> 
bool MyString<T>::operator ==(const MyString& usrString)
{
	if(this->length != usrString.length)
		return false;
	else
	{
		for(int i = 0; i < length; i++)
		{
			if(this->sPtr[i] != usrString.sPtr[i])
				return false;
		}
		return true;
	}
}
template <typename T>
bool MyString<T>::operator!=(const MyString& usrString)
{
	return !(*this == usrString);
}
template <typename T>
std::ostream& operator <<(const ostream& o, const MyString<T>& c)
{
	c.print();
}

template <typename T>
void MyString<T>::print()
{
	for(int i = 0; i < length; i++)
	{
		cout << sPtr[i];
	}
	cout << "\n";
}

#endif