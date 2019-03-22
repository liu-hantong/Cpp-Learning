#include "Manager.h"

void Manager::add(Member* member) {
	memberList.push_back(member);
}

void Manager::sortById()
{
	//use bubble sort to sort the members by id
	int sum = memberList.size();
	for (int i = sum - 1; i != 0; --i)
		for (int center = i - 1; center != -1; center--)
			if (memberList[center]->id >= memberList[i]->id)
			{
				Member *current = memberList[center];
				memberList[center] = memberList[i];
				memberList[i] = current;
			}
}

void Manager::sortBydate()
{
	int sum = memberList.size();
	for (int i = sum - 1; i != 0; --i)
		for (int center = i - 1; center != -1; center--)
		{
			if (memberList[center]->date >= memberList[i]->date)
			{
				Member *current = memberList[center];
				memberList[center] = memberList[i];
				memberList[i] = current;
			}
		}
	//sort the same date ones by id
	for (int i = sum - 1; i != 0; --i)
		for (int center = i - 1; center != -1; center--)
		{
			if (memberList[center]->date == memberList[i]->date && memberList[center]->id > memberList[i]->id)
			{
				Member *current = memberList[center];
				memberList[center] = memberList[i];
				memberList[i] = current;
			}
		}
}

void Manager::printSearch(const int id) 
{	
	int a;
	for (a = 0; a != memberList.size(); ++a)
	{
		if (memberList[a]->id == id)
		{
			memberList[a]->printInfo();
			break;
		}
	}
	if (a == memberList.size())
		std::cout << "Not found" << std::endl;
}


void Manager::printAll()
{
	for (auto member : Manager::memberList)
		member->printInfo();
}
