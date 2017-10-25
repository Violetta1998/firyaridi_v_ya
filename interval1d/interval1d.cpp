#include "interval1d.h"

interval1d& interval1d::operator+=(const interval1d& interval)
{
	x1 += interval.x1;
	x2 = interval.x2;
	return *this;
}

interval1d& interval1d::operator-=(const interval1d& interval) {
	x1 -= interval.x1;
	x2 -= interval.x2;
	return *this;
}

interval1d& interval1d::operator*=(const interval1d& interval) {
	x1 *= interval.x1;
	x2 *= interval.x2;
	return *this;
}

interval1d& interval1d::operator/=(const interval1d& interval) {
	x1 /= interval.x1;
	x2 /= interval.x2;
	return *this;
}

interval1d operator+(const interval1d& interval1, const interval1d& interval2)
{
	return interval1d((interval1.x1 + interval2.x1), (interval1.x2 + interval2.x2));
}

interval1d operator-(const interval1d& interval1, const interval1d& interval2)
{
	return interval1d((interval1.x1 - interval2.x1), (interval1.x2 - interval2.x2));
}

double intervalLength(interval1d interval) {
	return (interval.x2 - interval.x1);
}

interval1d operator/(const interval1d& interval1, const interval1d& interval2)
{
	return interval1d((interval1.x1 / interval2.x1), (interval1.x2 / interval2.x2));
}

interval1d unique(interval1d interval1, interval1d interval2) {
	
	if (interval2.x1<interval1.x2 && interval2.x1>interval1.x1) 
	{
		if (interval2.x2 > interval1.x2){
			return interval1d(interval2.x1, interval1.x2);
		}
		if (interval2.x2 <= interval1.x2){
			return interval1d(interval2.x1, interval2.x2);
		}
		if (interval2.x2 < interval1.x1) {
			return interval1d(interval1.x1, interval2.x1);
		}
	}

	if (interval1.x1>interval2.x1 && interval1.x2<interval2.x2)
	{
		return interval1d(interval1.x1, interval1.x2);
	}
	return interval1d(interval1);
}