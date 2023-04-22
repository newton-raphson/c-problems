#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int value; // variable to store five digit integer 
    int i =5;
    int divisor = 10000;
    cout << "Provide five digit integer" << endl;
    cin >> value;
    if (value < 9999 || value > 99999)
    {
        cout << "The number isn't of five digits";
        return 0;
    }
    // in this loop we print individual digits 

    while (i >0)
    {
        int tmp;
        tmp = value/(divisor);
        cout << tmp <<"   ";
        value-=tmp*divisor;
        divisor/=10;
        i--;
    }
}