#include"Complex.h"
Complex::Complex() : re(0), im(0){}
Complex::Complex(double re) : re(re), im(0){}
Complex::Complex(double re, double im) : re(re), im(im){}
Complex::~Complex() = default;
Complex &Complex::operator=(const Complex& right) {
	this->im = right.im;
	this->re = right.re;
	return *this;
}
Complex operator+(const Complex &left, const Complex &right) {
	Complex res;
	res.im = left.im + right.im;
	res.re = left.re + right.re;
	return res;
}
Complex operator-(const Complex &left, const Complex &right) {
	Complex res;
	res.im = left.im - right.im;
	res.re = left.re - right.re;
	return res;
}
Complex operator*(const Complex &left, const Complex &right) {
	Complex res;
	res.im = left.im * right.re + left.re * right.im;
	res.re = -(left.im * right.im) + left.re * right.re;
	return res;
}
Complex operator/(const Complex &left, const Complex &right) {
	//use operator *
	Complex res, rightCopy;
	rightCopy.re = right.re;
	rightCopy.im = -right.im;
	if ((right.im == 0) && (right.re == 0)) return res;
	res.im = (left * rightCopy).im / (right.im * right.im + right.re * right.re);
	res.re = (left * rightCopy).re / (right.im * right.im + right.re * right.re);
	return res;
}
std::ostream& operator<<(std::ostream& is, const Complex& right) {
	is << setiosflags(ios::fixed) << setprecision(2) << right.re << " " << right.im <<endl;
	return is;
}
