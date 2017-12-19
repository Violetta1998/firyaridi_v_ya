#include "stackArray.h"
#include <iostream>

using namespace std;
int main() {

	stackArray test(10);
	test.push(50);
	test.push(200);
	test.push(300);
	test.pop();
	int k = test.top();
	cout << k;
	return 0;
}