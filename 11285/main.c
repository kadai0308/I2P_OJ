# include <stdio.h>
# include <stdlib.h>

int determinant (int **matrix, int now_size);

int main(int argc, char const *argv[])
{
  int size = 0;
  scanf(" %d", &size);

  int **matrix;

  matrix = malloc (sizeof(int *) * size);

  for (int i = 0; i < size; ++i) {
    matrix[i] = malloc (sizeof(int *) * size);    
  }

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      scanf(" %d", &matrix[i][j]);
    }
  }

  int result = determinant(matrix, size);

  printf("%d\n", result);
  
  return 0;
}

int determinant (int **matrix, int now_size) {
  
  // for (int j = 0; j < now_size; ++j){
  //   for (int k = 0; k < now_size; ++k) {
  //     printf("%d ", matrix[j][k]);
  //   }
  //   printf("\n");
  // }

  if (now_size == 2) {
    return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
  }

  int result = 0;
  int **next_matrix;

  next_matrix = malloc (sizeof(int *) * (now_size - 1));

  for (int i = 0; i < now_size - 1; ++i) {
    next_matrix[i] = malloc (sizeof(int *) * (now_size - 1));
  }

  for (int i = 0; i < now_size; ++i) {
    
    for (int j = 1; j < now_size; ++j) {
      for (int k = 0; k < now_size; ++k) {
        
        if (k == i)
          continue;
        
        if (k > i) {
          next_matrix[j - 1][k - 1] = matrix[j][k];
        } else {
          next_matrix[j - 1][k] = matrix[j][k];
        }

      }
    }

    // for (int j = 0; j < now_size - 1; ++j){
    //   for (int k = 0; k < now_size - 1; ++k) {
    //     printf("%d ", next_matrix[j][k]);
    //   }
    //   printf("\n");
    // }

    if (i % 2 == 0) {
      result += matrix[0][i]*determinant(next_matrix, now_size - 1);
    } else if (i % 2 == 1) {
      result += (-1)*matrix[0][i]*determinant(next_matrix, now_size - 1);
    }
  }

  return result;
}
