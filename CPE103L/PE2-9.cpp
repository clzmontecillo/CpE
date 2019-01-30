#include <iostream>

using namespace std;

int main() {
  float a,b,x,y,z, mean;
  cout << "Enter a Number: ";
  cin >> a;
  cout << "Enter a Number: ";
  cin >> b;
  cout << "Enter a Number: ";
  cin >> x;
  cout << "Enter a Number: ";
  cin >> y;
  cout << "Enter a Number: ";
  cin >> z;
  mean = (a+b+x+y+z)/5;
  cout << "Your average test score is: " << mean << endl;
  return 0;
}
