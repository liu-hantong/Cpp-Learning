#include "QueryResult.h"



void QueryResult::print(std::vector<std::string> text)
{
	std::cout << "The text contains " << lineNumbers.size() << " \"" << word << "\".\n\n";
	for (auto a : lineNumbers)
		std::cout << "[ line " << a << " ]: " << text[a - 1] << "\n\n";
}
