# include <stdio.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
  char c;
  char input[10000];
  int len = 0;
  int count[128] = {0};
  int max = 0;
  int max_index = 0;

  while ((c = getchar()) != EOF) {
    input[len] = c;
    count[c] += 1;
    len++;
  }

  for (int i = 0; i < 128; ++i) {
    if (i == 32)
      continue;
    if (count[i] > max) {
      max = count[i];
      max_index = i;
    }
  }

  int shift_num = 'e' - max_index;

  for (int j = 0; j < len; ++j) {
    
    if (input[j] < 65 || (90 < input[j] && input[j] < 97) || (122 < input[j])) {
      printf("%c", input[j]);
      continue;
    }

    if (input[j] == '\n') {
      printf("%c", input[j]);
    }

    int word = input[j] + shift_num;

    if (word > 'Z' && word < 'a') {
      word = word - 'Z' + 'A' - 1;
    } else if (word > 'z') {
      word = word - 'z' + 'a' - 1;
    }
 
    printf("%c", word);
  }

  return 0;
}