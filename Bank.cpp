#include "Bank.h"

Bank::Bank()
{
	front = end = NULL;
	name = "BANK";
	address = "NA";
	workingHours = "NA";
}

Bank::Bank(string n, string a, string wh)
{
	front = end = NULL;
	name = n;
	address = a;
	workingHours = wh;
}

bool Bank::addAccount(BankAccount *ba)
{
	node* temp;
	temp = new node();
	temp->data = ba;
	temp->prev = end;
	temp->next = NULL;

	if (end == NULL)
		front = temp;
	else
		end->next = temp;
	end = temp;

	if (end == NULL)return false;
	return true;
}

void Bank::delAccount(string accNum)
{
	node* n;
	n = front;
	while (n != NULL)
	{
		//cout << temp->data << endl;
		if (n->data->getAccNumber() == accNum)
			break;
		n = n->next;
	}

	if (n->prev == NULL)
	{
		front = n->next;
		front->prev = NULL;
	}
	else if (n->next == NULL)
	{
		end = n->prev;
		end->next = NULL;
	}
	else
	{
		n->prev->next = n->next;
		n->next->prev = n->prev;
	}

	delete n->data;
	delete(n);
}

void Bank::traverse()
{
	node* temp;
	temp = front;
	while (temp != NULL)
	{
		//cout << temp->data << endl;
		temp->data->PrintInfo();
		temp = temp->next;
	}
}

// function to insert a new node in sorted way in
// a sorted doubly linked list
void Bank::sortedInsert(node** head_ref, node* newNode)
{
	node* current;

	// if list is empty
	if (*head_ref == NULL)
		*head_ref = newNode;

	// if the node is to be inserted at the beginning
	// of the doubly linked list
	else if ((*head_ref)->data->getAggBalance() >= newNode->data->getAggBalance()) {
		newNode->next = *head_ref;
		newNode->next->prev = newNode;
		*head_ref = newNode;
	}

	else {
		current = *head_ref;

		// locate the node after which the new node
		// is to be inserted
		while (current->next != NULL &&
			current->next->data->getAggBalance() < newNode->data->getAggBalance())
			current = current->next;

		/*Make the appropriate links */

		newNode->next = current->next;

		// if the new node is not inserted
		// at the end of the list
		if (current->next != NULL)
			newNode->next->prev = newNode;

		current->next = newNode;
		newNode->prev = current;
	}
}

