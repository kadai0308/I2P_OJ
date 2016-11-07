# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc, char const *argv[])
{
  int size = 0;
  int i = 0, j = 0;
  char input;
  int direct_vector[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  scanf(" %d", &size);

  char output[size][size];

  memset(output, ')', sizeof(output[0][0]) * size * size);

  // get rid of space
  input = getchar();

  for (int i = 0; i < size; ++i) {
    input = getchar();
    output[0][i] = input;
  }

  for (int i = 1; i < size; ++i) {
    input = getchar();
    output[i][size - 1] = input;
  }

  for (int i = size - 2; i >= 0; --i) {
    input = getchar();
    output[size - 1][i] = input;
  }

  for (int i = size - 2; i > 0; i--) {
    input = getchar();
    output[i][0] = input;
  }

  // for (int i = 0; i < size; ++i) {
  //   for (int j = 0; j < size; ++j) {
  //     printf("%c", output[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("\n");


  int amount = size*4 - 4;

  // up: 1 right: 2 down: 3 left: 4
  int direct = 2;
  int change_direct = 0;
  // start row, col
  i = 1;
  j = 1;

  while (amount < size*size) {
    input = getchar();
    if (direct == 1) {
      if (change_direct) {
        i -= 1;
        change_direct = 0;
      }
      
      output[i][j] = input;

      if (output[i - 1][j] != ')') {
        direct = 2;
        change_direct = 1;
      } else {
        i -= 1;
      }

    } else if (direct == 2) {
      if (change_direct) {
        j += 1;
        change_direct = 0;
      }

      output[i][j] = input;
      
      if (output[i][j + 1] != ')') {
        direct = 3;
        change_direct = 1;
      } else {
        j += 1;
      }

    } else if (direct == 3) {
      if (change_direct) {
        i += 1;
        change_direct = 0;
      }
      output[i][j] = input;

      if (output[i + 1][j] != ')') {
        direct = 4;
        change_direct = 1;
      } else {
        i += 1;
      }

    } else if (direct == 4) {
      if (change_direct) {
        j -= 1;
        change_direct = 0;
      }
      output[i][j] = input;

      if (output[i][j - 1] != ')') {
        direct = 1;
        change_direct = 1;
      } else {
        j -= 1;
      }

    }

    // for (int i = 0; i < size; ++i) {
    //   for (int j = 0; j < size; ++j) {
    //     printf("%c", output[i][j]);
    //   }
    //   printf("\n");
    // }
    // printf("\n");

    amount++;
  }

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      printf("%c", output[i][j]);
    }
    printf("\n");
  }


  return 0;
}