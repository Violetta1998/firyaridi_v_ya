#include "array.h"
#include <iostream>
#include <sstream>
#include <cstddef>>

using namespace std;
void consoleArray(Array& mass) {
	cout << "array";
	for (int i = 0; i < mass.size(); i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}

int main() {
	Array testMassive(3);
	testMassive[0] = 1;
	testMassive[1] = 10;
	testMassive[2] = 100;
	Array testMassive2(testMassive);

	try {
		testMassive[3] = 1000;
	}
	catch (length_error err) {
		cout << "Size is less then index" << endl;
	}

	consoleArray(testMassive);

	try {
		testMassive.remove(-1);
	}
	catch (invalid_argument e) {
		cout << "I cannot remove negative elements" << endl;
	}

	testMassive.insert(3, 1000);
	cout << "Massive after insert 1000 on index 3: " << endl;
	consoleArray(testMassive);

	testMassive.remove(1);
	cout << "Massive after removing a 1 index: " << endl;
	consoleArray(testMassive);

	cout << "capacity before resize:" << testMassive.capacity() << endl;
	testMassive.resize(10);
	cout << "capacity after resize:" << testMassive.capacity() << endl;
	return 0;
}