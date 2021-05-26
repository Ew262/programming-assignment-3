/*
Program name : checkingAccountClient.cpp
Ezra Thomas
4/1/2021
Input : DNE
Output : interactive menus and prompts that take user input
Description : Takes a checkingAccount class type array and lets a user manipulate
			  with an interactive program
*/

#include "checkingAccount.h"	// derived class of base bankAccount class
								// has private and public date from bankAccount
								// as well its own private and public data

#include <iostream>				// for i/o
#include <iomanip>				// for i/o manipulation i.e. setw
#include <string>				// for string functions

using namespace std;

int main() {
	const int MAX_ACCOUNTS = 25;
	checkingAccount accountsArray[MAX_ACCOUNTS];

	// for while loop
	bool mainMenuLoop = true;		// loop for the main menu set to true by default
	bool subMenuLoop = false;		// loop for the sub menu set to false by default

	// for different prompts
	int mainMenuInput;				// input for main menu prompt
	int subMenuInput;				// input for sub menu prompt
	int accountNumberInput;			// input for account number prompt

	double depositAmount;		// input for add deposit amount
	double withdrawalAmount;		// input for withdrawal amount

	// values for setting a bank user
	string initialHolderName = "";
	double initialDeposit = 0;
	double initialInterest = 0;
	int initialAccountNumber = 0;
	double initialMinimumBalance = 0;
	double initialMonthlyCharge = 0;

	// array
	int mainIndex = 0;
	int subMenuIndex = 0;

	// (while) mainMenuLoop is false
	while (mainMenuLoop) {
		// Print prompt and menu to user
			// Enter (1) to add a new customer.
			// Enter (2) to manage an existing customer.
			// Enter (3) to print customer data.
			// Enter (0) to quit program.
		cout << "Enter (1) Add a new customer.\n"
			 << "Enter (2) Manage an existing customer.\n"
			 << "Enter (3) Print customer data.\n"
			 << "Enter (0) Quit program.\n";
		// get user main menu input value
		if(!(cin >> mainMenuInput)) {
			// clear the error state
			cin.clear();
			// flush cin stream
			cin.ignore(10000, '\n');
			mainMenuInput = -1;
		}
		cout << endl;
		// (if) user mainMenu input value is greater than or equal to 0 and less than or equal to 3
		if (mainMenuInput >= 0 && mainMenuInput <= 3) {
			// (switch) put inputted user input value into a switch system
			switch (mainMenuInput) {
			// Enter (1) to add a new customer.
			case 1:
				if (mainIndex < MAX_ACCOUNTS) {
					// add customer name
					cout << "Enter customer name:\n";
					// get rid of any extra character space
					cin.ignore(1, ' ');
					getline(cin, initialHolderName);
					cout << endl;

					// deposit money
					cout << "Enter amount to be deposited to open account (ex: 200 = $200)\n";
					cin >> initialDeposit;
					cout << endl;

					if (initialDeposit < 0) {
						cout << "Error: balance cannot be below zero\n"
						     << "Please try again \n\n";
						break;
					}

					// set a percent interest rate
					cout << "Enter interest rate amount (ex: 0.02 = 2%):\n";
					cin >> initialInterest;
					cout << endl;

					if (initialInterest < 0) {
						cout << "Error: balance cannot be below zero\n"
                             << "Please try again \n\n";
						break;
					}

					// set min balance
					cout << "Enter minimum balance (defaults to $5 if set to 0 or below)\n";
					cin >> initialMinimumBalance;
					cout << endl;

					// set service charge
					cout << "Enter monthly service charge (defaults to $1 if set to 0 or below)\n";
					cin >> initialMonthlyCharge;
					cout << endl;

					// assign initial values;
					accountsArray[mainIndex].setCheckingAccountData(initialHolderName, initialAccountNumber,
																	initialDeposit, initialInterest,
																	initialMinimumBalance, initialMonthlyCharge);
					// randomize the account counter
					accountsArray[mainIndex].randomizeAccountCounter();
					// assign an account number to accountsArray
					accountsArray[mainIndex].setAccountNumber();
					// post-fix increment the index
					mainIndex++;
				}
				else {
					cout << "Error: Hit max limit of " << MAX_ACCOUNTS << endl << endl;
				}
				break;
			// Enter (2) to manage an existing customer.
			case 2:
				// ask for user id
				cout << "Enter corresponding account ID for matching account holder\n";
				cin >> accountNumberInput;
				cout << endl;

				// (for) loop sort thru list of users for user id
				for (int i = 0; i < mainIndex; i++) {
					// (if) assign matching account num to the index of the matching classTypeArray
					if (accountsArray[i].getAccountNumber() == accountNumberInput) {
						// set index value to the matching account num
						subMenuIndex = i;
						// subMenuLoop check is true
						subMenuLoop = true;
					}
				}
				// (if) subMenuLoop has not been checked,
				if (!subMenuLoop) {
					cout << "No matching id found\n\n";
				}
				break;
			// Enter (3) to print customer data
			case 3:
				// (if) at least the first account is assigned to value greater than zero
				if (accountsArray[0].getAccountNumber() > 0) {
					// print all customers in bankAccount array with for loop
					for (int x = 0; x < mainIndex; x++) {
						// repalaces print function from base class bankAccount
						cout << accountsArray[x];
					}
				}
				else {
					cout << "No accounts in system\n\n";
				}
				break;
			// Enter (0)
			case 0:
				cout << "Exiting program...\n";
				// end main menu loop
				mainMenuLoop = false;
				break;
			// Extra error checking incase something breaks
			default:
				cout << "Oops, something broke\n";
				return 1;
			}

			// (if) subMenuLoop check is true
			if (subMenuLoop) {
				// uses index from in the main menu from (2)
				// (while) loop while subMenuLoop is true
				while (subMenuLoop) {
					// prompt user for a choice in the submenu
					// Enter (1) Make a deposit for the customer number entered.
					// Enter (2) Make a withdrawal(with error checking) for the customer number entered.
					// Enter (3) Print balance of the customer number entered.
					// Enter (4) Update balance with interest for the customer number entered.
					// Enter (0) Exit the submenu.
					cout << "Enter (1) Make a deposit for specified customer.\n"
						 << "Enter (2) Make a withdrawal for specified customer.\n"
						 << "Enter (3) Print balance of specified customer.\n"
						 << "Enter (4) Update balance with interest.\n"
						 << "Enter (0) Exit to main menu.\n";
					// get user sub menu input value
					if (!(cin >> subMenuInput)) {
						// clear the error state
						cin.clear();
						// flush cin stream
						cin.ignore(10000, '\n');
						//cout << "Invalid input!\n";
						subMenuInput = -1;
					}
					cout << endl;
					// (if) user subMenu input value is greater than or equal to 0 and less than or equal to 4
					if (subMenuInput >= 0 && subMenuInput <= 4) {
						// (switch) use subMenu input value
						switch (subMenuInput) {
						// Enter (1) Make a deposit for the customer number entered
						case 1:
							// prompt user for deposit value
							cout << "(Deposit) Enter value to add\n";
							cin >> depositAmount;
							cout << endl;


							// overloaded addition operator
							// replaces deposit money function from base class bankAccount
							accountsArray[subMenuIndex] = accountsArray[subMenuIndex] + depositAmount;
							break;
						// Enter (2) Make a withdrawal(with error checking) for the customer number entered
						case 2:
							// prompt user for withdrawal value
							cout << "(Withdrawal) Enter value to withdrawal from account\n";
							cin >> withdrawalAmount;
							cout << endl;

							// withdrawal money function
							accountsArray[subMenuIndex].withdrawalMoney(withdrawalAmount);
							break;
						// Enter (3) Print balance of the customer number entered
						case 3:
							// print just this one user with subMenuIndex
							//accountsArray[subMenuIndex].print();
							cout << accountsArray[subMenuIndex];
							break;
						// Enter (4) Update balance with interest for the customer number entered
						case 4:
							// updateBalance function
							accountsArray[subMenuIndex].updateBalance();
							break;
						// Enter (0) Exit the submenu
						case 0:
							// set subMenuLoop check to false
							subMenuLoop = false;
							break;
						// Extra error checking in case something breaks
						default:
							cout << "Oops, something broke\n";
							return 1;
						}
					}
					// sub menu: otherwise, if input is not in the set value range
					// or not an int
					else  {
						cout << "Error: Invalid input!\n\n";
					}

				}
			}
		}
		// main menu: otherwise, if input is not in the set value range
		// or not an int
		else {
			cout << "Error: Invalid input!\n\n";
		}
	}
}
