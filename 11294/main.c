# include <stdio.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
  int m  = 0, o = 0 , input = 0, n = 0, s = 0, t = 0;

  scanf("%d", &m);

  int list[m];

  for (int i = 0; i < m; ++i) {
    list[i] = 0;
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d", &input);
    list[i] = input;
  }

  scanf("%d", &o);

  for (int i = 0; i < o; ++i) {
    scanf("%d%d%d", &n, &s, &t);
    int tmp = 0;

    for (int j = 0; j < n; ++j) {
      tmp = list[t + j];
      list[t + j] = list[s + j];
      list[s + j] = tmp;
    }
  }

  for (int i = 0; i < m; ++i) {
    if (i + 1 == m)
      printf("%d\n", list[i]);  
    else
      printf("%d ", list[i]);
  }

  return 0;
}