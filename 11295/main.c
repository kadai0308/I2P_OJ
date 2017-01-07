# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc, char const *argv[])
{
  int n = 0, print_amount = 0;

  scanf(" %d", &n);
  char *all_string[n];
  
  for (int i = 0; i < n; ++i) {
    char *input;
    input = malloc (sizeof(char)*1000);
    scanf(" %s", input);
    print_amount += strlen(input);
    all_string[i] = input;
  }

  print_amount = print_amount - (n - 1);

  int index1 = 0;
  int index2 = 0;

  for (int i = 0; i < print_amount; ++i) {
    printf("%c", all_string[index1][index2]);

    if (all_string[index1][index2+1] == '\0') {
      
      char last = all_string[index1][index2];
      
      for (int j = 0; j < n; ++j) {
        if (all_string[j][0] == last) {
 
          index1 = j;
          index2 = 0;
        }
      }

    }
    index2++;
  }
  printf("\n");

  return 0;
}