#pragma once
#ifndef BANKDATA_H
#define BANKDATA_H

class BankData
{
	public:
		void setInvestmentAmount(double amount);
		void setMonthlyDeposit(double deposit);
		void setAnnualInterest(double interest);
		void setNumberOfYears(unsigned int years);
		double getInvestmentAmount() const;
		double getMonthlyDeposit() const;
		double getAnnualInterest() const;
		unsigned int getNumberOfYears() const;
	private:
		double investmentAmount = 0;
		double monthlyDeposit = 0;
		double annualInterest = 0;
		unsigned int numberOfYears = 0;
};
#endif