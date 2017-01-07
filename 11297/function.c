#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int cmp (const void *a, const void *b) {
  int result = *(int *)(a) - *(int *)(b);
  // printf("%d\n", *(int *)(a));
  if (result > 0)
    return 1;
  else if (result < 0)
    return -1;
  else
    return 0;
}

int getAns(int *ar, int  n) {
  int num = 0;
  int dig = 1;
  qsort(ar, n, sizeof(int), cmp);

  if (ar[0] == 0) {
    for (int i = 1; i < n; ++i) {
      if (ar[i] != 0) {
        ar[0] = ar[i];
        ar[i] = 0;
        break;
      }
    }
  }

  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < n-i-1; ++j) {
      dig *= 10;
    }
    num += ar[i]*dig;
    dig= 1;
  }

  return num;
}