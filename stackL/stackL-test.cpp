#include "stackL.h"
#include <cstddef>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	StackL test;
	bool x = test.isEmpty();
	test.push(5);
	test.push(3);
	test.push(4);
	test.isEmpty();
	test.pop();
	int top = test.top();
	return 0;
}