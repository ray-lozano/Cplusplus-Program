#include <iostream>
using namespace std;

#include "BankMenu.h"
#include "BankData.h"
#include "BalanceTable.h"

//Show the initial Data input menu
void BankMenu::displayMenu()
{
	double amount;
	double deposit;
	double interest;
	unsigned int years;
	BankData data;
	BalanceTable table;

	//Create the very top border
	for (int i = 0; i < 34; ++i)
	{
		cout << '*';
		if (i == 33) cout << endl;
	}

	//Create the Data input header
	for (int i = 0; i < 10; ++i)
	{
		cout << '*';
	}

	cout << " Data Input ";

	for (int i = 0; i < 12; ++i)
	{
		cout << '*';
	}

	//Display the input requirements
	cout << endl << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit Amount: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;
	system("PAUSE");

	//Get data from the user
	//Create the very top border
	for (int i = 0; i < 34; ++i)
	{
		cout << '*';
		if (i == 33) cout << endl;
	}

	//Create the Data input header
	for (int i = 0; i < 10; ++i)
	{
		cout << '*';
	}

	cout << " Data Input ";

	for (int i = 0; i < 12; ++i)
	{
		cout << '*';
	}

	//Display the input requirements
	cout << endl << "Initial Investment Amount: $";
	cin >> amount;
	data.setInvestmentAmount(amount);

	cout << "Monthly Deposit Amount: $";
	cin >> deposit;
	data.setMonthlyDeposit(deposit);

	cout << "Annual Interest: %";
	cin >> interest;
	data.setAnnualInterest(interest);

	cout << "Number of Years: ";
	cin >> years;
	data.setNumberOfYears(years);	

	system("PAUSE");

	table.calculateBalanceWithoutMonthlyDeposit(data.getInvestmentAmount(), data.getAnnualInterest(), data.getNumberOfYears());
	table.calculateBalanceWithMonthlyDeposit(data.getInvestmentAmount(), data.getAnnualInterest(), data.getMonthlyDeposit(), data.getNumberOfYears());
	
}