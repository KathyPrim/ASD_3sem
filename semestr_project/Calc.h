#pragma once
#include <string>
using namespace std;

class Calc
{
public:
	Calc(string new_data) {
		this->input_data = new_data;
		opened_bracket = -1;
		closed_bracket = -1;
		space_amount = 0;
	};
	~Calc() {};

	void inner_brackets();
	void count();

private:
	string input_data;
	int opened_bracket, closed_bracket, space_amount; // indexes of '(' and ')'
	double result;
};

