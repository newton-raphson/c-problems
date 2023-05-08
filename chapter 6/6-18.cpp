#include <iostream>
#include <iomanip>

using namespace std;
unsigned long long integerPower(unsigned a, unsigned b)
{
    if (b==1)
    {
        return a;
    }
    return a * integerPower(a, b-1);
}

int main()
{
    // print values from 1 to 5 powered to it's own value 
    // 3 returns 3^3
    for (unsigned int i =1; i <=5; i++)
    {
        cout <<   integerPower(i,i) << setw(20);
    }
}