#include "TextQuery.h"



TextQuery::TextQuery(const std::string& fileName)
{
	//record this text
	fileInput.open(fileName, std::ios::in);
	if (!fileInput) {
		std::cerr << "Cannot open this file!" << std::endl;
		exit(1);
	}
	std::string Line;
	std::string word;
	int lineNumber = 0;
	while (getline(fileInput, Line)) {
		++lineNumber;
		textContent.push_back(Line);
		std::istringstream Convert(Line);
		std::set<int> lineExist;
		lineExist.insert(lineNumber);
		while (Convert >> word) {
			//create a set and insert it into the map
			if (wordLine.count(word)) {
				//if the word has existed
				lineExist = wordLine.find(word)->second;
				lineExist.insert(lineNumber);
				wordLine.erase(word);
				wordLine[word] = lineExist;
			}
			else
				//if not existed
				wordLine[word] = lineExist;
		}
	}
	fileInput.close();
}

QueryResult TextQuery::Search(const std::string& wordName) {
	if (!wordLine.count(wordName)) {
		std::cerr << "the word " << wordName << " doesn't exist!" << std::endl;
		system("pause");
		exit(1);
	}
	std::set<int> currentWord = wordLine.find(wordName)->second;
	return QueryResult(wordName, currentWord, textContent);
}

