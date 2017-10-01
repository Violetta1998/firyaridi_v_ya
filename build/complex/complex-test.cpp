#include "complex.h"
#include <string>
#include <sstream>

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

Complex testPlusEqual(Complex z) {
	using namespace std;
	cout << "Test of +=   The number was:" << z << endl;
	Complex plusEqual(z.re+=z.re, z.im+=z.im);
	cout << "The result:" << plusEqual << endl;
	return plusEqual;
}
Complex testMinusEqual(Complex z) {
	using namespace std;
	cout << "Test of -=   The number was:" << z << endl;
	Complex minusEqual(z.re -= z.re, z.im -= z.im);
	cout << "The result:" << minusEqual << endl;
	return minusEqual;
}
Complex testDevideEqual(Complex z) {
	using namespace std;
	cout << "Test of /=   The number was:" << z << endl;
	Complex devideEqual(z.re /= z.re, z.im /= z.im);
	cout << "The result:" << devideEqual << endl;
	return devideEqual;
}
Complex testMultiplyEqual(Complex z) {
	using namespace std;
	cout << "Test of *=   The number was:" << z << endl;
	Complex multiplyEqual(z.re *= z.re, z.im *= z.im);
	cout << "The result:" << multiplyEqual << endl;
	return multiplyEqual;
}

Complex testDevide(const Complex z,const Complex s) {
	using namespace std;
	Complex devide = z/s;

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

Complex testInterfacing(Complex z) {
	using namespace std;
	Complex interface(z.re,z.im*(-1));

	cout << "The number was " << z << ", result of interfacing " << interface << endl;
	return interface;
}

Complex testTrigonomicInterpretation(Complex rhs) {
	using namespace std;
	double summ = rhs.re*rhs.re + rhs.im*rhs.im;
	double r = pow(summ, 0.5);
	double corner = atan(rhs.im / rhs.re);
	Complex geom(r*cos(corner), r*sin(corner));
	cout << "The number " << rhs << "in trigonomic interpretation is" <<geom<< endl;
	return geom;
}
Complex testExponetiation(Complex a,double n) {
	using namespace std;
	cout << "Test of exponentiation number " << a << endl;
	testTrigonomicInterpretation(a);
	Complex exponent(pow(a.re, n), pow(a.im, n));
	cout <<" was exponented in " << n << " the result is: " << exponent << endl;
	return exponent;
}

int testSummDifferentTypes(Complex a, int n) {
	using namespace std;
	cout << "Test summ of different types " << " First complex:  " << a << "Second int:  " << n << endl;
	int result(static_cast<int>(a.re) + n);
	cout << "Result is " << result << endl;
	return result;
}

int testSummDifferentTypesReversed(int n,Complex a) {
	using namespace std;
	cout << "Test summ of different types " << " First int:  " << n << " Second complex:  " << a << endl;
	int result(static_cast<int>(a.re) + n);
	cout << "Result is " << result << endl;
	return result;
}

int main() {
	using namespace std;

	Complex z;
	z += Complex(8.0);
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9}");

	Complex first(1.353,-1.566);
	Complex second(0.0,0.0);

	testDevide(first, second);//0.0
	testMultiply(first, second);//0+0i
	testSubtraction(first, second);//8+8i
	testSumm(first, second);//8+8i
	
	testDevideEqual(first);
	testMinusEqual(first);
	testMultiplyEqual(first);
	testPlusEqual(first);

	testInterfacing(first);
	testTrigonomicInterpretation(first);
	testExponetiation(first, 3.5);

	Complex a(100);
	testSummDifferentTypes(a, 9);
	testSummDifferentTypesReversed(100, a);
	return 0;
}

