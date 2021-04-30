#ifndef _SAVING_SUB_ACCOUNT_H
#define _SAVING_SUB_ACCOUNT_H
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

class SavingSubAccount
{
private:
	string savingSubAccNum;
	int bonus = 100;

protected:
	double savingBalance;

public:
	static int savAccountNumStart;

	SavingSubAccount() {}
	SavingSubAccount(double amnt);

	void Deposit();
	void Withdraw();
	void savingSubAccMenu();
	string getSavingSubAccNum();
	void setSavingBalance(double);
	double getSavingBalance();
	double getBonus();
	void printSavingAccInfo();
};

#endif