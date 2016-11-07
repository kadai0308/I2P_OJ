# include <stdio.h>
# include <stdlib.h>

typedef struct rectangle 
{
  int x1;
  int y1;
  int x2;
  int y2;
  struct rectangle *next;
} rectangle;

rectangle * append(int x1, int y1, int x2, int y2);
int intersect (rectangle r1, rectangle r2);

int main(int argc, char const *argv[])
{
  int input_amount = 0;
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  int length = 0, width = 0;
  int count = 0;

  rectangle *head = NULL;
  rectangle *current_rectangle = NULL;
  rectangle *compare_rectangle = NULL;

  head = (rectangle *)malloc(sizeof(rectangle));
  current_rectangle = head;

  scanf(" %d", &input_amount);

  for (int i = 0; i < input_amount; ++i) {
    scanf(" %d", &x1);
    scanf(" %d", &y1);
    scanf(" %d", &width);
    scanf(" %d", &length);
    x2 = x1 + width;
    y2 = y1 + length;
    if (i == 0) {
      head->x1 = x1;
      head->y1 = y1;
      head->x2 = x2;
      head->y2 = y2;
    } else {
      current_rectangle->next = append(x1, y1, x2, y2);
      current_rectangle = current_rectangle->next;
    }
  }

  current_rectangle = head;
  int j = 0;
  int t = input_amount - 1;

  for (int i = 0; i < input_amount - 1; ++i) {
    compare_rectangle = head;

    // 移到 current 的下一個
    for (int k = input_amount - t; k > 0; k--) {
      compare_rectangle = compare_rectangle->next;
    }

    // t,j 為這一輪需要比較的次數 因為 j 每次都會被減到ㄧ 所以需要 t 紀錄
    j = t;

    while (j > 0) {
      if (intersect(*current_rectangle, *compare_rectangle)) {
        count++;
      }
      compare_rectangle = compare_rectangle->next;
      j--;
    }

    t--;
    current_rectangle = current_rectangle->next;
  }

  printf("%d\n", count);

  return 0;
}

rectangle * append(int x1, int y1, int x2, int y2) {
  rectangle *new = NULL;

  new = (rectangle *)malloc(sizeof(rectangle));

  new->x1 = x1;
  new->y1 = y1;
  new->x2 = x2;
  new->y2 = y2;
  new->next = NULL;

  return new;
}

int intersect (rectangle r1, rectangle r2) {
  if (r1.x2 <= r2.x1 || r1.x1 >= r2.x2 || r1.y2 <= r2.y1 || r1.y1 >= r2.y2) {
    return 0;
  } else {
    return 1;
  }
}

