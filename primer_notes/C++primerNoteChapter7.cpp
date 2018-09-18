//C++ primer note for chapter 7
//create a new class
#include<string>
#include<iostream>
using namespace std;


//The main practicing class in this chapter, shows many new features in constructing a C++ class
//practice 7.5 create a new class named Person
class Person 
{
private:
    std::string name;
    std::string address;
public:
	//the 1st const means this is const
	//the 2nd const means return type is string const&
    auto get_name() const -> std::string const& { return name; }
    auto get_addr() const -> std::string const& { return address; }
	Person() = default;
	//constructor can be defined like this without function body 
	Person(const string &n, const string &add) :name(n), address(add) {};
	Person(istream &is) { read (is, *this); };
};

//use non-member function to create read and print functions
friend istream &read (istream &is, Person &item){
	return is >> item.name >> item.address;
}

friend ostream &print (ostream &os, const Person &person){
	return os << person.name << " " << person.address;
	
}



//7.1.3 non-member function
//finds a new ways to define the non-member function 
//we can use cin in this function , I have never seen before!!!
read(cin, Person); // we can use cin like this.
istream &read (istream &is, Sales_data &item){
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}


//7.14 constructor
//constructor cannnot be defined as const function  
//" constructor() = default; " to explicitly define the constructor
//we can also use " : " to initialize the parameters

//7.15 copy, assign and destruct
// ? ? ? where is the main content? Are you joking ? ? ?


//7.2 access control and packaging
//constructor and destructor are public function
//the interface should be defined as public, the private data shouldn't expose to outside of the class.

//7.2.1
//note friend to use the private data
//declare the friend function to use the private data
//in order to allow user use the friends , we should declare the function twice outside the class in the header

//1st
friend auto friend_function(A);
class A {
//2nd
friend auto friend_function(A);
private:
	int a;
}
friend auto friend_function( A object ) { return object.a; }


//Additional class features
making members inline
//7.3.1 
//mutable Data Members
class Screen {
public:
	void some_member() const;
private:
	mutable size_t access_ctr; //may change even in a const object
	//other members as before
};

void Screen::some_member() const {
	++ access_ctr;
}
//initializers for Data Members of Class Type
class Window_mgr {
	private:
		std::vector<Screen> screens {Screen(24, 80, ' ')} ;
};

//7.3.2
//7.3.2 
//functions that return *this
// return *this as reference in order to return the object itself 
inline Screen &Screen::set (pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}
//as above, we can use  these function like this
Screen.move().set();
//move and set the value of the cursor after moved

class Screen {
public:
	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const {os << contents; return *this; }
private:
	void do_display(std::ostream &os) const {os << contents;}
}
//the compiler can choose either const or non-const function to use
//but actually I think this action is redundant

//7.3.3
//7.3.3
//The defination and declaration of class
class Screen; //the declaration of class screen
//We can use an incomplete type in only limited ways: We can define pointers or
//references to such types, and we can declare (but not define) functions that use an incomplete type as a parameter or return type.

//7.3.4
//7.3.4
//there are friendships between classes, for example
class Screen {
	friend class Windows_mgr;
}
//Each class controls which classes or functions are its friends

//Making A Member Function a Friend, for example
class Screen {
	friend void Windows_mgr::clear(ScreenIndex);
}










