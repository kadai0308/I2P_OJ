#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{ 
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[])
{
  int N = 0;
  int amount = 0;

  scanf (" %d", &N);

  for (int i = 0; i < N; ++i) {
    scanf(" %d", &amount);
    int array[amount];

    for (int j = 0; j < amount; ++j) {
      scanf(" %d", &array[j]);
    }

    qsort(array, amount, sizeof(int), cmpfunc);

    for (int j = 0; j < amount; ++j) {
      if (j + 1 == amount) {
        printf("%d", array[j]);
      } else {
        printf("%d ", array[j]);
      }

    }
    printf("\n");
  }
  return 0;
}

// int main(int argc, char const *argv[])
// {
//   int N = 0;
//   int amount = 0;

//   int min = 0;
//   int pos = 0;
//   int tmp = 0;

//   scanf(" %d", &N);
//   for (int i = 0; i < N; ++i) {
//     pos = 0;
//     tmp = 0;
//     scanf(" %d", &amount);
//     int array[amount];

//     for (int j = 0; j < amount; ++j) {
//       scanf(" %d", &array[j]);
//     }

//     for (int j = 0; j < amount; ++j) {
//       min = array[j];
//       for (int k = j + 1; k < amount; ++k) {
//         if (array[k] < min) {
//           min = array[k];
//           pos = k;
//           tmp = array[j];
//           array[j] = min;
//           array[pos] = tmp;
//         }
//       }
//     }

//     for (int j = 0; j < amount; ++j) {
//       printf("%d ", array[j]);
//     }
//     printf("\n");

//   }
//   return 0;
// }