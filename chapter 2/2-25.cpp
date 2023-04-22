#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int value1;
    int value2;
    cout << "Provide first value" << endl;
    cin >> value1;
    cout << "Provide second value" << endl;
    cin  >> value2;
    if (value1 % value2 == 0)
    {
        cout << "The first is multiple of second" << endl;
    }
    else
    {
        cout << "The first is not multiple of second" << endl;
    }
    return 0;
}