#include "interval1d.h"
#include <string>
#include <sstream>

double intervalLength(interval1d interval) {
	return (interval.x1 - interval.x2);
}

int main() {
	interval1d interval(1.0, 5.0);
	double length(intervalLength(interval));//4

	return 0;
}