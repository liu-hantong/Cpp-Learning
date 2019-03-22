#pragma once
#include<vector>
#include"Teacher.h"
#include"Student.h"
#include"Member.h"
#include<algorithm>
class Manager
{
	//manage all the members of the school
	std::vector<Member*> memberList;
public:
	Manager() = default;
	void add(Member* member);
	void sortById();
	void sortBydate();
	void printSearch(const int id);
	void printAll();
};

