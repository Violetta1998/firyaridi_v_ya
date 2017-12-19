#include "stackArray.h"

stackArray::stackArray(const int maxSize)
{
	stackSize = 0;
	arrayL = new int[maxSize];
}

stackArray::~stackArray()
{
	delete[] arrayL;
}

void stackArray::push(const int & element)
{
	arrayL[stackSize] = element;
	stackSize++;
}

void stackArray::pop()
{
	stackSize--;
}

int & stackArray::top()
{
	return arrayL[stackSize - 1];
}

const int & stackArray::top() const
{
	return arrayL[stackSize - 1];
}

int stackArray::size() {
	return stackSize;
}

/*bool stackArray::isEmpty() const
{
	return false;
}*/


