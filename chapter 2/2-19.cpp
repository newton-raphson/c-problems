#include <iostream>
using std::cout;
using std::cin;
using std::endl;
// program to calculate min,max,avg,prod and sum
// of three integers
int main(void)
{
    int num[3]; // defining array of three numbers
    int i=0;
    float avg=0;
    int min;
    int max;
    int sum=0;
    int prod=1;
    while(i<3)
    {
        cout<< "Enter number " << i+1 << endl; 
        cin >> num[i];
        if (i==0)
            {
                min = num[i]; // instead of comparing to garbage value 
                max = num[i]; // we initialize them
            }
        if (num[i]>=max)
            {
                max=num[i];
            }
        if (num[i]<=min)
            {
                min=num[i];
            }
        sum+=num[i];
        prod*=num[i];
        i++;
    }
    avg= float(sum)/i;
    cout<<"\nThe sum is "<< sum << endl;
    cout<<"\nThe average is "<< avg << endl;
    cout<<"\nThe product is "<<  prod << endl;
    cout<<"\nThe min is "<< min << endl;
    cout<<"\nThe max is "<< max << endl;
    return 0;
}