#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int,5> x ={5,56,8,9,12};
    for (int a:x)
    {
        cout << a << endl;
    }    

    for (int &ref:x)
    {
        ref*=2;
    }

    cout<<"Return the values";
    for (int a:x)
    {
        cout << a << endl;
    }
}