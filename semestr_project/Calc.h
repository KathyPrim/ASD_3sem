#pragma once
#include <string>
#include <iostream>
using namespace std;

class calc
{
private:
	void add_first(string newElem);
	void reset_list();

	class Node
	{
	public:
		enum class Type {
			undef = 0,
			plus = 1, //+
			minus, //-
			multiply, //*
			divide, // /
			raise, //^
			sin, // sin()
			cos, // cos()
			tg, // tg()
			ctg, // ctg()
			ln, // ln()
			lg, // decimal logarythm, lg()
			sqrt, // sqrt()
			cuber, // qube root, quber()
			int_number, // 123
			double_number, // 123.456
		};

		Node(string data, Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
			//this->expression = undef;
		};
		~Node() {};

		string data;
		Node* next;
		Node* prev;
		Type expression;
	};

	Node* head;
	Node* tail;
	size_t size;
	int brackets;

public:

	calc();
	~calc();

	void read_expression();
	void check_type();
	void push_back(string newElem);
	void push_front(string newElem);
	void pop_back();
	void pop_front();
	void insert(string newElem, int index);
	string at(size_t index) const;
	void remove(int index);
	size_t get_size() const;
	//void print_to_console();
	void clear();
	void set(int index, string newElem);
	bool isEmpty();
	void insert(calc newList, int index);
};
