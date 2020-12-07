#pragma once
#include"Stack.h"
#include <string>
#include <iostream>
#include<cmath>

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
			bracket,
			pi, eps,
		};

		enum class Priopity {
			operands = 10,
			brackets = 0,
			plus = 1, minus = 1,
			multiply = 2, divide = 2,
			raise = 2,
		};

		Node(string data, Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->res = 0;
			this->next = next;
			this->prev = prev;
			this->expression = static_cast<Node::Type>(0);
			this->order = static_cast<Node::Priopity>(-1);
		};
		~Node() {};

		string data;
		double res;
		Node* next;
		Node* prev;
		Type expression;
		Priopity order;
	};

	Node* inf_head;
	Node* inf_tail;
	size_t size;

public:

	calc();
	~calc();

	void read_expression();
	void check_type(string str);
	void push_back(string newElem);
	void push_front(string newElem);
	void pop_back();
	void pop_front();
	void insert(string newElem, int index);
	string at(size_t index) const;
	void remove(int index);
	size_t get_size() const;
	void print_to_console();
	void clear();
	void set(int index, string newElem);
	bool isEmpty();
	void insert(calc newList, int index);
};
