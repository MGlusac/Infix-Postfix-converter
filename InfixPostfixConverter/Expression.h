#ifndef Expression_H
#define Expression_H

#include <string>

using namespace std;

class Expression
{
	string* ifxPtr;
	string* pfxPrt;
public:
	Expression();	
	~Expression();
	string getInfix(string* data);
	void showInfix();
	void showPostfix();
	void convertToPostifx(string data);
};
#endif