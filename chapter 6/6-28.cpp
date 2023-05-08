#include <iostream>
#include <iomanip>

using namespace std;


bool checkperfect(unsigned long int a)
{
    unsigned long int sum =0;
    unsigned long int tmp=1;
    while(tmp<=a/2)
    {
        if (a%tmp==0)
        {
            sum+=tmp;
        }
        tmp++;
    }

    return sum==a;
}
int main()
{
    unsigned long int i=1;
    cout <<"Perfect Number"<<setw(20)<<"Divisor"<<endl;
    while (i <= 1000)
    {
        if (checkperfect(i))
        {
            cout <<  i <<setw(20);
            for (unsigned long int j =1; j<=i/2; j++)
            {
                if (i%j==0)
                    cout <<  j <<setw(5);
            }
            cout << endl;
        }
        i++;
    }
}
