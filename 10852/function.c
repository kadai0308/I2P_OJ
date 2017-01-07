#include <stdio.h>
#include "function.h"

int addition (int* a, int array_num, int* entry[], int* index_to_add, int num_ind) {
  int result = 0;
  int *targetArray = entry[array_num];

  for (int i = 0; i < num_ind*2; i += 2) {
    int row = index_to_add[i];
    int col = index_to_add[i+1];
    result += a[row*50+col];
    result += targetArray[row*50+col];
  }

  return result;
}