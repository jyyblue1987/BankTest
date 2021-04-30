#include "SavingSubAccount.h"

int SavingSubAccount::savAccountNumStart = 999;

SavingSubAccount::SavingSubAccount(double amnt)
{
	savAccountNumStart++;
	savingSubAccNum = "SAV" + to_string(savAccountNumStart);
	savingBalance = amnt;
	savingBalance += getBonus();
	cout << setw(5) << " " << "| A new Saving Sub-Account " << "SAV" + to_string(savAccountNumStart) << " was sucessfully created." << endl;
}

void SavingSubAccount::Deposit()
{

	cout << setw(5) << " " << "Enter the amount to deposit: ";
	double deposit;
	cin >> deposit;
	cout << endl;
	savingBalance += deposit;
	cout << setw(5) << " " << "| Deposit was successful." << endl;
	cout << setw(5) << " " << "| The current balance is: " << getSavingBalance() << endl;
	cout << endl;
}

void SavingSubAccount::Withdraw()
{
	cout << setw(5) << " " << "Enter the amount to withdraw: ";
	double wdAmnt;
	cin >> wdAmnt;
	cout << endl;
	savingBalance -= wdAmnt;
	cout << setw(5) << " " << "| Withdraw was successful." << endl;
	cout << setw(5) << " " << " The current balance is: " << getSavingBalance() << endl;
	cout << endl;
}

void SavingSubAccount::savingSubAccMenu()
{
	char choice;
	do
	{
		cout << "Eligible services of sub-Account " << "SAV" + to_string(savAccountNumStart) << endl;
		cout << setw(10) << " " << "D -- Deposit" << endl;
		cout << setw(10) << " " << "W -- Withdraw" << endl;
		cout << setw(10) << " " << "X --  Exit" << endl;
		cout << "Please enter your selection: ";
		cin >> choice;
		switch (toupper(choice))
		{
		case 'D':
			Deposit();
			break;
		case 'W':
			Withdraw();
			break;
		case 'X':
			cout << setw(5) << " " << "| End of service for sub-account " << "SAV" + to_string(savAccountNumStart) << endl;
			break;
		}
	} while (toupper(choice) != 'X');
}

string SavingSubAccount::getSavingSubAccNum()
{
	return savingSubAccNum;
}

void SavingSubAccount::setSavingBalance(double savBal)
{
	savingBalance = savBal;
}

double SavingSubAccount::getSavingBalance()
{
	return savingBalance;
}

double SavingSubAccount::getBonus()
{
	if (("SAV" + to_string(savAccountNumStart)) == "SAV1000")
		return bonus;
	else
		return 0;
}

void SavingSubAccount::printSavingAccInfo()
{
	cout << setw(5) << " " << "| Sub-Account number: " << savingSubAccNum << endl;
	cout << setw(5) << " " << "| Balance: " << getSavingBalance() << endl;
}