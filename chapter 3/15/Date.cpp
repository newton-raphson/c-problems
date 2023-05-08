//Implementation of Date Class
#include <iostream>
#include "Date.h"

using namespace std;
// defining a helper function here for the month
int check_month(int mnth)
{
    if (mnth > 12 || mnth < 1)
    {
        cerr << "The month can't be greater than 12 and less than 1 \n" << endl;
        return 1;
    }
    else
    {
        return mnth;
    }
}
Date::Date(int day_val, int mnth,int yrs)
{

    day = day_val;
    month = check_month(mnth);
    year = yrs;
}
int Date::getDay() const
{
    return day;
}
int Date::getMonth() const
{
    return month;
}
int Date::getYear() const
{
    return year;
}
void Date::setDay(int days)
{
    days= day;
}
void Date::setMonth(int mnth)
{
    month = check_month(mnth);
}
void Date::setYear(int yr)
{
    year=yr;
}
void Date::displayDate() const
{
    cout << "\n The Date saved is \n"<< getMonth() << "/"
    << getDay() << "/" << getYear() << endl;
}
