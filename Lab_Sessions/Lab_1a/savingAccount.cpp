#include "savingAccount.h"
#include <iostream>

using namespace std;

//Add default constructor
savingAccount::savingAccount() : account() {
    interestRate = 0;
}

//Add constructor with parameters
savingAccount::savingAccount(string f, string l, string n, double b, double d) : account(f, l, n, b) {
    this->interestRate = d;
}

//Override print
void savingAccount::print() const {
    cout << "Interest Rate: " << interestRate << endl;
}

void savingAccount::setRate(double r) {
    if (r <= 1 && r >= 0)
        interestRate = r;
}

double savingAccount::getRate() { return interestRate; }

void savingAccount::addInterest() {
    double temp_b = getBalance();
    setBalance(temp_b + temp_b * interestRate);
}
