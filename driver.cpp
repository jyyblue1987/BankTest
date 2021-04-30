#include"Bank.h"
#include<iostream>
using namespace std;

//void addBankAccountToBank(Bank& theBank);


int main()
{
	string bname, address, wHours;
	char menuChoice;
	cout << "Enter the name of the bank: ";
	getline(cin, bname);
	cout << "Enter the address of the bank: ";
	getline(cin, address);
	cout << "Enter the working hours: ";
	getline(cin, wHours);

	cout << endl << endl;
	Bank newBank(bname, address, wHours);
	newBank.displayEligibleServices();
	/*cout << "Please enter your selection: ";
	cin >> menuChoice;

	switch (toupper(menuChoice))
	{
	case 'A':
		break;
	case 'S':
		break;
	case 'H':
		break;
	case 'O':
		addBankAccountToBank(newBank);
		break;
	case 'C':
		break;
	case 'M':
		break;
	case 'D':
		break;
	case 'B':
		break;
	case 'X':
		break;
	}
	return 0;*/
}
//
//void addBankAccountToBank(Bank& theBank)
//{
//	char menuChoice;
//	
//	if (theBank.addAccount(newAccount))
//	{
//		cout << setw(5) << " " << "| A new Bank Account " << newAccount.getAccNumber() << " was successfuly created." << endl;
//		do
//		{
//			newAccount.displayEligibleServices();
//			cout << "Please enter your selection: ";
//			cin >> menuChoice;
//			switch (toupper(menuChoice))
//			{
//			case 'S':
//				//createSavingSubAccount(newAccount);
//				break;
//			case 'C':
//				//createCheckingSubAccount(newAccount);
//				break;
//			case 'M':
//				break;
//			case 'E':
//				break;
//			case 'D':
//				break;
//			case 'B':
//				newAccount.PrintBriefInfo();
//				break;
//			case 'X':
//				break;
//			default:
//				cout << "Invalid menu choice" << endl;
//				break;
//			}
//		} while (toupper(menuChoice) != 'X');
//		
//	}
//	else
//		cout << setw(5) << " " << "| Account creation failed." << endl;
//	cout << endl << endl;
//}
//