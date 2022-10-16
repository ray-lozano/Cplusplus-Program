#include <iostream>
using namespace std;

#include "BankData.h"

//Setters
void BankData::setInvestmentAmount(double amount)
{
	investmentAmount = amount;
}

void BankData::setMonthlyDeposit(double deposit)
{
	monthlyDeposit = deposit;
}

void BankData::setAnnualInterest(double interest)
{
	annualInterest = interest;
}

void BankData::setNumberOfYears(unsigned int years)
{
	numberOfYears = years;
}

//Getters
double BankData::getInvestmentAmount() const
{
	return investmentAmount;
}

double BankData::getMonthlyDeposit() const
{
	return monthlyDeposit;
}

double BankData::getAnnualInterest() const
{
	return annualInterest;
}

unsigned int BankData::getNumberOfYears() const
{
	return numberOfYears;
}