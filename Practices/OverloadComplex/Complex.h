#pragma once
#include<iomanip>
#include<iostream>
using namespace std;
class Complex {
private:
	double re; //real part
	double im; //imaginary part
public:
	Complex();
	Complex(double);
	Complex(double, double);
	~Complex();
	Complex &operator=(const Complex&);//overload operator =
	friend Complex operator+(const Complex&, const Complex&);//overload operator +
	friend Complex operator-(const Complex&, const Complex&);//overload operator -
	friend Complex operator*(const Complex&, const Complex&);//overload operator *
	friend Complex operator/(const Complex&, const Complex&);//overload operator /
	friend std::ostream& operator<<(std::ostream&, const Complex&); // output
};