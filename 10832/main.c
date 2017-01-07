#include <stdio.h>

void filling (int amount, int *container_array, int iter, int *result, int size);

int main(int argc, char const *argv[])
{
  int container_amount = 0;
  int container_input = 0;
  int input = 0;

  scanf(" %d", &container_amount);

  int container_array[container_amount];
  int result[container_amount];

  for (int i = 0; i < container_amount; ++i) {
    scanf(" %d", &container_input);
    container_array[i] = container_input;
  }

  scanf(" %d", &input);

  filling (input, container_array, 0, result, container_amount);

  return 0;
}

void filling (int amount, int *container_array, int iter, int *result, int size) {
  if (amount == 0) {
    printf("iter: %d ", iter);
    if (iter < size) {
      for (int i = iter; i < size; ++i) {
        result[i] = 0;
      }
    }

    for (int i = 0; i < size; ++i) {
      if (i == 0) printf("(%d,", result[i]);
      else if (i + 1 == size) printf("%d)", result[i]); 
      else printf("%d,", result[i]);
    }
    printf("\n");

  } else if (iter < size){
    int times = amount / container_array[iter];

    for (int i = times; i >=0 ; --i) {
      int next_amount = amount - container_array[iter]*i;
      result[iter] = i;
      filling (next_amount, container_array, iter+1, result, size);
    }
  }
}