# include <stdio.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
  char input;
  int up = 0, low = 0, other = 0;

  while ((scanf(" %c", &input)) != EOF) {
    if (('A' <= input) && (input <= 'Z')) {
      up++;
    } else if (('a' <= input) && (input <= 'z')) {
      low++;
    } else if (input == ' ') {

    } else {
      other++;
    }
  }

  printf("%d %d %d\n", up, low, other);
  return 0;
}