#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>

class Array {
public:
	explicit Array()=default;
	Array(const int& size);
	Array(const Array& mass);
	~Array() = default;

	ptrdiff_t& size();
	ptrdiff_t& capacity();

	int& operator[](const ptrdiff_t i);
	const int& operator[](const ptrdiff_t i) const;
	Array& operator=(const Array& obj);
	void resize(const ptrdiff_t& newCapacity);
	void insert(ptrdiff_t i, int data);
	void remove(ptrdiff_t i);
	void swapObjects(Array& mass);

private:
	ptrdiff_t capacity_{ 0 };
	ptrdiff_t size_{ 0 };
	int* pdata_{ nullptr };
};

#endif
