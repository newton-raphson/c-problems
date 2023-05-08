#include <iostream>
#include <cmath>
#include <chrono>
using namespace std::chrono;
using namespace std;

bool check_prime_half(unsigned long long int a)
{
    for (unsigned long long int i = 2; i<=a/2; i++)
    {
        if (a%i==0)
            return false;
    }
    return true;
}
bool check_prime_sqrt(unsigned long long int a)
{
    unsigned long long int val = sqrt(a);
    for (unsigned long long int i = 2; i<=val; i++)
    {
        if (a%i==0)
            return false;
    }
    return true;
}

int main()
{
    // Get starting timepoint
    cout << "Half Function"<<endl;
    for (unsigned long long int i=2; i<=10000; i++)
    {
        if (check_prime_half(i))
        {
            cout << i << endl;
        }
    }
 


    cout << "Sqrt Function"<<endl;

    for (unsigned long long int i=2; i<=10000; i++)
    {
        if (check_prime_sqrt(i))
        {
            cout << i << endl;
        }
    }
    
}