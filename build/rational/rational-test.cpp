#include "rational.h"
#include "rational.cpp"

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

