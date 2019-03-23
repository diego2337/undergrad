#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics{
private:
	int read;
	int write;
	int hits;
	int misses;
	int switches;
public:
	Statistics()
	{
		read = write = hits = misses = switches = 0;
	}
	void clear();
	int getRead();
	int getWrite();
	int getHits();
	int getMisses();
	int getSwitches();
	void incRead();
	void incWrite();
	void incHits();
	void incMisses();
	void incSwitches();
};

void Statistics::clear()
{
	read = write = hits = misses = switches = 0;
}

int Statistics::getRead()
{
	return read;
}

int Statistics::getWrite()
{
	return write;
}

int Statistics::getHits()
{
	return hits;
}

int Statistics::getMisses()
{
	return misses;
}

int Statistics::getSwitches()
{
	return switches;
}

void Statistics::incRead()
{
	this->read++;
}

void Statistics::incWrite()
{
	this->write++;
}

void Statistics::incHits()
{
	this->hits++;
}

void Statistics::incMisses()
{
	this->misses++;
}

void Statistics::incSwitches()
{
	this->switches++;
}

#endif