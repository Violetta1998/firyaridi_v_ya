#include "complex.h"
#include "complex.cpp"

bool testParse(const std::string& str) {
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << "->" << z << endl;
	}
	else {
		cout << "Read error: " << str << "->" << z << endl;
	}
	return istrm.good();
}

Complex testDevide(Complex z, Complex s) {
	using namespace std;
	Complex devide = z / s;

	cout << z << " / " << s << " result " << devide << endl;
	return devide;;
}

Complex testMultiply(Complex z, Complex s) {
	using namespace std;
	Complex multiply = z * s;

	cout << z << " * " << s << " result " << multiply << endl;
	return multiply;;
}

Complex testSubtraction(Complex z, Complex s) {
	using namespace std;
	Complex subtraction = z - s;

	cout << z << " - " << s << " result " << subtraction << endl;
	return subtraction;;
}

Complex testSumm(Complex z, Complex s) {
	using namespace std;
	Complex summ = z + s;

	cout << z << " + " << s << " result " << summ << endl;
	return summ;
}

int main() {
	using namespace std;

	Complex z;
	z += Complex(8.0);
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9}");

	Complex first; first.re = 8; first.im = 8;
	Complex second; second.re = 0; second.im = 0;
	testDevide(first, second);
	testMultiply(first, second);
	testSubtraction(first, second);
	testSumm(first, second);
	return 0;
}

