/*
 Program name: bankAccountImp.cpp
 Ezra Thomas
 4/1/2021
 Input: DNE
 Output: function definitions for base bankAccount class public functions
 Description: the class bankAccount implementation file
              contains the code for setter, getter functions for bankAccount
*/

#include "bankAccount.h"		// for bankAccount public class functions and private data
#include <iostream>				// for i/o
#include <iomanip>				// for i/o manipulation i.e. setw
#include <string>				// for string functions
#include <cstdlib>				// for srand and rand
#include <ctime>				// for time function

using namespace std;

// not a global variable, initializes the static int accountCounter to zero
// stores a random number with randomizeAccountCounter()
int bankAccount::accountCounter = 0;

bankAccount::bankAccount(string holderN, int accountNum,
								 double balance, double interest) {
	setBankAccountData(holderN, accountNum, balance, interest);
}

string bankAccount::getName() const {
	return holderName;
}

int bankAccount::getAccountNumber() const {
	return accountNumber;
}

double bankAccount::getBalance() const {
	return totalBalance;
}

double bankAccount::getInterestRate() const {
	return interestRate;
}

void bankAccount::setName(string sName) {
	holderName = sName;
}

void bankAccount::setAccountNumber() {
    // assign accountCounter's random number to accountNumber
	accountNumber = accountCounter;
}

void bankAccount::setBalance(const double& setAmount) {
	totalBalance = setAmount;
}

void bankAccount::setInterestRate(const double& setAmount) {
	interestRate = setAmount;
}

void bankAccount::setBankAccountData(string& setName, int& setAccountNum,
										 double& setBalance, double& setInterest) {
	holderName = setName;
	accountNumber = setAccountNum;
	totalBalance = setBalance;
	interestRate = setInterest;
}


void bankAccount::depositMoney(const double& amount) {
	// check if amount deposited is less than zero
	if (amount < 0) {
		cout << "Error: input cannot be below zero\n\n";
	}
	// otherwise, add amount to deposit
	else {
		totalBalance += amount;
	}
}

void bankAccount::withdrawalMoney(double amount) {
    // if total balance is less than zero
    // or if the amount subtracted to total balance is less than zero
	if ((totalBalance < 0) || ((totalBalance - amount) < 0))
		cout << "Error: balance is empty\n\n";
    // or if the amount is a number less than zero
	else if (amount < 0)
		cout << "Error: input cannot be below zero\n\n";
    // otherwise, subtract amount to total balance
	else
        totalBalance -= amount;
}

void bankAccount::updateBalance() {
	// totalBalance + (interestRate * totalBalance)
	// sum the totalBalance to the interestRate times totalBalance
	totalBalance += interestRate * totalBalance;
}

void bankAccount::print() const {
	cout << fixed << showpoint << setprecision(2);
	cout << "------------------------------------\n";
	cout << "Holder name: " << getName() << endl
		 << "Account number: " << getAccountNumber() << endl
		 << "Total balance: $" << getBalance() << endl
		 << "Interest rate: " << getInterestRate() * 100 << '%' << endl;
	cout << "------------------------------------\n\n";
}

void bankAccount::randomizeAccountCounter() {
    // gives a psuedo-random number with time
	// seed random number generator with time and nullptr
	srand(time(nullptr));
	// accountCounter + random number remainder of 9999
	accountCounter += rand() % 9999;
}
