#include"QuadraticEquation.h"
QuadraticEquation::QuadraticEquation(int a, int b, int c) : a(a), b(b), c(c) {};
int QuadraticEquation::getA() const { cout << a << endl; return a; };
int QuadraticEquation::getB() const { cout << b << endl; return b; };
int QuadraticEquation::getC() const { cout << c << endl; return c; };
int QuadraticEquation::getDiscriminant() { int x = b * b - 4 * a * c; cout << x << endl; return x; };
double QuadraticEquation::getRoot1() {
	int discriminant = b * b - 4 * a * c;
	if (discriminant < 0) {
		cout << 0 << endl;
		return 0.0;
	}
	else if (discriminant == 0) {
		cout << -static_cast<double>(b) / static_cast<double>(2 * a) << endl;
		return -static_cast<double>(b) / static_cast<double>(2 * a);
	}
	else if (a > 0 && discriminant > 0) {
		double solution = static_cast<double>(-b + sqrt(discriminant)) / static_cast<double>(2 * a);
		cout << solution << endl;
		return  solution;
	}
	else if (a < 0 && discriminant > 0) {
		double solution = static_cast<double>(-b - sqrt(discriminant)) / static_cast<double>(2 * a);
		cout << solution << endl;
		return  solution;
	}
}
double QuadraticEquation::getRoot2() {
	int discriminant = b * b - 4 * a * c;
	if (discriminant < 0) {
		cout << 0.0 << endl;
		return 0;
	}
	else if (discriminant == 0) {
		cout << -static_cast<double>(b) / static_cast<double>(2 * a) << endl;
		return -static_cast<double>(b) / static_cast<double>(2 * a);
	}
	else if (a > 0 && discriminant > 0) {
		double solution = static_cast<double>(-b - sqrt(discriminant)) / static_cast<double>(2 * a);
		cout << solution << endl;
		return  solution;
	}
	else if (a < 0 && discriminant > 0) {
		double solution = static_cast<double>(-b + sqrt(discriminant)) / static_cast<double>(2 * a);
		cout << solution << endl;
		return  solution;
	}
}