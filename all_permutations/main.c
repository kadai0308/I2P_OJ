#include <stdio.h>
#include <stdlib.h>

void all_permutations (char input[], int use_size, int unuse_size, int layer, int iter);

int main(int argc, char const *argv[])
{
  int input_size = 0;

  scanf(" %d", &input_size);

  char input[input_size];

  for (int i = 0; i < input_size; ++i) {
    scanf(" %c", &input[i]); 
  }

  printf("input: ");
  for (int i = 0; i < input_size; ++i) {
    printf("%c ", input[i]); 
  }
  printf("\n");

  for (int i = 0; i < input_size; ++i) {
    all_permutations (input, 0, input_size, 0, i);  
  }

  return 0;
}

void all_permutations (char input[], int use_size, int unuse_size, int layer, int iter) {
  if (unuse_size == 1) {
    for (int i = 0; i <= use_size; ++i) {
      printf("%c", input[i]);
    }
    printf("\n");
  } else {

    char next_input[use_size + unuse_size];

    for (int i = 0; i < use_size + unuse_size; ++i) {
      next_input[i] = input[i];
    }

    char tmp; 
    tmp = next_input[layer];
    next_input[layer] = next_input[iter];
    next_input[iter] = tmp;

    unuse_size -= 1;
    use_size += 1;
    layer += 1;
    for (int i = 0; i < unuse_size; ++i) {
      all_permutations (next_input, use_size, unuse_size, layer, i+layer);
    }
  }
}