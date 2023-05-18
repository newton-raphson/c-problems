#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"

using namespace std;

int main()
{
    BasePlusCommissionEmployee rames( "Bob", "Lewis", "333-33-3333", 5000, .04, 300 );

    cout << fixed << setprecision(2);
    cout << "Employee information obtained by get functions: \n";
    cout << rames.getGrossSales();
    rames.print();
}