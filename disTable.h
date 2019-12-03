#pragma once
#include "disList.h"
#include <vector>

class DisTable
{
private:
public:
	std::vector<Dis> HashTable;
	DisList dList;
	DisTable();
	//dislist
	int disHash(std::string key);
	void disInsert(Dis entry);
	void disSearch(Dis entry);
	void disPrint();
	void disDelete(Dis entry);
	void disSelect(Dis entry);
	void disUpdate(Dis entry);


};
