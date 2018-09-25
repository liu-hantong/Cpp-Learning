#include<iostream>
#include<vector>
using namespace std;
//16.1
//16.1
//Defining a template

//16.1.1
//16.1.1
//Function Template
template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

/*Instantiating a Function Template*/
compare(1, 0); //T replaced by int
compare(vector<int> ...) // T repalced by vecotr<int>

/*Template type paremeters*/
/*No distinction between typename and class in a template parameter list */
template <typedef T, class U> calc (const T&, const U&)


/*Nontype Template Parameters*/
template<unsigned N, unsigned M>
int compare (const char (&p1)[N], const char (&p2)[M])
{
	return strcmp(p1, p2);
}
compare("hi", "mom") //for example


/*inline and constexpr Function Templates*/
template <typename T> inline T min(const T&, const T&);

/*Definitions of function templates and member functions of class templates are ordinarily put into header files.*/

//16.1.2
//16.1.2
//class templates
template <typename T> class Blob {
private:    
	std::shared_ptr<std::vector<int>> data; 
	void check(size_type i, const std::string &msg) const;
}
/*Instantiating a Class Template*/
Blob<int> ia = {1, 2, 3, 4};
 
 /*define a member function of a class template*/
 template <typename T>
ret-type classname::member-name(parm-list)

/*define the constructor, class Blob for example*/
template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<t>>()) {}

 /*Simplifying use of a Template Class Name inside Class Code*/
There is one exception to the rule that we must supply template arguments
when we use a class template type.
Inside the scope of the template of the class template itself, we may
use the name of the template without arguments:
/*for example*/
template <typename T> class BlobPtr {
public:
	BlobPtr() : curr(0) {}
	BlobPtr& operator++();
private:
	stdLLsize_t curr;
};



/*General and Specific Template Friendship*/
template <typename T> class Pal; class C {  
	//C is an ordinary, nontemplate class 
	friend class Pal<C>; 
	// Pal instantiated with class C is a friend to C 
	// all instances of Pal2 are friends to C;  
	// no forward declaration required when we befriend all instantiations
    template <typename T> friend class Pal2; 
}; 
template <typename T> class C2 { 
	// C2 is itself a class template    
	// each instantiation of C2 has the same instance of Pal as a friend    
	friend class Pal<T>;  
	// a template declaration for Pal must be in scope    
	// all instances of Pal2 are friends of each instance of C2, prior declaration needed  
	template <typename X> friend class Pal2;   
	// Pal3 is a nontemplate class that is a friend of every instance of C2    
	friend class Pal3;   // prior declaration for Pal3 not needed
};
/*above are the examples of friendship bettween templates*/



/*we can befriend the template's Own Type Parameter*/
template<typename Type> class Bar {
	friend Typr; //grants access to the type used to instantiate Bar
	// ....
}


/*we can define a class type aliases*/
/*examples are as followed*/
typedef Blob<string> StrBlob;
template<typename T> using twin = pair<T, T>;
twin<string> authors; //authors is a pair<string, string>
template <typename T> using partNo = pair<T, unsigned>;
partNo<string> books;  // books is a pair<string, unsigned> 
partNo<Vehicle> cars;  // cars is a pair<Vehicle, unsigned> 
partNo<Student> kids;  // kids is a pair<Student, unsigned>



/*static Members of Class Templates*/
template <typename T> class Foo {
public:
	static std::size_t count() { return str; }
private:
	static std::size_t str;
}
// instantiates static members Foo<string>::ctr and Foo<string>::count 
Foo<string> fs; 

// all three objects share the same Foo<int>::ctr and Foo<int>::count members
Foo<int> fi, fi2, fi3;

/*we can also define the static member as template*/
template <typename T>
size_t Foo<T>::str = 0;//define and initialize ctr

/*the template declaration*/
template <typename T> int compare(const T&, const T&);
template <typename T> class Blob;















 




	
 
 
 
 
 
 
 
 
 
 
 
