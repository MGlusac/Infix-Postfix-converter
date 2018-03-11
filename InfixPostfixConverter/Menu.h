#ifndef Menu_H
#define Menu_H
class Menu
{	
	void setConsoleAttributes(int x, int y);
	int getInput();
	void printMenu();

public:
	void showMenu();
	Menu(int x, int y);
	Menu();
	~Menu();
};
#endif
