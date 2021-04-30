#ifndef _BANK_H
#define _BANK_H
#include<string>
#include<iostream>
#include"BankAccount.h"

using namespace std;

class Bank
{
private:
	struct node
	{
		BankAccount data;
		node* prev;
		node* next;
	};

	node* front;
	node* end;

	string name;
	string address;
	string workingHours;
	const double BONUS = 100;
	void sortedInsert(node** head_ref, node* newNode);


public:
	Bank();
	Bank(string, string, string);
	bool addAccount(BankAccount);
	void delAccount(string accNum);
	void traverse();
	int getTotalBankAccounts();
	void displayEligibleServices();
	void printInfo();
	void printBriefInfo();
	void insertionSort(node** head_ref);
	void modify();

};
#endif