/*
* Raymond Lozano
* CS-210 Programming Languages 22EW1
* Project One Chada Tech
* Module 3
* Twelve- and Twenty-Four Hour Clocks
*/

#include <iostream>
#include <string>
using namespace std;

class Clock
{
private:
	//Initalizing time variables.
	int second = 0;
	int minute = 0;
	int hour = 0;
	
	

public:
	//Setters
	void setSecond(int s)
	{
		second = s;
	}

	void setMinute(int m)
	{
		minute = m;
	}

	void setHour(int h)
	{
		hour = h;
	}

	//Getters
	int getSecond()
	{
		return second;
	}

	int getMinute()
	{
		return minute;
	}

	int getHour()
	{
		return hour;
	}

	//Formats a number as two digits
	string twoDigitString(unsigned int digit)
	{
		//If digit is less than ten then format the string to show double digit number ex: 1 = 01.
		string twoDigit = (digit < 10) ? "0" + to_string(digit) : to_string(digit);
		return twoDigit;
	}

	//Creates the border for the clock.
	string nCharString(size_t n, char c)
	{
		//Initializing variable
		string border;

		//Formatting and appending within the loop for the string.
		for (size_t i = 0; i < n; ++i)
		{
			border += c;
		}

		return border;
	}


	//Creates the twenty-four hour clock
	string formatTime24(unsigned int h, unsigned int m, unsigned int s)
	{
		string twentyFourClock = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

		// return hh:mm:ss
		return twentyFourClock;
	}

	/**
	 * Formats the time in am/pm format
	 *
	 * @param h, hours 0 to 23
	 * @param m, minutes 0 to 59
	 * @param s, seconds 0 to 59
	 *
	 * @return hh:mm:ss A M or hh:mm:ss P M where hh is between 01 and 12, inclusive
	 */
	string formatTime12(unsigned int h, unsigned int m, unsigned int s)
	{
		string twelveHourClock = " ";
		//If h == 0 then the clock is set to 12 AM.
		if (h == 0)
		{
			h = 12;
			twelveHourClock = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
		}
		//If h == 12 then the clock is set to 12 PM.
		else if (h == 12)
		{
			twelveHourClock = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
		}
		else if (h > 12)
		{
			//Sets the time to the appropriate PM time.
			h -= 12;
			twelveHourClock = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
		}
		else
		{
			twelveHourClock = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
		}

		// return hh:mm:ss A M or hh:mm:ss P M
		return twelveHourClock;
	}
	
	/**
	* Prints menu
	*
	* @param strings[], nonempty array of choices
	* @param width, width of each line, will be comfortably bigger than the longest string
	*
	*/
	void printMenu(string strings[], unsigned int numStrings, unsigned char width) {
		 //Prints the top border of the menu.
		cout << nCharString(width, '*') << endl;

		//Loops through the strings[] array to display the menu choices until all menu options are visible.
		for (unsigned int i = 0; i < numStrings; ++i)
		{
			cout << nCharString(1, '*') << nCharString(1, ' ') << i + 1 << nCharString(1, ' ') << nCharString(1, '-') << nCharString(1, ' ') 
				<< strings[i] << nCharString(width - strings[i].length() - 7, ' ') << nCharString(1, '*') << endl;
			if (i < numStrings - 1)
			{
				cout << endl;
			}
		}
		//Prints the bottom border of the menu.
		cout << nCharString(width, '*') << endl;
	}

	/**
	 * Gets menu choice 1 through maxChoice, inclusive
	 *
	 * @param maxChoice, maximum choice index, a number between 2 and 9, inclusive
	 * @return the first legal choice input, could be 1 through maxChoice, inclusive
	 */
	unsigned int getMenuChoice(unsigned int maxChoice)
	{
		unsigned int choice = 0;

		//Handles the input for the menu choice.
		while (choice < 1 || choice > maxChoice)
		{
			cin >> choice;

			//If a valid menu option is chosen, break out of the while loop.
			if (choice > 0 && choice < maxChoice)
			{
				break;
			}
		}

		// return the value
		return choice;
	}

	/**
	 * Display the clocks
	 *
	 * @param h, hours 0 to 23
	 * @param m, minutes 0 to 59
	 * @param s, seconds 0 to 59
	 */
	void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
		// nCharString(27,'*') gives a string of 27 stars. nCharString(3,' ') gives 3 spaces
		// formatTime12(h, m, s) and formatTime24(h, m, s) give the formatted time as specified in the assignment
		cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
		cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
		cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
		cout << endl;
		cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
		cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;
		cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	}

	
	/**
	 * Adds one second
	 */
	void addOneSecond()
	{
		//If getSecond is between 0 and 58 inclusive, add one second to setSecond.
		//Else if it is 59 then setSecond is set to 0 and one minute is added.
		if (getSecond() <= 58 && getSecond() >= 0)
		{
			setSecond(getSecond() + 1);
		}
		else
		{
			setSecond(0);
			addOneMinute();
		}

		// nothing to return, just call setSecond() with the right value and addOneMinute() when needed
	}

	/**
	 * Adds one minute
	 */
	void addOneMinute()
	{
		//If getMinute is between 0 and 58 inclusive, add one minute. 
		//Else if it is 59, setMinute is set to 0 and one hour is added.
		if (getMinute() <= 58 && getMinute() >= 0)
		{
			setMinute(getMinute() + 1);
		}
		else
		{
			setMinute(0);
			addOneHour();
		}
		// nothing to return, just setMinute to the appropriate value and use addOneHour if needed
	}

	/**
	 * Adds one hour
	 */
	void addOneHour() {
		//If the hour is between 0 and 22 inclusive, add one to setHour, otherwise setHour is set to 0
		if (getHour() >= 0 && getHour() <= 22)
		{
			setHour(getHour() + 1);
		}
		else
		{
			setHour(0);
		}

		// nothing to return, just setHour to the appropriate value
	}
	/**
 * repeats getting the user's choice and taking the appropriate action until the user chooses 4 for exit
 */
	void mainMenu() {
		//Initalize choice variable and string array.
		int choice = 0;
		string strings[4] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };

		//Display the clock and the menu
		displayClocks(getHour(), getMinute(), getSecond());
		printMenu(strings, 4, 27);
		
		//Loop through the menu using getMenuChoice.
		while (choice != 4)
		{
			//getMenuChoice(4) will handle the input and return 1, 2, 3, or 4.	
			choice = getMenuChoice(4);

			//Checks the choice and then clears the screen if choices are from 1-3.
			switch (choice)
			{
			case 1:
				addOneHour();
				system("cls");
				break;
			case 2:
				addOneMinute();
				system("cls");
				break;
			case 3:
				addOneSecond();
				system("cls");
				break;
			case 4:
				break;
			}

			//Breaks from the loop and causes the program to exit without clearing the screen.
			if (choice == 4)	
			{
				break;
			}

			//After clearing the screen, displays the menu and updated clocks again
			displayClocks(getHour(), getMinute(), getSecond());
			printMenu(strings, 4, 27);
		}		

		// nothing to return, just call the appropriate methods
	}
};

int main()
{
	//Creating the clock object and calling the main menu
	Clock clock;	
	clock.mainMenu();
}
