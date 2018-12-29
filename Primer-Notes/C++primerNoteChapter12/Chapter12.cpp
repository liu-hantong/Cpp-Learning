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

//Pra 12.10
void process(std::shared_ptr<int> p) {
	std::cout << "The use number now equals " << p.use_count() << std::endl;
}

//Pra 12.14
//Write your own version of a function that uses shared_ptr to manage a connection
struct connection {
	//information that the connection needed
	std::string ip;
	int port;
	connection(std::string ip_, int port_) :ip(ip_), port(port_) { }
};
struct destination {
	//what are we trying to connect
	std::string ip;
	int port;
	destination(std::string ip_, int port_) :ip(ip_), port(port_) { }
};
connection connect(destination *pDest) {
	//open the connection
	std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
	return *pConn;
}
void disconnect(connection pConn) {
	std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}
void f(destination &d)
{
	connection conn = connect(&d);
	std::shared_ptr<connection> p(&conn, [](connection *p) { disconnect(*p); });
	std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

//Pra 12.26
void input_reverse_output_string(int n)
{
	//an example of the using process of allocator
	std::allocator<std::string> alloc;//create an alloc object
	auto const p = alloc.allocate(n);//alloct n memories for alloc
	std::string s;
	auto q = p;
	while (q != p + n && std::cin >> s) //construct an object for a position in alloc
		alloc.construct(q++, s);
	while (q != p) {
		std::cout << --q << " ";
		alloc.destroy(q);//release the object in position
	}
	alloc.deallocate(p, n);//release the space that are applied
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

	//Pra 12.7
	//Create a ptr by function, fill it, output it by function
	std::shared_ptr<std::vector<int>> p6 = return_ptr();
	Input(p6);
	Output(p6);


	//Pra 12.10
	std::shared_ptr<int> p(new int(42));
	process(std::shared_ptr<int>(p));
	/**
	* codes below shows how the reference count change.
	*/
	//process(std::shared_ptr<int>(p.get()));//Pra 12.11 //this call can lead to memory release
	std::cout << p.use_count() << "\n";
	auto q = p;
	std::cout << p.use_count() << "\n";
	std::cout << "the int p now points to is:" << *p << "\n";

	/*Some principals we must follow when using smart pointer*/
	//Don't use the same built-in pointer value to initialize more than one smart pointer
	//Don't delete the pointer returned from get()
	//Don't use get() to initialze or reset another smart pointer
	//if you use a pointer returned by get(), remember that the pointer will become valid when the last
	//corresponding smart pointer goes away

	//Pra 12.15
	destination dest("202.118.176.67", 3316);
	f(dest);

	//Pra 12.26
	input_reverse_output_string(5);

	system("pause");
	return 0;
}
