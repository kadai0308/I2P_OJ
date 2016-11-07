# include <stdio.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
  int N = 0;
  float a1 = 1, a2 = 0;
  float p1 = 0, p2 = 0, p3 = 0, p4 = 0;
  float target = 0;
  int count = 0;
  float tmp_a1 = 0, tmp_a2 = 0;

  scanf(" %d", &N);

  for (int i  = 0; i < N; ++i) {
    scanf(" %f", &p1);
    scanf(" %f", &p2);
    scanf(" %f", &p3);
    scanf(" %f", &p4);
    scanf(" %f", &target);

    // printf("p1: %f\n", p1);
    // printf("p2: %f\n", p2);
    // printf("p3: %f\n", p3);
    // printf("p4: %f\n", p4);
    // printf("target: %f\n", target);

    a1 = 1;a2 = 0;tmp_a1 = 0;tmp_a2 = 0;
    count = 0;
    while (a1 > target) {
      tmp_a1 = a1;
      tmp_a2 = a2;
      a1 = tmp_a1*p1 + tmp_a2*p2;
      a2 = tmp_a1*p3 + tmp_a2*p4;
      // printf("%f\n", a1);
      count++;
    }
    printf("%d\n", count);
  }

  return 0;
}