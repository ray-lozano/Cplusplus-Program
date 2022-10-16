#include <iostream>
#include <iomanip>
using namespace std;

#include "BalanceTable.h"
#include "BankData.h"

/**
* Prints the calculated results of each years investment details in 3 separate fields
* @param year year number
* @param yearEndBalance the current dollar value of the investment
* @param interestEarned dollar amount of how much earned in that year
*/
void BalanceTable::printDetails(unsigned int year, double yearEndBalance, double interestEarned)
{
	cout << year;
	cout << "\t\t$" << right << setw(10) << fixed << setprecision(2) << yearEndBalance;
	cout << "\t\t$" << right << setw(10) << fixed << setprecision(2) << interestEarned << endl;
	//cout << year << "\t\t" << "$" << fixed << setprecision(2) << yearEndBalance << "\t\t\t$" << interestEarned << endl;
}

//Calculate the year end balance without monthly deposits
double BalanceTable::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, unsigned int numberOfYears)
{
	//Declare yearEndBalance and assign it initialInvestment
	double yearEndBalance = initialInvestment;
	double interestEarned = 0;

	//Create the Balance Table
	cout << "    Balance and Interest without Additional Monthly Deposits" << endl;
	for (int i = 0; i < 63; ++i)
	{
		cout << '=';
		if (i == 62) cout << endl;
	}
	cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
	for (int i = 0; i < 63; ++i)
	{
		cout << '-';
		if (i == 62) cout << endl;
	}

	//Calculate the interest earned and the year end balance
	for (unsigned int i = 1; i <= numberOfYears; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			interestEarned = yearEndBalance * ((interestRate / 100) / 12);
			yearEndBalance += interestEarned;
		}

		//Outputs the year end balance and interest earned for each year
		printDetails(i, yearEndBalance, interestEarned);
	}
	return yearEndBalance;
}

//Calculate the year end balance with monthly deposits
double BalanceTable::calculateBalanceWithMonthlyDeposit(double initialInvestment, double interestRate, double monthlyDeposit, unsigned int numberOfYears)
{
	double yearEndBalance = initialInvestment;
	double interestEarned = 0;

	//Create the Balance Table
	cout << "    Balance and Interest with Additional Monthly Deposits" << endl;
	for (int i = 0; i < 63; ++i)
	{
		cout << '=';
		if (i == 62) cout << endl;
	}
	cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
	for (int i = 0; i < 63; ++i)
	{
		cout << '-';
		if (i == 62) cout << endl;
	}

	//Calculate the interest earend and year end balance
	for (unsigned int i = 1; i <= numberOfYears; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			yearEndBalance += monthlyDeposit;
			interestEarned = yearEndBalance * ((interestRate / 100) / 12);
			yearEndBalance += interestEarned;
		}

		//Outputs the year end balance and interest earned for each year
		printDetails(i, yearEndBalance, interestEarned);
	}
	return yearEndBalance;
}

