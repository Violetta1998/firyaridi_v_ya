#include "array.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Array::Array(const int & size)
{
	if (size < 0) {
		throw "Size cannot be negative";
	}
	capacity_ = size;
	size_ = size;
	if (size != 0) { pdata_ = (new int[capacity_]); }
}

Array::Array(const Array & mass)
	:capacity_(mass.capacity_),
	size_(mass.size_)
{
	pdata_ = new int[capacity_];
	for (int i = 0; i < capacity_; i++)
	{
		*(pdata_ + i) = *(mass.pdata_ + i);
	}
}

ptrdiff_t & Array::size()
{
	return this->size_;
}

ptrdiff_t & Array::capacity()
{
	return this->capacity_;
}

int & Array::operator[](const ptrdiff_t i)
{
	if (i >= capacity_) {
		throw "index out of range";
	}
	return *(pdata_ + i);
}

const int & Array::operator[](const ptrdiff_t i) const
{
	if (i >= capacity_) {
		throw "index out of range";
	}
	return *(pdata_ + i);
}

void Array::swapObjects(Array& mass)
{
	swap(capacity_, mass.capacity_);
	swap(size_, mass.size_);
	swap(pdata_, mass.pdata_);
}

Array& Array::operator=(const Array & mass)
{
	if (this != &mass) { swapObjects(Array(mass)); }
	return *this;
}

void Array::resize(const ptrdiff_t& newCapacity)
{
	if (newCapacity <= 0) { throw "new cpacity cannot be negative"; }
	Array mass(newCapacity);
	if (newCapacity < size_) {
		mass.size_ = newCapacity;
	}
	else mass.size_ = size_;

	for (int i = 0; i < newCapacity; i++) {
		*(pdata_ + i) = *(mass.pdata_ + i);
	}
	this->swapObjects(mass);
}

void Array::insert(ptrdiff_t index, int data)
{
	if (index < 0) {
		throw "You cannot insert an element with negative index";
	}
	if (index >= size_) {
		throw "You cannot insert an element with index that is more than array size";
	}

	if (size_ = capacity_) {
		this->resize(size_ + 1);
	}
	size_++;
	for (int i = index + 1; i < size_; i++)
	{
		*(pdata_ + i) = *(pdata_ + i - 1);
	}
	*(pdata_ + index) = data;
}

void Array::remove(ptrdiff_t index)
{
	if (index < 0) {
		throw "You cannot remove an element with negative index";
	}
	if (index >= size_) {
		throw "You cannot remove an element with index that is more than array size";
	}
	for (int i = 0; i < size_ - 1; i++) {
		*(pdata_ + i) = *(pdata_ + i - 1);
	}
	capacity_--;
}

