#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createList() {
  int data = 0;
  
  Node *head = NULL;
  Node *ptr = NULL;
  Node *start;
  start = malloc (sizeof(Node));

  head = start;
  ptr = start;

  scanf(" %d", &data);
  start->data = data;

  while (1) {
    scanf(" %d", &data);
    if (data != -1) {
      Node *next;
      next = malloc (sizeof(Node));
      next->data = data;

      ptr->next = next;
      ptr = ptr->next;
    } else {
      ptr->next = NULL;
      break;
    }
  }

  return head;
}


void deleteNode(Node ** head, int value) {
  Node *prev = NULL;
  Node *ptr = NULL;

  while ((*head)->data == value) {
      *head = (*head)->next;
  }

  prev = *head;
  
  if ((*head)->next != NULL)
    ptr = ((*head)->next);

  // printf("value: %d ", value);
  // printf("%d %d\n", prev->data, ptr->data);

  while (1) {
    if (ptr->data == value)
      prev->next = ptr->next;
    else
      prev = prev->next;
    
    if (ptr->next != NULL)
      ptr = ptr->next;
    else
      break;
  }
}