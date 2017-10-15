#ifndef HG_COMPLEX_02102016 
#define HG_COMPLEX_01012016 
#include <iostream> 
#include <sstream> 
#include <cmath> 

template<typename T>
struct vectorT
{
public:
	T x{ T() };
	T y{ T() };
	T z{ T() };

public:
	vectorT() = default;
	vectorT(const T& xV, const T& yV, const T& zV)
		:x(xV),
		y(yV),
		z(zV)
	{
	}

	vectorT(const vectorT& v)
		:x(v.x),
		y(v.y),
		z(v.z)
	{
	}

	~vectorT() = default;
	vectorT<T>& operator*=(const vectorT<T>& num);
	vectorT<T>& operator+=(const vectorT<T>& num);
	vectorT<T>& operator-=(const vectorT<T>& num);
	vectorT<T>& operator/=(const vectorT<T>& num);

	//std::ostream& writeTo(std::ostream& ostrm) const;
	//std::istream& readFrom(std::istream& istrm); 
	static const char leftBrace{ '{' };
	static const char rightBrace{ '}' };
	static const char comma{ ',' };
};

/*template<typename T>
vectorT<T>::vectorT(const T& _x, const T& _y, const T& _z) :x(_x), y(_y), z(_z) {}*/

template<typename T>
vectorT<T>& operator*(const vectorT<T> num1, const vectorT<T> num2);

template<typename T>
vectorT<T>& vectorT<T>::operator*=(const vectorT<T>& num)
{
	x *= num.x;
	y *= num.y;
	z *= num.z;
	return *this;
}

template<typename T>
vectorT<T>& vectorT<T>::operator+=(const vectorT<T>& num)
{
	x += num.x;
	y += num.y;
	z += num.z;
	return *this;
}

template<typename T>
vectorT<T>& vectorT<T>::operator-=(const vectorT<T>& num) {
	x -= num.x;
	y -= num.y;
	z -= num.z;
	return *this;
}

template<typename T>
vectorT<T>& vectorT<T>::operator/=(const vectorT<T>& num)
{
	x /= num.x;
	y /= num.y;
	z /= num.z;
	return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& ostrm, const vectorT<T>& rhs)
{
	return rhs.writeTo(ostrm);
}

#endif

