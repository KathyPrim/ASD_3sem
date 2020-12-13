#include "Stack.h"

Stack::Stack()
{
	reset_stack();
};

Stack::~Stack()
{
	if (tail) {
		while (tail->prev) {
			pop_back();
		}
		reset_stack();
	}
};

void Stack::reset_stack()
{
	tail = nullptr;
	stack_size = 0;
}

void Stack::stack_add_first(double newElem)
{
	tail = new SNode(newElem);
}

void Stack::push_back(double newElem)
{
	if (stack_size == 0) {
		stack_add_first(newElem);
	}
	else {
		SNode* tmp = new SNode(newElem);
		tmp->prev = tail;
		tail = tmp;
	}
	stack_size++;
}

void Stack::pop_back()
{
	if (stack_size == 1) {
		delete tail;
		reset_stack();
	}
	else {
		SNode* current = tail->prev;
		delete tail;
		tail = current;
		stack_size--;
	}
}

bool Stack::isEmpty()
{
	return (stack_size == 0);
}

double Stack::return_last()
{
	return tail->data;
}
