#pragma once
#include"TextQuery.h"
class TextQuery;
using line_no = std::vector<std::string>::size_type;//this line is neccessary
													//but why?
class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) {};
private:
	std::string sought;//the word
	std::shared_ptr<std::set<line_no>> lines;//the emerged line_number
	std::shared_ptr<std::vector<std::string>> file;//the input file
};