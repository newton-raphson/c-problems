// Testing basic functionality of the class Account
#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    Account account1(30);
    Account account2(-2); // needs to print the error message
    cout << "The balance needs to be 0 :"<< account2.getBalance() << endl;
    
    account1.debit(40); // should display the error

    account2.credit(12); 
    cout << "The balance needs to be 12 :"<< account2.getBalance() << endl;
    
    account1.debit(10);
    cout << "The balance needs to be 20 :"<< account1.getBalance() << endl;
}