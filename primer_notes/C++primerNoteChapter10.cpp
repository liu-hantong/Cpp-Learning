#include<iostream>
int main(){
//Chapter 10
//Chapter 10
//Generic Algorithms
/*The standard library defines a set of generic algorithms:
they implement common classical algorithms such as sorting and 
searching. Generic means they operate on elements of different
type and across multiple container types*/


//10.1
//10.1
//Overview
/*Some algorithms that are defined in the standard library*/
result = find(iterator, iterater);//result will denote the element we want if it's in vec, or vec.cend if not
                                  //we can use find() function to look for values in any type of container.
int *result	= find(begin(a), end(a), val); //we can also use find to look in an array, and return the pointer
/*while how the algorithms work*/
//the algorithms work just as it looks like
//first - compare - MatchOrNot - next - end
/*iterators make the algorithms container independent*/
/*while algorithms do depend on Element-Type Operations*/
//count algorithms in algorithm
/*note that algorithms never execute container operations,
for example, algorithms never ever add or remove elements directly*/


//10.2
//10.2
//A first look at the algorithms
/*the standard library provides more than 100 algorithms, fortunately, like the containers
the algoris have a consistent architecture*/

//10.2.1
//10.2.1
//Read-only algorithms
/*The examples are as followed*/
#include<numeric> 
int sum = accumulate(vec.begin(), vec.cend(), 0);//return the sum of vec, the initial value of sum is 0
string sum = accumulate(v.cbegin(), v.cend(), string(""));//explicitlu create a  string as the third parameter
/*************important!!!!!**********/
/*ordinarily it is best to use cbegin() and cend()*/
/*algorithms that operate on two sequences*/
equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());//true if corresponding elements are equal, false if not


//10.2.2
//10.2.2
//algorithms that write container elements
fill(vec.begin(), vec.end(), 0)//assign 0 to the range from vec.begin() to vec.end()
/*valid inout sequence is safe*/
/*algorithms do not check write operations*/
fill_n(vec.begin(), vec.size(), 0);
fill_n(dest, n, val)
/*diaster, we specified the 10 elements should be written, if vec is empty, the call is diaster*/

/*introducing back_inserter*/
vector<int> vec;
auto it = back_inserter(vec);
*it = 42;
vector<int> vec;
fill_n(back_inserter(vec), 10, 0);//add 10 elements to vec, it's correct
/*copy algorithms*/
copy(begin(a1), end(a1), a2);//it is essential that the destination passed to copy be at least as large as the input range
replace(list.begin(), ilist.end(), 10, 0);//replace all the 10 within begin to end with 0)
replace_copy(ilist.cbegin(), ilist.cend(), back_inserter(ivec), 0, 42);//ilist is unchanged, ivec contains a copy of list while the value 0
//has the value 42 in ivec
//10.2.3
//10.2.3
//algorithms that reorder container elements
/*a simple example: sort the dictionary*/
sort(words.begin(), words.end());//resort the words alphabetically
auto end_unique = unique(words.begin(), words.end());//
words.erase(end_unique, words.end());//remove the nonunique elements
/*using container Operation to remove elements*/


//10.3
//10.3
//Customizing Operations
//10.3.1
//10.3.1
//passing a function to an algorithm
/*Predicates*/
//emmmmmmmmmmmmm
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
sort(words.begin(), words.end(), isShorter);
/*Sorting Algorithms*/
elimDups(words);//put words in alphabetical order and remove duplicates
stable_sort(words.begin(), words.end(), isShorter);


//10.3.2
//10.3.2
//Lambda Expression
find_if(iterator, iterator, predicate)//find the position of true predicate
/*the structure a lambda expression*/
[capture list] (parameter list) -> return type {function body}
auto f = [] { return 42; }
cout << f() << endl; //print 42
/*note that if lambdas with funcition bodies that contain anything other than a single return
statement that do not specify a return type return void*/
/*passing arguments to a lambda*/
[] (const string &a, const string &b) 
{return a.size() < b.size(); }
/*using capture  list*/
/*note that capture to capture list is essential*/
/*calling find_if*/
auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz ; });
/*for_each algorithms*/
for_each(wc, words.end(), [](const string &S) {cout << s << " ";});



//10.3.3
//10.3.3
//Lambda Capture and returns
/*When we define a lamdba, the compiler generates a new (unnamed) class type that correspond to that lambda*/
/*capture by value*/
//the captured value is copied when the lambda is created
/*note that keep your lambda captures simple*/
/*implicit captures*/
[=] value capture
[&] reference capture
[=, value]..ext is also allowed
/*mutable lambdas*/
[v1] () mutable { return ++v1; }
//whether reference capture can change a varible depends on if the value is const
/*specifying the lambda return type*/
/*we have to define a return type for lambda, we must use a trailing return type*/
[](int i) -> int { if (i < 0) return -i; else return i;};


//10.3.4
//10.3.4
//Binding Arguments
/*the library bind function*/
auto newCallabel = bind(callable, arg_list);//callable is function, arg_list passed arguments to callable
/*binding the sz parameter of check_size*/
auto check6 = bind(check_size, _1, 6);//_1 represents that the check6 only needs 1 parameter
/*using placeholderes Names*/
//we have to use namespace to use the _1 and other adapts
using namespace std::placeholderes;
/*arguments to bind*/
call = bind(function, a, b, _2, c, _1);
call this callable call(_1, _2) equals function(a, b, _1, c, _2);
/*using to bind reorder paremeters*/
call = bind(function, a, b, _3, _2, _1);
/*binding reference parameters*/
bind, ref, cref are all being defined in header functional


//10.4
//10.4
//Revisiting Iterators
 
}