#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(int amount)
{
    if (amount>0)
    {
        balance = amount;
    }
    if (amount <=0)
    {
        balance = 0;
        cerr << "The balance needs to be greater than 0" << endl;
    }
}

void Account::credit(int amount)
{
    balance+=amount;
}

void Account::debit(int amount)
{
    if (amount > balance)
    {
        cerr << "You have insufficient balance" << endl;
    }
    else
    {
        balance-=amount;
    }
}
int Account::getBalance() const
{
    return balance;
}