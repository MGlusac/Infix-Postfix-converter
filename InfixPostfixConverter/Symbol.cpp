#include "Symbol.h"
#include <cstddef>
#include <ctype.h>

//Constructor
Symbol::Symbol()
{
}

//Destructor
Symbol::~Symbol()
{
}

//Checking which parameter has higher precendence
bool Symbol::precendence(char opr1, char opr2)
{
	//2 local int variables set to null
	int prec1 = NULL;
	int prec2 = NULL;

	//If parameter 1 is equal to * or / set prec1 to 2
	if (opr1 == '*' || opr1 == '/')
		prec1 = 2;
	//If parameter 1 is equal to + or - set prec1 to 1
	else if (opr1 == '+' || opr1 == '-')
		prec1 = 1;
	//If parameter 1 is left bracket set prec1 to 0
	else if (opr1 == '(')
		prec1 = 0;

	//If parameter 2 is equal to * or / set prec2 to 2
	if (opr2 == '*' || opr2 == '/')
		prec2 = 2;
	//If parameter 2 is equal to + or - set prec2 to 1
	else if (opr2 == '+' || opr2 == '-')
		prec2 = 1;
	//If parameter 2 is left bracket set prec2 to 0
	else if (opr2 == '(')
		prec2 = 0;

	//return true if prec1 > prec 2 esle return false
	return prec1 >= prec2;
}

//Checking if passed parameter is an operator
bool Symbol::isOperator(char data)
{
	//Return true if data is equal to any of the symbols bellow, else return false
	return (data == '+' || data == '-' || data == '*' || data == '/');
}

//Checking if passed parameter is an operand
bool Symbol::isOperand(char c)
{
	//Return true if c => 0 && c<= 9 or is a letter, else return false
	return c >= '0' && c <= '9' || isalpha(c);
}





