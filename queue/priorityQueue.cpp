#include "priorityQueue.h"
#include <cstddef>

PriorityQueue::~PriorityQueue()
{
	bool emptiness = isEmpty();
	while (emptiness == true) {
		pop();
	}
}

void PriorityQueue::push(const int & element)
{
	bool emptiness = isEmpty();
	if (emptiness == true) {
		pHead_ = new Node(nullptr, element);
		pTail_ = pHead_;
	}
	else {
		pTail_->pNext_ = new Node(nullptr, element);//pTail.pNext = new
		pTail_ = pTail_->pNext_;
	}
}

void PriorityQueue::pop()
{
	bool emptiness = isEmpty();
	if (emptiness == false) {
		Node* pDell(pHead_);
		pHead_ = pHead_->pNext_;
		delete pDell;
	}
}

int & PriorityQueue::top()
{
	return pHead_->data_;
}

const int & PriorityQueue::top() const
{
	return pHead_->data_;
}

bool PriorityQueue::isEmpty() const
{
	return nullptr == pHead_;
}



