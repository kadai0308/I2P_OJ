# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
  const char *all_words[10000];
  int index = 0;
  char input[30];

  const char *min;
  
  char initial[50] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
  min = initial;

  int min_index = 0;

  while (scanf(" %s", &input) != EOF) {
    for (int i = 0; i < 30; ++i) {
      if ((21 <= input[i] && input[i] <= 64) || (91 <= input[i] && input[i] <= 96) || (123 <= input[i] && input[i] <= 126)) {
        input[i] = '\0';
      }
    }
    // printf("%s ", input);

    char *copy;

    copy = (char *) malloc (30*sizeof(char));

    for (int i = 0; i < 30; ++i) {
      copy[i] = input[i];
    }

    // printf("%p\n", copy);

    all_words[index] = copy;
    ++index;
  }

  for (int i = 0; i < index; ++i) {
    for (int j = i; j < index; ++j) {
      int result = strcasecmp( all_words[j], min);
      if (strcasecmp( all_words[j], min) < 0) {
        min = all_words[j];
        min_index = j;
      }
    }
    const char *tmp;
    tmp = all_words[i];
    all_words[i] = all_words[min_index];
    all_words[min_index] = tmp;
    min = initial;    
  }

  int count = 0;
  int j = 0;

  for (int i = 0; i < index; ++i) {
    if (i == 0) {
      continue;
    }
    if (!strcasecmp(all_words[i-1], all_words[i])) {
      count++;
    }
    if (i + 1 == index) {
      while (*(all_words[i] + j) != '\0') {
        printf("%c", tolower(*(all_words[i] + j)));
        ++j;
      }
      printf(" %d\n", count+1);
      j = 0;
      count = 0;
      break;
    }
    if (strcasecmp(all_words[i], all_words[i+1]) != 0) {
      while (*(all_words[i] + j) != '\0') {
        printf("%c", tolower(*(all_words[i] + j)));
        ++j;
      }
      printf(" %d\n", count+1);
      j = 0;
      count = 0;
    }
  }


  // for (int i = 0; i < index; ++i) {
  //   printf("%c", *all_words[i]);
  //   printf("%c\n", *(all_words[i]+1));
  // }


  return 0;
}