#include <stdio.h>
#include <stdlib.h>

void find_n (int l, int u, int n, int *result, int amount, int layer);

int main(int argc, char const *argv[])
{

  int l = 0, u = 0, n = 0;
  scanf ("%d%d%d", &l, &u, &n);

  int result[n];

  for (int i = 0; i < n; ++i) {
    result[i] = 0;
  }

  find_n(l , u, n, result, 0, 0);

  return 0;
}

void find_n (int l, int u, int n, int *result, int amount, int layer) {

  if (l < amount && amount <= u && layer == n) {
    for (int i = 0; i < n; ++i) {
      
      if (i + 1 == n)
        printf("%d\n", result[i]);  
      else
        printf("%d ", result[i]);

    }
  }

  if (amount > u || layer == n) 
    return;

  for (int i = 0; i <= u; ++i) {
    result[layer] = i;
    find_n (l, u, n, result, amount+i, layer+1);
    result[layer] = 0;
  }
}
