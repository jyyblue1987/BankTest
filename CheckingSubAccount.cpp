#include "CheckingSubAccount.h"

int CheckingSubAccount::chkAccountNumStart = 5999;

CheckingSubAccount::CheckingSubAccount(double bal, double maxc, bool isL)
{
	chkAccountNumStart++;

	checkingBalance = bal;
	maxCapacity = maxc;
	if (isL)LockSubAccount();
	else
		UnlockSubAccount();
	//checkingSubAccNum = "CHK" + to_string(chkAccountNumStart);
	cout << setw(5) << " " << "| A new Checking Sub-Account " << "CHK" + to_string(chkAccountNumStart) << " was sucessfully created." << endl;

}

void CheckingSubAccount::Deposit(double amnt)
{
	checkingBalance += amnt;
}

void CheckingSubAccount::Withdraw(double amnt)
{
	checkingBalance -= amnt;
}

void CheckingSubAccount::setMaxCapacity(double mAmt)
{
	maxCapacity = mAmt;
}

double CheckingSubAccount::getMaxCapacity()
{
	return maxCapacity;
}

void CheckingSubAccount::LockSubAccount()
{
	isLocked = true;
}

void CheckingSubAccount::UnlockSubAccount()
{
	isLocked = false;
}

string CheckingSubAccount::getCheckingSubAccNum()
{
	return "CHK" + to_string(chkAccountNumStart);
}

double CheckingSubAccount::getCheckingBalance()
{
	return checkingBalance;

}

void CheckingSubAccount::setCheckingBalance(double b)
{
	checkingBalance = b;
}

double CheckingSubAccount::getBalance()
{
	return checkingBalance;
}

void CheckingSubAccount::printCheckingAccInfo()
{
	cout << endl;

	cout << setw(5) << " " << "| Sub-Account number: " << "CHK" + to_string(chkAccountNumStart) << endl;
	cout << setw(5) << " " << "| Balance: " << getCheckingBalance() << endl << endl << endl;
	cout << setw(5) << " " << "| The maximum capacity is: " << getMaxCapacity() << endl;
	if (isLocked)
		cout << setw(5) << " " << "| The sub-account is locked." << endl;
	else
		cout << setw(5) << " " << "| The sub-account is not locked." << endl;
}

void CheckingSubAccount::checkingSubAccMenu()
{
	char choice;
	do
	{
		cout << "Eligible services for sub-account " << "CHK" + to_string(chkAccountNumStart) << endl;
		cout << setw(10) << " " << "D -- Deposit" << endl;
		cout << setw(10) << " " << "W -- Withdraw" << endl;
		cout << setw(10) << " " << "C -- Max capacity" << endl;
		cout << setw(10) << " " << "L -- Lock Sub-Account" << endl;
		cout << setw(10) << " " << "U -- Unlock Sub-Account" << endl;
		cout << setw(10) << " " << "X -- Exit" << endl;
		cout << "Please enter your selection: ";
		cin >> choice;
		double amnt;
		switch (toupper(choice))
		{
		case 'D':
			cout << setw(5) << " " << "| Enter the amount to deposit: ";
			cin >> amnt;
			if (isLocked)
			{
				cout << setw(5) << " " << "| The account is currently locked!" << endl;
				cout << setw(5) << " " << "| The deposit was unsuccessful." << endl;
			}
			else if (getCheckingBalance() + amnt > maxCapacity)
			{
				cout << setw(5) << " " << "| The account maximum capacity reached!" << endl;
				cout << setw(5) << " " << "| The deposit was unsuccessful. " << endl;
			}
			else
			{
				Deposit(amnt);
				cout << setw(5) << " " << "| Deposit was successful." << endl;
				cout << setw(5) << " " << "| The current balance is: " << getCheckingBalance() << endl;
				cout << endl;
			}
			break;
		case 'W':
			cout << setw(5) << " " << "| Enter the amount to withdraw: ";
			cin >> amnt;
			cout << endl;
			if (isLocked)
			{
				cout << setw(5) << " " << "| The account is currently locked!" << endl;
				cout << setw(5) << " " << "| The withdrawal was unsuccessful." << endl;
			}
			else
			{
				Withdraw(amnt);
				cout << setw(5) << " " << "| Withdraw was successful." << endl;
				cout << setw(5) << " " << "| The current balance is: " << getCheckingBalance() << endl;
				cout << endl;
			}
			break;
		case 'C':
			cout << setw(5) << " " << "| Enter the max capacity: ";
			cin >> amnt;
			cout << endl;
			if (isLocked)
			{
				cout << setw(5) << " " << "| The account is currently locked!" << endl;
				cout << setw(5) << " " << "| Max-Capacity cant be updated." << endl;
			}
			else
				setMaxCapacity(amnt);
			break;
		case 'L':
			isLocked = true;
			cout << setw(5) << " " << "| The sub-account " << "CHK" + to_string(chkAccountNumStart) << " " << " is locked now!" << endl;
			break;
		case 'U':
			isLocked = false;
			cout << setw(5) << " " << "| The sub-account " << "CHK" + to_string(chkAccountNumStart) << " " << " is unlocked now!" << endl;
			break;
		case 'X':
			cout << setw(5) << " " << "| End of service for sub-account " << "CHK" + to_string(chkAccountNumStart) << endl;
			break;
		}

	} while (toupper(choice) != 'X');
}