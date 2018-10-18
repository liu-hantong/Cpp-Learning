#include<iostream>
int main(){
//Chapter 9
//Sequential Containers
//9.1
//9.1
//Overview of the Sequential Containers
/*list of containers is followed
vector deque list forward_list array string*/
/*Rememer, the array's length is fixed*/
/*Note the new library containers are dramatically faster than in previous releases*/
/*Modern C++ programs should use the library containers rather than more primitive
structures like arrays*/
/*use vector is best*/


//9.2
//9.2
//Container library overview
/*we can almost save any kind of types elements to containers*/
//here are some containers' operations
//iterator, const_iterator, size_type, difference_type, value_type, reference and so on*/
/*the operations that can be used to iterators are some common types*/
//++, --, *, ->, +, ==, +=, >=, -=, +, -and so on
/*Iterator ranges*/
//begin points to the first element, end points to the position next to the last elements


//9.2.2
//9.2.2
//Container type members
/*defination of container type members*/
//for example
list<string>::iterator iter;;
vector<int>difference_type count;
list<string>::const_iterator // to read
list<string>::iterator // to write

//9.2.3
//9.2.3
//begin and end members
/*note that there are three types of begin and end members
the Correspondence is as followed*/
begin() -> iterator
rbegin() -> reverse_iterator
cbegin() -> const_iterator
crbegin() -> const_reverse_iterators
/*note that auto keyword is very useful*/


//9.2.4
//9.2.4
//define and initializing a Container
/*there are many ways to define and initializing a container*/
C c;
C c1(c2);
C c1 = c2;
C c{a, b, c, d, e, f};
C seq(n);
C seq
/*we can use iterators to copy elements to a new containers
the containers' type and element type must be equal*/
/*list initialization*/
list<string> authors = {"Milton", "Shakespeare", "Austen"}
vector<const char*> articles = {"a", "a", "the"}
/*sequential container size-related constructors*/
vector<int> ivec(10, -1);
list<string> svec(10, "hi!");
deque<string> svec(10);
/*library arrays have fixed size*/
array<int, 42>
array<string, 10>
array<int, 10> copy = digits; //correct


//9.2.5
//9.2.5
//assignments and swap
/*swap operations*/
/*swapping 2 containers is guaranteed to be fast - the elements themselves
are not swapped; internal data structures are swapped*/
seq.assign(b, e);
seq.assign(i1);
swap(c1, c2); //exchange elements in c1 with those in c2
/*use assign(Sequential Containers Only)*/
/*assign can also be used to initialize elements*/
s.assign(10, "haha");
/*we should consider the pointer, reference and iterator constant or not*/


//9.2.6
//9.2.6
//container size operations
/*size member*/

//9.2.7
//9.2.7
//relational operators
/*number > size > equal*/
/*here are the specific examples*/
vector<int> v1 = {1, 3, 5, 7, 9, 12};
vector<int> v2 = {1, 3, 9};
vector<int> v3 = {1, 3, 5, 7};
vector<int> v4 = {1, 3, 5, 7, 9, 12};
v1 < v2; //true "member"
v1 < v3; //flase 
v1 == v4; //true
v1 == v2 //false


//9.3
//9.3
//Sequential Container Operations
//9.3.1
//9.3.1
//Adding elements to a sequential Container
c.push_back(t);
c.emplace_back(t);
c.push_front(t);
c.emplace_front(t);
c.insert(p, t)
c.emplace(p, args);
c.insert(p, n, t)//insert n elements in front of p
c.insert(p, b, e)//insert elements between container b and e.
c.insert(p, i1)//insert i1 is a braced list of element values.

/*use push_back*/
string word;
while(cin >> word)
	container.push_back(word);
/*use push_front*/
list<int> ilist;
for(size_t ix = 0; ix != 4; ++ix)
	ilist.push_back(ix);
/*adding elements at a specified point in the container*/
slist.insert(iter, "Hello!");
//note that no push_front on vector but we can insert before begin()
//warning; inserting anywhere but at the end of a vector might be slow
/*inserting a range of elements*/
/*use the return from insert*/
list<string> lst;
auto iter = lst.begin();
while(cin >> word)
	iter = lst.insert(iter, word); //equals to useing push_front
/*using the emplace Operations*/
//note that emplace's parameters are passed to the constructor of this container
c.emplace_back();
c.emplace(iter, "99999");
c.emplace_front("Dsdasd", 123, 12.23);


//9.3.2
//9.3.2
//accessing elements
c.front();
c.back();
c[n];
c.at(n);
/*the access members return reference*/
if(!c.empty){
	c.front() = 42; //change
	auto &v = c.back(); //get reference
	v = 1024; //change 
	auto v2 = c.back(); //not a reference
	v2 = 0; //do not change
}
/*subscripting and safe random access*/
/*it's programmer's duty to ensure the validity of the subscript operator*/


//9.3.3
//9.3.3
//erasing elements
c.pop_back();
c.pop_front();
c.erase();
c.erase(b, e);
c.clear();


//9.3.4
//9.3.4
//Specialized forward_list operations
lst.before_begin();
lst.insert_after(p, t);
lst.insert_after(p, n, t);//iterator, number, object
emplace_after();
erase_after(p);
erase_after(b, e);

//9.3.5
//9.3.5
//resizing a container
c.resize()
c.resize(n, t)//number add 0


//9.3.6
//9.3.6
//container operations may invalidate iterators
/*note that it is a serious run-time error to use an iterator,
pointer, or reference that has been invalidated*/
/*advice: minimize the part of the program during which an iterator must stay valid*/
/*note that avoid storing the iterator returned from the end*/


}
