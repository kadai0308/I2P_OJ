# include <stdio.h>

int main(void) {
  int input = 0, i = 19, count = 0;
  int output[20] = {0};
  
  scanf("%d", &input);
  
  while (input != 0) {
      output[i] = input % 2;
      input = input / 2;
      if (input != 0) {
        i = i - 1;
      }
  }

  for (int j = 19;j >= 0;j--) {
      if (output[j] == 1) {
          count += 1;
          output[j] = 0;
      } else {
          output[j] = 1;
          if (j < i) {
              i = j;
          }
          break;
      }
  }
  
  for (i;i <= 19;++i) {
      printf("%d", output[i]);
  }
  
  printf(" %d", count);

  return 0;
}