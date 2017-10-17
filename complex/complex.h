#ifndef HG_COMPLEX_02102016
#define HG_COMPLEX_01012016

#include <iostream>

struct Complex
{
	Complex() {}
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);

	bool operator ==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }//нельзя сравнивать вещ. числа

	bool operator !=(const Complex& rhs) const { return !operator==(rhs); }

	Complex& operator+=(const Complex& rhs);

	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator/=(const Complex& rhs);

	//Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	//Complex& operator*=(const Complex& rhs);

	Complex& operator*=(const double rhs);

	std::ostream& writeTo(std::ostream& ostrm) const; //ostream - вывод
	std::istream& readFrom(std::istream& istrm); //istream - ввод

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Complex operator+(const Complex& ihs, const Complex& rhs);
Complex operator-(const Complex& ihs, const Complex& rhs);
Complex operator/(const Complex& ihs, const Complex& rhs);
Complex operator*(const Complex& ihs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Complex& rhs) {
	return rhs.readFrom(istrm);
}


#endif
