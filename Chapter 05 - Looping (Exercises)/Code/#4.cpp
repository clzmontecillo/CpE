#include <stdio.h>

int main(void){
  int i = 2;
  int m = 100;
  for(;i<m;i++){
    if(i%2 == 0)
      printf("%d\n",i);
  }
}