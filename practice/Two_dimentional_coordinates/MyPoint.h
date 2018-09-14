#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class MyPoint
{
private:
	int x, y;
public:
	MyPoint();//constructor without parameters
	MyPoint(int x, int y);//constructor of specified-coordinate parameters 
	int getX() const;//get x, print it and newline
	int getY() const;//get y, print it and newline
	double distance(const MyPoint p);//return the distance between two points
	double distance(int x, int y);//the distance of specified x and y points
};

