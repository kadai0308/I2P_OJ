#include <stdio.h>
#include "function.h"
int main(){
  int N, i;
  scanf("%d",&N);
  for(i=0; i<N; i++){
    if(1==isPrime(i)) printf("%d\n",i);
  }
}