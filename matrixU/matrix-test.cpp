#include "matrix.h"
#include <sstream>
#include <iostream>
#include <cstddef>

using namespace std;

int main() 
{
	MatrixU test(3,3);
	test.set(0, 1, 10);
	test.set(0, 2, 20); 

	try {
		MatrixU test2(-1, -1);
	}
	catch (invalid_argument err) {
		cout << "Matrix's size cannot be negative" << endl;
	}

	try {
		test.set(4, 4, 100);
	}
	catch (invalid_argument err) {
		cout << "Size is more then a size of concrete Matrix" << endl;
	}

	try {
		test.at(4, 4);
	}
	catch (invalid_argument err) {
        cout << "Size is more then a size of concrete Matrix" << endl;
	}
	MatrixU test2(3, 3);
	test2.set(0, 1, 10);
	test2.set(0, 2, 20);
	
	test.consoleMatrix(test);
	test2.consoleMatrix(test2);

	test.minusMatrix(test, test2);
	test.consoleMatrix(test);
	
	test.multiplyOnNumber(test, 435);
	test.consoleMatrix(test);
	
	test2.summMatrix(test, test2);
	test2.consoleMatrix(test2);
	return 0;
}