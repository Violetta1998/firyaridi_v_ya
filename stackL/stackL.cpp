#include "stackL.h"

StackL::StackL(const StackL & obj)
{
}

void StackL::push(const int & element)
{
	pHead_ = new Node(pHead_,element);
}

void StackL::pop()
{
	bool emptiness = isEmpty();
	if (emptiness ==false) {
		Node* pDell(pHead_);//сохраняем адрес верхнего элемента
		pHead_ = pHead_->pNext_;//2 элемент становится 1м
		delete pDell;
	}
}

int& StackL::top()
{
	return pHead_->data_;
}

const int & StackL::top() const
{
	return pHead_->data_;
}

bool StackL::isEmpty() const
{
	return nullptr == pHead_;
}

void StackL::clear()
{
	bool emptiness = isEmpty();
	while (emptiness != true) {
	  
	}
}
