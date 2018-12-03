#pragma once
#include"TextQuery.h"
class QueryResult
{
private:
	std::string  word;
	int wordCount;
	std::set<int> lineNumbers;
public:
	QueryResult(const std::string& word, const std::set<int>& wordSet, const std::vector<std::string>& text) : word(word), lineNumbers(wordSet) { print(text); };
	void print(std::vector<std::string>);
};

