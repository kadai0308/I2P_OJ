#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long Integer;
#define IO_TYPE " %lld"

int main(int argc, char const *argv[])
{
  Integer input = 0;
  Integer tmp1 = 0;
  Integer tmp2 = 0;
  Integer output[101] = {0};
  Integer break_judge = 0;
  Integer times = 0;

  scanf(IO_TYPE, &input);

  output[0] = 1;
  output[1] = 2;
  output[2] = 1;

  times = input + 1 - 3;

  tmp2 = 1;
  for (Integer i = 0; i < times; ++i) {
    for (Integer j = 0; j < 101; ++j) {
      
      output[0] = 1;
      output[3 + i] = 1;

      if ( (j != 0) && (j != (3 + i)) ) {
        tmp1 = output[j];
        output[j] = tmp2 + output[j];
        tmp2 = tmp1;
      }

      if (j ==  (3 + i)) {
        break;
      }
    }
  }
  
  for (Integer i = 0; i < 31; ++i) {
    if (output[i] == 0) {
      break;
    }
    printf(IO_TYPE, output[i]);
  }

  return 0;
}