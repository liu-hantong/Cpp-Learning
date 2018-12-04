#include"QueryResult.h"
#include"TextQuery.h"

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
	//decide whether the word is plural or not
	return (ctr == 1) ? word : word + ending;
}
std::ostream& print(std::ostream& os, const QueryResult& qr) {
	//if find it, print the number it occurs
	os << qr.sought << " occurs " << qr.lines->size() << " " <<
		make_plural(qr.lines->size(), "time", "s") << std::endl;
	//print every line of this word
	for (auto num : *qr.lines) //to every word of set
		//in order not to start from "0"
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
}

void runQueries(std::ifstream &infile) {
	//infile is a ifstream, pointing to the file we want to read
	TextQuery tq(infile);//save file and construct the query map
	//interact with the user: indicate the words that the user want to search, finish the query and print the result
	while (true) {
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		//if encourtered the file tail or the user type 'q', end this loop
		if (!(std::cin >> s) || s == "q") break;
		//point to the query result and print the results
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main() {
	std::ifstream infile;
	infile.open("C:\\Users\\ÁõêÏÍ©\\Desktop\\a.txt", std::ios::in);
	runQueries(infile);
	infile.close();
	return 0;
}
