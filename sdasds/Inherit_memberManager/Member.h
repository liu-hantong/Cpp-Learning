#pragma once
#include<string>
#include<iostream>
class Member
{
protected:
	int id;
	std::string name;
	int date;
	std::string department;
public:
	friend class Manager;
	Member() = default;
	void printInfo();
};

