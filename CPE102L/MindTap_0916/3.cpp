// This program calculates your age in the year 2050.
// Input:  None
// Output: Your current age followed by your age in 2050

#include <iostream>
using namespace std;
int main()
{
   // Declare and initialize your variables here
   int myNewAge = 0;
   int myCurrentAge = 18;
   int currentYear = 2018;
   myNewAge = myCurrentAge + (2050 - currentYear);
   cout << "My Current Age is " << myCurrentAge << endl;
   cout << "I will be " << myNewAge << " in 2050." << endl;
   return 0;
}

