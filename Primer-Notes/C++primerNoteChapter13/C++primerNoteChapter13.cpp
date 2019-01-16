#include<iostream>
#include<string>

//Pra 13.5 13.8 13.11
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
	HasPtr& operator=(const HasPtr& has) {
		if (this != &has) {
			std::string *temp_ps = new std::string(*has.ps);
			//tend to release the space
			delete ps;
			ps = temp_ps;
			i = has.i;
		}
	}
	~HasPtr() {
		delete ps;
	}
private:
	std::string *ps;
	int i;
};

//Pra 13.14 13.15
class numbered {
public:
	numbered() {
		mysn = seq++;
	}
	numbered(const numbered& num) {
		//add a copy constructor
		mysn = seq++;
	}
	static int seq;
	int mysn;
};
void f(const numbered& s) { std::cout << s.mysn << std::endl; }
int numbered::seq = 10;

//Pra 13.18
class Employee {
public:
	Employee() = default;
	Employee(const std::string& name) : name(name) { id = unique++; }
	Employee(const Employee& New) = delete;
	Employee& operator=(const Employee&) = delete;
	int print_num() const { return id; }
	std::string name;
	int id;
	static int unique;
};
int Employee::unique = 0;

//Pra 13.22
class HasPtr_22 {
public:
	HasPtr_22(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	HasPtr_22(const HasPtr_22 &p) : ps(new std::string(*p.ps)), i(p.i) {}//if don't define this function, the pointer copy will not funciton as you expect
	HasPtr_22& operator=(const HasPtr_22 &);
	~HasPtr_22() { delete ps; };//if don't define this type of function, a memory leak will occur
private:
	std::string *ps;
	int i;
};
HasPtr_22& HasPtr_22::operator=(const HasPtr_22 &rhs) {
	//copy
	auto newp = new std::string(*rhs.ps);
	//destroy
	delete ps;
	//re initialize
	ps = newp;
	i = rhs.i;
	return *this;
}

//Pra 13.27
class HasPtr_Pointer {
	HasPtr_Pointer(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {};
	HasPtr_Pointer& operator=(const HasPtr_Pointer&);
	HasPtr_Pointer(const HasPtr_Pointer &p) :ps(p.ps), i(p.i), use(p.use) { ++*use; }
	~HasPtr_Pointer();
private:
	std::string *ps;
	int i;
	//use this parameter to count the pointers
	std::size_t *use;
};
HasPtr_Pointer::~HasPtr_Pointer()
{
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}
HasPtr_Pointer& HasPtr_Pointer::operator=(const HasPtr_Pointer &rhs) {
	++*rhs.use;
	if (--*use == 0) {
		//if this pointer point to nothing than destroy it
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

int main() {

	//Pra 13.14 13.15
	numbered a, b = a, c = b;
	f(a); f(b); f(c);
	system("pause");

	//Pra 13.18
	std::string name1 = "lht";
	std::string name2 = "lht1";
	std::string name3 = "lht2";
	Employee N1(name1); 
	Employee N2(name2);
	Employee N3(name3);
	std::cout << N1.print_num() << N2.print_num() << N3.print_num() << std::endl;
	system("pause");


}