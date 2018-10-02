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


	








 











 
