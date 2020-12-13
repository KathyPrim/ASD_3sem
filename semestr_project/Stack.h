#pragma once
class Stack
{
private:
	void stack_add_first(double newElem);
	void reset_stack();

	class SNode
	{
	public:
		SNode(double data, SNode* prev = nullptr) {
			this->data = data;
			this->prev = prev;
		};
		~SNode() {};

		double data;
		SNode* prev;
	};

	SNode* tail;
	size_t stack_size;

public:

	Stack();

	~Stack();

	void push_back(double newElem);
	void pop_back();
	bool isEmpty();
	double return_last();
};