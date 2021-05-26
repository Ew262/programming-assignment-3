/*
 Program name: checkingAccount.h
 Ezra Thomas
 4/1/2021
 Input: DNE
 Output: checkingAccount class
 Description: a derived class of base bankAccount, header file with overridden operators
              overridden functions and base setter and getter function prototypes
*/

#ifndef checkingAccount_H
#define checkingAccount_H

#include "bankAccount.h"
#include <iostream>             // for overloaded << operator

using namespace std;

class checkingAccount: public bankAccount {

    // OVERRIED
    // friend function that changes how the (<<) ostream operator
    // intereacts with a checkingAccount class type
    // replaces print method of the base bankAccount class type
    // how it works ex: cout << checkingAccountObject
    // note: << is an operator that can only be changed while it is a friend function
    // Pre: valid << ostream operator
    //      valid checkingAccount object
    // Post: prints formatted data to screen
    friend ostream& operator << (ostream&, const checkingAccount&);

public:
    // Default Constructor
    // Pre: none
    // Post: (holderName = sName)
    //		 (accountNumber = sAccountNum) () base class values
    //		 (totalBalance = sBalance)
    //		 (interestRate = sInterest)
    //       minimumBalance = sMinimumBalance
    //       monthlyCharge = sMonthlyCharge
    //		 if no values are specified, the default
    //		 values are used to initialize the member variables
    checkingAccount(string sName = "", int sAccountNum = 0,
        double sBalance = 0.0, double sInterest = 0.0,
        double sMinimumBalance = 1, double sMonthlyCharge = 5);

    // setter for minimum balance
    // Pre: valid checkingAccount class object
    // Post: if setAmount == 0 default value is $5
    //       otherwise if setAmount > 0 value is setAmount
    void setMinBalance(const double& setAmount);

    // setter for monthlyCharge
    // otherwise monthly charge will be setAmount
    // Pre: valid checkingAccount class object
    // Post: if setAmount == 0 initial monthlyCharge be $1
    //       if setAmout > 0 monthlyCharge will be set to setAmount
    void setMonthlyCharge(const double& setAmount);

    // setter for all data types
    // Pre: valid checkingAccount class object
    // Post: (holderName = sName)
    //		 (accountNumber = sAccountNum) () base class values
    //		 (totalBalance = sBalance)
    //		 (interestRate = sInterest)
    //       minimumBalance = sMinimumBalance
    //       monthlyCharge = sMonthlyCharge
    void setCheckingAccountData(string sName, int sAccountNum,
        double sBalance, double sInterest,
        double sMinimumBalance, double sMonthlyCharge);

    // getter function for minimum balance
    // Pre: valid checkingAccount class object
    // Post: returns value of minimum balance
    double getMinBalance() const;

    // getter function for monthly balance
    // Pre: valid checkingAccount class object
    // Post: returns value of monthly balance
    double getMonthlyCharge() const;

    // OVERRIDED
    // function for withdrawing money from account
    // with error checking (e.g. cannot withdrawal with an account with a value of less than zero
    // checks for minimum balance)
    // if amount falls below minimum balance apply monthly service charge
    // Pre:  valid member object,
    //       valid double value for subtracting
    // Post: set amount subtracted to total balance
    void withdrawalMoney(const double& subAmount);

    // OVERRIDED
    // overrided + operator
    // replaces deposit method from the base class
    // adds a user deterimined amount to total balance
    // (e.g) checkingAccountObj += numberToAdd
    checkingAccount operator + (const double &addAmount);

private:
    // min balance
    double minimumBalance;

    // monthlyCharge
    double monthlyCharge;
};
#endif // checkingAccount_H
