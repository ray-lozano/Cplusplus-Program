#include <iostream>
using namespace std;

#include "BankMenu.h"
#include "BalanceTable.h"

int main()
{
	//BankMenu object and displaying the menu
	BankMenu menu;	
	
	//Loop until the user wants to quit
	char response = 'y';
	while (response != 'n' || response != 'N')
	{
		//Display the menu and run the functions
		menu.displayMenu();

		//Check if the user wants to enter new values or quit
		cout << "Would you like to put in different values? (Y/N) ";
		cin >> response;
		if (response == 'y' || response == 'Y') system("CLS");
		else break;
	}
	
	return 0;
}