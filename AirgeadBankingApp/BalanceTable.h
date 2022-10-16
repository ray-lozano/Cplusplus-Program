#pragma once
#ifndef BANKTABLE_H
#define BANKTABLE_H

class BalanceTable
{
	public:		
		void printDetails(unsigned int year, double yearEndBalance, double interestEarned);
		double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, unsigned int numberOfYears);
		double calculateBalanceWithMonthlyDeposit(double initialInvestment, double interestRate, double monthlyDeposit, unsigned int numberOfYears);
		
};

#endif