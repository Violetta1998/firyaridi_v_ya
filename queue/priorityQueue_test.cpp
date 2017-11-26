#include "priorityQueue.h"
#include <cstddef>
#include <iostream>
#include <sstream>


using namespace std;

void testMethods(PriorityQueue& queue) {
	bool emptiness = queue.isEmpty();
	cout << "Queue test is empty? : " << emptiness << endl;
	queue.push(10);
	cout << "Pushed 10" << endl;
	int x = queue.top();
	cout << "Queue top is " << x << endl;
}

void testPop(PriorityQueue& test) {
	test.push(100);
	test.push(200);
	cout << "Pushed 100 and 200" << endl;
	test.pop();
	cout << "Top after the pop is : " << test.top() << endl;
}

int main() {
	PriorityQueue test;
	test.push(10);
	test.push(100);
	test.push(200);
	test.push(300);
	test.pop();
	int top = test.top();//100
	testMethods(test);
	testPop(test);
	return 0;
}