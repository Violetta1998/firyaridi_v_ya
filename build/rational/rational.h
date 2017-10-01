#ifndef HG_COMPLEX_02102016
#define HG_COMPLEX_01012016
#include <iostream>
#include <sstream>

struct Rational {
	Rational() {}
	explicit Rational(const int unit);
	Rational(const int unit, const int fract);

	bool operator ==(const Rational& obj) const { return (unit == obj.unit) && (fract == obj.fract); }

	bool operator !=(const Rational& obj) const { return !operator==(obj); }

	Rational& operator+=(const Rational& obj);

	Rational& operator+=(const double obj) { return operator+=(Rational(obj)); }
	Rational& operator=(const Rational& obj);
	Rational& operator-=(const Rational& obj);
	Rational& operator/=(const Rational& obj);

	//Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	//Complex& operator*=(const Complex& rhs);

	Rational& operator*=(const double obj);

	std::ostream& writeTo(std::ostream& ostrm) const; //ostream - вывод
	std::istream& readFrom(std::istream& istrm); //istream - ввод

	int unit{ 0 };
	int fract{ 0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Rational operator+(const Rational& ihs, const Rational& rhs);
Rational operator-(const Rational& ihs, const Rational& rhs);
Rational operator*(const Rational& ihs, const Rational& rhs);
Rational operator/(const Rational& ihs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs) {
	return rhs.readFrom(istrm);
}


#endif
