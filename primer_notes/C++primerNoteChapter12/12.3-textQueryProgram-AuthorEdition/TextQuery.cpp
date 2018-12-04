#include "TextQuery.h"
#include"QueryResult.h"


TextQuery::TextQuery(std::ifstream&is) : file(new std::vector<std::string>)
{
	using namespace std;
	string text;
	while(getline(is, text)) {//to every line in this file
		file->push_back(text);//save this line
		int n = file->size() - 1;//current line number
		istringstream line(text);//divide the line into words
		string word;
		while (line >> word) {//for every word of this line
			//if the word doesn't exist, add this to the set
			auto &lines = wm[word]; //lines is a shard_ptr
			if (!lines)//if we first meet this word, the pointer is empty
				lines.reset(new set<line_no>);//allocate a new set
			lines->insert(n);//insert this line_number into this set
		}
	}
}


QueryResult TextQuery::query(const std::string sought) const {
	//if don't find sought, return the set
	std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	//use find to find the word, in order not to add the word to the wm!
	auto loc = wm.find(sought);
	if (loc == wm.end())//not find
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);//find it
}