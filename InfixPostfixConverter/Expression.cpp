#include "Expression.h"
#include <iostream>
#include "Stack.h"
#include "Symbol.h"


//No arguments Expression constructor
Expression::Expression()
{
	//Setting infix and postfix pointers to null pointers
	ifxPtr = nullptr;
	pfxPrt = nullptr;
}

//Expression class destructor reseting the pointers
Expression::~Expression()
{
	ifxPtr = nullptr;
	pfxPrt = nullptr;
}


// Gets the infix
string Expression::getInfix(string* data)
{
	ifxPtr = new string(*data);
	return *ifxPtr;
}


// Shows the infix
void Expression::showInfix()
{
	cout << "Infix expression: " << *ifxPtr << endl << endl;
}


// Shows the postfix
void Expression::showPostfix()
{
	cout << "Postfix expression: " << *pfxPrt << endl << endl << endl;
}

//Converts infix expression to postfix
void Expression::convertToPostifx(string data)
{
	Stack* _stack = new Stack();
	Symbol* _symbol = new Symbol();
	string postfix;


	//Scan the expression once from left to right
	for (int i = 0; data.length() > i; i++)
	{
		//If S is an operand		
		if (_symbol->isOperand(data[i]))
		{
			//Append it to the postfix expression
			postfix += data[i];
		}

		//If S is a left bracket
		else if (data[i] == '(')
		{
			//Push it onto the stack
			_stack->push(data[i]);
		}

		//If S is a right bracket
		else if (data[i] == ')')
		{
			//Pop and append all symbols from the stack until the most recent left bracket
			while (!_stack->isEmpty() && _stack->last() != '(')
			{
				postfix += _stack->last();
				_stack->pop();
			}

			//Pop and discard the left bracket				
			_stack->pop();
		}
		//If S is an operator
		else if (_symbol->isOperator(data[i]))
		{
			/*Pop and append to the postfix expression every operator from the stack that is
			above the most recently scanned left bracket and that has precedence greater
			than or equal to the new operator*/

			while (!_stack->isEmpty() && _stack->last() != '(' && _symbol->precendence(_stack->last(), data[i]))
			{
				postfix += _stack->last();
				_stack->pop();
			}
			/*Push the new operator on the stack*/
			_stack->push(data[i]);
		}
	}
	//Pop and append to the postfix string everything from the stack
	while (!_stack->isEmpty())
	{
		postfix += _stack->last();
		_stack->pop();
	}

	//setting the value of pointer pfxPrt
	pfxPrt = new string(postfix);

	//Delete stack and symbol instances
	delete _stack;
	delete _symbol;
}






