#include <iostream>
#include <iomanip>

using namespace std;

double celsius_to_farhneit(int celsius)
{
    return static_cast<double>(celsius)*1.8 +32;
}
double farhneit_to_celsius(int farhneit)
{
    return (static_cast<double>(farhneit)-32.0)*(5/9);
}

int main()
{
    cout << setprecision( 2 ) << fixed;
    cout<<"Celsius"<<setw(20)<<"Farhneit"<<endl;
    for( unsigned int i=0; i<=10; i++)
    {
        cout<<i*10<<setw(20)<<celsius_to_farhneit(i*10)<<endl;
    }
    cout<<"Farhneit"<<setw(20)<<"Celsius"<<endl;
    for( unsigned int i=32; i<=212; i+=18)
    {
        cout<<i<<setw(20)<<celsius_to_farhneit(i)<<endl;
    }
}
