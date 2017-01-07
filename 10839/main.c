#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int ptr_amount = 0;
  int edit_amount = 0;

  char type;
  int index_from = 0;
  int index_to = 0;
  int content = 0;


  scanf (" %d", &ptr_amount);
  scanf (" %d", &edit_amount);

  int *ptr_array[ptr_amount];
  
  for (int i = 0; i < ptr_amount; ++i) {
    ptr_array[i] = malloc(sizeof(int));
    *ptr_array[i] = 0;
  }

  for (int i = 0; i < edit_amount; ++i) {
    scanf (" %c", &type);
    if (type == 'P') {
      scanf (" %d", &index_from);
      scanf (" %d", &index_to);
      ptr_array[index_from] = ptr_array[index_to];
    } else {
      scanf (" %d", &index_from);
      scanf (" %d", &content);
      *ptr_array[index_from] = content;
    }
  }

  // print result

  for (int i = 0; i < ptr_amount; ++i) {
    if (i + 1 == ptr_amount) {
      printf("%d", *ptr_array[i]);
    } else {
      printf("%d ", *ptr_array[i]);
    }
    // printf("%p ", ptr_array[i]);
  }

  return 0;
}