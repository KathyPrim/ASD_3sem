#include "Calc.h"

void Calc::inner_brackets(){ // самые левые внутренние скобки
	int i = 0;
	for (i; i < input_data.length(); i++) {
		if (input_data[i] == ')') {
			closed_bracket = i;
			break;
		}
	}
	for (i; i > 0; i--) { // находим открытую для закрытой
		if (input_data[i] == ' ') {
			space_amount++;
			continue;
		}
		if (input_data[i] == '(') {
			opened_bracket = i;
			break;
		}
	}
	if ((opened_bracket == -1) && (closed_bracket == -1)) { // если скобок нет
		opened_bracket = 0;
		closed_bracket = input_data.length() - 1;
	}
}

void Calc::count(){
	
}
