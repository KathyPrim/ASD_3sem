#include "Calc.h"

int main()
{
    calc* Try = new calc;
    Try->read_expression();
    Try->print_to_console();
    Try->inf_to_pref();
    Try->print_to_console();
    cout << Try->count();
}