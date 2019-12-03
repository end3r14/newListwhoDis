#pragma once
#include "disData.h"

class DisTable;
class DisList
{
private:
	class DisNode
	{
	public:
		Dis* disData;
		DisNode* next;
	};
	DisNode* head;
	DisNode* tail;
	DisNode* temp;
	DisNode* current;
public:
	DisList();
	void printDisList();
	void insertNode(Dis& entry);
	void selectNode(Dis& entry);
	void deleteNode(Dis& entry);
};

bool disMatch(Dis entry, Dis compDis);