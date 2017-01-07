#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int cmp( const void *a , const void *b ) {

  const Score *new_a = (const Score *) a;
  const Score *new_b = (const Score *) b;

  int sum_a = 0;
  int sum_b = 0;

  for (int i = 0; i < 3; ++i) {
    sum_a += new_a->score[i];
    sum_b += new_b->score[i];
  }

  if (sum_a != sum_b) {
    return (sum_b - sum_a);
  } else {
    for (int i = 0; i < 3; ++i) {
      if (new_a->score[i] != new_b->score[i]) {
        return (new_b->score[i] - new_a->score[i]);
      }
    }
    return (new_a->id - new_b->id);
  }

}