#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
  int i = 0;
  int sum = 0;
  int m;
  cout << "Give a Number: ";
  cin >> m;
  for(;i<m;){
    sum += i + 1;
    i = i+1;
  }
  printf("%d\n", sum);
}