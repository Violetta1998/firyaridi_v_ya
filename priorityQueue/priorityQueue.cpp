#include "priorityQueue.h"
#include <cstddef>
#include <stdexcept>

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
		if (pHead_->data_ < element) {
			Node* pCc = pHead_->pNext_;
			pHead_ = new Node(pHead_->pNext_, element);
		}
		else {
			Node* pCycle = pHead_;
			while (pCycle->pNext_ != nullptr && pCycle->pNext_->data_ >= element) {
				pCycle = pCycle->pNext_;
			}
			Node* pCc = pCycle->pNext_;
			pCycle->pNext_ = new Node(pCc, element);
		}
		
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
	if (isEmpty()) { throw(("")); }
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

void PriorityQueue::clear()
{
	while (!isEmpty()) {
		pop();
	}
	pHead_ = nullptr;
	pTail_ = nullptr;
}



