#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int SECRET = 11;
  double RATE = 12.50;
  int num1, num2, newNum;
  string name;
  double hoursWorked, wages;
  cout << "Input num1: ";
  cin >> num1;
  cout << "Input num2: ";
  cin >> num2;
  cout << "The value of num1 = " << num1 << " and the value of num2 = " << num2 << "." << endl;
  newNum = (num1*2) + num2;
  newNum = newNum + SECRET;
  cout << "The value of newNum = " << newNum << endl;
  cout << "Last Name: ";
  cin >> name;
  cout << "Hours Worked (0-70): ";
  cin >> hoursWorked;
  if(hoursWorked > 70){
    cout << "Invalid.";
  }else if(hoursWorked < 0){
    cout << "Invalid.";
  }else{
    wages = RATE*hoursWorked;
    printf("Name: %s \n", name);
    printf("Pay Rate: $ %3.2f \n", RATE);
    printf("Hours Worked: %5.2f \n", hoursWorked);
    printf("Salary: %5.2f \n", wages);
  }
}
