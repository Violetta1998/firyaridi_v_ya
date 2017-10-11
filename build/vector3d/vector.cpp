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
	return new double(num1.x*num2.x +num1.y*num2.y + num1.z*num2.z);
}

double vectorLength(vector& num1) {
	return pow(pow(num1.x, 2), pow(num1.y, 2), pow(num1.z, 2), 0.5);
}

double operator*(const vector& num1,const vector& num2, double corner) { //векторное произведение
	double a = vectorLength(num1);
	double b = vectorLength(num2);
	//double num1 = pow(pow(num1.x, 2), pow(num1.y, 2),pow(num1.z,2), 0.5);
	//double num2 = pow(pow(num2.x, 2), pow(num2.y, 2), pow(num2.z,2), 0.5);
	double sinus = sin(corner);
	return a*b*sinus;
}