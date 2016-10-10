# include <stdio.h>
# include <stdlib.h>

int isvalueinarray(int val, int *arr, int size);

int main(int argc, char const *argv[])
{
  int input = 0;
  int output = 0;
  int index = 0;
  int array[10] = {0};
  int index_recoed[10] = {0};

  for (int i = 0; i < 10; ++i) {
    scanf(" %d", &input);
    array[i] = input;
  }

  index = 0;
  index_recoed[0] = 0;

  for (int i = 0; i < 10; ++i) {
    if (isvalueinarray(array[index] - 1, index_recoed, 10) == 1) {
      break;
    }
    output = output + array[index];

    index = array[index] - 1;
    index_recoed[i + 1] = index;
  }

  output = output + array[index];

  printf("%d\n", output);

  return 0;
}


int isvalueinarray (int val, int *arr, int size) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == val) {
      return 1;
    }
  }
  return 0;
}
