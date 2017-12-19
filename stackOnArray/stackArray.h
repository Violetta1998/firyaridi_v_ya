#ifndef STACK_H
#include <cstddef>

class stackArray {

public:
	stackArray(const int size);
	//stackArray(stackArray& obj);
	~stackArray();

	void push(const int& element);
	void pop();
	int& top();
	const int& top()const;
	bool isEmpty() const;
	int size();
	void clear();

private:
	int stackSize;
	int * arrayL;
};

#endif