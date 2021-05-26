/*
 Program name: bankAccount.h
 Ezra Thomas
 4/1/2021
 Input: DNE
 Output: base bankAccount class
 Description: the class bankAccount header file
*/

#ifndef bankAccount_H
#define	bankAccount_H
#include <string>

using namespace std;

class bankAccount {
private:
	// account holder�s name
	string holderName;

	// account number
	int accountNumber;

	// balance
	double totalBalance;

	// interest rate
	double interestRate;

	// static private int account number
	static int accountCounter;
public:
	// default constructor
	// Pre: none
	// Post: holderName = holderN
	//		 accountNumber = accountNum
	//		 totalBalance = balance
	//		 interestRate = interest;
	//		 uses setBankAccountData call inside
	//		 if no values are specified, the default
	//		 values are used to initialize the member variables
	bankAccount(string holderN = "", int accountNum = 0,
		double balance = 0.0, double interest = 0.0);

	// getter function for getting holder name
	// Pre:	 valid member object
	// Post: returns string variable tied to bankAccount class type
	std::string getName() const;

	// getter function for getting account num
	// Pre:  valid member object
	// Post: returns int variable tied to bankAccount class type
	int getAccountNumber() const;

	// getter function for getting balance
	// Pre:  valid member object
	// Post: returns double variable tied to bankAccount class type
	double getBalance() const;

	// getter function for getting interest
	// Pre:  valid member object
	// Post: returns double variable tied to bankAccount class type
	double getInterestRate() const;

	// setter function that sets account holder name
	// Pre: valid member object
	// Post: sets private data variable holderName to value of sName
	void setName(string sName);

	// setter function that uses the function
	// incrementAccountCounter()
	// Pre:  valid member object
	// Post: set accountNumber equal to accountCounter
	void setAccountNumber();

	// setter function for balance
	// Pre:  valid member object,
    //       valid double value
	// Post: totalBalance data member is
	//	     set to the value of function parameter
	void setBalance(const double& setAmount);

	// setter function for interest rate
	// Pre:  valid member object,
    //       valid double value
	// Post: interestRate data member
	//		 is set to the value of function parameter
	void setInterestRate(const double& setAmount);

	// setter for all values of bank account data
	// Pre:  valid member object
	//		 valid string, int, and 2 double values
	// Post: member values allocated to inputted parameters
	void setBankAccountData(string& holderN, int& accountNum,
		double& balance, double& interest);

	// function for adding money to a balance of the members bank account
	// Pre:  valid member object,
	//		 valid double value for summing
	// Post: amount added to totalBalance
	void depositMoney(const double& amount);

	// function for withdrawing money from account
	// with error checking (e.g. cannot withdrawal with an account with a value of less than zero)
	// Pre:  valid member object,
    //       valid double value for subtracting
	// Post: set amount subtracted to total balance
	void withdrawalMoney(double amount);

	// function for updating balance of an account with interestRate
	// uses interestRate data member to increment balance
	// Pre:  valid member object
	// Post: balance successfully incremented with interestRate
	void updateBalance();

	// function for printing (cout) the member object data
	// Pre:  valid member object
	// Post: member data formatted and printed to screen
	void print() const;

	// function for incrementing account numbers that uses a
	// random number generator
	// must use C++11 for nullptr
	// Pre: valid member object
	// Post: static int value is set to a random number
	static void randomizeAccountCounter();
};
#endif // bankAccount_H
