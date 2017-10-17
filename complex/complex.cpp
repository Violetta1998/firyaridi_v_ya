#include <iostream>
#include <sstream>
#include "complex.h"
#include <cmath> 

Complex::Complex(const double real)
     :Complex(real, 0.0)
{

}

Complex::Complex(const double real, const double imaginary)
	: re(real),
	im(imaginary)
{

}

Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator*=(const double rhs) {
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex& Complex::operator=(const Complex& rhs) {
	re = rhs.re;
	im = rhs.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
	re /= rhs.re;
	im /= rhs.im;
	return *this;
}

Complex operator+(const Complex& ihs, const Complex& rhs) {
	return Complex(ihs.re + rhs.re, ihs.im + rhs.im);
}

Complex operator -(const Complex& ihs, const Complex& rhs) {
	return Complex(ihs.re - rhs.re, ihs.im - rhs.im);
}

Complex operator *(const Complex& ihs, const Complex& rhs) {
	return Complex((rhs.re*ihs.re - rhs.im*ihs.im) , (rhs.re*ihs.im + rhs.im*ihs.re));
}


Complex operator /(const Complex& ihs, const Complex& rhs) {
	return Complex((rhs.re*ihs.re + rhs.im*ihs.im) / (ihs.re*ihs.re + ihs.im*ihs.im), 
		(rhs.im*ihs.re - rhs.re*ihs.im) / (ihs.re*ihs.re + ihs.im*ihs.im));
}

Complex interfacing(const Complex& rhs) {
	return Complex(rhs.re, (-1)*rhs.im);
}

Complex trigonomicInterpretation(Complex& rhs) {
	double summ = rhs.re*rhs.re + rhs.im*rhs.im;
	double r = pow(summ, 0.5);
	double corner = atan(rhs.im / rhs.re);
	Complex geom(r*cos(corner), r*sin(corner));
	return geom;
}

Complex exponentiation(Complex& rhs, double n) {
	trigonomicInterpretation(rhs);
	return Complex(pow(rhs.re, n), pow(rhs.im, n));
}

int summDifferentTypes(Complex& rhs, int a) {
	return static_cast<int>(rhs.re) + a;
}
int summDifferentTypesReversed(int a, Complex& rhs) {
	return static_cast<int>(rhs.re) + a;
}
double summDifferentTypes(Complex& rhs, double a) {
	return static_cast<double>(rhs.re) + a;
}
double summDifferentTypesReversed(double a, Complex& rhs) {
	return static_cast<double>(rhs.re) + a;
}

//Complex rootExtraction() {}


std::ostream& Complex::writeTo(std::ostream& ostrm) const {
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaginary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}