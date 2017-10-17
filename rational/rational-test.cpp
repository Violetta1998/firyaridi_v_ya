#include "rational.h"
#include <string>
#include <sstream>


Rational testPlusEqual(Rational z) {
	using namespace std;
	cout << "Test of +=   The number was:" << z << endl;
	Rational plusEqual(z.unit += z.unit, z.fract += z.fract);
	cout << "The result:" << plusEqual << endl;
	return plusEqual;
}
Rational testMinusEqual(Rational z) {
	using namespace std;
	cout << "Test of -=   The number was:" << z << endl;
	Rational minusEqual(z.unit -= z.unit, z.fract -= z.fract);
	cout << "The result:" << minusEqual << endl;
	return minusEqual;
}
Rational testDevideEqual(Rational z) {
	using namespace std;
	cout << "Test of /=   The number was:" << z << endl;
	Rational devideEqual(z.unit /= z.unit, z.fract /= z.fract);
	cout << "The result:" << devideEqual << endl;
	return devideEqual;
}
Rational testMultiplyEqual(Rational z) {
	using namespace std;
	cout << "Test of *=   The number was:" << z << endl;
	Rational multiplyEqual(z.unit *= z.unit, z.fract *= z.fract);
	cout << "The result:" << multiplyEqual << endl;
	return multiplyEqual;
}
bool testParse(const std::string& str) {
	using namespace std;
	istringstream istrm(str);
	Rational z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << "->" << z << endl;
	}
	else {
		cout << "Read error: " << str << "->" << z << endl;
	}
	return istrm.good();
}

Rational testDevide(Rational z, Rational s) {
	using namespace std;
	Rational devide = z / s;

	cout << z << " / " << s << " result " << devide << endl;
	return devide;;
}

Rational testMultiply(Rational z, Rational s) {
	using namespace std;
	Rational multiply = z * s;

	cout << z << " * " << s << " result " << multiply << endl;
	return multiply;;
}

Rational testSubtraction(Rational z, Rational s) {
	using namespace std;
	Rational subtraction = z - s;

	cout << z << " - " << s << " result " << subtraction << endl;
	return subtraction;;
}

Rational testSumm(Rational z, Rational s) {
	using namespace std;
	Rational summ = z + s;

	cout << z << " + " << s << " result " << summ << endl;
	return summ;
}

Rational testExponentian(Rational a, double n) {
	using namespace std;
	cout << "Test of exponentiation number " << a << endl;
	Rational exponent(pow(a.unit, n), pow(a.fract, n));
	cout << " was exponented in " << n << " the result is: " << exponent << endl;
	return exponent;
}
int testSummDifferentTypes(Rational a, int n) {
	using namespace std;
	cout << "Test summ of different types " << " First rational:  " << a << "Second int:  " << n << endl;
	int result(static_cast<int>(a.unit) + n);
	cout << "Result is " << result << endl;
	return result;
}

int testSummDifferentTypesReversed(int n, Rational a) {
	using namespace std;
	cout << "Test summ of different types " << " First int:  " << n << " Second rational:  " << a << endl;
	int result(static_cast<int>(a.unit) + n);
	cout << "Result is " << result << endl;
	return result;
}
int main() {
	using namespace std;

	Rational z;
	z += Rational(8.0);
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9}");

	Rational first; first.unit = 8; first.fract = 8;
	Rational second; second.unit = 0; second.fract = 0;
	testDevide(first, second);
	testMultiply(first, second);
	testSubtraction(first, second);
	testSumm(first, second);
	return 0;
}

