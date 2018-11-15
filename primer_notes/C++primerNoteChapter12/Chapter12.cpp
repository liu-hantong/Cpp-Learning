#include<iostream>
#include<memory>
#include<string>
#include"StrBlob.h"

//Pra 12.7
auto return_ptr(){
	//return shared ptr
	return std::make_shared<std::vector<int>>();
}
void Input(std::shared_ptr<std::vector<int>> p) {
	//input the element for the ptr of vector
	int in = 0;
	for (int i = 0; i < 5; ++i) {
		std::cin >> in;
		p->push_back(in);
	}
}
void Output(std::shared_ptr<std::vector<int>> p) {
	//output the element of the ptr of vector
	for (auto ele : *p) 
		std::cout << ele << std::endl;
}




int main() {
	//Chapter 12
	std::shared_ptr<int> p1;
	std::shared_ptr<double> p2;
	//use makes_shared() function to create a ptr
	//use auto to allovate a empty space;
	auto p3 = std::make_shared<int>(20);
	auto p4(p3);//all point to 20
	//as long as the counter becomes 0, the space that the pointer points to will be released


	//test for class StrBlob
	StrBlob liu{ "hello", "world", "liu" };
	const StrBlob han{ "hello", "world", "han" };
	std::cout << han.front() << " " << han.back() << std::endl;
	liu.back() = "haha";
	std::cout << liu.front() << " " << liu.back() << std::endl;

	//haha, remember not to use delete and new but use shared_ptr
	//Pra 12.7
	//Create a ptr by function, fill it, output it by function
	std::shared_ptr<std::vector<int>> p6 = return_ptr();
	Input(p6);
	Output(p6);

	system("pause");
	return 0;
}
