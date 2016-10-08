#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int input = 0, digits = 0;
  int i = 9;
  int output[10] = {0};

  scanf(" %d", &input);
  scanf(" %d", &digits);

  while (input != 0) {
     output[i] = input % 3;
     input = input / 3;
     i = i - 1;
  }

  i = 10 - digits;
  for (i;i <= 9;++i) {
     printf("%d", output[i]);
  }
     
  printf("\n");
  return 0;
}