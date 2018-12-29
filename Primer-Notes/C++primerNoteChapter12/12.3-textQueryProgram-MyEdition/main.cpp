#include"TextQuery.h"
int main() {
	std::string filePath = "C:\\Users\\ÁõêÏÍ©\\Desktop\\";
	std::string fileName;
	std::string test;
	while (true) {
		std::cout << "Please enter the file's name you want to investigate(enter \"q\" to quit): ";
		std::cin >> fileName;
		if (fileName == "q") exit(1);
		std::cout << "Please enter the word you want to search in this text: ";
		std::cin >> test;
		std::cout << std::endl;
		TextQuery search(filePath + fileName);
		search.Search(test);
	}
	system("pause");
}