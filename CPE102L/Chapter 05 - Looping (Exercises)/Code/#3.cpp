#include <stdio.h>

int main(void){
  int i = 1;
  int square = 0;
  int cube = 0;
  while(i <= 20){
    square = i*i;
    cube = i*i*i;
    printf("%d\f%10d\f%10d\n", i, square, cube);
    i = i + 1;
  }
}