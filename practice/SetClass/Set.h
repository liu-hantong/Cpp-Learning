#pragma once
#include<iostream>
#include<iomanip>
class Set {
private:
	int elems[100];
	int length;
public:
	Set();//default constructor
	Set(const Set &set);//constructor
	Set(int elements[], int length);//unsorted and contain the same elements
	void add(int elemebent);//add element
	bool erase(int element);//delete element
	bool contains(int element);//judge the existence of element
	int size();//the size of this set
	friend std::ostream& operator<<(std::ostream &os, const Set &rset);//print all the element in ascending order
	friend Set operator+(const Set &lset, const Set &rset);//relaod + opearation
	Set &operator+=(const Set &rset);//reload += operation
	friend Set operator-(const Set &lset, const Set &rset);//reload - operation
	Set &operator-=(const Set &rset);//reload -
	friend Set operator&(const Set &lset, const Set &rset);//reload union operation
	friend Set operator|(const Set &lset, const Set &rset);//reload intersectoin operation
	friend bool operator==(const Set &lset, const Set &rset);//equal or not
	friend bool operator!=(const Set &lset, const Set &rset);//not equal or not
	friend bool operator>(const Set &lset, const Set &rset);//greater than
	friend bool operator>=(const Set &lset, const Set &rset);//greater than or equal to
	friend bool operator<(const Set &lset, const Set &rset);//less than
	friend bool operator<=(const Set &lset, const Set &rset);//less than or equal to
	void* operator new(size_t size);//reload new operator
	void operator delete(void *p, size_t size);//reload delete operation
	~Set();//destructor
};