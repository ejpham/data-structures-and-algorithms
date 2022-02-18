#include "account.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

account::account() {
    firstName = "";
    lastName = "";
    accountNum = "0000000";
    balance = 0;
}

account::account(string f, string l, string n, double b) {
    firstName = f;
    lastName = l;

    if (n.length() == 7)
        accountNum = n;
    else
        accountNum = "0000000";

    balance = b;
}

void account::setFirstName(string f) { firstName = f; }
void account::setLastName(string l) { lastName = l; }

void account::setAccountNum(string n) {
    if (n.length() == 7)
        accountNum = n;
}

void account::setBalance(double d) { balance = d; }

string account::getFirstName() { return firstName; }
string account::getLastName() { return lastName; }
string account::getAccountNum() { return accountNum; }
double account::getBalance() { return balance; }

void account::print() const {
    cout << setprecision(2) << fixed;
    cout << firstName << " " << lastName << endl;
    cout << "Account number: " << accountNum << endl;
    cout << "Balance: " << balance << endl;
}

