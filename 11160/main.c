#include <stdio.h>
#include <stdlib.h>

int count_gcd(int a, int b, int c);
int count_lcm(int a, int b, int c);

int main(int argc, char const *argv[])
{
  int N = 0;
  int a = 0, b = 0, c = 0;
  int gcd = 0, lcm = 0;;

  scanf(" %d", &N);

  for (int i = 0; i < N; ++i) {
    scanf(" %d", &a);
    scanf(" %d", &b);
    scanf(" %d", &c);
    gcd = 0;
    gcd = count_gcd (a, b, c);
    lcm = count_lcm (a, b, c);
    printf("%d %d\n", gcd, lcm);
  }

  return 0;
}

int count_gcd(int a, int b, int c) {
  int test = 0;
  int gcd = 0;

  while (1) {
    test++;
    if ((a % test == 0) && (b % test == 0) && (c % test == 0)) {
      gcd = test;
    }
    if ((test == a) || (test == b) || (test == c)) {
      break;
    }
  }

  return gcd;
}


int count_lcm(int a, int b, int c) {
  int product = 1;
  int test = 0;
  int lcm = 0;

  while (1) {
    test = c*product;
    product++;
    if ((test % a == 0) && (test % b == 0)) {
      lcm = test;
      break;
    }
  }
  return lcm;
}
