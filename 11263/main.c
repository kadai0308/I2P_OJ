# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <ctype.h>

# include "function.h"

int main(int argc, char const *argv[])
{
  const char *test;
  const char *words_ptr[100000];
  const char *min;
  
  char initial[50] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
  min = initial;

  int min_index = 0;
  int order = 0;

  while (1) {
    test = fetch_word();
    if (test == NULL) break;
    words_ptr[order] = test;
    order++;
  }

  for (int i = 0; i < order; ++i) {
    for (int j = i; j < order; ++j) {
      int result = strcasecmp( words_ptr[j], min);
      if (strcasecmp( words_ptr[j], min) < 0) {
        min = words_ptr[j];
        min_index = j;
      }
    }
    const char *tmp;
    tmp = words_ptr[i];
    words_ptr[i] = words_ptr[min_index];
    words_ptr[min_index] = tmp;
    min = initial;    
  }

  int count = 0;
  int j = 0;

  for (int i = 0; i < order; ++i) {
    if (i == 0) {
      continue;
    }
    if (!strcasecmp(words_ptr[i-1], words_ptr[i])) {
      count++;
    }
    if (i + 1 == order) {
      while (*(words_ptr[i] + j) != '\0') {
        printf("%c", tolower(*(words_ptr[i] + j)));
        ++j;
      }
      printf(" %d", count+1);
      j = 0;
      count = 0;
      break;
    }
    if (strcasecmp(words_ptr[i], words_ptr[i+1]) != 0) {
      while (*(words_ptr[i] + j) != '\0') {
        printf("%c", tolower(*(words_ptr[i] + j)));
        ++j;
      }
      printf(" %d\n", count+1);
      j = 0;
      count = 0;
    }
  }

  return 0;
}