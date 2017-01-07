#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int main(){
    int digits[22];
    int i, n;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&digits[i]);
    }
    printf("%d\n",getAns(digits, n));
    return 0;
}