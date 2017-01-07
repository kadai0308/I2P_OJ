#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createList() {
  int input = 0;
  int counter = 0;
  Node *head = NULL;
  Node *ptr = NULL;

  while (1) {
    scanf(" %d", &input);
    if (input == -1) {
      ptr->next = NULL;
      break;
    }
    
    Node *new;
    new = (Node *) malloc (sizeof(Node));
    new->data = input;

    if (counter == 0) {
      head = new;
      ptr = new;     
    } else {
      ptr->next = new;
      ptr = ptr->next;
    }
    counter++;
  }
  return head;
}

Node* reverse(Node* head) {
  Node *ptr = NULL;
  Node *tmp_next = NULL;
  Node *tmp_last = NULL;

  ptr = head->next;
  tmp_last = head;
  tmp_next = ptr->next;
  head->next = NULL;
  while (1) {
    ptr->next = tmp_last;
    tmp_last = ptr;
    ptr = tmp_next;
    if (tmp_next->next != NULL) {
      tmp_next = tmp_next->next;
    } else {
      tmp_next->next = tmp_last;
      break;
    }
  }
  head = tmp_next;
  return head;
}