// function to sort a doubly linked list using insertion sort
void Bank::insertionSort(node** head_ref)
{
	// Initialize 'sorted' - a sorted doubly linked list
	node* sorted = NULL;

	// Traverse the given doubly linked list and
	// insert every node to 'sorted'
	node* current = *head_ref;
	while (current != NULL) {

		// Store next for next iteration
		node* next = current->next;

		// removing all the links so as to create 'current'
		// as a new node for insertion
		current->prev = current->next = NULL;

		// insert current in 'sorted' doubly linked list
		sortedInsert(&sorted, current);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted doubly linked list
	*head_ref = sorted;
}

void Bank::modify()
{
	string acc;
	cout << setw(5) << " " << "Enter the bank account number to be modified: ";
	cin >> acc;

	node* temp;
	temp = front;
	while (temp != NULL)
	{
		if (temp->data->getAccNumber() == acc)
			temp->data->displayEligibleServices();
		temp = temp->next;
	}
}

int Bank::getTotalBankAccounts()
{
	int c = 0;
	node* temp;
	temp = front;
	while (temp != NULL)
	{
		c++;
		temp = temp->next;
	}
	return c;
}

int Bank::getTotalNumSavingAccounts()
{
	int c = 0;
	node* temp;
	temp = front;
	while (temp != NULL)
	{
		c += temp->data->getNumSavingAccounts();

		temp = temp->next;
	}
	return c;
}


int Bank::getTotalNumCheckingAccounts()
{
	int c = 0;
	node* temp;
	temp = front;
	while (temp != NULL)
	{
		c += temp->data->getNumCheckingAccounts();

		temp = temp->next;
	}
	return c;
}

void Bank::displayEligibleServices()
{
	char choice;
	string fname, lname, ssn;
	BankAccount* newAccount;
	string tempAccNum;
	do
	{
		cout << "Eligible services for " << name << endl;
		cout << setw(10) << " " << "A -- Number of Bank-Accounts" << endl;
		cout << setw(10) << " " << "S -- Number of Saving-Accounts" << endl;
		cout << setw(10) << " " << "H -- Number of Checking-Accounts" << endl;
		cout << setw(10) << " " << "O -- Open Bank-Account" << endl;
		cout << setw(10) << " " << "C -- Close Bank-Account" << endl;
		cout << setw(10) << " " << "M -- Modify Bank-Account" << endl;
		cout << setw(10) << " " << "D -- Detailed Bank-Accounts" << endl;
		cout << setw(10) << " " << "B -- Brief Bank-Accounts Info Sorted Based on Aggregated  Balances" << endl;
		cout << setw(10) << " " << "X -- Number of Bank-Accounts" << endl;
		cout << "Please enter your selection: ";
		cin >> choice;
		cout << endl;

		switch (toupper(choice))
		{
		case 'A':
			cout << setw(5) << " " << "| Number of bank accounts: " << getTotalBankAccounts() << endl;
			break;
		case 'S':
			cout << setw(5) << " " << "| Number of Saving-accounts: " << getTotalNumSavingAccounts() << endl;
			break;
		case 'H':
			cout << setw(5) << " " << "| Number of Checking-accounts: " << getTotalNumCheckingAccounts() << endl;
			break;
		case 'O':
			cin.ignore();
			cout << endl;
			cout << setw(5) << " " << "Enter the first name of the account holder: ";
			getline(cin, fname);
			cout << setw(5) << " " << "Enter the last name of the account holder: ";
			getline(cin, lname);
			cout << setw(5) << " " << "Enter the SSN of the account holder: ";
			getline(cin, ssn);
			cout << endl;
			newAccount = new BankAccount(fname, lname, ssn);			
			cout << setw(5) << " " << "| A new bank account " << newAccount->getAccNumber() << " was successfully created. " << endl;
			newAccount->displayEligibleServices();
			addAccount(newAccount);
			break;
		case 'C':
			cout << endl << setw(5) << " " << " Enter the account number to be deleted: " << endl;
			cin >> tempAccNum;
			delAccount(tempAccNum);
			break;
		case 'M':
			modify();
			break;
		case 'D':
			printInfo();
			traverse();
			break;
		case 'B':
			insertionSort(&front);
			printBriefInfo();
			break;
		case 'X':
			cout << setw(5) << " " << "| End of service for " << name << endl;
			break;
		}
	} while (toupper(choice) != 'X');

}

void Bank::printInfo()
{
	node* temp;
	temp = front;
	cout << setw(5) << " " << "| Bank name: " << name << endl;
	cout << setw(5) << " " << "| Bank address: " << address << endl;
	cout << setw(5) << " " << "| Bank working hours: " << workingHours << endl;
	int totAccounts = 0;
	double totBal = 0;

	while (temp != NULL)
	{
		totBal += temp->data->getAggBalance();
		temp = temp->next;
	}

	cout << setw(5) << " " << "| Aggregated Balance: " << totBal << endl;
	cout << setw(5) << " " << "| Consists of " << getTotalBankAccounts() << " Banks- Accounts" << endl;
}

void Bank::printBriefInfo()
{
	node* temp;
	temp = front;
	cout << setw(5) << " " << "| Bank name: " << name << endl;
	cout << setw(5) << " " << "| Bank address: " << address << endl;
	cout << setw(5) << " " << "| Bank working hours: " << workingHours << endl;
	int totAccounts = 0;
	double totBal = 0;

	while (temp != NULL)
	{
		totBal += temp->data->getAggBalance();
		temp = temp->next;
	}

	cout << setw(5) << " " << "| Aggregated Balance: " << totBal << endl;
	cout << setw(5) << " " << "| Consists of " << getTotalBankAccounts() << " Banks- Accounts" << endl;
	temp = front;
	while (temp != NULL)
	{
		//cout << temp->data << endl;
		temp->data->PrintBriefInfo();
		temp = temp->next;
	}
}