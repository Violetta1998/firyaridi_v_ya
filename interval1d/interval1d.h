#ifndef HG_COMPLEX_02102016
#define HG_COMPLEX_01012016
#include <cmath> 

struct interval1d {
public:
	double x1{ 0.0 };
	double x2{ 0.0 };

public:
	interval1d() = default;
	interval1d(const double _x1, const double _x2)
		:x1(_x1),
		x2(_x2)
	{
	};

	interval1d(const interval1d& interval)
		:x1(interval.x1),
		x2(interval.x2)
	{
	};

	bool operator ==(interval1d& interval)const { return (x1 == interval.x1 && x2 == interval.x2); };
	interval1d& operator+=(const interval1d& interval);
	interval1d& operator-=(const interval1d& interval);
	interval1d& operator*=(const interval1d& interval);
	interval1d& operator/=(const interval1d& interval);

};
interval1d operator+(interval1d interval1, interval1d interval2);
interval1d operator-(interval1d interval1, interval1d interval2);
interval1d operator/(interval1d interval1, interval1d interval2);



#endif