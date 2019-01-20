#pragma once
#include "Member.h"
class Teacher : public Member
{
	Member mem;
	std::string title;
public:
	Teacher(int Tid, const char* Tname, int Tdate, const char* Tdepartment, const char* Ttitle);
};

