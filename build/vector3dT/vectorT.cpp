#include <iostream>
#include <sstream>
#include "vectorT.h"
#include <cmath> 

template <typename T>
vectorT<T>& operator*(const vectorT<T>& num1, const vectorT<T>& num2) {
	vectorT<T> result(num1.x*num2.x + num1.y*num2.y + num1.z*num2.z);
	return result;
}

template <typename T>
T vectorLength(vectorT<T>& num1) {
	return pow((pow(num1.x, 2) + pow(num1.y, 2) + pow(num1.z, 2)), 0.5);
}

template <typename T>
T vectorInterfacing(vectorT<T>& num1, vectorT<T>& num2, T corner) {
	T a = vectorLength(num1);
	T b = vectorLength(num2);
	T sinus = sin(corner);
	return a*b*sinus;
}
