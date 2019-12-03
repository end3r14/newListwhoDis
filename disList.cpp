#include "disList.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool disMatch(Dis entry, Dis compDis) {
	if (entry.getGeoN() == "*" || entry.getGeoN() == compDis.getGeoN())
	{
		if (entry.getH() == "*" || entry.getH() == compDis.getH())
		{
			if (entry.getV() == "*" || entry.getV() == compDis.getV())
			{
				if (entry.getC() == "*" || entry.getC() == compDis.getC())
				{
					if (entry.getA() == "*" || entry.getA() == compDis.getA())
					{
						if (entry.getS() == "*" || entry.getS() == compDis.getS())
						{
							if (entry.getI() == "*" || entry.getI() == compDis.getI())
							{
								//cout << "Entry matches" << endl;
								return true;
							}
						}
					}
				}
			}
		}
	}
	//cout << "Entry does not match" << endl;
	return false;
}

DisList::DisList()
{
	head = nullptr;
	tail = nullptr;
	temp = nullptr;
	current = nullptr;
}

//prints out the node information in order of the listing
void DisList::printDisList()
{
	//set our current pointer to the head so we can begin at the first node
	current = head;
	Dis tempDis;

	//if there isn't an entry, say no entries, otherwise walk the list
	if (current == nullptr)
	{
		cout << endl;
		cout << "There are no disability entries to display." << endl;
		return;
	}
	else
	{
		cout << endl;
		cout << "DISPLAY" << endl;
		cout << "|DISDATA FILLER|" << endl;
		//check each node until the current pointer gets to the end of the list
		while (current != nullptr)
		{
			//at each node, grab the data from the held address and print it out
			tempDis = *current->disData;
			cout << left << setw(30) << tempDis.getGeoN() << left << setw(10) << tempDis.getH() << left << setw(10) << tempDis.getV() << left << setw(10) << tempDis.getC() << setw(10) << tempDis.getA() << left << setw(10) << tempDis.getS() << left << setw(10) << tempDis.getI() << endl;
			//once printed, move to the next node and repeat
			current = current->next;
		}
	}
	cout << endl;
}

//adds a new node to the end of the list
void DisList::insertNode(Dis& entry)
{
	//create a new node in memory and have a pointer, n, point to where it's now located
	DisNode* n = new DisNode;
	//set the new node's data pointer to our entry's address and set the next pointer to be NULL since it's at the end
	n->disData = &entry;
	//cout << "Added data at address " << &entry << " to list."<< endl;
	n->next = nullptr;

	//check to see if this is the first node entered into the list (if not, we know we have a head and tail already)
	if (head != nullptr)
	{
		//given the list has a head/tail, set current node to the tail and link the current node to our new node
		current = tail;
		current->next = n;
		tail = n;
	}
	else
	{
		//since we have no head, this is the first entry in the list so set our head and tail to be the new node
		head = n;
		tail = n;
		//current = n;
		//temp = n;
	}
}

void DisList::selectNode(Dis& entry)
{
	Dis tempDis;

	current = head;
	bool foundSomething = false;
	//cout << "Searching for entries..." << endl;
	while (current != nullptr)
	{
		tempDis = *current->disData;
		if (disMatch(entry, tempDis) == true)
		{
			cout << "Found " << tempDis.showTuple() << " in disability." << endl;
			foundSomething = true;
		}
		current = current->next;
	}
	if (foundSomething == false)
	{
		cout << "No entries match query " << entry.showTuple() << " in disability." << endl;
	}
}

//deletes a node in the list and reconnects the list as needed
void DisList::deleteNode(Dis& entry)
{
	//a temporary storage for the data our entry will be compared with
	Dis tempDis;

	bool foundSomething = false;
	//cout << "Searching for entries to delete..." << endl;
	//if there is a list, set current and temp to the start of the list. otherwise, if no list exists, output message
	if (head != nullptr)
	{
		current = head;
		temp = head;
	}
	else
	{
		cout << "No entries match query " << entry.showTuple() << " in disability." << endl;
		return;
	}
	if (entry.getKey() != "*")
	{
		//as long as current is pointing to something, including not past the end of the list, check the node
		while (current != nullptr)
		{
			//store this node's data into tempAge and compare the keys of tempAge and entry
			tempDis = *current->disData;
			if (tempDis.getKey() == entry.getKey())
			{
				//when the keys are the same, check if we are at the first node (head)
				if (head == current)
				{
					//when we are at the head, move head to the next node before deleting the original head
					head = current->next;
					//cout << "Deleted " << tempAge.showTuple() << " in age" << endl;
					foundSomething = true;
					delete current;
					current = head;
					break;
				}
				else
				{
					//when we are not at the head, link temp to the node just past the node we are deleting
					temp->next = current->next;
					//cout << "Deleted " << tempAge.showTuple() << " in age" << endl;
					foundSomething = true;
					if (current == tail)
					{
						tail = temp;
					}
					delete current;
					current = head;
					break;
				}

			}
			//when the keys are not the same, catch temp up to current and then advance current to the next node to check
			else
			{
				temp = current;
				current = current->next;
			}
		}
	}
	else
	{
		while (current != nullptr)
		{
			//store this node's data into tempAge and compare the keys of tempAge and entry
			tempDis = *current->disData;
			if (disMatch(entry, tempDis) == true)
			{
				//when the keys are the same, check if we are at the first node (head)
				if (head == current)
				{
					//when we are at the head, move head to the next node before deleting the original head
					head = current->next;
					temp = head;
					cout << "Deleted " << tempDis.showTuple() << " disability." << endl;
					foundSomething = true;
					delete current;
					current = head;
				}
				else
				{
					//when we are not at the head, link temp to the node just past the node we are deleting
					temp->next = current->next;
					cout << "Deleted " << tempDis.showTuple() << " disability." << endl;
					foundSomething = true;
					if (current == tail)
					{
						tail = temp;
					}
					delete current;
					current = temp->next;
				}

			}
			else
			{
				temp = current;
				current = current->next;
			}
		}
	}
	if (foundSomething == false)
	{
		cout << "No entries match query " << entry.showTuple() << " disability." << endl;
	}
}