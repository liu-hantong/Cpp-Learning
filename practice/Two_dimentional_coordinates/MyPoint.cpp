#include "MyPoint.h"


MyPoint::MyPoint() : x(0), y(0) {};
MyPoint::MyPoint(int x, int y) : x(x), y(y) {};
int MyPoint::getX() const { cout << x << endl; return x; }
int MyPoint::getY() const { cout << y << endl; return y; }
double MyPoint::distance(const MyPoint p) 
{
	double dis = sqrt(pow(abs(this->x - p.x), 2) + pow(abs(this->y - p.y), 2));
	cout << dis << endl;
	return dis;
}
double MyPoint::distance(int x, int y)
{
	double dis = sqrt(pow(abs(this->x - x), 2) + pow(abs(this->y - y), 2));
	cout << dis << endl;
	return dis;
}