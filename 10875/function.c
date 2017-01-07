# include <stdio.h>
# include <stdlib.h>
#define COLUMN 5

void sortArray(int R, int (*array)[COLUMN]) {
  for (int i = 0; i < COLUMN; ++i) {
    // for (int f = 0; f < R; ++f) {
    //   printf("bef: %d ", array[f][i]);
    // }
    // printf("\n");
    for (int j = R - 1; j >= 0; --j) {
      int max = 0;
      int row = 0;
      int tmp = 0;
      for (int k = j; k >= 0; --k) {
        if (array[k][i] > max) {
          max = array[k][i];
          row = k;
        }
      }
      tmp = array[j][i];
      array[j][i] = max;
      array[row][i] = tmp;
    }
  }
}