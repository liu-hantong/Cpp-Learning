#pragma once
#include<iostream>
#include<string>
using namespace std;
template <typename T>
class Iterator {
public:
	T* ptr;//member variable
public:
	Iterator(T *p = 0) : ptr(p) {};//construtor
	~Iterator() = default;//destructor
	template<typename T> friend Iterator operator+(const Iterator&, const size_t&);//reload +
	template<typename T> friend Iterator operator-(const Iterator&, const size_t&);//reload -
	Iterator& operator++();//reload ++
	Iterator& operator--();//reload --
	Iterator operator++(int);//reload ++
	Iterator operator--(int);//reload --
	Iterator& operator=(const Iterator&);//reload =
	template<typename T> friend bool operator==(const Iterator&, const Iterator&);//relaod ==
	template<typename T> friend bool operator!=(const Iterator&, const Iterator&);//reload !=
	T operator*();//returns the reference of the current iterator 
};