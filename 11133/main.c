# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc, char const *argv[])
{
  int input_len = 0;
  char input[1000];


  while (scanf(" %s", input) != EOF) {
    input_len = strlen(input) - 1;
    for (int i = input_len; i >= 0; i--) {
      printf("%c", input[i]);
    }
    printf("\n");
  }

  return 0;
}