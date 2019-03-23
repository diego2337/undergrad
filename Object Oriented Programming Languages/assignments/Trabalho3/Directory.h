#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <iostream>
#include <vector>
using namespace std;

struct Dfield{
	bool dirty;
	int status;
	vector<int> cacheList;
};

class Directory
{
private:
	Dfield* dir;
public:
	Directory(int Max_blocks)
	{
		dir = new Dfield[Max_blocks];
		for(int i = 0; i < Max_blocks; i++)
			initialize(dir+i);
	}
	~Directory()
	{
		delete []this->dir;
	}
	void initialize(Dfield*);
	int checkStatus(int);
	void setStatus(int, int);
	void setCacheList(int, int);
	int returnNumberOfElements(int);
	int getCacheList(int, int);
	void setDirty(bool, int);
	void removeCacheList(int, int);
	bool checkDirty(int);
	void clear(int);
};

void Directory::initialize(Dfield *dir)
{
	dir->dirty = false;
	dir->status = 0;
	dir->cacheList.clear();
}

void Directory::clear(int Max_blocks)
{
	for(int i = 0; i < Max_blocks; i++)
		initialize(dir+i);
}

int Directory::checkStatus(int index)
{
	if(this->dir[index].status == 0)
		return 0;
	else if(this->dir[index].status == 1)
		return 1;
	else
		return 2;
}

void Directory::setStatus(int status2, int index)
{
	this->dir[index].status = status2;
}

void Directory::setCacheList(int cacheList2, int index)
{
	dir[index].cacheList.push_back(cacheList2);
}

int Directory::returnNumberOfElements(int index)
{
	return dir[index].cacheList.size();
}

int Directory::getCacheList(int i, int index)
{
	return dir[index].cacheList.at(i);
}

void Directory::setDirty(bool value, int index)
{
	this->dir[index].dirty = value;
}

void Directory::removeCacheList(int element, int index)
{
	vector<int>::iterator it = this->dir[index].cacheList.begin();
	*it = element;
	dir[index].cacheList.erase(it);
}

bool Directory::checkDirty(int index)
{
	if(this->dir[index].dirty == false)
		return true;
	else
		return false;
}
#endif 