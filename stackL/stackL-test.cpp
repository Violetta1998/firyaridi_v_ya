#include "stackL.h"
#include <cstddef>
#include <iostream>
#include <sstream>

using namespace std;

void testMethods(StackL& test) {
	bool emptiness = test.isEmpty();
	cout << "Stack test is empty? : " << emptiness << endl;
	test.push(10);
	cout << "Pushed 10" << endl;
	int x = test.top();
	cout << "Stack top is "<<x<< endl;
}

void testPop(StackL& test) {
	test.push(100);
	test.push(200);
	cout << "Pushed 100 and 200" << endl;
	test.pop();
	cout << "Top after the pop is : " << test.top() << endl;
}

int main() {
	StackL test;
	testMethods(test);
	testPop(test);
	return 0;
}