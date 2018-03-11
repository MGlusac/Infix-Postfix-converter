#ifndef Symbol_H
#define Sybmol_H
class Symbol
{
public:
	Symbol();
	~Symbol();
	bool isOperand(char c);
	bool precendence(char opr1, char opr2);
	bool isOperator(char data);	
};
#endif
