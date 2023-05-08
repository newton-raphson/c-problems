#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

unsigned int  random_generator(void);

int main()
{
    for (unsigned int i=0; i<10; i++)
    {
    // cout <<"Case" << i << endl;
    // 2,4,6,8,10
    cout << "Case a: "<< random_generator()*2 << endl;
    // 3,5,7,9,11.
    // cout << "Case b: "<< random_generator()*2+1 << endl;
    // // 6, 10, 14, 18, 22
    // cout << "Case c: "<< (random_generator()*2+1)*2 << endl;
    }
}
unsigned int random_generator()
{
    default_random_engine engine( static_cast<unsigned int>( time(0) ) );
    uniform_int_distribution<unsigned int> randomInt( 1, 5 );
    return randomInt(engine);

}