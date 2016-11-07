# include <stdio.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
  int rows = 0, cols = 0;
  int input = 0;
  int matrix[100] = {0};
  int index_pair = 0;
  int j = 0;

  scanf(" %d", &rows);
  scanf(" %d", &cols);

  for (int i = 0; i < rows*cols; ++i) {
    scanf(" %d", &input);
    matrix[i] = input;
  }

  scanf (" %d", &index_pair);

  int index_matrix[2*index_pair];

  for (int i = 0; i < 2*index_pair; ++i) {
    scanf(" %d", &input);
    index_matrix[i] = input;
  }

  for (int i = 0; i < index_pair; ++i) {
    printf("%d\n", matrix[index_matrix[j]*cols + index_matrix[j+1]]);
    j += 2;
  }

  return 0;
}