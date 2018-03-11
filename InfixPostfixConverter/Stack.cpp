#include <cstdlib>
#include <iostream>

#include "Stack.h"


using namespace std;

//Stack desctructor deleting the stack instance
Stack::~Stack()
{
	while (top)
	{
		NODE* tmp = top;
		top = top->next;
		delete tmp;
	}
}

//No argument constructor
Stack::Stack()
{
	top = NULL;
}

//Deleting the last element from the list
char Stack::pop()
{
	NODE* tmp = top;
	char val = top->data;
	top = top->next;
	delete tmp;
	return val;
}

//Returning the last element from the list
char Stack::last()
{
	return top->data;
}

//Adding an element at the end of the list
void Stack::push(char element)
{
	NODE* ptr = new NODE;
	ptr->next = top;
	ptr->data = element;
	top = ptr;
}

//Checking if stack is empty
bool Stack::isEmpty()
{
	return top == nullptr;
}
