#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void rotateList(Node** head, int k) {
  Node *ptr = NULL;
  Node *new_head = NULL;
  ptr = *head;

  for (int i = 0; i < k; ++i) {
    ptr = ptr->next;
  }

  new_head = ptr;
  ptr = *head;

  while (1) {
    if (ptr->next != NULL) {
      ptr = ptr->next;
      continue;
    }
    ptr->next = *head;
    break;
  }

  ptr = *head;

  for (int i = 0; i < k - 1; ++i) {
    ptr = ptr->next;
  }

  ptr->next = NULL;
  *head = new_head;

}