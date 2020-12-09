#pragma once
#include <string>
#include <iostream>
#include<cmath>

using namespace std;

double pi = 3.14159265358979323846;
double e = 2.71828182845904523536;

class calc
{
private:
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
			undef = -1,
			operands = 10,
			brackets = 0,
			plus = 1, minus = 1,
			multiply = 2, divide = 2,
			raise = 3,
		};

		Node(string data, double res, Type expression, Priopity order, Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->res = res;
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

	void add_first(string newElem, double res, Node::Priopity order, Node::Type exp);
	void reset_list();

	Node* head;
	Node* tail;

	size_t size;

public:

	calc();
	~calc();

	void read_expression();
	void check_type(string str);
	void push_back(string newElem, double res, Node::Priopity order, Node::Type exp);
	void push_front(string newElem, double res, Node::Priopity order, Node::Type exp);
	void print_to_console();
	void clear();
	void inf_to_pref();
	void pop_back();
	bool isEmpty();
	/*void pop_front();
	void insert(string newElem, int index);
	string at(size_t index) const;
	void remove(int index);
	size_t get_size() const;
	void set(int index, string newElem);
	void insert(calc newList, int index);*/
};
