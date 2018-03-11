#include <iostream>

#include "Menu.h"

using namespace std;

int main(void)
{
	//Instance of Menu class passing the parameters for positioning the console window
	Menu* mnptr = new Menu(300,500);

	//Print menu
	mnptr->showMenu();

	//Delete Menu instance
	delete mnptr;

	//Exit program
	return 0;
}

