#ifndef _BANK_ACCOUNT_H
#define _BANK_ACCOUNT_H
#include<string>
#include<iostream>
#include<iomanip>
#include<vector>
#include"SavingSubAccount.h"
#include"CheckingSubAccount.h"


using namespace std;

class BankAccount :protected SavingSubAccount, protected CheckingSubAccount
{
protected:
	string accNumber;
	string custFirstName;
	string custLastName;
	string SSN;

	int numChkSubAccounts;
	vector<SavingSubAccount> savingSubAccounts;
	vector<CheckingSubAccount> checkingSubAccounts;
	CheckingSubAccount checkingObj;
	SavingSubAccount savingObj;

public:
	static int AccountNumberStart;
	static int totalBankAccounts;
	
	BankAccount()
	{

	}

	int getNumSavingAccounts();
	int getNumCheckingAccounts();

	BankAccount(string, string, string);
	void OpenSavingSubAccount();
	void OpenCheckingSubAccount();
	/*void ModifySubAccount();
	void CloseSubAccount();*/
	void PrintInfo();
	void PrintBriefInfo();
	void displayEligibleServices();
	void PrintCheckingAccntsInfo();
	void PrintSavingAccntsInfo();
	void setAccNumber(string);
	string getAccNumber();
	void setCustFirstName(string);
	string getCustFirstName();
	void setCustLastName(string);
	string getCustLastName();
	void setSSN(string);
	string getSSN();
	double getAggBalance();

	virtual double getBalance() { return 0; }
};

#endif
