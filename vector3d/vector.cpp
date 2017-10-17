#include <iostream>
#include <sstream>
#include "vector.h"
#include <cmath> 

vector& vector::operator*=(const vector& num) {
	x *= num.x;
	y *= num.y;
	z *= num.z;
	return *this;
}

vector& vector::operator+=(const vector& num) {
	x += num.x;
	y += num.y;
	z += num.z;
	return *this;
}

vector& vector::operator-=(const vector& num) {
	x -= num.x;
	y -= num.y;
	z -= num.z;
	return *this;
}

vector& vector::operator/=(const vector& num) {
	x /= num.x;
	y /= num.y;
	z /= num.z;
	return *this;
}

double operator*(const vector& num1, const vector& num2) { //скалярное умножение
	double result(num1.x*num2.x + num1.y*num2.y + num1.z*num2.z);
	return result;
}

double vectorLength(vector& num1) {
	return pow((pow(num1.x, 2) + pow(num1.y, 2) +pow(num1.z, 2)), 0.5);
}

double vectorInterfacing(vector& num1,vector& num2, double corner) { //векторное произведение
	double a = vectorLength(num1);
	double b = vectorLength(num2);
	//double num1 = pow(pow(num1.x, 2), pow(num1.y, 2),pow(num1.z,2), 0.5);
	//double num2 = pow(pow(num2.x, 2), pow(num2.y, 2), pow(num2.z,2), 0.5);
	double sinus = sin(corner);
	return a*b*sinus;
}
std::ostream& vector::writeTo(std::ostream& ostrm) const {
	ostrm << leftBrace << x << comma << y << z << rightBrace;
	return ostrm;
}

/*std::istream& vector::readFrom(std::istream& istrm) {
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good()) {
		if ((vector::leftBrace == leftBrace) && (vector::separator == comma)
			&& (vector::rightBrace == rightBrace)) {
			x = x;
			y = y;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}*/