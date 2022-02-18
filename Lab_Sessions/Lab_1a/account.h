#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class account {
	//complete the class with attributes and functions
private:
	string firstName;
	string lastName;
	string accountNum;
	double balance;
public:
	account();
	account(string, string, string, double);
	void setFirstName(string);
	void setLastName(string);
	void setAccountNum(string);
	void setBalance(double);
	string getFirstName();
	string getLastName();
	string getAccountNum();
	double getBalance();
	void print() const;
};

#endif