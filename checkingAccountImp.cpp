/*
 Program name: checkingAccountImp.cpp
 Ezra Thomas
 4/1/2021
 Input: DNE
 Output:
 Description:
*/

#include "checkingAccount.h"
#include <iostream>				// for i/o
#include <iomanip>				// for i/o manipulation i.e. setw
#include <string>				// for string functions

using namespace std;

ostream& operator << (ostream& outputObj, const checkingAccount& account) {

	outputObj << fixed << showpoint << setprecision(2);
	outputObj << "------------------------------------\n";
	outputObj << "Holder name: " << account.getName() << endl
		<< "Account number: " << account.getAccountNumber() << endl
		<< "Total balance: $" << account.getBalance() << endl
		<< "Interest rate: " << account.getInterestRate() * 100 << '%' << endl
		<< "Minimum balance: $" << account.getMinBalance() << endl
		<< "Monthly service charge: $" << account.getMonthlyCharge() << endl;
	outputObj << "------------------------------------\n\n";
	return outputObj;
}


checkingAccount::checkingAccount(string sName, int sAccountNum,
	double sBalance, double sInterest,
	double sMinimumBalance, double sMonthlyCharge)
	: bankAccount(sName, sAccountNum, sBalance, sInterest) {
	setMinBalance(sMinimumBalance);
	setMonthlyCharge(sMonthlyCharge);
}

void checkingAccount::setMinBalance(const double& setAmount) {
	// if setAmount equals zero
	if (setAmount <= 0) {
		// set default to 5
		minimumBalance = 5;
	}
	// otherwise
	else {
		// assign value of setAmount to minimumBalance
		minimumBalance = setAmount;
	}

}

void checkingAccount::setMonthlyCharge(const double& setAmount) {
	// if setAmount equals zero
	if (setAmount <= 0) {
		// set default to 5
		monthlyCharge = 1;
	}
	// otherwise
	else {
		// assign value of setAmount to minimumBalance
		monthlyCharge = setAmount;
	}

}

void checkingAccount::setCheckingAccountData(string sName, int sAccountNum,
	double sBalance, double sInterest,
	double sMinimumBalance, double sMonthlyCharge) {
	bankAccount::setBankAccountData(sName, sAccountNum, sBalance, sInterest);
	setMinBalance(sMinimumBalance);
	setMonthlyCharge(sMonthlyCharge);
}

double checkingAccount::getMinBalance() const {
	return minimumBalance;
}

double checkingAccount::getMonthlyCharge() const {
	return monthlyCharge;
}

void checkingAccount::withdrawalMoney(const double& subAmount) {
	double subBalance;
	// get balance with bankAccount class public function
	subBalance = bankAccount::getBalance();

	// bool check if transaction is still present
	bool withdrawlTransaction = true;


	// if the amount subtracted to total balance is less than zero
	if ((subBalance < 0) || ((subBalance - subAmount) < 0)) {
		cout << "Error: account balance cannot go below zero, withdrawal canceled\n\n";
		// set transaction to false
		withdrawlTransaction = false;
	}

    if (subAmount < 0) {
        withdrawlTransaction = false;
        cout << "Error: negative integers are not allowed\n\n";
    }

	// otherwise, if transaction is still true
	if (withdrawlTransaction) {
		// subtract balance to subAmount
		subBalance -= subAmount;
		// if balance is below min balance
		if (subBalance <= minimumBalance) {
			cout << "Applying service charge of $" << monthlyCharge << " ...\n\n";
			// apply monthlyCharge rate
			subBalance -= monthlyCharge;
		}

		// if subBalance becomes less than 0
		if ((subBalance < 0)) {
			cout << "Error: account balance minus service charge would make balance go below zero, withdrawal canceled\n\n";
		}

		else {
			bankAccount::setBalance(subBalance);
			//cout << "Warning account is at $" << subBalance << endl << endl;
		}
	}

}

checkingAccount checkingAccount::operator +(const double& addAmount) {
	checkingAccount temp = *this;

	// get balance through derived public classes of bankAccount
	double setAmount;
	setAmount = temp.getBalance();

	// if addAmount is less than zero
	if (addAmount < 0) {
		cout << "Error: input cannot be below zero\n\n";
	}
	else {
		setAmount = setAmount + addAmount;
		temp.setBalance(setAmount);
	}

	return temp;
}
