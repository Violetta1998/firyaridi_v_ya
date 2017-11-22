#ifndef STACKL
#define STACKL
#include <cstddef>

class StackL {
public:
	StackL() = default;
	StackL(const StackL& obj);

	void push(const int& element);
	void pop();
	int& top();//?
	const int& top() const;
	bool isEmpty() const;
	void clear();//?

private:
	struct Node {
		Node* pNext_{ nullptr };
		int data_{ 0 };

		Node(Node* pNode, const int& element)
			:pNext_(pNode),
			data_(element)
		{

		}
	};
	Node* pHead_{ nullptr };
};

#endif