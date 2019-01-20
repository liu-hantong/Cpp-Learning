#include "Member.h"

void Member::printInfo()
{
	std::cout << id << "\t" << name << "\t" << date << "\t" << department;
	std::cout << std::endl;
}