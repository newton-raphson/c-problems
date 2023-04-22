#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
  int value;
  cout << "Enter the integer " << endl;
  cin >> value;
  if (value % 2==0)
  {
    cout <<"\nThe value is even"<< endl;
  }
  else
  {
    cout <<"\nThe value is odd" << endl;
  }
  return 0;
}
