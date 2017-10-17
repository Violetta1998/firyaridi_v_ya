#include "vectorT.h"
#include <string> 
#include <sstream> 
#include <cmath>

using namespace std;

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

int main() {
	vectorT<double> vec(2.0, 3.0, 1.0);
	vectorT<double> vec2(3.5, 1.0, 2.5);
	vec += vec2;
	vec2 += vec;

	vectorT<double> num1(1.0, 2.0, 3.0);
	vectorT<double> num2(1.0, 2.0, 3.0);
	num1 *= num2;////1 4 9
	double num3(vectorLength(num1));//9,8

	double res = vectorInterfacing(num1, num2, 30.0);//18.3

    //cout << vec << endl;
	return 0;
}