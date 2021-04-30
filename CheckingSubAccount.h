#ifndef _CHECKING_SUB_ACCOUNT_H
#define _CHECKING_SUB_ACCOUNT_H
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

class CheckingSubAccount
{
private:
	double maxCapacity;
	bool isLocked;
	double checkingBalance;

protected:
	/*string checkingSubAccNum;*/

public:
	static int chkAccountNumStart;
	CheckingSubAccount() {}
	CheckingSubAccount(double, double, bool);
	void Deposit(double amnt);
	void Withdraw(double amnt);
	void setMaxCapacity(double mAmt);
	double getMaxCapacity();
	void LockSubAccount();
	void UnlockSubAccount();
	string getCheckingSubAccNum();
	double getCheckingBalance();
	void setCheckingBalance(double b);
	double getBalance();
	void printCheckingAccInfo();
	void checkingSubAccMenu();
};
#endif