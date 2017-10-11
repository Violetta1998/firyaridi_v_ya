#include "vector.h"
#include <string>
#include <sstream>

vector testSummEqual(vector num) {
	using namespace std;
	vector result(num.x += num.x, num.y += num.y, num.z += num.z);
	cout << "The number was: " << num << " result of += : " << result << endl;
	return result;
}
vector testMinusEqual(vector num) {
	using namespace std;
	vector result(num.x -= num.x, num.y -= num.y, num.z -= num.z);
	cout << "The number was: " << num << " result of -= : " << result << endl;
	return result;
}

vector testDevideEqual(vector num) {
	using namespace std;
	vector result(num.x /= num.x, num.y /= num.y, num.z /= num.z);
	cout << "The number was: " << num << " result /= : " << result << endl;
	return result;
}

vector testInterfacingEqual(vector num) {
	using namespace std;
	vector result(num.x *= num.x, num.y *= num.y, num.x *= num.z);
	cout << "The number was: " << num << " result of *= : " << result << endl;
	return result;
}

double testSkalarInterfacing(vector num1, vector num2) {
	using namespace std;
	double result(num1.x*num2.x + num1.y*num2.y + num1.z*num2.z);
	cout << "The numbers were: " << num1 <<"  "<< num2 << " result of skalar interfacing: " << result << endl;
	return result;
}

double testVectorLength(vector num1) {
	using namespace std;
	double x(pow(num1.x, 2) + pow(num1.y, 2) + pow(num1.z, 2));
	double result(pow(x, 0.5));
	cout << "The number was: " << num1 << " vector length is: " << result << endl;
	return result;
}

double testVectorInterfacing(vector num1,vector num2, double corner) {
	using namespace std;
	double a1 = pow((pow(num1.x, 2) + pow(num1.y, 2) + pow(num1.z, 2)), 0.5);
	double a2 = pow((pow(num2.x, 2) + pow(num2.y, 2) + pow(num2.z,2)), 0.5);
	double sinus = sin(corner);
	double result(a1*a2*sinus);
	cout << "The numbers were: " << num1 << "  " << num2 << " and the corner " << corner <<" result of vector interfacing: " << result << endl;
	return result;

}

int main()
{
	using namespace std;
	vector a(3.5, 4.9, 9.9);
	vector b(3.2, 4.7, 5.5);
	cout << a << endl;

	vector result1(testDevideEqual(a));
	vector result2(testInterfacingEqual(a));
	vector result3(testSummEqual(a));
	vector result4(testMinusEqual(a));
	vector result5(testSummEqual(a));
	double result6(testSkalarInterfacing(a, b));
	double result7(testVectorInterfacing(a, b, 30));
	double result8(testVectorLength(a));
	return 0;
}
