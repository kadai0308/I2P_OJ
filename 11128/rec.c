# include <stdio.h>
# include <stdlib.h>

int binomial_coefficient (int first, int second);

int main(int argc, char const *argv[])
{
  int input = 0;
  int result = 0;

  scanf(" %d", &input);

  for (int i = 0; i <= input; ++i) {
    printf ("%10d", binomial_coefficient (input, i));
  }

  binomial_coefficient(input, input);

  return 0;
}

int binomial_coefficient (int first, int second) {
  if (second == 0) {
    return 1;
  } else if (second == 1) {
    return first;
  } else if (first == second) {
    return 1;
  } else {
    return binomial_coefficient(first - 1, second - 1) + binomial_coefficient(first - 1, second);
  }
}