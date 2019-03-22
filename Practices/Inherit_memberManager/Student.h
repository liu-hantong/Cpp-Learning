#pragma once
#include "Member.h"
class Student :
	public Member
{
	std::string major;
public:
	Student(int Sid, const char* Sname, int Sdate, const char* Sdepartment, const char* major);
};

