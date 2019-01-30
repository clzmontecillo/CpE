#include <iostream>
#include <math.h>

using namespace std;

int main() {
  float a,b,x,y,z, sum;
  //double f;
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
  sum = a+b+x+y+z;
  double rounded = round(sum);
  printf("%.0f", rounded);
  cout << endl;
  return 0;
}
