#include "BankAccount.h"
#include"SavingSubAccount.h"
#include"CheckingSubAccount.h"

int BankAccount::AccountNumberStart = 9999;

int BankAccount::getNumSavingAccounts()
{
	return savingSubAccounts.size();
}

int BankAccount::getNumCheckingAccounts()
{
	return checkingSubAccounts.size();
}

BankAccount::BankAccount(string fn, string ln, string ssn)
{
	AccountNumberStart++;
	custFirstName = fn;
	custLastName = ln;
	SSN = ssn;
	accNumber = "BNK" + to_string(AccountNumberStart);
}


void BankAccount::OpenSavingSubAccount()
{
	double initBal;
	cout << setw(5) << " " << "Enter the initial balance: ";
	cin >> initBal;

	SavingSubAccount newSavingAccnt(initBal);
	if (savingSubAccounts.size() == 0)
		newSavingAccnt.setSavingBalance(initBal + 100);//for bonus;
	savingSubAccounts.push_back(newSavingAccnt);
	savingObj.setSavingBalance(initBal);

}

void BankAccount::OpenCheckingSubAccount()
{
	double initBal;
	double maxCapacity;
	char locked;
	bool putLock = false;
	cout << setw(5) << " " << "Enter the initial balance: ";
	cin >> initBal;
	cout << setw(5) << " " << "Enter the desired maximum capacity: ";
	cin >> maxCapacity;
	cout << setw(5) << " " << "Define initial state: (L- Locked, Otherwise- Unlocked): ";
	cin >> locked;
	if (toupper(locked) == 'L')
		putLock = true;
	else
		putLock = false;
	CheckingSubAccount newCheckingAccnt(initBal, maxCapacity, putLock);
	checkingSubAccounts.push_back(newCheckingAccnt);
	checkingObj.setCheckingBalance(initBal);	
}



void BankAccount::PrintInfo()
{
	cout << endl;
	cout << setw(5) << " " << "| Bank Acount Number: " << accNumber << endl;
	cout << setw(5) << " " << "| Account Holder Full Name: " << custFirstName << " " << custLastName << endl;
	cout << setw(5) << " " << "| Account Holder SSN: " << SSN << endl;
	cout << setw(5) << " " << "| Bank Account number: " << accNumber << endl;
	
	for (int i = 0; i < savingSubAccounts.size(); i++)
		savingSubAccounts[i].printSavingAccInfo();
	for (int i = 0; i < checkingSubAccounts.size(); i++)
		checkingSubAccounts[i].printCheckingAccInfo();
}

void BankAccount::PrintBriefInfo()
{
	double tot = 0;
	cout << setw(5) << " " << "| Aggregated balance of the bank account: " << accNumber << " with " << savingSubAccounts.size() + checkingSubAccounts.size() << " Sub-Accounts is ";
	tot = getAggBalance();
	cout << tot << endl;
}

