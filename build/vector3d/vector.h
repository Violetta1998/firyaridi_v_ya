#ifndef HG_COMPLEX_02102016
#define HG_COMPLEX_01012016
#include <iostream>
#include <sstream>
#include <cmath> 

struct vector {

public:
	double x{ 0.0 };
	double y{ 0.0 };
	double z{ 0.0 };

public:
	vector() = default;//умолчательный - не принимающий аргументы
	vector(const double xV, const double yV, const double zV)
		:x(xV),
		 y(yV),
		 z(zV)
	{
	}

	vector(const vector& v)//конструктор копировани€
		:x(v.x),
		 y(v.y),
		 z(v.z)
	{
	}
	~vector() = default;//дестркутор - автоматически вызываетс€ дл€ разрушени€ объекта
	vector& operator=(const vector&) = default;
	bool operator==(const vector& num) const { return (x == num.x) && (y == num.y) && (z == num.z); };
	bool operator!=(const vector& num) const { return !operator==(num); };

	vector& operator-=(const vector& num);
	vector& operator+=(const vector& num);
	vector& operator/=(const vector& num);
	vector& operator*=(const vector& num);

	std::ostream& writeTo(std::ostream& ostrm) const;
	//std::istream& readFrom(std::istream& istrm);
	static const char leftBrace{ '{' };
	static const char rightBrace{ '}' };
	static const char comma{ ',' };
};

vector operator+(const vector num1, const vector num2);
vector operator-(const vector num1, const vector num2);
vector operator*(const vector num1, const vector num2);
vector operator*(const vector num1,const vector num2, double corner);

inline std::ostream& operator<<(std::ostream& ostrm, const vector& rhs)
{
	return rhs.writeTo(ostrm);
}


//inline std::istream& operator>>(std::istream& istrm, vector& rhs) 
//{
//	return rhs.readFrom(istrm);
//}



std::ostream& vector::writeTo(std::ostream& ostrm) const {
	ostrm << leftBrace << x << comma << y << z << rightBrace;
	return ostrm;
}

#endif