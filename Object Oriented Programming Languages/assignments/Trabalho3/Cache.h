#ifndef CACHE_H
#define CACHE_H
template <typename T>
struct Cfield{
	bool valid;
	int tag;
	T data;
};
/* Classe abstrata */
template <typename T>
class Cache
{
public:
	virtual void setData(T, int, int) = 0;
	virtual T getData(int) = 0;
	virtual int WriteMiss(int, T) = 0;
	virtual int WRITEHIT(int, T, int) = 0;
	virtual int WRITEMISS(int, T, int) = 0;
	virtual bool checkTag(int, int) = 0;
	virtual bool getValid(int) = 0;
	virtual void setValid(bool, int) = 0;	
};

template <typename T>
class WriteThrough : public Cache<T>
{
private:
	Cfield<T>* cache;
public:
	WriteThrough(int Max_blocks)
	{
		cache = new Cfield<T>[Max_blocks];
	}
	WriteThrough()
	{
		
	}
	~WriteThrough()
	{
		delete []cache;
	}
	void setData(T, int, int);
	T getData(int);
	int WriteMiss(int, T);
	int WRITEHIT(int, T, int);
	int WRITEMISS(int, T, int);
	bool checkTag(int, int);
	bool getValid(int);
	void setValid(bool, int);
};


template <typename T>
void WriteThrough<T>::setData(T data2, int index, int n)
{
	this->cache[index].data = data2;
	this->cache[index].tag = n;
}

template <typename T>
int WriteThrough<T>::WRITEHIT(int index, T value, int n)
{
	this->cache[index].data = value;
	this->cache[index].tag = n;
	return 0;
}

template <typename T>
int WriteThrough<T>::WRITEMISS(int index, T value, int n)
{
	this->cache[index].data = value;
	this->cache[index].tag = n;
	return 0;
}

template <typename T>
int WriteThrough<T>::WriteMiss(int index, T value)
{
	this->cache[index].data = value;
	return 0;
}

template <typename T>
T WriteThrough<T>::getData(int index)
{
	return this->cache[index].data;
}

template <typename T>
bool WriteThrough<T>::checkTag(int index, int n)
{
	return this->cache[index].tag == n;
}
template <typename T>
bool WriteThrough<T>::getValid(int index)
{
	if(this->cache[index].valid == true)
		return true;
	else
		return false;
}

template <typename T>
void WriteThrough<T>::setValid(bool status, int index)
{
	this->cache[index].valid = status;
}

template <typename T>
class WriteBack : public Cache<T>
{
private:
	Cfield<T>* cache;
public:
	WriteBack(int V)
	{
		cache = new Cfield<T>[V];
	}
	~WriteBack()
	{
		
	}
	void setData(T, int, int);
	T getData(int);
	int WriteMiss(int, T);
	int WRITEHIT(int, T, int);
	int WRITEMISS(int, T, int);
	bool checkTag(int, int);
	bool getValid(int);
	void setValid(bool, int);
};

template <typename T>
void WriteBack<T>::setData(T data2, int index, int n)
{
	this->cache[index].data = data2;
	this->cache[index].tag = n;
}

template <typename T>
int WriteBack<T>::WRITEHIT(int index, T value, int n)
{
	this->cache[index].data = value;
	this->cache[index].tag = n;
	return 1;
}

template <typename T>
int WriteBack<T>::WRITEMISS(int index, T value, int n)
{
	this->cache[index].data = value;
	this->cache[index].tag = n;
	return 1;
}

template <typename T>
int WriteBack<T>::WriteMiss(int index, T value)
{
	this->cache[index].data = value;
	return 1;
}

template <typename T>
T WriteBack<T>::getData(int index)
{
	return this->cache[index].data;
}

template <typename T>
bool WriteBack<T>::checkTag(int index, int n)
{
	return this->cache[index].tag == n;
}
template <typename T>
bool WriteBack<T>::getValid(int index)
{
	if(this->cache[index].valid == true)
		return true;
	else
		return false;
}

template <typename T>
void WriteBack<T>::setValid(bool status, int index)
{
	this->cache[index].valid = status;
}
#endif