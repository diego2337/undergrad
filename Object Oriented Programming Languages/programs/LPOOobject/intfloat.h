#ifndef INTFLOAT_H
#define INTFLOAT_H

#include "List.h"

class Int : public Object
{
	int value;
public:
	Int(int x = 0)
	{
		this->value = x;
	}
	~Int()
	{

	}
	Object* clone() const
	{
		Int* newObjInt;
		return newObjInt;
		/* ou estaticamente:
			Int newObjInt(this->value);
			return &newObjInt;*/
	}
	bool equals (const Object& x) const
	{
		const Int* x2 = dynamic_cast<const Int*>(&x);
		return (x2->value == this->value);
	}
	void print() const
	{
		cout << value << " ";
	}
};


class Float : public Object
{
	float value;
public:
	Float(float y = 0)
	{
		this->value = y;
	}
	~Float()
	{

	}
	Object* clone() const
	{
		Float* newObjInt;
		return newObjInt;
	}
	bool equals (const Object& y) const
	{
		const Float* y2 = dynamic_cast<const Float*>(&y);
		return (y2->value == this->value);
	}
	void print() const
	{
		cout << value << " ";
	}
};
#endif