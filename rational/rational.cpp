#include <iostream>
#include <sstream>
#include "rational.h"
#include <cmath> 

Rational::Rational(const int unit, const int fractial)
	: unit(unit),
	fract(fractial)
{

}

Rational& Rational::operator+=(const Rational& rhs) {
	unit += rhs.unit;
	fract += rhs.fract;
	return *this;
}

Rational& Rational::operator*=(const double rhs) {
	unit *= rhs;
	fract *= rhs;
	return *this;
}

Rational& Rational::operator=(const Rational& rhs) {
	unit = rhs.unit;
	fract = rhs.fract;
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
	unit -= rhs.unit;
	fract -= rhs.fract;
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
	unit /= rhs.unit;
	fract /= rhs.fract;
	return *this;
}

Rational operator+(const Rational& ihs, const Rational& rhs) {
	return Rational(ihs.unit + rhs.unit, ihs.fract + rhs.fract);
}

Rational operator -(const Rational& ihs, const Rational& rhs) {
	return Rational(ihs.unit - rhs.unit, ihs.fract - rhs.fract);
}

Rational operator *(const Rational& ihs, const Rational& rhs) {
	return Rational((rhs.unit*ihs.unit), (rhs.fract*ihs.fract));
}


Rational operator /(const Rational& ihs, const Rational& rhs) {
	return Rational(rhs.unit/ihs.unit,rhs.fract/ihs.fract);
}

Rational interfacing(const Rational& rhs) {
	return Rational((-1)*rhs.unit);
}

Rational exponentiation(Rational& rhs, double n) {
	return Rational(pow(rhs.unit, n), pow(rhs.fract, n));
}

Rational rootExtraction() {

}


std::ostream& Rational::writeTo(std::ostream& ostrm) const {
	ostrm << leftBrace << unit << separator << fract << rightBrace;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
	char leftBrace(0);
	char comma(0);
	char rightBrace(0);
	//int unit = 0, fract = 0;
	istrm >> leftBrace >> unit >> comma >> fract >> rightBrace;
	if (istrm.good()) {
		if ((Rational::leftBrace == leftBrace) && (Rational::separator == comma)
			&& (Rational::rightBrace == rightBrace)) {
			unit = unit;
			fract = fract;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}