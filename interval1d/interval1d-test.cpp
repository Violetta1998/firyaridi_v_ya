#include "interval1d.h"
#include <sstream>

using namespace std;

int main() {
	interval1d interval(1.0, 5.0);
	interval *= 5;
	interval += 5;
	interval -= 5;
	interval /= 5;
	return 0;
}