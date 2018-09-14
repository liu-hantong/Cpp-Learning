#pragma once
#include<iostream>
#include<math.h>
using namespace std;
class QuadraticEquation
{
private:
	int a, b, c;
public:
	QuadraticEquation(int a, int b, int c);
	int getA() const;
	int getB() const;
	int getC() const;
	int getDiscriminant();
	double getRoot1(), getRoot2();
};
