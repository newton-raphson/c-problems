#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    Date date1(11,10,1999);
    Date date2(12,14,2001); // to check month

    // verify date1
    date1.displayDate();

    // verify date2
    date2.displayDate();

    date1.setMonth(8);
    date1.setDay(13);

    date1.displayDate();

}