void BankAccount::displayEligibleServices()
{
	char choice;
	string modAccnt;

	do
	{
		double aggBal = 0;
		int indexSel = -1;
		bool modSavingAccount = false;
		vector<SavingSubAccount>tempSavVec;
		vector<CheckingSubAccount>tempChkVec;
		cout << endl << endl << endl;
		cout << "Eligible services for Bank-Account: " << accNumber << endl;
		cout << setw(10) << " " << "S -- Open Saving Sub-Account" << endl;
		cout << setw(10) << " " << "C -- Open Checking Sub-Account" << endl;
		cout << setw(10) << " " << "M -- Modify a Sub-Account" << endl;
		cout << setw(10) << " " << "E -- Close a Sub-Account" << endl;
		cout << setw(10) << " " << "D -- Detailed Bank Account Info Sorted Based on Balances of Sub-Accounts" << endl;
		cout << setw(10) << " " << "B -- Brief Bank Account Info" << endl;
		cout << setw(10) << " " << "X -- Exit" << endl;
		cout << "Please enter your selection: ";
		cin >> choice;

		switch (toupper(choice))
		{
		case 'S':
			OpenSavingSubAccount();
			break;
		case 'C':
			OpenCheckingSubAccount();
			break;
		case 'M':
			cout << setw(5) << " " << "| Enter the sub-account number to modify: ";
			cin >> modAccnt;
			cout << endl;

			for (int i = 0; i < savingSubAccounts.size(); i++)
			{
				if (modAccnt == savingSubAccounts[i].getSavingSubAccNum())
				{
					indexSel = i;
					modSavingAccount = true;
					break;
				}
			}

			for (int i = 0; i < checkingSubAccounts.size(); i++)
			{
				if (modAccnt == CheckingSubAccount::getCheckingSubAccNum())
				{
					indexSel = i;
					modSavingAccount = false;
					break;
				}
			}
			if (indexSel != -1)
			{
				if (modSavingAccount)
					savingSubAccounts[indexSel].savingSubAccMenu();
				else
					checkingSubAccounts[indexSel].checkingSubAccMenu();
			}
			else
				cout << setw(5) << " " << "| The sub-account is not registered. Please create one!" << endl;
			break;
		case 'E':
			cout << setw(5) << " " << "| Enter the sub-account number to be closed: ";
			cin >> modAccnt;
			cout << endl;

			for (int i = 0; i < savingSubAccounts.size(); i++)
			{
				if (savingSubAccounts[i].getSavingSubAccNum() != modAccnt)
				{
					tempSavVec.push_back(savingSubAccounts[i]);

				}
			}
			savingSubAccounts.clear();
			savingSubAccounts = tempSavVec;

			for (int i = 0; i < checkingSubAccounts.size(); i++)
			{
				if (checkingSubAccounts[i].getCheckingSubAccNum() != modAccnt)
				{
					tempChkVec.push_back(checkingSubAccounts[i]);
				}
			}

			checkingSubAccounts.clear();
			checkingSubAccounts = tempChkVec;
			//}
		//}
			cout << setw(5) << " " << "| Sub-account " << modAccnt << " was successfully closed" << endl;
			break;
		case 'D':
			PrintSavingAccntsInfo();
			cout << endl << endl;
			PrintCheckingAccntsInfo();
			break;
		case 'B':
			cout << setw(5) << " " << "| Aggregated balance of the bank account: " << accNumber << " with " << savingSubAccounts.size() + checkingSubAccounts.size() << " sub accounts is: ";
			for (int i = 0; i < savingSubAccounts.size(); i++)
				aggBal += savingSubAccounts[i].getSavingBalance();
			for (int i = 0; i < checkingSubAccounts.size(); i++)
				aggBal += checkingSubAccounts[i].getCheckingBalance();
			cout << aggBal << endl;
			break;
		case 'X':
			cout << setw(5) << "| End of service for bank-account " << accNumber << endl;
		}
	} while (toupper(choice) != 'X');

}

void BankAccount::PrintCheckingAccntsInfo()
{
	for (int i = 0; i < checkingSubAccounts.size(); i++)
		checkingSubAccounts[i].printCheckingAccInfo();
}

void BankAccount::PrintSavingAccntsInfo()
{
	for (int i = 0; i < savingSubAccounts.size(); i++)
		savingSubAccounts[i].printSavingAccInfo();
}

void BankAccount::setAccNumber(string an)
{
	accNumber = an;
}

string BankAccount::getAccNumber()
{
	return accNumber;
}

void BankAccount::setCustFirstName(string fn)
{
	custFirstName = fn;
}

string BankAccount::getCustFirstName()
{
	return custFirstName;
}

void BankAccount::setCustLastName(string ln)
{
	custLastName = ln;
}

string BankAccount::getCustLastName()
{
	return custLastName;
}

void BankAccount::setSSN(string ssn)
{
	SSN = ssn;
}

string BankAccount::getSSN()
{
	return SSN;
}

double BankAccount::getAggBalance()
{
	double tot = 0;
	for (int i = 0; i < savingSubAccounts.size(); i++)
		tot += savingSubAccounts[i].getSavingBalance();
	for (int i = 0; i < checkingSubAccounts.size(); i++)
		tot += checkingSubAccounts[i].getCheckingBalance();
	return tot;
}