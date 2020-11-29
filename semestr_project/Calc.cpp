#include "Calc.h"

void calc::reset_list()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

calc::calc()
{
	reset_list();
}

calc::~calc() {
	if (head) {
		while (head->next) {
			head = head->next;
			delete head->prev;
		}
		reset_list();
	}
}

void calc::add_first(string newElem)
{
	head = new Node(newElem);
	tail = head;
}

void calc::push_back(string newElem) // add in the end
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		Node* tmp = new Node(newElem);
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
	size++;
}

void calc::read_expression() { // read formula
	bool cont = true;
	string added;

	if (!head) {
		cin >> added;
		size = 1;
		add_first(added);
		if (added[added.length() - 1] == '/n') {
			cont = false;
		}
	}

	while (cont) {
		cin >> added;
		push_back(added);
		size++;
		if (added[added.length() - 1] == '/n') {
			cont = false;
		}
	}
}

void calc::check_type(){
	string str = tail->data;
	bool type[15] = { false };
	if (str.length() == 1) { // it should be only a sign
		if (str == "+") tail->expression = static_cast<Node::Type>(1);
		if (str == "-") tail->expression = static_cast<Node::Type>(2);
		if (str == "*") tail->expression = static_cast<Node::Type>(3);
		if (str == "/") tail->expression = static_cast<Node::Type>(4);
		if (str == "^") tail->expression = static_cast<Node::Type>(5);
	}
	else if ((str[0] == 's') && (str[1] == 'i') && (str[2] == 'n')) tail->expression = static_cast<Node::Type>(6);
	else if ((str[0] == 'c') && (str[1] == 'o') && (str[2] == 's')) tail->expression = static_cast<Node::Type>(7);
	else if ((str[0] == 't') && (str[1] == 'g')) tail->expression = static_cast<Node::Type>(8);
	else if ((str[0] == 'c') && (str[1] == 't') && (str[2] == 'g')) tail->expression = static_cast<Node::Type>(9);
	else if ((str[0] == 'l') && (str[1] == 'n')) tail->expression = static_cast<Node::Type>(10);
	else if ((str[0] == 'l') && (str[1] == 'g')) tail->expression = static_cast<Node::Type>(11);
	else if ((str[0] == 's') && (str[1] == 'q') && (str[2] == 'r') && (str[3] == 't')) tail->expression = static_cast<Node::Type>(12);
	else if ((str[0] == 'c') && (str[1] == 'u') && (str[2] == 'b') && (str[3] == 'e') && (str[4] == 'r')) tail->expression = static_cast<Node::Type>(13);
}

void calc::push_front(string newElem) // add in the beginning
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		Node* tmp = new Node(newElem, head);
		head->prev = tmp;
		head = tmp;
	}
	size++;
}

void calc::pop_back() // delete last
{
	if (size == 0) {
		throw out_of_range("Nothing to delete");
	}
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* current = tail->prev;
		current->next = nullptr;
		delete tail;
		tail = current;
		size--;
	}
}

void calc::pop_front() // delete first
{
	if (size == 0) {
		throw out_of_range("Nothing to delete");
	}
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		head = head->next;
		delete head->prev;
		size--;
	}
}

void calc::insert(string newElem, int index) // add #index
{
	if (index > size - 1) {
		throw out_of_range("Index is greater than list size");
	}
	if (index < 0) {
		throw out_of_range("Index is less than zero");
	}
	if (index == 0) { // newElem - new head
		push_front(newElem);
	}
	else if (index == size - 1) { // newElem - new tail
		push_back(newElem);
	}
	else {
		Node* add = new Node(newElem);
		Node* tmp = head;
		for (int i = 1; i < index - 1; i++) {
			tmp = tmp->next;
		} // tmp - before adding
		add->prev = tmp;
		add->next = tmp->next;
		tmp->next = add;
		size++;
	}
}

string calc::at(size_t index) const // find data from #index
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	if (index < 0) {
		throw out_of_range("Index is less than zero");
	}
	size_t counter = 0;
	Node* current = head;
	while (counter != index) {
		current = current->next;
		counter++;
	}
	return current->data;
}

void calc::remove(int index)
{
	Node* tmp = head;
	if (index > size - 1) {
		throw out_of_range("Index is greater than list size");
	}
	if (index < 0) {
		throw out_of_range("Index is less than zero");
	}
	if (index == 0) { // delete head
		pop_front();
	}
	else if (index == size - 1) { // delete tail
		pop_back();
	}
	else {
		for (int i = 0; i < index; i++) {
			tmp = tmp->next;
		} // tmp should be deleted
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		delete tmp;
		size--;
	}
}

size_t calc::get_size() const
{
	return size;
}

//void calc::print_to_console()
//{
//	cout << "Size is " << size << endl;
//	if (size != 0) {
//		Node* tmp = head;
//		do {
//			cout << tmp->data << endl;
//			tmp = tmp->next;
//		} while (tmp->next);
//		cout << tmp->data << endl;
//		cout << "....." << endl;
//	}
//	else cout << "nothing to print" << endl;
//}

void calc::clear()
{
	if (head) {
		while (head->next) {
			head = head->next;
			delete head->prev;
		}
		reset_list();
	}
}

void calc::set(int index, string newElem)
{
	if (index > size - 1) {
		throw out_of_range("Index is greater than list size");
	}
	if (index < 0) {
		throw out_of_range("Index is less than zero");
	}
	else {
		Node* tmp = head;
		for (int i = 0; i < index; i++) {
			tmp = tmp->next;
		}
		tmp->data = newElem;
	}
}

bool calc::isEmpty()
{
	return (head == nullptr);
}

void calc::insert(calc newList, int index)
{
	if (index > size - 1) {
		throw out_of_range("Index is greater than list size");
	}
	if (index < 0) {
		throw out_of_range("Index is less than zero");
	}
	if (index == 0) {
		newList.tail->next = head;
		head->prev = newList.tail;
		head = newList.head;
		size = size + newList.get_size();
	}
	else if (index == size - 1) {
		tail->next = newList.head;
		newList.head->prev = tail;
		tail = newList.tail;
		size = size + newList.get_size();
	}
	else {
		Node* tmp = head;
		int counter = index;
		while (counter)
		{
			tmp = tmp->next;
			counter--;
		} // add after tmp
		newList.tail->next = tmp->next;
		tmp->next->prev = newList.tail;
		tmp->next = newList.head;
		newList.head->prev = head;
		size = size + newList.get_size();
	}
}