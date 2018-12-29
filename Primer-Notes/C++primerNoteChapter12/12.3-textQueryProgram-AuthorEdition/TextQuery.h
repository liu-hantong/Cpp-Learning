#pragma once
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<memory>
#include<map>
#include<set>
#include"QueryResult.h"
class QueryResult;//to define the return type of query, this defination is neccessary
class TextQuery
{
public:
	using line_no = typename std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string) const;
private:
	std::shared_ptr<std::vector<std::string>> file;//the inputed file
	//mapping
	std::map < std::string, std::shared_ptr<std::set<line_no>>> wm;
};


