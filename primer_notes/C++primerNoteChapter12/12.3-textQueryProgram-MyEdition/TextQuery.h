#pragma once
#include<vector>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string.h>
#include<sstream>
#include"QueryResult.h"
class QueryResult;
class TextQuery
{
	//this class to read the inputed file
private:
	std::vector<std::string> textContent;//the content of all the text
	std::map<std::string, std::set<int>> wordLine;//word and its corresponding set
	std::ifstream fileInput;//the text
public:
	TextQuery(const std::string& fileName);//save the content of the text
	QueryResult Search(const std::string& wordName);//search the indicated word
	~TextQuery() = default;
};

