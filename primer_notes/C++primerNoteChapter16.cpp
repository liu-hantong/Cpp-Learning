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
//Instantiating a Class Template
Blob<int> ia = {1, 2, 3, 4};
 
 
 
 
 
 