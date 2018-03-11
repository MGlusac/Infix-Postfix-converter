#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <sstream>

#include "Menu.h"
#include "Expression.h"
#include "ErrorHandler.h"

using namespace std;

//Initialize pointers of the classes that are going to be used in this one
Expression* exPtr;
ErrorHandler* errPtr;

//Constuctor accepting no parameters
Menu::Menu()
{
	//Set the position of the console window
	setConsoleAttributes(300, 500);
}

//Constructor accepting x and y position of the console window parameters and font size
Menu::Menu(int x, int y)
{
	//Setting the position of the console widnow
	setConsoleAttributes(x, y);
}

//Menu desctructor 
Menu::~Menu()
{
	//Clear console print the message, stop thread for 2 seconds
	system("cls");
	cout << endl << "Closing program..." << endl;
	Sleep(2000);
}

//Printing the menu layout
void Menu::printMenu()
{
	//Clear the console window and change the color of it
	system("CLS");
	system("Color 37");

	//Print out the menu title and the options to the screen
	cout << endl << "            Menu" << endl << endl << endl;
	cout << "1> Convert Infix to Postfix" << endl << endl;
	cout << "2> Exit" << endl << endl;
}

//Getting the user input for the displayed options int he menu
int Menu::getInput()
{
	//Local variables of integer and string type
	int choice;	string buffer;

	//If it is an input of invalid type
	ws(cin);
	if (!getline(cin, buffer).eof())
	{
		//Convert to istream and store choice value
		istringstream i(buffer);
		i >> choice;

		//If it's not an invalid choice return it
		if (!i.fail())
			return choice;
	}

	return 3;
}

//Centering the console window on the screen
void Menu::setConsoleAttributes(int x, int y)
{
	//Set the fixed position of the console menu
	auto consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, nullptr, 500, 300, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	
}


//Prints the Menu with all the functionalities included
void Menu::showMenu()
{
	//Local variables to store the input
	string input; int choice;

	//Do this process while input is not equal to 2
	do
	{
		//Print menu options and store user input
		printMenu();
		choice = getInput();

		//Switch stored input
		switch (choice)
		{
			//If user input was equal to 1
		case 1:
			//Instance of Expression class
			exPtr = new Expression();

			//Clear screen, print message to user and store input
			system("CLS");
			cout << endl << "Enter infix expresion: ";
			cin >> input;
			cout << endl;

			//Passing the infix value to ConvertToPostfix method
			exPtr->convertToPostifx(exPtr->getInfix(&input));

			//Print infix, postfix to console, pause the screen so user can read
			exPtr->showInfix();
			exPtr->showPostfix();
			system("pause");

			//Delete instance
			delete exPtr;

			break;

			//If user input was equal to 2 return  0
		case 2:			
			break;

			//If user input was none of the cases
		default:

			//Instance of ErrorHandler class
			errPtr = new ErrorHandler();

			//Print the error message to the console screen
			errPtr->showError("Invalid input, please select option 1 or 2, and press enter.");

			//Delete instance
			delete errPtr;

			break;
		}
	}
	//While choice is not equal to 2
	while (choice != 2);
}



