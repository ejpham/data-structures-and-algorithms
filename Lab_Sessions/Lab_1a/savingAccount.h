#ifndef SAVING_H
#define SAVING_H

#include "account.h"
#include <string>


class savingAccount : public account {
private:
	double interestRate;
public:
	savingAccount();
	savingAccount(string, string, string, double, double);
	void setRate(double);
	double getRate();
	void addInterest();
	void print() const;
};

#endif#pragma once
