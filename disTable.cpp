#include "disTable.h"
#include <iomanip>

#include <vector>
using namespace std;
DisTable::DisTable()
{
	HashTable.resize(100);
}

void DisTable::disUpdate(Dis entry)
{
	cout << "Update" << endl;
	int index = disHash(entry.getKey());
	int probe = 0;
	while (probe != HashTable.size())
	{
		if (HashTable[index].getKey() == "")
		{
			cout << "FAILED TO UPDATE " << index << endl;
			return;
		}
		
		else if (HashTable[index].getKey() == entry.getKey())
		{
			HashTable[index] = entry;
			cout << "UPDATED " << index << endl;
			return;
		}
		else if (HashTable[index].getKey() == "-2"|| HashTable[index].getKey() != "")
		{
			index = (index + 1) % HashTable.size();
			cout << "COLLISION! TRYING INDEX " << index << endl;
			probe++;
		}
		

	}

	//if the entry is not in the table
	cout << "FAILURE TO UPDATE " << index << endl;
}


void DisTable::disSelect(Dis entry)
{
	cout << "Select" << endl;
	if (entry.getKey() != "*")
	{
		int index = disHash(entry.getKey());
		int probe = 0;
		while (probe != HashTable.size())
		{
			if (HashTable[index].getKey() == "")
			{
				cout << "FAILED TO FIND ENTRY " << index << endl;
				break;
			}
			else if (HashTable[index].getKey() == entry.getKey())
			{

				cout << "FOUND SELECTED ENTRY " << index << endl;
				break;
			}
			index = (index + 1) % HashTable.size();
			cout << "COLLISION! TRYING INDEX " << index << endl;
			probe++;

		}
	}
	else
	{
		dList.selectNode(entry);
	}
}

void DisTable::disDelete(Dis entry)
{
	cout << "Delete" << endl;
	int index = disHash(entry.getKey());
	int probe = 0;
	while (probe != HashTable.size())
	{
		if (HashTable[index].getKey() == "")
		{
			cout << "FAILED TO DELETE ENTRY " << index << endl;
			break;
		}
		else if (HashTable[index].getKey() == entry.getKey())
		{
			HashTable[index].setGeoN("-2");
			cout << "ENTRY DELETED " << index << endl;
			break;
		}
		index = (index + 1) % HashTable.size();
		cout << "COLLISION! TRYING INDEX " << index << endl;
		probe++;



	}
}

void DisTable::disPrint()
{
	cout << "Display" << endl;
	cout << "--------------------" << endl;
	for (int i = 0; i != HashTable.size(); i++)
	{
		if (HashTable[i].getKey() != "-2" && HashTable[i].getKey() != "")
		{
			cout << "index = " << i << " ";
			HashTable[i].print();
		}
	}
}

void DisTable::disInsert(Dis entry)
{
	//cout << "Insert" << endl;
	int index = disHash(entry.getKey());
	int probe = 0;
	while (probe != HashTable.size())
	{
		if (HashTable[index].getKey() == "")
		{
			HashTable[index] = entry;
			dList.insertNode(HashTable[index]);
			cout << "INSERTED AT INDEX " << index << endl;
			break;
		}
		else if (HashTable[index].getKey() == entry.getKey())
		{
			cout << "ALREADY HAVE ENTRY WITH SAME KEY" << endl;
			break;
		}
		index = (index + 1) % HashTable.size();
		cout << "COLLISION! TRYING INDEX " << index << endl;
		probe++;
	}
	
}
//hash function takes in a key then adds up each value in key then turns into an integer
int DisTable::disHash(std::string key)
{
	int index = 0;
	int mult = 2;
	int total = 0;
	for (int i = 0; i != key.size(); i++)
	{
		total = (total * mult) + (int)key[i];
	}

	//cout << "Hashed " << key << " to index: " << total % HashTable.size() << endl;

	return total % HashTable.size();
	

}