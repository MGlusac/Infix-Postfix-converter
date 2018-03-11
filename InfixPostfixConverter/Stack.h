#ifndef Stack_H
#define Stack_H

using namespace std;

class Stack
{
	typedef struct node
	{
		node* next;
		int data;
	} NODE;

	NODE* top;

public:
	Stack();
	~Stack();
	void push(char element);
	char last();
	char pop();
	bool isEmpty();	
};
#endif

