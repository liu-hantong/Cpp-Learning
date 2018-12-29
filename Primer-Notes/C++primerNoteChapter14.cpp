#include<iostream>
using namespace std;
//Chapter 14
//Chapter 14
//Overload operations and conversions
/* demo */
cout << item1 + item2 <<endl; //addition of two objects

//14.1
//14.1
//Basic Concepts
/*can't invent a new type of operations*/
/*the overlaod of delete and new is in p820*/
/*an overload operartor has the same precedence and associativity as the corresponding 
build-in operator*/


/*calling an overload operator function directly*/
//for example
data1 + data2;
operator+(data1, data2);
data += data2;
data.operator+=(data2);


/*some operators shouldn't be overloaded*/
logical and, address-of, logical OR, and comma operators, && and ||


/*use definations that are consistent with the built-in meaning*/
add - +
IO - shift operators
compare - >, <
same return type

/*assignment and compound assignment operators*/
//both arithmetic and bitwise operator
//for example where there is +, there must be +=.
//where there is |, there must be |=


/*choosing member or nonmember implementation*/
//members: must =, [], (), ->
//members: compound-assignment, like += *=
//members: increment, decrement, dereference that changes the state
//non-members: symmetric.


//14.2
//14.2
//Input and Output Operators

//14.2.1
//14.2.1
//Overloading the output Operator <<
/*for example*/
ostream &operator<<(ostream &os, const Sales_data &item)
{
	os << item.<> << ... ;
	return os;
}


/*Output operators usually do minimal Formatting*/
/*warning! output operators should not print a newline*/
/*IO operators must be NonMember functions*/


//14.2.2
//14.2.2
//Overloading the input operator
/*for example*/
istream &operator>>(istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> .. >>price;
	if(is) //check that the inputs succeed
		item.revenue = item.units_sold >>price;
	else
		item = Sales_data();
	return is;
}
/*Input operators must deal with the possibility that the input might fail*/


/*errors during input should be taken into account*/
//1. check the validty of iostream
//2. if failed, new a new object and initialize is with origin


//14.3
//14.3
//arithmetic and relational operators
/*for example*/
Sales_data
operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}
//tip: its better use += rather than +, because the space.


//14.3.1
//14.3.1
//Equality operators
/*some tips that is kind of important to understand this type of operator*/
//1. equal determination: operator+ better than other functions
//2. == can judge whether the given objects contain equivalent data
//3. == should be transtive
//4. == and != come up together
//5. == and !=, one of whitch work really.


//14.3.2
//14.3.2
//Relation Operators
/*we should define < and > operation only when the objects truly need them and can implement
them well*/


//14.4
//14.4
//assignment operators
//compound-assignment operators
/*reload assignment operators as members*/
/*vector reload functions*/
/*for example*/

//14.5
//14.5
//Subscript Operator
/*subscript operator must be members*/
/*If a class has a subscript operator, it usually should define two versions:
one that returns a plain reference and the other that is a const member and returns
a reference to const*/


//14.6
//14.6
//Increment and Decrement operators
/*our preference is to make these operators members*/
/*note that we should define increment and decrement operators both the prefix and postfix
versions. These operator usually should be defined as members*/
/*to be consistent with the build-in operators, the prefix operators should return a reference
to the incremented or decremented object*/
Str& StrBlobPtr::operator++() { }
/*we use int parameter to differentiate prefix and postfix operators*/
Str operator++( int );
/*we can call the operator explicitly like this*/
p.operator++(0);//the parameter is needed to defferentiate between prefix and postfix
p.operator++();

//14.7
//14.7
//Member Access Operators
//-> and *operator
/*operator must be a member, the deference operator is not required to be a member*/
/*the return type of these two operators are reference and pointer*/
(*point).mem;//point is a build-in pointer type
point.operator()->mem;//point is an object of class type
/*the overloaded arrow operator must return either a pointer to a class type or an
object of a class type that defines its own operator arrow*/


//14.8
//14.8
//Function-Call Operator
/*classes that overloaded the call operator allow objects of its type to be used as if
they were a function*/
struct abdInt{
	int operator()(int val) const {
		return val < 0 ? -val : val;
	}
}
//we can use this object like this
int ui = absObj(i);
/*note that the function call operator must be members*/

/*Function-Object Classes with State*/
/*we can also use the object-function as a parameter of the STL function such as copy*/


//14.8.1
//14.8.1
//Lambdas Are function Objects
/*Lambdas work as function objects inside the program, it will create a 
new class for these lambdas*/
class ShorterString{
public:
	bool operator()(const string &s1, const string &s2) const
	{return s1.size() < s2.size();}
}

/*Classes representing lambdas with Captures*/
//it will create the corresponding data member for the capture parameters*/
//typicaly, classes generated from a lambda expression have a deleted default constructor*/


//14.8.2
//14.8.2
//Lirary-Defined Function Objects
plus<int> intAdd;
negate<int> ineNegate;
int sum = intAdd(10, 20);
sum = intNegate(intAdd(10, 20));
//lots of function template classes are defined inside the STL
//they are "functions" of arithmetic, relational, logical operations

/*note that we can use STL function objects in Algorithms*/


//14.8.3
//14.8.3
//Callable Objects and function

/*defferent Types can have the same Call Signatrue*/
//ordinary function, lambda and function-object class can have same call signatrue

/*STL function type*/
//we can use function class to coordinate with the last callable objects
function<int(int, int)> f1 = add;//function
function<int(int, int)> f1 = divide();//function objects
function<int(int, int)> f1 = [](int i, int j);//lambda
//we can use function to define map
map<string, function<int(int, int)>> binops = {//this defination can solve previous problems
	{"+", add},
	{"-", std::minus<int> ()},
	{"/", divede()},
	{"*", [](int i, int j) {return i * j;}},
	{"%", mod} };
}

/*overloaded functions and function*/
//we can use function pointer or lambda to indicate the correct overloaded functions we
//want use in binops
int (*fp)(int, int) = add;
binops.insert( {"+", fp} );


 
	
	






 
