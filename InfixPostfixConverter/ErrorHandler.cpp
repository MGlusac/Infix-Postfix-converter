#include "ErrorHandler.h"
#include <iostream>


ErrorHandler::~ErrorHandler()
{
}

ErrorHandler::ErrorHandler()
{
}

void ErrorHandler::showError(string data)
{
	system("CLS");
	cout << data << endl;
	system("pause");
}
