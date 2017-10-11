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
	double result(pow(pow(num1.x, 2), pow(num1.y, 2), pow(num1.z, 2), 0.5));
	cout << "The number was: " << num1 << " vector length is: " << result << endl;
	return result;
}

double testVectorInterfacing(vector num1,vector num2, double corner) {
	double num1 = pow(pow(num1.x, 2), pow(num1.y, 2), pow(num1.z, 2), 0.5);
	double num2 = pow(pow(num2.x, 2), pow(num2.y, 2), pow(num2.z,2), 0.5);
	double sinus = sin(corner);
	double result(num1*num2*sinus);
	cout << "The numbers were: " << num1 << "  " << num2 << " and the corner " << corner <<" result of vector interfacing: " << result << endl;
	return result;

}

int main()
{
	using namespace std;
	vector a(3.5, 4.9, 9.9);
	vector b(3.2, 4.7, 5.5);
	cout << a << endl;

	vector result(testDevideEqual(a));
	vector result(testInterfacingEqual(a));
	vector result(testSummEqual(a));
	vector result(testMinusEqual(a));
	vector result(testSummEqual(a));
	vector result(testSkalarInterfacing(a, b));
	vector result(testVectorInterfacing(a, b, 30));
	vector result(testVectorLength(a));
	return 0;
}
